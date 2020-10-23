#pragma once
#include "Common/Transform/Transform.h"
#include "Common/Common.h"

#include "rendering/VertexArray.h"
#include "rendering/Texture.h"


struct DebugShape
{
	float lifetime = 0;
	float timeSinceCreated = 0.0f;
	VertexArray* vertexArray;
	Texture* texture;
	Transform transform;
	DrawParams drawParams;

	DebugShape()
	{
		texture = nullptr;
		//drawParams.faceCulling = FACE_CULL_NONE;
		//drawParams.primitiveType = PRIMITIVE_LINES;
	}

	~DebugShape()
	{
		delete vertexArray;
		DEBUG_LOG_TEMP("Debug Shape Destructor Was Called");
	}
};