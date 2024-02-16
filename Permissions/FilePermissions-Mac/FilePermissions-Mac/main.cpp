#include <cassert>
#include <filesystem>
int main()
{
    // https://stackoverflow.com/questions/19413181/step-into-stl-sources-in-xcode-5
    // https://stackoverflow.com/questions/7689735/lldb-does-not-appear-to-be-reading-my-lldbinit-file-on-startup
    // https://www.jviotti.com/2022/05/05/debugging-the-cxx-standard-library-on-macos.html
    auto path = "/System/Library/Accessibility/AccessibilityDefinitions.plist";
    auto myStatus = std::filesystem::status(path);
    auto stdPerms = myStatus.permissions();
    assert(stdPerms != std::filesystem::perms::all);
    return 0;
}
