#ifndef UTILS_H
#define UTILS_H

#include <iostream>

namespace util
{
    
    // python like wrapper for std::cout
    template <typename T>
    void print(T text)
    {
        std::cout << text << std::endl;
    }

};

#endif
