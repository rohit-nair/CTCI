#include <iostream>

bool IsRotationOf(std::string a, std::string b)
{
    return a.find(b);
}

int main()
{
    std::string a, b;

    std::cout << "Enter string one: ";
    std::cin >> a;

    std::cout << "Enter string two: ";
    std::cin >> b;

    if (IsRotationOf(a+a, b))
        printf("%s is a rotation of %s. \n", b.c_str(), a.c_str());
    else
        printf("%s is not a rotation of %s. \n", b.c_str(), a.c_str());
}
