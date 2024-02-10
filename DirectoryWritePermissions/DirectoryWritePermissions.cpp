//#include <filesystem>
//#include <fstream>
//#include <iostream>
//
//void demo_perms(std::filesystem::perms p)
//{
//    using std::filesystem::perms;
//    auto show = [=](char op, perms perm)
//        {
//            std::cout << (perms::none == (perm & p) ? '-' : op);
//        };
//    show('r', perms::owner_read);
//    show('w', perms::owner_write);
//    show('x', perms::owner_exec);
//    show('r', perms::group_read);
//    show('w', perms::group_write);
//    show('x', perms::group_exec);
//    show('r', perms::others_read);
//    show('w', perms::others_write);
//    show('x', perms::others_exec);
//    std::cout << '\n';
//}
//
//int main()
//{
//    std::string testDirectory = "C:\\Program Files\\MyFolder";
//    std::cout << "Directory: " << testDirectory << ":";
//    demo_perms(std::filesystem::status(testDirectory).permissions());
//
//    std::string testDirectory2 = "C:\\Program Files";
//    std::cout << "Directory2: " << testDirectory2 << ":";
//    demo_perms(std::filesystem::status(testDirectory2).permissions());
//}

#include <cassert>
#include <filesystem>
int main()
{
    //auto path = "C:\\Windows\\System32\\drivers\\etc\\hosts2";
    //auto path = "C:\\Windows\\System32\\drivers";
    //auto path = "C:\\Program Files\\2";
    auto path = "C:\\Program Files\\2\\Test.txt";
    auto myStatus = std::filesystem::status(path); 
    auto stdPerms = myStatus.permissions();
    assert(stdPerms != std::filesystem::perms::all);
    return 0;
}