#include <string>
#include <iostream>
using namespace std;

template<typename T>
void Innocent(T&& value)
{
    std::string local = std::move(value);
}

void Use()
{
    std::string s{"A very large string "
    "When you save or open a C++ file, "
    "you may see a notification from the C/C++ extension "
    "about the availability of an Insiders version, which lets "
    "you test new features and fixes. You can ignore this notification"
    " by selecting the X (Clear Notification)."
    };
    Innocent(s);
    cout << "'" << s << "'";
}

int main()
{
    Use();
}