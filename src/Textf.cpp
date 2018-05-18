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
    enum VariableTypes
    {
            v_int,
            v_float,
            v_string,
            MAX_VAR_TYPE
    };

    sf::String BufferString = this->OrgString;

    int StringSize = BufferString.getSize();

    std::vector <int>PositionOfVars;
    std::vector <int>Type;

    for(int i = 0; i < StringSize; i++)
    {
        if(BufferString[i] == '%')
        {
            if(BufferString[i + 1] == 'i')
            {
                PositionOfVars.push_back(i);
                Type.push_back(VariableTypes::v_int);
            }
            else if(BufferString[i + 1] == 'f')
            {
                PositionOfVars.push_back(i);
                Type.push_back(VariableTypes::v_float);
            }
            else if(BufferString[i + 1] == 'c')
            {
                PositionOfVars.push_back(i);
                Type.push_back(VariableTypes::v_string);
            }
        }
    }

    int ExtraChars = 0;

    for(unsigned int i = 0; i < PositionOfVars.size();i++)
    {
        BufferString.erase(PositionOfVars[i] + ExtraChars,2);
        switch(Type[i])
        {
            case VariableTypes::v_int:
            {
                std::string int_Buffer = std::to_string(*(int*)this->PoiterToVariabled[i]);
                BufferString.insert(PositionOfVars[i] + ExtraChars,int_Buffer);
                ExtraChars += int_Buffer.size() - 2;
                break;
            }
            case VariableTypes::v_float:
            {
                std::string float_Buffer = std::to_string(*(float*)this->PoiterToVariabled[i]);
                BufferString.insert(PositionOfVars[i] + ExtraChars,float_Buffer);
                ExtraChars += float_Buffer.size() - 2;
            }
            case VariableTypes::v_string:
            {
                char* chars = (char*)this->PoiterToVariabled[i];
                int LengthOfString;

                for(; chars[LengthOfString] != 0; LengthOfString++);

                BufferString.insert(PositionOfVars[i] + ExtraChars,chars);
                ExtraChars += LengthOfString;
            }
        }
    }

    sf::Text::setString(BufferString);
}

void Textf::setAutoUpdating(bool in)
{
    this->autoUpdating = in;
}


void Textf::addVaribale(void* Pointer)
{
    this->PoiterToVariabled.push_back(Pointer);
}

void Textf::removeVariable(void* Pointer)
{
    for(unsigned int i = 0; i < this->PoiterToVariabled.size();i++)
    {
        if(this->PoiterToVariabled[i] == Pointer)
        {
            this->PoiterToVariabled.erase(this->PoiterToVariabled.begin() + 1);
        }
    }
}
void Textf::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    void* t_this = (void*)this;

    if(this->autoUpdating)
        ((Textf*)t_this)->UpdateString();

    sf::Text Buffer(*(Textf*)t_this);
    target.draw(Buffer);
}

void Textf::setString(const sf::String& String)
{
    sf::Text::setString(String);

    this->OrgString = String;
}
