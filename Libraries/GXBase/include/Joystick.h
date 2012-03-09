#ifndef __Joystick_H
#define __Joystick_H

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

//-----------------------------------------------------------------------------

_GXBASE_BEGIN

/**
 * Simple joystick interface class, that allows for polling of joystick
 * analogue axes, and button state.
 */
class Joystick {
public:
	/**
	 * Default constructor.
	 */
	Joystick();

	/**
	 * Destructor.
	 */
	~Joystick();

	/**
	 * Returns the number of joysticks available.
	 */
	static int Count();

	/**
	 * Open the joystick interface. You must open the joystick before
	 * you can use it. The optional parameter can be used to specify
	 * the joystick ID in the range (0..15), by default the first
	 * joystick is opened. This function returns true if successful,
	 * or false in case of error. When you have finished, call Close()
	 * to close the interface.
	 */
	bool Open(int n=0);

	/**
	 * Close the joystick interface.
	 */
	void Close();

	/**
	 * Updates the state of the joystick. When you call this function,
	 * the joystick is polled, and the current values for each analogue
	 * axis and button are stored. You can then retrieve these values
	 * by calling the Axis() and Button() functions.
	 */
	void Update();

	/**
	 * Returns the analogue position for a given joystick axis,
	 * as a floating point value in the range -1 to +1. You should
	 * call Update() before calling the Axis() and Button() functions.
	 * Note: this is a raw position value for the axis. Many joysticks
	 * do not return exactly to zero, so you must account for this (for
	 * example by having a 'deadzone', and considering axis values
	 * below a certain threshold value to be zero).
	 */
	float Axis(int n) const;

	/**
	 * Returns the state of a given joystick button. Returns true if the
	 * button is down or false if the button is up (or in case of error).
	 * You should call Update() before calling the Axis() or Button()
	 * functions.
	 */
	bool Button(int n) const;

	/**
	 * Returns the descriptive name of the joystick.
	 */
	const char *Name() const;

private:
	/**
	 * Joystick number (0..15)
	 */
	int m_number;

	/**
	 * Private internal data
	 */
	void *_joy;

	/**
	 * Time of last update
	 */
	float m_time;
};

_GXBASE_END

//-----------------------------------------------------------------------------

#endif//__Joystick_H
