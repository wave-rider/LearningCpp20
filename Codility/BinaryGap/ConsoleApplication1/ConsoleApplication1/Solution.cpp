#include "Solution.h"
int solution(int N)
{
    string s = bitset<32>(N).to_string(); // 01100100.
    std::string::size_type maxSize = 0;
    std::string::size_type prevIndex = -1;
    for (std::string::size_type i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            if (maxSize < i - prevIndex - 1 && prevIndex != -1)
            {
                maxSize = i - prevIndex - 1;
            }
            prevIndex = i;
        }
    }
    
    return maxSize;
}