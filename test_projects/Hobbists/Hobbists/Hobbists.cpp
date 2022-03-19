#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>
#include <string>

typedef std::map<std::string, std::vector<std::string>> HobbiesMap;

std::vector<std::string> findAllHobbyists(const std::string& hobby, const HobbiesMap& hobbies)
{
    std::vector<std::string> result;

    for (auto it = hobbies.begin(); it != hobbies.end(); ++it)
    {
        auto name = it->first;
        auto hobbies = it->second;
        if (find(hobbies.begin(), hobbies.end(), hobby) != hobbies.end())
        {
            result.push_back(name);
        }
    }

    return result;
}

#ifndef RunTests
int main()
{
    HobbiesMap hobbies
    {
       {"Steve", {"Fashion", "Piano", "Reading"}},
       {"Patty", {"Drama", "Magic", "Pets"}},
       {"Chad", {"Puzzles", "Pets", "Yoga"}}
    };

    std::vector<std::string> hobbyists = findAllHobbyists("Yoga", hobbies);
    for (std::string hobbyist : hobbyists)
    {
        std::cout << hobbyist << std::endl;
    }
}
#endif