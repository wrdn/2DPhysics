#pragma once

#include <map>
#include <string>
#include "ctypes.h"

class float2;
class float3;
class float4;

// Config file in format:
// ParameterName =  Value
// Example: Velocity = (10,20,30)
//          LSystemRule = (P, F+F[X])
//          K = 3
// The AppConfig class is generic and will read the entire config file, with Parameter Names and Values, both
// as strings. At read time, the AppConfig class will NOT parse the data fully (i.e. it will not create
// a vector from the Velocity example above). The class will overwrite rather than storing multiple copies of data
// E.g. if "speed" appears twice, the final value in the map will be the second one
// Functions are provided to check whether a parameter exists, and to get a parameter as specific type.
// For example, GetInt() or GetVec4(). See the specific functions for parsing requirements and results
// Blank space in lines will be safely ignored. Lines starting with "#" will also be ignored as comments
class AppConfig
{
private:
	std::map<std::string, std::string> configMap; // holds strings for the keys (config parameter names) and results

public:
	AppConfig(void);
	~AppConfig(void);

	// Clears configMap then parses filename into configMap (parameterName, value)
	// Format: ParameterName = Value
	bool ParseConfigFile(const std::string &filename);

	// returns true if configMap contains the key param
	const bool ConfigParameterExists(const std::string &param) const;

	// Returns false if key param does not exist, otherwise returns the value in map associated with param
	bool GetString(const std::string &param, std::string &out);

	// Parses the value of key param as a signed integer
	// If key param does not exist, it will return false and out  will remain unchanged
	// If the parsing to an integer fails for whatever reason, it will return false and out will remain unchanged
	// On success, true will be returned and out will be set to the parsed integer
	bool GetInt(const std::string &param, i32 &out);

	// Parses the value of key param as a float
	// If key param does not exist, it will return false and out  will remain unchanged
	// If the parsing to a float fails for whatever reason, it will return false and out will remain unchanged
	// On success, true will be returned and out will be set to the parsed float
	bool GetFloat(const std::string &param, f32 &out);

	// Parses the value of key param as a 2 element vector
	// If key param does not exist, it will return false and out  will remain unchanged
	// If the parsing to a vector fails for whatever reason, it will return false and out will remain unchanged
	// On success, true will be returned and out will be set to the parsed vector
	// Vector should be in form (x,y). E.g. Velocity = (10,20)
	// This function could be used for any 2 element value
	bool GetVec2(const std::string &param, float2 &out);

	// Parses the value of key param as a 3 element vector
	// If key param does not exist, it will return false and out  will remain unchanged
	// If the parsing to a vector fails for whatever reason, it will return false and out will remain unchanged
	// On success, true will be returned and out will be set to the parsed vector
	// Vector should be in form (x,y,z). E.g. Velocity = (10,20,30)
	// This function could be used for any 3 element value (including RGB colours, GetVec4 for RGBA)
	bool GetVec3(const std::string &param, float3 &out);
	
	// Parses the value of key param as a 4 element vector
	// If key param does not exist, it will return false and out  will remain unchanged
	// If the parsing to a vector fails for whatever reason, it will return false and out will remain unchanged
	// On success, true will be returned and out will be set to the parsed vector
	// Vector should be in form (x,y,z,w). E.g. Velocity = (10,20,30,1)
	// This function could be used for any 4 element value (including RGBA colours)
	bool GetVec4(const std::string &param, float4 &out);
};