#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>

int main()
{
    std::string msg;
    std::cin >> msg;

    // to upper case
    std::transform(msg.begin(), msg.end(), msg.begin(), toupper);
    std::cout << "toupper=" << msg << '\n';

    std::reverse(msg.begin(), msg.end());
    std::cout << "reverse=" << msg << '\n';

    return 0;
}