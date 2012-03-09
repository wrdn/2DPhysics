#ifndef __GLWindow_H
#define __GLWindow_H

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

class WindowEx;

/**
 * This class represents an OpenGL window. You should derive a custom window
 * class from GLWindow, and implement code to handle events such as OnDisplay()
 * and OnResize(). Having done this, you can create a window simply by making
 * it a member variable of the application class. When the application is
 * created, your window(s) will be created automatically.
 */
class GLWindow {
public:
	/**
	 * Default constructor
	 */
	GLWindow();

	/**
	 * Destructor
	 */
	virtual ~GLWindow();

//---- event handlers ---------------------------------------------------------
//
// To use one of these events: derive a class from GLWindow, and implement one
// of these functions on your derived class. Your function will then be called
// automatically when that event occurs. For example, implement the OnDisplay
// function to provide your own custom drawing code for your new window class.

	/**
	 * The OnCreate function is called when the window is first created.
	 * Typically you would override this function to perform your own
	 * initialisation. This function is called from a valid OpenGL context,
	 * so that you can call OpenGL functions such as glEnable(..)
	 */
	virtual void OnCreate();

	/** 
	 * The OnDestroy function is called when the window is destroyed.
	 * This provides an opportunity for your code to clean up any
	 * memory allocation or display lists that you have used. This
	 * function is called from a valid OpenGL context just before the
	 * window is destroyed, so that you can call OpenGL functions such
	 * as glDeleteLists(..)
	 */
	virtual void OnDestroy();

	/**
	 * The OnDisplay function is called when the contents of the window
	 * need to be redrawn. Typically you would override this function
	 * to implement your own custom drawing code. This function is called
	 * from a valid OpenGL context, so that you can perform OpenGL drawing.
	 */
	virtual void OnDisplay();

	/**
	 * The OnResize function is called when the window is resized. This
	 * function is called from a valid OpenGL context, so that you can
	 * adjust the OpenGL viewport and viewing system when the window is
	 * resized.
	 */
	virtual void OnResize(int w, int h);

	/**
	 * Mouse button IDs for use with OnMouseButton.
	 */
	enum MouseButton {
		MBLeft   = 0,	///< Left mouse button
		MBMiddle = 1,	///< Middle mouse button
		MBRight  = 2	///< Right mouse button
	};

	/**
	 * The OnMouseButton function is called when a mouse button is
	 * pressed or released. The 'button' parameter indicates which
	 * button the event refers to (MBLeft, MBMiddle, MBRight) and
	 * the 'down' flag is true if the button is down, false
	 * if the button is up.
	 */
	virtual void OnMouseButton(MouseButton button, bool down);

	/**
	 * The OnMouseMove function is called when the mouse pointer is
	 * moved. The parameters contain the current pointer position.
	 */
	virtual void OnMouseMove(int x, int y);

	/**
	 * The OnKeyboard function is called when a key is pressed or
	 * released. The 'key' parameter is the keyboard code, and the
	 * 'down' flag is true if the key is down, false if the key
	 * is up. The state of the SHIFT/CTRL/ALT keys can be tested by
	 * calling one of the following methods: GetShiftKey, GetCtrlKey
	 * or GetAltKey from within the OnKeyboard event.
	 */
	virtual void OnKeyboard(int key, bool down);

	/**
	 * The OnKeyboardChar function is called when a keyboard
	 * character is typed. This is useful for accepting simple
	 * alphabetical or numeric typed characters. See also the
	 * OnKeyboard() and GetKey() functions.
	 */
	virtual void OnKeyboardChar(int chr);

	/**
	 * The OnMenu function is called when a menu item is selected.
	 * The 'id' parameter identifies the menu item.
	 */
	virtual void OnMenu(int id);

	/**
	 * The OnIdle function is called repeatedly when the application
	 * is idle.
	 */
	virtual void OnIdle();

//---- utility functions ------------------------------------------------------

	/**
	 * Swap the front and back display buffers in double buffered mode.
	 */
	void SwapBuffers();

	/**
	 * Make the OpenGL drawing context current (true), or release the
	 * context (false). Most of the event handlers already do this
	 * automatically, including: OnCreate, OnDisplay, OnResize.
	 * You would not normally need to call MakeCurrent() except in
	 * certain special cases. for example if code in the main
	 * application wishes to change OpenGL settings within the
	 * context of a particular window, or to query GL extensions.
	 * Returns true for success, false in case of error.
	 */
	bool MakeCurrent(bool current=true);

	/**
	 * Returns true if a particular OpenGL extension is supported,
	 * false otherwise. Note that the window must have been created
	 * in order for this function to work. If you call this function
	 * from App::OnCreate, this might not be the case. In this case,
	 * you can ensure that the window is created by calling Show().
	 */
	bool HasExtension(const char *name);

	/**
	 * Schedule a redraw for this window: request that the contents are
	 * redrawn. This will cause the OnDisplay() handler to be called at
	 * the next available opportunity.
	 */
	void Redraw();

	/**
	 * Show the window. If the window has not yet been created, this
	 * will cause the window to be created using the current window
	 * size and settings.
	 */
	void Show();

	/**
	 * Hide the window temporarily (it can be made visible
	 * again by calling the Show() function).
	 */
	void Hide();

	/**
	 * Close the window. Note: if you close the main window, the application
	 * will exit. If you only intend to temporarily hide the window, you
	 * should call the Hide() method instead.
	 */
	void Close();

	/**
	 * Returns true if the window is visible, false otherwise. Visible
	 * only means that the window is visible on the desktop; it may still
	 * be covered by other windows.
	 */
	bool IsVisible() const;

	/**
	 * Set the size of the window. If called before the window is created,
	 * this sets the initial size, otherwise it resizes the window. The
	 * Width(), Height() and Aspect() methods can be used to query the
	 * current size and aspect ratio of the window.
	 */
	void SetSize(int w, int h);

	/**
	 * Set the window position. If called before the window is created,
	 * this sets the initial position, otherwise it moves the window.
	 */
	void SetPosition(int x, int y);

	/**
	 * Get the window position. Returns the current window position.
	 */
	void GetPosition(int &x, int &y);

	/**
	 * Enable/disable quad-buffer stereo on this window. Not all graphics
	 * devices support this feature. Returns true for success, false in
	 * case of failure.
	 */
	bool SetStereo(bool stereo=true);

	/**
	 * Returns true if quad-buffer stereo is enabled on this window,
	 * false otherwise. If the window has not yet been shown, this
	 * returns the last state set with SetStereo(), otherwise it will
	 * only return true if the window actually has a stereo format.
	 */
	bool GetStereo() const;

	/**
	 * Enable/disable double-buffering on this window. Returns true for
	 * success, false in case of failure. Windows are double buffered
	 * by default. Setting this to false forces use of single buffer
	 * window mode.
	 */
	bool SetDoubleBuffer(bool bDouble);

	/**
	 * Returns true if window is double-buffered, returns false if
	 * single-buffered.
	 */
	bool GetDoubleBuffer() const;

	/**
	 * Set depth-buffer resolution (bit-depth). The default depth is
	 * 32-bit (if supported). You can use GetDepthBits() to query
	 * the current resolution (which may be less than requested, if
	 * the hardware/drivers cannot support the requested depth).
	 * Returns false if an error occurred (depth could not be set),
	 * or if an out of range value is given.
	 */
	bool SetDepthBits(int nBits);

	/**
	 * Returns the current depth buffer resolution (bit-depth). If an
	 * error occurs, this function may return 0.
	 */
	int GetDepthBits() const;

	/**
	 * Set stencil buffer resolution (bits). There is no stencil
	 * buffer supplied by default. Returns false if an error occurs.
	 */
	bool SetStencilBits(int nBits);

	/**
	 * Returns the current stencil buffer resolution (bits).
	 */
	int GetStencilBits() const;

	/**
	 * Set alpha buffer resolution (bits).
	 * Returns false if an error occurs.
	 */
	bool SetAlphaBits(int nBits);

	/**
	 * Returns the current alpha buffer resolution (bits).
	 */
	int GetAlphaBits() const;

	/**
	 * Set accumulation buffer resolution (bits). Some drivers do not
	 * allow the resolution to be specified, and only turn the buffer
	 * on/off, using a fixed resolution. You can use GetAccumBits() to
	 * find out the actual resolution. Returns false if an error occurs.
	 */
	bool SetAccumBits(int nBits);

	/**
	 * Returns the current accumulation buffer resolution (bits). This
	 * is the total number of bits allocated (per pixel).
	 */
	int GetAccumBits() const;

	/**
	 * Pass a set of OpenGL context creation attributes for use when
	 * creating the context. These are in the same format expected by
	 * the wglCreateContextAttribsARB() call. This function should
	 * be called from the window constructor.
	 */
	void SetContextAttribs( const int *attribs );

	/**
	 * Return width of window in pixels.
	 */
	int Width()  const;

	/**
	 * Return height of window in pixels.
	 */
	int Height() const;

	/**
	 * Return aspect ratio (w/h) of window. Returns 1 in the case where h==0.
	 */
	float Aspect() const;

	/**
	 * Set window title (caption).
	 */
	void SetTitle(const char *title);

	/**
	 * Get window title (caption). Returns an empty string "" if the title
	 * is empty or cannot be read (never returns an invalid pointer). The
	 * returned string should be considered temporary: do not store a
	 * pointer to the string..
	 */
	const char *GetTitle() const;

	/**
	 * Make this the main window. When the main window is closed, the
	 * application closes. The first window created is automatically
	 * treated as the main window by default. You only need to call this
	 * method if you wish to change the main window.
	 */
	void SetMainWindow();

	/**
	 * Returns true if this is the main window, and returns false for all
	 * other windows.
	 */
	bool GetMainWindow() const;

	/**
	 * Call this method to enable/disable fullscreen mode for this window.
	 * When fullscreen mode is enabled, the window will be expanded to
	 * fill the screen, and any window borders and decorations are removed.
	 * When disabled, the window reverts to its original size and shape.
	 */
	bool SetFullscreen(bool bFull=true);

	/**
	 * Returns true if the window is in fullscreen mode, false otherwise.
	 */
	bool GetFullscreen() const;

	/**
	 * Enable or disable the 'stay on top' property of the window. This
	 * works by adding or removing the topmost extended style.
	 */
	bool SetOnTop(bool bTop=true);

	/**
	 * Returns true if the window has the 'stay on top' property, false
	 * otherwise.
	 */
	bool GetOnTop() const;

	/**
	 * Print formatted text to the window, using a bitmap font. This method
	 * accepts the same parameters as the stdio printf() function. You can
	 * use the normal glColor and glRasterPos functions to colour and position
	 * the text. Note: the first time this method is called, it creates a set
	 * of display lists to store the font. The base list ID is generated with
	 * glGenLists, and is returned from this method. To prevent list collisions,
	 * you should avoid using fixed list IDs (use glGenLists). If you must use
	 * fixed list IDs, you can assume that this method uses no more than 256
	 * lists, starting with the base ID returned by this method.
	 * Note that the list ID will be regenerated if the pixel format of the
	 * window changes (since the window is destroyed and recreated in that case).
	 * The return value is the base list ID, or zero in case of error.
	 */
	unsigned int Printf(const char *format, ...);

	/**
	 * Set the font size and typeface to be used by the Printf() method. The
	 * default is to use the default system font. Specifying zero size or
	 * an empty/null font name will restore the original system font.
	 * For example: SetFont(16,"Arial"). Returns true for success, false in
	 * case of error.
	 */
	bool SetFont(int nSize, const char *sFontName);

	/**
	 * This method can be called from OnKeyboard() to test whether the SHIFT
	 * key is pressed. It returns true if the key is down, false otherwise.
	 */
	bool GetShiftKey() const;

	/**
	 * This method can be called from OnKeyboard() to test whether the CTRL
	 * key is pressed. It returns true if the key is down, false otherwise.
	 */
	bool GetCtrlKey() const;

	/**
	 * This method can be called from OnKeyboard() to test whether the ALT
	 * key is pressed. It returns true if the key is down, false otherwise.
	 */
	bool GetAltKey() const;

	/**
	 * This method allows you to test if a particular key is down (true)
	 * or up (false). It can be used as an alternative to the keyboard
	 * events, particularly for interactive use such as in a game.
	 */
	bool GetKey(int key) const;

	/**
	 * Cursor type IDs for use with SetCursor and GetCursor
	 */
	enum Cursor {
		CRNone		= 0,	///< Hide the cursor
		CRArrow		= 1,	///< Standard arrow cursor
		CRCross		= 2,	///< Crosshair cursor
		CRHourglass = 3,	///< Hourglass cursor
		CRHand		= 4		///< Hand cursor
	};

	/**
	 * Set the window mouse cursor type.
	 */
	bool SetCursor(Cursor c);

	/**
	 * Get the window mouse cursor type.
	 */
	Cursor GetCursor() const;

#ifdef  _WIN32
	/**
	 * AVOID USE OF THIS FUNCTION FOR PORTABILITY REASONS.
	 * This function returns the window handle, or NULL in case of error.
	 * PORTABILITY NOTE: This function is only available on the WIN32
	 * platform, if you want to write portable code, please don't use it.
	 * In particular, it is not good practice to use this handle to modify
	 * the window properties.
	 * It is intended for use as a last resort, for example with APIs such
	 * as DirectSound that require access to a window handle. It is not
	 * normally necessary to use the window handle directly, only in very
	 * special circumstances, and when you do not care about portability.
	 * You could consider using cross platform APIs such as OpenAL instead
	 * of DirectSound, and then would have no need of the window handle.
	 */
	HWND GetSafeHwnd() const;

	/**
	 * AVOID USE OF THIS FUNCTION FOR PORTABILITY REASONS.
	 * This function can be used to intercept the windows message loop.
	 * It is called directly from the WindowProc, prior to normal message
	 * processing. You cannot change the return value, or prevent the
	 * usual message processing from taking place.
	 * PORTABILITY NOTE: This function is only available on the WIN32
	 * platform, if you want to write portable code, please don't use it.
	 */
	virtual void OnWindowsMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#endif

private:
	///> copy is not supported
	GLWindow(const GLWindow &) {}

	///> assignment is not supported
	GLWindow & operator = (const GLWindow &) { return *this; }

private:
	/**
	 * This is a private structure that is used to interface to the window
	 * system. It avoids exposing platform specific types in this header.
	 */
	WindowEx *extra;
};

//-----------------------------------------------------------------------------

inline void GLWindow::OnIdle() { /* default does nothing, quickly */ }

//-----------------------------------------------------------------------------

_GXBASE_END

#endif//__GLWindow_H
