#pragma once

#include "ctypes.h"
#include "Namable.h"

#include <memory>

#ifdef __linux__
#include <tr1/memory> // for std::tr1::shared_ptr
#endif

class Resource : public Namable
{
private:
	i32 id;
public:
	Resource() : id(-1) {};
	Resource(int _id) : id(_id) {};
	virtual ~Resource() {};

	void SetResourceID(i32 _id) { id = _id; };
	i32 GetResourceID() const { return id; };

	// All Resources forced to overload this function
	// This function should be added to the destructor of each Resource
	virtual void Unload()=0;
};

typedef std::tr1::shared_ptr<Resource> ResourceHandle;