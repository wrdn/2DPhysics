#pragma once
#ifndef __Model_H
#define __Model_H

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

#include "GXBase.h"

_GXBASE_BEGIN

//-----------------------------------------------------------------------------

/**
 * Model.h
 *
 * This implements a 3D polygon model class, which can be loaded from file
 * and displayed using OpenGL. It takes care of all the details of loading,
 * transforming, applying materials and rendering the model. It currently
 * loads a subset of the 3DS file format.
 *
 * James Ward, 19th November 2003
 * Dept.of Computer Science
 * University of Hull (UK)
 */

//-----------------------------------------------------------------------------

/**
 * Private context data, used by Model class.
 */
class ModelEx;

//-----------------------------------------------------------------------------

/**
 * Draw styles, which can be used with the DrawGL method.
 */
typedef unsigned long DrawStyle;

// The following values are flags for use with the DrawGL method. They affect
// how the object is rendered using OpenGL.
//
static const DrawStyle
// ONLY ONE of these:
	DSHidden		= 0x0000L,	///< Don't draw anything
	DSPoints		= 0x0001L,	///< Draw as a cloud of points
	DSWire			= 0x0002L,	///< Draw as a plain wireframe
	DSFlat			= 0x0003L,	///< Draw as a plain, flat shaded model
	DSSmooth		= 0x0004L,	///< Draw as a plain, smooth shaded model
	DSMaterial		= 0x0005L,	///< Draw using smooth shading and materials
	DSVertNormTex	= 0x0006L,	///< Draw plain, using vertices,normals,texUV
// plus ANY COMBINATION of these:
	DSNoDisplayList = 0x0100L,	///< hint: don't use display lists (or binding)
	DSNoVertexArray = 0x0200L,	///< hint: don't use vertex arrays
	DSNoVertexBuffer= 0x0400L,	///< hint: don't use vertex buffers
	DSNoDelayTrans	= 0x0800L,	///< hint: don't use delayed transparency
	DSNoStateChange = 0x1000L,	///< hint: don't change state before drawing
	DSNoBindTexture = 0x2000L;	///< hint: don't bind textures	

//-----------------------------------------------------------------------------

/**
 * This class represents a 3D polygon model, which can be loaded from file
 * and displayed using OpenGL. It takes care of all the details of loading,
 * transforming, applying materials and rendering the model.
 */
class Model {
public:
	/**
	 * Default constructor.
	 */
	Model();

	/**
	 * Destructor.
	 */
	virtual ~Model();

	/**
	 * Load a model from file, where the 'name' parameter specifies the
	 * filename or pathname. Returns true for succes, false in case of
	 * failure.
	 */
	bool Load(const char *name);

	/**
	 * Draw the model using OpenGL. This call must be made from a valid
	 * OpenGL display context. The draw style can be altered by using
	 * different combinations of style flags in the 'style' parameter.
	 * When DrawGL is called after loading a model, it may generate OpenGL
	 * display lists, vertex arrays or vertex buffers. In order to later
	 * free these resources, you should call FreeGL() from a valid OpenGL
	 * context. You can prevent these OpenGL allocations by specifying the
	 * appropriate DrawStyle flags, although this may carry a significant
	 * performance penalty.
	 */
	void DrawGL(DrawStyle style = DSMaterial) const;

	/**
	 * Delete the current model, and free any storage that it was using.
	 */
	void Free();

	/**
	 * Free any OpenGL resources that the model is using. This function
	 * must be called from a valid OpenGL context (the same context that
	 * the resources were allocated from).
	 */
	void FreeGL();

	/**
	 * This is a lightweight vector type, used purely for exchanging 3D
	 * vector values with the user (since everyone has their own vector
	 * class, and we don't want to add to the confusion with another)
	 */
	class Vector3f;

	/**
	 * Get centre of object bounding box. This is the midpoint of the
	 * axis aligned bounding box that encloses the object.
	 */
	Vector3f GetBoxCentre() const;

	/**
	 * Get size of object bounding box. This is the size of the axis
	 * aligned bounding box that encloses the object.
	 */
	Vector3f GetBoxSize() const;

	/**
	 * Get total number of vertices.
	 */
	long GetNumVerts() const;

	/**
	 * Get vertex n, where n ranges from 0..GetNumVerts()-1. This returns
	 * the world coordinates of the vertex.
	 */
	Vector3f GetVert(long n);

	/**
	 * Get normal n, where n ranges from 0..GetNumVerts()-1. The normal
	 * is calculated based on the faces that are attached to the vertex,
	 * and the smoothing groups that those faces belong to.
	 */
	Vector3f GetNorm(long n);

	/**
	 * Get total number of faces
	 */
	long GetNumFaces() const;

	class Face;

	/**
	 * Get face n, where n ranges from 0..GetNumFaces()-1. The
	 * face consists of three indices into the vertex array.
	 * Each index is in the range 0..GetNumVerts()-1.
	 */
	Face GetFace(long n);

	/**
	 * Set object scale, relative to original scale when first created
	 * or loaded from file. Note that the scale is applied directly to
	 * the object vertices 'in place', to avoid duplicating vertex data.
	 * It is ideal for one-off scaling, immediately after an object is
	 * loaded for example.
	 * Notes:
	 *	- Object normals are not affected (unlike OpenGL scale)
	 *  - Vertices returned by GetVert are affected by SetScale
	 *  - Performance: may cause display list caches to be rebuilt
	 */
	void SetScale(float s);

	/**
	 * Returns the current object scale, relative to the original scale
	 * when first created or loaded. The scale can be modified by calling
	 * the SetScale method. When the object is first loaded, GetScale()
	 * will return 1.
	 */
	float GetScale() const;

private:
	/**
	 * Private context data. Avoids exposing platform specific types and
	 * implementation details in this header.
	 */
	ModelEx *extra;
};

//-----------------------------------------------------------------------------

/**
 * Simple face class. Stores integer indices of the three vertices that
 * define the face.
 */
class Model::Face {
public:
	Face() :a(0),b(0),c(0) {}

	Face(long A, long B, long C) :a(A),b(B),c(C) {}

	Face(const Face &rhs) {
		*this = rhs;
	}

	Face & operator = (const Face &rhs) {
		a=rhs.a;
		b=rhs.b;
		c=rhs.c;
		return *this;
	}

public:
	long a,b,c;
};

//-----------------------------------------------------------------------------

/**
 * Simple vector class. Stores three floating point values.
 */
class Model::Vector3f {
public:
	Vector3f() { x=y=z=0.0f; }

	Vector3f(float X, float Y, float Z) :x(X),y(Y),z(Z) {}

	Vector3f(const Vector3f &rhs) {
		*this = rhs;
	}

	Vector3f & operator = (const Vector3f &rhs) {
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}

public:
	float x,y,z;
};

//-----------------------------------------------------------------------------

_GXBASE_END

#endif//__Model_h
