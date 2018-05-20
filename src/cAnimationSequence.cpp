#include "cAnimationSequence.h"
#include <iostream>

cAnimationSequence::cAnimationSequence(const char* AnimationName, const char* Path, sf::Shape* TargetShape, cTextureLoader* TextureLoader)
{
	this->TextureLoader = TextureLoader;
	this->AnimationName = AnimationName;
	this->TargetShape = TargetShape;

	this->AnimationNameLength = 0;
	for(;this->AnimationName[AnimationNameLength]; AnimationNameLength++);

	sf::FileInputStream InputStream;
	InputStream.open(Path);

	unsigned char LenghOfTextureName = 0;
	InputStream.read(&LenghOfTextureName,1);

	char *TextureName = new char[LenghOfTextureName + 1];
	InputStream.read(TextureName,LenghOfTextureName);
	TextureName[LenghOfTextureName] = 0;

	this->Texture = this->TextureLoader->getTexture(TextureName);

	delete TextureName;

	InputStream.read(&this->loopable,1);

	InputStream.read(&this->LengthOfEachFrame,4);

	int NumberOfFrames;
	InputStream.read(&NumberOfFrames,4);

	sf::IntRect Buffer;

	for(int i = 0; i < NumberOfFrames; i++)
	{
		InputStream.read(&Buffer.left,4);
		InputStream.read(&Buffer.top,4);
		InputStream.read(&Buffer.width,4);
		InputStream.read(&Buffer.height,4);
		this->Frames.push_back(Buffer);
	};

	this->TargetShape->setTexture(this->Texture);
	this->TargetShape->setTextureRect(this->Frames[0]);
}

cAnimationSequence::~cAnimationSequence()
{
	//dtor
}

const char* cAnimationSequence::getName()
{
	return this->AnimationName;
}

void cAnimationSequence::Update()
{
	if(isRunning)
	{
		if(CurrentFrame == (this->Frames.size()-1))
		{
			if(!this->loopable)
			{
				this->isRunning = false;
				*this->isFinished = true;
				return;
			}
			CurrentFrame = 0;
		}
		if(this->AnimationCounter.getElapsedTime().asMilliseconds() > this->LengthOfEachFrame)
		{
			CurrentFrame++;

			this->TargetShape->setTextureRect(this->Frames[CurrentFrame]);

			this->AnimationCounter.restart();
		}
	}
}

void cAnimationSequence::Start(bool* onFinished)
{
	this->TargetShape->setTexture(Texture);
	this->TargetShape->setTextureRect(this->Frames[0]);
	this->CurrentFrame = 0;
	this->isRunning = true;
	this->AnimationCounter.restart();
	this->isFinished = onFinished;
}

void cAnimationSequence::Stop()
{
	this->isRunning = false;
}
