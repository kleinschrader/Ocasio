#ifndef CANIMATIONMANAGER_H
#define CANIMATIONMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "cAnimationSequence.h"

class cAnimationManager
{
	public:
		cAnimationManager(sf::Shape *TargetShape, cTextureLoader *TextureLoader,const char* defaultAnimation);
		virtual ~cAnimationManager();

		void loadAnimation(const char* animationName, const char* path, bool loopable);
		void playAnimation(const char* animationName);

		void Update();

		void setDefaultAnimation(const char* animationName);

		const char* getCurrentAnimation();
	private:
		std::vector <cAnimationSequence*> Sequences;

		const char* currentAnimation = "NO_ANIMATION";
		const char* defaultAnimation = "NO_ANIMATION";

		sf::Shape *TargetShape;
		cTextureLoader *TextureLoader;

		bool isFinished = false;
};

#endif // CANIMATIONMANAGER_H
