/*A playlist is considered a repeating playlist if any of the songs contain a pointer to a previous song in the playlist.Otherwise, the playlist will end with the last song which points to NULL.

Implement a function isRepeatingPlaylist that, efficiently with respect to time used, returns true if a playlist is repeating or false if it is not.

For example, the following code prints "true" as both songs point to each other.*/
#include <stdexcept>
#include <iostream>
#include <unordered_set>

class Song
{
public:
    Song(std::string name) : name(name), nextSong(NULL) {}

    void next(Song* song)
    {
        this->nextSong = song;
    }

    bool isRepeatingPlaylist()
    {
        auto currentSong = this;
        std::unordered_set<std::string> s;
        while (currentSong != nullptr) {
            if (s.find(currentSong->name) != s.end())
                return true;
            s.insert(currentSong->name);
            currentSong = currentSong->nextSong;
        }
        return false;
    }

private:
    const std::string name;
    Song* nextSong;
};

#ifndef RunTests
int main()
{
    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");

    first->next(second);
    second->next(first);

    std::cout << std::boolalpha << first->isRepeatingPlaylist();
    return 0;
}
#endif
