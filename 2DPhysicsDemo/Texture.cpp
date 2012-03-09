#include "Texture.h"
using namespace gxbase;

void Texture::SetParameteri(GLenum param, u32 v)
{
	Activate();
	glTexParameteri(GL_TEXTURE_2D, param, v);
	Deactivate();
};

void Texture::SetParameterf(GLenum param, f32 v)
{
	Activate();
	glTexParameterf(GL_TEXTURE_2D, param, v);
	Deactivate();
};

bool Texture::Load(const char *filename)
{
	Unload();

	bool returnVal = false;

	Image tex;
	bool loaded = tex.Load(filename);
	if(loaded)
	{
		glGenTextures(1, &textureID);
		if(textureID)
		{
			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, minFilter);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, magFilter);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);

			width = tex.Width();
			height = tex.Height();

			Activate();
			tex.gluBuild2DMipmaps();
			Deactivate();

			returnVal = true;
		}

		tex.Free();
	}
	return returnVal;
};

void Texture::Unload()
{
	if(textureID)
	{
		glDeleteTextures(1, &textureID);
	}
	textureID = 0;
};

void Texture::Activate()
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, magFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);

	glBindTexture(GL_TEXTURE_2D, GetGLTextureID());
};

void Texture::Deactivate() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
};