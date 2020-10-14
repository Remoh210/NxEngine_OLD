#define STB_IMAGE_IMPLEMENTATION
#include "ArrayBitmap.h"
#include "stb_image.h"

#define LOG_TYPE_ArrayBitmap "ArrayBitmap"

ArrayBitmap::ArrayBitmap(/*const string& fileName*/) 
{
	//height = 10;
    //Load(fileName);
}

bool ArrayBitmap::Load(const string& fileName) 
{
	bool bResult = false;
	int nrComponents;
	data = stbi_load(fileName.c_str(), &width, &height, &nrComponents, 0);
	
	if (data)
	{

		if (nrComponents == 1)
		format = PixelFormat::FORMAT_R;
		else if (nrComponents == 3)
		format = PixelFormat::FORMAT_RGB;
		else if (nrComponents == 4)
		format = PixelFormat::FORMAT_RGBA;

		bResult = true;
	}
	else
	{
		DEBUG_LOG(LOG_TYPE_ArrayBitmap, LOG_ERROR, "Failed to load ArrayBitmap: %s", fileName.c_str());
		stbi_image_free(data);
	}

	return bResult;
}

void ArrayBitmap::Clean()
{
	stbi_image_free(data);
}

ArrayBitmap::~ArrayBitmap() 
{
	//DEBUG_LOG_TEMP("ArrayBitmap destructor has been called");
	//Clean();
}
