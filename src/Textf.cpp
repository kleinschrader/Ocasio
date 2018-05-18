#include "Textf.h"

Textf::Textf() : sf::Text()
{
    //ctor
}

Textf::~Textf()
{
    //dtor
}

void Textf::UpdateString()
{
	//just numerate the File types
    enum VariableTypes
    {
            v_int,
            v_float,
            v_string
    };

	//Lade den Original string (ohne formating) in den BufferString
    sf::String BufferString = this->OrgString;

    //Hol die StringSize
    int StringSize = BufferString.getSize();

    //Erstelle eine liste von der Position im string des Formates
    std::vector <int>PositionOfVars;
    //Nummerire den Typ
    std::vector <int>Type;

    //Go through every character
    for(int i = 0; i < StringSize; i++)
    {
    	//Find the Percent sign
        if(BufferString[i] == '%')
        {
        	//If an i follows % place an integer
            if(BufferString[i + 1] == 'i')
            {
                PositionOfVars.push_back(i);
                Type.push_back(VariableTypes::v_int);
            }
            //Place an float if a f follows
            else if(BufferString[i + 1] == 'f')
            {
                PositionOfVars.push_back(i);
                Type.push_back(VariableTypes::v_float);
            }
            //place a string character if a c follows
            else if(BufferString[i + 1] == 'c')
            {
                PositionOfVars.push_back(i);
                Type.push_back(VariableTypes::v_string);
            }
        }
    }
	//Note the extra character we write, so we can scale it automatically
    int ExtraChars = 0;

    //loop through every placeholder to replace
    for(unsigned int i = 0; i < PositionOfVars.size();i++)
    {
    	//delete the placeholder
        BufferString.erase(PositionOfVars[i] + ExtraChars,2);

        //create a switch for each type
        switch(Type[i])
        {
        	//if its an integer
            case VariableTypes::v_int:
            {
            	//convert the integer to a string
                std::string int_Buffer = std::to_string(*(int*)this->PoiterToVariabled[i]);

                //insert the string where the placeholder was
                BufferString.insert(PositionOfVars[i] + ExtraChars,int_Buffer);

                //add the size of the string to extrachars
                ExtraChars += int_Buffer.size() - 2;

                //end the switch
                break;
            }
            //if its a float
            case VariableTypes::v_float:
            {
            	//Float -> String
                std::string float_Buffer = std::to_string(*(float*)this->PoiterToVariabled[i]);

                //Only cut off the end of the string if we didnt disable Percision
                if(Percision != 0xFF)
                {
                	//Loop the each character in the new string
                    for(unsigned int ii = 0; ii < float_Buffer.size();ii++)
                    {
                    	//do that until the dot
                        if(float_Buffer[ii] == '.')
                        {
                        	//dont cut off if the reminder is already smaller the out precision
                            if((float_Buffer.size() - ii) > this->Percision)
							{
                            	//Just erase everything from the dot + percisoin to the end of string
                                float_Buffer.erase(ii + this->Percision,float_Buffer.size() - ii);
							}
						}
					}
				}


                //insert the String
                BufferString.insert(PositionOfVars[i] + ExtraChars,float_Buffer);

                 //add the size of the string to extrachars
                ExtraChars += float_Buffer.size() - 2;
                break;
            }
            case VariableTypes::v_string:
            {
            	//get a pointer to the substring
                char* chars = (char*)this->PoiterToVariabled[i];

                //define a vriable for the size of substring
                int LengthOfString = 0;

                //count the size of the Sub string
                for(; chars[LengthOfString] != 0; LengthOfString++);

                //Insert the string
                BufferString.insert(PositionOfVars[i] + ExtraChars,chars);

                //Adjust the string size
                ExtraChars += LengthOfString - 2;

                //exit switch
                break;
            }
        }
    }

    //Set the string of the Text
    sf::Text::setString(BufferString);
}

//Set if the text sould be updated every time we draw or just manual
void Textf::setAutoUpdating(bool in)
{
    this->autoUpdating = in;
}

//add pointer to a variable
void Textf::addVaribale(void* Pointer)
{
    this->PoiterToVariabled.push_back(Pointer);
}

//remove a varibale
void Textf::removeVariable(void* Pointer)
{
	//loop through each element in out vector
    for(unsigned int i = 0; i < this->PoiterToVariabled.size();i++)
    {
    	//if the Pointer is the same at i remove it
        if(this->PoiterToVariabled[i] == Pointer)
        {
        	//remove the pointer
            this->PoiterToVariabled.erase(this->PoiterToVariabled.begin() + 1);
        }
    }
}

//gets called if window->draw(this)
void Textf::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//create a pointer to itself
	//this is necessary due to the const flag of the variable
    void* t_this = (void*)this;

    //if autoUpdate is on
    //update the string
    if(this->autoUpdating)
        ((Textf*)t_this)->UpdateString();

	//convert this to a normal text element so i call their draw function
    sf::Text Buffer(*(Textf*)t_this);
    target.draw(Buffer);
}

//sets the string of out text (with format placeholders)
void Textf::setString(const sf::String& String)
{
	//we call the original function
	//because m_string is private :/
    sf::Text::setString(String);

    //set the Original string
    this->OrgString = String;
}

//sets the percision for our Float values
void Textf::setPercision(unsigned char MaxLengh)
{
    this->Percision = MaxLengh;
}
