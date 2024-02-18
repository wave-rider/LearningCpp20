#include <cstdlib>
#include <variant>
#include <string>
//#include 

template < int > // short, int NNTP since C++98
struct IntWidget
{};

template < double > // Floating point NNTP since C++20
struct IntWidget
{};

template < auto > // Structural type NNTP since C++20
struct AutoWidget
{};

int main()
{
	std::variant<int, double, std::string> v{};
	return EXIT_SUCCESS;
}
