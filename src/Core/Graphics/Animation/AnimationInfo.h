#pragma once


class AnimationState
{
public:
	AnimationState() {};

	struct StateDetails
	{
		StateDetails() :
			currentTime(0.0f),
			totalTime(0.0f),
			bHasExitTime(false),
			frameStepTime(0.0f) {};
		std::string name;
		float currentTime;		// Time (frame) in current animation
		float totalTime;		// Total time animation goes
		float frameStepTime;	// Number of seconds to 'move' the animation	
		// Returns true if time had to be reset
		// (for checking to see if the animation has finished or not)
		// TODO: Deal with running the animation backwards, perhaps?? 
		bool bExited;
		bool bHasExitTime;

		inline bool IncrementTime(bool bResetToZero = true)
		{
			bool bDidWeReset = false;
			bExited = false;

			this->currentTime += this->frameStepTime;
			if (this->currentTime >= this->totalTime)
			{
				this->currentTime = 0.0f;
				bDidWeReset = true;
				bExited = true;
			}

			return bDidWeReset;
		}
	};


	// Extent Values for skinned mesh
	// These can be updated per frame, from the "update skinned mesh" call
	glm::vec3 minXYZ_from_SM_Bones;
	glm::vec3 maxXYZ_from_SM_Bones;
	// Store all the bones for this model, being updated per frame
	std::vector< glm::mat4x4 > vecObjectBoneTransformation;

	std::vector<StateDetails> vecAnimationQueue;
	StateDetails activeAnimation;
	StateDetails PrevAnimation;
	StateDetails defaultAnimation;
};

struct AnimationInfo
{
	std::string name;
	std::string fileName;
	float duration;
	bool bHasExitTime;
	const aiScene* pAIScene;
};