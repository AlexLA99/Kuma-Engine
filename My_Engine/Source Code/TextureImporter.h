#pragma once

#include "Globals.h"
#include <string>
#include <vector>
#include "Dependencies/Devil/include/ilu.h"


class aiScene;

class TextureInfo
{
public:
	~TextureInfo();

public:
	uint tex_ID;
	const char* tex_path;
	uint tex_width;
	uint tex_height;
	uint tex_bit_depth;
	uint tex_format;
	const void* tex_data = 0;
};

class TextureImporter
{
public:
	TextureImporter();
	~TextureImporter();

	bool Init();
	uint* CheckerImage();
	//TextureInfo* LoadSceneTextures(const std::string& filename, const std::string& texturename);
	TextureInfo* ImportTexture(const char* path);
	uint CreateTexture(const void* data, uint width, uint height, uint format);
};
