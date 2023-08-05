// std_any.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <any>
#include <cstdlib>
#include <string>
using namespace std::string_literals;

int main()
{
   std::any a;          // Creating an empty 'any'
   a = 1;               // Storing an 'int' inside the 'any';
   a = "some string"s;  // Replacing the 'int' with a 'std::string'

   // There is nothing we can do with the 'any' except for getting the value back
   
   // a = "15"; this is a const char* and it will throw an exception 
   std::string s = std::any_cast<std::string>( a );
   

   return EXIT_SUCCESS;
}
