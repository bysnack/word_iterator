#include <iostream>
#include "word_iterator.hpp"


int main() {
    constexpr std::string_view sw{ "this is a string" };
    word_iterator wi{sw};
    --wi;
    std::cout << *wi << '\n';
    ++wi;
    std::cout << *wi << '\n';
    std::cout << wi.first() << "-" << wi.last() << "\n";
    return 0;
}