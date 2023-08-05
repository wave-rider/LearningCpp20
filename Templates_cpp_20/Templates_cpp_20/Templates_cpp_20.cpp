

//  main.cpp

//  Templates
//
//  Created by Admin on 28/07/23.
//

#include <iostream>

class MyFile
{
public:
    void Read() { }
};

class ArrayWrapper;

class BaseClass
{
public:
    ArrayWrapper* arrayWrapper;
};



template <class T> class ArrayClass : public BaseClass
{
public:
    void Add();
};


class ArrayWrapper
{
public:
    ArrayWrapper() : file(new MyFile()) {
        std::cout << "ArrayWrapper" << std::endl;
    }

    ~ArrayWrapper() { delete file; }

    MyFile* file;
    ArrayClass<int> Array{};

    void Update()
    {
        Array.arrayWrapper = this;
        Array.Add();
    }
};


template <class T>
void ArrayClass<T>::Add()
{
    arrayWrapper->file->Read();
}

int main()
{
    ArrayWrapper wrapper;
    wrapper.Update();
    return 0;
}