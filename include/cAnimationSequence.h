#ifndef CANIMATIONSEQUENCE_H
#define CANIMATIONSEQUENCE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "cTextureLoader.h"

class cAnimationSequence
{
	public:
		cAnimationSequence(const char* AnimationName, const char* Path, sf::Shape* TargetShape, cTextureLoader* TextureLoader);
		virtual ~cAnimationSequence();

		void Update();

		void Start(bool* onFinished);
		void Stop();

		const char* getName();


	private:
		std::vector<sf::IntRect> Frames;

		sf::Clock AnimationCounter;

		const char* AnimationName;

		int AnimationNameLength;

		cTextureLoader *TextureLoader;

		const sf::Texture *Texture;

		sf::Shape *TargetShape;

		int LengthOfEachFrame;

		unsigned int CurrentFrame = 0;

		bool loopable;

		bool isRunning = false;

		bool *isFinished;
};

#endif // CANIMATIONSEQUENCE_H
