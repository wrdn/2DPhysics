#pragma once

#include <vector>
#include "ctypes.h"
#include "GameResource.h"
#include <GXBase.h>
using namespace std;

struct FBOTexture
{
public:
	GLuint texID;
	u32 width, height;
	GLint internal_format;
	GLenum format;
	GLenum type;
	GLenum attachPoint;
};

class RenderTarget : public Resource, public glex
{
private:
	GLuint fbo_id; // frame buffer object id
	u32 width, height; // width and height of textures

	vector<FBOTexture> textures;
public:
	
	void Unload()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glBindTexture(GL_TEXTURE_2D,0);

		for(u32 i=0;i<textures.size();++i)
		{
			glDeleteTextures(1, &textures[i].texID);
		}
		textures.clear();

		if(fbo_id)
		{
			glDeleteFramebuffers(1, &fbo_id);
			fbo_id = 0;
		}
	};

	RenderTarget()
	{
		width = 800;
		height = 600;
		glGenFramebuffers(1, &fbo_id);

		glex::Load();
	};

	RenderTarget(u32 pwidth, u32 pheight)
	{
		width = pwidth;
		height = pheight;
		glGenFramebuffers(1, &fbo_id);

		glex::Load();
	};
	~RenderTarget()
	{
		Unload();
	};

	u32 GetWidth() const { return width; }
	u32 GetHeight() const { return height; }

	void SetDrawReadBufferState(GLenum gl_draw_buffer, GLenum gl_read_buffer)
	{
		Bind();
		glDrawBuffer(gl_draw_buffer);
		glReadBuffer(gl_read_buffer);
		Unbind();
	}

	void SetWidth(u32 w) { width = w; RecreateTextures(); }
	void SetHeight(u32 h) { height = h; RecreateTextures(); }
	void SetWidthAndHeight(u32 w, u32 h)
	{
		width = w;
		height = h;
		RecreateTextures();
	};

	void RecreateTextures()
	{
		for(u32 i=0;i<textures.size();++i)
		{
			FBOTexture &tex = textures[i];
			tex.width = width; tex.height = height;

			glBindTexture(GL_TEXTURE_2D, tex.texID);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexImage2D(GL_TEXTURE_2D, 0, tex.internal_format, tex.width, tex.height, 0, tex.format, tex.type, 0);

			Bind();
			glFramebufferTexture2D(GL_FRAMEBUFFER, tex.attachPoint , GL_TEXTURE_2D, tex.texID, 0);
			Unbind();
		}
		Unbind();
	};

	FBOTexture CreateDepthTexture()
	{
		return CreateAndAttachTexture(GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, GL_DEPTH_ATTACHMENT, false, GL_NEAREST, GL_NEAREST, GL_CLAMP, GL_CLAMP);
	};

	// note: for depth textures, there is only ever 1 attachment point (GL_DEPTH_ATTACHMENT), hence why CreateDepthTexture() takes no arguments
	// in contrast, there can be many color attachments, from GL_COLOR_ATTACHMENT0+0 to GL_COLOR_ATTACHMENT0+GL_MAX_COLOR_ATTACHMENTS-1
	FBOTexture CreateColorTexture(GLenum attachmentPoint)
	{
		return CreateAndAttachTexture(GL_RGBA8, GL_RGBA, GL_UNSIGNED_BYTE, attachmentPoint,true);
	};

	FBOTexture CreateAndAttachTexture(GLint internal_format, GLenum format, GLenum type, GLenum attachmentPoint,
		bool genmipmaps=true,
		f32 minFilter = GL_LINEAR_MIPMAP_LINEAR, f32 magFilter = GL_LINEAR_MIPMAP_LINEAR,
		f32 wrapS = GL_CLAMP, f32 wrapT = GL_CLAMP)
	{
		FBOTexture tex;
		glGenTextures(1, &tex.texID);
		
		tex.width = width; tex.height = height;
		tex.internal_format = internal_format;
		tex.format = format;
		tex.type = type;
		tex.attachPoint = attachmentPoint;

		glBindTexture(GL_TEXTURE_2D, tex.texID);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, minFilter);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, magFilter);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
		glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE, GL_INTENSITY);

		glTexImage2D(GL_TEXTURE_2D, 0, tex.internal_format, tex.width, tex.height, 0, tex.format, tex.type, 0);

		if(genmipmaps)
		{
			glGenerateMipmap(GL_TEXTURE_2D);
		}

		Bind();
		glFramebufferTexture2D(GL_FRAMEBUFFER, tex.attachPoint , GL_TEXTURE_2D, tex.texID, 0);
		Unbind();

		glBindTexture(GL_TEXTURE_2D, 0);

		textures.push_back(tex);
		return textures.back();
	};

	void Bind()
	{
		glBindTexture(GL_TEXTURE_2D,0);
		glBindFramebuffer(GL_FRAMEBUFFER, fbo_id);
	};

	void Bind(GLenum target)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindFramebuffer(target, fbo_id);
	}

	void Unbind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
};

typedef std::tr1::shared_ptr<RenderTarget> RenderTargetHandle;