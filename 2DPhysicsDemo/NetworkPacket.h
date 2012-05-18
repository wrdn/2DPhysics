#pragma once

#include "Marshall.h"

/*
* This file has all the different types of packet we will be sending over the network. The data in each packet is not the actual data
* used for physics (in most cases). You need to marshall and unmarshall the data first, using provided utility functions.
* Since all packets use integral data types, its safe to call sizeof(*Packet) on them. NEVER hardcode packet sizes.
*/

enum NetworkPacketType
{
	KeepAlive=0,   // No contents, just a type. Send these every few ms to keep the connection alive (no timeout)
	ConnectAuth,   // First packet sent from machine A to machine B (that connected to A). Contains owner ID of B so we know which machine is which
	
	// dont accept these messages until we have got ConnectAuth
	StartInit,     // Object count, box count, triangle count. Signifies how many objects to generate, which we will then fill the properties for with InitObject messages
	InitObject,    // ID (into object array), pos, orientation, mass, velocity, angular velocity, inertia, originalOwner
	EndInit,       // No contents only a type, this packet is sent after we've finished sending InitObject
	
	// dont accept these messages until we have got EndInit
	PositionOrientationUpdate, // int ID (into object array) pos, orientation
	OwnershipUpdate, // Machine X gives owner of object to machine Y. int objectID, pos, orientation, velocity, angular velocity

	// Machine Y sends confirmation to X when it has taken control, so X can lose control of the object. Until we get this, X still holds the object.
	// If Y updates its ownership model to take ownership and sends this packet, it will no longer accept PositionRotationUpdate messages from X. Thus if they temporarily both
	// own it (while the OwnershipUpdateComplete message is being processed by X), the pos/rotation updates of X won't affect Y (and vice versa)
	//OwnershipUpdateComplete
};

struct StartInitData
{
	char type;
	float boxWidth, boxHeight, triangleSideLength;
	short boxCount, triangleCount;
};
struct InitObjectData
{
	char type;
	char originalOwner;
	short objectIndex;
	float2 pos, velocity;
	float orientation, mass, angularVelocity, inertia;
};
struct PositionOrientationData
{
	char type;
	short objectIndex;
	float2 pos;
	float orientation;

	PositionOrientationData() : type(PositionOrientationUpdate)
	{};
	PositionOrientationData(short _index, const float2 &_pos, float _orientation)
		: type(PositionOrientationUpdate), objectIndex(_index), pos(_pos), orientation(_orientation)
	{};
};
struct OwnershipUpdateData
{
	short objectIndex;
};

class NetworkPacket
{
public:
	char type; // defaults to KeepAlive packet
	NetworkPacket() : type(KeepAlive) {};
};

typedef NetworkPacket KeepAlivePacket; // type defaults to KeepAlive so typedef

class ConnectAuthPacket : public NetworkPacket
{
public:
	char assignedOwnerIdentifier; // what ID will the machine that got this packet use for objects?

	// what ID is the other machine using? (not really required)
	char otherMachineIdentifier;

	ConnectAuthPacket()
	{
		type = ConnectAuth;
	}

	ConnectAuthPacket(char assignedOwnerID, char otherMachineID)
	{
		type = ConnectAuth;
		Prepare(assignedOwnerID, otherMachineID);
	}

	// This doesn't need to do much, as they are only chars (1 byte), so we dont need to change the order
	void Prepare(char assignedOwnerID, char otherMachineID)
	{
		assignedOwnerIdentifier = assignedOwnerID;
		otherMachineIdentifier = otherMachineID;
	};
};

class StartInitPacket : public NetworkPacket
{
public:
	// walls are always the first 4 elements, but we can specify box and triangle count when initialising data across the network
	short boxCount; // what ID does this have for objects?
	short triangleCount; // what ID is the other machine using for objects

	ivec boxDimensions;
	int triangleSideLength;

	StartInitPacket()
	{
		type = StartInit;
	}
	StartInitPacket(float boxWidth, float boxHeight, float triangleSideLength,
		short _boxCount, short _triangleCount)
	{
		type = StartInit;
		Prepare(boxWidth, boxHeight, triangleSideLength, _boxCount, _triangleCount);
	}

	StartInitData Unprepare()
	{
		StartInitData data;
		data.type = type;
		
		data.boxWidth = Marshall::ConvertIntToFloat(ntohl(boxDimensions.x));
		data.boxHeight = Marshall::ConvertIntToFloat(ntohl(boxDimensions.y));
		data.triangleSideLength = Marshall::ConvertIntToFloat(ntohl(triangleSideLength));

		data.boxCount = ntohs(boxCount);
		data.triangleCount = ntohs(triangleCount);
		return data;
	};

	void Prepare(StartInitData &data)
	{
		Prepare(data.boxWidth, data.boxHeight, data.triangleSideLength, data.boxCount, data.triangleCount);
	};
	void Prepare(float boxWidth, float boxHeight, float _triangleSideLength,
		short _boxCount, short _triangleCount)
	{
		boxDimensions.x = htonl(Marshall::ConvertFloatToInt(boxWidth));
		boxDimensions.y = htonl(Marshall::ConvertFloatToInt(boxHeight));
		triangleSideLength = htonl(Marshall::ConvertFloatToInt(_triangleSideLength));

		boxCount = htons(_boxCount);
		triangleCount = htons(_triangleCount);
	};
};

class EndInitPacket : public NetworkPacket
{
public:
	EndInitPacket()
	{
		type = EndInit;
	}
};

// These are used at initialisation time to initialise an object and all the relevant properties
class InitObjectPacket : public NetworkPacket
{
public:
	char originalOwner;
	short objectIndex;
	ivec pos, velocity;
	int orientation, mass, angularVelocity, inertia;

	InitObjectPacket()
	{
		type = InitObject;
	}

	// converts data in packet back to a version we can understand (with floats where appropriate and host byte order)
	InitObjectData Unprepare()
	{
		InitObjectData data;
		
		data.type = type;

		data.originalOwner = originalOwner;
		data.objectIndex = ntohs(objectIndex);

		data.pos.x = Marshall::ConvertIntToFloat(ntohl(pos.x));
		data.pos.y = Marshall::ConvertIntToFloat(ntohl(pos.y));

		data.velocity.x = Marshall::ConvertIntToFloat(ntohl(velocity.x));
		data.velocity.y = Marshall::ConvertIntToFloat(ntohl(velocity.y));

		data.orientation = Marshall::ConvertIntToFloat(ntohl(orientation));
		data.angularVelocity = Marshall::ConvertIntToFloat(ntohl(angularVelocity));
		data.inertia = Marshall::ConvertIntToFloat(ntohl(inertia));

		data.mass =  Marshall::ConvertIntToFloat(ntohl(mass));
		
		return data;
	};

	// prepares data ready to be sent on network
	void Prepare(InitObjectData &data)
	{
		Prepare(data.originalOwner, data.objectIndex, data.pos, data.velocity, data.orientation, 
			data.mass, data.angularVelocity, data.inertia);
	};

	// prepares data ready to be sent on network
	void Prepare(char _originalOwner, short _objectIndex, float2 _pos, float2 _velocity, float _orientation,
		float _mass, float _angularVelocity, float _inertia)
	{
		originalOwner = _originalOwner;
		objectIndex = htons(_objectIndex);

		pos.x = htonl(Marshall::ConvertFloatToInt(_pos.x));
		pos.y = htonl(Marshall::ConvertFloatToInt(_pos.y));
		
		velocity.x = htonl(Marshall::ConvertFloatToInt(_velocity.x));
		velocity.y = htonl(Marshall::ConvertFloatToInt(_velocity.y));

		orientation = htonl(Marshall::ConvertFloatToInt(_orientation));
		angularVelocity = htonl(Marshall::ConvertFloatToInt(_angularVelocity));
		inertia = htonl(Marshall::ConvertFloatToInt(_inertia));

		mass = htonl(Marshall::ConvertFloatToInt(_mass));
	};
};

class PositionOrientationUpdatePacket : public NetworkPacket
{
public:
	short objectIndex;
	ivec pos;
	int orientation;

	PositionOrientationUpdatePacket()
	{
		type = PositionOrientationUpdate;
	};
	              
	PositionOrientationUpdatePacket(short _objectIndex, float2 &_pos, float _orientation)
	{
		type = PositionOrientationUpdate;
		Prepare(_objectIndex, _pos, _orientation);
	};

	PositionOrientationData Unprepare()
	{
		PositionOrientationData data;

		data.type = type;

		data.objectIndex = ntohs(objectIndex);
		
		data.pos.x = Marshall::ConvertIntToFloat(ntohl(pos.x));
		data.pos.y = Marshall::ConvertIntToFloat(ntohl(pos.y));

		data.orientation = Marshall::ConvertIntToFloat(ntohl(orientation));

		return data;
	};

	void Prepare(PositionOrientationData &data)
	{
		Prepare(data.objectIndex, data.pos, data.orientation);
	}
	
	void Prepare(short _objectIndex, float2 &_pos, float _orientation)
	{
		objectIndex = htons(_objectIndex);

		pos.x = htonl(Marshall::ConvertFloatToInt(_pos.x));
		pos.y = htonl(Marshall::ConvertFloatToInt(_pos.y));

		orientation = htonl(Marshall::ConvertFloatToInt(_orientation));
	};
};

// Other packets to do: OwnershipUpdate, OwnershipUpdateComplete(?)

// Used to "give" an object to another machine. Stick the object array index in objectIndex and send this packet
class OwnershipUpdatePacket : public NetworkPacket
{
public:
	OwnershipUpdatePacket()
	{
		type = OwnershipUpdate;
	};

	short objectIndex;

	void Prepare(short _objectIndex)
	{
		objectIndex = (_objectIndex);
	};

	OwnershipUpdateData Unprepare()
	{
		OwnershipUpdateData data;
		data.objectIndex = (objectIndex);
		return data;
	};
};