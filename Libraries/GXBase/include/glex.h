#pragma once
#ifndef __glex_h
#define __glex_h

/**
 * This is an automatically generated header file: do not edit
 * Generated 2076 functions on Sat Oct 22 20:42:56 2011
 * J.Ward, Computer Science, University of Hull, UK
 * Visit the OpenGL Extensions Registry for detailed
 * extension specifications:
 *   http://www.opengl.org/registry
 */

#include <assert.h>
#include "glexfp.h"

class glex {
public:
	glex();
	virtual ~glex();
	bool Load();
	long Count() const;
	long Known() const;
	bool Supports(const char *) const;
public:
	// GL extension functions

	void glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	void glBlendEquation(GLenum mode);
	void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
	void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
	void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	void glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
	void glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat *params);
	void glColorTableParameteriv(GLenum target, GLenum pname, const GLint *params);
	void glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
	void glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid *table);
	void glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat *params);
	void glGetColorTableParameteriv(GLenum target, GLenum pname, GLint *params);
	void glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
	void glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
	void glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
	void glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
	void glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params);
	void glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat *params);
	void glConvolutionParameteri(GLenum target, GLenum pname, GLint params);
	void glConvolutionParameteriv(GLenum target, GLenum pname, const GLint *params);
	void glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
	void glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
	void glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid *image);
	void glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat *params);
	void glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint *params);
	void glGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
	void glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
	void glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
	void glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat *params);
	void glGetHistogramParameteriv(GLenum target, GLenum pname, GLint *params);
	void glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
	void glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat *params);
	void glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint *params);
	void glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
	void glMinmax(GLenum target, GLenum internalformat, GLboolean sink);
	void glResetHistogram(GLenum target);
	void glResetMinmax(GLenum target);
	void glActiveTexture(GLenum texture);
	void glSampleCoverage(GLclampf value, GLboolean invert);
	void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
	void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
	void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
	void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
	void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
	void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
	void glGetCompressedTexImage(GLenum target, GLint level, GLvoid *img);
	void glClientActiveTexture(GLenum texture);
	void glMultiTexCoord1d(GLenum target, GLdouble s);
	void glMultiTexCoord1dv(GLenum target, const GLdouble *v);
	void glMultiTexCoord1f(GLenum target, GLfloat s);
	void glMultiTexCoord1fv(GLenum target, const GLfloat *v);
	void glMultiTexCoord1i(GLenum target, GLint s);
	void glMultiTexCoord1iv(GLenum target, const GLint *v);
	void glMultiTexCoord1s(GLenum target, GLshort s);
	void glMultiTexCoord1sv(GLenum target, const GLshort *v);
	void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t);
	void glMultiTexCoord2dv(GLenum target, const GLdouble *v);
	void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t);
	void glMultiTexCoord2fv(GLenum target, const GLfloat *v);
	void glMultiTexCoord2i(GLenum target, GLint s, GLint t);
	void glMultiTexCoord2iv(GLenum target, const GLint *v);
	void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t);
	void glMultiTexCoord2sv(GLenum target, const GLshort *v);
	void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r);
	void glMultiTexCoord3dv(GLenum target, const GLdouble *v);
	void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r);
	void glMultiTexCoord3fv(GLenum target, const GLfloat *v);
	void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r);
	void glMultiTexCoord3iv(GLenum target, const GLint *v);
	void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r);
	void glMultiTexCoord3sv(GLenum target, const GLshort *v);
	void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	void glMultiTexCoord4dv(GLenum target, const GLdouble *v);
	void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	void glMultiTexCoord4fv(GLenum target, const GLfloat *v);
	void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q);
	void glMultiTexCoord4iv(GLenum target, const GLint *v);
	void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
	void glMultiTexCoord4sv(GLenum target, const GLshort *v);
	void glLoadTransposeMatrixf(const GLfloat *m);
	void glLoadTransposeMatrixd(const GLdouble *m);
	void glMultTransposeMatrixf(const GLfloat *m);
	void glMultTransposeMatrixd(const GLdouble *m);
	void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	void glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
	void glMultiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount);
	void glPointParameterf(GLenum pname, GLfloat param);
	void glPointParameterfv(GLenum pname, const GLfloat *params);
	void glPointParameteri(GLenum pname, GLint param);
	void glPointParameteriv(GLenum pname, const GLint *params);
	void glFogCoordf(GLfloat coord);
	void glFogCoordfv(const GLfloat *coord);
	void glFogCoordd(GLdouble coord);
	void glFogCoorddv(const GLdouble *coord);
	void glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid *pointer);
	void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue);
	void glSecondaryColor3bv(const GLbyte *v);
	void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue);
	void glSecondaryColor3dv(const GLdouble *v);
	void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue);
	void glSecondaryColor3fv(const GLfloat *v);
	void glSecondaryColor3i(GLint red, GLint green, GLint blue);
	void glSecondaryColor3iv(const GLint *v);
	void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue);
	void glSecondaryColor3sv(const GLshort *v);
	void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue);
	void glSecondaryColor3ubv(const GLubyte *v);
	void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue);
	void glSecondaryColor3uiv(const GLuint *v);
	void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue);
	void glSecondaryColor3usv(const GLushort *v);
	void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	void glWindowPos2d(GLdouble x, GLdouble y);
	void glWindowPos2dv(const GLdouble *v);
	void glWindowPos2f(GLfloat x, GLfloat y);
	void glWindowPos2fv(const GLfloat *v);
	void glWindowPos2i(GLint x, GLint y);
	void glWindowPos2iv(const GLint *v);
	void glWindowPos2s(GLshort x, GLshort y);
	void glWindowPos2sv(const GLshort *v);
	void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z);
	void glWindowPos3dv(const GLdouble *v);
	void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z);
	void glWindowPos3fv(const GLfloat *v);
	void glWindowPos3i(GLint x, GLint y, GLint z);
	void glWindowPos3iv(const GLint *v);
	void glWindowPos3s(GLshort x, GLshort y, GLshort z);
	void glWindowPos3sv(const GLshort *v);
	void glGenQueries(GLsizei n, GLuint *ids);
	void glDeleteQueries(GLsizei n, const GLuint *ids);
	GLboolean glIsQuery(GLuint id);
	void glBeginQuery(GLenum target, GLuint id);
	void glEndQuery(GLenum target);
	void glGetQueryiv(GLenum target, GLenum pname, GLint *params);
	void glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params);
	void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params);
	void glBindBuffer(GLenum target, GLuint buffer);
	void glDeleteBuffers(GLsizei n, const GLuint *buffers);
	void glGenBuffers(GLsizei n, GLuint *buffers);
	GLboolean glIsBuffer(GLuint buffer);
	void glBufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
	void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
	void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data);
	GLvoid* glMapBuffer(GLenum target, GLenum access);
	GLboolean glUnmapBuffer(GLenum target);
	void glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params);
	void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid* *params);
	void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
	void glDrawBuffers(GLsizei n, const GLenum *bufs);
	void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
	void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
	void glStencilMaskSeparate(GLenum face, GLuint mask);
	void glAttachShader(GLuint program, GLuint shader);
	void glBindAttribLocation(GLuint program, GLuint index, const GLchar *name);
	void glCompileShader(GLuint shader);
	GLuint glCreateProgram(void);
	GLuint glCreateShader(GLenum type);
	void glDeleteProgram(GLuint program);
	void glDeleteShader(GLuint shader);
	void glDetachShader(GLuint program, GLuint shader);
	void glDisableVertexAttribArray(GLuint index);
	void glEnableVertexAttribArray(GLuint index);
	void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
	void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
	void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *obj);
	GLint glGetAttribLocation(GLuint program, const GLchar *name);
	void glGetProgramiv(GLuint program, GLenum pname, GLint *params);
	void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	void glGetShaderiv(GLuint shader, GLenum pname, GLint *params);
	void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
	GLint glGetUniformLocation(GLuint program, const GLchar *name);
	void glGetUniformfv(GLuint program, GLint location, GLfloat *params);
	void glGetUniformiv(GLuint program, GLint location, GLint *params);
	void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params);
	void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params);
	void glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params);
	void glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid* *pointer);
	GLboolean glIsProgram(GLuint program);
	GLboolean glIsShader(GLuint shader);
	void glLinkProgram(GLuint program);
	void glShaderSource(GLuint shader, GLsizei count, const GLchar* *string, const GLint *length);
	void glUseProgram(GLuint program);
	void glUniform1f(GLint location, GLfloat v0);
	void glUniform2f(GLint location, GLfloat v0, GLfloat v1);
	void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	void glUniform1i(GLint location, GLint v0);
	void glUniform2i(GLint location, GLint v0, GLint v1);
	void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
	void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	void glUniform1fv(GLint location, GLsizei count, const GLfloat *value);
	void glUniform2fv(GLint location, GLsizei count, const GLfloat *value);
	void glUniform3fv(GLint location, GLsizei count, const GLfloat *value);
	void glUniform4fv(GLint location, GLsizei count, const GLfloat *value);
	void glUniform1iv(GLint location, GLsizei count, const GLint *value);
	void glUniform2iv(GLint location, GLsizei count, const GLint *value);
	void glUniform3iv(GLint location, GLsizei count, const GLint *value);
	void glUniform4iv(GLint location, GLsizei count, const GLint *value);
	void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glValidateProgram(GLuint program);
	void glVertexAttrib1d(GLuint index, GLdouble x);
	void glVertexAttrib1dv(GLuint index, const GLdouble *v);
	void glVertexAttrib1f(GLuint index, GLfloat x);
	void glVertexAttrib1fv(GLuint index, const GLfloat *v);
	void glVertexAttrib1s(GLuint index, GLshort x);
	void glVertexAttrib1sv(GLuint index, const GLshort *v);
	void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y);
	void glVertexAttrib2dv(GLuint index, const GLdouble *v);
	void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
	void glVertexAttrib2fv(GLuint index, const GLfloat *v);
	void glVertexAttrib2s(GLuint index, GLshort x, GLshort y);
	void glVertexAttrib2sv(GLuint index, const GLshort *v);
	void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
	void glVertexAttrib3dv(GLuint index, const GLdouble *v);
	void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
	void glVertexAttrib3fv(GLuint index, const GLfloat *v);
	void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z);
	void glVertexAttrib3sv(GLuint index, const GLshort *v);
	void glVertexAttrib4Nbv(GLuint index, const GLbyte *v);
	void glVertexAttrib4Niv(GLuint index, const GLint *v);
	void glVertexAttrib4Nsv(GLuint index, const GLshort *v);
	void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
	void glVertexAttrib4Nubv(GLuint index, const GLubyte *v);
	void glVertexAttrib4Nuiv(GLuint index, const GLuint *v);
	void glVertexAttrib4Nusv(GLuint index, const GLushort *v);
	void glVertexAttrib4bv(GLuint index, const GLbyte *v);
	void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void glVertexAttrib4dv(GLuint index, const GLdouble *v);
	void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void glVertexAttrib4fv(GLuint index, const GLfloat *v);
	void glVertexAttrib4iv(GLuint index, const GLint *v);
	void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
	void glVertexAttrib4sv(GLuint index, const GLshort *v);
	void glVertexAttrib4ubv(GLuint index, const GLubyte *v);
	void glVertexAttrib4uiv(GLuint index, const GLuint *v);
	void glVertexAttrib4usv(GLuint index, const GLushort *v);
	void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
	void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
	void glGetBooleani_v(GLenum target, GLuint index, GLboolean *data);
	void glGetIntegeri_v(GLenum target, GLuint index, GLint *data);
	void glEnablei(GLenum target, GLuint index);
	void glDisablei(GLenum target, GLuint index);
	GLboolean glIsEnabledi(GLenum target, GLuint index);
	void glBeginTransformFeedback(GLenum primitiveMode);
	void glEndTransformFeedback(void);
	void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	void glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
	void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar* *varyings, GLenum bufferMode);
	void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
	void glClampColor(GLenum target, GLenum clamp);
	void glBeginConditionalRender(GLuint id, GLenum mode);
	void glEndConditionalRender(void);
	void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params);
	void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params);
	void glVertexAttribI1i(GLuint index, GLint x);
	void glVertexAttribI2i(GLuint index, GLint x, GLint y);
	void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z);
	void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w);
	void glVertexAttribI1ui(GLuint index, GLuint x);
	void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y);
	void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z);
	void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	void glVertexAttribI1iv(GLuint index, const GLint *v);
	void glVertexAttribI2iv(GLuint index, const GLint *v);
	void glVertexAttribI3iv(GLuint index, const GLint *v);
	void glVertexAttribI4iv(GLuint index, const GLint *v);
	void glVertexAttribI1uiv(GLuint index, const GLuint *v);
	void glVertexAttribI2uiv(GLuint index, const GLuint *v);
	void glVertexAttribI3uiv(GLuint index, const GLuint *v);
	void glVertexAttribI4uiv(GLuint index, const GLuint *v);
	void glVertexAttribI4bv(GLuint index, const GLbyte *v);
	void glVertexAttribI4sv(GLuint index, const GLshort *v);
	void glVertexAttribI4ubv(GLuint index, const GLubyte *v);
	void glVertexAttribI4usv(GLuint index, const GLushort *v);
	void glGetUniformuiv(GLuint program, GLint location, GLuint *params);
	void glBindFragDataLocation(GLuint program, GLuint color, const GLchar *name);
	GLint glGetFragDataLocation(GLuint program, const GLchar *name);
	void glUniform1ui(GLint location, GLuint v0);
	void glUniform2ui(GLint location, GLuint v0, GLuint v1);
	void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
	void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	void glUniform1uiv(GLint location, GLsizei count, const GLuint *value);
	void glUniform2uiv(GLint location, GLsizei count, const GLuint *value);
	void glUniform3uiv(GLint location, GLsizei count, const GLuint *value);
	void glUniform4uiv(GLint location, GLsizei count, const GLuint *value);
	void glTexParameterIiv(GLenum target, GLenum pname, const GLint *params);
	void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint *params);
	void glGetTexParameterIiv(GLenum target, GLenum pname, GLint *params);
	void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint *params);
	void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value);
	void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value);
	void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value);
	void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
	const GLubyte * glGetStringi(GLenum name, GLuint index);
	void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
	void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount);
	void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer);
	void glPrimitiveRestartIndex(GLuint index);
	void glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data);
	void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params);
	void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level);
	void glVertexAttribDivisor(GLuint index, GLuint divisor);
	void glMinSampleShading(GLclampf value);
	void glBlendEquationi(GLuint buf, GLenum mode);
	void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
	void glBlendFunci(GLuint buf, GLenum src, GLenum dst);
	void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
	void glActiveTextureARB(GLenum texture);
	void glClientActiveTextureARB(GLenum texture);
	void glMultiTexCoord1dARB(GLenum target, GLdouble s);
	void glMultiTexCoord1dvARB(GLenum target, const GLdouble *v);
	void glMultiTexCoord1fARB(GLenum target, GLfloat s);
	void glMultiTexCoord1fvARB(GLenum target, const GLfloat *v);
	void glMultiTexCoord1iARB(GLenum target, GLint s);
	void glMultiTexCoord1ivARB(GLenum target, const GLint *v);
	void glMultiTexCoord1sARB(GLenum target, GLshort s);
	void glMultiTexCoord1svARB(GLenum target, const GLshort *v);
	void glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t);
	void glMultiTexCoord2dvARB(GLenum target, const GLdouble *v);
	void glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t);
	void glMultiTexCoord2fvARB(GLenum target, const GLfloat *v);
	void glMultiTexCoord2iARB(GLenum target, GLint s, GLint t);
	void glMultiTexCoord2ivARB(GLenum target, const GLint *v);
	void glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t);
	void glMultiTexCoord2svARB(GLenum target, const GLshort *v);
	void glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r);
	void glMultiTexCoord3dvARB(GLenum target, const GLdouble *v);
	void glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r);
	void glMultiTexCoord3fvARB(GLenum target, const GLfloat *v);
	void glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r);
	void glMultiTexCoord3ivARB(GLenum target, const GLint *v);
	void glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r);
	void glMultiTexCoord3svARB(GLenum target, const GLshort *v);
	void glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	void glMultiTexCoord4dvARB(GLenum target, const GLdouble *v);
	void glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	void glMultiTexCoord4fvARB(GLenum target, const GLfloat *v);
	void glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q);
	void glMultiTexCoord4ivARB(GLenum target, const GLint *v);
	void glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
	void glMultiTexCoord4svARB(GLenum target, const GLshort *v);
	void glLoadTransposeMatrixfARB(const GLfloat *m);
	void glLoadTransposeMatrixdARB(const GLdouble *m);
	void glMultTransposeMatrixfARB(const GLfloat *m);
	void glMultTransposeMatrixdARB(const GLdouble *m);
	void glSampleCoverageARB(GLclampf value, GLboolean invert);
	void glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
	void glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
	void glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
	void glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
	void glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
	void glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
	void glGetCompressedTexImageARB(GLenum target, GLint level, GLvoid *img);
	void glPointParameterfARB(GLenum pname, GLfloat param);
	void glPointParameterfvARB(GLenum pname, const GLfloat *params);
	void glWeightbvARB(GLint size, const GLbyte *weights);
	void glWeightsvARB(GLint size, const GLshort *weights);
	void glWeightivARB(GLint size, const GLint *weights);
	void glWeightfvARB(GLint size, const GLfloat *weights);
	void glWeightdvARB(GLint size, const GLdouble *weights);
	void glWeightubvARB(GLint size, const GLubyte *weights);
	void glWeightusvARB(GLint size, const GLushort *weights);
	void glWeightuivARB(GLint size, const GLuint *weights);
	void glWeightPointerARB(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	void glVertexBlendARB(GLint count);
	void glCurrentPaletteMatrixARB(GLint index);
	void glMatrixIndexubvARB(GLint size, const GLubyte *indices);
	void glMatrixIndexusvARB(GLint size, const GLushort *indices);
	void glMatrixIndexuivARB(GLint size, const GLuint *indices);
	void glMatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	void glWindowPos2dARB(GLdouble x, GLdouble y);
	void glWindowPos2dvARB(const GLdouble *v);
	void glWindowPos2fARB(GLfloat x, GLfloat y);
	void glWindowPos2fvARB(const GLfloat *v);
	void glWindowPos2iARB(GLint x, GLint y);
	void glWindowPos2ivARB(const GLint *v);
	void glWindowPos2sARB(GLshort x, GLshort y);
	void glWindowPos2svARB(const GLshort *v);
	void glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z);
	void glWindowPos3dvARB(const GLdouble *v);
	void glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z);
	void glWindowPos3fvARB(const GLfloat *v);
	void glWindowPos3iARB(GLint x, GLint y, GLint z);
	void glWindowPos3ivARB(const GLint *v);
	void glWindowPos3sARB(GLshort x, GLshort y, GLshort z);
	void glWindowPos3svARB(const GLshort *v);
	void glVertexAttrib1dARB(GLuint index, GLdouble x);
	void glVertexAttrib1dvARB(GLuint index, const GLdouble *v);
	void glVertexAttrib1fARB(GLuint index, GLfloat x);
	void glVertexAttrib1fvARB(GLuint index, const GLfloat *v);
	void glVertexAttrib1sARB(GLuint index, GLshort x);
	void glVertexAttrib1svARB(GLuint index, const GLshort *v);
	void glVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y);
	void glVertexAttrib2dvARB(GLuint index, const GLdouble *v);
	void glVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y);
	void glVertexAttrib2fvARB(GLuint index, const GLfloat *v);
	void glVertexAttrib2sARB(GLuint index, GLshort x, GLshort y);
	void glVertexAttrib2svARB(GLuint index, const GLshort *v);
	void glVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z);
	void glVertexAttrib3dvARB(GLuint index, const GLdouble *v);
	void glVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z);
	void glVertexAttrib3fvARB(GLuint index, const GLfloat *v);
	void glVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z);
	void glVertexAttrib3svARB(GLuint index, const GLshort *v);
	void glVertexAttrib4NbvARB(GLuint index, const GLbyte *v);
	void glVertexAttrib4NivARB(GLuint index, const GLint *v);
	void glVertexAttrib4NsvARB(GLuint index, const GLshort *v);
	void glVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
	void glVertexAttrib4NubvARB(GLuint index, const GLubyte *v);
	void glVertexAttrib4NuivARB(GLuint index, const GLuint *v);
	void glVertexAttrib4NusvARB(GLuint index, const GLushort *v);
	void glVertexAttrib4bvARB(GLuint index, const GLbyte *v);
	void glVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void glVertexAttrib4dvARB(GLuint index, const GLdouble *v);
	void glVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void glVertexAttrib4fvARB(GLuint index, const GLfloat *v);
	void glVertexAttrib4ivARB(GLuint index, const GLint *v);
	void glVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
	void glVertexAttrib4svARB(GLuint index, const GLshort *v);
	void glVertexAttrib4ubvARB(GLuint index, const GLubyte *v);
	void glVertexAttrib4uivARB(GLuint index, const GLuint *v);
	void glVertexAttrib4usvARB(GLuint index, const GLushort *v);
	void glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
	void glEnableVertexAttribArrayARB(GLuint index);
	void glDisableVertexAttribArrayARB(GLuint index);
	void glProgramStringARB(GLenum target, GLenum format, GLsizei len, const GLvoid *string);
	void glBindProgramARB(GLenum target, GLuint program);
	void glDeleteProgramsARB(GLsizei n, const GLuint *programs);
	void glGenProgramsARB(GLsizei n, GLuint *programs);
	void glProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void glProgramEnvParameter4dvARB(GLenum target, GLuint index, const GLdouble *params);
	void glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void glProgramEnvParameter4fvARB(GLenum target, GLuint index, const GLfloat *params);
	void glProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void glProgramLocalParameter4dvARB(GLenum target, GLuint index, const GLdouble *params);
	void glProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void glProgramLocalParameter4fvARB(GLenum target, GLuint index, const GLfloat *params);
	void glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble *params);
	void glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat *params);
	void glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble *params);
	void glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat *params);
	void glGetProgramivARB(GLenum target, GLenum pname, GLint *params);
	void glGetProgramStringARB(GLenum target, GLenum pname, GLvoid *string);
	void glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble *params);
	void glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat *params);
	void glGetVertexAttribivARB(GLuint index, GLenum pname, GLint *params);
	void glGetVertexAttribPointervARB(GLuint index, GLenum pname, GLvoid* *pointer);
	GLboolean glIsProgramARB(GLuint program);
	void glBindBufferARB(GLenum target, GLuint buffer);
	void glDeleteBuffersARB(GLsizei n, const GLuint *buffers);
	void glGenBuffersARB(GLsizei n, GLuint *buffers);
	GLboolean glIsBufferARB(GLuint buffer);
	void glBufferDataARB(GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage);
	void glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data);
	void glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data);
	GLvoid* glMapBufferARB(GLenum target, GLenum access);
	GLboolean glUnmapBufferARB(GLenum target);
	void glGetBufferParameterivARB(GLenum target, GLenum pname, GLint *params);
	void glGetBufferPointervARB(GLenum target, GLenum pname, GLvoid* *params);
	void glGenQueriesARB(GLsizei n, GLuint *ids);
	void glDeleteQueriesARB(GLsizei n, const GLuint *ids);
	GLboolean glIsQueryARB(GLuint id);
	void glBeginQueryARB(GLenum target, GLuint id);
	void glEndQueryARB(GLenum target);
	void glGetQueryivARB(GLenum target, GLenum pname, GLint *params);
	void glGetQueryObjectivARB(GLuint id, GLenum pname, GLint *params);
	void glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint *params);
	void glDeleteObjectARB(GLhandleARB obj);
	GLhandleARB glGetHandleARB(GLenum pname);
	void glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj);
	GLhandleARB glCreateShaderObjectARB(GLenum shaderType);
	void glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, const GLcharARB* *string, const GLint *length);
	void glCompileShaderARB(GLhandleARB shaderObj);
	GLhandleARB glCreateProgramObjectARB(void);
	void glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj);
	void glLinkProgramARB(GLhandleARB programObj);
	void glUseProgramObjectARB(GLhandleARB programObj);
	void glValidateProgramARB(GLhandleARB programObj);
	void glUniform1fARB(GLint location, GLfloat v0);
	void glUniform2fARB(GLint location, GLfloat v0, GLfloat v1);
	void glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	void glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	void glUniform1iARB(GLint location, GLint v0);
	void glUniform2iARB(GLint location, GLint v0, GLint v1);
	void glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2);
	void glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	void glUniform1fvARB(GLint location, GLsizei count, const GLfloat *value);
	void glUniform2fvARB(GLint location, GLsizei count, const GLfloat *value);
	void glUniform3fvARB(GLint location, GLsizei count, const GLfloat *value);
	void glUniform4fvARB(GLint location, GLsizei count, const GLfloat *value);
	void glUniform1ivARB(GLint location, GLsizei count, const GLint *value);
	void glUniform2ivARB(GLint location, GLsizei count, const GLint *value);
	void glUniform3ivARB(GLint location, GLsizei count, const GLint *value);
	void glUniform4ivARB(GLint location, GLsizei count, const GLint *value);
	void glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat *params);
	void glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint *params);
	void glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
	void glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
	GLint glGetUniformLocationARB(GLhandleARB programObj, const GLcharARB *name);
	void glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
	void glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat *params);
	void glGetUniformivARB(GLhandleARB programObj, GLint location, GLint *params);
	void glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source);
	void glBindAttribLocationARB(GLhandleARB programObj, GLuint index, const GLcharARB *name);
	void glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
	GLint glGetAttribLocationARB(GLhandleARB programObj, const GLcharARB *name);
	void glDrawBuffersARB(GLsizei n, const GLenum *bufs);
	void glClampColorARB(GLenum target, GLenum clamp);
	void glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
	void glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount);
	GLboolean glIsRenderbuffer(GLuint renderbuffer);
	void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
	void glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers);
	void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers);
	void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params);
	GLboolean glIsFramebuffer(GLuint framebuffer);
	void glBindFramebuffer(GLenum target, GLuint framebuffer);
	void glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers);
	void glGenFramebuffers(GLsizei n, GLuint *framebuffers);
	GLenum glCheckFramebufferStatus(GLenum target);
	void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
	void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params);
	void glGenerateMipmap(GLenum target);
	void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	void glProgramParameteriARB(GLuint program, GLenum pname, GLint value);
	void glFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level);
	void glFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	void glFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
	void glVertexAttribDivisorARB(GLuint index, GLuint divisor);
	GLvoid* glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
	void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);
	void glTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer);
	void glBindVertexArray(GLuint array);
	void glDeleteVertexArrays(GLsizei n, const GLuint *arrays);
	void glGenVertexArrays(GLsizei n, GLuint *arrays);
	GLboolean glIsVertexArray(GLuint array);
	void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar* *uniformNames, GLuint *uniformIndices);
	void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
	void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
	GLuint glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName);
	void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
	void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
	void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
	void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
	void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint basevertex);
	void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint basevertex);
	void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount, GLint basevertex);
	void glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount, const GLint *basevertex);
	void glProvokingVertex(GLenum mode);
	GLsync glFenceSync(GLenum condition, GLbitfield flags);
	GLboolean glIsSync(GLsync sync);
	void glDeleteSync(GLsync sync);
	GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
	void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
	void glGetInteger64v(GLenum pname, GLint64 *params);
	void glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
	void glTexImage2DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	void glTexImage3DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
	void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val);
	void glSampleMaski(GLuint index, GLbitfield mask);
	void glBlendEquationiARB(GLuint buf, GLenum mode);
	void glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
	void glBlendFunciARB(GLuint buf, GLenum src, GLenum dst);
	void glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
	void glMinSampleShadingARB(GLclampf value);
	void glNamedStringARB(GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
	void glDeleteNamedStringARB(GLint namelen, const GLchar *name);
	void glCompileShaderIncludeARB(GLuint shader, GLsizei count, const GLchar* *path, const GLint *length);
	GLboolean glIsNamedStringARB(GLint namelen, const GLchar *name);
	void glGetNamedStringARB(GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
	void glGetNamedStringivARB(GLint namelen, const GLchar *name, GLenum pname, GLint *params);
	void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
	GLint glGetFragDataIndex(GLuint program, const GLchar *name);
	void glGenSamplers(GLsizei count, GLuint *samplers);
	void glDeleteSamplers(GLsizei count, const GLuint *samplers);
	GLboolean glIsSampler(GLuint sampler);
	void glBindSampler(GLuint unit, GLuint sampler);
	void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param);
	void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param);
	void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param);
	void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param);
	void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param);
	void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *param);
	void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params);
	void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params);
	void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params);
	void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params);
	void glQueryCounter(GLuint id, GLenum target);
	void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 *params);
	void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params);
	void glVertexP2ui(GLenum type, GLuint value);
	void glVertexP2uiv(GLenum type, const GLuint *value);
	void glVertexP3ui(GLenum type, GLuint value);
	void glVertexP3uiv(GLenum type, const GLuint *value);
	void glVertexP4ui(GLenum type, GLuint value);
	void glVertexP4uiv(GLenum type, const GLuint *value);
	void glTexCoordP1ui(GLenum type, GLuint coords);
	void glTexCoordP1uiv(GLenum type, const GLuint *coords);
	void glTexCoordP2ui(GLenum type, GLuint coords);
	void glTexCoordP2uiv(GLenum type, const GLuint *coords);
	void glTexCoordP3ui(GLenum type, GLuint coords);
	void glTexCoordP3uiv(GLenum type, const GLuint *coords);
	void glTexCoordP4ui(GLenum type, GLuint coords);
	void glTexCoordP4uiv(GLenum type, const GLuint *coords);
	void glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords);
	void glMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint *coords);
	void glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords);
	void glMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint *coords);
	void glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords);
	void glMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint *coords);
	void glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords);
	void glMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint *coords);
	void glNormalP3ui(GLenum type, GLuint coords);
	void glNormalP3uiv(GLenum type, const GLuint *coords);
	void glColorP3ui(GLenum type, GLuint color);
	void glColorP3uiv(GLenum type, const GLuint *color);
	void glColorP4ui(GLenum type, GLuint color);
	void glColorP4uiv(GLenum type, const GLuint *color);
	void glSecondaryColorP3ui(GLenum type, GLuint color);
	void glSecondaryColorP3uiv(GLenum type, const GLuint *color);
	void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
	void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
	void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
	void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
	void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	void glDrawArraysIndirect(GLenum mode, const GLvoid *indirect);
	void glDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid *indirect);
	void glUniform1d(GLint location, GLdouble x);
	void glUniform2d(GLint location, GLdouble x, GLdouble y);
	void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z);
	void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void glUniform1dv(GLint location, GLsizei count, const GLdouble *value);
	void glUniform2dv(GLint location, GLsizei count, const GLdouble *value);
	void glUniform3dv(GLint location, GLsizei count, const GLdouble *value);
	void glUniform4dv(GLint location, GLsizei count, const GLdouble *value);
	void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glGetUniformdv(GLuint program, GLint location, GLdouble *params);
	GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar *name);
	GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name);
	void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
	void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
	void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
	void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices);
	void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint *params);
	void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
	void glPatchParameteri(GLenum pname, GLint value);
	void glPatchParameterfv(GLenum pname, const GLfloat *values);
	void glBindTransformFeedback(GLenum target, GLuint id);
	void glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids);
	void glGenTransformFeedbacks(GLsizei n, GLuint *ids);
	GLboolean glIsTransformFeedback(GLuint id);
	void glPauseTransformFeedback(void);
	void glResumeTransformFeedback(void);
	void glDrawTransformFeedback(GLenum mode, GLuint id);
	void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream);
	void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id);
	void glEndQueryIndexed(GLenum target, GLuint index);
	void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint *params);
	void glReleaseShaderCompiler(void);
	void glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryformat, const GLvoid *binary, GLsizei length);
	void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
	void glDepthRangef(GLclampf n, GLclampf f);
	void glClearDepthf(GLclampf d);
	void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary);
	void glProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length);
	void glProgramParameteri(GLuint program, GLenum pname, GLint value);
	void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program);
	void glActiveShaderProgram(GLuint pipeline, GLuint program);
	GLuint glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar* *strings);
	void glBindProgramPipeline(GLuint pipeline);
	void glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines);
	void glGenProgramPipelines(GLsizei n, GLuint *pipelines);
	GLboolean glIsProgramPipeline(GLuint pipeline);
	void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params);
	void glProgramUniform1i(GLuint program, GLint location, GLint v0);
	void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value);
	void glProgramUniform1f(GLuint program, GLint location, GLfloat v0);
	void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	void glProgramUniform1d(GLuint program, GLint location, GLdouble v0);
	void glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	void glProgramUniform1ui(GLuint program, GLint location, GLuint v0);
	void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
	void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1);
	void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value);
	void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1);
	void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	void glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1);
	void glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	void glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1);
	void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
	void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
	void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value);
	void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	void glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
	void glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	void glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
	void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
	void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value);
	void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	void glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
	void glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	void glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
	void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glValidateProgramPipeline(GLuint pipeline);
	void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	void glVertexAttribL1d(GLuint index, GLdouble x);
	void glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y);
	void glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
	void glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void glVertexAttribL1dv(GLuint index, const GLdouble *v);
	void glVertexAttribL2dv(GLuint index, const GLdouble *v);
	void glVertexAttribL3dv(GLuint index, const GLdouble *v);
	void glVertexAttribL4dv(GLuint index, const GLdouble *v);
	void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params);
	void glViewportArrayv(GLuint first, GLsizei count, const GLfloat *v);
	void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
	void glViewportIndexedfv(GLuint index, const GLfloat *v);
	void glScissorArrayv(GLuint first, GLsizei count, const GLint *v);
	void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
	void glScissorIndexedv(GLuint index, const GLint *v);
	void glDepthRangeArrayv(GLuint first, GLsizei count, const GLclampd *v);
	void glDepthRangeIndexed(GLuint index, GLclampd n, GLclampd f);
	void glGetFloati_v(GLenum target, GLuint index, GLfloat *data);
	void glGetDoublei_v(GLenum target, GLuint index, GLdouble *data);
	GLsync glCreateSyncFromCLeventARB(struct _cl_context * context, struct _cl_event * event, GLbitfield flags);
	void glDebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
	void glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
	void glDebugMessageCallbackARB(GLDEBUGPROCARB callback, const GLvoid *userParam);
	GLuint glGetDebugMessageLogARB(GLuint count, GLsizei bufsize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
	GLenum glGetGraphicsResetStatusARB(void);
	void glGetnMapdvARB(GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
	void glGetnMapfvARB(GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
	void glGetnMapivARB(GLenum target, GLenum query, GLsizei bufSize, GLint *v);
	void glGetnPixelMapfvARB(GLenum map, GLsizei bufSize, GLfloat *values);
	void glGetnPixelMapuivARB(GLenum map, GLsizei bufSize, GLuint *values);
	void glGetnPixelMapusvARB(GLenum map, GLsizei bufSize, GLushort *values);
	void glGetnPolygonStippleARB(GLsizei bufSize, GLubyte *pattern);
	void glGetnColorTableARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid *table);
	void glGetnConvolutionFilterARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid *image);
	void glGetnSeparableFilterARB(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, GLvoid *row, GLsizei columnBufSize, GLvoid *column, GLvoid *span);
	void glGetnHistogramARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid *values);
	void glGetnMinmaxARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid *values);
	void glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid *img);
	void glReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid *data);
	void glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, GLvoid *img);
	void glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
	void glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint *params);
	void glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
	void glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
	void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLuint baseinstance);
	void glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount, GLuint baseinstance);
	void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount, GLint basevertex, GLuint baseinstance);
	void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei primcount);
	void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei primcount);
	void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
	void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
	void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
	void glMemoryBarrier(GLbitfield barriers);
	void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
	void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
	void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
	void glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
	void glTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
	void glTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
	void glBlendColorEXT(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	void glPolygonOffsetEXT(GLfloat factor, GLfloat bias);
	void glTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	void glTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
	void glGetTexFilterFuncSGIS(GLenum target, GLenum filter, GLfloat *weights);
	void glTexFilterFuncSGIS(GLenum target, GLenum filter, GLsizei n, const GLfloat *weights);
	void glTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
	void glTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
	void glCopyTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
	void glCopyTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	void glCopyTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	void glCopyTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	void glCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	void glGetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
	void glGetHistogramParameterfvEXT(GLenum target, GLenum pname, GLfloat *params);
	void glGetHistogramParameterivEXT(GLenum target, GLenum pname, GLint *params);
	void glGetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
	void glGetMinmaxParameterfvEXT(GLenum target, GLenum pname, GLfloat *params);
	void glGetMinmaxParameterivEXT(GLenum target, GLenum pname, GLint *params);
	void glHistogramEXT(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
	void glMinmaxEXT(GLenum target, GLenum internalformat, GLboolean sink);
	void glResetHistogramEXT(GLenum target);
	void glResetMinmaxEXT(GLenum target);
	void glConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
	void glConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
	void glConvolutionParameterfEXT(GLenum target, GLenum pname, GLfloat params);
	void glConvolutionParameterfvEXT(GLenum target, GLenum pname, const GLfloat *params);
	void glConvolutionParameteriEXT(GLenum target, GLenum pname, GLint params);
	void glConvolutionParameterivEXT(GLenum target, GLenum pname, const GLint *params);
	void glCopyConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
	void glCopyConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
	void glGetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid *image);
	void glGetConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat *params);
	void glGetConvolutionParameterivEXT(GLenum target, GLenum pname, GLint *params);
	void glGetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
	void glSeparableFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
	void glColorTableSGI(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
	void glColorTableParameterfvSGI(GLenum target, GLenum pname, const GLfloat *params);
	void glColorTableParameterivSGI(GLenum target, GLenum pname, const GLint *params);
	void glCopyColorTableSGI(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
	void glGetColorTableSGI(GLenum target, GLenum format, GLenum type, GLvoid *table);
	void glGetColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat *params);
	void glGetColorTableParameterivSGI(GLenum target, GLenum pname, GLint *params);
	void glPixelTexGenSGIX(GLenum mode);
	void glPixelTexGenParameteriSGIS(GLenum pname, GLint param);
	void glPixelTexGenParameterivSGIS(GLenum pname, const GLint *params);
	void glPixelTexGenParameterfSGIS(GLenum pname, GLfloat param);
	void glPixelTexGenParameterfvSGIS(GLenum pname, const GLfloat *params);
	void glGetPixelTexGenParameterivSGIS(GLenum pname, GLint *params);
	void glGetPixelTexGenParameterfvSGIS(GLenum pname, GLfloat *params);
	void glTexImage4DSGIS(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	void glTexSubImage4DSGIS(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const GLvoid *pixels);
	GLboolean glAreTexturesResidentEXT(GLsizei n, const GLuint *textures, GLboolean *residences);
	void glBindTextureEXT(GLenum target, GLuint texture);
	void glDeleteTexturesEXT(GLsizei n, const GLuint *textures);
	void glGenTexturesEXT(GLsizei n, GLuint *textures);
	GLboolean glIsTextureEXT(GLuint texture);
	void glPrioritizeTexturesEXT(GLsizei n, const GLuint *textures, const GLclampf *priorities);
	void glDetailTexFuncSGIS(GLenum target, GLsizei n, const GLfloat *points);
	void glGetDetailTexFuncSGIS(GLenum target, GLfloat *points);
	void glSharpenTexFuncSGIS(GLenum target, GLsizei n, const GLfloat *points);
	void glGetSharpenTexFuncSGIS(GLenum target, GLfloat *points);
	void glSampleMaskSGIS(GLclampf value, GLboolean invert);
	void glSamplePatternSGIS(GLenum pattern);
	void glArrayElementEXT(GLint i);
	void glColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
	void glDrawArraysEXT(GLenum mode, GLint first, GLsizei count);
	void glEdgeFlagPointerEXT(GLsizei stride, GLsizei count, const GLboolean *pointer);
	void glGetPointervEXT(GLenum pname, GLvoid* *params);
	void glIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
	void glNormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
	void glTexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
	void glVertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
	void glBlendEquationEXT(GLenum mode);
	void glSpriteParameterfSGIX(GLenum pname, GLfloat param);
	void glSpriteParameterfvSGIX(GLenum pname, const GLfloat *params);
	void glSpriteParameteriSGIX(GLenum pname, GLint param);
	void glSpriteParameterivSGIX(GLenum pname, const GLint *params);
	void glPointParameterfEXT(GLenum pname, GLfloat param);
	void glPointParameterfvEXT(GLenum pname, const GLfloat *params);
	void glPointParameterfSGIS(GLenum pname, GLfloat param);
	void glPointParameterfvSGIS(GLenum pname, const GLfloat *params);
	GLint glGetInstrumentsSGIX(void);
	void glInstrumentsBufferSGIX(GLsizei size, GLint *buffer);
	GLint glPollInstrumentsSGIX(GLint *marker_p);
	void glReadInstrumentsSGIX(GLint marker);
	void glStartInstrumentsSGIX(void);
	void glStopInstrumentsSGIX(GLint marker);
	void glFrameZoomSGIX(GLint factor);
	void glTagSampleBufferSGIX(void);
	void glDeformationMap3dSGIX(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble *points);
	void glDeformationMap3fSGIX(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat *points);
	void glDeformSGIX(GLbitfield mask);
	void glLoadIdentityDeformationMapSGIX(GLbitfield mask);
	void glReferencePlaneSGIX(const GLdouble *equation);
	void glFlushRasterSGIX(void);
	void glFogFuncSGIS(GLsizei n, const GLfloat *points);
	void glGetFogFuncSGIS(GLfloat *points);
	void glImageTransformParameteriHP(GLenum target, GLenum pname, GLint param);
	void glImageTransformParameterfHP(GLenum target, GLenum pname, GLfloat param);
	void glImageTransformParameterivHP(GLenum target, GLenum pname, const GLint *params);
	void glImageTransformParameterfvHP(GLenum target, GLenum pname, const GLfloat *params);
	void glGetImageTransformParameterivHP(GLenum target, GLenum pname, GLint *params);
	void glGetImageTransformParameterfvHP(GLenum target, GLenum pname, GLfloat *params);
	void glColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
	void glCopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
	void glHintPGI(GLenum target, GLint mode);
	void glColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
	void glGetColorTableEXT(GLenum target, GLenum format, GLenum type, GLvoid *data);
	void glGetColorTableParameterivEXT(GLenum target, GLenum pname, GLint *params);
	void glGetColorTableParameterfvEXT(GLenum target, GLenum pname, GLfloat *params);
	void glGetListParameterfvSGIX(GLuint list, GLenum pname, GLfloat *params);
	void glGetListParameterivSGIX(GLuint list, GLenum pname, GLint *params);
	void glListParameterfSGIX(GLuint list, GLenum pname, GLfloat param);
	void glListParameterfvSGIX(GLuint list, GLenum pname, const GLfloat *params);
	void glListParameteriSGIX(GLuint list, GLenum pname, GLint param);
	void glListParameterivSGIX(GLuint list, GLenum pname, const GLint *params);
	void glIndexMaterialEXT(GLenum face, GLenum mode);
	void glIndexFuncEXT(GLenum func, GLclampf ref);
	void glLockArraysEXT(GLint first, GLsizei count);
	void glUnlockArraysEXT(void);
	void glCullParameterdvEXT(GLenum pname, GLdouble *params);
	void glCullParameterfvEXT(GLenum pname, GLfloat *params);
	void glFragmentColorMaterialSGIX(GLenum face, GLenum mode);
	void glFragmentLightfSGIX(GLenum light, GLenum pname, GLfloat param);
	void glFragmentLightfvSGIX(GLenum light, GLenum pname, const GLfloat *params);
	void glFragmentLightiSGIX(GLenum light, GLenum pname, GLint param);
	void glFragmentLightivSGIX(GLenum light, GLenum pname, const GLint *params);
	void glFragmentLightModelfSGIX(GLenum pname, GLfloat param);
	void glFragmentLightModelfvSGIX(GLenum pname, const GLfloat *params);
	void glFragmentLightModeliSGIX(GLenum pname, GLint param);
	void glFragmentLightModelivSGIX(GLenum pname, const GLint *params);
	void glFragmentMaterialfSGIX(GLenum face, GLenum pname, GLfloat param);
	void glFragmentMaterialfvSGIX(GLenum face, GLenum pname, const GLfloat *params);
	void glFragmentMaterialiSGIX(GLenum face, GLenum pname, GLint param);
	void glFragmentMaterialivSGIX(GLenum face, GLenum pname, const GLint *params);
	void glGetFragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat *params);
	void glGetFragmentLightivSGIX(GLenum light, GLenum pname, GLint *params);
	void glGetFragmentMaterialfvSGIX(GLenum face, GLenum pname, GLfloat *params);
	void glGetFragmentMaterialivSGIX(GLenum face, GLenum pname, GLint *params);
	void glLightEnviSGIX(GLenum pname, GLint param);
	void glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
	void glApplyTextureEXT(GLenum mode);
	void glTextureLightEXT(GLenum pname);
	void glTextureMaterialEXT(GLenum face, GLenum mode);
	void glAsyncMarkerSGIX(GLuint marker);
	GLint glFinishAsyncSGIX(GLuint *markerp);
	GLint glPollAsyncSGIX(GLuint *markerp);
	GLuint glGenAsyncMarkersSGIX(GLsizei range);
	void glDeleteAsyncMarkersSGIX(GLuint marker, GLsizei range);
	GLboolean glIsAsyncMarkerSGIX(GLuint marker);
	void glVertexPointervINTEL(GLint size, GLenum type, const GLvoid* *pointer);
	void glNormalPointervINTEL(GLenum type, const GLvoid* *pointer);
	void glColorPointervINTEL(GLint size, GLenum type, const GLvoid* *pointer);
	void glTexCoordPointervINTEL(GLint size, GLenum type, const GLvoid* *pointer);
	void glPixelTransformParameteriEXT(GLenum target, GLenum pname, GLint param);
	void glPixelTransformParameterfEXT(GLenum target, GLenum pname, GLfloat param);
	void glPixelTransformParameterivEXT(GLenum target, GLenum pname, const GLint *params);
	void glPixelTransformParameterfvEXT(GLenum target, GLenum pname, const GLfloat *params);
	void glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue);
	void glSecondaryColor3bvEXT(const GLbyte *v);
	void glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue);
	void glSecondaryColor3dvEXT(const GLdouble *v);
	void glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue);
	void glSecondaryColor3fvEXT(const GLfloat *v);
	void glSecondaryColor3iEXT(GLint red, GLint green, GLint blue);
	void glSecondaryColor3ivEXT(const GLint *v);
	void glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue);
	void glSecondaryColor3svEXT(const GLshort *v);
	void glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue);
	void glSecondaryColor3ubvEXT(const GLubyte *v);
	void glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue);
	void glSecondaryColor3uivEXT(const GLuint *v);
	void glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue);
	void glSecondaryColor3usvEXT(const GLushort *v);
	void glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	void glTextureNormalEXT(GLenum mode);
	void glMultiDrawArraysEXT(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
	void glMultiDrawElementsEXT(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount);
	void glFogCoordfEXT(GLfloat coord);
	void glFogCoordfvEXT(const GLfloat *coord);
	void glFogCoorddEXT(GLdouble coord);
	void glFogCoorddvEXT(const GLdouble *coord);
	void glFogCoordPointerEXT(GLenum type, GLsizei stride, const GLvoid *pointer);
	void glTangent3bEXT(GLbyte tx, GLbyte ty, GLbyte tz);
	void glTangent3bvEXT(const GLbyte *v);
	void glTangent3dEXT(GLdouble tx, GLdouble ty, GLdouble tz);
	void glTangent3dvEXT(const GLdouble *v);
	void glTangent3fEXT(GLfloat tx, GLfloat ty, GLfloat tz);
	void glTangent3fvEXT(const GLfloat *v);
	void glTangent3iEXT(GLint tx, GLint ty, GLint tz);
	void glTangent3ivEXT(const GLint *v);
	void glTangent3sEXT(GLshort tx, GLshort ty, GLshort tz);
	void glTangent3svEXT(const GLshort *v);
	void glBinormal3bEXT(GLbyte bx, GLbyte by, GLbyte bz);
	void glBinormal3bvEXT(const GLbyte *v);
	void glBinormal3dEXT(GLdouble bx, GLdouble by, GLdouble bz);
	void glBinormal3dvEXT(const GLdouble *v);
	void glBinormal3fEXT(GLfloat bx, GLfloat by, GLfloat bz);
	void glBinormal3fvEXT(const GLfloat *v);
	void glBinormal3iEXT(GLint bx, GLint by, GLint bz);
	void glBinormal3ivEXT(const GLint *v);
	void glBinormal3sEXT(GLshort bx, GLshort by, GLshort bz);
	void glBinormal3svEXT(const GLshort *v);
	void glTangentPointerEXT(GLenum type, GLsizei stride, const GLvoid *pointer);
	void glBinormalPointerEXT(GLenum type, GLsizei stride, const GLvoid *pointer);
	void glFinishTextureSUNX(void);
	void glGlobalAlphaFactorbSUN(GLbyte factor);
	void glGlobalAlphaFactorsSUN(GLshort factor);
	void glGlobalAlphaFactoriSUN(GLint factor);
	void glGlobalAlphaFactorfSUN(GLfloat factor);
	void glGlobalAlphaFactordSUN(GLdouble factor);
	void glGlobalAlphaFactorubSUN(GLubyte factor);
	void glGlobalAlphaFactorusSUN(GLushort factor);
	void glGlobalAlphaFactoruiSUN(GLuint factor);
	void glReplacementCodeuiSUN(GLuint code);
	void glReplacementCodeusSUN(GLushort code);
	void glReplacementCodeubSUN(GLubyte code);
	void glReplacementCodeuivSUN(const GLuint *code);
	void glReplacementCodeusvSUN(const GLushort *code);
	void glReplacementCodeubvSUN(const GLubyte *code);
	void glReplacementCodePointerSUN(GLenum type, GLsizei stride, const GLvoid* *pointer);
	void glColor4ubVertex2fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
	void glColor4ubVertex2fvSUN(const GLubyte *c, const GLfloat *v);
	void glColor4ubVertex3fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
	void glColor4ubVertex3fvSUN(const GLubyte *c, const GLfloat *v);
	void glColor3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
	void glColor3fVertex3fvSUN(const GLfloat *c, const GLfloat *v);
	void glNormal3fVertex3fSUN(GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	void glNormal3fVertex3fvSUN(const GLfloat *n, const GLfloat *v);
	void glColor4fNormal3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	void glColor4fNormal3fVertex3fvSUN(const GLfloat *c, const GLfloat *n, const GLfloat *v);
	void glTexCoord2fVertex3fSUN(GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
	void glTexCoord2fVertex3fvSUN(const GLfloat *tc, const GLfloat *v);
	void glTexCoord4fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void glTexCoord4fVertex4fvSUN(const GLfloat *tc, const GLfloat *v);
	void glTexCoord2fColor4ubVertex3fSUN(GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
	void glTexCoord2fColor4ubVertex3fvSUN(const GLfloat *tc, const GLubyte *c, const GLfloat *v);
	void glTexCoord2fColor3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
	void glTexCoord2fColor3fVertex3fvSUN(const GLfloat *tc, const GLfloat *c, const GLfloat *v);
	void glTexCoord2fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	void glTexCoord2fNormal3fVertex3fvSUN(const GLfloat *tc, const GLfloat *n, const GLfloat *v);
	void glTexCoord2fColor4fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	void glTexCoord2fColor4fNormal3fVertex3fvSUN(const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
	void glTexCoord4fColor4fNormal3fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void glTexCoord4fColor4fNormal3fVertex4fvSUN(const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
	void glReplacementCodeuiVertex3fSUN(GLuint rc, GLfloat x, GLfloat y, GLfloat z);
	void glReplacementCodeuiVertex3fvSUN(const GLuint *rc, const GLfloat *v);
	void glReplacementCodeuiColor4ubVertex3fSUN(GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
	void glReplacementCodeuiColor4ubVertex3fvSUN(const GLuint *rc, const GLubyte *c, const GLfloat *v);
	void glReplacementCodeuiColor3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
	void glReplacementCodeuiColor3fVertex3fvSUN(const GLuint *rc, const GLfloat *c, const GLfloat *v);
	void glReplacementCodeuiNormal3fVertex3fSUN(GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	void glReplacementCodeuiNormal3fVertex3fvSUN(const GLuint *rc, const GLfloat *n, const GLfloat *v);
	void glReplacementCodeuiColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	void glReplacementCodeuiColor4fNormal3fVertex3fvSUN(const GLuint *rc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
	void glReplacementCodeuiTexCoord2fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
	void glReplacementCodeuiTexCoord2fVertex3fvSUN(const GLuint *rc, const GLfloat *tc, const GLfloat *v);
	void glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	void glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(const GLuint *rc, const GLfloat *tc, const GLfloat *n, const GLfloat *v);
	void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(const GLuint *rc, const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
	void glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	void glBlendFuncSeparateINGR(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	void glVertexWeightfEXT(GLfloat weight);
	void glVertexWeightfvEXT(const GLfloat *weight);
	void glVertexWeightPointerEXT(GLsizei size, GLenum type, GLsizei stride, const GLvoid *pointer);
	void glFlushVertexArrayRangeNV(void);
	void glVertexArrayRangeNV(GLsizei length, const GLvoid *pointer);
	void glCombinerParameterfvNV(GLenum pname, const GLfloat *params);
	void glCombinerParameterfNV(GLenum pname, GLfloat param);
	void glCombinerParameterivNV(GLenum pname, const GLint *params);
	void glCombinerParameteriNV(GLenum pname, GLint param);
	void glCombinerInputNV(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
	void glCombinerOutputNV(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
	void glFinalCombinerInputNV(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
	void glGetCombinerInputParameterfvNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params);
	void glGetCombinerInputParameterivNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params);
	void glGetCombinerOutputParameterfvNV(GLenum stage, GLenum portion, GLenum pname, GLfloat *params);
	void glGetCombinerOutputParameterivNV(GLenum stage, GLenum portion, GLenum pname, GLint *params);
	void glGetFinalCombinerInputParameterfvNV(GLenum variable, GLenum pname, GLfloat *params);
	void glGetFinalCombinerInputParameterivNV(GLenum variable, GLenum pname, GLint *params);
	void glResizeBuffersMESA(void);
	void glWindowPos2dMESA(GLdouble x, GLdouble y);
	void glWindowPos2dvMESA(const GLdouble *v);
	void glWindowPos2fMESA(GLfloat x, GLfloat y);
	void glWindowPos2fvMESA(const GLfloat *v);
	void glWindowPos2iMESA(GLint x, GLint y);
	void glWindowPos2ivMESA(const GLint *v);
	void glWindowPos2sMESA(GLshort x, GLshort y);
	void glWindowPos2svMESA(const GLshort *v);
	void glWindowPos3dMESA(GLdouble x, GLdouble y, GLdouble z);
	void glWindowPos3dvMESA(const GLdouble *v);
	void glWindowPos3fMESA(GLfloat x, GLfloat y, GLfloat z);
	void glWindowPos3fvMESA(const GLfloat *v);
	void glWindowPos3iMESA(GLint x, GLint y, GLint z);
	void glWindowPos3ivMESA(const GLint *v);
	void glWindowPos3sMESA(GLshort x, GLshort y, GLshort z);
	void glWindowPos3svMESA(const GLshort *v);
	void glWindowPos4dMESA(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void glWindowPos4dvMESA(const GLdouble *v);
	void glWindowPos4fMESA(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void glWindowPos4fvMESA(const GLfloat *v);
	void glWindowPos4iMESA(GLint x, GLint y, GLint z, GLint w);
	void glWindowPos4ivMESA(const GLint *v);
	void glWindowPos4sMESA(GLshort x, GLshort y, GLshort z, GLshort w);
	void glWindowPos4svMESA(const GLshort *v);
	void glMultiModeDrawArraysIBM(const GLenum *mode, const GLint *first, const GLsizei *count, GLsizei primcount, GLint modestride);
	void glMultiModeDrawElementsIBM(const GLenum *mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei primcount, GLint modestride);
	void glColorPointerListIBM(GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
	void glSecondaryColorPointerListIBM(GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
	void glEdgeFlagPointerListIBM(GLint stride, const GLboolean* *pointer, GLint ptrstride);
	void glFogCoordPointerListIBM(GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
	void glIndexPointerListIBM(GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
	void glNormalPointerListIBM(GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
	void glTexCoordPointerListIBM(GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
	void glVertexPointerListIBM(GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
	void glTbufferMask3DFX(GLuint mask);
	void glSampleMaskEXT(GLclampf value, GLboolean invert);
	void glSamplePatternEXT(GLenum pattern);
	void glTextureColorMaskSGIS(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
	void glIglooInterfaceSGIX(GLenum pname, const GLvoid *params);
	void glDeleteFencesNV(GLsizei n, const GLuint *fences);
	void glGenFencesNV(GLsizei n, GLuint *fences);
	GLboolean glIsFenceNV(GLuint fence);
	GLboolean glTestFenceNV(GLuint fence);
	void glGetFenceivNV(GLuint fence, GLenum pname, GLint *params);
	void glFinishFenceNV(GLuint fence);
	void glSetFenceNV(GLuint fence, GLenum condition);
	void glMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const GLvoid *points);
	void glMapParameterivNV(GLenum target, GLenum pname, const GLint *params);
	void glMapParameterfvNV(GLenum target, GLenum pname, const GLfloat *params);
	void glGetMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, GLvoid *points);
	void glGetMapParameterivNV(GLenum target, GLenum pname, GLint *params);
	void glGetMapParameterfvNV(GLenum target, GLenum pname, GLfloat *params);
	void glGetMapAttribParameterivNV(GLenum target, GLuint index, GLenum pname, GLint *params);
	void glGetMapAttribParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat *params);
	void glEvalMapsNV(GLenum target, GLenum mode);
	void glCombinerStageParameterfvNV(GLenum stage, GLenum pname, const GLfloat *params);
	void glGetCombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat *params);
	GLboolean glAreProgramsResidentNV(GLsizei n, const GLuint *programs, GLboolean *residences);
	void glBindProgramNV(GLenum target, GLuint id);
	void glDeleteProgramsNV(GLsizei n, const GLuint *programs);
	void glExecuteProgramNV(GLenum target, GLuint id, const GLfloat *params);
	void glGenProgramsNV(GLsizei n, GLuint *programs);
	void glGetProgramParameterdvNV(GLenum target, GLuint index, GLenum pname, GLdouble *params);
	void glGetProgramParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat *params);
	void glGetProgramivNV(GLuint id, GLenum pname, GLint *params);
	void glGetProgramStringNV(GLuint id, GLenum pname, GLubyte *program);
	void glGetTrackMatrixivNV(GLenum target, GLuint address, GLenum pname, GLint *params);
	void glGetVertexAttribdvNV(GLuint index, GLenum pname, GLdouble *params);
	void glGetVertexAttribfvNV(GLuint index, GLenum pname, GLfloat *params);
	void glGetVertexAttribivNV(GLuint index, GLenum pname, GLint *params);
	void glGetVertexAttribPointervNV(GLuint index, GLenum pname, GLvoid* *pointer);
	GLboolean glIsProgramNV(GLuint id);
	void glLoadProgramNV(GLenum target, GLuint id, GLsizei len, const GLubyte *program);
	void glProgramParameter4dNV(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void glProgramParameter4dvNV(GLenum target, GLuint index, const GLdouble *v);
	void glProgramParameter4fNV(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void glProgramParameter4fvNV(GLenum target, GLuint index, const GLfloat *v);
	void glProgramParameters4dvNV(GLenum target, GLuint index, GLsizei count, const GLdouble *v);
	void glProgramParameters4fvNV(GLenum target, GLuint index, GLsizei count, const GLfloat *v);
	void glRequestResidentProgramsNV(GLsizei n, const GLuint *programs);
	void glTrackMatrixNV(GLenum target, GLuint address, GLenum matrix, GLenum transform);
	void glVertexAttribPointerNV(GLuint index, GLint fsize, GLenum type, GLsizei stride, const GLvoid *pointer);
	void glVertexAttrib1dNV(GLuint index, GLdouble x);
	void glVertexAttrib1dvNV(GLuint index, const GLdouble *v);
	void glVertexAttrib1fNV(GLuint index, GLfloat x);
	void glVertexAttrib1fvNV(GLuint index, const GLfloat *v);
	void glVertexAttrib1sNV(GLuint index, GLshort x);
	void glVertexAttrib1svNV(GLuint index, const GLshort *v);
	void glVertexAttrib2dNV(GLuint index, GLdouble x, GLdouble y);
	void glVertexAttrib2dvNV(GLuint index, const GLdouble *v);
	void glVertexAttrib2fNV(GLuint index, GLfloat x, GLfloat y);
	void glVertexAttrib2fvNV(GLuint index, const GLfloat *v);
	void glVertexAttrib2sNV(GLuint index, GLshort x, GLshort y);
	void glVertexAttrib2svNV(GLuint index, const GLshort *v);
	void glVertexAttrib3dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z);
	void glVertexAttrib3dvNV(GLuint index, const GLdouble *v);
	void glVertexAttrib3fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z);
	void glVertexAttrib3fvNV(GLuint index, const GLfloat *v);
	void glVertexAttrib3sNV(GLuint index, GLshort x, GLshort y, GLshort z);
	void glVertexAttrib3svNV(GLuint index, const GLshort *v);
	void glVertexAttrib4dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void glVertexAttrib4dvNV(GLuint index, const GLdouble *v);
	void glVertexAttrib4fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void glVertexAttrib4fvNV(GLuint index, const GLfloat *v);
	void glVertexAttrib4sNV(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
	void glVertexAttrib4svNV(GLuint index, const GLshort *v);
	void glVertexAttrib4ubNV(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
	void glVertexAttrib4ubvNV(GLuint index, const GLubyte *v);
	void glVertexAttribs1dvNV(GLuint index, GLsizei count, const GLdouble *v);
	void glVertexAttribs1fvNV(GLuint index, GLsizei count, const GLfloat *v);
	void glVertexAttribs1svNV(GLuint index, GLsizei count, const GLshort *v);
	void glVertexAttribs2dvNV(GLuint index, GLsizei count, const GLdouble *v);
	void glVertexAttribs2fvNV(GLuint index, GLsizei count, const GLfloat *v);
	void glVertexAttribs2svNV(GLuint index, GLsizei count, const GLshort *v);
	void glVertexAttribs3dvNV(GLuint index, GLsizei count, const GLdouble *v);
	void glVertexAttribs3fvNV(GLuint index, GLsizei count, const GLfloat *v);
	void glVertexAttribs3svNV(GLuint index, GLsizei count, const GLshort *v);
	void glVertexAttribs4dvNV(GLuint index, GLsizei count, const GLdouble *v);
	void glVertexAttribs4fvNV(GLuint index, GLsizei count, const GLfloat *v);
	void glVertexAttribs4svNV(GLuint index, GLsizei count, const GLshort *v);
	void glVertexAttribs4ubvNV(GLuint index, GLsizei count, const GLubyte *v);
	void glTexBumpParameterivATI(GLenum pname, const GLint *param);
	void glTexBumpParameterfvATI(GLenum pname, const GLfloat *param);
	void glGetTexBumpParameterivATI(GLenum pname, GLint *param);
	void glGetTexBumpParameterfvATI(GLenum pname, GLfloat *param);
	GLuint glGenFragmentShadersATI(GLuint range);
	void glBindFragmentShaderATI(GLuint id);
	void glDeleteFragmentShaderATI(GLuint id);
	void glBeginFragmentShaderATI(void);
	void glEndFragmentShaderATI(void);
	void glPassTexCoordATI(GLuint dst, GLuint coord, GLenum swizzle);
	void glSampleMapATI(GLuint dst, GLuint interp, GLenum swizzle);
	void glColorFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
	void glColorFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
	void glColorFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
	void glAlphaFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
	void glAlphaFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
	void glAlphaFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
	void glSetFragmentShaderConstantATI(GLuint dst, const GLfloat *value);
	void glPNTrianglesiATI(GLenum pname, GLint param);
	void glPNTrianglesfATI(GLenum pname, GLfloat param);
	GLuint glNewObjectBufferATI(GLsizei size, const GLvoid *pointer, GLenum usage);
	GLboolean glIsObjectBufferATI(GLuint buffer);
	void glUpdateObjectBufferATI(GLuint buffer, GLuint offset, GLsizei size, const GLvoid *pointer, GLenum preserve);
	void glGetObjectBufferfvATI(GLuint buffer, GLenum pname, GLfloat *params);
	void glGetObjectBufferivATI(GLuint buffer, GLenum pname, GLint *params);
	void glFreeObjectBufferATI(GLuint buffer);
	void glArrayObjectATI(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
	void glGetArrayObjectfvATI(GLenum array, GLenum pname, GLfloat *params);
	void glGetArrayObjectivATI(GLenum array, GLenum pname, GLint *params);
	void glVariantArrayObjectATI(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
	void glGetVariantArrayObjectfvATI(GLuint id, GLenum pname, GLfloat *params);
	void glGetVariantArrayObjectivATI(GLuint id, GLenum pname, GLint *params);
	void glBeginVertexShaderEXT(void);
	void glEndVertexShaderEXT(void);
	void glBindVertexShaderEXT(GLuint id);
	GLuint glGenVertexShadersEXT(GLuint range);
	void glDeleteVertexShaderEXT(GLuint id);
	void glShaderOp1EXT(GLenum op, GLuint res, GLuint arg1);
	void glShaderOp2EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2);
	void glShaderOp3EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
	void glSwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
	void glWriteMaskEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
	void glInsertComponentEXT(GLuint res, GLuint src, GLuint num);
	void glExtractComponentEXT(GLuint res, GLuint src, GLuint num);
	GLuint glGenSymbolsEXT(GLenum datatype, GLenum storagetype, GLenum range, GLuint components);
	void glSetInvariantEXT(GLuint id, GLenum type, const GLvoid *addr);
	void glSetLocalConstantEXT(GLuint id, GLenum type, const GLvoid *addr);
	void glVariantbvEXT(GLuint id, const GLbyte *addr);
	void glVariantsvEXT(GLuint id, const GLshort *addr);
	void glVariantivEXT(GLuint id, const GLint *addr);
	void glVariantfvEXT(GLuint id, const GLfloat *addr);
	void glVariantdvEXT(GLuint id, const GLdouble *addr);
	void glVariantubvEXT(GLuint id, const GLubyte *addr);
	void glVariantusvEXT(GLuint id, const GLushort *addr);
	void glVariantuivEXT(GLuint id, const GLuint *addr);
	void glVariantPointerEXT(GLuint id, GLenum type, GLuint stride, const GLvoid *addr);
	void glEnableVariantClientStateEXT(GLuint id);
	void glDisableVariantClientStateEXT(GLuint id);
	GLuint glBindLightParameterEXT(GLenum light, GLenum value);
	GLuint glBindMaterialParameterEXT(GLenum face, GLenum value);
	GLuint glBindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value);
	GLuint glBindTextureUnitParameterEXT(GLenum unit, GLenum value);
	GLuint glBindParameterEXT(GLenum value);
	GLboolean glIsVariantEnabledEXT(GLuint id, GLenum cap);
	void glGetVariantBooleanvEXT(GLuint id, GLenum value, GLboolean *data);
	void glGetVariantIntegervEXT(GLuint id, GLenum value, GLint *data);
	void glGetVariantFloatvEXT(GLuint id, GLenum value, GLfloat *data);
	void glGetVariantPointervEXT(GLuint id, GLenum value, GLvoid* *data);
	void glGetInvariantBooleanvEXT(GLuint id, GLenum value, GLboolean *data);
	void glGetInvariantIntegervEXT(GLuint id, GLenum value, GLint *data);
	void glGetInvariantFloatvEXT(GLuint id, GLenum value, GLfloat *data);
	void glGetLocalConstantBooleanvEXT(GLuint id, GLenum value, GLboolean *data);
	void glGetLocalConstantIntegervEXT(GLuint id, GLenum value, GLint *data);
	void glGetLocalConstantFloatvEXT(GLuint id, GLenum value, GLfloat *data);
	void glVertexStream1sATI(GLenum stream, GLshort x);
	void glVertexStream1svATI(GLenum stream, const GLshort *coords);
	void glVertexStream1iATI(GLenum stream, GLint x);
	void glVertexStream1ivATI(GLenum stream, const GLint *coords);
	void glVertexStream1fATI(GLenum stream, GLfloat x);
	void glVertexStream1fvATI(GLenum stream, const GLfloat *coords);
	void glVertexStream1dATI(GLenum stream, GLdouble x);
	void glVertexStream1dvATI(GLenum stream, const GLdouble *coords);
	void glVertexStream2sATI(GLenum stream, GLshort x, GLshort y);
	void glVertexStream2svATI(GLenum stream, const GLshort *coords);
	void glVertexStream2iATI(GLenum stream, GLint x, GLint y);
	void glVertexStream2ivATI(GLenum stream, const GLint *coords);
	void glVertexStream2fATI(GLenum stream, GLfloat x, GLfloat y);
	void glVertexStream2fvATI(GLenum stream, const GLfloat *coords);
	void glVertexStream2dATI(GLenum stream, GLdouble x, GLdouble y);
	void glVertexStream2dvATI(GLenum stream, const GLdouble *coords);
	void glVertexStream3sATI(GLenum stream, GLshort x, GLshort y, GLshort z);
	void glVertexStream3svATI(GLenum stream, const GLshort *coords);
	void glVertexStream3iATI(GLenum stream, GLint x, GLint y, GLint z);
	void glVertexStream3ivATI(GLenum stream, const GLint *coords);
	void glVertexStream3fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z);
	void glVertexStream3fvATI(GLenum stream, const GLfloat *coords);
	void glVertexStream3dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z);
	void glVertexStream3dvATI(GLenum stream, const GLdouble *coords);
	void glVertexStream4sATI(GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w);
	void glVertexStream4svATI(GLenum stream, const GLshort *coords);
	void glVertexStream4iATI(GLenum stream, GLint x, GLint y, GLint z, GLint w);
	void glVertexStream4ivATI(GLenum stream, const GLint *coords);
	void glVertexStream4fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void glVertexStream4fvATI(GLenum stream, const GLfloat *coords);
	void glVertexStream4dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void glVertexStream4dvATI(GLenum stream, const GLdouble *coords);
	void glNormalStream3bATI(GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz);
	void glNormalStream3bvATI(GLenum stream, const GLbyte *coords);
	void glNormalStream3sATI(GLenum stream, GLshort nx, GLshort ny, GLshort nz);
	void glNormalStream3svATI(GLenum stream, const GLshort *coords);
	void glNormalStream3iATI(GLenum stream, GLint nx, GLint ny, GLint nz);
	void glNormalStream3ivATI(GLenum stream, const GLint *coords);
	void glNormalStream3fATI(GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz);
	void glNormalStream3fvATI(GLenum stream, const GLfloat *coords);
	void glNormalStream3dATI(GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz);
	void glNormalStream3dvATI(GLenum stream, const GLdouble *coords);
	void glClientActiveVertexStreamATI(GLenum stream);
	void glVertexBlendEnviATI(GLenum pname, GLint param);
	void glVertexBlendEnvfATI(GLenum pname, GLfloat param);
	void glElementPointerATI(GLenum type, const GLvoid *pointer);
	void glDrawElementArrayATI(GLenum mode, GLsizei count);
	void glDrawRangeElementArrayATI(GLenum mode, GLuint start, GLuint end, GLsizei count);
	void glDrawMeshArraysSUN(GLenum mode, GLint first, GLsizei count, GLsizei width);
	void glGenOcclusionQueriesNV(GLsizei n, GLuint *ids);
	void glDeleteOcclusionQueriesNV(GLsizei n, const GLuint *ids);
	GLboolean glIsOcclusionQueryNV(GLuint id);
	void glBeginOcclusionQueryNV(GLuint id);
	void glEndOcclusionQueryNV(void);
	void glGetOcclusionQueryivNV(GLuint id, GLenum pname, GLint *params);
	void glGetOcclusionQueryuivNV(GLuint id, GLenum pname, GLuint *params);
	void glPointParameteriNV(GLenum pname, GLint param);
	void glPointParameterivNV(GLenum pname, const GLint *params);
	void glActiveStencilFaceEXT(GLenum face);
	void glElementPointerAPPLE(GLenum type, const GLvoid *pointer);
	void glDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count);
	void glDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
	void glMultiDrawElementArrayAPPLE(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
	void glMultiDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount);
	void glGenFencesAPPLE(GLsizei n, GLuint *fences);
	void glDeleteFencesAPPLE(GLsizei n, const GLuint *fences);
	void glSetFenceAPPLE(GLuint fence);
	GLboolean glIsFenceAPPLE(GLuint fence);
	GLboolean glTestFenceAPPLE(GLuint fence);
	void glFinishFenceAPPLE(GLuint fence);
	GLboolean glTestObjectAPPLE(GLenum object, GLuint name);
	void glFinishObjectAPPLE(GLenum object, GLint name);
	void glBindVertexArrayAPPLE(GLuint array);
	void glDeleteVertexArraysAPPLE(GLsizei n, const GLuint *arrays);
	void glGenVertexArraysAPPLE(GLsizei n, GLuint *arrays);
	GLboolean glIsVertexArrayAPPLE(GLuint array);
	void glVertexArrayRangeAPPLE(GLsizei length, GLvoid *pointer);
	void glFlushVertexArrayRangeAPPLE(GLsizei length, GLvoid *pointer);
	void glVertexArrayParameteriAPPLE(GLenum pname, GLint param);
	void glDrawBuffersATI(GLsizei n, const GLenum *bufs);
	void glProgramNamedParameter4fNV(GLuint id, GLsizei len, const GLubyte *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void glProgramNamedParameter4dNV(GLuint id, GLsizei len, const GLubyte *name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void glProgramNamedParameter4fvNV(GLuint id, GLsizei len, const GLubyte *name, const GLfloat *v);
	void glProgramNamedParameter4dvNV(GLuint id, GLsizei len, const GLubyte *name, const GLdouble *v);
	void glGetProgramNamedParameterfvNV(GLuint id, GLsizei len, const GLubyte *name, GLfloat *params);
	void glGetProgramNamedParameterdvNV(GLuint id, GLsizei len, const GLubyte *name, GLdouble *params);
	void glVertex2hNV(GLhalfNV x, GLhalfNV y);
	void glVertex2hvNV(const GLhalfNV *v);
	void glVertex3hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z);
	void glVertex3hvNV(const GLhalfNV *v);
	void glVertex4hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
	void glVertex4hvNV(const GLhalfNV *v);
	void glNormal3hNV(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz);
	void glNormal3hvNV(const GLhalfNV *v);
	void glColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
	void glColor3hvNV(const GLhalfNV *v);
	void glColor4hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha);
	void glColor4hvNV(const GLhalfNV *v);
	void glTexCoord1hNV(GLhalfNV s);
	void glTexCoord1hvNV(const GLhalfNV *v);
	void glTexCoord2hNV(GLhalfNV s, GLhalfNV t);
	void glTexCoord2hvNV(const GLhalfNV *v);
	void glTexCoord3hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r);
	void glTexCoord3hvNV(const GLhalfNV *v);
	void glTexCoord4hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
	void glTexCoord4hvNV(const GLhalfNV *v);
	void glMultiTexCoord1hNV(GLenum target, GLhalfNV s);
	void glMultiTexCoord1hvNV(GLenum target, const GLhalfNV *v);
	void glMultiTexCoord2hNV(GLenum target, GLhalfNV s, GLhalfNV t);
	void glMultiTexCoord2hvNV(GLenum target, const GLhalfNV *v);
	void glMultiTexCoord3hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r);
	void glMultiTexCoord3hvNV(GLenum target, const GLhalfNV *v);
	void glMultiTexCoord4hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
	void glMultiTexCoord4hvNV(GLenum target, const GLhalfNV *v);
	void glFogCoordhNV(GLhalfNV fog);
	void glFogCoordhvNV(const GLhalfNV *fog);
	void glSecondaryColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
	void glSecondaryColor3hvNV(const GLhalfNV *v);
	void glVertexWeighthNV(GLhalfNV weight);
	void glVertexWeighthvNV(const GLhalfNV *weight);
	void glVertexAttrib1hNV(GLuint index, GLhalfNV x);
	void glVertexAttrib1hvNV(GLuint index, const GLhalfNV *v);
	void glVertexAttrib2hNV(GLuint index, GLhalfNV x, GLhalfNV y);
	void glVertexAttrib2hvNV(GLuint index, const GLhalfNV *v);
	void glVertexAttrib3hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z);
	void glVertexAttrib3hvNV(GLuint index, const GLhalfNV *v);
	void glVertexAttrib4hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
	void glVertexAttrib4hvNV(GLuint index, const GLhalfNV *v);
	void glVertexAttribs1hvNV(GLuint index, GLsizei n, const GLhalfNV *v);
	void glVertexAttribs2hvNV(GLuint index, GLsizei n, const GLhalfNV *v);
	void glVertexAttribs3hvNV(GLuint index, GLsizei n, const GLhalfNV *v);
	void glVertexAttribs4hvNV(GLuint index, GLsizei n, const GLhalfNV *v);
	void glPixelDataRangeNV(GLenum target, GLsizei length, GLvoid *pointer);
	void glFlushPixelDataRangeNV(GLenum target);
	void glPrimitiveRestartNV(void);
	void glPrimitiveRestartIndexNV(GLuint index);
	GLvoid* glMapObjectBufferATI(GLuint buffer);
	void glUnmapObjectBufferATI(GLuint buffer);
	void glStencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
	void glStencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
	void glVertexAttribArrayObjectATI(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset);
	void glGetVertexAttribArrayObjectfvATI(GLuint index, GLenum pname, GLfloat *params);
	void glGetVertexAttribArrayObjectivATI(GLuint index, GLenum pname, GLint *params);
	void glDepthBoundsEXT(GLclampd zmin, GLclampd zmax);
	void glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha);
	GLboolean glIsRenderbufferEXT(GLuint renderbuffer);
	void glBindRenderbufferEXT(GLenum target, GLuint renderbuffer);
	void glDeleteRenderbuffersEXT(GLsizei n, const GLuint *renderbuffers);
	void glGenRenderbuffersEXT(GLsizei n, GLuint *renderbuffers);
	void glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	void glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint *params);
	GLboolean glIsFramebufferEXT(GLuint framebuffer);
	void glBindFramebufferEXT(GLenum target, GLuint framebuffer);
	void glDeleteFramebuffersEXT(GLsizei n, const GLuint *framebuffers);
	void glGenFramebuffersEXT(GLsizei n, GLuint *framebuffers);
	GLenum glCheckFramebufferStatusEXT(GLenum target);
	void glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	void glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	void glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
	void glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	void glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint *params);
	void glGenerateMipmapEXT(GLenum target);
	void glStringMarkerGREMEDY(GLsizei len, const GLvoid *string);
	void glStencilClearTagEXT(GLsizei stencilTagBits, GLuint stencilClearTag);
	void glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	void glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	void glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64EXT *params);
	void glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64EXT *params);
	void glProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat *params);
	void glProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat *params);
	void glBufferParameteriAPPLE(GLenum target, GLenum pname, GLint param);
	void glFlushMappedBufferRangeAPPLE(GLenum target, GLintptr offset, GLsizeiptr size);
	void glProgramLocalParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
	void glProgramLocalParameterI4ivNV(GLenum target, GLuint index, const GLint *params);
	void glProgramLocalParametersI4ivNV(GLenum target, GLuint index, GLsizei count, const GLint *params);
	void glProgramLocalParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	void glProgramLocalParameterI4uivNV(GLenum target, GLuint index, const GLuint *params);
	void glProgramLocalParametersI4uivNV(GLenum target, GLuint index, GLsizei count, const GLuint *params);
	void glProgramEnvParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
	void glProgramEnvParameterI4ivNV(GLenum target, GLuint index, const GLint *params);
	void glProgramEnvParametersI4ivNV(GLenum target, GLuint index, GLsizei count, const GLint *params);
	void glProgramEnvParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	void glProgramEnvParameterI4uivNV(GLenum target, GLuint index, const GLuint *params);
	void glProgramEnvParametersI4uivNV(GLenum target, GLuint index, GLsizei count, const GLuint *params);
	void glGetProgramLocalParameterIivNV(GLenum target, GLuint index, GLint *params);
	void glGetProgramLocalParameterIuivNV(GLenum target, GLuint index, GLuint *params);
	void glGetProgramEnvParameterIivNV(GLenum target, GLuint index, GLint *params);
	void glGetProgramEnvParameterIuivNV(GLenum target, GLuint index, GLuint *params);
	void glProgramVertexLimitNV(GLenum target, GLint limit);
	void glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level);
	void glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	void glFramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
	void glProgramParameteriEXT(GLuint program, GLenum pname, GLint value);
	void glVertexAttribI1iEXT(GLuint index, GLint x);
	void glVertexAttribI2iEXT(GLuint index, GLint x, GLint y);
	void glVertexAttribI3iEXT(GLuint index, GLint x, GLint y, GLint z);
	void glVertexAttribI4iEXT(GLuint index, GLint x, GLint y, GLint z, GLint w);
	void glVertexAttribI1uiEXT(GLuint index, GLuint x);
	void glVertexAttribI2uiEXT(GLuint index, GLuint x, GLuint y);
	void glVertexAttribI3uiEXT(GLuint index, GLuint x, GLuint y, GLuint z);
	void glVertexAttribI4uiEXT(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	void glVertexAttribI1ivEXT(GLuint index, const GLint *v);
	void glVertexAttribI2ivEXT(GLuint index, const GLint *v);
	void glVertexAttribI3ivEXT(GLuint index, const GLint *v);
	void glVertexAttribI4ivEXT(GLuint index, const GLint *v);
	void glVertexAttribI1uivEXT(GLuint index, const GLuint *v);
	void glVertexAttribI2uivEXT(GLuint index, const GLuint *v);
	void glVertexAttribI3uivEXT(GLuint index, const GLuint *v);
	void glVertexAttribI4uivEXT(GLuint index, const GLuint *v);
	void glVertexAttribI4bvEXT(GLuint index, const GLbyte *v);
	void glVertexAttribI4svEXT(GLuint index, const GLshort *v);
	void glVertexAttribI4ubvEXT(GLuint index, const GLubyte *v);
	void glVertexAttribI4usvEXT(GLuint index, const GLushort *v);
	void glVertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	void glGetVertexAttribIivEXT(GLuint index, GLenum pname, GLint *params);
	void glGetVertexAttribIuivEXT(GLuint index, GLenum pname, GLuint *params);
	void glGetUniformuivEXT(GLuint program, GLint location, GLuint *params);
	void glBindFragDataLocationEXT(GLuint program, GLuint color, const GLchar *name);
	GLint glGetFragDataLocationEXT(GLuint program, const GLchar *name);
	void glUniform1uiEXT(GLint location, GLuint v0);
	void glUniform2uiEXT(GLint location, GLuint v0, GLuint v1);
	void glUniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2);
	void glUniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	void glUniform1uivEXT(GLint location, GLsizei count, const GLuint *value);
	void glUniform2uivEXT(GLint location, GLsizei count, const GLuint *value);
	void glUniform3uivEXT(GLint location, GLsizei count, const GLuint *value);
	void glUniform4uivEXT(GLint location, GLsizei count, const GLuint *value);
	void glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
	void glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount);
	void glTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer);
	void glDepthRangedNV(GLdouble zNear, GLdouble zFar);
	void glClearDepthdNV(GLdouble depth);
	void glDepthBoundsdNV(GLdouble zmin, GLdouble zmax);
	void glRenderbufferStorageMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
	void glProgramBufferParametersfvNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLfloat *params);
	void glProgramBufferParametersIivNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLint *params);
	void glProgramBufferParametersIuivNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLuint *params);
	void glColorMaskIndexedEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
	void glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean *data);
	void glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint *data);
	void glEnableIndexedEXT(GLenum target, GLuint index);
	void glDisableIndexedEXT(GLenum target, GLuint index);
	GLboolean glIsEnabledIndexedEXT(GLenum target, GLuint index);
	void glBeginTransformFeedbackNV(GLenum primitiveMode);
	void glEndTransformFeedbackNV(void);
	void glTransformFeedbackAttribsNV(GLuint count, const GLint *attribs, GLenum bufferMode);
	void glBindBufferRangeNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	void glBindBufferOffsetNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
	void glBindBufferBaseNV(GLenum target, GLuint index, GLuint buffer);
	void glTransformFeedbackVaryingsNV(GLuint program, GLsizei count, const GLint *locations, GLenum bufferMode);
	void glActiveVaryingNV(GLuint program, const GLchar *name);
	GLint glGetVaryingLocationNV(GLuint program, const GLchar *name);
	void glGetActiveVaryingNV(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
	void glGetTransformFeedbackVaryingNV(GLuint program, GLuint index, GLint *location);
	void glTransformFeedbackStreamAttribsNV(GLsizei count, const GLint *attribs, GLsizei nbuffers, const GLint *bufstreams, GLenum bufferMode);
	void glUniformBufferEXT(GLuint program, GLint location, GLuint buffer);
	GLint glGetUniformBufferSizeEXT(GLuint program, GLint location);
	GLintptr glGetUniformOffsetEXT(GLuint program, GLint location);
	void glTexParameterIivEXT(GLenum target, GLenum pname, const GLint *params);
	void glTexParameterIuivEXT(GLenum target, GLenum pname, const GLuint *params);
	void glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint *params);
	void glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint *params);
	void glClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha);
	void glClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha);
	void glFrameTerminatorGREMEDY(void);
	void glBeginConditionalRenderNV(GLuint id, GLenum mode);
	void glEndConditionalRenderNV(void);
	void glPresentFrameKeyedNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1);
	void glPresentFrameDualFillNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3);
	void glGetVideoivNV(GLuint video_slot, GLenum pname, GLint *params);
	void glGetVideouivNV(GLuint video_slot, GLenum pname, GLuint *params);
	void glGetVideoi64vNV(GLuint video_slot, GLenum pname, GLint64EXT *params);
	void glGetVideoui64vNV(GLuint video_slot, GLenum pname, GLuint64EXT *params);
	void glBeginTransformFeedbackEXT(GLenum primitiveMode);
	void glEndTransformFeedbackEXT(void);
	void glBindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	void glBindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
	void glBindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer);
	void glTransformFeedbackVaryingsEXT(GLuint program, GLsizei count, const GLchar* *varyings, GLenum bufferMode);
	void glGetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
	void glClientAttribDefaultEXT(GLbitfield mask);
	void glPushClientAttribDefaultEXT(GLbitfield mask);
	void glMatrixLoadfEXT(GLenum mode, const GLfloat *m);
	void glMatrixLoaddEXT(GLenum mode, const GLdouble *m);
	void glMatrixMultfEXT(GLenum mode, const GLfloat *m);
	void glMatrixMultdEXT(GLenum mode, const GLdouble *m);
	void glMatrixLoadIdentityEXT(GLenum mode);
	void glMatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
	void glMatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
	void glMatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
	void glMatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
	void glMatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
	void glMatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
	void glMatrixFrustumEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
	void glMatrixOrthoEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
	void glMatrixPopEXT(GLenum mode);
	void glMatrixPushEXT(GLenum mode);
	void glMatrixLoadTransposefEXT(GLenum mode, const GLfloat *m);
	void glMatrixLoadTransposedEXT(GLenum mode, const GLdouble *m);
	void glMatrixMultTransposefEXT(GLenum mode, const GLfloat *m);
	void glMatrixMultTransposedEXT(GLenum mode, const GLdouble *m);
	void glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param);
	void glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, const GLfloat *params);
	void glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param);
	void glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, const GLint *params);
	void glTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	void glTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	void glTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
	void glTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
	void glCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
	void glCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	void glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	void glCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	void glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
	void glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat *params);
	void glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint *params);
	void glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
	void glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);
	void glTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	void glTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
	void glCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	void glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
	void glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
	void glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
	void glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
	void glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	void glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	void glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
	void glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
	void glCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
	void glCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	void glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	void glCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	void glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
	void glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
	void glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint *params);
	void glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params);
	void glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params);
	void glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	void glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
	void glCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	void glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture);
	void glEnableClientStateIndexedEXT(GLenum array, GLuint index);
	void glDisableClientStateIndexedEXT(GLenum array, GLuint index);
	void glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	void glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
	void glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
	void glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
	void glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
	void glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
	void glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params);
	void glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
	void glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params);
	void glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param);
	void glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint *params);
	void glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
	void glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint *params);
	void glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble *params);
	void glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat *params);
	void glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint *params);
	void glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat *data);
	void glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble *data);
	void glGetPointerIndexedvEXT(GLenum target, GLuint index, GLvoid* *data);
	void glCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *bits);
	void glCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *bits);
	void glCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *bits);
	void glCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *bits);
	void glCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *bits);
	void glCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *bits);
	void glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, GLvoid *img);
	void glCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *bits);
	void glCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *bits);
	void glCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *bits);
	void glCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *bits);
	void glCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *bits);
	void glCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *bits);
	void glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, GLvoid *img);
	void glNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, const GLvoid *string);
	void glNamedProgramLocalParameter4dEXT(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void glNamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, const GLdouble *params);
	void glNamedProgramLocalParameter4fEXT(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void glNamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, const GLfloat *params);
	void glGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble *params);
	void glGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat *params);
	void glGetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint *params);
	void glGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, GLvoid *string);
	void glNamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
	void glNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
	void glNamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, const GLint *params);
	void glNamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params);
	void glNamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	void glNamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, const GLuint *params);
	void glNamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params);
	void glGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint *params);
	void glGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint *params);
	void glTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, const GLint *params);
	void glTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, const GLuint *params);
	void glGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint *params);
	void glGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint *params);
	void glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
	void glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, const GLuint *params);
	void glGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint *params);
	void glGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint *params);
	void glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0);
	void glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1);
	void glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	void glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	void glProgramUniform1iEXT(GLuint program, GLint location, GLint v0);
	void glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1);
	void glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
	void glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	void glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	void glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	void glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	void glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	void glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, const GLint *value);
	void glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, const GLint *value);
	void glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, const GLint *value);
	void glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, const GLint *value);
	void glProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	void glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0);
	void glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1);
	void glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
	void glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	void glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, const GLuint *value);
	void glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, const GLuint *value);
	void glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, const GLuint *value);
	void glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, const GLuint *value);
	void glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const GLvoid *data, GLenum usage);
	void glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid *data);
	GLvoid* glMapNamedBufferEXT(GLuint buffer, GLenum access);
	GLboolean glUnmapNamedBufferEXT(GLuint buffer);
	GLvoid* glMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
	void glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length);
	void glNamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
	void glGetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint *params);
	void glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, GLvoid* *params);
	void glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid *data);
	void glTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
	void glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
	void glNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
	void glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint *params);
	GLenum glCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target);
	void glNamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	void glNamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	void glNamedFramebufferTexture3DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
	void glNamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	void glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
	void glGenerateTextureMipmapEXT(GLuint texture, GLenum target);
	void glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target);
	void glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode);
	void glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, const GLenum *bufs);
	void glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode);
	void glGetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint *params);
	void glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	void glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
	void glNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
	void glNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
	void glNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
	void glTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer);
	void glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer);
	void glProgramUniform1dEXT(GLuint program, GLint location, GLdouble x);
	void glProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y);
	void glProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
	void glProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void glProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	void glProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	void glProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	void glProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	void glProgramUniformMatrix2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix2x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix2x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix3x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix3x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix4x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glProgramUniformMatrix4x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	void glGetMultisamplefvNV(GLenum pname, GLuint index, GLfloat *val);
	void glSampleMaskIndexedNV(GLuint index, GLbitfield mask);
	void glTexRenderbufferNV(GLenum target, GLuint renderbuffer);
	void glBindTransformFeedbackNV(GLenum target, GLuint id);
	void glDeleteTransformFeedbacksNV(GLsizei n, const GLuint *ids);
	void glGenTransformFeedbacksNV(GLsizei n, GLuint *ids);
	GLboolean glIsTransformFeedbackNV(GLuint id);
	void glPauseTransformFeedbackNV(void);
	void glResumeTransformFeedbackNV(void);
	void glDrawTransformFeedbackNV(GLenum mode, GLuint id);
	void glGetPerfMonitorGroupsAMD(GLint *numGroups, GLsizei groupsSize, GLuint *groups);
	void glGetPerfMonitorCountersAMD(GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters);
	void glGetPerfMonitorGroupStringAMD(GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString);
	void glGetPerfMonitorCounterStringAMD(GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString);
	void glGetPerfMonitorCounterInfoAMD(GLuint group, GLuint counter, GLenum pname, GLvoid *data);
	void glGenPerfMonitorsAMD(GLsizei n, GLuint *monitors);
	void glDeletePerfMonitorsAMD(GLsizei n, GLuint *monitors);
	void glSelectPerfMonitorCountersAMD(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList);
	void glBeginPerfMonitorAMD(GLuint monitor);
	void glEndPerfMonitorAMD(GLuint monitor);
	void glGetPerfMonitorCounterDataAMD(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten);
	void glTessellationFactorAMD(GLfloat factor);
	void glTessellationModeAMD(GLenum mode);
	void glProvokingVertexEXT(GLenum mode);
	void glBlendFuncIndexedAMD(GLuint buf, GLenum src, GLenum dst);
	void glBlendFuncSeparateIndexedAMD(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
	void glBlendEquationIndexedAMD(GLuint buf, GLenum mode);
	void glBlendEquationSeparateIndexedAMD(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
	void glTextureRangeAPPLE(GLenum target, GLsizei length, const GLvoid *pointer);
	void glGetTexParameterPointervAPPLE(GLenum target, GLenum pname, GLvoid* *params);
	void glEnableVertexAttribAPPLE(GLuint index, GLenum pname);
	void glDisableVertexAttribAPPLE(GLuint index, GLenum pname);
	GLboolean glIsVertexAttribEnabledAPPLE(GLuint index, GLenum pname);
	void glMapVertexAttrib1dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
	void glMapVertexAttrib1fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
	void glMapVertexAttrib2dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
	void glMapVertexAttrib2fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
	GLenum glObjectPurgeableAPPLE(GLenum objectType, GLuint name, GLenum option);
	GLenum glObjectUnpurgeableAPPLE(GLenum objectType, GLuint name, GLenum option);
	void glGetObjectParameterivAPPLE(GLenum objectType, GLuint name, GLenum pname, GLint *params);
	void glBeginVideoCaptureNV(GLuint video_capture_slot);
	void glBindVideoCaptureStreamBufferNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset);
	void glBindVideoCaptureStreamTextureNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture);
	void glEndVideoCaptureNV(GLuint video_capture_slot);
	void glGetVideoCaptureivNV(GLuint video_capture_slot, GLenum pname, GLint *params);
	void glGetVideoCaptureStreamivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint *params);
	void glGetVideoCaptureStreamfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat *params);
	void glGetVideoCaptureStreamdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble *params);
	GLenum glVideoCaptureNV(GLuint video_capture_slot, GLuint *sequence_num, GLuint64EXT *capture_time);
	void glVideoCaptureStreamParameterivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint *params);
	void glVideoCaptureStreamParameterfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat *params);
	void glVideoCaptureStreamParameterdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble *params);
	void glCopyImageSubDataNV(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
	void glUseShaderProgramEXT(GLenum type, GLuint program);
	void glActiveProgramEXT(GLuint program);
	GLuint glCreateShaderProgramEXT(GLenum type, const GLchar *string);
	void glMakeBufferResidentNV(GLenum target, GLenum access);
	void glMakeBufferNonResidentNV(GLenum target);
	GLboolean glIsBufferResidentNV(GLenum target);
	void glMakeNamedBufferResidentNV(GLuint buffer, GLenum access);
	void glMakeNamedBufferNonResidentNV(GLuint buffer);
	GLboolean glIsNamedBufferResidentNV(GLuint buffer);
	void glGetBufferParameterui64vNV(GLenum target, GLenum pname, GLuint64EXT *params);
	void glGetNamedBufferParameterui64vNV(GLuint buffer, GLenum pname, GLuint64EXT *params);
	void glGetIntegerui64vNV(GLenum value, GLuint64EXT *result);
	void glUniformui64NV(GLint location, GLuint64EXT value);
	void glUniformui64vNV(GLint location, GLsizei count, const GLuint64EXT *value);
	void glGetUniformui64vNV(GLuint program, GLint location, GLuint64EXT *params);
	void glProgramUniformui64NV(GLuint program, GLint location, GLuint64EXT value);
	void glProgramUniformui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
	void glBufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
	void glVertexFormatNV(GLint size, GLenum type, GLsizei stride);
	void glNormalFormatNV(GLenum type, GLsizei stride);
	void glColorFormatNV(GLint size, GLenum type, GLsizei stride);
	void glIndexFormatNV(GLenum type, GLsizei stride);
	void glTexCoordFormatNV(GLint size, GLenum type, GLsizei stride);
	void glEdgeFlagFormatNV(GLsizei stride);
	void glSecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride);
	void glFogCoordFormatNV(GLenum type, GLsizei stride);
	void glVertexAttribFormatNV(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
	void glVertexAttribIFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride);
	void glGetIntegerui64i_vNV(GLenum value, GLuint index, GLuint64EXT *result);
	void glTextureBarrierNV(void);
	void glBindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
	void glMemoryBarrierEXT(GLbitfield barriers);
	void glVertexAttribL1dEXT(GLuint index, GLdouble x);
	void glVertexAttribL2dEXT(GLuint index, GLdouble x, GLdouble y);
	void glVertexAttribL3dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z);
	void glVertexAttribL4dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void glVertexAttribL1dvEXT(GLuint index, const GLdouble *v);
	void glVertexAttribL2dvEXT(GLuint index, const GLdouble *v);
	void glVertexAttribL3dvEXT(GLuint index, const GLdouble *v);
	void glVertexAttribL4dvEXT(GLuint index, const GLdouble *v);
	void glVertexAttribLPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	void glGetVertexAttribLdvEXT(GLuint index, GLenum pname, GLdouble *params);
	void glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
	void glProgramSubroutineParametersuivNV(GLenum target, GLsizei count, const GLuint *params);
	void glGetProgramSubroutineParameteruivNV(GLenum target, GLuint index, GLuint *param);
	void glUniform1i64NV(GLint location, GLint64EXT x);
	void glUniform2i64NV(GLint location, GLint64EXT x, GLint64EXT y);
	void glUniform3i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
	void glUniform4i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
	void glUniform1i64vNV(GLint location, GLsizei count, const GLint64EXT *value);
	void glUniform2i64vNV(GLint location, GLsizei count, const GLint64EXT *value);
	void glUniform3i64vNV(GLint location, GLsizei count, const GLint64EXT *value);
	void glUniform4i64vNV(GLint location, GLsizei count, const GLint64EXT *value);
	void glUniform1ui64NV(GLint location, GLuint64EXT x);
	void glUniform2ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y);
	void glUniform3ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
	void glUniform4ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
	void glUniform1ui64vNV(GLint location, GLsizei count, const GLuint64EXT *value);
	void glUniform2ui64vNV(GLint location, GLsizei count, const GLuint64EXT *value);
	void glUniform3ui64vNV(GLint location, GLsizei count, const GLuint64EXT *value);
	void glUniform4ui64vNV(GLint location, GLsizei count, const GLuint64EXT *value);
	void glGetUniformi64vNV(GLuint program, GLint location, GLint64EXT *params);
	void glProgramUniform1i64NV(GLuint program, GLint location, GLint64EXT x);
	void glProgramUniform2i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
	void glProgramUniform3i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
	void glProgramUniform4i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
	void glProgramUniform1i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
	void glProgramUniform2i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
	void glProgramUniform3i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
	void glProgramUniform4i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
	void glProgramUniform1ui64NV(GLuint program, GLint location, GLuint64EXT x);
	void glProgramUniform2ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
	void glProgramUniform3ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
	void glProgramUniform4ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
	void glProgramUniform1ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
	void glProgramUniform2ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
	void glProgramUniform3ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
	void glProgramUniform4ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
	void glVertexAttribL1i64NV(GLuint index, GLint64EXT x);
	void glVertexAttribL2i64NV(GLuint index, GLint64EXT x, GLint64EXT y);
	void glVertexAttribL3i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
	void glVertexAttribL4i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
	void glVertexAttribL1i64vNV(GLuint index, const GLint64EXT *v);
	void glVertexAttribL2i64vNV(GLuint index, const GLint64EXT *v);
	void glVertexAttribL3i64vNV(GLuint index, const GLint64EXT *v);
	void glVertexAttribL4i64vNV(GLuint index, const GLint64EXT *v);
	void glVertexAttribL1ui64NV(GLuint index, GLuint64EXT x);
	void glVertexAttribL2ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y);
	void glVertexAttribL3ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
	void glVertexAttribL4ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
	void glVertexAttribL1ui64vNV(GLuint index, const GLuint64EXT *v);
	void glVertexAttribL2ui64vNV(GLuint index, const GLuint64EXT *v);
	void glVertexAttribL3ui64vNV(GLuint index, const GLuint64EXT *v);
	void glVertexAttribL4ui64vNV(GLuint index, const GLuint64EXT *v);
	void glGetVertexAttribLi64vNV(GLuint index, GLenum pname, GLint64EXT *params);
	void glGetVertexAttribLui64vNV(GLuint index, GLenum pname, GLuint64EXT *params);
	void glVertexAttribLFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride);
	void glGenNamesAMD(GLenum identifier, GLuint num, GLuint *names);
	void glDeleteNamesAMD(GLenum identifier, GLuint num, const GLuint *names);
	GLboolean glIsNameAMD(GLenum identifier, GLuint name);
	void glDebugMessageEnableAMD(GLenum category, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
	void glDebugMessageInsertAMD(GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar *buf);
	void glDebugMessageCallbackAMD(GLDEBUGPROCAMD callback, GLvoid *userParam);
	GLuint glGetDebugMessageLogAMD(GLuint count, GLsizei bufsize, GLenum *categories, GLuint *severities, GLuint *ids, GLsizei *lengths, GLchar *message);
	void glVDPAUInitNV(const GLvoid *vdpDevice, const GLvoid *getProcAddress);
	void glVDPAUFiniNV(void);
	GLvdpauSurfaceNV glVDPAURegisterVideoSurfaceNV(GLvoid *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames);
	GLvdpauSurfaceNV glVDPAURegisterOutputSurfaceNV(GLvoid *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames);
	void glVDPAUIsSurfaceNV(GLvdpauSurfaceNV surface);
	void glVDPAUUnregisterSurfaceNV(GLvdpauSurfaceNV surface);
	void glVDPAUGetSurfaceivNV(GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
	void glVDPAUSurfaceAccessNV(GLvdpauSurfaceNV surface, GLenum access);
	void glVDPAUMapSurfacesNV(GLsizei numSurfaces, const GLvdpauSurfaceNV *surfaces);
	void glVDPAUUnmapSurfacesNV(GLsizei numSurface, const GLvdpauSurfaceNV *surfaces);
	void glTexImage2DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
	void glTexImage3DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
	void glTextureImage2DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
	void glTextureImage3DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
	void glTextureImage2DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
	void glTextureImage3DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
	void glSetMultisamplefvAMD(GLenum pname, GLuint index, const GLfloat *val);
	GLsync glImportSyncEXT(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags);
	void glMultiDrawArraysIndirectAMD(GLenum mode, const GLvoid *indirect, GLsizei primcount, GLsizei stride);
	void glMultiDrawElementsIndirectAMD(GLenum mode, GLenum type, const GLvoid *indirect, GLsizei primcount, GLsizei stride);
	HANDLE wglCreateBufferRegionARB(HDC hDC, int iLayerPlane, UINT uType);
	VOID wglDeleteBufferRegionARB(HANDLE hRegion);
	BOOL wglSaveBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height);
	BOOL wglRestoreBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
	const char * wglGetExtensionsStringARB(HDC hdc);
	BOOL wglGetPixelFormatAttribivARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
	BOOL wglGetPixelFormatAttribfvARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
	BOOL wglChoosePixelFormatARB(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
	BOOL wglMakeContextCurrentARB(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
	HDC wglGetCurrentReadDCARB(void);
	HPBUFFERARB wglCreatePbufferARB(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
	HDC wglGetPbufferDCARB(HPBUFFERARB hPbuffer);
	int wglReleasePbufferDCARB(HPBUFFERARB hPbuffer, HDC hDC);
	BOOL wglDestroyPbufferARB(HPBUFFERARB hPbuffer);
	BOOL wglQueryPbufferARB(HPBUFFERARB hPbuffer, int iAttribute, int *piValue);
	BOOL wglBindTexImageARB(HPBUFFERARB hPbuffer, int iBuffer);
	BOOL wglReleaseTexImageARB(HPBUFFERARB hPbuffer, int iBuffer);
	BOOL wglSetPbufferAttribARB(HPBUFFERARB hPbuffer, const int *piAttribList);
	HGLRC wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int *attribList);
	GLboolean wglCreateDisplayColorTableEXT(GLushort id);
	GLboolean wglLoadDisplayColorTableEXT(const GLushort *table, GLuint length);
	GLboolean wglBindDisplayColorTableEXT(GLushort id);
	VOID wglDestroyDisplayColorTableEXT(GLushort id);
	const char * wglGetExtensionsStringEXT(void);
	BOOL wglMakeContextCurrentEXT(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
	HDC wglGetCurrentReadDCEXT(void);
	HPBUFFEREXT wglCreatePbufferEXT(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
	HDC wglGetPbufferDCEXT(HPBUFFEREXT hPbuffer);
	int wglReleasePbufferDCEXT(HPBUFFEREXT hPbuffer, HDC hDC);
	BOOL wglDestroyPbufferEXT(HPBUFFEREXT hPbuffer);
	BOOL wglQueryPbufferEXT(HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);
	BOOL wglGetPixelFormatAttribivEXT(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
	BOOL wglGetPixelFormatAttribfvEXT(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
	BOOL wglChoosePixelFormatEXT(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
	BOOL wglSwapIntervalEXT(int interval);
	int wglGetSwapIntervalEXT(void);
	void* wglAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
	void wglFreeMemoryNV(void *pointer);
	BOOL wglGetSyncValuesOML(HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
	BOOL wglGetMscRateOML(HDC hdc, INT32 *numerator, INT32 *denominator);
	INT64 wglSwapBuffersMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
	INT64 wglSwapLayerBuffersMscOML(HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
	BOOL wglWaitForMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
	BOOL wglWaitForSbcOML(HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);
	BOOL wglGetDigitalVideoParametersI3D(HDC hDC, int iAttribute, int *piValue);
	BOOL wglSetDigitalVideoParametersI3D(HDC hDC, int iAttribute, const int *piValue);
	BOOL wglGetGammaTableParametersI3D(HDC hDC, int iAttribute, int *piValue);
	BOOL wglSetGammaTableParametersI3D(HDC hDC, int iAttribute, const int *piValue);
	BOOL wglGetGammaTableI3D(HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
	BOOL wglSetGammaTableI3D(HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);
	BOOL wglEnableGenlockI3D(HDC hDC);
	BOOL wglDisableGenlockI3D(HDC hDC);
	BOOL wglIsEnabledGenlockI3D(HDC hDC, BOOL *pFlag);
	BOOL wglGenlockSourceI3D(HDC hDC, UINT uSource);
	BOOL wglGetGenlockSourceI3D(HDC hDC, UINT *uSource);
	BOOL wglGenlockSourceEdgeI3D(HDC hDC, UINT uEdge);
	BOOL wglGetGenlockSourceEdgeI3D(HDC hDC, UINT *uEdge);
	BOOL wglGenlockSampleRateI3D(HDC hDC, UINT uRate);
	BOOL wglGetGenlockSampleRateI3D(HDC hDC, UINT *uRate);
	BOOL wglGenlockSourceDelayI3D(HDC hDC, UINT uDelay);
	BOOL wglGetGenlockSourceDelayI3D(HDC hDC, UINT *uDelay);
	BOOL wglQueryGenlockMaxSourceDelayI3D(HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);
	LPVOID wglCreateImageBufferI3D(HDC hDC, DWORD dwSize, UINT uFlags);
	BOOL wglDestroyImageBufferI3D(HDC hDC, LPVOID pAddress);
	BOOL wglAssociateImageBufferEventsI3D(HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
	BOOL wglReleaseImageBufferEventsI3D(HDC hDC, const LPVOID *pAddress, UINT count);
	BOOL wglEnableFrameLockI3D(void);
	BOOL wglDisableFrameLockI3D(void);
	BOOL wglIsEnabledFrameLockI3D(BOOL *pFlag);
	BOOL wglQueryFrameLockMasterI3D(BOOL *pFlag);
	BOOL wglGetFrameUsageI3D(float *pUsage);
	BOOL wglBeginFrameTrackingI3D(void);
	BOOL wglEndFrameTrackingI3D(void);
	BOOL wglQueryFrameTrackingI3D(DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);
	BOOL wglSetStereoEmitterState3DL(HDC hDC, UINT uState);
	int wglEnumerateVideoDevicesNV(HDC hDC, HVIDEOOUTPUTDEVICENV *phDeviceList);
	BOOL wglBindVideoDeviceNV(HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int *piAttribList);
	BOOL wglQueryCurrentContextNV(int iAttribute, int *piValue);
	BOOL wglGetVideoDeviceNV(HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
	BOOL wglReleaseVideoDeviceNV(HPVIDEODEV hVideoDevice);
	BOOL wglBindVideoImageNV(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
	BOOL wglReleaseVideoImageNV(HPBUFFERARB hPbuffer, int iVideoBuffer);
	BOOL wglSendPbufferToVideoNV(HPBUFFERARB hPbuffer, int iBufferType, unsigned long *pulCounterPbuffer, BOOL bBlock);
	BOOL wglGetVideoInfoNV(HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo);
	BOOL wglJoinSwapGroupNV(HDC hDC, GLuint group);
	BOOL wglBindSwapBarrierNV(GLuint group, GLuint barrier);
	BOOL wglQuerySwapGroupNV(HDC hDC, GLuint *group, GLuint *barrier);
	BOOL wglQueryMaxSwapGroupsNV(HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
	BOOL wglQueryFrameCountNV(HDC hDC, GLuint *count);
	BOOL wglResetFrameCountNV(HDC hDC);
	BOOL wglEnumGpusNV(UINT iGpuIndex, HGPUNV *phGpu);
	BOOL wglEnumGpuDevicesNV(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
	HDC wglCreateAffinityDCNV(const HGPUNV *phGpuList);
	BOOL wglEnumGpusFromAffinityDCNV(HDC hAffinityDC, UINT iGpuIndex, HGPUNV *hGpu);
	BOOL wglDeleteDCNV(HDC hdc);
	UINT wglGetGPUIDsAMD(UINT maxCount, UINT *ids);
	INT wglGetGPUInfoAMD(UINT id, int property, GLenum dataType, UINT size, void *data);
	UINT wglGetContextGPUIDAMD(HGLRC hglrc);
	HGLRC wglCreateAssociatedContextAMD(UINT id);
	HGLRC wglCreateAssociatedContextAttribsAMD(UINT id, HGLRC hShareContext, const int *attribList);
	BOOL wglDeleteAssociatedContextAMD(HGLRC hglrc);
	BOOL wglMakeAssociatedContextCurrentAMD(HGLRC hglrc);
	HGLRC wglGetCurrentAssociatedContextAMD(void);
	VOID wglBlitContextFramebufferAMD(HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	BOOL wglBindVideoCaptureDeviceNV(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
	UINT wglEnumerateVideoCaptureDevicesNV(HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
	BOOL wglLockVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
	BOOL wglQueryVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
	BOOL wglReleaseVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
	BOOL wglCopyImageSubDataNV(HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
	BOOL wglDXSetResourceShareHandleNV(void *dxObject, HANDLE shareHandle);
	HANDLE wglDXOpenDeviceNV(void *dxDevice);
	BOOL wglDXCloseDeviceNV(HANDLE hDevice);
	HANDLE wglDXRegisterObjectNV(HANDLE hDevice, void *dxObject, GLuint name, GLenum type, GLenum access);
	BOOL wglDXUnregisterObjectNV(HANDLE hDevice, HANDLE hObject);
	BOOL wglDXObjectAccessNV(HANDLE hObject, GLenum access);
	BOOL wglDXLockObjectsNV(HANDLE hDevice, GLint count, HANDLE *hObjects);
	BOOL wglDXUnlockObjectsNV(HANDLE hDevice, GLint count, HANDLE *hObjects);
private:
	// Private member variables
	glexfp *m_pglex;
};

//----------------------------------------------------------------------------

inline glex::glex() {
	m_pglex = new glexfp;
	assert(m_pglex!=NULL);
}

inline glex::~glex() {
	delete m_pglex;
}

inline bool glex::Load() {
	return m_pglex->Load();
}

inline long glex::Count() const {
	return m_pglex->Count();
}

inline long glex::Known() const {
	return m_pglex->Known();
}

inline bool glex::Supports(const char *sExt) const {
	return m_pglex->Supports(sExt);
}

inline void glex::glBlendColor(GLclampf a, GLclampf b, GLclampf c, GLclampf d) {
	m_pglex->glBlendColor(a,b,c,d);
}

inline void glex::glBlendEquation(GLenum a) {
	m_pglex->glBlendEquation(a);
}

inline void glex::glDrawRangeElements(GLenum a, GLuint b, GLuint c, GLsizei d, GLenum e, const GLvoid *f) {
	m_pglex->glDrawRangeElements(a,b,c,d,e,f);
}

inline void glex::glTexImage3D(GLenum a, GLint b, GLint c, GLsizei d, GLsizei e, GLsizei f, GLint g, GLenum h, GLenum i, const GLvoid *j) {
	m_pglex->glTexImage3D(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glTexSubImage3D(GLenum a, GLint b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLsizei h, GLenum i, GLenum j, const GLvoid *k) {
	m_pglex->glTexSubImage3D(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glCopyTexSubImage3D(GLenum a, GLint b, GLint c, GLint d, GLint e, GLint f, GLint g, GLsizei h, GLsizei i) {
	m_pglex->glCopyTexSubImage3D(a,b,c,d,e,f,g,h,i);
}

inline void glex::glColorTable(GLenum a, GLenum b, GLsizei c, GLenum d, GLenum e, const GLvoid *f) {
	m_pglex->glColorTable(a,b,c,d,e,f);
}

inline void glex::glColorTableParameterfv(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glColorTableParameterfv(a,b,c);
}

inline void glex::glColorTableParameteriv(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glColorTableParameteriv(a,b,c);
}

inline void glex::glCopyColorTable(GLenum a, GLenum b, GLint c, GLint d, GLsizei e) {
	m_pglex->glCopyColorTable(a,b,c,d,e);
}

inline void glex::glGetColorTable(GLenum a, GLenum b, GLenum c, GLvoid *d) {
	m_pglex->glGetColorTable(a,b,c,d);
}

inline void glex::glGetColorTableParameterfv(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetColorTableParameterfv(a,b,c);
}

inline void glex::glGetColorTableParameteriv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetColorTableParameteriv(a,b,c);
}

inline void glex::glColorSubTable(GLenum a, GLsizei b, GLsizei c, GLenum d, GLenum e, const GLvoid *f) {
	m_pglex->glColorSubTable(a,b,c,d,e,f);
}

inline void glex::glCopyColorSubTable(GLenum a, GLsizei b, GLint c, GLint d, GLsizei e) {
	m_pglex->glCopyColorSubTable(a,b,c,d,e);
}

inline void glex::glConvolutionFilter1D(GLenum a, GLenum b, GLsizei c, GLenum d, GLenum e, const GLvoid *f) {
	m_pglex->glConvolutionFilter1D(a,b,c,d,e,f);
}

inline void glex::glConvolutionFilter2D(GLenum a, GLenum b, GLsizei c, GLsizei d, GLenum e, GLenum f, const GLvoid *g) {
	m_pglex->glConvolutionFilter2D(a,b,c,d,e,f,g);
}

inline void glex::glConvolutionParameterf(GLenum a, GLenum b, GLfloat c) {
	m_pglex->glConvolutionParameterf(a,b,c);
}

inline void glex::glConvolutionParameterfv(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glConvolutionParameterfv(a,b,c);
}

inline void glex::glConvolutionParameteri(GLenum a, GLenum b, GLint c) {
	m_pglex->glConvolutionParameteri(a,b,c);
}

inline void glex::glConvolutionParameteriv(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glConvolutionParameteriv(a,b,c);
}

inline void glex::glCopyConvolutionFilter1D(GLenum a, GLenum b, GLint c, GLint d, GLsizei e) {
	m_pglex->glCopyConvolutionFilter1D(a,b,c,d,e);
}

inline void glex::glCopyConvolutionFilter2D(GLenum a, GLenum b, GLint c, GLint d, GLsizei e, GLsizei f) {
	m_pglex->glCopyConvolutionFilter2D(a,b,c,d,e,f);
}

inline void glex::glGetConvolutionFilter(GLenum a, GLenum b, GLenum c, GLvoid *d) {
	m_pglex->glGetConvolutionFilter(a,b,c,d);
}

inline void glex::glGetConvolutionParameterfv(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetConvolutionParameterfv(a,b,c);
}

inline void glex::glGetConvolutionParameteriv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetConvolutionParameteriv(a,b,c);
}

inline void glex::glGetSeparableFilter(GLenum a, GLenum b, GLenum c, GLvoid *d, GLvoid *e, GLvoid *f) {
	m_pglex->glGetSeparableFilter(a,b,c,d,e,f);
}

inline void glex::glSeparableFilter2D(GLenum a, GLenum b, GLsizei c, GLsizei d, GLenum e, GLenum f, const GLvoid *g, const GLvoid *h) {
	m_pglex->glSeparableFilter2D(a,b,c,d,e,f,g,h);
}

inline void glex::glGetHistogram(GLenum a, GLboolean b, GLenum c, GLenum d, GLvoid *e) {
	m_pglex->glGetHistogram(a,b,c,d,e);
}

inline void glex::glGetHistogramParameterfv(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetHistogramParameterfv(a,b,c);
}

inline void glex::glGetHistogramParameteriv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetHistogramParameteriv(a,b,c);
}

inline void glex::glGetMinmax(GLenum a, GLboolean b, GLenum c, GLenum d, GLvoid *e) {
	m_pglex->glGetMinmax(a,b,c,d,e);
}

inline void glex::glGetMinmaxParameterfv(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetMinmaxParameterfv(a,b,c);
}

inline void glex::glGetMinmaxParameteriv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetMinmaxParameteriv(a,b,c);
}

inline void glex::glHistogram(GLenum a, GLsizei b, GLenum c, GLboolean d) {
	m_pglex->glHistogram(a,b,c,d);
}

inline void glex::glMinmax(GLenum a, GLenum b, GLboolean c) {
	m_pglex->glMinmax(a,b,c);
}

inline void glex::glResetHistogram(GLenum a) {
	m_pglex->glResetHistogram(a);
}

inline void glex::glResetMinmax(GLenum a) {
	m_pglex->glResetMinmax(a);
}

inline void glex::glActiveTexture(GLenum a) {
	m_pglex->glActiveTexture(a);
}

inline void glex::glSampleCoverage(GLclampf a, GLboolean b) {
	m_pglex->glSampleCoverage(a,b);
}

inline void glex::glCompressedTexImage3D(GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLsizei f, GLint g, GLsizei h, const GLvoid *i) {
	m_pglex->glCompressedTexImage3D(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCompressedTexImage2D(GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLint f, GLsizei g, const GLvoid *h) {
	m_pglex->glCompressedTexImage2D(a,b,c,d,e,f,g,h);
}

inline void glex::glCompressedTexImage1D(GLenum a, GLint b, GLenum c, GLsizei d, GLint e, GLsizei f, const GLvoid *g) {
	m_pglex->glCompressedTexImage1D(a,b,c,d,e,f,g);
}

inline void glex::glCompressedTexSubImage3D(GLenum a, GLint b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLsizei h, GLenum i, GLsizei j, const GLvoid *k) {
	m_pglex->glCompressedTexSubImage3D(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glCompressedTexSubImage2D(GLenum a, GLint b, GLint c, GLint d, GLsizei e, GLsizei f, GLenum g, GLsizei h, const GLvoid *i) {
	m_pglex->glCompressedTexSubImage2D(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCompressedTexSubImage1D(GLenum a, GLint b, GLint c, GLsizei d, GLenum e, GLsizei f, const GLvoid *g) {
	m_pglex->glCompressedTexSubImage1D(a,b,c,d,e,f,g);
}

inline void glex::glGetCompressedTexImage(GLenum a, GLint b, GLvoid *c) {
	m_pglex->glGetCompressedTexImage(a,b,c);
}

inline void glex::glClientActiveTexture(GLenum a) {
	m_pglex->glClientActiveTexture(a);
}

inline void glex::glMultiTexCoord1d(GLenum a, GLdouble b) {
	m_pglex->glMultiTexCoord1d(a,b);
}

inline void glex::glMultiTexCoord1dv(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord1dv(a,b);
}

inline void glex::glMultiTexCoord1f(GLenum a, GLfloat b) {
	m_pglex->glMultiTexCoord1f(a,b);
}

inline void glex::glMultiTexCoord1fv(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord1fv(a,b);
}

inline void glex::glMultiTexCoord1i(GLenum a, GLint b) {
	m_pglex->glMultiTexCoord1i(a,b);
}

inline void glex::glMultiTexCoord1iv(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord1iv(a,b);
}

inline void glex::glMultiTexCoord1s(GLenum a, GLshort b) {
	m_pglex->glMultiTexCoord1s(a,b);
}

inline void glex::glMultiTexCoord1sv(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord1sv(a,b);
}

inline void glex::glMultiTexCoord2d(GLenum a, GLdouble b, GLdouble c) {
	m_pglex->glMultiTexCoord2d(a,b,c);
}

inline void glex::glMultiTexCoord2dv(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord2dv(a,b);
}

inline void glex::glMultiTexCoord2f(GLenum a, GLfloat b, GLfloat c) {
	m_pglex->glMultiTexCoord2f(a,b,c);
}

inline void glex::glMultiTexCoord2fv(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord2fv(a,b);
}

inline void glex::glMultiTexCoord2i(GLenum a, GLint b, GLint c) {
	m_pglex->glMultiTexCoord2i(a,b,c);
}

inline void glex::glMultiTexCoord2iv(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord2iv(a,b);
}

inline void glex::glMultiTexCoord2s(GLenum a, GLshort b, GLshort c) {
	m_pglex->glMultiTexCoord2s(a,b,c);
}

inline void glex::glMultiTexCoord2sv(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord2sv(a,b);
}

inline void glex::glMultiTexCoord3d(GLenum a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glMultiTexCoord3d(a,b,c,d);
}

inline void glex::glMultiTexCoord3dv(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord3dv(a,b);
}

inline void glex::glMultiTexCoord3f(GLenum a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glMultiTexCoord3f(a,b,c,d);
}

inline void glex::glMultiTexCoord3fv(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord3fv(a,b);
}

inline void glex::glMultiTexCoord3i(GLenum a, GLint b, GLint c, GLint d) {
	m_pglex->glMultiTexCoord3i(a,b,c,d);
}

inline void glex::glMultiTexCoord3iv(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord3iv(a,b);
}

inline void glex::glMultiTexCoord3s(GLenum a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glMultiTexCoord3s(a,b,c,d);
}

inline void glex::glMultiTexCoord3sv(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord3sv(a,b);
}

inline void glex::glMultiTexCoord4d(GLenum a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glMultiTexCoord4d(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4dv(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord4dv(a,b);
}

inline void glex::glMultiTexCoord4f(GLenum a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glMultiTexCoord4f(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4fv(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord4fv(a,b);
}

inline void glex::glMultiTexCoord4i(GLenum a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glMultiTexCoord4i(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4iv(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord4iv(a,b);
}

inline void glex::glMultiTexCoord4s(GLenum a, GLshort b, GLshort c, GLshort d, GLshort e) {
	m_pglex->glMultiTexCoord4s(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4sv(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord4sv(a,b);
}

inline void glex::glLoadTransposeMatrixf(const GLfloat *a) {
	m_pglex->glLoadTransposeMatrixf(a);
}

inline void glex::glLoadTransposeMatrixd(const GLdouble *a) {
	m_pglex->glLoadTransposeMatrixd(a);
}

inline void glex::glMultTransposeMatrixf(const GLfloat *a) {
	m_pglex->glMultTransposeMatrixf(a);
}

inline void glex::glMultTransposeMatrixd(const GLdouble *a) {
	m_pglex->glMultTransposeMatrixd(a);
}

inline void glex::glBlendFuncSeparate(GLenum a, GLenum b, GLenum c, GLenum d) {
	m_pglex->glBlendFuncSeparate(a,b,c,d);
}

inline void glex::glMultiDrawArrays(GLenum a, const GLint *b, const GLsizei *c, GLsizei d) {
	m_pglex->glMultiDrawArrays(a,b,c,d);
}

inline void glex::glMultiDrawElements(GLenum a, const GLsizei *b, GLenum c, const GLvoid* *d, GLsizei e) {
	m_pglex->glMultiDrawElements(a,b,c,d,e);
}

inline void glex::glPointParameterf(GLenum a, GLfloat b) {
	m_pglex->glPointParameterf(a,b);
}

inline void glex::glPointParameterfv(GLenum a, const GLfloat *b) {
	m_pglex->glPointParameterfv(a,b);
}

inline void glex::glPointParameteri(GLenum a, GLint b) {
	m_pglex->glPointParameteri(a,b);
}

inline void glex::glPointParameteriv(GLenum a, const GLint *b) {
	m_pglex->glPointParameteriv(a,b);
}

inline void glex::glFogCoordf(GLfloat a) {
	m_pglex->glFogCoordf(a);
}

inline void glex::glFogCoordfv(const GLfloat *a) {
	m_pglex->glFogCoordfv(a);
}

inline void glex::glFogCoordd(GLdouble a) {
	m_pglex->glFogCoordd(a);
}

inline void glex::glFogCoorddv(const GLdouble *a) {
	m_pglex->glFogCoorddv(a);
}

inline void glex::glFogCoordPointer(GLenum a, GLsizei b, const GLvoid *c) {
	m_pglex->glFogCoordPointer(a,b,c);
}

inline void glex::glSecondaryColor3b(GLbyte a, GLbyte b, GLbyte c) {
	m_pglex->glSecondaryColor3b(a,b,c);
}

inline void glex::glSecondaryColor3bv(const GLbyte *a) {
	m_pglex->glSecondaryColor3bv(a);
}

inline void glex::glSecondaryColor3d(GLdouble a, GLdouble b, GLdouble c) {
	m_pglex->glSecondaryColor3d(a,b,c);
}

inline void glex::glSecondaryColor3dv(const GLdouble *a) {
	m_pglex->glSecondaryColor3dv(a);
}

inline void glex::glSecondaryColor3f(GLfloat a, GLfloat b, GLfloat c) {
	m_pglex->glSecondaryColor3f(a,b,c);
}

inline void glex::glSecondaryColor3fv(const GLfloat *a) {
	m_pglex->glSecondaryColor3fv(a);
}

inline void glex::glSecondaryColor3i(GLint a, GLint b, GLint c) {
	m_pglex->glSecondaryColor3i(a,b,c);
}

inline void glex::glSecondaryColor3iv(const GLint *a) {
	m_pglex->glSecondaryColor3iv(a);
}

inline void glex::glSecondaryColor3s(GLshort a, GLshort b, GLshort c) {
	m_pglex->glSecondaryColor3s(a,b,c);
}

inline void glex::glSecondaryColor3sv(const GLshort *a) {
	m_pglex->glSecondaryColor3sv(a);
}

inline void glex::glSecondaryColor3ub(GLubyte a, GLubyte b, GLubyte c) {
	m_pglex->glSecondaryColor3ub(a,b,c);
}

inline void glex::glSecondaryColor3ubv(const GLubyte *a) {
	m_pglex->glSecondaryColor3ubv(a);
}

inline void glex::glSecondaryColor3ui(GLuint a, GLuint b, GLuint c) {
	m_pglex->glSecondaryColor3ui(a,b,c);
}

inline void glex::glSecondaryColor3uiv(const GLuint *a) {
	m_pglex->glSecondaryColor3uiv(a);
}

inline void glex::glSecondaryColor3us(GLushort a, GLushort b, GLushort c) {
	m_pglex->glSecondaryColor3us(a,b,c);
}

inline void glex::glSecondaryColor3usv(const GLushort *a) {
	m_pglex->glSecondaryColor3usv(a);
}

inline void glex::glSecondaryColorPointer(GLint a, GLenum b, GLsizei c, const GLvoid *d) {
	m_pglex->glSecondaryColorPointer(a,b,c,d);
}

inline void glex::glWindowPos2d(GLdouble a, GLdouble b) {
	m_pglex->glWindowPos2d(a,b);
}

inline void glex::glWindowPos2dv(const GLdouble *a) {
	m_pglex->glWindowPos2dv(a);
}

inline void glex::glWindowPos2f(GLfloat a, GLfloat b) {
	m_pglex->glWindowPos2f(a,b);
}

inline void glex::glWindowPos2fv(const GLfloat *a) {
	m_pglex->glWindowPos2fv(a);
}

inline void glex::glWindowPos2i(GLint a, GLint b) {
	m_pglex->glWindowPos2i(a,b);
}

inline void glex::glWindowPos2iv(const GLint *a) {
	m_pglex->glWindowPos2iv(a);
}

inline void glex::glWindowPos2s(GLshort a, GLshort b) {
	m_pglex->glWindowPos2s(a,b);
}

inline void glex::glWindowPos2sv(const GLshort *a) {
	m_pglex->glWindowPos2sv(a);
}

inline void glex::glWindowPos3d(GLdouble a, GLdouble b, GLdouble c) {
	m_pglex->glWindowPos3d(a,b,c);
}

inline void glex::glWindowPos3dv(const GLdouble *a) {
	m_pglex->glWindowPos3dv(a);
}

inline void glex::glWindowPos3f(GLfloat a, GLfloat b, GLfloat c) {
	m_pglex->glWindowPos3f(a,b,c);
}

inline void glex::glWindowPos3fv(const GLfloat *a) {
	m_pglex->glWindowPos3fv(a);
}

inline void glex::glWindowPos3i(GLint a, GLint b, GLint c) {
	m_pglex->glWindowPos3i(a,b,c);
}

inline void glex::glWindowPos3iv(const GLint *a) {
	m_pglex->glWindowPos3iv(a);
}

inline void glex::glWindowPos3s(GLshort a, GLshort b, GLshort c) {
	m_pglex->glWindowPos3s(a,b,c);
}

inline void glex::glWindowPos3sv(const GLshort *a) {
	m_pglex->glWindowPos3sv(a);
}

inline void glex::glGenQueries(GLsizei a, GLuint *b) {
	m_pglex->glGenQueries(a,b);
}

inline void glex::glDeleteQueries(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteQueries(a,b);
}

inline GLboolean glex::glIsQuery(GLuint a) {
	return m_pglex->glIsQuery(a);
}

inline void glex::glBeginQuery(GLenum a, GLuint b) {
	m_pglex->glBeginQuery(a,b);
}

inline void glex::glEndQuery(GLenum a) {
	m_pglex->glEndQuery(a);
}

inline void glex::glGetQueryiv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetQueryiv(a,b,c);
}

inline void glex::glGetQueryObjectiv(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetQueryObjectiv(a,b,c);
}

inline void glex::glGetQueryObjectuiv(GLuint a, GLenum b, GLuint *c) {
	m_pglex->glGetQueryObjectuiv(a,b,c);
}

inline void glex::glBindBuffer(GLenum a, GLuint b) {
	m_pglex->glBindBuffer(a,b);
}

inline void glex::glDeleteBuffers(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteBuffers(a,b);
}

inline void glex::glGenBuffers(GLsizei a, GLuint *b) {
	m_pglex->glGenBuffers(a,b);
}

inline GLboolean glex::glIsBuffer(GLuint a) {
	return m_pglex->glIsBuffer(a);
}

inline void glex::glBufferData(GLenum a, GLsizeiptr b, const GLvoid *c, GLenum d) {
	m_pglex->glBufferData(a,b,c,d);
}

inline void glex::glBufferSubData(GLenum a, GLintptr b, GLsizeiptr c, const GLvoid *d) {
	m_pglex->glBufferSubData(a,b,c,d);
}

inline void glex::glGetBufferSubData(GLenum a, GLintptr b, GLsizeiptr c, GLvoid *d) {
	m_pglex->glGetBufferSubData(a,b,c,d);
}

inline GLvoid* glex::glMapBuffer(GLenum a, GLenum b) {
	return m_pglex->glMapBuffer(a,b);
}

inline GLboolean glex::glUnmapBuffer(GLenum a) {
	return m_pglex->glUnmapBuffer(a);
}

inline void glex::glGetBufferParameteriv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetBufferParameteriv(a,b,c);
}

inline void glex::glGetBufferPointerv(GLenum a, GLenum b, GLvoid* *c) {
	m_pglex->glGetBufferPointerv(a,b,c);
}

inline void glex::glBlendEquationSeparate(GLenum a, GLenum b) {
	m_pglex->glBlendEquationSeparate(a,b);
}

inline void glex::glDrawBuffers(GLsizei a, const GLenum *b) {
	m_pglex->glDrawBuffers(a,b);
}

inline void glex::glStencilOpSeparate(GLenum a, GLenum b, GLenum c, GLenum d) {
	m_pglex->glStencilOpSeparate(a,b,c,d);
}

inline void glex::glStencilFuncSeparate(GLenum a, GLenum b, GLint c, GLuint d) {
	m_pglex->glStencilFuncSeparate(a,b,c,d);
}

inline void glex::glStencilMaskSeparate(GLenum a, GLuint b) {
	m_pglex->glStencilMaskSeparate(a,b);
}

inline void glex::glAttachShader(GLuint a, GLuint b) {
	m_pglex->glAttachShader(a,b);
}

inline void glex::glBindAttribLocation(GLuint a, GLuint b, const GLchar *c) {
	m_pglex->glBindAttribLocation(a,b,c);
}

inline void glex::glCompileShader(GLuint a) {
	m_pglex->glCompileShader(a);
}

inline GLuint glex::glCreateProgram(void) {
	return m_pglex->glCreateProgram();
}

inline GLuint glex::glCreateShader(GLenum a) {
	return m_pglex->glCreateShader(a);
}

inline void glex::glDeleteProgram(GLuint a) {
	m_pglex->glDeleteProgram(a);
}

inline void glex::glDeleteShader(GLuint a) {
	m_pglex->glDeleteShader(a);
}

inline void glex::glDetachShader(GLuint a, GLuint b) {
	m_pglex->glDetachShader(a,b);
}

inline void glex::glDisableVertexAttribArray(GLuint a) {
	m_pglex->glDisableVertexAttribArray(a);
}

inline void glex::glEnableVertexAttribArray(GLuint a) {
	m_pglex->glEnableVertexAttribArray(a);
}

inline void glex::glGetActiveAttrib(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLint *e, GLenum *f, GLchar *g) {
	m_pglex->glGetActiveAttrib(a,b,c,d,e,f,g);
}

inline void glex::glGetActiveUniform(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLint *e, GLenum *f, GLchar *g) {
	m_pglex->glGetActiveUniform(a,b,c,d,e,f,g);
}

inline void glex::glGetAttachedShaders(GLuint a, GLsizei b, GLsizei *c, GLuint *d) {
	m_pglex->glGetAttachedShaders(a,b,c,d);
}

inline GLint glex::glGetAttribLocation(GLuint a, const GLchar *b) {
	return m_pglex->glGetAttribLocation(a,b);
}

inline void glex::glGetProgramiv(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetProgramiv(a,b,c);
}

inline void glex::glGetProgramInfoLog(GLuint a, GLsizei b, GLsizei *c, GLchar *d) {
	m_pglex->glGetProgramInfoLog(a,b,c,d);
}

inline void glex::glGetShaderiv(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetShaderiv(a,b,c);
}

inline void glex::glGetShaderInfoLog(GLuint a, GLsizei b, GLsizei *c, GLchar *d) {
	m_pglex->glGetShaderInfoLog(a,b,c,d);
}

inline void glex::glGetShaderSource(GLuint a, GLsizei b, GLsizei *c, GLchar *d) {
	m_pglex->glGetShaderSource(a,b,c,d);
}

inline GLint glex::glGetUniformLocation(GLuint a, const GLchar *b) {
	return m_pglex->glGetUniformLocation(a,b);
}

inline void glex::glGetUniformfv(GLuint a, GLint b, GLfloat *c) {
	m_pglex->glGetUniformfv(a,b,c);
}

inline void glex::glGetUniformiv(GLuint a, GLint b, GLint *c) {
	m_pglex->glGetUniformiv(a,b,c);
}

inline void glex::glGetVertexAttribdv(GLuint a, GLenum b, GLdouble *c) {
	m_pglex->glGetVertexAttribdv(a,b,c);
}

inline void glex::glGetVertexAttribfv(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetVertexAttribfv(a,b,c);
}

inline void glex::glGetVertexAttribiv(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVertexAttribiv(a,b,c);
}

inline void glex::glGetVertexAttribPointerv(GLuint a, GLenum b, GLvoid* *c) {
	m_pglex->glGetVertexAttribPointerv(a,b,c);
}

inline GLboolean glex::glIsProgram(GLuint a) {
	return m_pglex->glIsProgram(a);
}

inline GLboolean glex::glIsShader(GLuint a) {
	return m_pglex->glIsShader(a);
}

inline void glex::glLinkProgram(GLuint a) {
	m_pglex->glLinkProgram(a);
}

inline void glex::glShaderSource(GLuint a, GLsizei b, const GLchar* *c, const GLint *d) {
	m_pglex->glShaderSource(a,b,c,d);
}

inline void glex::glUseProgram(GLuint a) {
	m_pglex->glUseProgram(a);
}

inline void glex::glUniform1f(GLint a, GLfloat b) {
	m_pglex->glUniform1f(a,b);
}

inline void glex::glUniform2f(GLint a, GLfloat b, GLfloat c) {
	m_pglex->glUniform2f(a,b,c);
}

inline void glex::glUniform3f(GLint a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glUniform3f(a,b,c,d);
}

inline void glex::glUniform4f(GLint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glUniform4f(a,b,c,d,e);
}

inline void glex::glUniform1i(GLint a, GLint b) {
	m_pglex->glUniform1i(a,b);
}

inline void glex::glUniform2i(GLint a, GLint b, GLint c) {
	m_pglex->glUniform2i(a,b,c);
}

inline void glex::glUniform3i(GLint a, GLint b, GLint c, GLint d) {
	m_pglex->glUniform3i(a,b,c,d);
}

inline void glex::glUniform4i(GLint a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glUniform4i(a,b,c,d,e);
}

inline void glex::glUniform1fv(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform1fv(a,b,c);
}

inline void glex::glUniform2fv(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform2fv(a,b,c);
}

inline void glex::glUniform3fv(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform3fv(a,b,c);
}

inline void glex::glUniform4fv(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform4fv(a,b,c);
}

inline void glex::glUniform1iv(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform1iv(a,b,c);
}

inline void glex::glUniform2iv(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform2iv(a,b,c);
}

inline void glex::glUniform3iv(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform3iv(a,b,c);
}

inline void glex::glUniform4iv(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform4iv(a,b,c);
}

inline void glex::glUniformMatrix2fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix2fv(a,b,c,d);
}

inline void glex::glUniformMatrix3fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix3fv(a,b,c,d);
}

inline void glex::glUniformMatrix4fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix4fv(a,b,c,d);
}

inline void glex::glValidateProgram(GLuint a) {
	m_pglex->glValidateProgram(a);
}

inline void glex::glVertexAttrib1d(GLuint a, GLdouble b) {
	m_pglex->glVertexAttrib1d(a,b);
}

inline void glex::glVertexAttrib1dv(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib1dv(a,b);
}

inline void glex::glVertexAttrib1f(GLuint a, GLfloat b) {
	m_pglex->glVertexAttrib1f(a,b);
}

inline void glex::glVertexAttrib1fv(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib1fv(a,b);
}

inline void glex::glVertexAttrib1s(GLuint a, GLshort b) {
	m_pglex->glVertexAttrib1s(a,b);
}

inline void glex::glVertexAttrib1sv(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib1sv(a,b);
}

inline void glex::glVertexAttrib2d(GLuint a, GLdouble b, GLdouble c) {
	m_pglex->glVertexAttrib2d(a,b,c);
}

inline void glex::glVertexAttrib2dv(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib2dv(a,b);
}

inline void glex::glVertexAttrib2f(GLuint a, GLfloat b, GLfloat c) {
	m_pglex->glVertexAttrib2f(a,b,c);
}

inline void glex::glVertexAttrib2fv(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib2fv(a,b);
}

inline void glex::glVertexAttrib2s(GLuint a, GLshort b, GLshort c) {
	m_pglex->glVertexAttrib2s(a,b,c);
}

inline void glex::glVertexAttrib2sv(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib2sv(a,b);
}

inline void glex::glVertexAttrib3d(GLuint a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glVertexAttrib3d(a,b,c,d);
}

inline void glex::glVertexAttrib3dv(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib3dv(a,b);
}

inline void glex::glVertexAttrib3f(GLuint a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glVertexAttrib3f(a,b,c,d);
}

inline void glex::glVertexAttrib3fv(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib3fv(a,b);
}

inline void glex::glVertexAttrib3s(GLuint a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glVertexAttrib3s(a,b,c,d);
}

inline void glex::glVertexAttrib3sv(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib3sv(a,b);
}

inline void glex::glVertexAttrib4Nbv(GLuint a, const GLbyte *b) {
	m_pglex->glVertexAttrib4Nbv(a,b);
}

inline void glex::glVertexAttrib4Niv(GLuint a, const GLint *b) {
	m_pglex->glVertexAttrib4Niv(a,b);
}

inline void glex::glVertexAttrib4Nsv(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib4Nsv(a,b);
}

inline void glex::glVertexAttrib4Nub(GLuint a, GLubyte b, GLubyte c, GLubyte d, GLubyte e) {
	m_pglex->glVertexAttrib4Nub(a,b,c,d,e);
}

inline void glex::glVertexAttrib4Nubv(GLuint a, const GLubyte *b) {
	m_pglex->glVertexAttrib4Nubv(a,b);
}

inline void glex::glVertexAttrib4Nuiv(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttrib4Nuiv(a,b);
}

inline void glex::glVertexAttrib4Nusv(GLuint a, const GLushort *b) {
	m_pglex->glVertexAttrib4Nusv(a,b);
}

inline void glex::glVertexAttrib4bv(GLuint a, const GLbyte *b) {
	m_pglex->glVertexAttrib4bv(a,b);
}

inline void glex::glVertexAttrib4d(GLuint a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glVertexAttrib4d(a,b,c,d,e);
}

inline void glex::glVertexAttrib4dv(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib4dv(a,b);
}

inline void glex::glVertexAttrib4f(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glVertexAttrib4f(a,b,c,d,e);
}

inline void glex::glVertexAttrib4fv(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib4fv(a,b);
}

inline void glex::glVertexAttrib4iv(GLuint a, const GLint *b) {
	m_pglex->glVertexAttrib4iv(a,b);
}

inline void glex::glVertexAttrib4s(GLuint a, GLshort b, GLshort c, GLshort d, GLshort e) {
	m_pglex->glVertexAttrib4s(a,b,c,d,e);
}

inline void glex::glVertexAttrib4sv(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib4sv(a,b);
}

inline void glex::glVertexAttrib4ubv(GLuint a, const GLubyte *b) {
	m_pglex->glVertexAttrib4ubv(a,b);
}

inline void glex::glVertexAttrib4uiv(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttrib4uiv(a,b);
}

inline void glex::glVertexAttrib4usv(GLuint a, const GLushort *b) {
	m_pglex->glVertexAttrib4usv(a,b);
}

inline void glex::glVertexAttribPointer(GLuint a, GLint b, GLenum c, GLboolean d, GLsizei e, const GLvoid *f) {
	m_pglex->glVertexAttribPointer(a,b,c,d,e,f);
}

inline void glex::glUniformMatrix2x3fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix2x3fv(a,b,c,d);
}

inline void glex::glUniformMatrix3x2fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix3x2fv(a,b,c,d);
}

inline void glex::glUniformMatrix2x4fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix2x4fv(a,b,c,d);
}

inline void glex::glUniformMatrix4x2fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix4x2fv(a,b,c,d);
}

inline void glex::glUniformMatrix3x4fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix3x4fv(a,b,c,d);
}

inline void glex::glUniformMatrix4x3fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix4x3fv(a,b,c,d);
}

inline void glex::glColorMaski(GLuint a, GLboolean b, GLboolean c, GLboolean d, GLboolean e) {
	m_pglex->glColorMaski(a,b,c,d,e);
}

inline void glex::glGetBooleani_v(GLenum a, GLuint b, GLboolean *c) {
	m_pglex->glGetBooleani_v(a,b,c);
}

inline void glex::glGetIntegeri_v(GLenum a, GLuint b, GLint *c) {
	m_pglex->glGetIntegeri_v(a,b,c);
}

inline void glex::glEnablei(GLenum a, GLuint b) {
	m_pglex->glEnablei(a,b);
}

inline void glex::glDisablei(GLenum a, GLuint b) {
	m_pglex->glDisablei(a,b);
}

inline GLboolean glex::glIsEnabledi(GLenum a, GLuint b) {
	return m_pglex->glIsEnabledi(a,b);
}

inline void glex::glBeginTransformFeedback(GLenum a) {
	m_pglex->glBeginTransformFeedback(a);
}

inline void glex::glEndTransformFeedback(void) {
	m_pglex->glEndTransformFeedback();
}

inline void glex::glBindBufferRange(GLenum a, GLuint b, GLuint c, GLintptr d, GLsizeiptr e) {
	m_pglex->glBindBufferRange(a,b,c,d,e);
}

inline void glex::glBindBufferBase(GLenum a, GLuint b, GLuint c) {
	m_pglex->glBindBufferBase(a,b,c);
}

inline void glex::glTransformFeedbackVaryings(GLuint a, GLsizei b, const GLchar* *c, GLenum d) {
	m_pglex->glTransformFeedbackVaryings(a,b,c,d);
}

inline void glex::glGetTransformFeedbackVarying(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLsizei *e, GLenum *f, GLchar *g) {
	m_pglex->glGetTransformFeedbackVarying(a,b,c,d,e,f,g);
}

inline void glex::glClampColor(GLenum a, GLenum b) {
	m_pglex->glClampColor(a,b);
}

inline void glex::glBeginConditionalRender(GLuint a, GLenum b) {
	m_pglex->glBeginConditionalRender(a,b);
}

inline void glex::glEndConditionalRender(void) {
	m_pglex->glEndConditionalRender();
}

inline void glex::glVertexAttribIPointer(GLuint a, GLint b, GLenum c, GLsizei d, const GLvoid *e) {
	m_pglex->glVertexAttribIPointer(a,b,c,d,e);
}

inline void glex::glGetVertexAttribIiv(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVertexAttribIiv(a,b,c);
}

inline void glex::glGetVertexAttribIuiv(GLuint a, GLenum b, GLuint *c) {
	m_pglex->glGetVertexAttribIuiv(a,b,c);
}

inline void glex::glVertexAttribI1i(GLuint a, GLint b) {
	m_pglex->glVertexAttribI1i(a,b);
}

inline void glex::glVertexAttribI2i(GLuint a, GLint b, GLint c) {
	m_pglex->glVertexAttribI2i(a,b,c);
}

inline void glex::glVertexAttribI3i(GLuint a, GLint b, GLint c, GLint d) {
	m_pglex->glVertexAttribI3i(a,b,c,d);
}

inline void glex::glVertexAttribI4i(GLuint a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glVertexAttribI4i(a,b,c,d,e);
}

inline void glex::glVertexAttribI1ui(GLuint a, GLuint b) {
	m_pglex->glVertexAttribI1ui(a,b);
}

inline void glex::glVertexAttribI2ui(GLuint a, GLuint b, GLuint c) {
	m_pglex->glVertexAttribI2ui(a,b,c);
}

inline void glex::glVertexAttribI3ui(GLuint a, GLuint b, GLuint c, GLuint d) {
	m_pglex->glVertexAttribI3ui(a,b,c,d);
}

inline void glex::glVertexAttribI4ui(GLuint a, GLuint b, GLuint c, GLuint d, GLuint e) {
	m_pglex->glVertexAttribI4ui(a,b,c,d,e);
}

inline void glex::glVertexAttribI1iv(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI1iv(a,b);
}

inline void glex::glVertexAttribI2iv(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI2iv(a,b);
}

inline void glex::glVertexAttribI3iv(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI3iv(a,b);
}

inline void glex::glVertexAttribI4iv(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI4iv(a,b);
}

inline void glex::glVertexAttribI1uiv(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI1uiv(a,b);
}

inline void glex::glVertexAttribI2uiv(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI2uiv(a,b);
}

inline void glex::glVertexAttribI3uiv(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI3uiv(a,b);
}

inline void glex::glVertexAttribI4uiv(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI4uiv(a,b);
}

inline void glex::glVertexAttribI4bv(GLuint a, const GLbyte *b) {
	m_pglex->glVertexAttribI4bv(a,b);
}

inline void glex::glVertexAttribI4sv(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttribI4sv(a,b);
}

inline void glex::glVertexAttribI4ubv(GLuint a, const GLubyte *b) {
	m_pglex->glVertexAttribI4ubv(a,b);
}

inline void glex::glVertexAttribI4usv(GLuint a, const GLushort *b) {
	m_pglex->glVertexAttribI4usv(a,b);
}

inline void glex::glGetUniformuiv(GLuint a, GLint b, GLuint *c) {
	m_pglex->glGetUniformuiv(a,b,c);
}

inline void glex::glBindFragDataLocation(GLuint a, GLuint b, const GLchar *c) {
	m_pglex->glBindFragDataLocation(a,b,c);
}

inline GLint glex::glGetFragDataLocation(GLuint a, const GLchar *b) {
	return m_pglex->glGetFragDataLocation(a,b);
}

inline void glex::glUniform1ui(GLint a, GLuint b) {
	m_pglex->glUniform1ui(a,b);
}

inline void glex::glUniform2ui(GLint a, GLuint b, GLuint c) {
	m_pglex->glUniform2ui(a,b,c);
}

inline void glex::glUniform3ui(GLint a, GLuint b, GLuint c, GLuint d) {
	m_pglex->glUniform3ui(a,b,c,d);
}

inline void glex::glUniform4ui(GLint a, GLuint b, GLuint c, GLuint d, GLuint e) {
	m_pglex->glUniform4ui(a,b,c,d,e);
}

inline void glex::glUniform1uiv(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform1uiv(a,b,c);
}

inline void glex::glUniform2uiv(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform2uiv(a,b,c);
}

inline void glex::glUniform3uiv(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform3uiv(a,b,c);
}

inline void glex::glUniform4uiv(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform4uiv(a,b,c);
}

inline void glex::glTexParameterIiv(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glTexParameterIiv(a,b,c);
}

inline void glex::glTexParameterIuiv(GLenum a, GLenum b, const GLuint *c) {
	m_pglex->glTexParameterIuiv(a,b,c);
}

inline void glex::glGetTexParameterIiv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetTexParameterIiv(a,b,c);
}

inline void glex::glGetTexParameterIuiv(GLenum a, GLenum b, GLuint *c) {
	m_pglex->glGetTexParameterIuiv(a,b,c);
}

inline void glex::glClearBufferiv(GLenum a, GLint b, const GLint *c) {
	m_pglex->glClearBufferiv(a,b,c);
}

inline void glex::glClearBufferuiv(GLenum a, GLint b, const GLuint *c) {
	m_pglex->glClearBufferuiv(a,b,c);
}

inline void glex::glClearBufferfv(GLenum a, GLint b, const GLfloat *c) {
	m_pglex->glClearBufferfv(a,b,c);
}

inline void glex::glClearBufferfi(GLenum a, GLint b, GLfloat c, GLint d) {
	m_pglex->glClearBufferfi(a,b,c,d);
}

inline const GLubyte * glex::glGetStringi(GLenum a, GLuint b) {
	return m_pglex->glGetStringi(a,b);
}

inline void glex::glDrawArraysInstanced(GLenum a, GLint b, GLsizei c, GLsizei d) {
	m_pglex->glDrawArraysInstanced(a,b,c,d);
}

inline void glex::glDrawElementsInstanced(GLenum a, GLsizei b, GLenum c, const GLvoid *d, GLsizei e) {
	m_pglex->glDrawElementsInstanced(a,b,c,d,e);
}

inline void glex::glTexBuffer(GLenum a, GLenum b, GLuint c) {
	m_pglex->glTexBuffer(a,b,c);
}

inline void glex::glPrimitiveRestartIndex(GLuint a) {
	m_pglex->glPrimitiveRestartIndex(a);
}

inline void glex::glGetInteger64i_v(GLenum a, GLuint b, GLint64 *c) {
	m_pglex->glGetInteger64i_v(a,b,c);
}

inline void glex::glGetBufferParameteri64v(GLenum a, GLenum b, GLint64 *c) {
	m_pglex->glGetBufferParameteri64v(a,b,c);
}

inline void glex::glFramebufferTexture(GLenum a, GLenum b, GLuint c, GLint d) {
	m_pglex->glFramebufferTexture(a,b,c,d);
}

inline void glex::glVertexAttribDivisor(GLuint a, GLuint b) {
	m_pglex->glVertexAttribDivisor(a,b);
}

inline void glex::glMinSampleShading(GLclampf a) {
	m_pglex->glMinSampleShading(a);
}

inline void glex::glBlendEquationi(GLuint a, GLenum b) {
	m_pglex->glBlendEquationi(a,b);
}

inline void glex::glBlendEquationSeparatei(GLuint a, GLenum b, GLenum c) {
	m_pglex->glBlendEquationSeparatei(a,b,c);
}

inline void glex::glBlendFunci(GLuint a, GLenum b, GLenum c) {
	m_pglex->glBlendFunci(a,b,c);
}

inline void glex::glBlendFuncSeparatei(GLuint a, GLenum b, GLenum c, GLenum d, GLenum e) {
	m_pglex->glBlendFuncSeparatei(a,b,c,d,e);
}

inline void glex::glActiveTextureARB(GLenum a) {
	m_pglex->glActiveTextureARB(a);
}

inline void glex::glClientActiveTextureARB(GLenum a) {
	m_pglex->glClientActiveTextureARB(a);
}

inline void glex::glMultiTexCoord1dARB(GLenum a, GLdouble b) {
	m_pglex->glMultiTexCoord1dARB(a,b);
}

inline void glex::glMultiTexCoord1dvARB(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord1dvARB(a,b);
}

inline void glex::glMultiTexCoord1fARB(GLenum a, GLfloat b) {
	m_pglex->glMultiTexCoord1fARB(a,b);
}

inline void glex::glMultiTexCoord1fvARB(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord1fvARB(a,b);
}

inline void glex::glMultiTexCoord1iARB(GLenum a, GLint b) {
	m_pglex->glMultiTexCoord1iARB(a,b);
}

inline void glex::glMultiTexCoord1ivARB(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord1ivARB(a,b);
}

inline void glex::glMultiTexCoord1sARB(GLenum a, GLshort b) {
	m_pglex->glMultiTexCoord1sARB(a,b);
}

inline void glex::glMultiTexCoord1svARB(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord1svARB(a,b);
}

inline void glex::glMultiTexCoord2dARB(GLenum a, GLdouble b, GLdouble c) {
	m_pglex->glMultiTexCoord2dARB(a,b,c);
}

inline void glex::glMultiTexCoord2dvARB(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord2dvARB(a,b);
}

inline void glex::glMultiTexCoord2fARB(GLenum a, GLfloat b, GLfloat c) {
	m_pglex->glMultiTexCoord2fARB(a,b,c);
}

inline void glex::glMultiTexCoord2fvARB(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord2fvARB(a,b);
}

inline void glex::glMultiTexCoord2iARB(GLenum a, GLint b, GLint c) {
	m_pglex->glMultiTexCoord2iARB(a,b,c);
}

inline void glex::glMultiTexCoord2ivARB(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord2ivARB(a,b);
}

inline void glex::glMultiTexCoord2sARB(GLenum a, GLshort b, GLshort c) {
	m_pglex->glMultiTexCoord2sARB(a,b,c);
}

inline void glex::glMultiTexCoord2svARB(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord2svARB(a,b);
}

inline void glex::glMultiTexCoord3dARB(GLenum a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glMultiTexCoord3dARB(a,b,c,d);
}

inline void glex::glMultiTexCoord3dvARB(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord3dvARB(a,b);
}

inline void glex::glMultiTexCoord3fARB(GLenum a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glMultiTexCoord3fARB(a,b,c,d);
}

inline void glex::glMultiTexCoord3fvARB(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord3fvARB(a,b);
}

inline void glex::glMultiTexCoord3iARB(GLenum a, GLint b, GLint c, GLint d) {
	m_pglex->glMultiTexCoord3iARB(a,b,c,d);
}

inline void glex::glMultiTexCoord3ivARB(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord3ivARB(a,b);
}

inline void glex::glMultiTexCoord3sARB(GLenum a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glMultiTexCoord3sARB(a,b,c,d);
}

inline void glex::glMultiTexCoord3svARB(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord3svARB(a,b);
}

inline void glex::glMultiTexCoord4dARB(GLenum a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glMultiTexCoord4dARB(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4dvARB(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord4dvARB(a,b);
}

inline void glex::glMultiTexCoord4fARB(GLenum a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glMultiTexCoord4fARB(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4fvARB(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord4fvARB(a,b);
}

inline void glex::glMultiTexCoord4iARB(GLenum a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glMultiTexCoord4iARB(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4ivARB(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord4ivARB(a,b);
}

inline void glex::glMultiTexCoord4sARB(GLenum a, GLshort b, GLshort c, GLshort d, GLshort e) {
	m_pglex->glMultiTexCoord4sARB(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4svARB(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord4svARB(a,b);
}

inline void glex::glLoadTransposeMatrixfARB(const GLfloat *a) {
	m_pglex->glLoadTransposeMatrixfARB(a);
}

inline void glex::glLoadTransposeMatrixdARB(const GLdouble *a) {
	m_pglex->glLoadTransposeMatrixdARB(a);
}

inline void glex::glMultTransposeMatrixfARB(const GLfloat *a) {
	m_pglex->glMultTransposeMatrixfARB(a);
}

inline void glex::glMultTransposeMatrixdARB(const GLdouble *a) {
	m_pglex->glMultTransposeMatrixdARB(a);
}

inline void glex::glSampleCoverageARB(GLclampf a, GLboolean b) {
	m_pglex->glSampleCoverageARB(a,b);
}

inline void glex::glCompressedTexImage3DARB(GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLsizei f, GLint g, GLsizei h, const GLvoid *i) {
	m_pglex->glCompressedTexImage3DARB(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCompressedTexImage2DARB(GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLint f, GLsizei g, const GLvoid *h) {
	m_pglex->glCompressedTexImage2DARB(a,b,c,d,e,f,g,h);
}

inline void glex::glCompressedTexImage1DARB(GLenum a, GLint b, GLenum c, GLsizei d, GLint e, GLsizei f, const GLvoid *g) {
	m_pglex->glCompressedTexImage1DARB(a,b,c,d,e,f,g);
}

inline void glex::glCompressedTexSubImage3DARB(GLenum a, GLint b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLsizei h, GLenum i, GLsizei j, const GLvoid *k) {
	m_pglex->glCompressedTexSubImage3DARB(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glCompressedTexSubImage2DARB(GLenum a, GLint b, GLint c, GLint d, GLsizei e, GLsizei f, GLenum g, GLsizei h, const GLvoid *i) {
	m_pglex->glCompressedTexSubImage2DARB(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCompressedTexSubImage1DARB(GLenum a, GLint b, GLint c, GLsizei d, GLenum e, GLsizei f, const GLvoid *g) {
	m_pglex->glCompressedTexSubImage1DARB(a,b,c,d,e,f,g);
}

inline void glex::glGetCompressedTexImageARB(GLenum a, GLint b, GLvoid *c) {
	m_pglex->glGetCompressedTexImageARB(a,b,c);
}

inline void glex::glPointParameterfARB(GLenum a, GLfloat b) {
	m_pglex->glPointParameterfARB(a,b);
}

inline void glex::glPointParameterfvARB(GLenum a, const GLfloat *b) {
	m_pglex->glPointParameterfvARB(a,b);
}

inline void glex::glWeightbvARB(GLint a, const GLbyte *b) {
	m_pglex->glWeightbvARB(a,b);
}

inline void glex::glWeightsvARB(GLint a, const GLshort *b) {
	m_pglex->glWeightsvARB(a,b);
}

inline void glex::glWeightivARB(GLint a, const GLint *b) {
	m_pglex->glWeightivARB(a,b);
}

inline void glex::glWeightfvARB(GLint a, const GLfloat *b) {
	m_pglex->glWeightfvARB(a,b);
}

inline void glex::glWeightdvARB(GLint a, const GLdouble *b) {
	m_pglex->glWeightdvARB(a,b);
}

inline void glex::glWeightubvARB(GLint a, const GLubyte *b) {
	m_pglex->glWeightubvARB(a,b);
}

inline void glex::glWeightusvARB(GLint a, const GLushort *b) {
	m_pglex->glWeightusvARB(a,b);
}

inline void glex::glWeightuivARB(GLint a, const GLuint *b) {
	m_pglex->glWeightuivARB(a,b);
}

inline void glex::glWeightPointerARB(GLint a, GLenum b, GLsizei c, const GLvoid *d) {
	m_pglex->glWeightPointerARB(a,b,c,d);
}

inline void glex::glVertexBlendARB(GLint a) {
	m_pglex->glVertexBlendARB(a);
}

inline void glex::glCurrentPaletteMatrixARB(GLint a) {
	m_pglex->glCurrentPaletteMatrixARB(a);
}

inline void glex::glMatrixIndexubvARB(GLint a, const GLubyte *b) {
	m_pglex->glMatrixIndexubvARB(a,b);
}

inline void glex::glMatrixIndexusvARB(GLint a, const GLushort *b) {
	m_pglex->glMatrixIndexusvARB(a,b);
}

inline void glex::glMatrixIndexuivARB(GLint a, const GLuint *b) {
	m_pglex->glMatrixIndexuivARB(a,b);
}

inline void glex::glMatrixIndexPointerARB(GLint a, GLenum b, GLsizei c, const GLvoid *d) {
	m_pglex->glMatrixIndexPointerARB(a,b,c,d);
}

inline void glex::glWindowPos2dARB(GLdouble a, GLdouble b) {
	m_pglex->glWindowPos2dARB(a,b);
}

inline void glex::glWindowPos2dvARB(const GLdouble *a) {
	m_pglex->glWindowPos2dvARB(a);
}

inline void glex::glWindowPos2fARB(GLfloat a, GLfloat b) {
	m_pglex->glWindowPos2fARB(a,b);
}

inline void glex::glWindowPos2fvARB(const GLfloat *a) {
	m_pglex->glWindowPos2fvARB(a);
}

inline void glex::glWindowPos2iARB(GLint a, GLint b) {
	m_pglex->glWindowPos2iARB(a,b);
}

inline void glex::glWindowPos2ivARB(const GLint *a) {
	m_pglex->glWindowPos2ivARB(a);
}

inline void glex::glWindowPos2sARB(GLshort a, GLshort b) {
	m_pglex->glWindowPos2sARB(a,b);
}

inline void glex::glWindowPos2svARB(const GLshort *a) {
	m_pglex->glWindowPos2svARB(a);
}

inline void glex::glWindowPos3dARB(GLdouble a, GLdouble b, GLdouble c) {
	m_pglex->glWindowPos3dARB(a,b,c);
}

inline void glex::glWindowPos3dvARB(const GLdouble *a) {
	m_pglex->glWindowPos3dvARB(a);
}

inline void glex::glWindowPos3fARB(GLfloat a, GLfloat b, GLfloat c) {
	m_pglex->glWindowPos3fARB(a,b,c);
}

inline void glex::glWindowPos3fvARB(const GLfloat *a) {
	m_pglex->glWindowPos3fvARB(a);
}

inline void glex::glWindowPos3iARB(GLint a, GLint b, GLint c) {
	m_pglex->glWindowPos3iARB(a,b,c);
}

inline void glex::glWindowPos3ivARB(const GLint *a) {
	m_pglex->glWindowPos3ivARB(a);
}

inline void glex::glWindowPos3sARB(GLshort a, GLshort b, GLshort c) {
	m_pglex->glWindowPos3sARB(a,b,c);
}

inline void glex::glWindowPos3svARB(const GLshort *a) {
	m_pglex->glWindowPos3svARB(a);
}

inline void glex::glVertexAttrib1dARB(GLuint a, GLdouble b) {
	m_pglex->glVertexAttrib1dARB(a,b);
}

inline void glex::glVertexAttrib1dvARB(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib1dvARB(a,b);
}

inline void glex::glVertexAttrib1fARB(GLuint a, GLfloat b) {
	m_pglex->glVertexAttrib1fARB(a,b);
}

inline void glex::glVertexAttrib1fvARB(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib1fvARB(a,b);
}

inline void glex::glVertexAttrib1sARB(GLuint a, GLshort b) {
	m_pglex->glVertexAttrib1sARB(a,b);
}

inline void glex::glVertexAttrib1svARB(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib1svARB(a,b);
}

inline void glex::glVertexAttrib2dARB(GLuint a, GLdouble b, GLdouble c) {
	m_pglex->glVertexAttrib2dARB(a,b,c);
}

inline void glex::glVertexAttrib2dvARB(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib2dvARB(a,b);
}

inline void glex::glVertexAttrib2fARB(GLuint a, GLfloat b, GLfloat c) {
	m_pglex->glVertexAttrib2fARB(a,b,c);
}

inline void glex::glVertexAttrib2fvARB(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib2fvARB(a,b);
}

inline void glex::glVertexAttrib2sARB(GLuint a, GLshort b, GLshort c) {
	m_pglex->glVertexAttrib2sARB(a,b,c);
}

inline void glex::glVertexAttrib2svARB(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib2svARB(a,b);
}

inline void glex::glVertexAttrib3dARB(GLuint a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glVertexAttrib3dARB(a,b,c,d);
}

inline void glex::glVertexAttrib3dvARB(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib3dvARB(a,b);
}

inline void glex::glVertexAttrib3fARB(GLuint a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glVertexAttrib3fARB(a,b,c,d);
}

inline void glex::glVertexAttrib3fvARB(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib3fvARB(a,b);
}

inline void glex::glVertexAttrib3sARB(GLuint a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glVertexAttrib3sARB(a,b,c,d);
}

inline void glex::glVertexAttrib3svARB(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib3svARB(a,b);
}

inline void glex::glVertexAttrib4NbvARB(GLuint a, const GLbyte *b) {
	m_pglex->glVertexAttrib4NbvARB(a,b);
}

inline void glex::glVertexAttrib4NivARB(GLuint a, const GLint *b) {
	m_pglex->glVertexAttrib4NivARB(a,b);
}

inline void glex::glVertexAttrib4NsvARB(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib4NsvARB(a,b);
}

inline void glex::glVertexAttrib4NubARB(GLuint a, GLubyte b, GLubyte c, GLubyte d, GLubyte e) {
	m_pglex->glVertexAttrib4NubARB(a,b,c,d,e);
}

inline void glex::glVertexAttrib4NubvARB(GLuint a, const GLubyte *b) {
	m_pglex->glVertexAttrib4NubvARB(a,b);
}

inline void glex::glVertexAttrib4NuivARB(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttrib4NuivARB(a,b);
}

inline void glex::glVertexAttrib4NusvARB(GLuint a, const GLushort *b) {
	m_pglex->glVertexAttrib4NusvARB(a,b);
}

inline void glex::glVertexAttrib4bvARB(GLuint a, const GLbyte *b) {
	m_pglex->glVertexAttrib4bvARB(a,b);
}

inline void glex::glVertexAttrib4dARB(GLuint a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glVertexAttrib4dARB(a,b,c,d,e);
}

inline void glex::glVertexAttrib4dvARB(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib4dvARB(a,b);
}

inline void glex::glVertexAttrib4fARB(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glVertexAttrib4fARB(a,b,c,d,e);
}

inline void glex::glVertexAttrib4fvARB(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib4fvARB(a,b);
}

inline void glex::glVertexAttrib4ivARB(GLuint a, const GLint *b) {
	m_pglex->glVertexAttrib4ivARB(a,b);
}

inline void glex::glVertexAttrib4sARB(GLuint a, GLshort b, GLshort c, GLshort d, GLshort e) {
	m_pglex->glVertexAttrib4sARB(a,b,c,d,e);
}

inline void glex::glVertexAttrib4svARB(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib4svARB(a,b);
}

inline void glex::glVertexAttrib4ubvARB(GLuint a, const GLubyte *b) {
	m_pglex->glVertexAttrib4ubvARB(a,b);
}

inline void glex::glVertexAttrib4uivARB(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttrib4uivARB(a,b);
}

inline void glex::glVertexAttrib4usvARB(GLuint a, const GLushort *b) {
	m_pglex->glVertexAttrib4usvARB(a,b);
}

inline void glex::glVertexAttribPointerARB(GLuint a, GLint b, GLenum c, GLboolean d, GLsizei e, const GLvoid *f) {
	m_pglex->glVertexAttribPointerARB(a,b,c,d,e,f);
}

inline void glex::glEnableVertexAttribArrayARB(GLuint a) {
	m_pglex->glEnableVertexAttribArrayARB(a);
}

inline void glex::glDisableVertexAttribArrayARB(GLuint a) {
	m_pglex->glDisableVertexAttribArrayARB(a);
}

inline void glex::glProgramStringARB(GLenum a, GLenum b, GLsizei c, const GLvoid *d) {
	m_pglex->glProgramStringARB(a,b,c,d);
}

inline void glex::glBindProgramARB(GLenum a, GLuint b) {
	m_pglex->glBindProgramARB(a,b);
}

inline void glex::glDeleteProgramsARB(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteProgramsARB(a,b);
}

inline void glex::glGenProgramsARB(GLsizei a, GLuint *b) {
	m_pglex->glGenProgramsARB(a,b);
}

inline void glex::glProgramEnvParameter4dARB(GLenum a, GLuint b, GLdouble c, GLdouble d, GLdouble e, GLdouble f) {
	m_pglex->glProgramEnvParameter4dARB(a,b,c,d,e,f);
}

inline void glex::glProgramEnvParameter4dvARB(GLenum a, GLuint b, const GLdouble *c) {
	m_pglex->glProgramEnvParameter4dvARB(a,b,c);
}

inline void glex::glProgramEnvParameter4fARB(GLenum a, GLuint b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glProgramEnvParameter4fARB(a,b,c,d,e,f);
}

inline void glex::glProgramEnvParameter4fvARB(GLenum a, GLuint b, const GLfloat *c) {
	m_pglex->glProgramEnvParameter4fvARB(a,b,c);
}

inline void glex::glProgramLocalParameter4dARB(GLenum a, GLuint b, GLdouble c, GLdouble d, GLdouble e, GLdouble f) {
	m_pglex->glProgramLocalParameter4dARB(a,b,c,d,e,f);
}

inline void glex::glProgramLocalParameter4dvARB(GLenum a, GLuint b, const GLdouble *c) {
	m_pglex->glProgramLocalParameter4dvARB(a,b,c);
}

inline void glex::glProgramLocalParameter4fARB(GLenum a, GLuint b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glProgramLocalParameter4fARB(a,b,c,d,e,f);
}

inline void glex::glProgramLocalParameter4fvARB(GLenum a, GLuint b, const GLfloat *c) {
	m_pglex->glProgramLocalParameter4fvARB(a,b,c);
}

inline void glex::glGetProgramEnvParameterdvARB(GLenum a, GLuint b, GLdouble *c) {
	m_pglex->glGetProgramEnvParameterdvARB(a,b,c);
}

inline void glex::glGetProgramEnvParameterfvARB(GLenum a, GLuint b, GLfloat *c) {
	m_pglex->glGetProgramEnvParameterfvARB(a,b,c);
}

inline void glex::glGetProgramLocalParameterdvARB(GLenum a, GLuint b, GLdouble *c) {
	m_pglex->glGetProgramLocalParameterdvARB(a,b,c);
}

inline void glex::glGetProgramLocalParameterfvARB(GLenum a, GLuint b, GLfloat *c) {
	m_pglex->glGetProgramLocalParameterfvARB(a,b,c);
}

inline void glex::glGetProgramivARB(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetProgramivARB(a,b,c);
}

inline void glex::glGetProgramStringARB(GLenum a, GLenum b, GLvoid *c) {
	m_pglex->glGetProgramStringARB(a,b,c);
}

inline void glex::glGetVertexAttribdvARB(GLuint a, GLenum b, GLdouble *c) {
	m_pglex->glGetVertexAttribdvARB(a,b,c);
}

inline void glex::glGetVertexAttribfvARB(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetVertexAttribfvARB(a,b,c);
}

inline void glex::glGetVertexAttribivARB(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVertexAttribivARB(a,b,c);
}

inline void glex::glGetVertexAttribPointervARB(GLuint a, GLenum b, GLvoid* *c) {
	m_pglex->glGetVertexAttribPointervARB(a,b,c);
}

inline GLboolean glex::glIsProgramARB(GLuint a) {
	return m_pglex->glIsProgramARB(a);
}

inline void glex::glBindBufferARB(GLenum a, GLuint b) {
	m_pglex->glBindBufferARB(a,b);
}

inline void glex::glDeleteBuffersARB(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteBuffersARB(a,b);
}

inline void glex::glGenBuffersARB(GLsizei a, GLuint *b) {
	m_pglex->glGenBuffersARB(a,b);
}

inline GLboolean glex::glIsBufferARB(GLuint a) {
	return m_pglex->glIsBufferARB(a);
}

inline void glex::glBufferDataARB(GLenum a, GLsizeiptrARB b, const GLvoid *c, GLenum d) {
	m_pglex->glBufferDataARB(a,b,c,d);
}

inline void glex::glBufferSubDataARB(GLenum a, GLintptrARB b, GLsizeiptrARB c, const GLvoid *d) {
	m_pglex->glBufferSubDataARB(a,b,c,d);
}

inline void glex::glGetBufferSubDataARB(GLenum a, GLintptrARB b, GLsizeiptrARB c, GLvoid *d) {
	m_pglex->glGetBufferSubDataARB(a,b,c,d);
}

inline GLvoid* glex::glMapBufferARB(GLenum a, GLenum b) {
	return m_pglex->glMapBufferARB(a,b);
}

inline GLboolean glex::glUnmapBufferARB(GLenum a) {
	return m_pglex->glUnmapBufferARB(a);
}

inline void glex::glGetBufferParameterivARB(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetBufferParameterivARB(a,b,c);
}

inline void glex::glGetBufferPointervARB(GLenum a, GLenum b, GLvoid* *c) {
	m_pglex->glGetBufferPointervARB(a,b,c);
}

inline void glex::glGenQueriesARB(GLsizei a, GLuint *b) {
	m_pglex->glGenQueriesARB(a,b);
}

inline void glex::glDeleteQueriesARB(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteQueriesARB(a,b);
}

inline GLboolean glex::glIsQueryARB(GLuint a) {
	return m_pglex->glIsQueryARB(a);
}

inline void glex::glBeginQueryARB(GLenum a, GLuint b) {
	m_pglex->glBeginQueryARB(a,b);
}

inline void glex::glEndQueryARB(GLenum a) {
	m_pglex->glEndQueryARB(a);
}

inline void glex::glGetQueryivARB(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetQueryivARB(a,b,c);
}

inline void glex::glGetQueryObjectivARB(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetQueryObjectivARB(a,b,c);
}

inline void glex::glGetQueryObjectuivARB(GLuint a, GLenum b, GLuint *c) {
	m_pglex->glGetQueryObjectuivARB(a,b,c);
}

inline void glex::glDeleteObjectARB(GLhandleARB a) {
	m_pglex->glDeleteObjectARB(a);
}

inline GLhandleARB glex::glGetHandleARB(GLenum a) {
	return m_pglex->glGetHandleARB(a);
}

inline void glex::glDetachObjectARB(GLhandleARB a, GLhandleARB b) {
	m_pglex->glDetachObjectARB(a,b);
}

inline GLhandleARB glex::glCreateShaderObjectARB(GLenum a) {
	return m_pglex->glCreateShaderObjectARB(a);
}

inline void glex::glShaderSourceARB(GLhandleARB a, GLsizei b, const GLcharARB* *c, const GLint *d) {
	m_pglex->glShaderSourceARB(a,b,c,d);
}

inline void glex::glCompileShaderARB(GLhandleARB a) {
	m_pglex->glCompileShaderARB(a);
}

inline GLhandleARB glex::glCreateProgramObjectARB(void) {
	return m_pglex->glCreateProgramObjectARB();
}

inline void glex::glAttachObjectARB(GLhandleARB a, GLhandleARB b) {
	m_pglex->glAttachObjectARB(a,b);
}

inline void glex::glLinkProgramARB(GLhandleARB a) {
	m_pglex->glLinkProgramARB(a);
}

inline void glex::glUseProgramObjectARB(GLhandleARB a) {
	m_pglex->glUseProgramObjectARB(a);
}

inline void glex::glValidateProgramARB(GLhandleARB a) {
	m_pglex->glValidateProgramARB(a);
}

inline void glex::glUniform1fARB(GLint a, GLfloat b) {
	m_pglex->glUniform1fARB(a,b);
}

inline void glex::glUniform2fARB(GLint a, GLfloat b, GLfloat c) {
	m_pglex->glUniform2fARB(a,b,c);
}

inline void glex::glUniform3fARB(GLint a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glUniform3fARB(a,b,c,d);
}

inline void glex::glUniform4fARB(GLint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glUniform4fARB(a,b,c,d,e);
}

inline void glex::glUniform1iARB(GLint a, GLint b) {
	m_pglex->glUniform1iARB(a,b);
}

inline void glex::glUniform2iARB(GLint a, GLint b, GLint c) {
	m_pglex->glUniform2iARB(a,b,c);
}

inline void glex::glUniform3iARB(GLint a, GLint b, GLint c, GLint d) {
	m_pglex->glUniform3iARB(a,b,c,d);
}

inline void glex::glUniform4iARB(GLint a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glUniform4iARB(a,b,c,d,e);
}

inline void glex::glUniform1fvARB(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform1fvARB(a,b,c);
}

inline void glex::glUniform2fvARB(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform2fvARB(a,b,c);
}

inline void glex::glUniform3fvARB(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform3fvARB(a,b,c);
}

inline void glex::glUniform4fvARB(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform4fvARB(a,b,c);
}

inline void glex::glUniform1ivARB(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform1ivARB(a,b,c);
}

inline void glex::glUniform2ivARB(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform2ivARB(a,b,c);
}

inline void glex::glUniform3ivARB(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform3ivARB(a,b,c);
}

inline void glex::glUniform4ivARB(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform4ivARB(a,b,c);
}

inline void glex::glUniformMatrix2fvARB(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix2fvARB(a,b,c,d);
}

inline void glex::glUniformMatrix3fvARB(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix3fvARB(a,b,c,d);
}

inline void glex::glUniformMatrix4fvARB(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix4fvARB(a,b,c,d);
}

inline void glex::glGetObjectParameterfvARB(GLhandleARB a, GLenum b, GLfloat *c) {
	m_pglex->glGetObjectParameterfvARB(a,b,c);
}

inline void glex::glGetObjectParameterivARB(GLhandleARB a, GLenum b, GLint *c) {
	m_pglex->glGetObjectParameterivARB(a,b,c);
}

inline void glex::glGetInfoLogARB(GLhandleARB a, GLsizei b, GLsizei *c, GLcharARB *d) {
	m_pglex->glGetInfoLogARB(a,b,c,d);
}

inline void glex::glGetAttachedObjectsARB(GLhandleARB a, GLsizei b, GLsizei *c, GLhandleARB *d) {
	m_pglex->glGetAttachedObjectsARB(a,b,c,d);
}

inline GLint glex::glGetUniformLocationARB(GLhandleARB a, const GLcharARB *b) {
	return m_pglex->glGetUniformLocationARB(a,b);
}

inline void glex::glGetActiveUniformARB(GLhandleARB a, GLuint b, GLsizei c, GLsizei *d, GLint *e, GLenum *f, GLcharARB *g) {
	m_pglex->glGetActiveUniformARB(a,b,c,d,e,f,g);
}

inline void glex::glGetUniformfvARB(GLhandleARB a, GLint b, GLfloat *c) {
	m_pglex->glGetUniformfvARB(a,b,c);
}

inline void glex::glGetUniformivARB(GLhandleARB a, GLint b, GLint *c) {
	m_pglex->glGetUniformivARB(a,b,c);
}

inline void glex::glGetShaderSourceARB(GLhandleARB a, GLsizei b, GLsizei *c, GLcharARB *d) {
	m_pglex->glGetShaderSourceARB(a,b,c,d);
}

inline void glex::glBindAttribLocationARB(GLhandleARB a, GLuint b, const GLcharARB *c) {
	m_pglex->glBindAttribLocationARB(a,b,c);
}

inline void glex::glGetActiveAttribARB(GLhandleARB a, GLuint b, GLsizei c, GLsizei *d, GLint *e, GLenum *f, GLcharARB *g) {
	m_pglex->glGetActiveAttribARB(a,b,c,d,e,f,g);
}

inline GLint glex::glGetAttribLocationARB(GLhandleARB a, const GLcharARB *b) {
	return m_pglex->glGetAttribLocationARB(a,b);
}

inline void glex::glDrawBuffersARB(GLsizei a, const GLenum *b) {
	m_pglex->glDrawBuffersARB(a,b);
}

inline void glex::glClampColorARB(GLenum a, GLenum b) {
	m_pglex->glClampColorARB(a,b);
}

inline void glex::glDrawArraysInstancedARB(GLenum a, GLint b, GLsizei c, GLsizei d) {
	m_pglex->glDrawArraysInstancedARB(a,b,c,d);
}

inline void glex::glDrawElementsInstancedARB(GLenum a, GLsizei b, GLenum c, const GLvoid *d, GLsizei e) {
	m_pglex->glDrawElementsInstancedARB(a,b,c,d,e);
}

inline GLboolean glex::glIsRenderbuffer(GLuint a) {
	return m_pglex->glIsRenderbuffer(a);
}

inline void glex::glBindRenderbuffer(GLenum a, GLuint b) {
	m_pglex->glBindRenderbuffer(a,b);
}

inline void glex::glDeleteRenderbuffers(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteRenderbuffers(a,b);
}

inline void glex::glGenRenderbuffers(GLsizei a, GLuint *b) {
	m_pglex->glGenRenderbuffers(a,b);
}

inline void glex::glRenderbufferStorage(GLenum a, GLenum b, GLsizei c, GLsizei d) {
	m_pglex->glRenderbufferStorage(a,b,c,d);
}

inline void glex::glGetRenderbufferParameteriv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetRenderbufferParameteriv(a,b,c);
}

inline GLboolean glex::glIsFramebuffer(GLuint a) {
	return m_pglex->glIsFramebuffer(a);
}

inline void glex::glBindFramebuffer(GLenum a, GLuint b) {
	m_pglex->glBindFramebuffer(a,b);
}

inline void glex::glDeleteFramebuffers(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteFramebuffers(a,b);
}

inline void glex::glGenFramebuffers(GLsizei a, GLuint *b) {
	m_pglex->glGenFramebuffers(a,b);
}

inline GLenum glex::glCheckFramebufferStatus(GLenum a) {
	return m_pglex->glCheckFramebufferStatus(a);
}

inline void glex::glFramebufferTexture1D(GLenum a, GLenum b, GLenum c, GLuint d, GLint e) {
	m_pglex->glFramebufferTexture1D(a,b,c,d,e);
}

inline void glex::glFramebufferTexture2D(GLenum a, GLenum b, GLenum c, GLuint d, GLint e) {
	m_pglex->glFramebufferTexture2D(a,b,c,d,e);
}

inline void glex::glFramebufferTexture3D(GLenum a, GLenum b, GLenum c, GLuint d, GLint e, GLint f) {
	m_pglex->glFramebufferTexture3D(a,b,c,d,e,f);
}

inline void glex::glFramebufferRenderbuffer(GLenum a, GLenum b, GLenum c, GLuint d) {
	m_pglex->glFramebufferRenderbuffer(a,b,c,d);
}

inline void glex::glGetFramebufferAttachmentParameteriv(GLenum a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetFramebufferAttachmentParameteriv(a,b,c,d);
}

inline void glex::glGenerateMipmap(GLenum a) {
	m_pglex->glGenerateMipmap(a);
}

inline void glex::glBlitFramebuffer(GLint a, GLint b, GLint c, GLint d, GLint e, GLint f, GLint g, GLint h, GLbitfield i, GLenum j) {
	m_pglex->glBlitFramebuffer(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glRenderbufferStorageMultisample(GLenum a, GLsizei b, GLenum c, GLsizei d, GLsizei e) {
	m_pglex->glRenderbufferStorageMultisample(a,b,c,d,e);
}

inline void glex::glFramebufferTextureLayer(GLenum a, GLenum b, GLuint c, GLint d, GLint e) {
	m_pglex->glFramebufferTextureLayer(a,b,c,d,e);
}

inline void glex::glProgramParameteriARB(GLuint a, GLenum b, GLint c) {
	m_pglex->glProgramParameteriARB(a,b,c);
}

inline void glex::glFramebufferTextureARB(GLenum a, GLenum b, GLuint c, GLint d) {
	m_pglex->glFramebufferTextureARB(a,b,c,d);
}

inline void glex::glFramebufferTextureLayerARB(GLenum a, GLenum b, GLuint c, GLint d, GLint e) {
	m_pglex->glFramebufferTextureLayerARB(a,b,c,d,e);
}

inline void glex::glFramebufferTextureFaceARB(GLenum a, GLenum b, GLuint c, GLint d, GLenum e) {
	m_pglex->glFramebufferTextureFaceARB(a,b,c,d,e);
}

inline void glex::glVertexAttribDivisorARB(GLuint a, GLuint b) {
	m_pglex->glVertexAttribDivisorARB(a,b);
}

inline GLvoid* glex::glMapBufferRange(GLenum a, GLintptr b, GLsizeiptr c, GLbitfield d) {
	return m_pglex->glMapBufferRange(a,b,c,d);
}

inline void glex::glFlushMappedBufferRange(GLenum a, GLintptr b, GLsizeiptr c) {
	m_pglex->glFlushMappedBufferRange(a,b,c);
}

inline void glex::glTexBufferARB(GLenum a, GLenum b, GLuint c) {
	m_pglex->glTexBufferARB(a,b,c);
}

inline void glex::glBindVertexArray(GLuint a) {
	m_pglex->glBindVertexArray(a);
}

inline void glex::glDeleteVertexArrays(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteVertexArrays(a,b);
}

inline void glex::glGenVertexArrays(GLsizei a, GLuint *b) {
	m_pglex->glGenVertexArrays(a,b);
}

inline GLboolean glex::glIsVertexArray(GLuint a) {
	return m_pglex->glIsVertexArray(a);
}

inline void glex::glGetUniformIndices(GLuint a, GLsizei b, const GLchar* *c, GLuint *d) {
	m_pglex->glGetUniformIndices(a,b,c,d);
}

inline void glex::glGetActiveUniformsiv(GLuint a, GLsizei b, const GLuint *c, GLenum d, GLint *e) {
	m_pglex->glGetActiveUniformsiv(a,b,c,d,e);
}

inline void glex::glGetActiveUniformName(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLchar *e) {
	m_pglex->glGetActiveUniformName(a,b,c,d,e);
}

inline GLuint glex::glGetUniformBlockIndex(GLuint a, const GLchar *b) {
	return m_pglex->glGetUniformBlockIndex(a,b);
}

inline void glex::glGetActiveUniformBlockiv(GLuint a, GLuint b, GLenum c, GLint *d) {
	m_pglex->glGetActiveUniformBlockiv(a,b,c,d);
}

inline void glex::glGetActiveUniformBlockName(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLchar *e) {
	m_pglex->glGetActiveUniformBlockName(a,b,c,d,e);
}

inline void glex::glUniformBlockBinding(GLuint a, GLuint b, GLuint c) {
	m_pglex->glUniformBlockBinding(a,b,c);
}

inline void glex::glCopyBufferSubData(GLenum a, GLenum b, GLintptr c, GLintptr d, GLsizeiptr e) {
	m_pglex->glCopyBufferSubData(a,b,c,d,e);
}

inline void glex::glDrawElementsBaseVertex(GLenum a, GLsizei b, GLenum c, const GLvoid *d, GLint e) {
	m_pglex->glDrawElementsBaseVertex(a,b,c,d,e);
}

inline void glex::glDrawRangeElementsBaseVertex(GLenum a, GLuint b, GLuint c, GLsizei d, GLenum e, const GLvoid *f, GLint g) {
	m_pglex->glDrawRangeElementsBaseVertex(a,b,c,d,e,f,g);
}

inline void glex::glDrawElementsInstancedBaseVertex(GLenum a, GLsizei b, GLenum c, const GLvoid *d, GLsizei e, GLint f) {
	m_pglex->glDrawElementsInstancedBaseVertex(a,b,c,d,e,f);
}

inline void glex::glMultiDrawElementsBaseVertex(GLenum a, const GLsizei *b, GLenum c, const GLvoid* *d, GLsizei e, const GLint *f) {
	m_pglex->glMultiDrawElementsBaseVertex(a,b,c,d,e,f);
}

inline void glex::glProvokingVertex(GLenum a) {
	m_pglex->glProvokingVertex(a);
}

inline GLsync glex::glFenceSync(GLenum a, GLbitfield b) {
	return m_pglex->glFenceSync(a,b);
}

inline GLboolean glex::glIsSync(GLsync a) {
	return m_pglex->glIsSync(a);
}

inline void glex::glDeleteSync(GLsync a) {
	m_pglex->glDeleteSync(a);
}

inline GLenum glex::glClientWaitSync(GLsync a, GLbitfield b, GLuint64 c) {
	return m_pglex->glClientWaitSync(a,b,c);
}

inline void glex::glWaitSync(GLsync a, GLbitfield b, GLuint64 c) {
	m_pglex->glWaitSync(a,b,c);
}

inline void glex::glGetInteger64v(GLenum a, GLint64 *b) {
	m_pglex->glGetInteger64v(a,b);
}

inline void glex::glGetSynciv(GLsync a, GLenum b, GLsizei c, GLsizei *d, GLint *e) {
	m_pglex->glGetSynciv(a,b,c,d,e);
}

inline void glex::glTexImage2DMultisample(GLenum a, GLsizei b, GLint c, GLsizei d, GLsizei e, GLboolean f) {
	m_pglex->glTexImage2DMultisample(a,b,c,d,e,f);
}

inline void glex::glTexImage3DMultisample(GLenum a, GLsizei b, GLint c, GLsizei d, GLsizei e, GLsizei f, GLboolean g) {
	m_pglex->glTexImage3DMultisample(a,b,c,d,e,f,g);
}

inline void glex::glGetMultisamplefv(GLenum a, GLuint b, GLfloat *c) {
	m_pglex->glGetMultisamplefv(a,b,c);
}

inline void glex::glSampleMaski(GLuint a, GLbitfield b) {
	m_pglex->glSampleMaski(a,b);
}

inline void glex::glBlendEquationiARB(GLuint a, GLenum b) {
	m_pglex->glBlendEquationiARB(a,b);
}

inline void glex::glBlendEquationSeparateiARB(GLuint a, GLenum b, GLenum c) {
	m_pglex->glBlendEquationSeparateiARB(a,b,c);
}

inline void glex::glBlendFunciARB(GLuint a, GLenum b, GLenum c) {
	m_pglex->glBlendFunciARB(a,b,c);
}

inline void glex::glBlendFuncSeparateiARB(GLuint a, GLenum b, GLenum c, GLenum d, GLenum e) {
	m_pglex->glBlendFuncSeparateiARB(a,b,c,d,e);
}

inline void glex::glMinSampleShadingARB(GLclampf a) {
	m_pglex->glMinSampleShadingARB(a);
}

inline void glex::glNamedStringARB(GLenum a, GLint b, const GLchar *c, GLint d, const GLchar *e) {
	m_pglex->glNamedStringARB(a,b,c,d,e);
}

inline void glex::glDeleteNamedStringARB(GLint a, const GLchar *b) {
	m_pglex->glDeleteNamedStringARB(a,b);
}

inline void glex::glCompileShaderIncludeARB(GLuint a, GLsizei b, const GLchar* *c, const GLint *d) {
	m_pglex->glCompileShaderIncludeARB(a,b,c,d);
}

inline GLboolean glex::glIsNamedStringARB(GLint a, const GLchar *b) {
	return m_pglex->glIsNamedStringARB(a,b);
}

inline void glex::glGetNamedStringARB(GLint a, const GLchar *b, GLsizei c, GLint *d, GLchar *e) {
	m_pglex->glGetNamedStringARB(a,b,c,d,e);
}

inline void glex::glGetNamedStringivARB(GLint a, const GLchar *b, GLenum c, GLint *d) {
	m_pglex->glGetNamedStringivARB(a,b,c,d);
}

inline void glex::glBindFragDataLocationIndexed(GLuint a, GLuint b, GLuint c, const GLchar *d) {
	m_pglex->glBindFragDataLocationIndexed(a,b,c,d);
}

inline GLint glex::glGetFragDataIndex(GLuint a, const GLchar *b) {
	return m_pglex->glGetFragDataIndex(a,b);
}

inline void glex::glGenSamplers(GLsizei a, GLuint *b) {
	m_pglex->glGenSamplers(a,b);
}

inline void glex::glDeleteSamplers(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteSamplers(a,b);
}

inline GLboolean glex::glIsSampler(GLuint a) {
	return m_pglex->glIsSampler(a);
}

inline void glex::glBindSampler(GLuint a, GLuint b) {
	m_pglex->glBindSampler(a,b);
}

inline void glex::glSamplerParameteri(GLuint a, GLenum b, GLint c) {
	m_pglex->glSamplerParameteri(a,b,c);
}

inline void glex::glSamplerParameteriv(GLuint a, GLenum b, const GLint *c) {
	m_pglex->glSamplerParameteriv(a,b,c);
}

inline void glex::glSamplerParameterf(GLuint a, GLenum b, GLfloat c) {
	m_pglex->glSamplerParameterf(a,b,c);
}

inline void glex::glSamplerParameterfv(GLuint a, GLenum b, const GLfloat *c) {
	m_pglex->glSamplerParameterfv(a,b,c);
}

inline void glex::glSamplerParameterIiv(GLuint a, GLenum b, const GLint *c) {
	m_pglex->glSamplerParameterIiv(a,b,c);
}

inline void glex::glSamplerParameterIuiv(GLuint a, GLenum b, const GLuint *c) {
	m_pglex->glSamplerParameterIuiv(a,b,c);
}

inline void glex::glGetSamplerParameteriv(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetSamplerParameteriv(a,b,c);
}

inline void glex::glGetSamplerParameterIiv(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetSamplerParameterIiv(a,b,c);
}

inline void glex::glGetSamplerParameterfv(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetSamplerParameterfv(a,b,c);
}

inline void glex::glGetSamplerParameterIuiv(GLuint a, GLenum b, GLuint *c) {
	m_pglex->glGetSamplerParameterIuiv(a,b,c);
}

inline void glex::glQueryCounter(GLuint a, GLenum b) {
	m_pglex->glQueryCounter(a,b);
}

inline void glex::glGetQueryObjecti64v(GLuint a, GLenum b, GLint64 *c) {
	m_pglex->glGetQueryObjecti64v(a,b,c);
}

inline void glex::glGetQueryObjectui64v(GLuint a, GLenum b, GLuint64 *c) {
	m_pglex->glGetQueryObjectui64v(a,b,c);
}

inline void glex::glVertexP2ui(GLenum a, GLuint b) {
	m_pglex->glVertexP2ui(a,b);
}

inline void glex::glVertexP2uiv(GLenum a, const GLuint *b) {
	m_pglex->glVertexP2uiv(a,b);
}

inline void glex::glVertexP3ui(GLenum a, GLuint b) {
	m_pglex->glVertexP3ui(a,b);
}

inline void glex::glVertexP3uiv(GLenum a, const GLuint *b) {
	m_pglex->glVertexP3uiv(a,b);
}

inline void glex::glVertexP4ui(GLenum a, GLuint b) {
	m_pglex->glVertexP4ui(a,b);
}

inline void glex::glVertexP4uiv(GLenum a, const GLuint *b) {
	m_pglex->glVertexP4uiv(a,b);
}

inline void glex::glTexCoordP1ui(GLenum a, GLuint b) {
	m_pglex->glTexCoordP1ui(a,b);
}

inline void glex::glTexCoordP1uiv(GLenum a, const GLuint *b) {
	m_pglex->glTexCoordP1uiv(a,b);
}

inline void glex::glTexCoordP2ui(GLenum a, GLuint b) {
	m_pglex->glTexCoordP2ui(a,b);
}

inline void glex::glTexCoordP2uiv(GLenum a, const GLuint *b) {
	m_pglex->glTexCoordP2uiv(a,b);
}

inline void glex::glTexCoordP3ui(GLenum a, GLuint b) {
	m_pglex->glTexCoordP3ui(a,b);
}

inline void glex::glTexCoordP3uiv(GLenum a, const GLuint *b) {
	m_pglex->glTexCoordP3uiv(a,b);
}

inline void glex::glTexCoordP4ui(GLenum a, GLuint b) {
	m_pglex->glTexCoordP4ui(a,b);
}

inline void glex::glTexCoordP4uiv(GLenum a, const GLuint *b) {
	m_pglex->glTexCoordP4uiv(a,b);
}

inline void glex::glMultiTexCoordP1ui(GLenum a, GLenum b, GLuint c) {
	m_pglex->glMultiTexCoordP1ui(a,b,c);
}

inline void glex::glMultiTexCoordP1uiv(GLenum a, GLenum b, const GLuint *c) {
	m_pglex->glMultiTexCoordP1uiv(a,b,c);
}

inline void glex::glMultiTexCoordP2ui(GLenum a, GLenum b, GLuint c) {
	m_pglex->glMultiTexCoordP2ui(a,b,c);
}

inline void glex::glMultiTexCoordP2uiv(GLenum a, GLenum b, const GLuint *c) {
	m_pglex->glMultiTexCoordP2uiv(a,b,c);
}

inline void glex::glMultiTexCoordP3ui(GLenum a, GLenum b, GLuint c) {
	m_pglex->glMultiTexCoordP3ui(a,b,c);
}

inline void glex::glMultiTexCoordP3uiv(GLenum a, GLenum b, const GLuint *c) {
	m_pglex->glMultiTexCoordP3uiv(a,b,c);
}

inline void glex::glMultiTexCoordP4ui(GLenum a, GLenum b, GLuint c) {
	m_pglex->glMultiTexCoordP4ui(a,b,c);
}

inline void glex::glMultiTexCoordP4uiv(GLenum a, GLenum b, const GLuint *c) {
	m_pglex->glMultiTexCoordP4uiv(a,b,c);
}

inline void glex::glNormalP3ui(GLenum a, GLuint b) {
	m_pglex->glNormalP3ui(a,b);
}

inline void glex::glNormalP3uiv(GLenum a, const GLuint *b) {
	m_pglex->glNormalP3uiv(a,b);
}

inline void glex::glColorP3ui(GLenum a, GLuint b) {
	m_pglex->glColorP3ui(a,b);
}

inline void glex::glColorP3uiv(GLenum a, const GLuint *b) {
	m_pglex->glColorP3uiv(a,b);
}

inline void glex::glColorP4ui(GLenum a, GLuint b) {
	m_pglex->glColorP4ui(a,b);
}

inline void glex::glColorP4uiv(GLenum a, const GLuint *b) {
	m_pglex->glColorP4uiv(a,b);
}

inline void glex::glSecondaryColorP3ui(GLenum a, GLuint b) {
	m_pglex->glSecondaryColorP3ui(a,b);
}

inline void glex::glSecondaryColorP3uiv(GLenum a, const GLuint *b) {
	m_pglex->glSecondaryColorP3uiv(a,b);
}

inline void glex::glVertexAttribP1ui(GLuint a, GLenum b, GLboolean c, GLuint d) {
	m_pglex->glVertexAttribP1ui(a,b,c,d);
}

inline void glex::glVertexAttribP1uiv(GLuint a, GLenum b, GLboolean c, const GLuint *d) {
	m_pglex->glVertexAttribP1uiv(a,b,c,d);
}

inline void glex::glVertexAttribP2ui(GLuint a, GLenum b, GLboolean c, GLuint d) {
	m_pglex->glVertexAttribP2ui(a,b,c,d);
}

inline void glex::glVertexAttribP2uiv(GLuint a, GLenum b, GLboolean c, const GLuint *d) {
	m_pglex->glVertexAttribP2uiv(a,b,c,d);
}

inline void glex::glVertexAttribP3ui(GLuint a, GLenum b, GLboolean c, GLuint d) {
	m_pglex->glVertexAttribP3ui(a,b,c,d);
}

inline void glex::glVertexAttribP3uiv(GLuint a, GLenum b, GLboolean c, const GLuint *d) {
	m_pglex->glVertexAttribP3uiv(a,b,c,d);
}

inline void glex::glVertexAttribP4ui(GLuint a, GLenum b, GLboolean c, GLuint d) {
	m_pglex->glVertexAttribP4ui(a,b,c,d);
}

inline void glex::glVertexAttribP4uiv(GLuint a, GLenum b, GLboolean c, const GLuint *d) {
	m_pglex->glVertexAttribP4uiv(a,b,c,d);
}

inline void glex::glDrawArraysIndirect(GLenum a, const GLvoid *b) {
	m_pglex->glDrawArraysIndirect(a,b);
}

inline void glex::glDrawElementsIndirect(GLenum a, GLenum b, const GLvoid *c) {
	m_pglex->glDrawElementsIndirect(a,b,c);
}

inline void glex::glUniform1d(GLint a, GLdouble b) {
	m_pglex->glUniform1d(a,b);
}

inline void glex::glUniform2d(GLint a, GLdouble b, GLdouble c) {
	m_pglex->glUniform2d(a,b,c);
}

inline void glex::glUniform3d(GLint a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glUniform3d(a,b,c,d);
}

inline void glex::glUniform4d(GLint a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glUniform4d(a,b,c,d,e);
}

inline void glex::glUniform1dv(GLint a, GLsizei b, const GLdouble *c) {
	m_pglex->glUniform1dv(a,b,c);
}

inline void glex::glUniform2dv(GLint a, GLsizei b, const GLdouble *c) {
	m_pglex->glUniform2dv(a,b,c);
}

inline void glex::glUniform3dv(GLint a, GLsizei b, const GLdouble *c) {
	m_pglex->glUniform3dv(a,b,c);
}

inline void glex::glUniform4dv(GLint a, GLsizei b, const GLdouble *c) {
	m_pglex->glUniform4dv(a,b,c);
}

inline void glex::glUniformMatrix2dv(GLint a, GLsizei b, GLboolean c, const GLdouble *d) {
	m_pglex->glUniformMatrix2dv(a,b,c,d);
}

inline void glex::glUniformMatrix3dv(GLint a, GLsizei b, GLboolean c, const GLdouble *d) {
	m_pglex->glUniformMatrix3dv(a,b,c,d);
}

inline void glex::glUniformMatrix4dv(GLint a, GLsizei b, GLboolean c, const GLdouble *d) {
	m_pglex->glUniformMatrix4dv(a,b,c,d);
}

inline void glex::glUniformMatrix2x3dv(GLint a, GLsizei b, GLboolean c, const GLdouble *d) {
	m_pglex->glUniformMatrix2x3dv(a,b,c,d);
}

inline void glex::glUniformMatrix2x4dv(GLint a, GLsizei b, GLboolean c, const GLdouble *d) {
	m_pglex->glUniformMatrix2x4dv(a,b,c,d);
}

inline void glex::glUniformMatrix3x2dv(GLint a, GLsizei b, GLboolean c, const GLdouble *d) {
	m_pglex->glUniformMatrix3x2dv(a,b,c,d);
}

inline void glex::glUniformMatrix3x4dv(GLint a, GLsizei b, GLboolean c, const GLdouble *d) {
	m_pglex->glUniformMatrix3x4dv(a,b,c,d);
}

inline void glex::glUniformMatrix4x2dv(GLint a, GLsizei b, GLboolean c, const GLdouble *d) {
	m_pglex->glUniformMatrix4x2dv(a,b,c,d);
}

inline void glex::glUniformMatrix4x3dv(GLint a, GLsizei b, GLboolean c, const GLdouble *d) {
	m_pglex->glUniformMatrix4x3dv(a,b,c,d);
}

inline void glex::glGetUniformdv(GLuint a, GLint b, GLdouble *c) {
	m_pglex->glGetUniformdv(a,b,c);
}

inline GLint glex::glGetSubroutineUniformLocation(GLuint a, GLenum b, const GLchar *c) {
	return m_pglex->glGetSubroutineUniformLocation(a,b,c);
}

inline GLuint glex::glGetSubroutineIndex(GLuint a, GLenum b, const GLchar *c) {
	return m_pglex->glGetSubroutineIndex(a,b,c);
}

inline void glex::glGetActiveSubroutineUniformiv(GLuint a, GLenum b, GLuint c, GLenum d, GLint *e) {
	m_pglex->glGetActiveSubroutineUniformiv(a,b,c,d,e);
}

inline void glex::glGetActiveSubroutineUniformName(GLuint a, GLenum b, GLuint c, GLsizei d, GLsizei *e, GLchar *f) {
	m_pglex->glGetActiveSubroutineUniformName(a,b,c,d,e,f);
}

inline void glex::glGetActiveSubroutineName(GLuint a, GLenum b, GLuint c, GLsizei d, GLsizei *e, GLchar *f) {
	m_pglex->glGetActiveSubroutineName(a,b,c,d,e,f);
}

inline void glex::glUniformSubroutinesuiv(GLenum a, GLsizei b, const GLuint *c) {
	m_pglex->glUniformSubroutinesuiv(a,b,c);
}

inline void glex::glGetUniformSubroutineuiv(GLenum a, GLint b, GLuint *c) {
	m_pglex->glGetUniformSubroutineuiv(a,b,c);
}

inline void glex::glGetProgramStageiv(GLuint a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetProgramStageiv(a,b,c,d);
}

inline void glex::glPatchParameteri(GLenum a, GLint b) {
	m_pglex->glPatchParameteri(a,b);
}

inline void glex::glPatchParameterfv(GLenum a, const GLfloat *b) {
	m_pglex->glPatchParameterfv(a,b);
}

inline void glex::glBindTransformFeedback(GLenum a, GLuint b) {
	m_pglex->glBindTransformFeedback(a,b);
}

inline void glex::glDeleteTransformFeedbacks(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteTransformFeedbacks(a,b);
}

inline void glex::glGenTransformFeedbacks(GLsizei a, GLuint *b) {
	m_pglex->glGenTransformFeedbacks(a,b);
}

inline GLboolean glex::glIsTransformFeedback(GLuint a) {
	return m_pglex->glIsTransformFeedback(a);
}

inline void glex::glPauseTransformFeedback(void) {
	m_pglex->glPauseTransformFeedback();
}

inline void glex::glResumeTransformFeedback(void) {
	m_pglex->glResumeTransformFeedback();
}

inline void glex::glDrawTransformFeedback(GLenum a, GLuint b) {
	m_pglex->glDrawTransformFeedback(a,b);
}

inline void glex::glDrawTransformFeedbackStream(GLenum a, GLuint b, GLuint c) {
	m_pglex->glDrawTransformFeedbackStream(a,b,c);
}

inline void glex::glBeginQueryIndexed(GLenum a, GLuint b, GLuint c) {
	m_pglex->glBeginQueryIndexed(a,b,c);
}

inline void glex::glEndQueryIndexed(GLenum a, GLuint b) {
	m_pglex->glEndQueryIndexed(a,b);
}

inline void glex::glGetQueryIndexediv(GLenum a, GLuint b, GLenum c, GLint *d) {
	m_pglex->glGetQueryIndexediv(a,b,c,d);
}

inline void glex::glReleaseShaderCompiler(void) {
	m_pglex->glReleaseShaderCompiler();
}

inline void glex::glShaderBinary(GLsizei a, const GLuint *b, GLenum c, const GLvoid *d, GLsizei e) {
	m_pglex->glShaderBinary(a,b,c,d,e);
}

inline void glex::glGetShaderPrecisionFormat(GLenum a, GLenum b, GLint *c, GLint *d) {
	m_pglex->glGetShaderPrecisionFormat(a,b,c,d);
}

inline void glex::glDepthRangef(GLclampf a, GLclampf b) {
	m_pglex->glDepthRangef(a,b);
}

inline void glex::glClearDepthf(GLclampf a) {
	m_pglex->glClearDepthf(a);
}

inline void glex::glGetProgramBinary(GLuint a, GLsizei b, GLsizei *c, GLenum *d, GLvoid *e) {
	m_pglex->glGetProgramBinary(a,b,c,d,e);
}

inline void glex::glProgramBinary(GLuint a, GLenum b, const GLvoid *c, GLsizei d) {
	m_pglex->glProgramBinary(a,b,c,d);
}

inline void glex::glProgramParameteri(GLuint a, GLenum b, GLint c) {
	m_pglex->glProgramParameteri(a,b,c);
}

inline void glex::glUseProgramStages(GLuint a, GLbitfield b, GLuint c) {
	m_pglex->glUseProgramStages(a,b,c);
}

inline void glex::glActiveShaderProgram(GLuint a, GLuint b) {
	m_pglex->glActiveShaderProgram(a,b);
}

inline GLuint glex::glCreateShaderProgramv(GLenum a, GLsizei b, const GLchar* *c) {
	return m_pglex->glCreateShaderProgramv(a,b,c);
}

inline void glex::glBindProgramPipeline(GLuint a) {
	m_pglex->glBindProgramPipeline(a);
}

inline void glex::glDeleteProgramPipelines(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteProgramPipelines(a,b);
}

inline void glex::glGenProgramPipelines(GLsizei a, GLuint *b) {
	m_pglex->glGenProgramPipelines(a,b);
}

inline GLboolean glex::glIsProgramPipeline(GLuint a) {
	return m_pglex->glIsProgramPipeline(a);
}

inline void glex::glGetProgramPipelineiv(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetProgramPipelineiv(a,b,c);
}

inline void glex::glProgramUniform1i(GLuint a, GLint b, GLint c) {
	m_pglex->glProgramUniform1i(a,b,c);
}

inline void glex::glProgramUniform1iv(GLuint a, GLint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramUniform1iv(a,b,c,d);
}

inline void glex::glProgramUniform1f(GLuint a, GLint b, GLfloat c) {
	m_pglex->glProgramUniform1f(a,b,c);
}

inline void glex::glProgramUniform1fv(GLuint a, GLint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramUniform1fv(a,b,c,d);
}

inline void glex::glProgramUniform1d(GLuint a, GLint b, GLdouble c) {
	m_pglex->glProgramUniform1d(a,b,c);
}

inline void glex::glProgramUniform1dv(GLuint a, GLint b, GLsizei c, const GLdouble *d) {
	m_pglex->glProgramUniform1dv(a,b,c,d);
}

inline void glex::glProgramUniform1ui(GLuint a, GLint b, GLuint c) {
	m_pglex->glProgramUniform1ui(a,b,c);
}

inline void glex::glProgramUniform1uiv(GLuint a, GLint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramUniform1uiv(a,b,c,d);
}

inline void glex::glProgramUniform2i(GLuint a, GLint b, GLint c, GLint d) {
	m_pglex->glProgramUniform2i(a,b,c,d);
}

inline void glex::glProgramUniform2iv(GLuint a, GLint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramUniform2iv(a,b,c,d);
}

inline void glex::glProgramUniform2f(GLuint a, GLint b, GLfloat c, GLfloat d) {
	m_pglex->glProgramUniform2f(a,b,c,d);
}

inline void glex::glProgramUniform2fv(GLuint a, GLint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramUniform2fv(a,b,c,d);
}

inline void glex::glProgramUniform2d(GLuint a, GLint b, GLdouble c, GLdouble d) {
	m_pglex->glProgramUniform2d(a,b,c,d);
}

inline void glex::glProgramUniform2dv(GLuint a, GLint b, GLsizei c, const GLdouble *d) {
	m_pglex->glProgramUniform2dv(a,b,c,d);
}

inline void glex::glProgramUniform2ui(GLuint a, GLint b, GLuint c, GLuint d) {
	m_pglex->glProgramUniform2ui(a,b,c,d);
}

inline void glex::glProgramUniform2uiv(GLuint a, GLint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramUniform2uiv(a,b,c,d);
}

inline void glex::glProgramUniform3i(GLuint a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glProgramUniform3i(a,b,c,d,e);
}

inline void glex::glProgramUniform3iv(GLuint a, GLint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramUniform3iv(a,b,c,d);
}

inline void glex::glProgramUniform3f(GLuint a, GLint b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glProgramUniform3f(a,b,c,d,e);
}

inline void glex::glProgramUniform3fv(GLuint a, GLint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramUniform3fv(a,b,c,d);
}

inline void glex::glProgramUniform3d(GLuint a, GLint b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glProgramUniform3d(a,b,c,d,e);
}

inline void glex::glProgramUniform3dv(GLuint a, GLint b, GLsizei c, const GLdouble *d) {
	m_pglex->glProgramUniform3dv(a,b,c,d);
}

inline void glex::glProgramUniform3ui(GLuint a, GLint b, GLuint c, GLuint d, GLuint e) {
	m_pglex->glProgramUniform3ui(a,b,c,d,e);
}

inline void glex::glProgramUniform3uiv(GLuint a, GLint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramUniform3uiv(a,b,c,d);
}

inline void glex::glProgramUniform4i(GLuint a, GLint b, GLint c, GLint d, GLint e, GLint f) {
	m_pglex->glProgramUniform4i(a,b,c,d,e,f);
}

inline void glex::glProgramUniform4iv(GLuint a, GLint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramUniform4iv(a,b,c,d);
}

inline void glex::glProgramUniform4f(GLuint a, GLint b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glProgramUniform4f(a,b,c,d,e,f);
}

inline void glex::glProgramUniform4fv(GLuint a, GLint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramUniform4fv(a,b,c,d);
}

inline void glex::glProgramUniform4d(GLuint a, GLint b, GLdouble c, GLdouble d, GLdouble e, GLdouble f) {
	m_pglex->glProgramUniform4d(a,b,c,d,e,f);
}

inline void glex::glProgramUniform4dv(GLuint a, GLint b, GLsizei c, const GLdouble *d) {
	m_pglex->glProgramUniform4dv(a,b,c,d);
}

inline void glex::glProgramUniform4ui(GLuint a, GLint b, GLuint c, GLuint d, GLuint e, GLuint f) {
	m_pglex->glProgramUniform4ui(a,b,c,d,e,f);
}

inline void glex::glProgramUniform4uiv(GLuint a, GLint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramUniform4uiv(a,b,c,d);
}

inline void glex::glProgramUniformMatrix2fv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix2fv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3fv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix3fv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4fv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix4fv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix2dv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix2dv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3dv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix3dv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4dv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix4dv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix2x3fv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix2x3fv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3x2fv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix3x2fv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix2x4fv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix2x4fv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4x2fv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix4x2fv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3x4fv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix3x4fv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4x3fv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix4x3fv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix2x3dv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix2x3dv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3x2dv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix3x2dv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix2x4dv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix2x4dv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4x2dv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix4x2dv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3x4dv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix3x4dv(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4x3dv(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix4x3dv(a,b,c,d,e);
}

inline void glex::glValidateProgramPipeline(GLuint a) {
	m_pglex->glValidateProgramPipeline(a);
}

inline void glex::glGetProgramPipelineInfoLog(GLuint a, GLsizei b, GLsizei *c, GLchar *d) {
	m_pglex->glGetProgramPipelineInfoLog(a,b,c,d);
}

inline void glex::glVertexAttribL1d(GLuint a, GLdouble b) {
	m_pglex->glVertexAttribL1d(a,b);
}

inline void glex::glVertexAttribL2d(GLuint a, GLdouble b, GLdouble c) {
	m_pglex->glVertexAttribL2d(a,b,c);
}

inline void glex::glVertexAttribL3d(GLuint a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glVertexAttribL3d(a,b,c,d);
}

inline void glex::glVertexAttribL4d(GLuint a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glVertexAttribL4d(a,b,c,d,e);
}

inline void glex::glVertexAttribL1dv(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttribL1dv(a,b);
}

inline void glex::glVertexAttribL2dv(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttribL2dv(a,b);
}

inline void glex::glVertexAttribL3dv(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttribL3dv(a,b);
}

inline void glex::glVertexAttribL4dv(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttribL4dv(a,b);
}

inline void glex::glVertexAttribLPointer(GLuint a, GLint b, GLenum c, GLsizei d, const GLvoid *e) {
	m_pglex->glVertexAttribLPointer(a,b,c,d,e);
}

inline void glex::glGetVertexAttribLdv(GLuint a, GLenum b, GLdouble *c) {
	m_pglex->glGetVertexAttribLdv(a,b,c);
}

inline void glex::glViewportArrayv(GLuint a, GLsizei b, const GLfloat *c) {
	m_pglex->glViewportArrayv(a,b,c);
}

inline void glex::glViewportIndexedf(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glViewportIndexedf(a,b,c,d,e);
}

inline void glex::glViewportIndexedfv(GLuint a, const GLfloat *b) {
	m_pglex->glViewportIndexedfv(a,b);
}

inline void glex::glScissorArrayv(GLuint a, GLsizei b, const GLint *c) {
	m_pglex->glScissorArrayv(a,b,c);
}

inline void glex::glScissorIndexed(GLuint a, GLint b, GLint c, GLsizei d, GLsizei e) {
	m_pglex->glScissorIndexed(a,b,c,d,e);
}

inline void glex::glScissorIndexedv(GLuint a, const GLint *b) {
	m_pglex->glScissorIndexedv(a,b);
}

inline void glex::glDepthRangeArrayv(GLuint a, GLsizei b, const GLclampd *c) {
	m_pglex->glDepthRangeArrayv(a,b,c);
}

inline void glex::glDepthRangeIndexed(GLuint a, GLclampd b, GLclampd c) {
	m_pglex->glDepthRangeIndexed(a,b,c);
}

inline void glex::glGetFloati_v(GLenum a, GLuint b, GLfloat *c) {
	m_pglex->glGetFloati_v(a,b,c);
}

inline void glex::glGetDoublei_v(GLenum a, GLuint b, GLdouble *c) {
	m_pglex->glGetDoublei_v(a,b,c);
}

inline GLsync glex::glCreateSyncFromCLeventARB(struct _cl_context * a, struct _cl_event * b, GLbitfield c) {
	return m_pglex->glCreateSyncFromCLeventARB(a,b,c);
}

inline void glex::glDebugMessageControlARB(GLenum a, GLenum b, GLenum c, GLsizei d, const GLuint *e, GLboolean f) {
	m_pglex->glDebugMessageControlARB(a,b,c,d,e,f);
}

inline void glex::glDebugMessageInsertARB(GLenum a, GLenum b, GLuint c, GLenum d, GLsizei e, const GLchar *f) {
	m_pglex->glDebugMessageInsertARB(a,b,c,d,e,f);
}

inline void glex::glDebugMessageCallbackARB(GLDEBUGPROCARB a, const GLvoid *b) {
	m_pglex->glDebugMessageCallbackARB(a,b);
}

inline GLuint glex::glGetDebugMessageLogARB(GLuint a, GLsizei b, GLenum *c, GLenum *d, GLuint *e, GLenum *f, GLsizei *g, GLchar *h) {
	return m_pglex->glGetDebugMessageLogARB(a,b,c,d,e,f,g,h);
}

inline GLenum glex::glGetGraphicsResetStatusARB(void) {
	return m_pglex->glGetGraphicsResetStatusARB();
}

inline void glex::glGetnMapdvARB(GLenum a, GLenum b, GLsizei c, GLdouble *d) {
	m_pglex->glGetnMapdvARB(a,b,c,d);
}

inline void glex::glGetnMapfvARB(GLenum a, GLenum b, GLsizei c, GLfloat *d) {
	m_pglex->glGetnMapfvARB(a,b,c,d);
}

inline void glex::glGetnMapivARB(GLenum a, GLenum b, GLsizei c, GLint *d) {
	m_pglex->glGetnMapivARB(a,b,c,d);
}

inline void glex::glGetnPixelMapfvARB(GLenum a, GLsizei b, GLfloat *c) {
	m_pglex->glGetnPixelMapfvARB(a,b,c);
}

inline void glex::glGetnPixelMapuivARB(GLenum a, GLsizei b, GLuint *c) {
	m_pglex->glGetnPixelMapuivARB(a,b,c);
}

inline void glex::glGetnPixelMapusvARB(GLenum a, GLsizei b, GLushort *c) {
	m_pglex->glGetnPixelMapusvARB(a,b,c);
}

inline void glex::glGetnPolygonStippleARB(GLsizei a, GLubyte *b) {
	m_pglex->glGetnPolygonStippleARB(a,b);
}

inline void glex::glGetnColorTableARB(GLenum a, GLenum b, GLenum c, GLsizei d, GLvoid *e) {
	m_pglex->glGetnColorTableARB(a,b,c,d,e);
}

inline void glex::glGetnConvolutionFilterARB(GLenum a, GLenum b, GLenum c, GLsizei d, GLvoid *e) {
	m_pglex->glGetnConvolutionFilterARB(a,b,c,d,e);
}

inline void glex::glGetnSeparableFilterARB(GLenum a, GLenum b, GLenum c, GLsizei d, GLvoid *e, GLsizei f, GLvoid *g, GLvoid *h) {
	m_pglex->glGetnSeparableFilterARB(a,b,c,d,e,f,g,h);
}

inline void glex::glGetnHistogramARB(GLenum a, GLboolean b, GLenum c, GLenum d, GLsizei e, GLvoid *f) {
	m_pglex->glGetnHistogramARB(a,b,c,d,e,f);
}

inline void glex::glGetnMinmaxARB(GLenum a, GLboolean b, GLenum c, GLenum d, GLsizei e, GLvoid *f) {
	m_pglex->glGetnMinmaxARB(a,b,c,d,e,f);
}

inline void glex::glGetnTexImageARB(GLenum a, GLint b, GLenum c, GLenum d, GLsizei e, GLvoid *f) {
	m_pglex->glGetnTexImageARB(a,b,c,d,e,f);
}

inline void glex::glReadnPixelsARB(GLint a, GLint b, GLsizei c, GLsizei d, GLenum e, GLenum f, GLsizei g, GLvoid *h) {
	m_pglex->glReadnPixelsARB(a,b,c,d,e,f,g,h);
}

inline void glex::glGetnCompressedTexImageARB(GLenum a, GLint b, GLsizei c, GLvoid *d) {
	m_pglex->glGetnCompressedTexImageARB(a,b,c,d);
}

inline void glex::glGetnUniformfvARB(GLuint a, GLint b, GLsizei c, GLfloat *d) {
	m_pglex->glGetnUniformfvARB(a,b,c,d);
}

inline void glex::glGetnUniformivARB(GLuint a, GLint b, GLsizei c, GLint *d) {
	m_pglex->glGetnUniformivARB(a,b,c,d);
}

inline void glex::glGetnUniformuivARB(GLuint a, GLint b, GLsizei c, GLuint *d) {
	m_pglex->glGetnUniformuivARB(a,b,c,d);
}

inline void glex::glGetnUniformdvARB(GLuint a, GLint b, GLsizei c, GLdouble *d) {
	m_pglex->glGetnUniformdvARB(a,b,c,d);
}

inline void glex::glDrawArraysInstancedBaseInstance(GLenum a, GLint b, GLsizei c, GLsizei d, GLuint e) {
	m_pglex->glDrawArraysInstancedBaseInstance(a,b,c,d,e);
}

inline void glex::glDrawElementsInstancedBaseInstance(GLenum a, GLsizei b, GLenum c, const void *d, GLsizei e, GLuint f) {
	m_pglex->glDrawElementsInstancedBaseInstance(a,b,c,d,e,f);
}

inline void glex::glDrawElementsInstancedBaseVertexBaseInstance(GLenum a, GLsizei b, GLenum c, const void *d, GLsizei e, GLint f, GLuint g) {
	m_pglex->glDrawElementsInstancedBaseVertexBaseInstance(a,b,c,d,e,f,g);
}

inline void glex::glDrawTransformFeedbackInstanced(GLenum a, GLuint b, GLsizei c) {
	m_pglex->glDrawTransformFeedbackInstanced(a,b,c);
}

inline void glex::glDrawTransformFeedbackStreamInstanced(GLenum a, GLuint b, GLuint c, GLsizei d) {
	m_pglex->glDrawTransformFeedbackStreamInstanced(a,b,c,d);
}

inline void glex::glGetInternalformativ(GLenum a, GLenum b, GLenum c, GLsizei d, GLint *e) {
	m_pglex->glGetInternalformativ(a,b,c,d,e);
}

inline void glex::glGetActiveAtomicCounterBufferiv(GLuint a, GLuint b, GLenum c, GLint *d) {
	m_pglex->glGetActiveAtomicCounterBufferiv(a,b,c,d);
}

inline void glex::glBindImageTexture(GLuint a, GLuint b, GLint c, GLboolean d, GLint e, GLenum f, GLenum g) {
	m_pglex->glBindImageTexture(a,b,c,d,e,f,g);
}

inline void glex::glMemoryBarrier(GLbitfield a) {
	m_pglex->glMemoryBarrier(a);
}

inline void glex::glTexStorage1D(GLenum a, GLsizei b, GLenum c, GLsizei d) {
	m_pglex->glTexStorage1D(a,b,c,d);
}

inline void glex::glTexStorage2D(GLenum a, GLsizei b, GLenum c, GLsizei d, GLsizei e) {
	m_pglex->glTexStorage2D(a,b,c,d,e);
}

inline void glex::glTexStorage3D(GLenum a, GLsizei b, GLenum c, GLsizei d, GLsizei e, GLsizei f) {
	m_pglex->glTexStorage3D(a,b,c,d,e,f);
}

inline void glex::glTextureStorage1DEXT(GLuint a, GLenum b, GLsizei c, GLenum d, GLsizei e) {
	m_pglex->glTextureStorage1DEXT(a,b,c,d,e);
}

inline void glex::glTextureStorage2DEXT(GLuint a, GLenum b, GLsizei c, GLenum d, GLsizei e, GLsizei f) {
	m_pglex->glTextureStorage2DEXT(a,b,c,d,e,f);
}

inline void glex::glTextureStorage3DEXT(GLuint a, GLenum b, GLsizei c, GLenum d, GLsizei e, GLsizei f, GLsizei g) {
	m_pglex->glTextureStorage3DEXT(a,b,c,d,e,f,g);
}

inline void glex::glBlendColorEXT(GLclampf a, GLclampf b, GLclampf c, GLclampf d) {
	m_pglex->glBlendColorEXT(a,b,c,d);
}

inline void glex::glPolygonOffsetEXT(GLfloat a, GLfloat b) {
	m_pglex->glPolygonOffsetEXT(a,b);
}

inline void glex::glTexImage3DEXT(GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLsizei f, GLint g, GLenum h, GLenum i, const GLvoid *j) {
	m_pglex->glTexImage3DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glTexSubImage3DEXT(GLenum a, GLint b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLsizei h, GLenum i, GLenum j, const GLvoid *k) {
	m_pglex->glTexSubImage3DEXT(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glGetTexFilterFuncSGIS(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetTexFilterFuncSGIS(a,b,c);
}

inline void glex::glTexFilterFuncSGIS(GLenum a, GLenum b, GLsizei c, const GLfloat *d) {
	m_pglex->glTexFilterFuncSGIS(a,b,c,d);
}

inline void glex::glTexSubImage1DEXT(GLenum a, GLint b, GLint c, GLsizei d, GLenum e, GLenum f, const GLvoid *g) {
	m_pglex->glTexSubImage1DEXT(a,b,c,d,e,f,g);
}

inline void glex::glTexSubImage2DEXT(GLenum a, GLint b, GLint c, GLint d, GLsizei e, GLsizei f, GLenum g, GLenum h, const GLvoid *i) {
	m_pglex->glTexSubImage2DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCopyTexImage1DEXT(GLenum a, GLint b, GLenum c, GLint d, GLint e, GLsizei f, GLint g) {
	m_pglex->glCopyTexImage1DEXT(a,b,c,d,e,f,g);
}

inline void glex::glCopyTexImage2DEXT(GLenum a, GLint b, GLenum c, GLint d, GLint e, GLsizei f, GLsizei g, GLint h) {
	m_pglex->glCopyTexImage2DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glCopyTexSubImage1DEXT(GLenum a, GLint b, GLint c, GLint d, GLint e, GLsizei f) {
	m_pglex->glCopyTexSubImage1DEXT(a,b,c,d,e,f);
}

inline void glex::glCopyTexSubImage2DEXT(GLenum a, GLint b, GLint c, GLint d, GLint e, GLint f, GLsizei g, GLsizei h) {
	m_pglex->glCopyTexSubImage2DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glCopyTexSubImage3DEXT(GLenum a, GLint b, GLint c, GLint d, GLint e, GLint f, GLint g, GLsizei h, GLsizei i) {
	m_pglex->glCopyTexSubImage3DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glGetHistogramEXT(GLenum a, GLboolean b, GLenum c, GLenum d, GLvoid *e) {
	m_pglex->glGetHistogramEXT(a,b,c,d,e);
}

inline void glex::glGetHistogramParameterfvEXT(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetHistogramParameterfvEXT(a,b,c);
}

inline void glex::glGetHistogramParameterivEXT(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetHistogramParameterivEXT(a,b,c);
}

inline void glex::glGetMinmaxEXT(GLenum a, GLboolean b, GLenum c, GLenum d, GLvoid *e) {
	m_pglex->glGetMinmaxEXT(a,b,c,d,e);
}

inline void glex::glGetMinmaxParameterfvEXT(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetMinmaxParameterfvEXT(a,b,c);
}

inline void glex::glGetMinmaxParameterivEXT(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetMinmaxParameterivEXT(a,b,c);
}

inline void glex::glHistogramEXT(GLenum a, GLsizei b, GLenum c, GLboolean d) {
	m_pglex->glHistogramEXT(a,b,c,d);
}

inline void glex::glMinmaxEXT(GLenum a, GLenum b, GLboolean c) {
	m_pglex->glMinmaxEXT(a,b,c);
}

inline void glex::glResetHistogramEXT(GLenum a) {
	m_pglex->glResetHistogramEXT(a);
}

inline void glex::glResetMinmaxEXT(GLenum a) {
	m_pglex->glResetMinmaxEXT(a);
}

inline void glex::glConvolutionFilter1DEXT(GLenum a, GLenum b, GLsizei c, GLenum d, GLenum e, const GLvoid *f) {
	m_pglex->glConvolutionFilter1DEXT(a,b,c,d,e,f);
}

inline void glex::glConvolutionFilter2DEXT(GLenum a, GLenum b, GLsizei c, GLsizei d, GLenum e, GLenum f, const GLvoid *g) {
	m_pglex->glConvolutionFilter2DEXT(a,b,c,d,e,f,g);
}

inline void glex::glConvolutionParameterfEXT(GLenum a, GLenum b, GLfloat c) {
	m_pglex->glConvolutionParameterfEXT(a,b,c);
}

inline void glex::glConvolutionParameterfvEXT(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glConvolutionParameterfvEXT(a,b,c);
}

inline void glex::glConvolutionParameteriEXT(GLenum a, GLenum b, GLint c) {
	m_pglex->glConvolutionParameteriEXT(a,b,c);
}

inline void glex::glConvolutionParameterivEXT(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glConvolutionParameterivEXT(a,b,c);
}

inline void glex::glCopyConvolutionFilter1DEXT(GLenum a, GLenum b, GLint c, GLint d, GLsizei e) {
	m_pglex->glCopyConvolutionFilter1DEXT(a,b,c,d,e);
}

inline void glex::glCopyConvolutionFilter2DEXT(GLenum a, GLenum b, GLint c, GLint d, GLsizei e, GLsizei f) {
	m_pglex->glCopyConvolutionFilter2DEXT(a,b,c,d,e,f);
}

inline void glex::glGetConvolutionFilterEXT(GLenum a, GLenum b, GLenum c, GLvoid *d) {
	m_pglex->glGetConvolutionFilterEXT(a,b,c,d);
}

inline void glex::glGetConvolutionParameterfvEXT(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetConvolutionParameterfvEXT(a,b,c);
}

inline void glex::glGetConvolutionParameterivEXT(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetConvolutionParameterivEXT(a,b,c);
}

inline void glex::glGetSeparableFilterEXT(GLenum a, GLenum b, GLenum c, GLvoid *d, GLvoid *e, GLvoid *f) {
	m_pglex->glGetSeparableFilterEXT(a,b,c,d,e,f);
}

inline void glex::glSeparableFilter2DEXT(GLenum a, GLenum b, GLsizei c, GLsizei d, GLenum e, GLenum f, const GLvoid *g, const GLvoid *h) {
	m_pglex->glSeparableFilter2DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glColorTableSGI(GLenum a, GLenum b, GLsizei c, GLenum d, GLenum e, const GLvoid *f) {
	m_pglex->glColorTableSGI(a,b,c,d,e,f);
}

inline void glex::glColorTableParameterfvSGI(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glColorTableParameterfvSGI(a,b,c);
}

inline void glex::glColorTableParameterivSGI(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glColorTableParameterivSGI(a,b,c);
}

inline void glex::glCopyColorTableSGI(GLenum a, GLenum b, GLint c, GLint d, GLsizei e) {
	m_pglex->glCopyColorTableSGI(a,b,c,d,e);
}

inline void glex::glGetColorTableSGI(GLenum a, GLenum b, GLenum c, GLvoid *d) {
	m_pglex->glGetColorTableSGI(a,b,c,d);
}

inline void glex::glGetColorTableParameterfvSGI(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetColorTableParameterfvSGI(a,b,c);
}

inline void glex::glGetColorTableParameterivSGI(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetColorTableParameterivSGI(a,b,c);
}

inline void glex::glPixelTexGenSGIX(GLenum a) {
	m_pglex->glPixelTexGenSGIX(a);
}

inline void glex::glPixelTexGenParameteriSGIS(GLenum a, GLint b) {
	m_pglex->glPixelTexGenParameteriSGIS(a,b);
}

inline void glex::glPixelTexGenParameterivSGIS(GLenum a, const GLint *b) {
	m_pglex->glPixelTexGenParameterivSGIS(a,b);
}

inline void glex::glPixelTexGenParameterfSGIS(GLenum a, GLfloat b) {
	m_pglex->glPixelTexGenParameterfSGIS(a,b);
}

inline void glex::glPixelTexGenParameterfvSGIS(GLenum a, const GLfloat *b) {
	m_pglex->glPixelTexGenParameterfvSGIS(a,b);
}

inline void glex::glGetPixelTexGenParameterivSGIS(GLenum a, GLint *b) {
	m_pglex->glGetPixelTexGenParameterivSGIS(a,b);
}

inline void glex::glGetPixelTexGenParameterfvSGIS(GLenum a, GLfloat *b) {
	m_pglex->glGetPixelTexGenParameterfvSGIS(a,b);
}

inline void glex::glTexImage4DSGIS(GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLsizei f, GLsizei g, GLint h, GLenum i, GLenum j, const GLvoid *k) {
	m_pglex->glTexImage4DSGIS(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glTexSubImage4DSGIS(GLenum a, GLint b, GLint c, GLint d, GLint e, GLint f, GLsizei g, GLsizei h, GLsizei i, GLsizei j, GLenum k, GLenum l, const GLvoid *m) {
	m_pglex->glTexSubImage4DSGIS(a,b,c,d,e,f,g,h,i,j,k,l,m);
}

inline GLboolean glex::glAreTexturesResidentEXT(GLsizei a, const GLuint *b, GLboolean *c) {
	return m_pglex->glAreTexturesResidentEXT(a,b,c);
}

inline void glex::glBindTextureEXT(GLenum a, GLuint b) {
	m_pglex->glBindTextureEXT(a,b);
}

inline void glex::glDeleteTexturesEXT(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteTexturesEXT(a,b);
}

inline void glex::glGenTexturesEXT(GLsizei a, GLuint *b) {
	m_pglex->glGenTexturesEXT(a,b);
}

inline GLboolean glex::glIsTextureEXT(GLuint a) {
	return m_pglex->glIsTextureEXT(a);
}

inline void glex::glPrioritizeTexturesEXT(GLsizei a, const GLuint *b, const GLclampf *c) {
	m_pglex->glPrioritizeTexturesEXT(a,b,c);
}

inline void glex::glDetailTexFuncSGIS(GLenum a, GLsizei b, const GLfloat *c) {
	m_pglex->glDetailTexFuncSGIS(a,b,c);
}

inline void glex::glGetDetailTexFuncSGIS(GLenum a, GLfloat *b) {
	m_pglex->glGetDetailTexFuncSGIS(a,b);
}

inline void glex::glSharpenTexFuncSGIS(GLenum a, GLsizei b, const GLfloat *c) {
	m_pglex->glSharpenTexFuncSGIS(a,b,c);
}

inline void glex::glGetSharpenTexFuncSGIS(GLenum a, GLfloat *b) {
	m_pglex->glGetSharpenTexFuncSGIS(a,b);
}

inline void glex::glSampleMaskSGIS(GLclampf a, GLboolean b) {
	m_pglex->glSampleMaskSGIS(a,b);
}

inline void glex::glSamplePatternSGIS(GLenum a) {
	m_pglex->glSamplePatternSGIS(a);
}

inline void glex::glArrayElementEXT(GLint a) {
	m_pglex->glArrayElementEXT(a);
}

inline void glex::glColorPointerEXT(GLint a, GLenum b, GLsizei c, GLsizei d, const GLvoid *e) {
	m_pglex->glColorPointerEXT(a,b,c,d,e);
}

inline void glex::glDrawArraysEXT(GLenum a, GLint b, GLsizei c) {
	m_pglex->glDrawArraysEXT(a,b,c);
}

inline void glex::glEdgeFlagPointerEXT(GLsizei a, GLsizei b, const GLboolean *c) {
	m_pglex->glEdgeFlagPointerEXT(a,b,c);
}

inline void glex::glGetPointervEXT(GLenum a, GLvoid* *b) {
	m_pglex->glGetPointervEXT(a,b);
}

inline void glex::glIndexPointerEXT(GLenum a, GLsizei b, GLsizei c, const GLvoid *d) {
	m_pglex->glIndexPointerEXT(a,b,c,d);
}

inline void glex::glNormalPointerEXT(GLenum a, GLsizei b, GLsizei c, const GLvoid *d) {
	m_pglex->glNormalPointerEXT(a,b,c,d);
}

inline void glex::glTexCoordPointerEXT(GLint a, GLenum b, GLsizei c, GLsizei d, const GLvoid *e) {
	m_pglex->glTexCoordPointerEXT(a,b,c,d,e);
}

inline void glex::glVertexPointerEXT(GLint a, GLenum b, GLsizei c, GLsizei d, const GLvoid *e) {
	m_pglex->glVertexPointerEXT(a,b,c,d,e);
}

inline void glex::glBlendEquationEXT(GLenum a) {
	m_pglex->glBlendEquationEXT(a);
}

inline void glex::glSpriteParameterfSGIX(GLenum a, GLfloat b) {
	m_pglex->glSpriteParameterfSGIX(a,b);
}

inline void glex::glSpriteParameterfvSGIX(GLenum a, const GLfloat *b) {
	m_pglex->glSpriteParameterfvSGIX(a,b);
}

inline void glex::glSpriteParameteriSGIX(GLenum a, GLint b) {
	m_pglex->glSpriteParameteriSGIX(a,b);
}

inline void glex::glSpriteParameterivSGIX(GLenum a, const GLint *b) {
	m_pglex->glSpriteParameterivSGIX(a,b);
}

inline void glex::glPointParameterfEXT(GLenum a, GLfloat b) {
	m_pglex->glPointParameterfEXT(a,b);
}

inline void glex::glPointParameterfvEXT(GLenum a, const GLfloat *b) {
	m_pglex->glPointParameterfvEXT(a,b);
}

inline void glex::glPointParameterfSGIS(GLenum a, GLfloat b) {
	m_pglex->glPointParameterfSGIS(a,b);
}

inline void glex::glPointParameterfvSGIS(GLenum a, const GLfloat *b) {
	m_pglex->glPointParameterfvSGIS(a,b);
}

inline GLint glex::glGetInstrumentsSGIX(void) {
	return m_pglex->glGetInstrumentsSGIX();
}

inline void glex::glInstrumentsBufferSGIX(GLsizei a, GLint *b) {
	m_pglex->glInstrumentsBufferSGIX(a,b);
}

inline GLint glex::glPollInstrumentsSGIX(GLint *a) {
	return m_pglex->glPollInstrumentsSGIX(a);
}

inline void glex::glReadInstrumentsSGIX(GLint a) {
	m_pglex->glReadInstrumentsSGIX(a);
}

inline void glex::glStartInstrumentsSGIX(void) {
	m_pglex->glStartInstrumentsSGIX();
}

inline void glex::glStopInstrumentsSGIX(GLint a) {
	m_pglex->glStopInstrumentsSGIX(a);
}

inline void glex::glFrameZoomSGIX(GLint a) {
	m_pglex->glFrameZoomSGIX(a);
}

inline void glex::glTagSampleBufferSGIX(void) {
	m_pglex->glTagSampleBufferSGIX();
}

inline void glex::glDeformationMap3dSGIX(GLenum a, GLdouble b, GLdouble c, GLint d, GLint e, GLdouble f, GLdouble g, GLint h, GLint i, GLdouble j, GLdouble k, GLint l, GLint m, const GLdouble *n) {
	m_pglex->glDeformationMap3dSGIX(a,b,c,d,e,f,g,h,i,j,k,l,m,n);
}

inline void glex::glDeformationMap3fSGIX(GLenum a, GLfloat b, GLfloat c, GLint d, GLint e, GLfloat f, GLfloat g, GLint h, GLint i, GLfloat j, GLfloat k, GLint l, GLint m, const GLfloat *n) {
	m_pglex->glDeformationMap3fSGIX(a,b,c,d,e,f,g,h,i,j,k,l,m,n);
}

inline void glex::glDeformSGIX(GLbitfield a) {
	m_pglex->glDeformSGIX(a);
}

inline void glex::glLoadIdentityDeformationMapSGIX(GLbitfield a) {
	m_pglex->glLoadIdentityDeformationMapSGIX(a);
}

inline void glex::glReferencePlaneSGIX(const GLdouble *a) {
	m_pglex->glReferencePlaneSGIX(a);
}

inline void glex::glFlushRasterSGIX(void) {
	m_pglex->glFlushRasterSGIX();
}

inline void glex::glFogFuncSGIS(GLsizei a, const GLfloat *b) {
	m_pglex->glFogFuncSGIS(a,b);
}

inline void glex::glGetFogFuncSGIS(GLfloat *a) {
	m_pglex->glGetFogFuncSGIS(a);
}

inline void glex::glImageTransformParameteriHP(GLenum a, GLenum b, GLint c) {
	m_pglex->glImageTransformParameteriHP(a,b,c);
}

inline void glex::glImageTransformParameterfHP(GLenum a, GLenum b, GLfloat c) {
	m_pglex->glImageTransformParameterfHP(a,b,c);
}

inline void glex::glImageTransformParameterivHP(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glImageTransformParameterivHP(a,b,c);
}

inline void glex::glImageTransformParameterfvHP(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glImageTransformParameterfvHP(a,b,c);
}

inline void glex::glGetImageTransformParameterivHP(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetImageTransformParameterivHP(a,b,c);
}

inline void glex::glGetImageTransformParameterfvHP(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetImageTransformParameterfvHP(a,b,c);
}

inline void glex::glColorSubTableEXT(GLenum a, GLsizei b, GLsizei c, GLenum d, GLenum e, const GLvoid *f) {
	m_pglex->glColorSubTableEXT(a,b,c,d,e,f);
}

inline void glex::glCopyColorSubTableEXT(GLenum a, GLsizei b, GLint c, GLint d, GLsizei e) {
	m_pglex->glCopyColorSubTableEXT(a,b,c,d,e);
}

inline void glex::glHintPGI(GLenum a, GLint b) {
	m_pglex->glHintPGI(a,b);
}

inline void glex::glColorTableEXT(GLenum a, GLenum b, GLsizei c, GLenum d, GLenum e, const GLvoid *f) {
	m_pglex->glColorTableEXT(a,b,c,d,e,f);
}

inline void glex::glGetColorTableEXT(GLenum a, GLenum b, GLenum c, GLvoid *d) {
	m_pglex->glGetColorTableEXT(a,b,c,d);
}

inline void glex::glGetColorTableParameterivEXT(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetColorTableParameterivEXT(a,b,c);
}

inline void glex::glGetColorTableParameterfvEXT(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetColorTableParameterfvEXT(a,b,c);
}

inline void glex::glGetListParameterfvSGIX(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetListParameterfvSGIX(a,b,c);
}

inline void glex::glGetListParameterivSGIX(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetListParameterivSGIX(a,b,c);
}

inline void glex::glListParameterfSGIX(GLuint a, GLenum b, GLfloat c) {
	m_pglex->glListParameterfSGIX(a,b,c);
}

inline void glex::glListParameterfvSGIX(GLuint a, GLenum b, const GLfloat *c) {
	m_pglex->glListParameterfvSGIX(a,b,c);
}

inline void glex::glListParameteriSGIX(GLuint a, GLenum b, GLint c) {
	m_pglex->glListParameteriSGIX(a,b,c);
}

inline void glex::glListParameterivSGIX(GLuint a, GLenum b, const GLint *c) {
	m_pglex->glListParameterivSGIX(a,b,c);
}

inline void glex::glIndexMaterialEXT(GLenum a, GLenum b) {
	m_pglex->glIndexMaterialEXT(a,b);
}

inline void glex::glIndexFuncEXT(GLenum a, GLclampf b) {
	m_pglex->glIndexFuncEXT(a,b);
}

inline void glex::glLockArraysEXT(GLint a, GLsizei b) {
	m_pglex->glLockArraysEXT(a,b);
}

inline void glex::glUnlockArraysEXT(void) {
	m_pglex->glUnlockArraysEXT();
}

inline void glex::glCullParameterdvEXT(GLenum a, GLdouble *b) {
	m_pglex->glCullParameterdvEXT(a,b);
}

inline void glex::glCullParameterfvEXT(GLenum a, GLfloat *b) {
	m_pglex->glCullParameterfvEXT(a,b);
}

inline void glex::glFragmentColorMaterialSGIX(GLenum a, GLenum b) {
	m_pglex->glFragmentColorMaterialSGIX(a,b);
}

inline void glex::glFragmentLightfSGIX(GLenum a, GLenum b, GLfloat c) {
	m_pglex->glFragmentLightfSGIX(a,b,c);
}

inline void glex::glFragmentLightfvSGIX(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glFragmentLightfvSGIX(a,b,c);
}

inline void glex::glFragmentLightiSGIX(GLenum a, GLenum b, GLint c) {
	m_pglex->glFragmentLightiSGIX(a,b,c);
}

inline void glex::glFragmentLightivSGIX(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glFragmentLightivSGIX(a,b,c);
}

inline void glex::glFragmentLightModelfSGIX(GLenum a, GLfloat b) {
	m_pglex->glFragmentLightModelfSGIX(a,b);
}

inline void glex::glFragmentLightModelfvSGIX(GLenum a, const GLfloat *b) {
	m_pglex->glFragmentLightModelfvSGIX(a,b);
}

inline void glex::glFragmentLightModeliSGIX(GLenum a, GLint b) {
	m_pglex->glFragmentLightModeliSGIX(a,b);
}

inline void glex::glFragmentLightModelivSGIX(GLenum a, const GLint *b) {
	m_pglex->glFragmentLightModelivSGIX(a,b);
}

inline void glex::glFragmentMaterialfSGIX(GLenum a, GLenum b, GLfloat c) {
	m_pglex->glFragmentMaterialfSGIX(a,b,c);
}

inline void glex::glFragmentMaterialfvSGIX(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glFragmentMaterialfvSGIX(a,b,c);
}

inline void glex::glFragmentMaterialiSGIX(GLenum a, GLenum b, GLint c) {
	m_pglex->glFragmentMaterialiSGIX(a,b,c);
}

inline void glex::glFragmentMaterialivSGIX(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glFragmentMaterialivSGIX(a,b,c);
}

inline void glex::glGetFragmentLightfvSGIX(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetFragmentLightfvSGIX(a,b,c);
}

inline void glex::glGetFragmentLightivSGIX(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetFragmentLightivSGIX(a,b,c);
}

inline void glex::glGetFragmentMaterialfvSGIX(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetFragmentMaterialfvSGIX(a,b,c);
}

inline void glex::glGetFragmentMaterialivSGIX(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetFragmentMaterialivSGIX(a,b,c);
}

inline void glex::glLightEnviSGIX(GLenum a, GLint b) {
	m_pglex->glLightEnviSGIX(a,b);
}

inline void glex::glDrawRangeElementsEXT(GLenum a, GLuint b, GLuint c, GLsizei d, GLenum e, const GLvoid *f) {
	m_pglex->glDrawRangeElementsEXT(a,b,c,d,e,f);
}

inline void glex::glApplyTextureEXT(GLenum a) {
	m_pglex->glApplyTextureEXT(a);
}

inline void glex::glTextureLightEXT(GLenum a) {
	m_pglex->glTextureLightEXT(a);
}

inline void glex::glTextureMaterialEXT(GLenum a, GLenum b) {
	m_pglex->glTextureMaterialEXT(a,b);
}

inline void glex::glAsyncMarkerSGIX(GLuint a) {
	m_pglex->glAsyncMarkerSGIX(a);
}

inline GLint glex::glFinishAsyncSGIX(GLuint *a) {
	return m_pglex->glFinishAsyncSGIX(a);
}

inline GLint glex::glPollAsyncSGIX(GLuint *a) {
	return m_pglex->glPollAsyncSGIX(a);
}

inline GLuint glex::glGenAsyncMarkersSGIX(GLsizei a) {
	return m_pglex->glGenAsyncMarkersSGIX(a);
}

inline void glex::glDeleteAsyncMarkersSGIX(GLuint a, GLsizei b) {
	m_pglex->glDeleteAsyncMarkersSGIX(a,b);
}

inline GLboolean glex::glIsAsyncMarkerSGIX(GLuint a) {
	return m_pglex->glIsAsyncMarkerSGIX(a);
}

inline void glex::glVertexPointervINTEL(GLint a, GLenum b, const GLvoid* *c) {
	m_pglex->glVertexPointervINTEL(a,b,c);
}

inline void glex::glNormalPointervINTEL(GLenum a, const GLvoid* *b) {
	m_pglex->glNormalPointervINTEL(a,b);
}

inline void glex::glColorPointervINTEL(GLint a, GLenum b, const GLvoid* *c) {
	m_pglex->glColorPointervINTEL(a,b,c);
}

inline void glex::glTexCoordPointervINTEL(GLint a, GLenum b, const GLvoid* *c) {
	m_pglex->glTexCoordPointervINTEL(a,b,c);
}

inline void glex::glPixelTransformParameteriEXT(GLenum a, GLenum b, GLint c) {
	m_pglex->glPixelTransformParameteriEXT(a,b,c);
}

inline void glex::glPixelTransformParameterfEXT(GLenum a, GLenum b, GLfloat c) {
	m_pglex->glPixelTransformParameterfEXT(a,b,c);
}

inline void glex::glPixelTransformParameterivEXT(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glPixelTransformParameterivEXT(a,b,c);
}

inline void glex::glPixelTransformParameterfvEXT(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glPixelTransformParameterfvEXT(a,b,c);
}

inline void glex::glSecondaryColor3bEXT(GLbyte a, GLbyte b, GLbyte c) {
	m_pglex->glSecondaryColor3bEXT(a,b,c);
}

inline void glex::glSecondaryColor3bvEXT(const GLbyte *a) {
	m_pglex->glSecondaryColor3bvEXT(a);
}

inline void glex::glSecondaryColor3dEXT(GLdouble a, GLdouble b, GLdouble c) {
	m_pglex->glSecondaryColor3dEXT(a,b,c);
}

inline void glex::glSecondaryColor3dvEXT(const GLdouble *a) {
	m_pglex->glSecondaryColor3dvEXT(a);
}

inline void glex::glSecondaryColor3fEXT(GLfloat a, GLfloat b, GLfloat c) {
	m_pglex->glSecondaryColor3fEXT(a,b,c);
}

inline void glex::glSecondaryColor3fvEXT(const GLfloat *a) {
	m_pglex->glSecondaryColor3fvEXT(a);
}

inline void glex::glSecondaryColor3iEXT(GLint a, GLint b, GLint c) {
	m_pglex->glSecondaryColor3iEXT(a,b,c);
}

inline void glex::glSecondaryColor3ivEXT(const GLint *a) {
	m_pglex->glSecondaryColor3ivEXT(a);
}

inline void glex::glSecondaryColor3sEXT(GLshort a, GLshort b, GLshort c) {
	m_pglex->glSecondaryColor3sEXT(a,b,c);
}

inline void glex::glSecondaryColor3svEXT(const GLshort *a) {
	m_pglex->glSecondaryColor3svEXT(a);
}

inline void glex::glSecondaryColor3ubEXT(GLubyte a, GLubyte b, GLubyte c) {
	m_pglex->glSecondaryColor3ubEXT(a,b,c);
}

inline void glex::glSecondaryColor3ubvEXT(const GLubyte *a) {
	m_pglex->glSecondaryColor3ubvEXT(a);
}

inline void glex::glSecondaryColor3uiEXT(GLuint a, GLuint b, GLuint c) {
	m_pglex->glSecondaryColor3uiEXT(a,b,c);
}

inline void glex::glSecondaryColor3uivEXT(const GLuint *a) {
	m_pglex->glSecondaryColor3uivEXT(a);
}

inline void glex::glSecondaryColor3usEXT(GLushort a, GLushort b, GLushort c) {
	m_pglex->glSecondaryColor3usEXT(a,b,c);
}

inline void glex::glSecondaryColor3usvEXT(const GLushort *a) {
	m_pglex->glSecondaryColor3usvEXT(a);
}

inline void glex::glSecondaryColorPointerEXT(GLint a, GLenum b, GLsizei c, const GLvoid *d) {
	m_pglex->glSecondaryColorPointerEXT(a,b,c,d);
}

inline void glex::glTextureNormalEXT(GLenum a) {
	m_pglex->glTextureNormalEXT(a);
}

inline void glex::glMultiDrawArraysEXT(GLenum a, const GLint *b, const GLsizei *c, GLsizei d) {
	m_pglex->glMultiDrawArraysEXT(a,b,c,d);
}

inline void glex::glMultiDrawElementsEXT(GLenum a, const GLsizei *b, GLenum c, const GLvoid* *d, GLsizei e) {
	m_pglex->glMultiDrawElementsEXT(a,b,c,d,e);
}

inline void glex::glFogCoordfEXT(GLfloat a) {
	m_pglex->glFogCoordfEXT(a);
}

inline void glex::glFogCoordfvEXT(const GLfloat *a) {
	m_pglex->glFogCoordfvEXT(a);
}

inline void glex::glFogCoorddEXT(GLdouble a) {
	m_pglex->glFogCoorddEXT(a);
}

inline void glex::glFogCoorddvEXT(const GLdouble *a) {
	m_pglex->glFogCoorddvEXT(a);
}

inline void glex::glFogCoordPointerEXT(GLenum a, GLsizei b, const GLvoid *c) {
	m_pglex->glFogCoordPointerEXT(a,b,c);
}

inline void glex::glTangent3bEXT(GLbyte a, GLbyte b, GLbyte c) {
	m_pglex->glTangent3bEXT(a,b,c);
}

inline void glex::glTangent3bvEXT(const GLbyte *a) {
	m_pglex->glTangent3bvEXT(a);
}

inline void glex::glTangent3dEXT(GLdouble a, GLdouble b, GLdouble c) {
	m_pglex->glTangent3dEXT(a,b,c);
}

inline void glex::glTangent3dvEXT(const GLdouble *a) {
	m_pglex->glTangent3dvEXT(a);
}

inline void glex::glTangent3fEXT(GLfloat a, GLfloat b, GLfloat c) {
	m_pglex->glTangent3fEXT(a,b,c);
}

inline void glex::glTangent3fvEXT(const GLfloat *a) {
	m_pglex->glTangent3fvEXT(a);
}

inline void glex::glTangent3iEXT(GLint a, GLint b, GLint c) {
	m_pglex->glTangent3iEXT(a,b,c);
}

inline void glex::glTangent3ivEXT(const GLint *a) {
	m_pglex->glTangent3ivEXT(a);
}

inline void glex::glTangent3sEXT(GLshort a, GLshort b, GLshort c) {
	m_pglex->glTangent3sEXT(a,b,c);
}

inline void glex::glTangent3svEXT(const GLshort *a) {
	m_pglex->glTangent3svEXT(a);
}

inline void glex::glBinormal3bEXT(GLbyte a, GLbyte b, GLbyte c) {
	m_pglex->glBinormal3bEXT(a,b,c);
}

inline void glex::glBinormal3bvEXT(const GLbyte *a) {
	m_pglex->glBinormal3bvEXT(a);
}

inline void glex::glBinormal3dEXT(GLdouble a, GLdouble b, GLdouble c) {
	m_pglex->glBinormal3dEXT(a,b,c);
}

inline void glex::glBinormal3dvEXT(const GLdouble *a) {
	m_pglex->glBinormal3dvEXT(a);
}

inline void glex::glBinormal3fEXT(GLfloat a, GLfloat b, GLfloat c) {
	m_pglex->glBinormal3fEXT(a,b,c);
}

inline void glex::glBinormal3fvEXT(const GLfloat *a) {
	m_pglex->glBinormal3fvEXT(a);
}

inline void glex::glBinormal3iEXT(GLint a, GLint b, GLint c) {
	m_pglex->glBinormal3iEXT(a,b,c);
}

inline void glex::glBinormal3ivEXT(const GLint *a) {
	m_pglex->glBinormal3ivEXT(a);
}

inline void glex::glBinormal3sEXT(GLshort a, GLshort b, GLshort c) {
	m_pglex->glBinormal3sEXT(a,b,c);
}

inline void glex::glBinormal3svEXT(const GLshort *a) {
	m_pglex->glBinormal3svEXT(a);
}

inline void glex::glTangentPointerEXT(GLenum a, GLsizei b, const GLvoid *c) {
	m_pglex->glTangentPointerEXT(a,b,c);
}

inline void glex::glBinormalPointerEXT(GLenum a, GLsizei b, const GLvoid *c) {
	m_pglex->glBinormalPointerEXT(a,b,c);
}

inline void glex::glFinishTextureSUNX(void) {
	m_pglex->glFinishTextureSUNX();
}

inline void glex::glGlobalAlphaFactorbSUN(GLbyte a) {
	m_pglex->glGlobalAlphaFactorbSUN(a);
}

inline void glex::glGlobalAlphaFactorsSUN(GLshort a) {
	m_pglex->glGlobalAlphaFactorsSUN(a);
}

inline void glex::glGlobalAlphaFactoriSUN(GLint a) {
	m_pglex->glGlobalAlphaFactoriSUN(a);
}

inline void glex::glGlobalAlphaFactorfSUN(GLfloat a) {
	m_pglex->glGlobalAlphaFactorfSUN(a);
}

inline void glex::glGlobalAlphaFactordSUN(GLdouble a) {
	m_pglex->glGlobalAlphaFactordSUN(a);
}

inline void glex::glGlobalAlphaFactorubSUN(GLubyte a) {
	m_pglex->glGlobalAlphaFactorubSUN(a);
}

inline void glex::glGlobalAlphaFactorusSUN(GLushort a) {
	m_pglex->glGlobalAlphaFactorusSUN(a);
}

inline void glex::glGlobalAlphaFactoruiSUN(GLuint a) {
	m_pglex->glGlobalAlphaFactoruiSUN(a);
}

inline void glex::glReplacementCodeuiSUN(GLuint a) {
	m_pglex->glReplacementCodeuiSUN(a);
}

inline void glex::glReplacementCodeusSUN(GLushort a) {
	m_pglex->glReplacementCodeusSUN(a);
}

inline void glex::glReplacementCodeubSUN(GLubyte a) {
	m_pglex->glReplacementCodeubSUN(a);
}

inline void glex::glReplacementCodeuivSUN(const GLuint *a) {
	m_pglex->glReplacementCodeuivSUN(a);
}

inline void glex::glReplacementCodeusvSUN(const GLushort *a) {
	m_pglex->glReplacementCodeusvSUN(a);
}

inline void glex::glReplacementCodeubvSUN(const GLubyte *a) {
	m_pglex->glReplacementCodeubvSUN(a);
}

inline void glex::glReplacementCodePointerSUN(GLenum a, GLsizei b, const GLvoid* *c) {
	m_pglex->glReplacementCodePointerSUN(a,b,c);
}

inline void glex::glColor4ubVertex2fSUN(GLubyte a, GLubyte b, GLubyte c, GLubyte d, GLfloat e, GLfloat f) {
	m_pglex->glColor4ubVertex2fSUN(a,b,c,d,e,f);
}

inline void glex::glColor4ubVertex2fvSUN(const GLubyte *a, const GLfloat *b) {
	m_pglex->glColor4ubVertex2fvSUN(a,b);
}

inline void glex::glColor4ubVertex3fSUN(GLubyte a, GLubyte b, GLubyte c, GLubyte d, GLfloat e, GLfloat f, GLfloat g) {
	m_pglex->glColor4ubVertex3fSUN(a,b,c,d,e,f,g);
}

inline void glex::glColor4ubVertex3fvSUN(const GLubyte *a, const GLfloat *b) {
	m_pglex->glColor4ubVertex3fvSUN(a,b);
}

inline void glex::glColor3fVertex3fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glColor3fVertex3fSUN(a,b,c,d,e,f);
}

inline void glex::glColor3fVertex3fvSUN(const GLfloat *a, const GLfloat *b) {
	m_pglex->glColor3fVertex3fvSUN(a,b);
}

inline void glex::glNormal3fVertex3fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glNormal3fVertex3fSUN(a,b,c,d,e,f);
}

inline void glex::glNormal3fVertex3fvSUN(const GLfloat *a, const GLfloat *b) {
	m_pglex->glNormal3fVertex3fvSUN(a,b);
}

inline void glex::glColor4fNormal3fVertex3fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h, GLfloat i, GLfloat j) {
	m_pglex->glColor4fNormal3fVertex3fSUN(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glColor4fNormal3fVertex3fvSUN(const GLfloat *a, const GLfloat *b, const GLfloat *c) {
	m_pglex->glColor4fNormal3fVertex3fvSUN(a,b,c);
}

inline void glex::glTexCoord2fVertex3fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glTexCoord2fVertex3fSUN(a,b,c,d,e);
}

inline void glex::glTexCoord2fVertex3fvSUN(const GLfloat *a, const GLfloat *b) {
	m_pglex->glTexCoord2fVertex3fvSUN(a,b);
}

inline void glex::glTexCoord4fVertex4fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h) {
	m_pglex->glTexCoord4fVertex4fSUN(a,b,c,d,e,f,g,h);
}

inline void glex::glTexCoord4fVertex4fvSUN(const GLfloat *a, const GLfloat *b) {
	m_pglex->glTexCoord4fVertex4fvSUN(a,b);
}

inline void glex::glTexCoord2fColor4ubVertex3fSUN(GLfloat a, GLfloat b, GLubyte c, GLubyte d, GLubyte e, GLubyte f, GLfloat g, GLfloat h, GLfloat i) {
	m_pglex->glTexCoord2fColor4ubVertex3fSUN(a,b,c,d,e,f,g,h,i);
}

inline void glex::glTexCoord2fColor4ubVertex3fvSUN(const GLfloat *a, const GLubyte *b, const GLfloat *c) {
	m_pglex->glTexCoord2fColor4ubVertex3fvSUN(a,b,c);
}

inline void glex::glTexCoord2fColor3fVertex3fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h) {
	m_pglex->glTexCoord2fColor3fVertex3fSUN(a,b,c,d,e,f,g,h);
}

inline void glex::glTexCoord2fColor3fVertex3fvSUN(const GLfloat *a, const GLfloat *b, const GLfloat *c) {
	m_pglex->glTexCoord2fColor3fVertex3fvSUN(a,b,c);
}

inline void glex::glTexCoord2fNormal3fVertex3fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h) {
	m_pglex->glTexCoord2fNormal3fVertex3fSUN(a,b,c,d,e,f,g,h);
}

inline void glex::glTexCoord2fNormal3fVertex3fvSUN(const GLfloat *a, const GLfloat *b, const GLfloat *c) {
	m_pglex->glTexCoord2fNormal3fVertex3fvSUN(a,b,c);
}

inline void glex::glTexCoord2fColor4fNormal3fVertex3fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h, GLfloat i, GLfloat j, GLfloat k, GLfloat l) {
	m_pglex->glTexCoord2fColor4fNormal3fVertex3fSUN(a,b,c,d,e,f,g,h,i,j,k,l);
}

inline void glex::glTexCoord2fColor4fNormal3fVertex3fvSUN(const GLfloat *a, const GLfloat *b, const GLfloat *c, const GLfloat *d) {
	m_pglex->glTexCoord2fColor4fNormal3fVertex3fvSUN(a,b,c,d);
}

inline void glex::glTexCoord4fColor4fNormal3fVertex4fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h, GLfloat i, GLfloat j, GLfloat k, GLfloat l, GLfloat m, GLfloat n, GLfloat o) {
	m_pglex->glTexCoord4fColor4fNormal3fVertex4fSUN(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o);
}

inline void glex::glTexCoord4fColor4fNormal3fVertex4fvSUN(const GLfloat *a, const GLfloat *b, const GLfloat *c, const GLfloat *d) {
	m_pglex->glTexCoord4fColor4fNormal3fVertex4fvSUN(a,b,c,d);
}

inline void glex::glReplacementCodeuiVertex3fSUN(GLuint a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glReplacementCodeuiVertex3fSUN(a,b,c,d);
}

inline void glex::glReplacementCodeuiVertex3fvSUN(const GLuint *a, const GLfloat *b) {
	m_pglex->glReplacementCodeuiVertex3fvSUN(a,b);
}

inline void glex::glReplacementCodeuiColor4ubVertex3fSUN(GLuint a, GLubyte b, GLubyte c, GLubyte d, GLubyte e, GLfloat f, GLfloat g, GLfloat h) {
	m_pglex->glReplacementCodeuiColor4ubVertex3fSUN(a,b,c,d,e,f,g,h);
}

inline void glex::glReplacementCodeuiColor4ubVertex3fvSUN(const GLuint *a, const GLubyte *b, const GLfloat *c) {
	m_pglex->glReplacementCodeuiColor4ubVertex3fvSUN(a,b,c);
}

inline void glex::glReplacementCodeuiColor3fVertex3fSUN(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g) {
	m_pglex->glReplacementCodeuiColor3fVertex3fSUN(a,b,c,d,e,f,g);
}

inline void glex::glReplacementCodeuiColor3fVertex3fvSUN(const GLuint *a, const GLfloat *b, const GLfloat *c) {
	m_pglex->glReplacementCodeuiColor3fVertex3fvSUN(a,b,c);
}

inline void glex::glReplacementCodeuiNormal3fVertex3fSUN(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g) {
	m_pglex->glReplacementCodeuiNormal3fVertex3fSUN(a,b,c,d,e,f,g);
}

inline void glex::glReplacementCodeuiNormal3fVertex3fvSUN(const GLuint *a, const GLfloat *b, const GLfloat *c) {
	m_pglex->glReplacementCodeuiNormal3fVertex3fvSUN(a,b,c);
}

inline void glex::glReplacementCodeuiColor4fNormal3fVertex3fSUN(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h, GLfloat i, GLfloat j, GLfloat k) {
	m_pglex->glReplacementCodeuiColor4fNormal3fVertex3fSUN(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glReplacementCodeuiColor4fNormal3fVertex3fvSUN(const GLuint *a, const GLfloat *b, const GLfloat *c, const GLfloat *d) {
	m_pglex->glReplacementCodeuiColor4fNormal3fVertex3fvSUN(a,b,c,d);
}

inline void glex::glReplacementCodeuiTexCoord2fVertex3fSUN(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glReplacementCodeuiTexCoord2fVertex3fSUN(a,b,c,d,e,f);
}

inline void glex::glReplacementCodeuiTexCoord2fVertex3fvSUN(const GLuint *a, const GLfloat *b, const GLfloat *c) {
	m_pglex->glReplacementCodeuiTexCoord2fVertex3fvSUN(a,b,c);
}

inline void glex::glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h, GLfloat i) {
	m_pglex->glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(a,b,c,d,e,f,g,h,i);
}

inline void glex::glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(const GLuint *a, const GLfloat *b, const GLfloat *c, const GLfloat *d) {
	m_pglex->glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(a,b,c,d);
}

inline void glex::glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h, GLfloat i, GLfloat j, GLfloat k, GLfloat l, GLfloat m) {
	m_pglex->glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(a,b,c,d,e,f,g,h,i,j,k,l,m);
}

inline void glex::glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(const GLuint *a, const GLfloat *b, const GLfloat *c, const GLfloat *d, const GLfloat *e) {
	m_pglex->glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(a,b,c,d,e);
}

inline void glex::glBlendFuncSeparateEXT(GLenum a, GLenum b, GLenum c, GLenum d) {
	m_pglex->glBlendFuncSeparateEXT(a,b,c,d);
}

inline void glex::glBlendFuncSeparateINGR(GLenum a, GLenum b, GLenum c, GLenum d) {
	m_pglex->glBlendFuncSeparateINGR(a,b,c,d);
}

inline void glex::glVertexWeightfEXT(GLfloat a) {
	m_pglex->glVertexWeightfEXT(a);
}

inline void glex::glVertexWeightfvEXT(const GLfloat *a) {
	m_pglex->glVertexWeightfvEXT(a);
}

inline void glex::glVertexWeightPointerEXT(GLsizei a, GLenum b, GLsizei c, const GLvoid *d) {
	m_pglex->glVertexWeightPointerEXT(a,b,c,d);
}

inline void glex::glFlushVertexArrayRangeNV(void) {
	m_pglex->glFlushVertexArrayRangeNV();
}

inline void glex::glVertexArrayRangeNV(GLsizei a, const GLvoid *b) {
	m_pglex->glVertexArrayRangeNV(a,b);
}

inline void glex::glCombinerParameterfvNV(GLenum a, const GLfloat *b) {
	m_pglex->glCombinerParameterfvNV(a,b);
}

inline void glex::glCombinerParameterfNV(GLenum a, GLfloat b) {
	m_pglex->glCombinerParameterfNV(a,b);
}

inline void glex::glCombinerParameterivNV(GLenum a, const GLint *b) {
	m_pglex->glCombinerParameterivNV(a,b);
}

inline void glex::glCombinerParameteriNV(GLenum a, GLint b) {
	m_pglex->glCombinerParameteriNV(a,b);
}

inline void glex::glCombinerInputNV(GLenum a, GLenum b, GLenum c, GLenum d, GLenum e, GLenum f) {
	m_pglex->glCombinerInputNV(a,b,c,d,e,f);
}

inline void glex::glCombinerOutputNV(GLenum a, GLenum b, GLenum c, GLenum d, GLenum e, GLenum f, GLenum g, GLboolean h, GLboolean i, GLboolean j) {
	m_pglex->glCombinerOutputNV(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glFinalCombinerInputNV(GLenum a, GLenum b, GLenum c, GLenum d) {
	m_pglex->glFinalCombinerInputNV(a,b,c,d);
}

inline void glex::glGetCombinerInputParameterfvNV(GLenum a, GLenum b, GLenum c, GLenum d, GLfloat *e) {
	m_pglex->glGetCombinerInputParameterfvNV(a,b,c,d,e);
}

inline void glex::glGetCombinerInputParameterivNV(GLenum a, GLenum b, GLenum c, GLenum d, GLint *e) {
	m_pglex->glGetCombinerInputParameterivNV(a,b,c,d,e);
}

inline void glex::glGetCombinerOutputParameterfvNV(GLenum a, GLenum b, GLenum c, GLfloat *d) {
	m_pglex->glGetCombinerOutputParameterfvNV(a,b,c,d);
}

inline void glex::glGetCombinerOutputParameterivNV(GLenum a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetCombinerOutputParameterivNV(a,b,c,d);
}

inline void glex::glGetFinalCombinerInputParameterfvNV(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetFinalCombinerInputParameterfvNV(a,b,c);
}

inline void glex::glGetFinalCombinerInputParameterivNV(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetFinalCombinerInputParameterivNV(a,b,c);
}

inline void glex::glResizeBuffersMESA(void) {
	m_pglex->glResizeBuffersMESA();
}

inline void glex::glWindowPos2dMESA(GLdouble a, GLdouble b) {
	m_pglex->glWindowPos2dMESA(a,b);
}

inline void glex::glWindowPos2dvMESA(const GLdouble *a) {
	m_pglex->glWindowPos2dvMESA(a);
}

inline void glex::glWindowPos2fMESA(GLfloat a, GLfloat b) {
	m_pglex->glWindowPos2fMESA(a,b);
}

inline void glex::glWindowPos2fvMESA(const GLfloat *a) {
	m_pglex->glWindowPos2fvMESA(a);
}

inline void glex::glWindowPos2iMESA(GLint a, GLint b) {
	m_pglex->glWindowPos2iMESA(a,b);
}

inline void glex::glWindowPos2ivMESA(const GLint *a) {
	m_pglex->glWindowPos2ivMESA(a);
}

inline void glex::glWindowPos2sMESA(GLshort a, GLshort b) {
	m_pglex->glWindowPos2sMESA(a,b);
}

inline void glex::glWindowPos2svMESA(const GLshort *a) {
	m_pglex->glWindowPos2svMESA(a);
}

inline void glex::glWindowPos3dMESA(GLdouble a, GLdouble b, GLdouble c) {
	m_pglex->glWindowPos3dMESA(a,b,c);
}

inline void glex::glWindowPos3dvMESA(const GLdouble *a) {
	m_pglex->glWindowPos3dvMESA(a);
}

inline void glex::glWindowPos3fMESA(GLfloat a, GLfloat b, GLfloat c) {
	m_pglex->glWindowPos3fMESA(a,b,c);
}

inline void glex::glWindowPos3fvMESA(const GLfloat *a) {
	m_pglex->glWindowPos3fvMESA(a);
}

inline void glex::glWindowPos3iMESA(GLint a, GLint b, GLint c) {
	m_pglex->glWindowPos3iMESA(a,b,c);
}

inline void glex::glWindowPos3ivMESA(const GLint *a) {
	m_pglex->glWindowPos3ivMESA(a);
}

inline void glex::glWindowPos3sMESA(GLshort a, GLshort b, GLshort c) {
	m_pglex->glWindowPos3sMESA(a,b,c);
}

inline void glex::glWindowPos3svMESA(const GLshort *a) {
	m_pglex->glWindowPos3svMESA(a);
}

inline void glex::glWindowPos4dMESA(GLdouble a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glWindowPos4dMESA(a,b,c,d);
}

inline void glex::glWindowPos4dvMESA(const GLdouble *a) {
	m_pglex->glWindowPos4dvMESA(a);
}

inline void glex::glWindowPos4fMESA(GLfloat a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glWindowPos4fMESA(a,b,c,d);
}

inline void glex::glWindowPos4fvMESA(const GLfloat *a) {
	m_pglex->glWindowPos4fvMESA(a);
}

inline void glex::glWindowPos4iMESA(GLint a, GLint b, GLint c, GLint d) {
	m_pglex->glWindowPos4iMESA(a,b,c,d);
}

inline void glex::glWindowPos4ivMESA(const GLint *a) {
	m_pglex->glWindowPos4ivMESA(a);
}

inline void glex::glWindowPos4sMESA(GLshort a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glWindowPos4sMESA(a,b,c,d);
}

inline void glex::glWindowPos4svMESA(const GLshort *a) {
	m_pglex->glWindowPos4svMESA(a);
}

inline void glex::glMultiModeDrawArraysIBM(const GLenum *a, const GLint *b, const GLsizei *c, GLsizei d, GLint e) {
	m_pglex->glMultiModeDrawArraysIBM(a,b,c,d,e);
}

inline void glex::glMultiModeDrawElementsIBM(const GLenum *a, const GLsizei *b, GLenum c, const GLvoid* const *d, GLsizei e, GLint f) {
	m_pglex->glMultiModeDrawElementsIBM(a,b,c,d,e,f);
}

inline void glex::glColorPointerListIBM(GLint a, GLenum b, GLint c, const GLvoid* *d, GLint e) {
	m_pglex->glColorPointerListIBM(a,b,c,d,e);
}

inline void glex::glSecondaryColorPointerListIBM(GLint a, GLenum b, GLint c, const GLvoid* *d, GLint e) {
	m_pglex->glSecondaryColorPointerListIBM(a,b,c,d,e);
}

inline void glex::glEdgeFlagPointerListIBM(GLint a, const GLboolean* *b, GLint c) {
	m_pglex->glEdgeFlagPointerListIBM(a,b,c);
}

inline void glex::glFogCoordPointerListIBM(GLenum a, GLint b, const GLvoid* *c, GLint d) {
	m_pglex->glFogCoordPointerListIBM(a,b,c,d);
}

inline void glex::glIndexPointerListIBM(GLenum a, GLint b, const GLvoid* *c, GLint d) {
	m_pglex->glIndexPointerListIBM(a,b,c,d);
}

inline void glex::glNormalPointerListIBM(GLenum a, GLint b, const GLvoid* *c, GLint d) {
	m_pglex->glNormalPointerListIBM(a,b,c,d);
}

inline void glex::glTexCoordPointerListIBM(GLint a, GLenum b, GLint c, const GLvoid* *d, GLint e) {
	m_pglex->glTexCoordPointerListIBM(a,b,c,d,e);
}

inline void glex::glVertexPointerListIBM(GLint a, GLenum b, GLint c, const GLvoid* *d, GLint e) {
	m_pglex->glVertexPointerListIBM(a,b,c,d,e);
}

inline void glex::glTbufferMask3DFX(GLuint a) {
	m_pglex->glTbufferMask3DFX(a);
}

inline void glex::glSampleMaskEXT(GLclampf a, GLboolean b) {
	m_pglex->glSampleMaskEXT(a,b);
}

inline void glex::glSamplePatternEXT(GLenum a) {
	m_pglex->glSamplePatternEXT(a);
}

inline void glex::glTextureColorMaskSGIS(GLboolean a, GLboolean b, GLboolean c, GLboolean d) {
	m_pglex->glTextureColorMaskSGIS(a,b,c,d);
}

inline void glex::glIglooInterfaceSGIX(GLenum a, const GLvoid *b) {
	m_pglex->glIglooInterfaceSGIX(a,b);
}

inline void glex::glDeleteFencesNV(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteFencesNV(a,b);
}

inline void glex::glGenFencesNV(GLsizei a, GLuint *b) {
	m_pglex->glGenFencesNV(a,b);
}

inline GLboolean glex::glIsFenceNV(GLuint a) {
	return m_pglex->glIsFenceNV(a);
}

inline GLboolean glex::glTestFenceNV(GLuint a) {
	return m_pglex->glTestFenceNV(a);
}

inline void glex::glGetFenceivNV(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetFenceivNV(a,b,c);
}

inline void glex::glFinishFenceNV(GLuint a) {
	m_pglex->glFinishFenceNV(a);
}

inline void glex::glSetFenceNV(GLuint a, GLenum b) {
	m_pglex->glSetFenceNV(a,b);
}

inline void glex::glMapControlPointsNV(GLenum a, GLuint b, GLenum c, GLsizei d, GLsizei e, GLint f, GLint g, GLboolean h, const GLvoid *i) {
	m_pglex->glMapControlPointsNV(a,b,c,d,e,f,g,h,i);
}

inline void glex::glMapParameterivNV(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glMapParameterivNV(a,b,c);
}

inline void glex::glMapParameterfvNV(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glMapParameterfvNV(a,b,c);
}

inline void glex::glGetMapControlPointsNV(GLenum a, GLuint b, GLenum c, GLsizei d, GLsizei e, GLboolean f, GLvoid *g) {
	m_pglex->glGetMapControlPointsNV(a,b,c,d,e,f,g);
}

inline void glex::glGetMapParameterivNV(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetMapParameterivNV(a,b,c);
}

inline void glex::glGetMapParameterfvNV(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetMapParameterfvNV(a,b,c);
}

inline void glex::glGetMapAttribParameterivNV(GLenum a, GLuint b, GLenum c, GLint *d) {
	m_pglex->glGetMapAttribParameterivNV(a,b,c,d);
}

inline void glex::glGetMapAttribParameterfvNV(GLenum a, GLuint b, GLenum c, GLfloat *d) {
	m_pglex->glGetMapAttribParameterfvNV(a,b,c,d);
}

inline void glex::glEvalMapsNV(GLenum a, GLenum b) {
	m_pglex->glEvalMapsNV(a,b);
}

inline void glex::glCombinerStageParameterfvNV(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glCombinerStageParameterfvNV(a,b,c);
}

inline void glex::glGetCombinerStageParameterfvNV(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetCombinerStageParameterfvNV(a,b,c);
}

inline GLboolean glex::glAreProgramsResidentNV(GLsizei a, const GLuint *b, GLboolean *c) {
	return m_pglex->glAreProgramsResidentNV(a,b,c);
}

inline void glex::glBindProgramNV(GLenum a, GLuint b) {
	m_pglex->glBindProgramNV(a,b);
}

inline void glex::glDeleteProgramsNV(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteProgramsNV(a,b);
}

inline void glex::glExecuteProgramNV(GLenum a, GLuint b, const GLfloat *c) {
	m_pglex->glExecuteProgramNV(a,b,c);
}

inline void glex::glGenProgramsNV(GLsizei a, GLuint *b) {
	m_pglex->glGenProgramsNV(a,b);
}

inline void glex::glGetProgramParameterdvNV(GLenum a, GLuint b, GLenum c, GLdouble *d) {
	m_pglex->glGetProgramParameterdvNV(a,b,c,d);
}

inline void glex::glGetProgramParameterfvNV(GLenum a, GLuint b, GLenum c, GLfloat *d) {
	m_pglex->glGetProgramParameterfvNV(a,b,c,d);
}

inline void glex::glGetProgramivNV(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetProgramivNV(a,b,c);
}

inline void glex::glGetProgramStringNV(GLuint a, GLenum b, GLubyte *c) {
	m_pglex->glGetProgramStringNV(a,b,c);
}

inline void glex::glGetTrackMatrixivNV(GLenum a, GLuint b, GLenum c, GLint *d) {
	m_pglex->glGetTrackMatrixivNV(a,b,c,d);
}

inline void glex::glGetVertexAttribdvNV(GLuint a, GLenum b, GLdouble *c) {
	m_pglex->glGetVertexAttribdvNV(a,b,c);
}

inline void glex::glGetVertexAttribfvNV(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetVertexAttribfvNV(a,b,c);
}

inline void glex::glGetVertexAttribivNV(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVertexAttribivNV(a,b,c);
}

inline void glex::glGetVertexAttribPointervNV(GLuint a, GLenum b, GLvoid* *c) {
	m_pglex->glGetVertexAttribPointervNV(a,b,c);
}

inline GLboolean glex::glIsProgramNV(GLuint a) {
	return m_pglex->glIsProgramNV(a);
}

inline void glex::glLoadProgramNV(GLenum a, GLuint b, GLsizei c, const GLubyte *d) {
	m_pglex->glLoadProgramNV(a,b,c,d);
}

inline void glex::glProgramParameter4dNV(GLenum a, GLuint b, GLdouble c, GLdouble d, GLdouble e, GLdouble f) {
	m_pglex->glProgramParameter4dNV(a,b,c,d,e,f);
}

inline void glex::glProgramParameter4dvNV(GLenum a, GLuint b, const GLdouble *c) {
	m_pglex->glProgramParameter4dvNV(a,b,c);
}

inline void glex::glProgramParameter4fNV(GLenum a, GLuint b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glProgramParameter4fNV(a,b,c,d,e,f);
}

inline void glex::glProgramParameter4fvNV(GLenum a, GLuint b, const GLfloat *c) {
	m_pglex->glProgramParameter4fvNV(a,b,c);
}

inline void glex::glProgramParameters4dvNV(GLenum a, GLuint b, GLsizei c, const GLdouble *d) {
	m_pglex->glProgramParameters4dvNV(a,b,c,d);
}

inline void glex::glProgramParameters4fvNV(GLenum a, GLuint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramParameters4fvNV(a,b,c,d);
}

inline void glex::glRequestResidentProgramsNV(GLsizei a, const GLuint *b) {
	m_pglex->glRequestResidentProgramsNV(a,b);
}

inline void glex::glTrackMatrixNV(GLenum a, GLuint b, GLenum c, GLenum d) {
	m_pglex->glTrackMatrixNV(a,b,c,d);
}

inline void glex::glVertexAttribPointerNV(GLuint a, GLint b, GLenum c, GLsizei d, const GLvoid *e) {
	m_pglex->glVertexAttribPointerNV(a,b,c,d,e);
}

inline void glex::glVertexAttrib1dNV(GLuint a, GLdouble b) {
	m_pglex->glVertexAttrib1dNV(a,b);
}

inline void glex::glVertexAttrib1dvNV(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib1dvNV(a,b);
}

inline void glex::glVertexAttrib1fNV(GLuint a, GLfloat b) {
	m_pglex->glVertexAttrib1fNV(a,b);
}

inline void glex::glVertexAttrib1fvNV(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib1fvNV(a,b);
}

inline void glex::glVertexAttrib1sNV(GLuint a, GLshort b) {
	m_pglex->glVertexAttrib1sNV(a,b);
}

inline void glex::glVertexAttrib1svNV(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib1svNV(a,b);
}

inline void glex::glVertexAttrib2dNV(GLuint a, GLdouble b, GLdouble c) {
	m_pglex->glVertexAttrib2dNV(a,b,c);
}

inline void glex::glVertexAttrib2dvNV(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib2dvNV(a,b);
}

inline void glex::glVertexAttrib2fNV(GLuint a, GLfloat b, GLfloat c) {
	m_pglex->glVertexAttrib2fNV(a,b,c);
}

inline void glex::glVertexAttrib2fvNV(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib2fvNV(a,b);
}

inline void glex::glVertexAttrib2sNV(GLuint a, GLshort b, GLshort c) {
	m_pglex->glVertexAttrib2sNV(a,b,c);
}

inline void glex::glVertexAttrib2svNV(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib2svNV(a,b);
}

inline void glex::glVertexAttrib3dNV(GLuint a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glVertexAttrib3dNV(a,b,c,d);
}

inline void glex::glVertexAttrib3dvNV(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib3dvNV(a,b);
}

inline void glex::glVertexAttrib3fNV(GLuint a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glVertexAttrib3fNV(a,b,c,d);
}

inline void glex::glVertexAttrib3fvNV(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib3fvNV(a,b);
}

inline void glex::glVertexAttrib3sNV(GLuint a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glVertexAttrib3sNV(a,b,c,d);
}

inline void glex::glVertexAttrib3svNV(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib3svNV(a,b);
}

inline void glex::glVertexAttrib4dNV(GLuint a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glVertexAttrib4dNV(a,b,c,d,e);
}

inline void glex::glVertexAttrib4dvNV(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib4dvNV(a,b);
}

inline void glex::glVertexAttrib4fNV(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glVertexAttrib4fNV(a,b,c,d,e);
}

inline void glex::glVertexAttrib4fvNV(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib4fvNV(a,b);
}

inline void glex::glVertexAttrib4sNV(GLuint a, GLshort b, GLshort c, GLshort d, GLshort e) {
	m_pglex->glVertexAttrib4sNV(a,b,c,d,e);
}

inline void glex::glVertexAttrib4svNV(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib4svNV(a,b);
}

inline void glex::glVertexAttrib4ubNV(GLuint a, GLubyte b, GLubyte c, GLubyte d, GLubyte e) {
	m_pglex->glVertexAttrib4ubNV(a,b,c,d,e);
}

inline void glex::glVertexAttrib4ubvNV(GLuint a, const GLubyte *b) {
	m_pglex->glVertexAttrib4ubvNV(a,b);
}

inline void glex::glVertexAttribs1dvNV(GLuint a, GLsizei b, const GLdouble *c) {
	m_pglex->glVertexAttribs1dvNV(a,b,c);
}

inline void glex::glVertexAttribs1fvNV(GLuint a, GLsizei b, const GLfloat *c) {
	m_pglex->glVertexAttribs1fvNV(a,b,c);
}

inline void glex::glVertexAttribs1svNV(GLuint a, GLsizei b, const GLshort *c) {
	m_pglex->glVertexAttribs1svNV(a,b,c);
}

inline void glex::glVertexAttribs2dvNV(GLuint a, GLsizei b, const GLdouble *c) {
	m_pglex->glVertexAttribs2dvNV(a,b,c);
}

inline void glex::glVertexAttribs2fvNV(GLuint a, GLsizei b, const GLfloat *c) {
	m_pglex->glVertexAttribs2fvNV(a,b,c);
}

inline void glex::glVertexAttribs2svNV(GLuint a, GLsizei b, const GLshort *c) {
	m_pglex->glVertexAttribs2svNV(a,b,c);
}

inline void glex::glVertexAttribs3dvNV(GLuint a, GLsizei b, const GLdouble *c) {
	m_pglex->glVertexAttribs3dvNV(a,b,c);
}

inline void glex::glVertexAttribs3fvNV(GLuint a, GLsizei b, const GLfloat *c) {
	m_pglex->glVertexAttribs3fvNV(a,b,c);
}

inline void glex::glVertexAttribs3svNV(GLuint a, GLsizei b, const GLshort *c) {
	m_pglex->glVertexAttribs3svNV(a,b,c);
}

inline void glex::glVertexAttribs4dvNV(GLuint a, GLsizei b, const GLdouble *c) {
	m_pglex->glVertexAttribs4dvNV(a,b,c);
}

inline void glex::glVertexAttribs4fvNV(GLuint a, GLsizei b, const GLfloat *c) {
	m_pglex->glVertexAttribs4fvNV(a,b,c);
}

inline void glex::glVertexAttribs4svNV(GLuint a, GLsizei b, const GLshort *c) {
	m_pglex->glVertexAttribs4svNV(a,b,c);
}

inline void glex::glVertexAttribs4ubvNV(GLuint a, GLsizei b, const GLubyte *c) {
	m_pglex->glVertexAttribs4ubvNV(a,b,c);
}

inline void glex::glTexBumpParameterivATI(GLenum a, const GLint *b) {
	m_pglex->glTexBumpParameterivATI(a,b);
}

inline void glex::glTexBumpParameterfvATI(GLenum a, const GLfloat *b) {
	m_pglex->glTexBumpParameterfvATI(a,b);
}

inline void glex::glGetTexBumpParameterivATI(GLenum a, GLint *b) {
	m_pglex->glGetTexBumpParameterivATI(a,b);
}

inline void glex::glGetTexBumpParameterfvATI(GLenum a, GLfloat *b) {
	m_pglex->glGetTexBumpParameterfvATI(a,b);
}

inline GLuint glex::glGenFragmentShadersATI(GLuint a) {
	return m_pglex->glGenFragmentShadersATI(a);
}

inline void glex::glBindFragmentShaderATI(GLuint a) {
	m_pglex->glBindFragmentShaderATI(a);
}

inline void glex::glDeleteFragmentShaderATI(GLuint a) {
	m_pglex->glDeleteFragmentShaderATI(a);
}

inline void glex::glBeginFragmentShaderATI(void) {
	m_pglex->glBeginFragmentShaderATI();
}

inline void glex::glEndFragmentShaderATI(void) {
	m_pglex->glEndFragmentShaderATI();
}

inline void glex::glPassTexCoordATI(GLuint a, GLuint b, GLenum c) {
	m_pglex->glPassTexCoordATI(a,b,c);
}

inline void glex::glSampleMapATI(GLuint a, GLuint b, GLenum c) {
	m_pglex->glSampleMapATI(a,b,c);
}

inline void glex::glColorFragmentOp1ATI(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f, GLuint g) {
	m_pglex->glColorFragmentOp1ATI(a,b,c,d,e,f,g);
}

inline void glex::glColorFragmentOp2ATI(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f, GLuint g, GLuint h, GLuint i, GLuint j) {
	m_pglex->glColorFragmentOp2ATI(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glColorFragmentOp3ATI(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f, GLuint g, GLuint h, GLuint i, GLuint j, GLuint k, GLuint l, GLuint m) {
	m_pglex->glColorFragmentOp3ATI(a,b,c,d,e,f,g,h,i,j,k,l,m);
}

inline void glex::glAlphaFragmentOp1ATI(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f) {
	m_pglex->glAlphaFragmentOp1ATI(a,b,c,d,e,f);
}

inline void glex::glAlphaFragmentOp2ATI(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f, GLuint g, GLuint h, GLuint i) {
	m_pglex->glAlphaFragmentOp2ATI(a,b,c,d,e,f,g,h,i);
}

inline void glex::glAlphaFragmentOp3ATI(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f, GLuint g, GLuint h, GLuint i, GLuint j, GLuint k, GLuint l) {
	m_pglex->glAlphaFragmentOp3ATI(a,b,c,d,e,f,g,h,i,j,k,l);
}

inline void glex::glSetFragmentShaderConstantATI(GLuint a, const GLfloat *b) {
	m_pglex->glSetFragmentShaderConstantATI(a,b);
}

inline void glex::glPNTrianglesiATI(GLenum a, GLint b) {
	m_pglex->glPNTrianglesiATI(a,b);
}

inline void glex::glPNTrianglesfATI(GLenum a, GLfloat b) {
	m_pglex->glPNTrianglesfATI(a,b);
}

inline GLuint glex::glNewObjectBufferATI(GLsizei a, const GLvoid *b, GLenum c) {
	return m_pglex->glNewObjectBufferATI(a,b,c);
}

inline GLboolean glex::glIsObjectBufferATI(GLuint a) {
	return m_pglex->glIsObjectBufferATI(a);
}

inline void glex::glUpdateObjectBufferATI(GLuint a, GLuint b, GLsizei c, const GLvoid *d, GLenum e) {
	m_pglex->glUpdateObjectBufferATI(a,b,c,d,e);
}

inline void glex::glGetObjectBufferfvATI(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetObjectBufferfvATI(a,b,c);
}

inline void glex::glGetObjectBufferivATI(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetObjectBufferivATI(a,b,c);
}

inline void glex::glFreeObjectBufferATI(GLuint a) {
	m_pglex->glFreeObjectBufferATI(a);
}

inline void glex::glArrayObjectATI(GLenum a, GLint b, GLenum c, GLsizei d, GLuint e, GLuint f) {
	m_pglex->glArrayObjectATI(a,b,c,d,e,f);
}

inline void glex::glGetArrayObjectfvATI(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetArrayObjectfvATI(a,b,c);
}

inline void glex::glGetArrayObjectivATI(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetArrayObjectivATI(a,b,c);
}

inline void glex::glVariantArrayObjectATI(GLuint a, GLenum b, GLsizei c, GLuint d, GLuint e) {
	m_pglex->glVariantArrayObjectATI(a,b,c,d,e);
}

inline void glex::glGetVariantArrayObjectfvATI(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetVariantArrayObjectfvATI(a,b,c);
}

inline void glex::glGetVariantArrayObjectivATI(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVariantArrayObjectivATI(a,b,c);
}

inline void glex::glBeginVertexShaderEXT(void) {
	m_pglex->glBeginVertexShaderEXT();
}

inline void glex::glEndVertexShaderEXT(void) {
	m_pglex->glEndVertexShaderEXT();
}

inline void glex::glBindVertexShaderEXT(GLuint a) {
	m_pglex->glBindVertexShaderEXT(a);
}

inline GLuint glex::glGenVertexShadersEXT(GLuint a) {
	return m_pglex->glGenVertexShadersEXT(a);
}

inline void glex::glDeleteVertexShaderEXT(GLuint a) {
	m_pglex->glDeleteVertexShaderEXT(a);
}

inline void glex::glShaderOp1EXT(GLenum a, GLuint b, GLuint c) {
	m_pglex->glShaderOp1EXT(a,b,c);
}

inline void glex::glShaderOp2EXT(GLenum a, GLuint b, GLuint c, GLuint d) {
	m_pglex->glShaderOp2EXT(a,b,c,d);
}

inline void glex::glShaderOp3EXT(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e) {
	m_pglex->glShaderOp3EXT(a,b,c,d,e);
}

inline void glex::glSwizzleEXT(GLuint a, GLuint b, GLenum c, GLenum d, GLenum e, GLenum f) {
	m_pglex->glSwizzleEXT(a,b,c,d,e,f);
}

inline void glex::glWriteMaskEXT(GLuint a, GLuint b, GLenum c, GLenum d, GLenum e, GLenum f) {
	m_pglex->glWriteMaskEXT(a,b,c,d,e,f);
}

inline void glex::glInsertComponentEXT(GLuint a, GLuint b, GLuint c) {
	m_pglex->glInsertComponentEXT(a,b,c);
}

inline void glex::glExtractComponentEXT(GLuint a, GLuint b, GLuint c) {
	m_pglex->glExtractComponentEXT(a,b,c);
}

inline GLuint glex::glGenSymbolsEXT(GLenum a, GLenum b, GLenum c, GLuint d) {
	return m_pglex->glGenSymbolsEXT(a,b,c,d);
}

inline void glex::glSetInvariantEXT(GLuint a, GLenum b, const GLvoid *c) {
	m_pglex->glSetInvariantEXT(a,b,c);
}

inline void glex::glSetLocalConstantEXT(GLuint a, GLenum b, const GLvoid *c) {
	m_pglex->glSetLocalConstantEXT(a,b,c);
}

inline void glex::glVariantbvEXT(GLuint a, const GLbyte *b) {
	m_pglex->glVariantbvEXT(a,b);
}

inline void glex::glVariantsvEXT(GLuint a, const GLshort *b) {
	m_pglex->glVariantsvEXT(a,b);
}

inline void glex::glVariantivEXT(GLuint a, const GLint *b) {
	m_pglex->glVariantivEXT(a,b);
}

inline void glex::glVariantfvEXT(GLuint a, const GLfloat *b) {
	m_pglex->glVariantfvEXT(a,b);
}

inline void glex::glVariantdvEXT(GLuint a, const GLdouble *b) {
	m_pglex->glVariantdvEXT(a,b);
}

inline void glex::glVariantubvEXT(GLuint a, const GLubyte *b) {
	m_pglex->glVariantubvEXT(a,b);
}

inline void glex::glVariantusvEXT(GLuint a, const GLushort *b) {
	m_pglex->glVariantusvEXT(a,b);
}

inline void glex::glVariantuivEXT(GLuint a, const GLuint *b) {
	m_pglex->glVariantuivEXT(a,b);
}

inline void glex::glVariantPointerEXT(GLuint a, GLenum b, GLuint c, const GLvoid *d) {
	m_pglex->glVariantPointerEXT(a,b,c,d);
}

inline void glex::glEnableVariantClientStateEXT(GLuint a) {
	m_pglex->glEnableVariantClientStateEXT(a);
}

inline void glex::glDisableVariantClientStateEXT(GLuint a) {
	m_pglex->glDisableVariantClientStateEXT(a);
}

inline GLuint glex::glBindLightParameterEXT(GLenum a, GLenum b) {
	return m_pglex->glBindLightParameterEXT(a,b);
}

inline GLuint glex::glBindMaterialParameterEXT(GLenum a, GLenum b) {
	return m_pglex->glBindMaterialParameterEXT(a,b);
}

inline GLuint glex::glBindTexGenParameterEXT(GLenum a, GLenum b, GLenum c) {
	return m_pglex->glBindTexGenParameterEXT(a,b,c);
}

inline GLuint glex::glBindTextureUnitParameterEXT(GLenum a, GLenum b) {
	return m_pglex->glBindTextureUnitParameterEXT(a,b);
}

inline GLuint glex::glBindParameterEXT(GLenum a) {
	return m_pglex->glBindParameterEXT(a);
}

inline GLboolean glex::glIsVariantEnabledEXT(GLuint a, GLenum b) {
	return m_pglex->glIsVariantEnabledEXT(a,b);
}

inline void glex::glGetVariantBooleanvEXT(GLuint a, GLenum b, GLboolean *c) {
	m_pglex->glGetVariantBooleanvEXT(a,b,c);
}

inline void glex::glGetVariantIntegervEXT(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVariantIntegervEXT(a,b,c);
}

inline void glex::glGetVariantFloatvEXT(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetVariantFloatvEXT(a,b,c);
}

inline void glex::glGetVariantPointervEXT(GLuint a, GLenum b, GLvoid* *c) {
	m_pglex->glGetVariantPointervEXT(a,b,c);
}

inline void glex::glGetInvariantBooleanvEXT(GLuint a, GLenum b, GLboolean *c) {
	m_pglex->glGetInvariantBooleanvEXT(a,b,c);
}

inline void glex::glGetInvariantIntegervEXT(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetInvariantIntegervEXT(a,b,c);
}

inline void glex::glGetInvariantFloatvEXT(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetInvariantFloatvEXT(a,b,c);
}

inline void glex::glGetLocalConstantBooleanvEXT(GLuint a, GLenum b, GLboolean *c) {
	m_pglex->glGetLocalConstantBooleanvEXT(a,b,c);
}

inline void glex::glGetLocalConstantIntegervEXT(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetLocalConstantIntegervEXT(a,b,c);
}

inline void glex::glGetLocalConstantFloatvEXT(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetLocalConstantFloatvEXT(a,b,c);
}

inline void glex::glVertexStream1sATI(GLenum a, GLshort b) {
	m_pglex->glVertexStream1sATI(a,b);
}

inline void glex::glVertexStream1svATI(GLenum a, const GLshort *b) {
	m_pglex->glVertexStream1svATI(a,b);
}

inline void glex::glVertexStream1iATI(GLenum a, GLint b) {
	m_pglex->glVertexStream1iATI(a,b);
}

inline void glex::glVertexStream1ivATI(GLenum a, const GLint *b) {
	m_pglex->glVertexStream1ivATI(a,b);
}

inline void glex::glVertexStream1fATI(GLenum a, GLfloat b) {
	m_pglex->glVertexStream1fATI(a,b);
}

inline void glex::glVertexStream1fvATI(GLenum a, const GLfloat *b) {
	m_pglex->glVertexStream1fvATI(a,b);
}

inline void glex::glVertexStream1dATI(GLenum a, GLdouble b) {
	m_pglex->glVertexStream1dATI(a,b);
}

inline void glex::glVertexStream1dvATI(GLenum a, const GLdouble *b) {
	m_pglex->glVertexStream1dvATI(a,b);
}

inline void glex::glVertexStream2sATI(GLenum a, GLshort b, GLshort c) {
	m_pglex->glVertexStream2sATI(a,b,c);
}

inline void glex::glVertexStream2svATI(GLenum a, const GLshort *b) {
	m_pglex->glVertexStream2svATI(a,b);
}

inline void glex::glVertexStream2iATI(GLenum a, GLint b, GLint c) {
	m_pglex->glVertexStream2iATI(a,b,c);
}

inline void glex::glVertexStream2ivATI(GLenum a, const GLint *b) {
	m_pglex->glVertexStream2ivATI(a,b);
}

inline void glex::glVertexStream2fATI(GLenum a, GLfloat b, GLfloat c) {
	m_pglex->glVertexStream2fATI(a,b,c);
}

inline void glex::glVertexStream2fvATI(GLenum a, const GLfloat *b) {
	m_pglex->glVertexStream2fvATI(a,b);
}

inline void glex::glVertexStream2dATI(GLenum a, GLdouble b, GLdouble c) {
	m_pglex->glVertexStream2dATI(a,b,c);
}

inline void glex::glVertexStream2dvATI(GLenum a, const GLdouble *b) {
	m_pglex->glVertexStream2dvATI(a,b);
}

inline void glex::glVertexStream3sATI(GLenum a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glVertexStream3sATI(a,b,c,d);
}

inline void glex::glVertexStream3svATI(GLenum a, const GLshort *b) {
	m_pglex->glVertexStream3svATI(a,b);
}

inline void glex::glVertexStream3iATI(GLenum a, GLint b, GLint c, GLint d) {
	m_pglex->glVertexStream3iATI(a,b,c,d);
}

inline void glex::glVertexStream3ivATI(GLenum a, const GLint *b) {
	m_pglex->glVertexStream3ivATI(a,b);
}

inline void glex::glVertexStream3fATI(GLenum a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glVertexStream3fATI(a,b,c,d);
}

inline void glex::glVertexStream3fvATI(GLenum a, const GLfloat *b) {
	m_pglex->glVertexStream3fvATI(a,b);
}

inline void glex::glVertexStream3dATI(GLenum a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glVertexStream3dATI(a,b,c,d);
}

inline void glex::glVertexStream3dvATI(GLenum a, const GLdouble *b) {
	m_pglex->glVertexStream3dvATI(a,b);
}

inline void glex::glVertexStream4sATI(GLenum a, GLshort b, GLshort c, GLshort d, GLshort e) {
	m_pglex->glVertexStream4sATI(a,b,c,d,e);
}

inline void glex::glVertexStream4svATI(GLenum a, const GLshort *b) {
	m_pglex->glVertexStream4svATI(a,b);
}

inline void glex::glVertexStream4iATI(GLenum a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glVertexStream4iATI(a,b,c,d,e);
}

inline void glex::glVertexStream4ivATI(GLenum a, const GLint *b) {
	m_pglex->glVertexStream4ivATI(a,b);
}

inline void glex::glVertexStream4fATI(GLenum a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glVertexStream4fATI(a,b,c,d,e);
}

inline void glex::glVertexStream4fvATI(GLenum a, const GLfloat *b) {
	m_pglex->glVertexStream4fvATI(a,b);
}

inline void glex::glVertexStream4dATI(GLenum a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glVertexStream4dATI(a,b,c,d,e);
}

inline void glex::glVertexStream4dvATI(GLenum a, const GLdouble *b) {
	m_pglex->glVertexStream4dvATI(a,b);
}

inline void glex::glNormalStream3bATI(GLenum a, GLbyte b, GLbyte c, GLbyte d) {
	m_pglex->glNormalStream3bATI(a,b,c,d);
}

inline void glex::glNormalStream3bvATI(GLenum a, const GLbyte *b) {
	m_pglex->glNormalStream3bvATI(a,b);
}

inline void glex::glNormalStream3sATI(GLenum a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glNormalStream3sATI(a,b,c,d);
}

inline void glex::glNormalStream3svATI(GLenum a, const GLshort *b) {
	m_pglex->glNormalStream3svATI(a,b);
}

inline void glex::glNormalStream3iATI(GLenum a, GLint b, GLint c, GLint d) {
	m_pglex->glNormalStream3iATI(a,b,c,d);
}

inline void glex::glNormalStream3ivATI(GLenum a, const GLint *b) {
	m_pglex->glNormalStream3ivATI(a,b);
}

inline void glex::glNormalStream3fATI(GLenum a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glNormalStream3fATI(a,b,c,d);
}

inline void glex::glNormalStream3fvATI(GLenum a, const GLfloat *b) {
	m_pglex->glNormalStream3fvATI(a,b);
}

inline void glex::glNormalStream3dATI(GLenum a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glNormalStream3dATI(a,b,c,d);
}

inline void glex::glNormalStream3dvATI(GLenum a, const GLdouble *b) {
	m_pglex->glNormalStream3dvATI(a,b);
}

inline void glex::glClientActiveVertexStreamATI(GLenum a) {
	m_pglex->glClientActiveVertexStreamATI(a);
}

inline void glex::glVertexBlendEnviATI(GLenum a, GLint b) {
	m_pglex->glVertexBlendEnviATI(a,b);
}

inline void glex::glVertexBlendEnvfATI(GLenum a, GLfloat b) {
	m_pglex->glVertexBlendEnvfATI(a,b);
}

inline void glex::glElementPointerATI(GLenum a, const GLvoid *b) {
	m_pglex->glElementPointerATI(a,b);
}

inline void glex::glDrawElementArrayATI(GLenum a, GLsizei b) {
	m_pglex->glDrawElementArrayATI(a,b);
}

inline void glex::glDrawRangeElementArrayATI(GLenum a, GLuint b, GLuint c, GLsizei d) {
	m_pglex->glDrawRangeElementArrayATI(a,b,c,d);
}

inline void glex::glDrawMeshArraysSUN(GLenum a, GLint b, GLsizei c, GLsizei d) {
	m_pglex->glDrawMeshArraysSUN(a,b,c,d);
}

inline void glex::glGenOcclusionQueriesNV(GLsizei a, GLuint *b) {
	m_pglex->glGenOcclusionQueriesNV(a,b);
}

inline void glex::glDeleteOcclusionQueriesNV(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteOcclusionQueriesNV(a,b);
}

inline GLboolean glex::glIsOcclusionQueryNV(GLuint a) {
	return m_pglex->glIsOcclusionQueryNV(a);
}

inline void glex::glBeginOcclusionQueryNV(GLuint a) {
	m_pglex->glBeginOcclusionQueryNV(a);
}

inline void glex::glEndOcclusionQueryNV(void) {
	m_pglex->glEndOcclusionQueryNV();
}

inline void glex::glGetOcclusionQueryivNV(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetOcclusionQueryivNV(a,b,c);
}

inline void glex::glGetOcclusionQueryuivNV(GLuint a, GLenum b, GLuint *c) {
	m_pglex->glGetOcclusionQueryuivNV(a,b,c);
}

inline void glex::glPointParameteriNV(GLenum a, GLint b) {
	m_pglex->glPointParameteriNV(a,b);
}

inline void glex::glPointParameterivNV(GLenum a, const GLint *b) {
	m_pglex->glPointParameterivNV(a,b);
}

inline void glex::glActiveStencilFaceEXT(GLenum a) {
	m_pglex->glActiveStencilFaceEXT(a);
}

inline void glex::glElementPointerAPPLE(GLenum a, const GLvoid *b) {
	m_pglex->glElementPointerAPPLE(a,b);
}

inline void glex::glDrawElementArrayAPPLE(GLenum a, GLint b, GLsizei c) {
	m_pglex->glDrawElementArrayAPPLE(a,b,c);
}

inline void glex::glDrawRangeElementArrayAPPLE(GLenum a, GLuint b, GLuint c, GLint d, GLsizei e) {
	m_pglex->glDrawRangeElementArrayAPPLE(a,b,c,d,e);
}

inline void glex::glMultiDrawElementArrayAPPLE(GLenum a, const GLint *b, const GLsizei *c, GLsizei d) {
	m_pglex->glMultiDrawElementArrayAPPLE(a,b,c,d);
}

inline void glex::glMultiDrawRangeElementArrayAPPLE(GLenum a, GLuint b, GLuint c, const GLint *d, const GLsizei *e, GLsizei f) {
	m_pglex->glMultiDrawRangeElementArrayAPPLE(a,b,c,d,e,f);
}

inline void glex::glGenFencesAPPLE(GLsizei a, GLuint *b) {
	m_pglex->glGenFencesAPPLE(a,b);
}

inline void glex::glDeleteFencesAPPLE(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteFencesAPPLE(a,b);
}

inline void glex::glSetFenceAPPLE(GLuint a) {
	m_pglex->glSetFenceAPPLE(a);
}

inline GLboolean glex::glIsFenceAPPLE(GLuint a) {
	return m_pglex->glIsFenceAPPLE(a);
}

inline GLboolean glex::glTestFenceAPPLE(GLuint a) {
	return m_pglex->glTestFenceAPPLE(a);
}

inline void glex::glFinishFenceAPPLE(GLuint a) {
	m_pglex->glFinishFenceAPPLE(a);
}

inline GLboolean glex::glTestObjectAPPLE(GLenum a, GLuint b) {
	return m_pglex->glTestObjectAPPLE(a,b);
}

inline void glex::glFinishObjectAPPLE(GLenum a, GLint b) {
	m_pglex->glFinishObjectAPPLE(a,b);
}

inline void glex::glBindVertexArrayAPPLE(GLuint a) {
	m_pglex->glBindVertexArrayAPPLE(a);
}

inline void glex::glDeleteVertexArraysAPPLE(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteVertexArraysAPPLE(a,b);
}

inline void glex::glGenVertexArraysAPPLE(GLsizei a, GLuint *b) {
	m_pglex->glGenVertexArraysAPPLE(a,b);
}

inline GLboolean glex::glIsVertexArrayAPPLE(GLuint a) {
	return m_pglex->glIsVertexArrayAPPLE(a);
}

inline void glex::glVertexArrayRangeAPPLE(GLsizei a, GLvoid *b) {
	m_pglex->glVertexArrayRangeAPPLE(a,b);
}

inline void glex::glFlushVertexArrayRangeAPPLE(GLsizei a, GLvoid *b) {
	m_pglex->glFlushVertexArrayRangeAPPLE(a,b);
}

inline void glex::glVertexArrayParameteriAPPLE(GLenum a, GLint b) {
	m_pglex->glVertexArrayParameteriAPPLE(a,b);
}

inline void glex::glDrawBuffersATI(GLsizei a, const GLenum *b) {
	m_pglex->glDrawBuffersATI(a,b);
}

inline void glex::glProgramNamedParameter4fNV(GLuint a, GLsizei b, const GLubyte *c, GLfloat d, GLfloat e, GLfloat f, GLfloat g) {
	m_pglex->glProgramNamedParameter4fNV(a,b,c,d,e,f,g);
}

inline void glex::glProgramNamedParameter4dNV(GLuint a, GLsizei b, const GLubyte *c, GLdouble d, GLdouble e, GLdouble f, GLdouble g) {
	m_pglex->glProgramNamedParameter4dNV(a,b,c,d,e,f,g);
}

inline void glex::glProgramNamedParameter4fvNV(GLuint a, GLsizei b, const GLubyte *c, const GLfloat *d) {
	m_pglex->glProgramNamedParameter4fvNV(a,b,c,d);
}

inline void glex::glProgramNamedParameter4dvNV(GLuint a, GLsizei b, const GLubyte *c, const GLdouble *d) {
	m_pglex->glProgramNamedParameter4dvNV(a,b,c,d);
}

inline void glex::glGetProgramNamedParameterfvNV(GLuint a, GLsizei b, const GLubyte *c, GLfloat *d) {
	m_pglex->glGetProgramNamedParameterfvNV(a,b,c,d);
}

inline void glex::glGetProgramNamedParameterdvNV(GLuint a, GLsizei b, const GLubyte *c, GLdouble *d) {
	m_pglex->glGetProgramNamedParameterdvNV(a,b,c,d);
}

inline void glex::glVertex2hNV(GLhalfNV a, GLhalfNV b) {
	m_pglex->glVertex2hNV(a,b);
}

inline void glex::glVertex2hvNV(const GLhalfNV *a) {
	m_pglex->glVertex2hvNV(a);
}

inline void glex::glVertex3hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c) {
	m_pglex->glVertex3hNV(a,b,c);
}

inline void glex::glVertex3hvNV(const GLhalfNV *a) {
	m_pglex->glVertex3hvNV(a);
}

inline void glex::glVertex4hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c, GLhalfNV d) {
	m_pglex->glVertex4hNV(a,b,c,d);
}

inline void glex::glVertex4hvNV(const GLhalfNV *a) {
	m_pglex->glVertex4hvNV(a);
}

inline void glex::glNormal3hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c) {
	m_pglex->glNormal3hNV(a,b,c);
}

inline void glex::glNormal3hvNV(const GLhalfNV *a) {
	m_pglex->glNormal3hvNV(a);
}

inline void glex::glColor3hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c) {
	m_pglex->glColor3hNV(a,b,c);
}

inline void glex::glColor3hvNV(const GLhalfNV *a) {
	m_pglex->glColor3hvNV(a);
}

inline void glex::glColor4hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c, GLhalfNV d) {
	m_pglex->glColor4hNV(a,b,c,d);
}

inline void glex::glColor4hvNV(const GLhalfNV *a) {
	m_pglex->glColor4hvNV(a);
}

inline void glex::glTexCoord1hNV(GLhalfNV a) {
	m_pglex->glTexCoord1hNV(a);
}

inline void glex::glTexCoord1hvNV(const GLhalfNV *a) {
	m_pglex->glTexCoord1hvNV(a);
}

inline void glex::glTexCoord2hNV(GLhalfNV a, GLhalfNV b) {
	m_pglex->glTexCoord2hNV(a,b);
}

inline void glex::glTexCoord2hvNV(const GLhalfNV *a) {
	m_pglex->glTexCoord2hvNV(a);
}

inline void glex::glTexCoord3hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c) {
	m_pglex->glTexCoord3hNV(a,b,c);
}

inline void glex::glTexCoord3hvNV(const GLhalfNV *a) {
	m_pglex->glTexCoord3hvNV(a);
}

inline void glex::glTexCoord4hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c, GLhalfNV d) {
	m_pglex->glTexCoord4hNV(a,b,c,d);
}

inline void glex::glTexCoord4hvNV(const GLhalfNV *a) {
	m_pglex->glTexCoord4hvNV(a);
}

inline void glex::glMultiTexCoord1hNV(GLenum a, GLhalfNV b) {
	m_pglex->glMultiTexCoord1hNV(a,b);
}

inline void glex::glMultiTexCoord1hvNV(GLenum a, const GLhalfNV *b) {
	m_pglex->glMultiTexCoord1hvNV(a,b);
}

inline void glex::glMultiTexCoord2hNV(GLenum a, GLhalfNV b, GLhalfNV c) {
	m_pglex->glMultiTexCoord2hNV(a,b,c);
}

inline void glex::glMultiTexCoord2hvNV(GLenum a, const GLhalfNV *b) {
	m_pglex->glMultiTexCoord2hvNV(a,b);
}

inline void glex::glMultiTexCoord3hNV(GLenum a, GLhalfNV b, GLhalfNV c, GLhalfNV d) {
	m_pglex->glMultiTexCoord3hNV(a,b,c,d);
}

inline void glex::glMultiTexCoord3hvNV(GLenum a, const GLhalfNV *b) {
	m_pglex->glMultiTexCoord3hvNV(a,b);
}

inline void glex::glMultiTexCoord4hNV(GLenum a, GLhalfNV b, GLhalfNV c, GLhalfNV d, GLhalfNV e) {
	m_pglex->glMultiTexCoord4hNV(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4hvNV(GLenum a, const GLhalfNV *b) {
	m_pglex->glMultiTexCoord4hvNV(a,b);
}

inline void glex::glFogCoordhNV(GLhalfNV a) {
	m_pglex->glFogCoordhNV(a);
}

inline void glex::glFogCoordhvNV(const GLhalfNV *a) {
	m_pglex->glFogCoordhvNV(a);
}

inline void glex::glSecondaryColor3hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c) {
	m_pglex->glSecondaryColor3hNV(a,b,c);
}

inline void glex::glSecondaryColor3hvNV(const GLhalfNV *a) {
	m_pglex->glSecondaryColor3hvNV(a);
}

inline void glex::glVertexWeighthNV(GLhalfNV a) {
	m_pglex->glVertexWeighthNV(a);
}

inline void glex::glVertexWeighthvNV(const GLhalfNV *a) {
	m_pglex->glVertexWeighthvNV(a);
}

inline void glex::glVertexAttrib1hNV(GLuint a, GLhalfNV b) {
	m_pglex->glVertexAttrib1hNV(a,b);
}

inline void glex::glVertexAttrib1hvNV(GLuint a, const GLhalfNV *b) {
	m_pglex->glVertexAttrib1hvNV(a,b);
}

inline void glex::glVertexAttrib2hNV(GLuint a, GLhalfNV b, GLhalfNV c) {
	m_pglex->glVertexAttrib2hNV(a,b,c);
}

inline void glex::glVertexAttrib2hvNV(GLuint a, const GLhalfNV *b) {
	m_pglex->glVertexAttrib2hvNV(a,b);
}

inline void glex::glVertexAttrib3hNV(GLuint a, GLhalfNV b, GLhalfNV c, GLhalfNV d) {
	m_pglex->glVertexAttrib3hNV(a,b,c,d);
}

inline void glex::glVertexAttrib3hvNV(GLuint a, const GLhalfNV *b) {
	m_pglex->glVertexAttrib3hvNV(a,b);
}

inline void glex::glVertexAttrib4hNV(GLuint a, GLhalfNV b, GLhalfNV c, GLhalfNV d, GLhalfNV e) {
	m_pglex->glVertexAttrib4hNV(a,b,c,d,e);
}

inline void glex::glVertexAttrib4hvNV(GLuint a, const GLhalfNV *b) {
	m_pglex->glVertexAttrib4hvNV(a,b);
}

inline void glex::glVertexAttribs1hvNV(GLuint a, GLsizei b, const GLhalfNV *c) {
	m_pglex->glVertexAttribs1hvNV(a,b,c);
}

inline void glex::glVertexAttribs2hvNV(GLuint a, GLsizei b, const GLhalfNV *c) {
	m_pglex->glVertexAttribs2hvNV(a,b,c);
}

inline void glex::glVertexAttribs3hvNV(GLuint a, GLsizei b, const GLhalfNV *c) {
	m_pglex->glVertexAttribs3hvNV(a,b,c);
}

inline void glex::glVertexAttribs4hvNV(GLuint a, GLsizei b, const GLhalfNV *c) {
	m_pglex->glVertexAttribs4hvNV(a,b,c);
}

inline void glex::glPixelDataRangeNV(GLenum a, GLsizei b, GLvoid *c) {
	m_pglex->glPixelDataRangeNV(a,b,c);
}

inline void glex::glFlushPixelDataRangeNV(GLenum a) {
	m_pglex->glFlushPixelDataRangeNV(a);
}

inline void glex::glPrimitiveRestartNV(void) {
	m_pglex->glPrimitiveRestartNV();
}

inline void glex::glPrimitiveRestartIndexNV(GLuint a) {
	m_pglex->glPrimitiveRestartIndexNV(a);
}

inline GLvoid* glex::glMapObjectBufferATI(GLuint a) {
	return m_pglex->glMapObjectBufferATI(a);
}

inline void glex::glUnmapObjectBufferATI(GLuint a) {
	m_pglex->glUnmapObjectBufferATI(a);
}

inline void glex::glStencilOpSeparateATI(GLenum a, GLenum b, GLenum c, GLenum d) {
	m_pglex->glStencilOpSeparateATI(a,b,c,d);
}

inline void glex::glStencilFuncSeparateATI(GLenum a, GLenum b, GLint c, GLuint d) {
	m_pglex->glStencilFuncSeparateATI(a,b,c,d);
}

inline void glex::glVertexAttribArrayObjectATI(GLuint a, GLint b, GLenum c, GLboolean d, GLsizei e, GLuint f, GLuint g) {
	m_pglex->glVertexAttribArrayObjectATI(a,b,c,d,e,f,g);
}

inline void glex::glGetVertexAttribArrayObjectfvATI(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetVertexAttribArrayObjectfvATI(a,b,c);
}

inline void glex::glGetVertexAttribArrayObjectivATI(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVertexAttribArrayObjectivATI(a,b,c);
}

inline void glex::glDepthBoundsEXT(GLclampd a, GLclampd b) {
	m_pglex->glDepthBoundsEXT(a,b);
}

inline void glex::glBlendEquationSeparateEXT(GLenum a, GLenum b) {
	m_pglex->glBlendEquationSeparateEXT(a,b);
}

inline GLboolean glex::glIsRenderbufferEXT(GLuint a) {
	return m_pglex->glIsRenderbufferEXT(a);
}

inline void glex::glBindRenderbufferEXT(GLenum a, GLuint b) {
	m_pglex->glBindRenderbufferEXT(a,b);
}

inline void glex::glDeleteRenderbuffersEXT(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteRenderbuffersEXT(a,b);
}

inline void glex::glGenRenderbuffersEXT(GLsizei a, GLuint *b) {
	m_pglex->glGenRenderbuffersEXT(a,b);
}

inline void glex::glRenderbufferStorageEXT(GLenum a, GLenum b, GLsizei c, GLsizei d) {
	m_pglex->glRenderbufferStorageEXT(a,b,c,d);
}

inline void glex::glGetRenderbufferParameterivEXT(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetRenderbufferParameterivEXT(a,b,c);
}

inline GLboolean glex::glIsFramebufferEXT(GLuint a) {
	return m_pglex->glIsFramebufferEXT(a);
}

inline void glex::glBindFramebufferEXT(GLenum a, GLuint b) {
	m_pglex->glBindFramebufferEXT(a,b);
}

inline void glex::glDeleteFramebuffersEXT(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteFramebuffersEXT(a,b);
}

inline void glex::glGenFramebuffersEXT(GLsizei a, GLuint *b) {
	m_pglex->glGenFramebuffersEXT(a,b);
}

inline GLenum glex::glCheckFramebufferStatusEXT(GLenum a) {
	return m_pglex->glCheckFramebufferStatusEXT(a);
}

inline void glex::glFramebufferTexture1DEXT(GLenum a, GLenum b, GLenum c, GLuint d, GLint e) {
	m_pglex->glFramebufferTexture1DEXT(a,b,c,d,e);
}

inline void glex::glFramebufferTexture2DEXT(GLenum a, GLenum b, GLenum c, GLuint d, GLint e) {
	m_pglex->glFramebufferTexture2DEXT(a,b,c,d,e);
}

inline void glex::glFramebufferTexture3DEXT(GLenum a, GLenum b, GLenum c, GLuint d, GLint e, GLint f) {
	m_pglex->glFramebufferTexture3DEXT(a,b,c,d,e,f);
}

inline void glex::glFramebufferRenderbufferEXT(GLenum a, GLenum b, GLenum c, GLuint d) {
	m_pglex->glFramebufferRenderbufferEXT(a,b,c,d);
}

inline void glex::glGetFramebufferAttachmentParameterivEXT(GLenum a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetFramebufferAttachmentParameterivEXT(a,b,c,d);
}

inline void glex::glGenerateMipmapEXT(GLenum a) {
	m_pglex->glGenerateMipmapEXT(a);
}

inline void glex::glStringMarkerGREMEDY(GLsizei a, const GLvoid *b) {
	m_pglex->glStringMarkerGREMEDY(a,b);
}

inline void glex::glStencilClearTagEXT(GLsizei a, GLuint b) {
	m_pglex->glStencilClearTagEXT(a,b);
}

inline void glex::glBlitFramebufferEXT(GLint a, GLint b, GLint c, GLint d, GLint e, GLint f, GLint g, GLint h, GLbitfield i, GLenum j) {
	m_pglex->glBlitFramebufferEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glRenderbufferStorageMultisampleEXT(GLenum a, GLsizei b, GLenum c, GLsizei d, GLsizei e) {
	m_pglex->glRenderbufferStorageMultisampleEXT(a,b,c,d,e);
}

inline void glex::glGetQueryObjecti64vEXT(GLuint a, GLenum b, GLint64EXT *c) {
	m_pglex->glGetQueryObjecti64vEXT(a,b,c);
}

inline void glex::glGetQueryObjectui64vEXT(GLuint a, GLenum b, GLuint64EXT *c) {
	m_pglex->glGetQueryObjectui64vEXT(a,b,c);
}

inline void glex::glProgramEnvParameters4fvEXT(GLenum a, GLuint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramEnvParameters4fvEXT(a,b,c,d);
}

inline void glex::glProgramLocalParameters4fvEXT(GLenum a, GLuint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramLocalParameters4fvEXT(a,b,c,d);
}

inline void glex::glBufferParameteriAPPLE(GLenum a, GLenum b, GLint c) {
	m_pglex->glBufferParameteriAPPLE(a,b,c);
}

inline void glex::glFlushMappedBufferRangeAPPLE(GLenum a, GLintptr b, GLsizeiptr c) {
	m_pglex->glFlushMappedBufferRangeAPPLE(a,b,c);
}

inline void glex::glProgramLocalParameterI4iNV(GLenum a, GLuint b, GLint c, GLint d, GLint e, GLint f) {
	m_pglex->glProgramLocalParameterI4iNV(a,b,c,d,e,f);
}

inline void glex::glProgramLocalParameterI4ivNV(GLenum a, GLuint b, const GLint *c) {
	m_pglex->glProgramLocalParameterI4ivNV(a,b,c);
}

inline void glex::glProgramLocalParametersI4ivNV(GLenum a, GLuint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramLocalParametersI4ivNV(a,b,c,d);
}

inline void glex::glProgramLocalParameterI4uiNV(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f) {
	m_pglex->glProgramLocalParameterI4uiNV(a,b,c,d,e,f);
}

inline void glex::glProgramLocalParameterI4uivNV(GLenum a, GLuint b, const GLuint *c) {
	m_pglex->glProgramLocalParameterI4uivNV(a,b,c);
}

inline void glex::glProgramLocalParametersI4uivNV(GLenum a, GLuint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramLocalParametersI4uivNV(a,b,c,d);
}

inline void glex::glProgramEnvParameterI4iNV(GLenum a, GLuint b, GLint c, GLint d, GLint e, GLint f) {
	m_pglex->glProgramEnvParameterI4iNV(a,b,c,d,e,f);
}

inline void glex::glProgramEnvParameterI4ivNV(GLenum a, GLuint b, const GLint *c) {
	m_pglex->glProgramEnvParameterI4ivNV(a,b,c);
}

inline void glex::glProgramEnvParametersI4ivNV(GLenum a, GLuint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramEnvParametersI4ivNV(a,b,c,d);
}

inline void glex::glProgramEnvParameterI4uiNV(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f) {
	m_pglex->glProgramEnvParameterI4uiNV(a,b,c,d,e,f);
}

inline void glex::glProgramEnvParameterI4uivNV(GLenum a, GLuint b, const GLuint *c) {
	m_pglex->glProgramEnvParameterI4uivNV(a,b,c);
}

inline void glex::glProgramEnvParametersI4uivNV(GLenum a, GLuint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramEnvParametersI4uivNV(a,b,c,d);
}

inline void glex::glGetProgramLocalParameterIivNV(GLenum a, GLuint b, GLint *c) {
	m_pglex->glGetProgramLocalParameterIivNV(a,b,c);
}

inline void glex::glGetProgramLocalParameterIuivNV(GLenum a, GLuint b, GLuint *c) {
	m_pglex->glGetProgramLocalParameterIuivNV(a,b,c);
}

inline void glex::glGetProgramEnvParameterIivNV(GLenum a, GLuint b, GLint *c) {
	m_pglex->glGetProgramEnvParameterIivNV(a,b,c);
}

inline void glex::glGetProgramEnvParameterIuivNV(GLenum a, GLuint b, GLuint *c) {
	m_pglex->glGetProgramEnvParameterIuivNV(a,b,c);
}

inline void glex::glProgramVertexLimitNV(GLenum a, GLint b) {
	m_pglex->glProgramVertexLimitNV(a,b);
}

inline void glex::glFramebufferTextureEXT(GLenum a, GLenum b, GLuint c, GLint d) {
	m_pglex->glFramebufferTextureEXT(a,b,c,d);
}

inline void glex::glFramebufferTextureLayerEXT(GLenum a, GLenum b, GLuint c, GLint d, GLint e) {
	m_pglex->glFramebufferTextureLayerEXT(a,b,c,d,e);
}

inline void glex::glFramebufferTextureFaceEXT(GLenum a, GLenum b, GLuint c, GLint d, GLenum e) {
	m_pglex->glFramebufferTextureFaceEXT(a,b,c,d,e);
}

inline void glex::glProgramParameteriEXT(GLuint a, GLenum b, GLint c) {
	m_pglex->glProgramParameteriEXT(a,b,c);
}

inline void glex::glVertexAttribI1iEXT(GLuint a, GLint b) {
	m_pglex->glVertexAttribI1iEXT(a,b);
}

inline void glex::glVertexAttribI2iEXT(GLuint a, GLint b, GLint c) {
	m_pglex->glVertexAttribI2iEXT(a,b,c);
}

inline void glex::glVertexAttribI3iEXT(GLuint a, GLint b, GLint c, GLint d) {
	m_pglex->glVertexAttribI3iEXT(a,b,c,d);
}

inline void glex::glVertexAttribI4iEXT(GLuint a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glVertexAttribI4iEXT(a,b,c,d,e);
}

inline void glex::glVertexAttribI1uiEXT(GLuint a, GLuint b) {
	m_pglex->glVertexAttribI1uiEXT(a,b);
}

inline void glex::glVertexAttribI2uiEXT(GLuint a, GLuint b, GLuint c) {
	m_pglex->glVertexAttribI2uiEXT(a,b,c);
}

inline void glex::glVertexAttribI3uiEXT(GLuint a, GLuint b, GLuint c, GLuint d) {
	m_pglex->glVertexAttribI3uiEXT(a,b,c,d);
}

inline void glex::glVertexAttribI4uiEXT(GLuint a, GLuint b, GLuint c, GLuint d, GLuint e) {
	m_pglex->glVertexAttribI4uiEXT(a,b,c,d,e);
}

inline void glex::glVertexAttribI1ivEXT(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI1ivEXT(a,b);
}

inline void glex::glVertexAttribI2ivEXT(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI2ivEXT(a,b);
}

inline void glex::glVertexAttribI3ivEXT(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI3ivEXT(a,b);
}

inline void glex::glVertexAttribI4ivEXT(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI4ivEXT(a,b);
}

inline void glex::glVertexAttribI1uivEXT(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI1uivEXT(a,b);
}

inline void glex::glVertexAttribI2uivEXT(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI2uivEXT(a,b);
}

inline void glex::glVertexAttribI3uivEXT(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI3uivEXT(a,b);
}

inline void glex::glVertexAttribI4uivEXT(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI4uivEXT(a,b);
}

inline void glex::glVertexAttribI4bvEXT(GLuint a, const GLbyte *b) {
	m_pglex->glVertexAttribI4bvEXT(a,b);
}

inline void glex::glVertexAttribI4svEXT(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttribI4svEXT(a,b);
}

inline void glex::glVertexAttribI4ubvEXT(GLuint a, const GLubyte *b) {
	m_pglex->glVertexAttribI4ubvEXT(a,b);
}

inline void glex::glVertexAttribI4usvEXT(GLuint a, const GLushort *b) {
	m_pglex->glVertexAttribI4usvEXT(a,b);
}

inline void glex::glVertexAttribIPointerEXT(GLuint a, GLint b, GLenum c, GLsizei d, const GLvoid *e) {
	m_pglex->glVertexAttribIPointerEXT(a,b,c,d,e);
}

inline void glex::glGetVertexAttribIivEXT(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVertexAttribIivEXT(a,b,c);
}

inline void glex::glGetVertexAttribIuivEXT(GLuint a, GLenum b, GLuint *c) {
	m_pglex->glGetVertexAttribIuivEXT(a,b,c);
}

inline void glex::glGetUniformuivEXT(GLuint a, GLint b, GLuint *c) {
	m_pglex->glGetUniformuivEXT(a,b,c);
}

inline void glex::glBindFragDataLocationEXT(GLuint a, GLuint b, const GLchar *c) {
	m_pglex->glBindFragDataLocationEXT(a,b,c);
}

inline GLint glex::glGetFragDataLocationEXT(GLuint a, const GLchar *b) {
	return m_pglex->glGetFragDataLocationEXT(a,b);
}

inline void glex::glUniform1uiEXT(GLint a, GLuint b) {
	m_pglex->glUniform1uiEXT(a,b);
}

inline void glex::glUniform2uiEXT(GLint a, GLuint b, GLuint c) {
	m_pglex->glUniform2uiEXT(a,b,c);
}

inline void glex::glUniform3uiEXT(GLint a, GLuint b, GLuint c, GLuint d) {
	m_pglex->glUniform3uiEXT(a,b,c,d);
}

inline void glex::glUniform4uiEXT(GLint a, GLuint b, GLuint c, GLuint d, GLuint e) {
	m_pglex->glUniform4uiEXT(a,b,c,d,e);
}

inline void glex::glUniform1uivEXT(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform1uivEXT(a,b,c);
}

inline void glex::glUniform2uivEXT(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform2uivEXT(a,b,c);
}

inline void glex::glUniform3uivEXT(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform3uivEXT(a,b,c);
}

inline void glex::glUniform4uivEXT(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform4uivEXT(a,b,c);
}

inline void glex::glDrawArraysInstancedEXT(GLenum a, GLint b, GLsizei c, GLsizei d) {
	m_pglex->glDrawArraysInstancedEXT(a,b,c,d);
}

inline void glex::glDrawElementsInstancedEXT(GLenum a, GLsizei b, GLenum c, const GLvoid *d, GLsizei e) {
	m_pglex->glDrawElementsInstancedEXT(a,b,c,d,e);
}

inline void glex::glTexBufferEXT(GLenum a, GLenum b, GLuint c) {
	m_pglex->glTexBufferEXT(a,b,c);
}

inline void glex::glDepthRangedNV(GLdouble a, GLdouble b) {
	m_pglex->glDepthRangedNV(a,b);
}

inline void glex::glClearDepthdNV(GLdouble a) {
	m_pglex->glClearDepthdNV(a);
}

inline void glex::glDepthBoundsdNV(GLdouble a, GLdouble b) {
	m_pglex->glDepthBoundsdNV(a,b);
}

inline void glex::glRenderbufferStorageMultisampleCoverageNV(GLenum a, GLsizei b, GLsizei c, GLenum d, GLsizei e, GLsizei f) {
	m_pglex->glRenderbufferStorageMultisampleCoverageNV(a,b,c,d,e,f);
}

inline void glex::glProgramBufferParametersfvNV(GLenum a, GLuint b, GLuint c, GLsizei d, const GLfloat *e) {
	m_pglex->glProgramBufferParametersfvNV(a,b,c,d,e);
}

inline void glex::glProgramBufferParametersIivNV(GLenum a, GLuint b, GLuint c, GLsizei d, const GLint *e) {
	m_pglex->glProgramBufferParametersIivNV(a,b,c,d,e);
}

inline void glex::glProgramBufferParametersIuivNV(GLenum a, GLuint b, GLuint c, GLsizei d, const GLuint *e) {
	m_pglex->glProgramBufferParametersIuivNV(a,b,c,d,e);
}

inline void glex::glColorMaskIndexedEXT(GLuint a, GLboolean b, GLboolean c, GLboolean d, GLboolean e) {
	m_pglex->glColorMaskIndexedEXT(a,b,c,d,e);
}

inline void glex::glGetBooleanIndexedvEXT(GLenum a, GLuint b, GLboolean *c) {
	m_pglex->glGetBooleanIndexedvEXT(a,b,c);
}

inline void glex::glGetIntegerIndexedvEXT(GLenum a, GLuint b, GLint *c) {
	m_pglex->glGetIntegerIndexedvEXT(a,b,c);
}

inline void glex::glEnableIndexedEXT(GLenum a, GLuint b) {
	m_pglex->glEnableIndexedEXT(a,b);
}

inline void glex::glDisableIndexedEXT(GLenum a, GLuint b) {
	m_pglex->glDisableIndexedEXT(a,b);
}

inline GLboolean glex::glIsEnabledIndexedEXT(GLenum a, GLuint b) {
	return m_pglex->glIsEnabledIndexedEXT(a,b);
}

inline void glex::glBeginTransformFeedbackNV(GLenum a) {
	m_pglex->glBeginTransformFeedbackNV(a);
}

inline void glex::glEndTransformFeedbackNV(void) {
	m_pglex->glEndTransformFeedbackNV();
}

inline void glex::glTransformFeedbackAttribsNV(GLuint a, const GLint *b, GLenum c) {
	m_pglex->glTransformFeedbackAttribsNV(a,b,c);
}

inline void glex::glBindBufferRangeNV(GLenum a, GLuint b, GLuint c, GLintptr d, GLsizeiptr e) {
	m_pglex->glBindBufferRangeNV(a,b,c,d,e);
}

inline void glex::glBindBufferOffsetNV(GLenum a, GLuint b, GLuint c, GLintptr d) {
	m_pglex->glBindBufferOffsetNV(a,b,c,d);
}

inline void glex::glBindBufferBaseNV(GLenum a, GLuint b, GLuint c) {
	m_pglex->glBindBufferBaseNV(a,b,c);
}

inline void glex::glTransformFeedbackVaryingsNV(GLuint a, GLsizei b, const GLint *c, GLenum d) {
	m_pglex->glTransformFeedbackVaryingsNV(a,b,c,d);
}

inline void glex::glActiveVaryingNV(GLuint a, const GLchar *b) {
	m_pglex->glActiveVaryingNV(a,b);
}

inline GLint glex::glGetVaryingLocationNV(GLuint a, const GLchar *b) {
	return m_pglex->glGetVaryingLocationNV(a,b);
}

inline void glex::glGetActiveVaryingNV(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLsizei *e, GLenum *f, GLchar *g) {
	m_pglex->glGetActiveVaryingNV(a,b,c,d,e,f,g);
}

inline void glex::glGetTransformFeedbackVaryingNV(GLuint a, GLuint b, GLint *c) {
	m_pglex->glGetTransformFeedbackVaryingNV(a,b,c);
}

inline void glex::glTransformFeedbackStreamAttribsNV(GLsizei a, const GLint *b, GLsizei c, const GLint *d, GLenum e) {
	m_pglex->glTransformFeedbackStreamAttribsNV(a,b,c,d,e);
}

inline void glex::glUniformBufferEXT(GLuint a, GLint b, GLuint c) {
	m_pglex->glUniformBufferEXT(a,b,c);
}

inline GLint glex::glGetUniformBufferSizeEXT(GLuint a, GLint b) {
	return m_pglex->glGetUniformBufferSizeEXT(a,b);
}

inline GLintptr glex::glGetUniformOffsetEXT(GLuint a, GLint b) {
	return m_pglex->glGetUniformOffsetEXT(a,b);
}

inline void glex::glTexParameterIivEXT(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glTexParameterIivEXT(a,b,c);
}

inline void glex::glTexParameterIuivEXT(GLenum a, GLenum b, const GLuint *c) {
	m_pglex->glTexParameterIuivEXT(a,b,c);
}

inline void glex::glGetTexParameterIivEXT(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetTexParameterIivEXT(a,b,c);
}

inline void glex::glGetTexParameterIuivEXT(GLenum a, GLenum b, GLuint *c) {
	m_pglex->glGetTexParameterIuivEXT(a,b,c);
}

inline void glex::glClearColorIiEXT(GLint a, GLint b, GLint c, GLint d) {
	m_pglex->glClearColorIiEXT(a,b,c,d);
}

inline void glex::glClearColorIuiEXT(GLuint a, GLuint b, GLuint c, GLuint d) {
	m_pglex->glClearColorIuiEXT(a,b,c,d);
}

inline void glex::glFrameTerminatorGREMEDY(void) {
	m_pglex->glFrameTerminatorGREMEDY();
}

inline void glex::glBeginConditionalRenderNV(GLuint a, GLenum b) {
	m_pglex->glBeginConditionalRenderNV(a,b);
}

inline void glex::glEndConditionalRenderNV(void) {
	m_pglex->glEndConditionalRenderNV();
}

inline void glex::glPresentFrameKeyedNV(GLuint a, GLuint64EXT b, GLuint c, GLuint d, GLenum e, GLenum f, GLuint g, GLuint h, GLenum i, GLuint j, GLuint k) {
	m_pglex->glPresentFrameKeyedNV(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glPresentFrameDualFillNV(GLuint a, GLuint64EXT b, GLuint c, GLuint d, GLenum e, GLenum f, GLuint g, GLenum h, GLuint i, GLenum j, GLuint k, GLenum l, GLuint m) {
	m_pglex->glPresentFrameDualFillNV(a,b,c,d,e,f,g,h,i,j,k,l,m);
}

inline void glex::glGetVideoivNV(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVideoivNV(a,b,c);
}

inline void glex::glGetVideouivNV(GLuint a, GLenum b, GLuint *c) {
	m_pglex->glGetVideouivNV(a,b,c);
}

inline void glex::glGetVideoi64vNV(GLuint a, GLenum b, GLint64EXT *c) {
	m_pglex->glGetVideoi64vNV(a,b,c);
}

inline void glex::glGetVideoui64vNV(GLuint a, GLenum b, GLuint64EXT *c) {
	m_pglex->glGetVideoui64vNV(a,b,c);
}

inline void glex::glBeginTransformFeedbackEXT(GLenum a) {
	m_pglex->glBeginTransformFeedbackEXT(a);
}

inline void glex::glEndTransformFeedbackEXT(void) {
	m_pglex->glEndTransformFeedbackEXT();
}

inline void glex::glBindBufferRangeEXT(GLenum a, GLuint b, GLuint c, GLintptr d, GLsizeiptr e) {
	m_pglex->glBindBufferRangeEXT(a,b,c,d,e);
}

inline void glex::glBindBufferOffsetEXT(GLenum a, GLuint b, GLuint c, GLintptr d) {
	m_pglex->glBindBufferOffsetEXT(a,b,c,d);
}

inline void glex::glBindBufferBaseEXT(GLenum a, GLuint b, GLuint c) {
	m_pglex->glBindBufferBaseEXT(a,b,c);
}

inline void glex::glTransformFeedbackVaryingsEXT(GLuint a, GLsizei b, const GLchar* *c, GLenum d) {
	m_pglex->glTransformFeedbackVaryingsEXT(a,b,c,d);
}

inline void glex::glGetTransformFeedbackVaryingEXT(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLsizei *e, GLenum *f, GLchar *g) {
	m_pglex->glGetTransformFeedbackVaryingEXT(a,b,c,d,e,f,g);
}

inline void glex::glClientAttribDefaultEXT(GLbitfield a) {
	m_pglex->glClientAttribDefaultEXT(a);
}

inline void glex::glPushClientAttribDefaultEXT(GLbitfield a) {
	m_pglex->glPushClientAttribDefaultEXT(a);
}

inline void glex::glMatrixLoadfEXT(GLenum a, const GLfloat *b) {
	m_pglex->glMatrixLoadfEXT(a,b);
}

inline void glex::glMatrixLoaddEXT(GLenum a, const GLdouble *b) {
	m_pglex->glMatrixLoaddEXT(a,b);
}

inline void glex::glMatrixMultfEXT(GLenum a, const GLfloat *b) {
	m_pglex->glMatrixMultfEXT(a,b);
}

inline void glex::glMatrixMultdEXT(GLenum a, const GLdouble *b) {
	m_pglex->glMatrixMultdEXT(a,b);
}

inline void glex::glMatrixLoadIdentityEXT(GLenum a) {
	m_pglex->glMatrixLoadIdentityEXT(a);
}

inline void glex::glMatrixRotatefEXT(GLenum a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glMatrixRotatefEXT(a,b,c,d,e);
}

inline void glex::glMatrixRotatedEXT(GLenum a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glMatrixRotatedEXT(a,b,c,d,e);
}

inline void glex::glMatrixScalefEXT(GLenum a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glMatrixScalefEXT(a,b,c,d);
}

inline void glex::glMatrixScaledEXT(GLenum a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glMatrixScaledEXT(a,b,c,d);
}

inline void glex::glMatrixTranslatefEXT(GLenum a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glMatrixTranslatefEXT(a,b,c,d);
}

inline void glex::glMatrixTranslatedEXT(GLenum a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glMatrixTranslatedEXT(a,b,c,d);
}

inline void glex::glMatrixFrustumEXT(GLenum a, GLdouble b, GLdouble c, GLdouble d, GLdouble e, GLdouble f, GLdouble g) {
	m_pglex->glMatrixFrustumEXT(a,b,c,d,e,f,g);
}

inline void glex::glMatrixOrthoEXT(GLenum a, GLdouble b, GLdouble c, GLdouble d, GLdouble e, GLdouble f, GLdouble g) {
	m_pglex->glMatrixOrthoEXT(a,b,c,d,e,f,g);
}

inline void glex::glMatrixPopEXT(GLenum a) {
	m_pglex->glMatrixPopEXT(a);
}

inline void glex::glMatrixPushEXT(GLenum a) {
	m_pglex->glMatrixPushEXT(a);
}

inline void glex::glMatrixLoadTransposefEXT(GLenum a, const GLfloat *b) {
	m_pglex->glMatrixLoadTransposefEXT(a,b);
}

inline void glex::glMatrixLoadTransposedEXT(GLenum a, const GLdouble *b) {
	m_pglex->glMatrixLoadTransposedEXT(a,b);
}

inline void glex::glMatrixMultTransposefEXT(GLenum a, const GLfloat *b) {
	m_pglex->glMatrixMultTransposefEXT(a,b);
}

inline void glex::glMatrixMultTransposedEXT(GLenum a, const GLdouble *b) {
	m_pglex->glMatrixMultTransposedEXT(a,b);
}

inline void glex::glTextureParameterfEXT(GLuint a, GLenum b, GLenum c, GLfloat d) {
	m_pglex->glTextureParameterfEXT(a,b,c,d);
}

inline void glex::glTextureParameterfvEXT(GLuint a, GLenum b, GLenum c, const GLfloat *d) {
	m_pglex->glTextureParameterfvEXT(a,b,c,d);
}

inline void glex::glTextureParameteriEXT(GLuint a, GLenum b, GLenum c, GLint d) {
	m_pglex->glTextureParameteriEXT(a,b,c,d);
}

inline void glex::glTextureParameterivEXT(GLuint a, GLenum b, GLenum c, const GLint *d) {
	m_pglex->glTextureParameterivEXT(a,b,c,d);
}

inline void glex::glTextureImage1DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLsizei e, GLint f, GLenum g, GLenum h, const GLvoid *i) {
	m_pglex->glTextureImage1DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glTextureImage2DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLint g, GLenum h, GLenum i, const GLvoid *j) {
	m_pglex->glTextureImage2DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glTextureSubImage1DEXT(GLuint a, GLenum b, GLint c, GLint d, GLsizei e, GLenum f, GLenum g, const GLvoid *h) {
	m_pglex->glTextureSubImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glTextureSubImage2DEXT(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLenum h, GLenum i, const GLvoid *j) {
	m_pglex->glTextureSubImage2DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glCopyTextureImage1DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLint e, GLint f, GLsizei g, GLint h) {
	m_pglex->glCopyTextureImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glCopyTextureImage2DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLint e, GLint f, GLsizei g, GLsizei h, GLint i) {
	m_pglex->glCopyTextureImage2DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCopyTextureSubImage1DEXT(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLsizei g) {
	m_pglex->glCopyTextureSubImage1DEXT(a,b,c,d,e,f,g);
}

inline void glex::glCopyTextureSubImage2DEXT(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLint g, GLsizei h, GLsizei i) {
	m_pglex->glCopyTextureSubImage2DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glGetTextureImageEXT(GLuint a, GLenum b, GLint c, GLenum d, GLenum e, GLvoid *f) {
	m_pglex->glGetTextureImageEXT(a,b,c,d,e,f);
}

inline void glex::glGetTextureParameterfvEXT(GLuint a, GLenum b, GLenum c, GLfloat *d) {
	m_pglex->glGetTextureParameterfvEXT(a,b,c,d);
}

inline void glex::glGetTextureParameterivEXT(GLuint a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetTextureParameterivEXT(a,b,c,d);
}

inline void glex::glGetTextureLevelParameterfvEXT(GLuint a, GLenum b, GLint c, GLenum d, GLfloat *e) {
	m_pglex->glGetTextureLevelParameterfvEXT(a,b,c,d,e);
}

inline void glex::glGetTextureLevelParameterivEXT(GLuint a, GLenum b, GLint c, GLenum d, GLint *e) {
	m_pglex->glGetTextureLevelParameterivEXT(a,b,c,d,e);
}

inline void glex::glTextureImage3DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLsizei g, GLint h, GLenum i, GLenum j, const GLvoid *k) {
	m_pglex->glTextureImage3DEXT(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glTextureSubImage3DEXT(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLsizei g, GLsizei h, GLsizei i, GLenum j, GLenum k, const GLvoid *l) {
	m_pglex->glTextureSubImage3DEXT(a,b,c,d,e,f,g,h,i,j,k,l);
}

inline void glex::glCopyTextureSubImage3DEXT(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLint g, GLint h, GLsizei i, GLsizei j) {
	m_pglex->glCopyTextureSubImage3DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glMultiTexParameterfEXT(GLenum a, GLenum b, GLenum c, GLfloat d) {
	m_pglex->glMultiTexParameterfEXT(a,b,c,d);
}

inline void glex::glMultiTexParameterfvEXT(GLenum a, GLenum b, GLenum c, const GLfloat *d) {
	m_pglex->glMultiTexParameterfvEXT(a,b,c,d);
}

inline void glex::glMultiTexParameteriEXT(GLenum a, GLenum b, GLenum c, GLint d) {
	m_pglex->glMultiTexParameteriEXT(a,b,c,d);
}

inline void glex::glMultiTexParameterivEXT(GLenum a, GLenum b, GLenum c, const GLint *d) {
	m_pglex->glMultiTexParameterivEXT(a,b,c,d);
}

inline void glex::glMultiTexImage1DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLsizei e, GLint f, GLenum g, GLenum h, const GLvoid *i) {
	m_pglex->glMultiTexImage1DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glMultiTexImage2DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLint g, GLenum h, GLenum i, const GLvoid *j) {
	m_pglex->glMultiTexImage2DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glMultiTexSubImage1DEXT(GLenum a, GLenum b, GLint c, GLint d, GLsizei e, GLenum f, GLenum g, const GLvoid *h) {
	m_pglex->glMultiTexSubImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glMultiTexSubImage2DEXT(GLenum a, GLenum b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLenum h, GLenum i, const GLvoid *j) {
	m_pglex->glMultiTexSubImage2DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glCopyMultiTexImage1DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLint e, GLint f, GLsizei g, GLint h) {
	m_pglex->glCopyMultiTexImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glCopyMultiTexImage2DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLint e, GLint f, GLsizei g, GLsizei h, GLint i) {
	m_pglex->glCopyMultiTexImage2DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCopyMultiTexSubImage1DEXT(GLenum a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLsizei g) {
	m_pglex->glCopyMultiTexSubImage1DEXT(a,b,c,d,e,f,g);
}

inline void glex::glCopyMultiTexSubImage2DEXT(GLenum a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLint g, GLsizei h, GLsizei i) {
	m_pglex->glCopyMultiTexSubImage2DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glGetMultiTexImageEXT(GLenum a, GLenum b, GLint c, GLenum d, GLenum e, GLvoid *f) {
	m_pglex->glGetMultiTexImageEXT(a,b,c,d,e,f);
}

inline void glex::glGetMultiTexParameterfvEXT(GLenum a, GLenum b, GLenum c, GLfloat *d) {
	m_pglex->glGetMultiTexParameterfvEXT(a,b,c,d);
}

inline void glex::glGetMultiTexParameterivEXT(GLenum a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetMultiTexParameterivEXT(a,b,c,d);
}

inline void glex::glGetMultiTexLevelParameterfvEXT(GLenum a, GLenum b, GLint c, GLenum d, GLfloat *e) {
	m_pglex->glGetMultiTexLevelParameterfvEXT(a,b,c,d,e);
}

inline void glex::glGetMultiTexLevelParameterivEXT(GLenum a, GLenum b, GLint c, GLenum d, GLint *e) {
	m_pglex->glGetMultiTexLevelParameterivEXT(a,b,c,d,e);
}

inline void glex::glMultiTexImage3DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLsizei g, GLint h, GLenum i, GLenum j, const GLvoid *k) {
	m_pglex->glMultiTexImage3DEXT(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glMultiTexSubImage3DEXT(GLenum a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLsizei g, GLsizei h, GLsizei i, GLenum j, GLenum k, const GLvoid *l) {
	m_pglex->glMultiTexSubImage3DEXT(a,b,c,d,e,f,g,h,i,j,k,l);
}

inline void glex::glCopyMultiTexSubImage3DEXT(GLenum a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLint g, GLint h, GLsizei i, GLsizei j) {
	m_pglex->glCopyMultiTexSubImage3DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glBindMultiTextureEXT(GLenum a, GLenum b, GLuint c) {
	m_pglex->glBindMultiTextureEXT(a,b,c);
}

inline void glex::glEnableClientStateIndexedEXT(GLenum a, GLuint b) {
	m_pglex->glEnableClientStateIndexedEXT(a,b);
}

inline void glex::glDisableClientStateIndexedEXT(GLenum a, GLuint b) {
	m_pglex->glDisableClientStateIndexedEXT(a,b);
}

inline void glex::glMultiTexCoordPointerEXT(GLenum a, GLint b, GLenum c, GLsizei d, const GLvoid *e) {
	m_pglex->glMultiTexCoordPointerEXT(a,b,c,d,e);
}

inline void glex::glMultiTexEnvfEXT(GLenum a, GLenum b, GLenum c, GLfloat d) {
	m_pglex->glMultiTexEnvfEXT(a,b,c,d);
}

inline void glex::glMultiTexEnvfvEXT(GLenum a, GLenum b, GLenum c, const GLfloat *d) {
	m_pglex->glMultiTexEnvfvEXT(a,b,c,d);
}

inline void glex::glMultiTexEnviEXT(GLenum a, GLenum b, GLenum c, GLint d) {
	m_pglex->glMultiTexEnviEXT(a,b,c,d);
}

inline void glex::glMultiTexEnvivEXT(GLenum a, GLenum b, GLenum c, const GLint *d) {
	m_pglex->glMultiTexEnvivEXT(a,b,c,d);
}

inline void glex::glMultiTexGendEXT(GLenum a, GLenum b, GLenum c, GLdouble d) {
	m_pglex->glMultiTexGendEXT(a,b,c,d);
}

inline void glex::glMultiTexGendvEXT(GLenum a, GLenum b, GLenum c, const GLdouble *d) {
	m_pglex->glMultiTexGendvEXT(a,b,c,d);
}

inline void glex::glMultiTexGenfEXT(GLenum a, GLenum b, GLenum c, GLfloat d) {
	m_pglex->glMultiTexGenfEXT(a,b,c,d);
}

inline void glex::glMultiTexGenfvEXT(GLenum a, GLenum b, GLenum c, const GLfloat *d) {
	m_pglex->glMultiTexGenfvEXT(a,b,c,d);
}

inline void glex::glMultiTexGeniEXT(GLenum a, GLenum b, GLenum c, GLint d) {
	m_pglex->glMultiTexGeniEXT(a,b,c,d);
}

inline void glex::glMultiTexGenivEXT(GLenum a, GLenum b, GLenum c, const GLint *d) {
	m_pglex->glMultiTexGenivEXT(a,b,c,d);
}

inline void glex::glGetMultiTexEnvfvEXT(GLenum a, GLenum b, GLenum c, GLfloat *d) {
	m_pglex->glGetMultiTexEnvfvEXT(a,b,c,d);
}

inline void glex::glGetMultiTexEnvivEXT(GLenum a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetMultiTexEnvivEXT(a,b,c,d);
}

inline void glex::glGetMultiTexGendvEXT(GLenum a, GLenum b, GLenum c, GLdouble *d) {
	m_pglex->glGetMultiTexGendvEXT(a,b,c,d);
}

inline void glex::glGetMultiTexGenfvEXT(GLenum a, GLenum b, GLenum c, GLfloat *d) {
	m_pglex->glGetMultiTexGenfvEXT(a,b,c,d);
}

inline void glex::glGetMultiTexGenivEXT(GLenum a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetMultiTexGenivEXT(a,b,c,d);
}

inline void glex::glGetFloatIndexedvEXT(GLenum a, GLuint b, GLfloat *c) {
	m_pglex->glGetFloatIndexedvEXT(a,b,c);
}

inline void glex::glGetDoubleIndexedvEXT(GLenum a, GLuint b, GLdouble *c) {
	m_pglex->glGetDoubleIndexedvEXT(a,b,c);
}

inline void glex::glGetPointerIndexedvEXT(GLenum a, GLuint b, GLvoid* *c) {
	m_pglex->glGetPointerIndexedvEXT(a,b,c);
}

inline void glex::glCompressedTextureImage3DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLsizei g, GLint h, GLsizei i, const GLvoid *j) {
	m_pglex->glCompressedTextureImage3DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glCompressedTextureImage2DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLint g, GLsizei h, const GLvoid *i) {
	m_pglex->glCompressedTextureImage2DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCompressedTextureImage1DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLsizei e, GLint f, GLsizei g, const GLvoid *h) {
	m_pglex->glCompressedTextureImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glCompressedTextureSubImage3DEXT(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLsizei g, GLsizei h, GLsizei i, GLenum j, GLsizei k, const GLvoid *l) {
	m_pglex->glCompressedTextureSubImage3DEXT(a,b,c,d,e,f,g,h,i,j,k,l);
}

inline void glex::glCompressedTextureSubImage2DEXT(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLenum h, GLsizei i, const GLvoid *j) {
	m_pglex->glCompressedTextureSubImage2DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glCompressedTextureSubImage1DEXT(GLuint a, GLenum b, GLint c, GLint d, GLsizei e, GLenum f, GLsizei g, const GLvoid *h) {
	m_pglex->glCompressedTextureSubImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glGetCompressedTextureImageEXT(GLuint a, GLenum b, GLint c, GLvoid *d) {
	m_pglex->glGetCompressedTextureImageEXT(a,b,c,d);
}

inline void glex::glCompressedMultiTexImage3DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLsizei g, GLint h, GLsizei i, const GLvoid *j) {
	m_pglex->glCompressedMultiTexImage3DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glCompressedMultiTexImage2DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLint g, GLsizei h, const GLvoid *i) {
	m_pglex->glCompressedMultiTexImage2DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCompressedMultiTexImage1DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLsizei e, GLint f, GLsizei g, const GLvoid *h) {
	m_pglex->glCompressedMultiTexImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glCompressedMultiTexSubImage3DEXT(GLenum a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLsizei g, GLsizei h, GLsizei i, GLenum j, GLsizei k, const GLvoid *l) {
	m_pglex->glCompressedMultiTexSubImage3DEXT(a,b,c,d,e,f,g,h,i,j,k,l);
}

inline void glex::glCompressedMultiTexSubImage2DEXT(GLenum a, GLenum b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLenum h, GLsizei i, const GLvoid *j) {
	m_pglex->glCompressedMultiTexSubImage2DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glCompressedMultiTexSubImage1DEXT(GLenum a, GLenum b, GLint c, GLint d, GLsizei e, GLenum f, GLsizei g, const GLvoid *h) {
	m_pglex->glCompressedMultiTexSubImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glGetCompressedMultiTexImageEXT(GLenum a, GLenum b, GLint c, GLvoid *d) {
	m_pglex->glGetCompressedMultiTexImageEXT(a,b,c,d);
}

inline void glex::glNamedProgramStringEXT(GLuint a, GLenum b, GLenum c, GLsizei d, const GLvoid *e) {
	m_pglex->glNamedProgramStringEXT(a,b,c,d,e);
}

inline void glex::glNamedProgramLocalParameter4dEXT(GLuint a, GLenum b, GLuint c, GLdouble d, GLdouble e, GLdouble f, GLdouble g) {
	m_pglex->glNamedProgramLocalParameter4dEXT(a,b,c,d,e,f,g);
}

inline void glex::glNamedProgramLocalParameter4dvEXT(GLuint a, GLenum b, GLuint c, const GLdouble *d) {
	m_pglex->glNamedProgramLocalParameter4dvEXT(a,b,c,d);
}

inline void glex::glNamedProgramLocalParameter4fEXT(GLuint a, GLenum b, GLuint c, GLfloat d, GLfloat e, GLfloat f, GLfloat g) {
	m_pglex->glNamedProgramLocalParameter4fEXT(a,b,c,d,e,f,g);
}

inline void glex::glNamedProgramLocalParameter4fvEXT(GLuint a, GLenum b, GLuint c, const GLfloat *d) {
	m_pglex->glNamedProgramLocalParameter4fvEXT(a,b,c,d);
}

inline void glex::glGetNamedProgramLocalParameterdvEXT(GLuint a, GLenum b, GLuint c, GLdouble *d) {
	m_pglex->glGetNamedProgramLocalParameterdvEXT(a,b,c,d);
}

inline void glex::glGetNamedProgramLocalParameterfvEXT(GLuint a, GLenum b, GLuint c, GLfloat *d) {
	m_pglex->glGetNamedProgramLocalParameterfvEXT(a,b,c,d);
}

inline void glex::glGetNamedProgramivEXT(GLuint a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetNamedProgramivEXT(a,b,c,d);
}

inline void glex::glGetNamedProgramStringEXT(GLuint a, GLenum b, GLenum c, GLvoid *d) {
	m_pglex->glGetNamedProgramStringEXT(a,b,c,d);
}

inline void glex::glNamedProgramLocalParameters4fvEXT(GLuint a, GLenum b, GLuint c, GLsizei d, const GLfloat *e) {
	m_pglex->glNamedProgramLocalParameters4fvEXT(a,b,c,d,e);
}

inline void glex::glNamedProgramLocalParameterI4iEXT(GLuint a, GLenum b, GLuint c, GLint d, GLint e, GLint f, GLint g) {
	m_pglex->glNamedProgramLocalParameterI4iEXT(a,b,c,d,e,f,g);
}

inline void glex::glNamedProgramLocalParameterI4ivEXT(GLuint a, GLenum b, GLuint c, const GLint *d) {
	m_pglex->glNamedProgramLocalParameterI4ivEXT(a,b,c,d);
}

inline void glex::glNamedProgramLocalParametersI4ivEXT(GLuint a, GLenum b, GLuint c, GLsizei d, const GLint *e) {
	m_pglex->glNamedProgramLocalParametersI4ivEXT(a,b,c,d,e);
}

inline void glex::glNamedProgramLocalParameterI4uiEXT(GLuint a, GLenum b, GLuint c, GLuint d, GLuint e, GLuint f, GLuint g) {
	m_pglex->glNamedProgramLocalParameterI4uiEXT(a,b,c,d,e,f,g);
}

inline void glex::glNamedProgramLocalParameterI4uivEXT(GLuint a, GLenum b, GLuint c, const GLuint *d) {
	m_pglex->glNamedProgramLocalParameterI4uivEXT(a,b,c,d);
}

inline void glex::glNamedProgramLocalParametersI4uivEXT(GLuint a, GLenum b, GLuint c, GLsizei d, const GLuint *e) {
	m_pglex->glNamedProgramLocalParametersI4uivEXT(a,b,c,d,e);
}

inline void glex::glGetNamedProgramLocalParameterIivEXT(GLuint a, GLenum b, GLuint c, GLint *d) {
	m_pglex->glGetNamedProgramLocalParameterIivEXT(a,b,c,d);
}

inline void glex::glGetNamedProgramLocalParameterIuivEXT(GLuint a, GLenum b, GLuint c, GLuint *d) {
	m_pglex->glGetNamedProgramLocalParameterIuivEXT(a,b,c,d);
}

inline void glex::glTextureParameterIivEXT(GLuint a, GLenum b, GLenum c, const GLint *d) {
	m_pglex->glTextureParameterIivEXT(a,b,c,d);
}

inline void glex::glTextureParameterIuivEXT(GLuint a, GLenum b, GLenum c, const GLuint *d) {
	m_pglex->glTextureParameterIuivEXT(a,b,c,d);
}

inline void glex::glGetTextureParameterIivEXT(GLuint a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetTextureParameterIivEXT(a,b,c,d);
}

inline void glex::glGetTextureParameterIuivEXT(GLuint a, GLenum b, GLenum c, GLuint *d) {
	m_pglex->glGetTextureParameterIuivEXT(a,b,c,d);
}

inline void glex::glMultiTexParameterIivEXT(GLenum a, GLenum b, GLenum c, const GLint *d) {
	m_pglex->glMultiTexParameterIivEXT(a,b,c,d);
}

inline void glex::glMultiTexParameterIuivEXT(GLenum a, GLenum b, GLenum c, const GLuint *d) {
	m_pglex->glMultiTexParameterIuivEXT(a,b,c,d);
}

inline void glex::glGetMultiTexParameterIivEXT(GLenum a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetMultiTexParameterIivEXT(a,b,c,d);
}

inline void glex::glGetMultiTexParameterIuivEXT(GLenum a, GLenum b, GLenum c, GLuint *d) {
	m_pglex->glGetMultiTexParameterIuivEXT(a,b,c,d);
}

inline void glex::glProgramUniform1fEXT(GLuint a, GLint b, GLfloat c) {
	m_pglex->glProgramUniform1fEXT(a,b,c);
}

inline void glex::glProgramUniform2fEXT(GLuint a, GLint b, GLfloat c, GLfloat d) {
	m_pglex->glProgramUniform2fEXT(a,b,c,d);
}

inline void glex::glProgramUniform3fEXT(GLuint a, GLint b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glProgramUniform3fEXT(a,b,c,d,e);
}

inline void glex::glProgramUniform4fEXT(GLuint a, GLint b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glProgramUniform4fEXT(a,b,c,d,e,f);
}

inline void glex::glProgramUniform1iEXT(GLuint a, GLint b, GLint c) {
	m_pglex->glProgramUniform1iEXT(a,b,c);
}

inline void glex::glProgramUniform2iEXT(GLuint a, GLint b, GLint c, GLint d) {
	m_pglex->glProgramUniform2iEXT(a,b,c,d);
}

inline void glex::glProgramUniform3iEXT(GLuint a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glProgramUniform3iEXT(a,b,c,d,e);
}

inline void glex::glProgramUniform4iEXT(GLuint a, GLint b, GLint c, GLint d, GLint e, GLint f) {
	m_pglex->glProgramUniform4iEXT(a,b,c,d,e,f);
}

inline void glex::glProgramUniform1fvEXT(GLuint a, GLint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramUniform1fvEXT(a,b,c,d);
}

inline void glex::glProgramUniform2fvEXT(GLuint a, GLint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramUniform2fvEXT(a,b,c,d);
}

inline void glex::glProgramUniform3fvEXT(GLuint a, GLint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramUniform3fvEXT(a,b,c,d);
}

inline void glex::glProgramUniform4fvEXT(GLuint a, GLint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramUniform4fvEXT(a,b,c,d);
}

inline void glex::glProgramUniform1ivEXT(GLuint a, GLint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramUniform1ivEXT(a,b,c,d);
}

inline void glex::glProgramUniform2ivEXT(GLuint a, GLint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramUniform2ivEXT(a,b,c,d);
}

inline void glex::glProgramUniform3ivEXT(GLuint a, GLint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramUniform3ivEXT(a,b,c,d);
}

inline void glex::glProgramUniform4ivEXT(GLuint a, GLint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramUniform4ivEXT(a,b,c,d);
}

inline void glex::glProgramUniformMatrix2fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix2fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix3fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix4fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix2x3fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix2x3fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3x2fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix3x2fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix2x4fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix2x4fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4x2fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix4x2fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3x4fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix3x4fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4x3fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix4x3fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniform1uiEXT(GLuint a, GLint b, GLuint c) {
	m_pglex->glProgramUniform1uiEXT(a,b,c);
}

inline void glex::glProgramUniform2uiEXT(GLuint a, GLint b, GLuint c, GLuint d) {
	m_pglex->glProgramUniform2uiEXT(a,b,c,d);
}

inline void glex::glProgramUniform3uiEXT(GLuint a, GLint b, GLuint c, GLuint d, GLuint e) {
	m_pglex->glProgramUniform3uiEXT(a,b,c,d,e);
}

inline void glex::glProgramUniform4uiEXT(GLuint a, GLint b, GLuint c, GLuint d, GLuint e, GLuint f) {
	m_pglex->glProgramUniform4uiEXT(a,b,c,d,e,f);
}

inline void glex::glProgramUniform1uivEXT(GLuint a, GLint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramUniform1uivEXT(a,b,c,d);
}

inline void glex::glProgramUniform2uivEXT(GLuint a, GLint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramUniform2uivEXT(a,b,c,d);
}

inline void glex::glProgramUniform3uivEXT(GLuint a, GLint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramUniform3uivEXT(a,b,c,d);
}

inline void glex::glProgramUniform4uivEXT(GLuint a, GLint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramUniform4uivEXT(a,b,c,d);
}

inline void glex::glNamedBufferDataEXT(GLuint a, GLsizeiptr b, const GLvoid *c, GLenum d) {
	m_pglex->glNamedBufferDataEXT(a,b,c,d);
}

inline void glex::glNamedBufferSubDataEXT(GLuint a, GLintptr b, GLsizeiptr c, const GLvoid *d) {
	m_pglex->glNamedBufferSubDataEXT(a,b,c,d);
}

inline GLvoid* glex::glMapNamedBufferEXT(GLuint a, GLenum b) {
	return m_pglex->glMapNamedBufferEXT(a,b);
}

inline GLboolean glex::glUnmapNamedBufferEXT(GLuint a) {
	return m_pglex->glUnmapNamedBufferEXT(a);
}

inline GLvoid* glex::glMapNamedBufferRangeEXT(GLuint a, GLintptr b, GLsizeiptr c, GLbitfield d) {
	return m_pglex->glMapNamedBufferRangeEXT(a,b,c,d);
}

inline void glex::glFlushMappedNamedBufferRangeEXT(GLuint a, GLintptr b, GLsizeiptr c) {
	m_pglex->glFlushMappedNamedBufferRangeEXT(a,b,c);
}

inline void glex::glNamedCopyBufferSubDataEXT(GLuint a, GLuint b, GLintptr c, GLintptr d, GLsizeiptr e) {
	m_pglex->glNamedCopyBufferSubDataEXT(a,b,c,d,e);
}

inline void glex::glGetNamedBufferParameterivEXT(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetNamedBufferParameterivEXT(a,b,c);
}

inline void glex::glGetNamedBufferPointervEXT(GLuint a, GLenum b, GLvoid* *c) {
	m_pglex->glGetNamedBufferPointervEXT(a,b,c);
}

inline void glex::glGetNamedBufferSubDataEXT(GLuint a, GLintptr b, GLsizeiptr c, GLvoid *d) {
	m_pglex->glGetNamedBufferSubDataEXT(a,b,c,d);
}

inline void glex::glTextureBufferEXT(GLuint a, GLenum b, GLenum c, GLuint d) {
	m_pglex->glTextureBufferEXT(a,b,c,d);
}

inline void glex::glMultiTexBufferEXT(GLenum a, GLenum b, GLenum c, GLuint d) {
	m_pglex->glMultiTexBufferEXT(a,b,c,d);
}

inline void glex::glNamedRenderbufferStorageEXT(GLuint a, GLenum b, GLsizei c, GLsizei d) {
	m_pglex->glNamedRenderbufferStorageEXT(a,b,c,d);
}

inline void glex::glGetNamedRenderbufferParameterivEXT(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetNamedRenderbufferParameterivEXT(a,b,c);
}

inline GLenum glex::glCheckNamedFramebufferStatusEXT(GLuint a, GLenum b) {
	return m_pglex->glCheckNamedFramebufferStatusEXT(a,b);
}

inline void glex::glNamedFramebufferTexture1DEXT(GLuint a, GLenum b, GLenum c, GLuint d, GLint e) {
	m_pglex->glNamedFramebufferTexture1DEXT(a,b,c,d,e);
}

inline void glex::glNamedFramebufferTexture2DEXT(GLuint a, GLenum b, GLenum c, GLuint d, GLint e) {
	m_pglex->glNamedFramebufferTexture2DEXT(a,b,c,d,e);
}

inline void glex::glNamedFramebufferTexture3DEXT(GLuint a, GLenum b, GLenum c, GLuint d, GLint e, GLint f) {
	m_pglex->glNamedFramebufferTexture3DEXT(a,b,c,d,e,f);
}

inline void glex::glNamedFramebufferRenderbufferEXT(GLuint a, GLenum b, GLenum c, GLuint d) {
	m_pglex->glNamedFramebufferRenderbufferEXT(a,b,c,d);
}

inline void glex::glGetNamedFramebufferAttachmentParameterivEXT(GLuint a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetNamedFramebufferAttachmentParameterivEXT(a,b,c,d);
}

inline void glex::glGenerateTextureMipmapEXT(GLuint a, GLenum b) {
	m_pglex->glGenerateTextureMipmapEXT(a,b);
}

inline void glex::glGenerateMultiTexMipmapEXT(GLenum a, GLenum b) {
	m_pglex->glGenerateMultiTexMipmapEXT(a,b);
}

inline void glex::glFramebufferDrawBufferEXT(GLuint a, GLenum b) {
	m_pglex->glFramebufferDrawBufferEXT(a,b);
}

inline void glex::glFramebufferDrawBuffersEXT(GLuint a, GLsizei b, const GLenum *c) {
	m_pglex->glFramebufferDrawBuffersEXT(a,b,c);
}

inline void glex::glFramebufferReadBufferEXT(GLuint a, GLenum b) {
	m_pglex->glFramebufferReadBufferEXT(a,b);
}

inline void glex::glGetFramebufferParameterivEXT(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetFramebufferParameterivEXT(a,b,c);
}

inline void glex::glNamedRenderbufferStorageMultisampleEXT(GLuint a, GLsizei b, GLenum c, GLsizei d, GLsizei e) {
	m_pglex->glNamedRenderbufferStorageMultisampleEXT(a,b,c,d,e);
}

inline void glex::glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint a, GLsizei b, GLsizei c, GLenum d, GLsizei e, GLsizei f) {
	m_pglex->glNamedRenderbufferStorageMultisampleCoverageEXT(a,b,c,d,e,f);
}

inline void glex::glNamedFramebufferTextureEXT(GLuint a, GLenum b, GLuint c, GLint d) {
	m_pglex->glNamedFramebufferTextureEXT(a,b,c,d);
}

inline void glex::glNamedFramebufferTextureLayerEXT(GLuint a, GLenum b, GLuint c, GLint d, GLint e) {
	m_pglex->glNamedFramebufferTextureLayerEXT(a,b,c,d,e);
}

inline void glex::glNamedFramebufferTextureFaceEXT(GLuint a, GLenum b, GLuint c, GLint d, GLenum e) {
	m_pglex->glNamedFramebufferTextureFaceEXT(a,b,c,d,e);
}

inline void glex::glTextureRenderbufferEXT(GLuint a, GLenum b, GLuint c) {
	m_pglex->glTextureRenderbufferEXT(a,b,c);
}

inline void glex::glMultiTexRenderbufferEXT(GLenum a, GLenum b, GLuint c) {
	m_pglex->glMultiTexRenderbufferEXT(a,b,c);
}

inline void glex::glProgramUniform1dEXT(GLuint a, GLint b, GLdouble c) {
	m_pglex->glProgramUniform1dEXT(a,b,c);
}

inline void glex::glProgramUniform2dEXT(GLuint a, GLint b, GLdouble c, GLdouble d) {
	m_pglex->glProgramUniform2dEXT(a,b,c,d);
}

inline void glex::glProgramUniform3dEXT(GLuint a, GLint b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glProgramUniform3dEXT(a,b,c,d,e);
}

inline void glex::glProgramUniform4dEXT(GLuint a, GLint b, GLdouble c, GLdouble d, GLdouble e, GLdouble f) {
	m_pglex->glProgramUniform4dEXT(a,b,c,d,e,f);
}

inline void glex::glProgramUniform1dvEXT(GLuint a, GLint b, GLsizei c, const GLdouble *d) {
	m_pglex->glProgramUniform1dvEXT(a,b,c,d);
}

inline void glex::glProgramUniform2dvEXT(GLuint a, GLint b, GLsizei c, const GLdouble *d) {
	m_pglex->glProgramUniform2dvEXT(a,b,c,d);
}

inline void glex::glProgramUniform3dvEXT(GLuint a, GLint b, GLsizei c, const GLdouble *d) {
	m_pglex->glProgramUniform3dvEXT(a,b,c,d);
}

inline void glex::glProgramUniform4dvEXT(GLuint a, GLint b, GLsizei c, const GLdouble *d) {
	m_pglex->glProgramUniform4dvEXT(a,b,c,d);
}

inline void glex::glProgramUniformMatrix2dvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix2dvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3dvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix3dvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4dvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix4dvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix2x3dvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix2x3dvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix2x4dvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix2x4dvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3x2dvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix3x2dvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3x4dvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix3x4dvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4x2dvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix4x2dvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4x3dvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLdouble *e) {
	m_pglex->glProgramUniformMatrix4x3dvEXT(a,b,c,d,e);
}

inline void glex::glGetMultisamplefvNV(GLenum a, GLuint b, GLfloat *c) {
	m_pglex->glGetMultisamplefvNV(a,b,c);
}

inline void glex::glSampleMaskIndexedNV(GLuint a, GLbitfield b) {
	m_pglex->glSampleMaskIndexedNV(a,b);
}

inline void glex::glTexRenderbufferNV(GLenum a, GLuint b) {
	m_pglex->glTexRenderbufferNV(a,b);
}

inline void glex::glBindTransformFeedbackNV(GLenum a, GLuint b) {
	m_pglex->glBindTransformFeedbackNV(a,b);
}

inline void glex::glDeleteTransformFeedbacksNV(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteTransformFeedbacksNV(a,b);
}

inline void glex::glGenTransformFeedbacksNV(GLsizei a, GLuint *b) {
	m_pglex->glGenTransformFeedbacksNV(a,b);
}

inline GLboolean glex::glIsTransformFeedbackNV(GLuint a) {
	return m_pglex->glIsTransformFeedbackNV(a);
}

inline void glex::glPauseTransformFeedbackNV(void) {
	m_pglex->glPauseTransformFeedbackNV();
}

inline void glex::glResumeTransformFeedbackNV(void) {
	m_pglex->glResumeTransformFeedbackNV();
}

inline void glex::glDrawTransformFeedbackNV(GLenum a, GLuint b) {
	m_pglex->glDrawTransformFeedbackNV(a,b);
}

inline void glex::glGetPerfMonitorGroupsAMD(GLint *a, GLsizei b, GLuint *c) {
	m_pglex->glGetPerfMonitorGroupsAMD(a,b,c);
}

inline void glex::glGetPerfMonitorCountersAMD(GLuint a, GLint *b, GLint *c, GLsizei d, GLuint *e) {
	m_pglex->glGetPerfMonitorCountersAMD(a,b,c,d,e);
}

inline void glex::glGetPerfMonitorGroupStringAMD(GLuint a, GLsizei b, GLsizei *c, GLchar *d) {
	m_pglex->glGetPerfMonitorGroupStringAMD(a,b,c,d);
}

inline void glex::glGetPerfMonitorCounterStringAMD(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLchar *e) {
	m_pglex->glGetPerfMonitorCounterStringAMD(a,b,c,d,e);
}

inline void glex::glGetPerfMonitorCounterInfoAMD(GLuint a, GLuint b, GLenum c, GLvoid *d) {
	m_pglex->glGetPerfMonitorCounterInfoAMD(a,b,c,d);
}

inline void glex::glGenPerfMonitorsAMD(GLsizei a, GLuint *b) {
	m_pglex->glGenPerfMonitorsAMD(a,b);
}

inline void glex::glDeletePerfMonitorsAMD(GLsizei a, GLuint *b) {
	m_pglex->glDeletePerfMonitorsAMD(a,b);
}

inline void glex::glSelectPerfMonitorCountersAMD(GLuint a, GLboolean b, GLuint c, GLint d, GLuint *e) {
	m_pglex->glSelectPerfMonitorCountersAMD(a,b,c,d,e);
}

inline void glex::glBeginPerfMonitorAMD(GLuint a) {
	m_pglex->glBeginPerfMonitorAMD(a);
}

inline void glex::glEndPerfMonitorAMD(GLuint a) {
	m_pglex->glEndPerfMonitorAMD(a);
}

inline void glex::glGetPerfMonitorCounterDataAMD(GLuint a, GLenum b, GLsizei c, GLuint *d, GLint *e) {
	m_pglex->glGetPerfMonitorCounterDataAMD(a,b,c,d,e);
}

inline void glex::glTessellationFactorAMD(GLfloat a) {
	m_pglex->glTessellationFactorAMD(a);
}

inline void glex::glTessellationModeAMD(GLenum a) {
	m_pglex->glTessellationModeAMD(a);
}

inline void glex::glProvokingVertexEXT(GLenum a) {
	m_pglex->glProvokingVertexEXT(a);
}

inline void glex::glBlendFuncIndexedAMD(GLuint a, GLenum b, GLenum c) {
	m_pglex->glBlendFuncIndexedAMD(a,b,c);
}

inline void glex::glBlendFuncSeparateIndexedAMD(GLuint a, GLenum b, GLenum c, GLenum d, GLenum e) {
	m_pglex->glBlendFuncSeparateIndexedAMD(a,b,c,d,e);
}

inline void glex::glBlendEquationIndexedAMD(GLuint a, GLenum b) {
	m_pglex->glBlendEquationIndexedAMD(a,b);
}

inline void glex::glBlendEquationSeparateIndexedAMD(GLuint a, GLenum b, GLenum c) {
	m_pglex->glBlendEquationSeparateIndexedAMD(a,b,c);
}

inline void glex::glTextureRangeAPPLE(GLenum a, GLsizei b, const GLvoid *c) {
	m_pglex->glTextureRangeAPPLE(a,b,c);
}

inline void glex::glGetTexParameterPointervAPPLE(GLenum a, GLenum b, GLvoid* *c) {
	m_pglex->glGetTexParameterPointervAPPLE(a,b,c);
}

inline void glex::glEnableVertexAttribAPPLE(GLuint a, GLenum b) {
	m_pglex->glEnableVertexAttribAPPLE(a,b);
}

inline void glex::glDisableVertexAttribAPPLE(GLuint a, GLenum b) {
	m_pglex->glDisableVertexAttribAPPLE(a,b);
}

inline GLboolean glex::glIsVertexAttribEnabledAPPLE(GLuint a, GLenum b) {
	return m_pglex->glIsVertexAttribEnabledAPPLE(a,b);
}

inline void glex::glMapVertexAttrib1dAPPLE(GLuint a, GLuint b, GLdouble c, GLdouble d, GLint e, GLint f, const GLdouble *g) {
	m_pglex->glMapVertexAttrib1dAPPLE(a,b,c,d,e,f,g);
}

inline void glex::glMapVertexAttrib1fAPPLE(GLuint a, GLuint b, GLfloat c, GLfloat d, GLint e, GLint f, const GLfloat *g) {
	m_pglex->glMapVertexAttrib1fAPPLE(a,b,c,d,e,f,g);
}

inline void glex::glMapVertexAttrib2dAPPLE(GLuint a, GLuint b, GLdouble c, GLdouble d, GLint e, GLint f, GLdouble g, GLdouble h, GLint i, GLint j, const GLdouble *k) {
	m_pglex->glMapVertexAttrib2dAPPLE(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glMapVertexAttrib2fAPPLE(GLuint a, GLuint b, GLfloat c, GLfloat d, GLint e, GLint f, GLfloat g, GLfloat h, GLint i, GLint j, const GLfloat *k) {
	m_pglex->glMapVertexAttrib2fAPPLE(a,b,c,d,e,f,g,h,i,j,k);
}

inline GLenum glex::glObjectPurgeableAPPLE(GLenum a, GLuint b, GLenum c) {
	return m_pglex->glObjectPurgeableAPPLE(a,b,c);
}

inline GLenum glex::glObjectUnpurgeableAPPLE(GLenum a, GLuint b, GLenum c) {
	return m_pglex->glObjectUnpurgeableAPPLE(a,b,c);
}

inline void glex::glGetObjectParameterivAPPLE(GLenum a, GLuint b, GLenum c, GLint *d) {
	m_pglex->glGetObjectParameterivAPPLE(a,b,c,d);
}

inline void glex::glBeginVideoCaptureNV(GLuint a) {
	m_pglex->glBeginVideoCaptureNV(a);
}

inline void glex::glBindVideoCaptureStreamBufferNV(GLuint a, GLuint b, GLenum c, GLintptrARB d) {
	m_pglex->glBindVideoCaptureStreamBufferNV(a,b,c,d);
}

inline void glex::glBindVideoCaptureStreamTextureNV(GLuint a, GLuint b, GLenum c, GLenum d, GLuint e) {
	m_pglex->glBindVideoCaptureStreamTextureNV(a,b,c,d,e);
}

inline void glex::glEndVideoCaptureNV(GLuint a) {
	m_pglex->glEndVideoCaptureNV(a);
}

inline void glex::glGetVideoCaptureivNV(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVideoCaptureivNV(a,b,c);
}

inline void glex::glGetVideoCaptureStreamivNV(GLuint a, GLuint b, GLenum c, GLint *d) {
	m_pglex->glGetVideoCaptureStreamivNV(a,b,c,d);
}

inline void glex::glGetVideoCaptureStreamfvNV(GLuint a, GLuint b, GLenum c, GLfloat *d) {
	m_pglex->glGetVideoCaptureStreamfvNV(a,b,c,d);
}

inline void glex::glGetVideoCaptureStreamdvNV(GLuint a, GLuint b, GLenum c, GLdouble *d) {
	m_pglex->glGetVideoCaptureStreamdvNV(a,b,c,d);
}

inline GLenum glex::glVideoCaptureNV(GLuint a, GLuint *b, GLuint64EXT *c) {
	return m_pglex->glVideoCaptureNV(a,b,c);
}

inline void glex::glVideoCaptureStreamParameterivNV(GLuint a, GLuint b, GLenum c, const GLint *d) {
	m_pglex->glVideoCaptureStreamParameterivNV(a,b,c,d);
}

inline void glex::glVideoCaptureStreamParameterfvNV(GLuint a, GLuint b, GLenum c, const GLfloat *d) {
	m_pglex->glVideoCaptureStreamParameterfvNV(a,b,c,d);
}

inline void glex::glVideoCaptureStreamParameterdvNV(GLuint a, GLuint b, GLenum c, const GLdouble *d) {
	m_pglex->glVideoCaptureStreamParameterdvNV(a,b,c,d);
}

inline void glex::glCopyImageSubDataNV(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLuint g, GLenum h, GLint i, GLint j, GLint k, GLint l, GLsizei m, GLsizei n, GLsizei o) {
	m_pglex->glCopyImageSubDataNV(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o);
}

inline void glex::glUseShaderProgramEXT(GLenum a, GLuint b) {
	m_pglex->glUseShaderProgramEXT(a,b);
}

inline void glex::glActiveProgramEXT(GLuint a) {
	m_pglex->glActiveProgramEXT(a);
}

inline GLuint glex::glCreateShaderProgramEXT(GLenum a, const GLchar *b) {
	return m_pglex->glCreateShaderProgramEXT(a,b);
}

inline void glex::glMakeBufferResidentNV(GLenum a, GLenum b) {
	m_pglex->glMakeBufferResidentNV(a,b);
}

inline void glex::glMakeBufferNonResidentNV(GLenum a) {
	m_pglex->glMakeBufferNonResidentNV(a);
}

inline GLboolean glex::glIsBufferResidentNV(GLenum a) {
	return m_pglex->glIsBufferResidentNV(a);
}

inline void glex::glMakeNamedBufferResidentNV(GLuint a, GLenum b) {
	m_pglex->glMakeNamedBufferResidentNV(a,b);
}

inline void glex::glMakeNamedBufferNonResidentNV(GLuint a) {
	m_pglex->glMakeNamedBufferNonResidentNV(a);
}

inline GLboolean glex::glIsNamedBufferResidentNV(GLuint a) {
	return m_pglex->glIsNamedBufferResidentNV(a);
}

inline void glex::glGetBufferParameterui64vNV(GLenum a, GLenum b, GLuint64EXT *c) {
	m_pglex->glGetBufferParameterui64vNV(a,b,c);
}

inline void glex::glGetNamedBufferParameterui64vNV(GLuint a, GLenum b, GLuint64EXT *c) {
	m_pglex->glGetNamedBufferParameterui64vNV(a,b,c);
}

inline void glex::glGetIntegerui64vNV(GLenum a, GLuint64EXT *b) {
	m_pglex->glGetIntegerui64vNV(a,b);
}

inline void glex::glUniformui64NV(GLint a, GLuint64EXT b) {
	m_pglex->glUniformui64NV(a,b);
}

inline void glex::glUniformui64vNV(GLint a, GLsizei b, const GLuint64EXT *c) {
	m_pglex->glUniformui64vNV(a,b,c);
}

inline void glex::glGetUniformui64vNV(GLuint a, GLint b, GLuint64EXT *c) {
	m_pglex->glGetUniformui64vNV(a,b,c);
}

inline void glex::glProgramUniformui64NV(GLuint a, GLint b, GLuint64EXT c) {
	m_pglex->glProgramUniformui64NV(a,b,c);
}

inline void glex::glProgramUniformui64vNV(GLuint a, GLint b, GLsizei c, const GLuint64EXT *d) {
	m_pglex->glProgramUniformui64vNV(a,b,c,d);
}

inline void glex::glBufferAddressRangeNV(GLenum a, GLuint b, GLuint64EXT c, GLsizeiptr d) {
	m_pglex->glBufferAddressRangeNV(a,b,c,d);
}

inline void glex::glVertexFormatNV(GLint a, GLenum b, GLsizei c) {
	m_pglex->glVertexFormatNV(a,b,c);
}

inline void glex::glNormalFormatNV(GLenum a, GLsizei b) {
	m_pglex->glNormalFormatNV(a,b);
}

inline void glex::glColorFormatNV(GLint a, GLenum b, GLsizei c) {
	m_pglex->glColorFormatNV(a,b,c);
}

inline void glex::glIndexFormatNV(GLenum a, GLsizei b) {
	m_pglex->glIndexFormatNV(a,b);
}

inline void glex::glTexCoordFormatNV(GLint a, GLenum b, GLsizei c) {
	m_pglex->glTexCoordFormatNV(a,b,c);
}

inline void glex::glEdgeFlagFormatNV(GLsizei a) {
	m_pglex->glEdgeFlagFormatNV(a);
}

inline void glex::glSecondaryColorFormatNV(GLint a, GLenum b, GLsizei c) {
	m_pglex->glSecondaryColorFormatNV(a,b,c);
}

inline void glex::glFogCoordFormatNV(GLenum a, GLsizei b) {
	m_pglex->glFogCoordFormatNV(a,b);
}

inline void glex::glVertexAttribFormatNV(GLuint a, GLint b, GLenum c, GLboolean d, GLsizei e) {
	m_pglex->glVertexAttribFormatNV(a,b,c,d,e);
}

inline void glex::glVertexAttribIFormatNV(GLuint a, GLint b, GLenum c, GLsizei d) {
	m_pglex->glVertexAttribIFormatNV(a,b,c,d);
}

inline void glex::glGetIntegerui64i_vNV(GLenum a, GLuint b, GLuint64EXT *c) {
	m_pglex->glGetIntegerui64i_vNV(a,b,c);
}

inline void glex::glTextureBarrierNV(void) {
	m_pglex->glTextureBarrierNV();
}

inline void glex::glBindImageTextureEXT(GLuint a, GLuint b, GLint c, GLboolean d, GLint e, GLenum f, GLint g) {
	m_pglex->glBindImageTextureEXT(a,b,c,d,e,f,g);
}

inline void glex::glMemoryBarrierEXT(GLbitfield a) {
	m_pglex->glMemoryBarrierEXT(a);
}

inline void glex::glVertexAttribL1dEXT(GLuint a, GLdouble b) {
	m_pglex->glVertexAttribL1dEXT(a,b);
}

inline void glex::glVertexAttribL2dEXT(GLuint a, GLdouble b, GLdouble c) {
	m_pglex->glVertexAttribL2dEXT(a,b,c);
}

inline void glex::glVertexAttribL3dEXT(GLuint a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glVertexAttribL3dEXT(a,b,c,d);
}

inline void glex::glVertexAttribL4dEXT(GLuint a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glVertexAttribL4dEXT(a,b,c,d,e);
}

inline void glex::glVertexAttribL1dvEXT(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttribL1dvEXT(a,b);
}

inline void glex::glVertexAttribL2dvEXT(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttribL2dvEXT(a,b);
}

inline void glex::glVertexAttribL3dvEXT(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttribL3dvEXT(a,b);
}

inline void glex::glVertexAttribL4dvEXT(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttribL4dvEXT(a,b);
}

inline void glex::glVertexAttribLPointerEXT(GLuint a, GLint b, GLenum c, GLsizei d, const GLvoid *e) {
	m_pglex->glVertexAttribLPointerEXT(a,b,c,d,e);
}

inline void glex::glGetVertexAttribLdvEXT(GLuint a, GLenum b, GLdouble *c) {
	m_pglex->glGetVertexAttribLdvEXT(a,b,c);
}

inline void glex::glVertexArrayVertexAttribLOffsetEXT(GLuint a, GLuint b, GLuint c, GLint d, GLenum e, GLsizei f, GLintptr g) {
	m_pglex->glVertexArrayVertexAttribLOffsetEXT(a,b,c,d,e,f,g);
}

inline void glex::glProgramSubroutineParametersuivNV(GLenum a, GLsizei b, const GLuint *c) {
	m_pglex->glProgramSubroutineParametersuivNV(a,b,c);
}

inline void glex::glGetProgramSubroutineParameteruivNV(GLenum a, GLuint b, GLuint *c) {
	m_pglex->glGetProgramSubroutineParameteruivNV(a,b,c);
}

inline void glex::glUniform1i64NV(GLint a, GLint64EXT b) {
	m_pglex->glUniform1i64NV(a,b);
}

inline void glex::glUniform2i64NV(GLint a, GLint64EXT b, GLint64EXT c) {
	m_pglex->glUniform2i64NV(a,b,c);
}

inline void glex::glUniform3i64NV(GLint a, GLint64EXT b, GLint64EXT c, GLint64EXT d) {
	m_pglex->glUniform3i64NV(a,b,c,d);
}

inline void glex::glUniform4i64NV(GLint a, GLint64EXT b, GLint64EXT c, GLint64EXT d, GLint64EXT e) {
	m_pglex->glUniform4i64NV(a,b,c,d,e);
}

inline void glex::glUniform1i64vNV(GLint a, GLsizei b, const GLint64EXT *c) {
	m_pglex->glUniform1i64vNV(a,b,c);
}

inline void glex::glUniform2i64vNV(GLint a, GLsizei b, const GLint64EXT *c) {
	m_pglex->glUniform2i64vNV(a,b,c);
}

inline void glex::glUniform3i64vNV(GLint a, GLsizei b, const GLint64EXT *c) {
	m_pglex->glUniform3i64vNV(a,b,c);
}

inline void glex::glUniform4i64vNV(GLint a, GLsizei b, const GLint64EXT *c) {
	m_pglex->glUniform4i64vNV(a,b,c);
}

inline void glex::glUniform1ui64NV(GLint a, GLuint64EXT b) {
	m_pglex->glUniform1ui64NV(a,b);
}

inline void glex::glUniform2ui64NV(GLint a, GLuint64EXT b, GLuint64EXT c) {
	m_pglex->glUniform2ui64NV(a,b,c);
}

inline void glex::glUniform3ui64NV(GLint a, GLuint64EXT b, GLuint64EXT c, GLuint64EXT d) {
	m_pglex->glUniform3ui64NV(a,b,c,d);
}

inline void glex::glUniform4ui64NV(GLint a, GLuint64EXT b, GLuint64EXT c, GLuint64EXT d, GLuint64EXT e) {
	m_pglex->glUniform4ui64NV(a,b,c,d,e);
}

inline void glex::glUniform1ui64vNV(GLint a, GLsizei b, const GLuint64EXT *c) {
	m_pglex->glUniform1ui64vNV(a,b,c);
}

inline void glex::glUniform2ui64vNV(GLint a, GLsizei b, const GLuint64EXT *c) {
	m_pglex->glUniform2ui64vNV(a,b,c);
}

inline void glex::glUniform3ui64vNV(GLint a, GLsizei b, const GLuint64EXT *c) {
	m_pglex->glUniform3ui64vNV(a,b,c);
}

inline void glex::glUniform4ui64vNV(GLint a, GLsizei b, const GLuint64EXT *c) {
	m_pglex->glUniform4ui64vNV(a,b,c);
}

inline void glex::glGetUniformi64vNV(GLuint a, GLint b, GLint64EXT *c) {
	m_pglex->glGetUniformi64vNV(a,b,c);
}

inline void glex::glProgramUniform1i64NV(GLuint a, GLint b, GLint64EXT c) {
	m_pglex->glProgramUniform1i64NV(a,b,c);
}

inline void glex::glProgramUniform2i64NV(GLuint a, GLint b, GLint64EXT c, GLint64EXT d) {
	m_pglex->glProgramUniform2i64NV(a,b,c,d);
}

inline void glex::glProgramUniform3i64NV(GLuint a, GLint b, GLint64EXT c, GLint64EXT d, GLint64EXT e) {
	m_pglex->glProgramUniform3i64NV(a,b,c,d,e);
}

inline void glex::glProgramUniform4i64NV(GLuint a, GLint b, GLint64EXT c, GLint64EXT d, GLint64EXT e, GLint64EXT f) {
	m_pglex->glProgramUniform4i64NV(a,b,c,d,e,f);
}

inline void glex::glProgramUniform1i64vNV(GLuint a, GLint b, GLsizei c, const GLint64EXT *d) {
	m_pglex->glProgramUniform1i64vNV(a,b,c,d);
}

inline void glex::glProgramUniform2i64vNV(GLuint a, GLint b, GLsizei c, const GLint64EXT *d) {
	m_pglex->glProgramUniform2i64vNV(a,b,c,d);
}

inline void glex::glProgramUniform3i64vNV(GLuint a, GLint b, GLsizei c, const GLint64EXT *d) {
	m_pglex->glProgramUniform3i64vNV(a,b,c,d);
}

inline void glex::glProgramUniform4i64vNV(GLuint a, GLint b, GLsizei c, const GLint64EXT *d) {
	m_pglex->glProgramUniform4i64vNV(a,b,c,d);
}

inline void glex::glProgramUniform1ui64NV(GLuint a, GLint b, GLuint64EXT c) {
	m_pglex->glProgramUniform1ui64NV(a,b,c);
}

inline void glex::glProgramUniform2ui64NV(GLuint a, GLint b, GLuint64EXT c, GLuint64EXT d) {
	m_pglex->glProgramUniform2ui64NV(a,b,c,d);
}

inline void glex::glProgramUniform3ui64NV(GLuint a, GLint b, GLuint64EXT c, GLuint64EXT d, GLuint64EXT e) {
	m_pglex->glProgramUniform3ui64NV(a,b,c,d,e);
}

inline void glex::glProgramUniform4ui64NV(GLuint a, GLint b, GLuint64EXT c, GLuint64EXT d, GLuint64EXT e, GLuint64EXT f) {
	m_pglex->glProgramUniform4ui64NV(a,b,c,d,e,f);
}

inline void glex::glProgramUniform1ui64vNV(GLuint a, GLint b, GLsizei c, const GLuint64EXT *d) {
	m_pglex->glProgramUniform1ui64vNV(a,b,c,d);
}

inline void glex::glProgramUniform2ui64vNV(GLuint a, GLint b, GLsizei c, const GLuint64EXT *d) {
	m_pglex->glProgramUniform2ui64vNV(a,b,c,d);
}

inline void glex::glProgramUniform3ui64vNV(GLuint a, GLint b, GLsizei c, const GLuint64EXT *d) {
	m_pglex->glProgramUniform3ui64vNV(a,b,c,d);
}

inline void glex::glProgramUniform4ui64vNV(GLuint a, GLint b, GLsizei c, const GLuint64EXT *d) {
	m_pglex->glProgramUniform4ui64vNV(a,b,c,d);
}

inline void glex::glVertexAttribL1i64NV(GLuint a, GLint64EXT b) {
	m_pglex->glVertexAttribL1i64NV(a,b);
}

inline void glex::glVertexAttribL2i64NV(GLuint a, GLint64EXT b, GLint64EXT c) {
	m_pglex->glVertexAttribL2i64NV(a,b,c);
}

inline void glex::glVertexAttribL3i64NV(GLuint a, GLint64EXT b, GLint64EXT c, GLint64EXT d) {
	m_pglex->glVertexAttribL3i64NV(a,b,c,d);
}

inline void glex::glVertexAttribL4i64NV(GLuint a, GLint64EXT b, GLint64EXT c, GLint64EXT d, GLint64EXT e) {
	m_pglex->glVertexAttribL4i64NV(a,b,c,d,e);
}

inline void glex::glVertexAttribL1i64vNV(GLuint a, const GLint64EXT *b) {
	m_pglex->glVertexAttribL1i64vNV(a,b);
}

inline void glex::glVertexAttribL2i64vNV(GLuint a, const GLint64EXT *b) {
	m_pglex->glVertexAttribL2i64vNV(a,b);
}

inline void glex::glVertexAttribL3i64vNV(GLuint a, const GLint64EXT *b) {
	m_pglex->glVertexAttribL3i64vNV(a,b);
}

inline void glex::glVertexAttribL4i64vNV(GLuint a, const GLint64EXT *b) {
	m_pglex->glVertexAttribL4i64vNV(a,b);
}

inline void glex::glVertexAttribL1ui64NV(GLuint a, GLuint64EXT b) {
	m_pglex->glVertexAttribL1ui64NV(a,b);
}

inline void glex::glVertexAttribL2ui64NV(GLuint a, GLuint64EXT b, GLuint64EXT c) {
	m_pglex->glVertexAttribL2ui64NV(a,b,c);
}

inline void glex::glVertexAttribL3ui64NV(GLuint a, GLuint64EXT b, GLuint64EXT c, GLuint64EXT d) {
	m_pglex->glVertexAttribL3ui64NV(a,b,c,d);
}

inline void glex::glVertexAttribL4ui64NV(GLuint a, GLuint64EXT b, GLuint64EXT c, GLuint64EXT d, GLuint64EXT e) {
	m_pglex->glVertexAttribL4ui64NV(a,b,c,d,e);
}

inline void glex::glVertexAttribL1ui64vNV(GLuint a, const GLuint64EXT *b) {
	m_pglex->glVertexAttribL1ui64vNV(a,b);
}

inline void glex::glVertexAttribL2ui64vNV(GLuint a, const GLuint64EXT *b) {
	m_pglex->glVertexAttribL2ui64vNV(a,b);
}

inline void glex::glVertexAttribL3ui64vNV(GLuint a, const GLuint64EXT *b) {
	m_pglex->glVertexAttribL3ui64vNV(a,b);
}

inline void glex::glVertexAttribL4ui64vNV(GLuint a, const GLuint64EXT *b) {
	m_pglex->glVertexAttribL4ui64vNV(a,b);
}

inline void glex::glGetVertexAttribLi64vNV(GLuint a, GLenum b, GLint64EXT *c) {
	m_pglex->glGetVertexAttribLi64vNV(a,b,c);
}

inline void glex::glGetVertexAttribLui64vNV(GLuint a, GLenum b, GLuint64EXT *c) {
	m_pglex->glGetVertexAttribLui64vNV(a,b,c);
}

inline void glex::glVertexAttribLFormatNV(GLuint a, GLint b, GLenum c, GLsizei d) {
	m_pglex->glVertexAttribLFormatNV(a,b,c,d);
}

inline void glex::glGenNamesAMD(GLenum a, GLuint b, GLuint *c) {
	m_pglex->glGenNamesAMD(a,b,c);
}

inline void glex::glDeleteNamesAMD(GLenum a, GLuint b, const GLuint *c) {
	m_pglex->glDeleteNamesAMD(a,b,c);
}

inline GLboolean glex::glIsNameAMD(GLenum a, GLuint b) {
	return m_pglex->glIsNameAMD(a,b);
}

inline void glex::glDebugMessageEnableAMD(GLenum a, GLenum b, GLsizei c, const GLuint *d, GLboolean e) {
	m_pglex->glDebugMessageEnableAMD(a,b,c,d,e);
}

inline void glex::glDebugMessageInsertAMD(GLenum a, GLenum b, GLuint c, GLsizei d, const GLchar *e) {
	m_pglex->glDebugMessageInsertAMD(a,b,c,d,e);
}

inline void glex::glDebugMessageCallbackAMD(GLDEBUGPROCAMD a, GLvoid *b) {
	m_pglex->glDebugMessageCallbackAMD(a,b);
}

inline GLuint glex::glGetDebugMessageLogAMD(GLuint a, GLsizei b, GLenum *c, GLuint *d, GLuint *e, GLsizei *f, GLchar *g) {
	return m_pglex->glGetDebugMessageLogAMD(a,b,c,d,e,f,g);
}

inline void glex::glVDPAUInitNV(const GLvoid *a, const GLvoid *b) {
	m_pglex->glVDPAUInitNV(a,b);
}

inline void glex::glVDPAUFiniNV(void) {
	m_pglex->glVDPAUFiniNV();
}

inline GLvdpauSurfaceNV glex::glVDPAURegisterVideoSurfaceNV(GLvoid *a, GLenum b, GLsizei c, const GLuint *d) {
	return m_pglex->glVDPAURegisterVideoSurfaceNV(a,b,c,d);
}

inline GLvdpauSurfaceNV glex::glVDPAURegisterOutputSurfaceNV(GLvoid *a, GLenum b, GLsizei c, const GLuint *d) {
	return m_pglex->glVDPAURegisterOutputSurfaceNV(a,b,c,d);
}

inline void glex::glVDPAUIsSurfaceNV(GLvdpauSurfaceNV a) {
	m_pglex->glVDPAUIsSurfaceNV(a);
}

inline void glex::glVDPAUUnregisterSurfaceNV(GLvdpauSurfaceNV a) {
	m_pglex->glVDPAUUnregisterSurfaceNV(a);
}

inline void glex::glVDPAUGetSurfaceivNV(GLvdpauSurfaceNV a, GLenum b, GLsizei c, GLsizei *d, GLint *e) {
	m_pglex->glVDPAUGetSurfaceivNV(a,b,c,d,e);
}

inline void glex::glVDPAUSurfaceAccessNV(GLvdpauSurfaceNV a, GLenum b) {
	m_pglex->glVDPAUSurfaceAccessNV(a,b);
}

inline void glex::glVDPAUMapSurfacesNV(GLsizei a, const GLvdpauSurfaceNV *b) {
	m_pglex->glVDPAUMapSurfacesNV(a,b);
}

inline void glex::glVDPAUUnmapSurfacesNV(GLsizei a, const GLvdpauSurfaceNV *b) {
	m_pglex->glVDPAUUnmapSurfacesNV(a,b);
}

inline void glex::glTexImage2DMultisampleCoverageNV(GLenum a, GLsizei b, GLsizei c, GLint d, GLsizei e, GLsizei f, GLboolean g) {
	m_pglex->glTexImage2DMultisampleCoverageNV(a,b,c,d,e,f,g);
}

inline void glex::glTexImage3DMultisampleCoverageNV(GLenum a, GLsizei b, GLsizei c, GLint d, GLsizei e, GLsizei f, GLsizei g, GLboolean h) {
	m_pglex->glTexImage3DMultisampleCoverageNV(a,b,c,d,e,f,g,h);
}

inline void glex::glTextureImage2DMultisampleNV(GLuint a, GLenum b, GLsizei c, GLint d, GLsizei e, GLsizei f, GLboolean g) {
	m_pglex->glTextureImage2DMultisampleNV(a,b,c,d,e,f,g);
}

inline void glex::glTextureImage3DMultisampleNV(GLuint a, GLenum b, GLsizei c, GLint d, GLsizei e, GLsizei f, GLsizei g, GLboolean h) {
	m_pglex->glTextureImage3DMultisampleNV(a,b,c,d,e,f,g,h);
}

inline void glex::glTextureImage2DMultisampleCoverageNV(GLuint a, GLenum b, GLsizei c, GLsizei d, GLint e, GLsizei f, GLsizei g, GLboolean h) {
	m_pglex->glTextureImage2DMultisampleCoverageNV(a,b,c,d,e,f,g,h);
}

inline void glex::glTextureImage3DMultisampleCoverageNV(GLuint a, GLenum b, GLsizei c, GLsizei d, GLint e, GLsizei f, GLsizei g, GLsizei h, GLboolean i) {
	m_pglex->glTextureImage3DMultisampleCoverageNV(a,b,c,d,e,f,g,h,i);
}

inline void glex::glSetMultisamplefvAMD(GLenum a, GLuint b, const GLfloat *c) {
	m_pglex->glSetMultisamplefvAMD(a,b,c);
}

inline GLsync glex::glImportSyncEXT(GLenum a, GLintptr b, GLbitfield c) {
	return m_pglex->glImportSyncEXT(a,b,c);
}

inline void glex::glMultiDrawArraysIndirectAMD(GLenum a, const GLvoid *b, GLsizei c, GLsizei d) {
	m_pglex->glMultiDrawArraysIndirectAMD(a,b,c,d);
}

inline void glex::glMultiDrawElementsIndirectAMD(GLenum a, GLenum b, const GLvoid *c, GLsizei d, GLsizei e) {
	m_pglex->glMultiDrawElementsIndirectAMD(a,b,c,d,e);
}

inline HANDLE glex::wglCreateBufferRegionARB(HDC a, int b, UINT c) {
	return m_pglex->wglCreateBufferRegionARB(a,b,c);
}

inline VOID glex::wglDeleteBufferRegionARB(HANDLE a) {
	m_pglex->wglDeleteBufferRegionARB(a);
}

inline BOOL glex::wglSaveBufferRegionARB(HANDLE a, int b, int c, int d, int e) {
	return m_pglex->wglSaveBufferRegionARB(a,b,c,d,e);
}

inline BOOL glex::wglRestoreBufferRegionARB(HANDLE a, int b, int c, int d, int e, int f, int g) {
	return m_pglex->wglRestoreBufferRegionARB(a,b,c,d,e,f,g);
}

inline const char * glex::wglGetExtensionsStringARB(HDC a) {
	return m_pglex->wglGetExtensionsStringARB(a);
}

inline BOOL glex::wglGetPixelFormatAttribivARB(HDC a, int b, int c, UINT d, const int *e, int *f) {
	return m_pglex->wglGetPixelFormatAttribivARB(a,b,c,d,e,f);
}

inline BOOL glex::wglGetPixelFormatAttribfvARB(HDC a, int b, int c, UINT d, const int *e, FLOAT *f) {
	return m_pglex->wglGetPixelFormatAttribfvARB(a,b,c,d,e,f);
}

inline BOOL glex::wglChoosePixelFormatARB(HDC a, const int *b, const FLOAT *c, UINT d, int *e, UINT *f) {
	return m_pglex->wglChoosePixelFormatARB(a,b,c,d,e,f);
}

inline BOOL glex::wglMakeContextCurrentARB(HDC a, HDC b, HGLRC c) {
	return m_pglex->wglMakeContextCurrentARB(a,b,c);
}

inline HDC glex::wglGetCurrentReadDCARB(void) {
	return m_pglex->wglGetCurrentReadDCARB();
}

inline HPBUFFERARB glex::wglCreatePbufferARB(HDC a, int b, int c, int d, const int *e) {
	return m_pglex->wglCreatePbufferARB(a,b,c,d,e);
}

inline HDC glex::wglGetPbufferDCARB(HPBUFFERARB a) {
	return m_pglex->wglGetPbufferDCARB(a);
}

inline int glex::wglReleasePbufferDCARB(HPBUFFERARB a, HDC b) {
	return m_pglex->wglReleasePbufferDCARB(a,b);
}

inline BOOL glex::wglDestroyPbufferARB(HPBUFFERARB a) {
	return m_pglex->wglDestroyPbufferARB(a);
}

inline BOOL glex::wglQueryPbufferARB(HPBUFFERARB a, int b, int *c) {
	return m_pglex->wglQueryPbufferARB(a,b,c);
}

inline BOOL glex::wglBindTexImageARB(HPBUFFERARB a, int b) {
	return m_pglex->wglBindTexImageARB(a,b);
}

inline BOOL glex::wglReleaseTexImageARB(HPBUFFERARB a, int b) {
	return m_pglex->wglReleaseTexImageARB(a,b);
}

inline BOOL glex::wglSetPbufferAttribARB(HPBUFFERARB a, const int *b) {
	return m_pglex->wglSetPbufferAttribARB(a,b);
}

inline HGLRC glex::wglCreateContextAttribsARB(HDC a, HGLRC b, const int *c) {
	return m_pglex->wglCreateContextAttribsARB(a,b,c);
}

inline GLboolean glex::wglCreateDisplayColorTableEXT(GLushort a) {
	return m_pglex->wglCreateDisplayColorTableEXT(a);
}

inline GLboolean glex::wglLoadDisplayColorTableEXT(const GLushort *a, GLuint b) {
	return m_pglex->wglLoadDisplayColorTableEXT(a,b);
}

inline GLboolean glex::wglBindDisplayColorTableEXT(GLushort a) {
	return m_pglex->wglBindDisplayColorTableEXT(a);
}

inline VOID glex::wglDestroyDisplayColorTableEXT(GLushort a) {
	m_pglex->wglDestroyDisplayColorTableEXT(a);
}

inline const char * glex::wglGetExtensionsStringEXT(void) {
	return m_pglex->wglGetExtensionsStringEXT();
}

inline BOOL glex::wglMakeContextCurrentEXT(HDC a, HDC b, HGLRC c) {
	return m_pglex->wglMakeContextCurrentEXT(a,b,c);
}

inline HDC glex::wglGetCurrentReadDCEXT(void) {
	return m_pglex->wglGetCurrentReadDCEXT();
}

inline HPBUFFEREXT glex::wglCreatePbufferEXT(HDC a, int b, int c, int d, const int *e) {
	return m_pglex->wglCreatePbufferEXT(a,b,c,d,e);
}

inline HDC glex::wglGetPbufferDCEXT(HPBUFFEREXT a) {
	return m_pglex->wglGetPbufferDCEXT(a);
}

inline int glex::wglReleasePbufferDCEXT(HPBUFFEREXT a, HDC b) {
	return m_pglex->wglReleasePbufferDCEXT(a,b);
}

inline BOOL glex::wglDestroyPbufferEXT(HPBUFFEREXT a) {
	return m_pglex->wglDestroyPbufferEXT(a);
}

inline BOOL glex::wglQueryPbufferEXT(HPBUFFEREXT a, int b, int *c) {
	return m_pglex->wglQueryPbufferEXT(a,b,c);
}

inline BOOL glex::wglGetPixelFormatAttribivEXT(HDC a, int b, int c, UINT d, int *e, int *f) {
	return m_pglex->wglGetPixelFormatAttribivEXT(a,b,c,d,e,f);
}

inline BOOL glex::wglGetPixelFormatAttribfvEXT(HDC a, int b, int c, UINT d, int *e, FLOAT *f) {
	return m_pglex->wglGetPixelFormatAttribfvEXT(a,b,c,d,e,f);
}

inline BOOL glex::wglChoosePixelFormatEXT(HDC a, const int *b, const FLOAT *c, UINT d, int *e, UINT *f) {
	return m_pglex->wglChoosePixelFormatEXT(a,b,c,d,e,f);
}

inline BOOL glex::wglSwapIntervalEXT(int a) {
	return m_pglex->wglSwapIntervalEXT(a);
}

inline int glex::wglGetSwapIntervalEXT(void) {
	return m_pglex->wglGetSwapIntervalEXT();
}

inline void* glex::wglAllocateMemoryNV(GLsizei a, GLfloat b, GLfloat c, GLfloat d) {
	return m_pglex->wglAllocateMemoryNV(a,b,c,d);
}

inline void glex::wglFreeMemoryNV(void *a) {
	m_pglex->wglFreeMemoryNV(a);
}

inline BOOL glex::wglGetSyncValuesOML(HDC a, INT64 *b, INT64 *c, INT64 *d) {
	return m_pglex->wglGetSyncValuesOML(a,b,c,d);
}

inline BOOL glex::wglGetMscRateOML(HDC a, INT32 *b, INT32 *c) {
	return m_pglex->wglGetMscRateOML(a,b,c);
}

inline INT64 glex::wglSwapBuffersMscOML(HDC a, INT64 b, INT64 c, INT64 d) {
	return m_pglex->wglSwapBuffersMscOML(a,b,c,d);
}

inline INT64 glex::wglSwapLayerBuffersMscOML(HDC a, int b, INT64 c, INT64 d, INT64 e) {
	return m_pglex->wglSwapLayerBuffersMscOML(a,b,c,d,e);
}

inline BOOL glex::wglWaitForMscOML(HDC a, INT64 b, INT64 c, INT64 d, INT64 *e, INT64 *f, INT64 *g) {
	return m_pglex->wglWaitForMscOML(a,b,c,d,e,f,g);
}

inline BOOL glex::wglWaitForSbcOML(HDC a, INT64 b, INT64 *c, INT64 *d, INT64 *e) {
	return m_pglex->wglWaitForSbcOML(a,b,c,d,e);
}

inline BOOL glex::wglGetDigitalVideoParametersI3D(HDC a, int b, int *c) {
	return m_pglex->wglGetDigitalVideoParametersI3D(a,b,c);
}

inline BOOL glex::wglSetDigitalVideoParametersI3D(HDC a, int b, const int *c) {
	return m_pglex->wglSetDigitalVideoParametersI3D(a,b,c);
}

inline BOOL glex::wglGetGammaTableParametersI3D(HDC a, int b, int *c) {
	return m_pglex->wglGetGammaTableParametersI3D(a,b,c);
}

inline BOOL glex::wglSetGammaTableParametersI3D(HDC a, int b, const int *c) {
	return m_pglex->wglSetGammaTableParametersI3D(a,b,c);
}

inline BOOL glex::wglGetGammaTableI3D(HDC a, int b, USHORT *c, USHORT *d, USHORT *e) {
	return m_pglex->wglGetGammaTableI3D(a,b,c,d,e);
}

inline BOOL glex::wglSetGammaTableI3D(HDC a, int b, const USHORT *c, const USHORT *d, const USHORT *e) {
	return m_pglex->wglSetGammaTableI3D(a,b,c,d,e);
}

inline BOOL glex::wglEnableGenlockI3D(HDC a) {
	return m_pglex->wglEnableGenlockI3D(a);
}

inline BOOL glex::wglDisableGenlockI3D(HDC a) {
	return m_pglex->wglDisableGenlockI3D(a);
}

inline BOOL glex::wglIsEnabledGenlockI3D(HDC a, BOOL *b) {
	return m_pglex->wglIsEnabledGenlockI3D(a,b);
}

inline BOOL glex::wglGenlockSourceI3D(HDC a, UINT b) {
	return m_pglex->wglGenlockSourceI3D(a,b);
}

inline BOOL glex::wglGetGenlockSourceI3D(HDC a, UINT *b) {
	return m_pglex->wglGetGenlockSourceI3D(a,b);
}

inline BOOL glex::wglGenlockSourceEdgeI3D(HDC a, UINT b) {
	return m_pglex->wglGenlockSourceEdgeI3D(a,b);
}

inline BOOL glex::wglGetGenlockSourceEdgeI3D(HDC a, UINT *b) {
	return m_pglex->wglGetGenlockSourceEdgeI3D(a,b);
}

inline BOOL glex::wglGenlockSampleRateI3D(HDC a, UINT b) {
	return m_pglex->wglGenlockSampleRateI3D(a,b);
}

inline BOOL glex::wglGetGenlockSampleRateI3D(HDC a, UINT *b) {
	return m_pglex->wglGetGenlockSampleRateI3D(a,b);
}

inline BOOL glex::wglGenlockSourceDelayI3D(HDC a, UINT b) {
	return m_pglex->wglGenlockSourceDelayI3D(a,b);
}

inline BOOL glex::wglGetGenlockSourceDelayI3D(HDC a, UINT *b) {
	return m_pglex->wglGetGenlockSourceDelayI3D(a,b);
}

inline BOOL glex::wglQueryGenlockMaxSourceDelayI3D(HDC a, UINT *b, UINT *c) {
	return m_pglex->wglQueryGenlockMaxSourceDelayI3D(a,b,c);
}

inline LPVOID glex::wglCreateImageBufferI3D(HDC a, DWORD b, UINT c) {
	return m_pglex->wglCreateImageBufferI3D(a,b,c);
}

inline BOOL glex::wglDestroyImageBufferI3D(HDC a, LPVOID b) {
	return m_pglex->wglDestroyImageBufferI3D(a,b);
}

inline BOOL glex::wglAssociateImageBufferEventsI3D(HDC a, const HANDLE *b, const LPVOID *c, const DWORD *d, UINT e) {
	return m_pglex->wglAssociateImageBufferEventsI3D(a,b,c,d,e);
}

inline BOOL glex::wglReleaseImageBufferEventsI3D(HDC a, const LPVOID *b, UINT c) {
	return m_pglex->wglReleaseImageBufferEventsI3D(a,b,c);
}

inline BOOL glex::wglEnableFrameLockI3D(void) {
	return m_pglex->wglEnableFrameLockI3D();
}

inline BOOL glex::wglDisableFrameLockI3D(void) {
	return m_pglex->wglDisableFrameLockI3D();
}

inline BOOL glex::wglIsEnabledFrameLockI3D(BOOL *a) {
	return m_pglex->wglIsEnabledFrameLockI3D(a);
}

inline BOOL glex::wglQueryFrameLockMasterI3D(BOOL *a) {
	return m_pglex->wglQueryFrameLockMasterI3D(a);
}

inline BOOL glex::wglGetFrameUsageI3D(float *a) {
	return m_pglex->wglGetFrameUsageI3D(a);
}

inline BOOL glex::wglBeginFrameTrackingI3D(void) {
	return m_pglex->wglBeginFrameTrackingI3D();
}

inline BOOL glex::wglEndFrameTrackingI3D(void) {
	return m_pglex->wglEndFrameTrackingI3D();
}

inline BOOL glex::wglQueryFrameTrackingI3D(DWORD *a, DWORD *b, float *c) {
	return m_pglex->wglQueryFrameTrackingI3D(a,b,c);
}

inline BOOL glex::wglSetStereoEmitterState3DL(HDC a, UINT b) {
	return m_pglex->wglSetStereoEmitterState3DL(a,b);
}

inline int glex::wglEnumerateVideoDevicesNV(HDC a, HVIDEOOUTPUTDEVICENV *b) {
	return m_pglex->wglEnumerateVideoDevicesNV(a,b);
}

inline BOOL glex::wglBindVideoDeviceNV(HDC a, unsigned int b, HVIDEOOUTPUTDEVICENV c, const int *d) {
	return m_pglex->wglBindVideoDeviceNV(a,b,c,d);
}

inline BOOL glex::wglQueryCurrentContextNV(int a, int *b) {
	return m_pglex->wglQueryCurrentContextNV(a,b);
}

inline BOOL glex::wglGetVideoDeviceNV(HDC a, int b, HPVIDEODEV *c) {
	return m_pglex->wglGetVideoDeviceNV(a,b,c);
}

inline BOOL glex::wglReleaseVideoDeviceNV(HPVIDEODEV a) {
	return m_pglex->wglReleaseVideoDeviceNV(a);
}

inline BOOL glex::wglBindVideoImageNV(HPVIDEODEV a, HPBUFFERARB b, int c) {
	return m_pglex->wglBindVideoImageNV(a,b,c);
}

inline BOOL glex::wglReleaseVideoImageNV(HPBUFFERARB a, int b) {
	return m_pglex->wglReleaseVideoImageNV(a,b);
}

inline BOOL glex::wglSendPbufferToVideoNV(HPBUFFERARB a, int b, unsigned long *c, BOOL d) {
	return m_pglex->wglSendPbufferToVideoNV(a,b,c,d);
}

inline BOOL glex::wglGetVideoInfoNV(HPVIDEODEV a, unsigned long *b, unsigned long *c) {
	return m_pglex->wglGetVideoInfoNV(a,b,c);
}

inline BOOL glex::wglJoinSwapGroupNV(HDC a, GLuint b) {
	return m_pglex->wglJoinSwapGroupNV(a,b);
}

inline BOOL glex::wglBindSwapBarrierNV(GLuint a, GLuint b) {
	return m_pglex->wglBindSwapBarrierNV(a,b);
}

inline BOOL glex::wglQuerySwapGroupNV(HDC a, GLuint *b, GLuint *c) {
	return m_pglex->wglQuerySwapGroupNV(a,b,c);
}

inline BOOL glex::wglQueryMaxSwapGroupsNV(HDC a, GLuint *b, GLuint *c) {
	return m_pglex->wglQueryMaxSwapGroupsNV(a,b,c);
}

inline BOOL glex::wglQueryFrameCountNV(HDC a, GLuint *b) {
	return m_pglex->wglQueryFrameCountNV(a,b);
}

inline BOOL glex::wglResetFrameCountNV(HDC a) {
	return m_pglex->wglResetFrameCountNV(a);
}

inline BOOL glex::wglEnumGpusNV(UINT a, HGPUNV *b) {
	return m_pglex->wglEnumGpusNV(a,b);
}

inline BOOL glex::wglEnumGpuDevicesNV(HGPUNV a, UINT b, PGPU_DEVICE c) {
	return m_pglex->wglEnumGpuDevicesNV(a,b,c);
}

inline HDC glex::wglCreateAffinityDCNV(const HGPUNV *a) {
	return m_pglex->wglCreateAffinityDCNV(a);
}

inline BOOL glex::wglEnumGpusFromAffinityDCNV(HDC a, UINT b, HGPUNV *c) {
	return m_pglex->wglEnumGpusFromAffinityDCNV(a,b,c);
}

inline BOOL glex::wglDeleteDCNV(HDC a) {
	return m_pglex->wglDeleteDCNV(a);
}

inline UINT glex::wglGetGPUIDsAMD(UINT a, UINT *b) {
	return m_pglex->wglGetGPUIDsAMD(a,b);
}

inline INT glex::wglGetGPUInfoAMD(UINT a, int b, GLenum c, UINT d, void *e) {
	return m_pglex->wglGetGPUInfoAMD(a,b,c,d,e);
}

inline UINT glex::wglGetContextGPUIDAMD(HGLRC a) {
	return m_pglex->wglGetContextGPUIDAMD(a);
}

inline HGLRC glex::wglCreateAssociatedContextAMD(UINT a) {
	return m_pglex->wglCreateAssociatedContextAMD(a);
}

inline HGLRC glex::wglCreateAssociatedContextAttribsAMD(UINT a, HGLRC b, const int *c) {
	return m_pglex->wglCreateAssociatedContextAttribsAMD(a,b,c);
}

inline BOOL glex::wglDeleteAssociatedContextAMD(HGLRC a) {
	return m_pglex->wglDeleteAssociatedContextAMD(a);
}

inline BOOL glex::wglMakeAssociatedContextCurrentAMD(HGLRC a) {
	return m_pglex->wglMakeAssociatedContextCurrentAMD(a);
}

inline HGLRC glex::wglGetCurrentAssociatedContextAMD(void) {
	return m_pglex->wglGetCurrentAssociatedContextAMD();
}

inline VOID glex::wglBlitContextFramebufferAMD(HGLRC a, GLint b, GLint c, GLint d, GLint e, GLint f, GLint g, GLint h, GLint i, GLbitfield j, GLenum k) {
	m_pglex->wglBlitContextFramebufferAMD(a,b,c,d,e,f,g,h,i,j,k);
}

inline BOOL glex::wglBindVideoCaptureDeviceNV(UINT a, HVIDEOINPUTDEVICENV b) {
	return m_pglex->wglBindVideoCaptureDeviceNV(a,b);
}

inline UINT glex::wglEnumerateVideoCaptureDevicesNV(HDC a, HVIDEOINPUTDEVICENV *b) {
	return m_pglex->wglEnumerateVideoCaptureDevicesNV(a,b);
}

inline BOOL glex::wglLockVideoCaptureDeviceNV(HDC a, HVIDEOINPUTDEVICENV b) {
	return m_pglex->wglLockVideoCaptureDeviceNV(a,b);
}

inline BOOL glex::wglQueryVideoCaptureDeviceNV(HDC a, HVIDEOINPUTDEVICENV b, int c, int *d) {
	return m_pglex->wglQueryVideoCaptureDeviceNV(a,b,c,d);
}

inline BOOL glex::wglReleaseVideoCaptureDeviceNV(HDC a, HVIDEOINPUTDEVICENV b) {
	return m_pglex->wglReleaseVideoCaptureDeviceNV(a,b);
}

inline BOOL glex::wglCopyImageSubDataNV(HGLRC a, GLuint b, GLenum c, GLint d, GLint e, GLint f, GLint g, HGLRC h, GLuint i, GLenum j, GLint k, GLint l, GLint m, GLint n, GLsizei o, GLsizei p, GLsizei q) {
	return m_pglex->wglCopyImageSubDataNV(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q);
}

inline BOOL glex::wglDXSetResourceShareHandleNV(void *a, HANDLE b) {
	return m_pglex->wglDXSetResourceShareHandleNV(a,b);
}

inline HANDLE glex::wglDXOpenDeviceNV(void *a) {
	return m_pglex->wglDXOpenDeviceNV(a);
}

inline BOOL glex::wglDXCloseDeviceNV(HANDLE a) {
	return m_pglex->wglDXCloseDeviceNV(a);
}

inline HANDLE glex::wglDXRegisterObjectNV(HANDLE a, void *b, GLuint c, GLenum d, GLenum e) {
	return m_pglex->wglDXRegisterObjectNV(a,b,c,d,e);
}

inline BOOL glex::wglDXUnregisterObjectNV(HANDLE a, HANDLE b) {
	return m_pglex->wglDXUnregisterObjectNV(a,b);
}

inline BOOL glex::wglDXObjectAccessNV(HANDLE a, GLenum b) {
	return m_pglex->wglDXObjectAccessNV(a,b);
}

inline BOOL glex::wglDXLockObjectsNV(HANDLE a, GLint b, HANDLE *c) {
	return m_pglex->wglDXLockObjectsNV(a,b,c);
}

inline BOOL glex::wglDXUnlockObjectsNV(HANDLE a, GLint b, HANDLE *c) {
	return m_pglex->wglDXUnlockObjectsNV(a,b,c);
}

//----------------------------------------------------------------------------

#endif//__glex_h
