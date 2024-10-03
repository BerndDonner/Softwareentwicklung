#include <iostream>
#include <chrono>

//dafür wird c++20 standard benötigt

int main()
{
    auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());

    std::cout << "Zeit: " << std::format("{:%Y-%m-%d %X}", time) << std::endl;
    return 0;
}
