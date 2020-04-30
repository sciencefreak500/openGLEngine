#ifndef UTILS_H
#define UTILS_H

#include <iostream>

namespace util
{
    template <typename Arg, typename... Args>
    void print(Arg&& arg, Args&&... args)
    {
        std::cout << std::forward<Arg>(arg);
        using expander = int[];
        (void)expander{0, (void(std::cout << ' ' << std::forward<Args>(args)), 0)...};
        std::cout << std::endl;
    }
};

#endif
