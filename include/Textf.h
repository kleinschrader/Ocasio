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
    private:
         virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        std::vector<void*> PoiterToVariabled;
        bool autoUpdating = false;


        sf::String OrgString;
};

#endif // TEXTF_H
