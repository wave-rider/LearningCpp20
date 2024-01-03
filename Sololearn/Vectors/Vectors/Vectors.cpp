// This code is a an update for the vector's little helper code from 2018
// It uses the copy and move constructors 
// and reserves the memory  for 100 items

#include <iostream>
#include <vector>
using namespace std;

class A {
public:
    static int cnt;

    A(int a) {
        this->a = a;
        cout << "a=" << a << " The constructor is called and cnt=" << A::cnt << endl;
        this->_cnt = A::cnt++;
    }
    ~A()
    {
        cout << "The destructor is called and cnt=" << A::cnt << " _cnt=" << this->_cnt << " a=" << this->a << endl;        
    }
    int a;
    int _cnt;

    A(A&& rcOther)
        : a(rcOther.a)
        , _cnt(A::cnt)
    {
        cout << "a=" << a << " The move constructor is called and cnt=" << A::cnt << endl;
    }

    A(const A& rcOther)
        : a(rcOther.a)
        , _cnt(A::cnt)
    {
        cout << "a=" << a << " The copy constructor is called and cnt=" << A::cnt << endl;
    }

};
int A::cnt = 0;

int main(int argc, const char* argv[]) {
    cout << "Init vector..." << endl;
    vector<A> vector;
    vector.reserve(100);
    A t(10);
    vector.push_back(std::move(t));
    A t1(11);
    vector.push_back(std::move(t1));
    A t2(12);
    vector.push_back(std::move(t2));
    A t3(13);
    vector.push_back(std::move(t3));

    cout << "Before push_back vector.size()=" << vector.size() << endl;
    vector.push_back(1); // This is allowed because we didn't mark our constructor as 'explicit'
    std::cout << "After push_back the vector.size()=" << vector.size() << " cnt=" << A::cnt << endl; // A::cnt is 6 at this point
    return 0;
}