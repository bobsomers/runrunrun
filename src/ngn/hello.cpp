#include "ngn/hello.h"

#include <iostream>
#include <string>

namespace ngn {

void printHello(const std::string& name)
{
    std::cout << "Hello, " << name << "!" << std::endl;
}

} // namespace ngn
