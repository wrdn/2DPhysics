#ifndef __Dialog_H
#define __Dialog_H

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

class Dialog {
public:
	/**
	 * Set the window title (caption) text. Returns true for success, false
	 * on failure.
	 */
	virtual bool SetTitle(const char *sTitle) = 0;

	/**
	 * Returns the current window title (caption) text.
	 */
	virtual const char *GetTitle() const = 0;

	/**
	 * Show the dialog box.
	 */
	virtual bool Show() = 0;
};

//-----------------------------------------------------------------------------

class FileDialogEx;

/**
 * File Open/Save dialog.
 */
class FileDialog :public Dialog {
public:
	/**
	 * Flags that affect the behaviour and appearance of the dialog box.
	 * These flags are used with the SetFlags() and GetFlags() methods.
	 * They can be logically OR'ed together with the '|' operator.
	 *	- Default		  = Use default settings
	 *	- PathMustExist	  = Chosen directory path must exist
	 *	- FileMustExist	  = Chosen file must exist
	 *  - CreatePrompt    = For Save dialog: prompt if file doesn't exist
	 *	- HideReadOnly    = Hide read-only checkbox on dialog
	 *	- NoChangeDir     = Don't change directory
	 *	- OverwritePrompt = For Save dialog: prompt if file already exists
	 */
	typedef DWORD Flags;						///< Flag type definition
	static const Flags Default			= 0x00;	///< Default state
	static const Flags PathMustExist	= 0x01;	///< Chosen path must exist
	static const Flags FileMustExist	= 0x02;	///< Chosen file must exist
	static const Flags CreatePrompt		= 0x04;	///< Prompt if file doesn't exist?
	static const Flags HideReadOnly		= 0x08;	///< Hide read-only checkbox
	static const Flags NoChangeDir		= 0x10;	///< Don't change directory
	static const Flags OverwritePrompt	= 0x20;	///< Prompt if file already exists?

	/**
	 * Default Constructor
	 */
	FileDialog();

	/**
	 * Constructor
	 */
	FileDialog(
		const char *sDefExt,		///< default filename extension
		const char *sFileName=0,	///< default filename
		const char *sFilter=0,		///< filter, for file type selection
		Flags	    flags=0			///< flags control dialog appearance/behaviour
	);

	/**
	 * Destructor
	 */
	virtual ~FileDialog();

	/**
	 * Set the window title (caption) text. Returns true for success, false
	 * on failure.
	 */
	bool SetTitle(const char *sTitle);

	/**
	 * Returns the current window title (caption) text.
	 */
	const char *GetTitle() const;

	/**
	 * Show the file dialog (modally). This method does not return until the
	 * user selects either OK or Cancel, or an error occurs. The method
	 * returns true if the user selected a file and clicked OK, otherwise it
	 * returns false.
	 */
	virtual bool Show() = 0;

	/**
	 * This function allows the default filename to be set before the dialog
	 * box is displayed.
	 */
	bool SetFileName(const char *sFileName);

	/**
	 * Returns the full path to the file. Typically, you would call this to
	 * obtain the pathname after the Show() method has returned.
	 */
	const char *GetPathName() const;

	/**
	 * Set the filter string, used to select which file extensions will be
	 * displayed in the file dialog. For example, you can restrict the dialog
	 * to only display image files. The filter string format is the same as
	 * that used in the MFC CFileDialog class.
	 */
	bool SetFilter(const char *sFilter);

	/**
	 * Get the current filter string.
	 */
	const char *GetFilter() const;

	/**
	 * Set the default filename extension (three letters). This extension
	 * is automatically appended to the filename when the user does not
	 * select one. For example, SetDefaultExt("txt") would automatically
	 * append .txt to end of the filename. Only the first three letters
	 * of the supplied string will be used, and the string should not
	 * contain a dot character. Passing an empty string (which is the
	 * default) will prevent an extension from being automatically appended.
	 */
	bool SetDefaultExt(const char *sDefExt);

	/**
	 * Returns the default filename extension. This is the extension
	 * previously specified with the SetDefaultExt() method.
	 */
	const char *GetDefaultExt() const;

	/**
	 * Set the flags. The flags control the behaviour and appearance of
	 * the file dialog.
	 */
	bool SetFlags(Flags f);

	/**
	 * Get the current flags.
	 */
	Flags GetFlags() const;

protected:
	/**
	 * Show the dialog modally. The bOpenDlg parameter determines whether the
	 * dialog is treated as an Open dialog (if true), or a Save dialog (if false).
	 */
	bool Show(bool bOpenDlg);

private:
	/**
	 * Copy constructor not implemented
	 */
	FileDialog(const FileDialog &) {}

	/**
	 * Assignment operator not implemented
	 */
	FileDialog & operator = (const FileDialog &) {}

private:
	FileDialogEx *extra;
};

//-----------------------------------------------------------------------------

/**
 * The OpenFileDialog class can be used to display an Open file dialog.
 */
class OpenFileDialog :public FileDialog {
public:
	/**
	 * Default Constructor
	 */
	OpenFileDialog() {}

	/**
	 * This constructor allows the most important settings to be specified
	 * directly when the dialog is created.
	 */
	OpenFileDialog(
		const char *sDefExt,		///< default filename extension
		const char *sFileName=0,	///< default filename
		const char *sFilter=0,		///< filter, for file type selection
		Flags	    flags=0			///< flags control dialog appearance/behaviour
	) :FileDialog(sDefExt,sFileName,sFilter,flags) {}

	/**
	 * Show the file dialog (modally). This method does not return until the
	 * user selects either OK or Cancel, or an error occurs. The method
	 * returns true if the user selected a file and clicked OK, otherwise it
	 * returns false.
	 */
	bool Show() {
		return FileDialog::Show(true);
	}
};

//-----------------------------------------------------------------------------

/**
 * The SaveFileDialog class can be used to display a Save file dialog.
 */
class SaveFileDialog :public FileDialog {
public:
	/**
	 * Default Constructor
	 */
	SaveFileDialog() {}

	/**
	 * This constructor allows the most important settings to be specified
	 * directly when the dialog is created.
	 */
	SaveFileDialog(
		const char *sDefExt,		///< default filename extension
		const char *sFileName=0,	///< default filename
		const char *sFilter=0,		///< filter, for file type selection
		Flags	    flags=0			///< flags control dialog appearance/behaviour
	) :FileDialog(sDefExt,sFileName,sFilter,flags) {}

	/**
	 * Show the file dialog (modally). This method does not return until the
	 * user selects either OK or Cancel, or an error occurs. The method
	 * returns true if the user selected a file and clicked OK, otherwise it
	 * returns false.
	 */
	bool Show() {
		return FileDialog::Show(false);
	}
};

//-----------------------------------------------------------------------------

_GXBASE_END

#endif//__dialog_h
