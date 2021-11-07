#include "TextureImporter.h"
#include "Globals.h"
#include "Application.h"
#include "Assimp.h"
#include <cmath>

#include "Dependencies/glew/include/GL/glew.h"

#include "Dependencies/Devil/include/il.h"
#include "Dependencies/Devil/include/ilu.h"
#include "Dependencies/Devil/include/ilut.h"
#pragma comment( lib, "Devil/libx86/DevIL.lib" )
#pragma comment( lib, "Devil/libx86/ILU.lib" )
#pragma comment( lib, "Devil/libx86/ILUT.lib" )

//Devil

TextureImporter::TextureImporter()
{

}

TextureImporter::~TextureImporter()
{

}

TextureInfo::~TextureInfo()
{
	ilDeleteImages(1, &this->tex_ID);
}

bool TextureImporter::Init()
{
	bool ret = true;

	if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION || iluGetInteger(ILU_VERSION_NUM) < ILU_VERSION || iluGetInteger(ILUT_VERSION_NUM) < ILUT_VERSION)
	{
		LOG("ERROR: DevIL version not correct");
		ret = false;
	}

	else
	{
		LOG("Initializing DevIL");

		ilInit();
		iluInit();
		ilutInit();

		ilutRenderer(ILUT_OPENGL);
	}

	return ret;
}

//TextureInfo* TextureImporter::LoadSceneTextures(const std::string& filename, const std::string& texturename)
//{
//	TextureInfo* ret = nullptr;
//	//import the scene from a file
//	const char* file_path = filename.c_str();
//	const char* texture_path = texturename.c_str();
//
//	//Assimp::MeshImporter MeshImporter; //what is this? Could it be a better implementation?
//	//const aiScene* scene = MeshImporter.ReadFile(file_path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_JoinIdenticalVertices);
//
//	LOG("Loading Model from file: %s", file_path);
//
//	const aiScene* scene = aiImportFile(file_path, aiProcessPreset_TargetRealtime_MaxQuality | aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
//
//	//Make sure the scene was loaded correctly and has materials to load
//	if (scene != nullptr && scene->HasMaterials())
//	{
//		// Use scene->mNumMeshes to iterate on scene->mMaterials array
//		for (uint i = 0; i < scene->mNumMaterials; ++i)
//		{
//			ret = ImportTexture(texture_path);
//		}
//	}
//	else
//		LOG("No materials at scene: %s", file_path);
//	aiReleaseImport(scene);
//
//	return ret;
//}

TextureInfo* TextureImporter::ImportTexture(const char* path)
{
	TextureInfo* newTexture = new TextureInfo;
	uint i;

	ilGenImages(1, &i);
	ilBindImage(i);

	if (ilLoadImage(path))
	{
		ILinfo ImgInfo;
		iluGetImageInfo(&ImgInfo);

		if (ImgInfo.Origin == IL_ORIGIN_UPPER_LEFT)
			iluFlipImage();

		if (ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE))
		{
			newTexture->tex_ID = CreateTexture(ilGetData(), ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT), ilGetInteger(IL_IMAGE_FORMAT));
			newTexture->tex_height = ilGetInteger(IL_IMAGE_HEIGHT);
			newTexture->tex_width = ilGetInteger(IL_IMAGE_WIDTH);
			newTexture->tex_path = path;

			LOG("Successfully loaded Texture from: %s", path);
		}
		else
		{
			LOG("(ERROR)Could not convert image %s", path);
		}
	}
	else
	{
		LOG("(ERROR) Error loading Image %s", path);
	}

	return newTexture;
}

uint TextureImporter::CreateTexture(const void* data, uint width, uint height, uint format)
{
	uint id;

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height,
		0, format, GL_UNSIGNED_BYTE, data);

	glBindTexture(GL_TEXTURE_2D, 0);

	return id;
}

uint* TextureImporter::CheckerImage()
{
	return 0;
}

