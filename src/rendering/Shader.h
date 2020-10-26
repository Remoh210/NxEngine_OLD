#pragma once
#include "RenderDevice.h"
#include "Texture.h"
#include "UniformBuffer.h"
#include "Sampler.h"

class Shader
{
public:
    Shader(RenderDevice& deviceIn, const NString& shaderText):
            mRenderDevice(&deviceIn),
            mProgramId(deviceIn.CreateShaderProgram(shaderText))
            {}
    inline uint32 GetId() { return mProgramId; };
    inline ~Shader()
	{
		//mRenderDevice->ReleaseShaderProgram(deviceId);
	}

	inline void SetUniformBuffer(const NString& name, UniformBuffer& buffer)
	{
		mRenderDevice->SetShaderUniformBuffer(mProgramId, name, buffer.GetId());
	}

    inline void SetSampler(const NString& name, Texture& texture, Sampler& sampler,
            uint32 unit)
    {
        mRenderDevice->SetShaderSampler(mProgramId, name, texture.GetId(), sampler.GetId(), unit);
    }

private:
    RenderDevice* mRenderDevice;
    uint32 mProgramId;
};

