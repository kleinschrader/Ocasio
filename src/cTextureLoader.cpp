#include "cTextureLoader.h"

cTextureLoader::cTextureLoader()
{
	//ctor
}

cTextureLoader::~cTextureLoader()
{
    //dtor
}

void cTextureLoader::loadTexture(const char* nameOfTextue, const char *path)
{
	//Create A Buffer for texture
    cIDTexture *Buffer = new cIDTexture;

    //Load the texture from the Path
    Buffer->loadFromFile(path);

    //Set the name of out texture
    Buffer->setTextureID(nameOfTextue);

    //Push the Buffer to the End of the Vector
    this->textures.push_back(Buffer);
}

const sf::Texture* cTextureLoader::getTexture(const char* nameOfTextue)
{
	// grab our vector Size
	int vectorSize = this->textures.size();

	//Loop through every element
	for(int i = 0; i < vectorSize; i++)
	{
		//Grab the Texture name (ID) from texture[i]
		const char* textureID = this->textures[i]->getTextureID();
		//A bool to check if the id is the same
		bool isEqual = true;
		//Loop through every character and compare them
		//Loop until either of the ID's are end
		for(int ii = 0; nameOfTextue[ii] != 0 && textureID[ii] != 0; ii++)
		{
			//if one element isnt the same
			if(nameOfTextue[ii] != textureID[ii])
			{
				//it wasnt equal, set isEqual to false
				isEqual = false;
				//end this loop
				break;
			}
		}
		//if they are the same return the texture
		if(isEqual)
		{
			return this->textures[i];
		}
	}
	//we didnt find it, return 0
	return nullptr;
}
