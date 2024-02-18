#include <iostream>>
struct Test{

  Test( int j) : i{j}
  {
    std::cout << "Ctr i=" << i << "\n";
  }  
  ~Test()
  {
    std::cout << "Dtr i=" << i << "\n"; 
  }

  int i;
};

std::ostream& operator<<(std::ostream& os, Test test)
{
    return os << test.i;
}

template< typename T >
class unique_ptr
{
    public:
    using pointer = T*;

    explicit unique_ptr(pointer ptr):ptr_{ptr}{}
    ~unique_ptr() { delete ptr_; }
    private:
    pointer ptr_;
};

template< typename T >
class unique_ptr<T[]> // Partial template specialization
{
    public:
    using pointer = T*;

    explicit unique_ptr(pointer ptr):ptr_{ptr}{}
    ~unique_ptr() { delete[] ptr_; }
    private:
    pointer ptr_;
};

int main()
{
    unique_ptr<Test> ptr{ new Test{42}};

    unique_ptr<Test[]> ptr2{ new Test[3]{1,2,3}};
}