#ifndef __Image_H
#define __Image_H

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

// if you wish to use this Image class outside GXBase then defining the symbol
// IMAGE_CLASS_STANDALONE in the compiler settings should allow it to be
// compiled independently without altering this source code
//
#ifndef IMAGE_CLASS_STANDALONE
	#include "GXBase.h"
#else// IMAGE_CLASS_STANDALONE
	#define _GXBASE_BEGIN
	#define _GXBASE_END
	#ifndef GXBASE_JPEG_IJG
		#define GXBASE_JPEG_IPIC
	#endif
	#ifdef _WIN32
		#include <windows.h>
	#endif
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif//IMAGE_CLASS_STANDALONE

_GXBASE_BEGIN

class ImageEx;

/**
 * This image class can store several different image formats,
 * and translate between them. There are functions for loading
 * and saving images, grabbing the screen, and defining OpenGL
 * textures from an image.
 */
class Image {
public:
	/**
	 * Image format enumeration
	 */
	enum Format {
		RGB,	///< RGB:  8-bit Red,Green,Blue
		RGBA,	///< RGBA: 8-bit Red,Green,Blue,Alpha
		BGR,	///< BGR:  8-bit Blue,Green,Red
		BGRA,	///< BGR Alpha: 8-bit Red,Green,Blue
		LUM,	///< Luminance: 8-bit greyscale
		LUMALP,	///< Luminance Alpha: 8-bit greyscale, 8-bit alpha
		ALPHA	///< Alpha: 8-bit alpha
	};

	/**
	 * Default constructor
	 */
	Image();

	/**
	 * Construct an image of given (width,height) and image format. This call
	 * is exactly equivalent to constructing an image, and calling Create()
	 * except that the return code from Create() is silently discarded.
	 * You can later check if the image was created successfully by using
	 * the IsValid() method.
	 */
	Image(long width, long height, Format fmt=RGB, long rowPad=0);

	/**
	 * Copy constructor
	 */
	Image(const Image &);

	/**
	 * Destructor
	 */
	virtual ~Image();

	/**
	 * Assignment operator
	 */
	Image & operator = (const Image &);

	/**
	 * Load from file. Returns true for success, false on failure.
	 */
	bool Load(const char *name);

	/**
	 * Save to file. Return true for success, false on failure.
	 */
	bool Save(const char *name) const;

	/**
	 * Grab the contents of the screen into this image. Returns true
	 * for success, false on failure.
	 */
	bool GrabScreen();

	/**
	 * Grab the contents of the current OpenGL viewport as an RGB
	 * image. Returns true for success, false on failure. For example,
	 * you can then use the Save() method to save the image to a file.
	 * The GrabGLViewport() method must be called from a valid OpenGL
	 * context.
	 */
	bool GrabGLViewport();

	/**
	 * Grab the contents of the current OpenGL window as an RGB
	 * image. Note: GrabGLViewport() is preferred; it will usually
	 * achieve the same result (unless you have multiple viewports),
	 * and will be slightly faster in most cases.
	 * Returns true for success, false on failure. For example,
	 * you can then use the Save() method to save the image to a file.
	 * The GrabGLWindow() method must be called from a valid OpenGL
	 * context.
	 */
	bool GrabGLWindow();

	/**
	 * Create an image. Any existing image is destroyed. Calling Create()
	 * with (width==height==0) is equivalent to Free(). The default format
	 * is RGB, but other formats can be specified. The rowPad parameter
	 * allows padding bytes to be added at the end of each row. When the
	 * image is created, the memory is not filled (ie. the image may
	 * contain random data). The Clear methods can be used to clear the
	 * contents of the image to a particular colour.
	 */
	bool Create(long width=0, long height=0, Format fmt=RGB, long rowPad=0);

	/**
	 * Free an image. This releases any storage used for the image.
	 */
	void Free();

	/**
	 * The IsValid() method checks to see if the image is valid. It checks
	 * that the image is allocated, has a non zero width and height, and
	 * that the internal structure looks reasonable. It is useful to test
	 * if an image has been created/loaded successfully, for example when
	 * an image has been created from the constructor.
	 * The IsValid() method returns true if the image is valid, false if
	 * the image is not valid, or if the image is empty.
	 */
	bool IsValid() const;

	/**
	 * The IsEmpty() method returns true if the image is empty, that is
	 * to say that it has zero width or height, and contains no data.
	 * Otherwise, it returns false.
	 */
	bool IsEmpty() const;

	/**
	 * Copy the alpha channel from the source image to the current image
	 * (destination). The colour or intensity values in the destination
	 * image are not altered, but the alpha values are replaced with those
	 * from the source. The images must have the same size.
	 * If the destination image does not have an alpha channel, one will be
	 * added first. If the source image does not have an alpha channel, the
	 * operation will fail.
	 * Returns true for success, false on failure.
	 */
	bool CopyAlpha(const Image &source);

	/**
	 * Clear the image to the specified grey level. The (i) value ranges
	 * from (0..255)
	 */
	bool Clear1b(BYTE i);

	/**
	 * Clear the image to the specified grey level. The (i) value ranges
	 * from 0 to 1.
	 */
	bool Clear1f(float f);

	/**
	 * Clear the image to the specified RGB colour. The (r,g,b) values range
	 * from (0..255), values outside this range are clamped. If the image is
	 * greyscale, the RGB colour is converted to an appropriate grey level
	 * first. See also Clear3f.
	 */
	bool Clear3b(BYTE r, BYTE g, BYTE b);

	/**
	 * Clear the image to the specified RGB colour. The (r,g,b) values range
	 * from (0..1), values outside this range are clamped. If the image is
	 * greyscale, the RGB colour is converted to an appropriate grey level
	 * first. See also Clear3b.
	 */
	bool Clear3f(float r, float g, float b);

	/**
	 * Clear the image to the specified RGBA colour. The (r,g,b,a) values range
	 * from (0..255), values outside this range are clamped. If the image is
	 * greyscale, the RGBA colour is converted to an appropriate grey level
	 * first. If the image does not have an alpha component, the (a) parameter
	 * will be discarded. See also Clear4f.
	 */
	bool Clear4b(BYTE r, BYTE g, BYTE b, BYTE a);

	/**
	 * Clear the image to the specified RGBA colour. The (r,g,b,a) values range
	 * from (0..1), values outside this range are clamped. If the image is
	 * greyscale, the RGBA colour is converted to an appropriate grey level
	 * first. If the image does not have an alpha component, the (a) parameter
	 * will be discarded. See also Clear4b.
	 */
	bool Clear4f(float r, float g, float b, float a);

	/**
	 * Set a pixel at (x,y) to colour (r,g,b,a). Colour values range from
	 * 0 to 255.
	 */
	void SetPixel4b(long x, long y, BYTE r, BYTE g, BYTE b, BYTE a);

	/**
	 * Set a pixel at (x,y) to colour (r,g,b,a). Colour values range from
	 * 0 to 1.
	 */
	void SetPixel4f(long x, long y, float r, float g, float b, float a);

	/**
	 * Set a pixel at (x,y) to colour (r,g,b). Colour values range from
	 * 0 to 255.
	 */
	void SetPixel3b(long x, long y, BYTE r, BYTE g, BYTE b);

	/**
	 * Set a pixel at (x,y) to colour (r,g,b). Colour values range from
	 * 0 to 1.
	 */
	void SetPixel3f(long x, long y, float r, float g, float b);

	/**
	 * Set a pixel at (x,y) to intensity (i) alpha (a). Values range from
	 * 0 to 255.
	 */
	void SetPixel2b(long x, long y, BYTE i, BYTE a);

	/**
	 * Set a pixel at (x,y) to intensity (i). Values range from
	 * 0 to 255.
	 */
	void SetPixel1b(long x, long y, BYTE i);

	/**
	 * Set a pixel at (x,y) to intensity (i) alpha (a). Values range from
	 * 0 to 1.
	 */
	void SetPixel2f(long x, long y, float i, float a);

	/**
	 * Set a pixel at (x,y) to intensity (i). Values range from
	 * 0 to 1.
	 * Note: on an ALPHA image, this sets the alpha channel instead.
	 */
	void SetPixel1f(long x, long y, float i);

	/**
	 * Get the colour values (r,g,b,a) from the pixel at (x,y).
	 * Colour values range from 0 to 255.
	 */
	void GetPixel4b(long x, long y, BYTE &r, BYTE &g, BYTE &b, BYTE &a) const;

	/**
	 * Get the colour values (r,g,b,a) from the pixel at (x,y).
	 * Colour values range from 0 to 1.
	 */
	void GetPixel4f(long x, long y, float &r, float &g, float &b, float &a) const;

	/**
	 * Get the colour values (r,g,b) from the pixel at (x,y).
	 * Colour values range from 0 to 255.
	 */
	void GetPixel3b(long x, long y, BYTE &r, BYTE &g, BYTE &b) const;

	/**
	 * Get the colour values (r,g,b) from the pixel at (x,y).
	 * Colour values range from 0 to 1.
	 */
	void GetPixel3f(long x, long y, float &r, float &g, float &b) const;

	/**
	 * Get the intensity and alpha values (i,a) from the pixel at (x,y).
	 * Values range from 0 to 255.
	 */
	void GetPixel2b(long x, long y, BYTE &i, BYTE &a) const;

	/**
	 * Get the intensity and alpha values (i,a) from the pixel at (x,y).
	 * Values range from 0 to 1.
	 */
	void GetPixel2f(long x, long y, float &i, float &a) const;

	/**
	 * Get the intensity value (i) from the pixel at (x,y).
	 * The value ranges from 0 to 255.
	 */
	void GetPixel1b(long x, long y, BYTE &i) const;

	/**
	 * Get the intensity value (i) from the pixel at (x,y).
	 * The value ranges from 0 to 1.
	 * Note: on an ALPHA image, this returns the image alpha channel.
	 */
	void GetPixel1f(long x, long y, float &i) const;

	/**
	 * Draw a line from (x1,y1) to (x2,y2) using colour (r,g,b)
	 * where each component ranges from 0 to 255.
	 */
	void DrawLine3b(long x1, long y1, long x2, long y2, BYTE r, BYTE g, BYTE b);

	/**
	 * Draw a line from (x1,y1) to (x2,y2) using colour (r,g,b)
	 * where each component ranges from 0 to 1.
	 */
	void DrawLine3f(long x1, long y1, long x2, long y2, float r, float g, float b);

	/**
	 * Draw a line from (x1,y1) to (x2,y2) using intensity (i)
	 * which ranges from 0 to 255.
	 */
	void DrawLine1b(long x1, long y1, long x2, long y2, BYTE i);

	/**
	 * Draw a line from (x1,y1) to (x2,y2) using intensity (i)
	 * which ranges from 0 to 1.
	 */
	void DrawLine1f(long x1, long y1, long x2, long y2, float i);

	/**
	 * Draw rectangle from (x1,y1) to (x2,y2) using colour (r,g,b)
	 * where each component ranges from 0 to 255.
	 */
	void DrawRect3b(long x1, long y1, long x2, long y2, BYTE r, BYTE g, BYTE b);

	/**
	 * Draw rectangle from (x1,y1) to (x2,y2) using colour (r,g,b)
	 * where each component ranges from 0 to 1.
	 */
	void DrawRect3f(long x1, long y1, long x2, long y2, float r, float g, float b);

	/**
	 * Draw rectangle from (x1,y1) to (x2,y2) using intensity (i)
	 * which ranges from 0 to 255.
	 */
	void DrawRect1b(long x1, long y1, long x2, long y2, BYTE i);

	/**
	 * Draw rectangle from (x1,y1) to (x2,y2) using intensity (i)
	 * which ranges from 0 to 1.
	 */
	void DrawRect1f(long x1, long y1, long x2, long y2, float i);

	/**
	 * Flood fill region at (x,y) using colour (r,g,b)
	 */
	void FloodFill3b(long x, long y, BYTE r, BYTE g, BYTE b);

	/**
	 * Flood fill region at (x,y) using colour (r,g,b)
	 */
	void FloodFill3f(long x, long y, float r, float g, float b);

	/**
	 * Flood fill region at (x,y) using intensity (i)
	 */
	void FloodFill1b(long x, long y, BYTE i);

	/**
	 * Flood fill region at (x,y) using intensity (i)
	 */
	void FloodFill1f(long x, long y, float i);

	/**
	 * Blur the image. This is a gentle but reasonably fast blur
	 * using a 3x3 filter kernel. Use the GaussBlur() method if
	 * you need a larger blur radius.
	 */
	void Blur();

	/**
	 * Gaussian blur the image with the specified radius. Larger
	 * radii will produce a stronger blur (and will be slower).
	 */
	void GaussBlur(float radius);

	/**
	 * Average this image with a second image. The two images must
	 * have identical format and dimensions.
	 * Returns true if successful, false otherwise.
	 */
	bool Average(const Image &rhs);

	/**
	 * Logically AND the contents of this image with a second image.
	 * The two images must have identical format and dimensions.
	 * Returns true if successful, false otherwise.
	 */
	bool AND(const Image &rhs);

	/**
	 * Logically XOR the contents of this image with a second image.
	 * The two images must have identical format and dimensions.
	 * Returns true if successful, false otherwise.
	 */
	bool XOR(const Image &rhs);

	/**
	 * Logically OR the contents of this image with a second image.
	 * The two images must have identical format and dimensions.
	 * Returns true if successful, false otherwise.
	 */
	bool OR(const Image &rhs);

	/**
	 * Returns true if two image share the same dimensions and
	 * format.
	 */
	bool SameFormat(const Image &rhs) const;

	/**
	 * Set image format. If the image already exists in a different format,
	 * this will attempt to convert the image to the requested format. If
	 * an exact conversion is not possible, some information may be lost.
	 * For example, in converting a colour to greyscale image, you will
	 * obviously not be able to recover the colour later.
	 */
	bool SetFormat(Format fmt);

	/**
	 * Get the image format.
	 */
	Format GetFormat() const;

	/**
	 * Image width (pixels)
	 */
	long Width() const;

	/**
	 * Image height (pixels)
	 */
	long Height() const;

	/**
	 * Image aspect ratio (width/height). Returns 1.0 if the height is zero.
	 */
	float Aspect() const;

	/**
	 * Rescale the image to an arbitrary size. If the image already has the
	 * requested size, or the parameters are invalid, no scaling takes place.
	 * After scaling, the image will be packed. If the function succeeds,
	 * the return value is zero. If the function fails, the return value is
	 * a GLU error code (as defined elsewhere by the GLU documentation).
	 * Must be called from a valid OpenGL context.
	 */
	int gluScaleImage(long width, long height);

	/**
	 * Scale to nearest power of 2 size on each axis. This is automatically
	 * restricted to the maximum texture size supported by OpenGL. If the
	 * texture size already meets these constraints, the image will not be
	 * scaled. The scaling is performed by gluScaleImage().
	 * Returns true for success, false on failure.
	 */
	bool ScaleImagePow2();

	/**
	 * Issues a call to gluBuild1DMipmaps() with the current image. The
	 * parameters are automatically chosen, according to the current image
	 * format. The 1D texture is defined by the image width, and only the
	 * first row of the image will be used. For this to work, the call must
	 * be made from a valid OpenGL context. Returns the gluBuild1DMipmaps()
	 * result code, where 0 indicates success.
	 */
	int gluBuild1DMipmaps();

	/**
	 * Issues a call to gluBuild2DMipmaps() with the current image. The
	 * parameters are automatically chosen, according to the current image
	 * format. For this to work, the call must be made from a valid OpenGL
	 * context. Returns the gluBuild2DMipmaps() result code, where 0
	 * indicates success.
	 */
	int gluBuild2DMipmaps();

	/**
	 * Issues a call to glTexImage1D() with the current image. The
	 * parameters are automatically chosen, according to the current image
	 * format. The 1D texture is defined by the image width, and only the
	 * first row of the image will be used. For this to work, the call must
	 * be made from a valid OpenGL context. Returns true for success, false
	 * in case of failure.
	 * The (level) parameter specifies the level-of-detail number. Level 0
	 * is the base image level. Level n is the nth mipmap reduction image.
	 * Note: glTexImage1D() normally requires that the texture has a width
	 * that is a power of two.
	 */
	bool glTexImage1D(int level=0);

	/**
	 * Issues a call to glTexImage2D() with the current image. The
	 * parameters are automatically chosen, according to the current image
	 * format. For this to work, the call must be made from a valid OpenGL
	 * context. Returns true for success, false in case of failure.
	 * The (level) parameter specifies the level-of-detail number. Level 0
	 * is the base image level. Level n is the nth mipmap reduction image.
	 * Note: glTexImage2D() normally requires that textures have width and
	 * height values that are a power of two, although some cards/drivers
	 * support non power of two textures. You can use the ScaleImagePow2()
	 * method to scale the image to an appropriate size first.
	 */
	bool glTexImage2D(int level=0);

	/**
	 * Issues a call to glDrawPixels() with the current image. The parameters
	 * are automatically chosen, according to the current image format. The
	 * call must be made from a valid OpenGL context. Returns true for success,
	 * false in case of failure.
	 */
	bool glDrawPixels();

	/**
	 * Constructs an image from a call to glReadPixels(). The (x,y) values
	 * specify the lower-left corner of the capture region, and the
	 * (width,height) parameters specify the size of the region. The (format)
	 * parameter specifies the desired image format. The output image will
	 * be packed (ie. will not have row padding).
	 * Returns true for success, false in case of failure.
	 * Note that the format is a member of the Image::Format enumeration.
	 * The mapping between Image formats and OpenGL formats is as follows:
	 *		- RGB	= GL_RGB
	 *		- RGBA	= GL_RGBA
	 *		- BGR	= GL_BGR_EXT
	 *		- BGRA	= GL_BGRA_EXT
	 *		- LUM	= GL_LUMINANCE
	 *		- LUMALP= GL_LUMINANCE_ALPHA
	 *		- ALPHA = GL_ALPHA
	 *
	 * This call is affected by the usual OpenGL state, such as glReadBuffer,
	 * pixel map and pixel scale. However, the OpenGL GL_PACK_xxx settings are
	 * automatically set for you (and restored before returning).
	 */
	bool glReadPixels(int x, int y, int width, int height, Format format);

	/**
	 * Get image size (bytes)
	 */
	long Size() const;

	/**
	 * This function packs the image tightly, removing any padding at the end
	 * of each image row. It returns true for success, false on failure.
	 */
	bool PackImage();

	/**
	 * Set the image row size in bytes. This can be used to add padding at the
	 * end of each image row. If you attempt to set the row size to a value less
	 * than the storage size of an image row, the function will fail and return
	 * false to indicate an error.
	 */
	bool SetRowSize(long size);
	
	/**
	 * Get the image row size in bytes. This may include padding at the end of
	 * each row of pixels.
	 */
	long GetRowSize() const;

	/**
	 * Get the pixel size of the current pixel format, which is the number of
	 * bytes used to store each pixel. This will depend on the current image
	 * format.
	 */
	long GetPixelSize() const;

	/**
	 * Set row padding. It allows you to add padding at the end of each image
	 * row. It returns true for success, false on failure. Specifying a pad
	 * value of zero will remove any row padding.
	 */
	bool SetRowPad(long pad);

	/**
	 * Get row padding. This returns the number of extra padding bytes at the
	 * end of each image row.
	 */
	long GetRowPad() const;

	/**
	 * Get a pointer to the raw image data. This is useful for use with
	 * functions such as glTexImage2d(). See GetRowData() for more details
	 * of the image storage format.
	 */
	BYTE *GetData();

	/**
	 * Const version of GetData method
	 */
	const BYTE *GetData() const;

	/**
	 * Get a pointer to the raw image data for a particular row. The rows
	 * are numbered 0..Height()-1. Each row consists of Width() pixels,
	 * and the pixel format can be obtained using the GetFormat() method.
	 * If you want to verify the storage size of each pixel, use the
	 * GetPixelSize() method. At the end of each row there may be zero
	 * or more padding bytes. The number of padding bytes can be obtained
	 * with the GetRowPad() method. If the row number is out of range,
	 * this method will return a NULL pointer.
	 * Tip: to simplify your code, you can call SetFormat() to convert the
	 * image to a fixed format first. Then your code only needs to handle
	 * that one particular format. For example, if you SetFormat(RGB),
	 * then each row simply has Width() pixels, each of 3-bytes: Red,Green
	 * and Blue.
	 */
	BYTE *GetRowData(long row);

	/**
	 * Const version of GetRowData method
	 */
	const BYTE *GetRowData(long row) const;

	/**
	 * Flip the image horizontally.
	 */
	void FlipX();

	/**
	 * Flip the image vertically.
	 */
	void FlipY();

private:
	ImageEx *extra;
};

_GXBASE_END

#endif//__Image_H
