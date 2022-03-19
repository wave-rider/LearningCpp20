#include <limits>
#include <iostream>
#include <math.h>

using namespace std;

bool isLimit(double value)
{
   /* cout << "Min:" << std::numeric_limits<double>::min() << endl;
    cout << "Max:" << std::numeric_limits<double>::max() << endl;

    cout << fabs(std::numeric_limits<double>::min() - value) << endl;
    cout << fabs(std::numeric_limits<double>::max() - value) << endl;*/
    return value == std::numeric_limits<double>::min() || value == std::numeric_limits<double>::max();
}

#ifndef RunTests
int main()
{
    std::cout << isLimit(0.0);
    std::cout << isLimit(std::numeric_limits<double>::min());
    std::cout << isLimit(std::numeric_limits<double>::max());
}
#endif