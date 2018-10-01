#include "mylibrary.h"
#include <iostream>
namespace mylibrary
{
    myclass::myclass()
    {

    }
    myclass::~myclass()
    {

    }
    void myclass::printsomething()
    {
        std::cout << "Hello World!" << std::endl;
    }
}