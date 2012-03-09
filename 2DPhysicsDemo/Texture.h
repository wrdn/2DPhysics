#pragma once

#include <GXBase.h>
#include "ctypes.h"
#include "GameResource.h"

enum OpenGLTextureSlot
{
	SLOT_GL_TEXTURE_0 = GL_TEXTURE0,
	SLOT_GL_TEXTURE_1 = GL_TEXTURE1,
	SLOT_GL_TEXTURE_2 = GL_TEXTURE2,
	SLOT_GL_TEXTURE_3 = GL_TEXTURE3,
	SLOT_GL_TEXTURE_4 = GL_TEXTURE4,
	SLOT_GL_TEXTURE_5 = GL_TEXTURE5,
	SLOT_GL_TEXTURE_6 = GL_TEXTURE6,
	SLOT_GL_TEXTURE_7 = GL_TEXTURE7,
};

class Texture : public Resource
{
private:
	u32 textureID;
	u32 minFilter, magFilter, wrapS, wrapT; // common texture properties
	u32 width, height;
	OpenGLTextureSlot glTexSlot;

public:
	Texture() : textureID(0), minFilter(GL_LINEAR_MIPMAP_LINEAR), magFilter(GL_LINEAR_MIPMAP_LINEAR), wrapS(GL_REPEAT), wrapT(GL_REPEAT),
		width(0), height(0), glTexSlot(SLOT_GL_TEXTURE_0)
	{
	};

	~Texture()
	{
		Unload();
	}; // REMEMBER: CAREFUL WITH TEXTURE ON STACK, TEXTURE IS DELETED IN DESTRUCTOR

	bool Load(const char *filename);

	void Unload();

	void Activate();
	void Deactivate() const;

	void SetParameteri(GLenum param, u32 v);
	void SetParameterf(GLenum param, f32 v);

	void SetWrapS(u32 wrap_s) { SetParameteri(GL_TEXTURE_WRAP_S, wrap_s); }
	void SetWrapT(u32 wrap_t) { SetParameteri(GL_TEXTURE_WRAP_T, wrap_t); }
	void SetMinFilter(u32 minFilter) { SetParameteri(GL_TEXTURE_MIN_FILTER, minFilter); }
	void SetMagFilter(u32 magFilter) { SetParameteri(GL_TEXTURE_MAG_FILTER, magFilter); }

	u32 GetGLTextureID() const { return textureID; };
	void SetTextureSlot(OpenGLTextureSlot s) { glTexSlot = s; };
	OpenGLTextureSlot GetTextureSlot() const { return glTexSlot; };
	u32 GetTextureSlotIndex() const { return glTexSlot - SLOT_GL_TEXTURE_0; };
};

typedef std::tr1::shared_ptr<Texture> TextureHandle;