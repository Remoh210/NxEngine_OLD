#pragma once

#include "Editor/EditorRenderContext.h"
#include "rendering/RenderDevice.h"
#include "Common/dataStructs/Array.h"
#include "Common/Transform/Transform.h"
#include "DebugShape.h"

class DebugRenderer
{
public:

    DebugRenderer(EditorRenderContext& contextIn);
    
	void DebugRenderer::DrawDebugSphere(vec3 position, float time = 0, float radius = 1, vec3 color = vec3(1.f, 0.f, 0.f),
		uint32 sectorCount = 36, uint32 stackCount = 18);

    void DrawDebugLine(vec3 start, vec3 end, float time, vec3 color);

    void Update(float dt);


private:
    EditorRenderContext& editorContext;
    Array<DebugShape*> ShapesToDraw;
    Shader* shader;
    DrawParams debugDrawParams;
};