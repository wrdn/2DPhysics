#ifndef __GLWindowEx_H
#define __GLWindowEx_H

/**************************************************************************\
 *
 * This file is part of the GXBase graphics library.
 * Copyright (C) 2003-2006 James Ward, Department of Computer Science,
 * University of Hull. All rights reserved.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 \**************************************************************************/

// Include style would ideally change to <GX/base.h>
#include "GXBase.h"
#include "glex.h"

//-----------------------------------------------------------------------------

/**
 * This class adds support for OpenGL extension functions to the GLWindow
 * class. Derive your own custom window class from GLWindowEx in order to
 * get support for OpenGL extensions.
 */
_GXBASE_BEGIN
class GLWindowEx :public GLWindow, public glex {
public:
	///> default constructor
	GLWindowEx() {
	}

	/**
	 * This event is handled so that the GL extension loader will load the
	 * OpenGL extensions automatically when the OpenGL context is created.
	 * NOTE: If you override OnCreate() in your derived class, it must call
	 * GLWindowEx::OnCreate(), or duplicate the code below.
	 */
	virtual void OnCreate() {
		// load extensions when the OpenGL drawing context is created
		glex::Load();
	}

private:
	///> copy is not supported
	GLWindowEx(const GLWindowEx &) {}

	///> assignment is not supported
	GLWindowEx & operator = (const GLWindowEx &) { return *this; }
};
_GXBASE_END

//-----------------------------------------------------------------------------

#endif//__GLWindowEx_H
