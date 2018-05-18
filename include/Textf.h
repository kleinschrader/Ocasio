#ifndef TEXTF_H
#define TEXTF_H

#include <SFML/graphics.hpp>
#include <vector>

class Textf : public sf::Text
{
    public:
        Textf();
        virtual ~Textf();

        /*
        Textf is comparable to printf().
        it will auto adjust text based on given variables

        %i will insert an integer
        %f will insert a float
        %c will insert a Text (char array)
        */

        //Update the string
        void UpdateString();

        //If Auto Updating is enabled, the String will be modified every time it gets drawn
        //else you will need to call UpdateString()
        //
        //This is useful when using multiple Threads
        void setAutoUpdating(bool);

        //Adds a Variable
        void addVaribale(void* Pointer);

        //Removes a Variable
        void removeVariable(void* Pointer);

        //Overrides the string
        void setString(const sf::String& String);

        //sets the Number of Characters after the "." in float values
        //0XFF for no limit
        void setPercision(unsigned char);
    private:
    	//gets called on window->draw(this)
         virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		//creates a vector for out variables
        std::vector<void*> PoiterToVariabled;

        //Sould we allow updating on draw?
        bool autoUpdating = false;

        //How many extra places do we allow after the dot
        //0xFF (255) is no cutoff
        unsigned char Percision = 0xFF;

        //Here we store our original string
        sf::String OrgString;
};

#endif // TEXTF_H
