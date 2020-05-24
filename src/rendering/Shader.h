#pragma once
#include "RenderDevice.h"
#include "Texture.h"
#include "Sampler.h"

class Shader
{
public:
    Shader(RenderDevice& deviceIn, const String& shaderText):
            mRenderDevice(&deviceIn),
            mProgramId(deviceIn.CreateShaderProgram(shaderText))
            {}
    inline uint32 GetId() { return mProgramId; };
    inline ~Shader()
	{
		//mRenderDevice->ReleaseShaderProgram(deviceId);
	}

	//inline void setUniformBuffer(const String& name, UniformBuffer& buffer)
    //{
    //    
    //}
    inline void SetSampler(const String& name, Texture& texture, Sampler& sampler,
            uint32 unit)
    {
        mRenderDevice->SetShaderSampler(mProgramId, name, texture.GetId(), sampler.GetId(), unit);
    }

private:
    RenderDevice* mRenderDevice;
    uint32 mProgramId;
};

