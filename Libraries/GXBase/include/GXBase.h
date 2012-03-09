#pragma once
#ifndef __GXBase_H
#define __GXBase_H

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

/*! \mainpage GXBase Library
 *
 * \section intro Introduction
 *
 * The GXBase Library is an object-oriented application framework for
 * developing graphics applications in C++. The current version provides
 * support for multiple OpenGL windows, within a single application.
 * The process of window creation and event handling is very much
 * simplified when compared to native WIN32 API or MFC.
 *
 * You create an application in GXBase by extending existing classes
 * such as App (application class) and GLWindow (window class) to create
 * your own custom classes. The framework sends events to your custom
 * classes by calling virtual functions. You can implement your own
 * custom behaviour by overriding these virtual functions.
 *
 * GXBase includes functions for loading and manipulating images (for
 * example to use as texture maps), loading 3DS models, as well as
 * native support for all current OpenGL extensions (through the
 * GLWindowEx class).
 *
 * \section copy Copyright
 *
 * Copyright (C) 2003-2006 James Ward
 * Department of Computer Science
 * University of Hull, Hull, UK.
 */

// Include windows ahead of GL to avoid problems
#ifdef  _WIN32
#include <windows.h>
#endif//_WIN32

#include <GL/gl.h>
#include <GL/glu.h>

// Defines namespace used by GXBASE classes
//
#ifdef  __cplusplus
	#define _GXBASE_BEGIN namespace gxbase {
	#define _GXBASE_END }
#endif//__cplusplus

// For MS VC++ only (includes VC6 and VS.NET), and not building a LIB
//
#if defined(_MSC_VER) && !defined(_LIB) // auto-link
	// Automatically link OpenGL and GLU
	#pragma comment (lib, "opengl32")
	#pragma comment (lib, "glu32")

	// Automatically link the required libraries, if the project settings
	// are correct, otherwise issues an error message.
	// Supported libraries:
	//   LIBC    (/ML)  Single Threaded (<= VS.NET 2005)
	//   LIBCD   (/MLd) Debug Single Threaded (<= VS.NET 2005)
	//	 LIBCMT	 (/MT)	Multithreaded, static link (>= VS.NET 2008)
	//	 LIBCMTD (/MTd) Multithreaded Debug, static link (>= VS.NET 2008)
	//   MSVCRT  (/MD)  Multithreaded DLL
	//	 MSVCRTD (/MDd) Debug Multithreaded DLL
	//
	// Note:
	//	 * On VS.NET 2008 upwards, use Multithreaded (static/DLL) runtime libaries
	//   * On VS.NET 2003 or 2005, use Single Threaded (static), or Multithreaded DLL
	//
	#if defined(_MT)
		// Multithreaded

		#if defined(_DLL)
			// Multithreaded DLL (/MD or /MDd)

			#if defined(_DEBUG)
				// MSVCRTD (/MDd) Debug Multithreaded DLL
				#pragma comment (lib, "gxbasemd")
				#ifdef GXBASE_JPEG
					#pragma comment (lib, "libjpegmd")
				#endif
			#else
				// MSVCRT (/MD) Multithreaded DLL
				#pragma comment (lib, "gxbasem")
				#ifdef GXBASE_JPEG
					#pragma comment (lib, "libjpegm")
				#endif
			#endif
		#else
			#if (_MSC_VER < 1500)
				// On compilers earlier than VS.NET 2008, we only support Single Threaded
				// or Multithreaded DLL runtime. Under Project.. Properties.. Code Generation
				// you need to select the appropriate runtime library
				#error Please use either Single Threaded or Multithreaded DLL runtime
			#else
				// On VS.NET 2008 and above, we support Multithreaded or Multithreaded
				// DLL runtime, but there is no Single Threaded support
				#if defined(_DEBUG)
					// Debug Multithreaded (static)
					#pragma comment (lib, "gxbased")
				#else
					// Multithreaded (static)
					#pragma comment (lib, "gxbase")
				#endif
			#endif
		#endif
	#else
		// Single Threaded

		#if (_MSC_VER < 1500)
			// Single Threaded (/ML or /MLd)
			#if defined(_DEBUG)
				// LIBCD (/MLd) Debug Single Threaded
				#pragma comment (lib, "gxbased")
				#ifdef GXBASE_JPEG
					#pragma comment (lib, "libjpegd")
				#endif
			#else
				// LIBC (/ML) Single Threaded
				#pragma comment (lib, "gxbase")
				#ifdef GXBASE_JPEG
					#pragma comment (lib, "libjpeg")
				#endif
			#endif
		#else
			// Need to select Multithread or Multithread DLL runtime in project settings
			#error Single Thread runtime is not supported, please choose a Multhreaded runtime
		#endif
	#endif
#endif//auto-link

// Automatically include other GXBASE headers, may duplicate
// Include style would ideally change to <GX/blah.h>
#include "App.h"
#include "GLWindow.h"
#include "GLWindowEx.h"
#include "Image.h"
#include "Model.h"
#include "Dialog.h"
#include "Joystick.h"

#endif//__GXBase_H
