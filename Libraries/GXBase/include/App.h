#ifndef __App_H
#define __App_H

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

//-----------------------------------------------------------------------------

#include "GXBase.h"

//-----------------------------------------------------------------------------

_GXBASE_BEGIN

/**
 * This class represents an application. You should derive a custom application
 * class from App, and implement code to handle events such as OnCreate()
 * and OnDestroy(). Your application class will typically store data or
 * documents, and have a number of windows that display views of this data.
 * You should create a single instance of your application class, so that it
 * can run.
 */
class App {
public:
	/**
	 * The OnCreate event handler is called when the application is first
	 * created. You can override this function in your custom application
	 * class in order to perform initialisation. For example, to load
	 * configuration files, or to process command line arguments.
	 */
	virtual void OnCreate();

	/**
	 * The OnIdle event handler is called when the application is idle.
	 * This can be useful to perform background processing. Placing time
	 * consuming code in here could degrade the application performance.
	 */
	virtual void OnIdle();

	/**
	 * The OnTimer event handler is called when a timer event occurs,
	 * which must first be enabled by the SetTimerPeriod method.
	 * The time parameter is an increasing time value, measured in
	 * seconds since the system was started.
	 */
	virtual void OnTimer(double time);

	/**
	 * The OnDestroy event handler is called when the application is
	 * about to be destroyed. It provides an opportunity to clean up
	 * before the application closes.
	 */
	virtual void OnDestroy();

	/**
	 * Calling the Close() method will post a request to the application
	 * to close gracefully. The same effect can be achieved by closing
	 * the main application window.
	 */
	void Close();

	/**
	 * Returns the number of command line arguments.
	 */
	int ArgCount() const;

	/**
	 * Returns a particular argument string, given an integer index
	 * from 0..ArgCount()-1
	 */
	const char *Arg(int n) const;

	/**
	 * Returns an elapsed time value in seconds, from the system. This is
	 * suitable for animation and timing purposes. Note that it's a static
	 * method, so you can just call it like this.. App::GetTime().
	 */
	static double GetTime();

	/**
	 * Returns the elapsed time since the last call to GetDeltaTime().
	 * If this is the first call to GetDeltaTime(), it will return a
	 * default interval of 1/50th of a second.
	 */
	static double GetDeltaTime();

	/**
	 * This method can be used to set the timer period in milliseconds,
	 * or to disable the timer. For example, setting the timer period
	 * to 40 would cause the OnTimer function to be called approximately
	 * 25 times per second (1000ms/40ms = 25Hz). Setting the period to
	 * zero disables the timer.
	 * The return value is the actual timer period in milliseconds.
	 * The resolution, accuracy and minimum period depend on the O/S.
	 * For example, the timer is limited to a minimum period of 10ms
	 * on Windows 2000/XP.
	 */
	unsigned SetTimerPeriod(unsigned ms);

	/**
	 * Returns the current timer period in milliseconds, or zero if
	 * the timer is disabled. Refer to SetTimerPeriod for details.
	 */
	unsigned GetTimerPeriod() const;

	/**
	 * MsgPrintf will print a formatted message to the console (if building
	 * a console application), or to a pop-up message box (if building a
	 * windows application).
	 */
	static void MsgPrintf(const char* format, ...);

	/**
	 * Return a pointer to the single application instance. Not something that
	 * you will usually need to do.
	 */
	static App *Get();

	/**
	 * Set global debug message level. This is only relevant when building a
	 * debug version, and then only in console mode. It prints out lots of
	 * diagnostic information to the console. Setting the level to zero will
	 * disable this output.
	 */
	static void SetDebugMessageLevel(int level);

protected:
	/**
	 * You cannot create instances of App directly. You should derive your
	 * own custom application class from App.
	 */
	App();

	/**
	 * Destructor.
	 */
	virtual ~App();

private:
	/**
	 * You cannot copy App.
	 */
	App(const App &) {}

	/**
	 * You cannot copy App.
	 */
	App & operator = (const App &) { return *this; }
};

//-----------------------------------------------------------------------------

inline void App::OnIdle()  {/* default implementation does nothing, quickly */}
inline void App::OnTimer(double /*time*/)
	{/* default implementation does nothing, quickly */}

//-----------------------------------------------------------------------------

_GXBASE_END

#endif//__App_H
