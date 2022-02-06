#include <iostream>
#include <string>
using namespace std;
#include<ctype.h>

class TextInput
{
protected:
    string value;
public:
    virtual void add(char c) {
        value += c;
    }

    std::string getValue() { return value; }
};

class NumericInput : public TextInput {

public:
    void add(char c) {
        if (isdigit(static_cast<unsigned char>(c))) {
            value += c;
        }
    }
};

int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
    return 0;
}