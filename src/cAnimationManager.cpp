#include "cAnimationManager.h"

cAnimationManager::cAnimationManager(sf::Shape *TargetShape, cTextureLoader *TextureLoader,const char* defaultAnimation)
{
	this->TargetShape = TargetShape;
	this->TextureLoader = TextureLoader;
	this->defaultAnimation = defaultAnimation;
}

cAnimationManager::~cAnimationManager()
{
	//dtor
}

void cAnimationManager::loadAnimation(const char* animationName, const char* path, bool loopable)
{
	cAnimationSequence *Buffer = new cAnimationSequence(animationName,path,this->TargetShape,this->TextureLoader);
	this->Sequences.push_back(Buffer);
}

void cAnimationManager::playAnimation(const char* animationName)
{
	this->currentAnimation = animationName;
	for(unsigned int i = 0; i < this->Sequences.size(); i++)
	{
		this->Sequences[i]->Stop();

		const char* tmpName = this->Sequences[i]->getName();

		int tmpNameSize = 0;
		int curNameSize = 0;
		for(; tmpName[tmpNameSize] != 0; tmpNameSize++);
		for(; animationName[curNameSize] != 0; curNameSize++);

		if(tmpNameSize != curNameSize)
			continue;

		for(int ii = 0; ii < tmpNameSize; ii++)
		{
			if(tmpName[ii] != animationName[ii])
				continue;
		}

		this->Sequences[i]->Start(&this->isFinished);
	}
}

void cAnimationManager::Update()
{
	if(this->isFinished)
		this->playAnimation(this->defaultAnimation);

	this->isFinished = false;

	int animations = this->Sequences.size();
	for(int i = 0; i < animations;i++)
	{
		this->Sequences[i]->Update();
	}
}

void cAnimationManager::setDefaultAnimation(const char* animationName)
{
	this->defaultAnimation = animationName;
}

const char* cAnimationManager::getCurrentAnimation()
{
	return this->currentAnimation;
}
