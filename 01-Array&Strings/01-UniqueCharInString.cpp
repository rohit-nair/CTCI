#include <iostream>
#include<string>

bool IsUnique(std::string str)
{
    if (str.length() > 256)
        return false;

    int64_t checker = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int val = str[i] - 'a';
        __int64_t shift = 1ULL;
        if (checker & (shift << val))
            return false;
        checker |= (shift << val);
    }
    return true;
}

int main()
{
    std::string s = "sdfhjeruioqp";
    bool res = IsUnique(s);
    if (res)
        std::cout << "Unique string.\n";
    else
        std::cout << "Duplicate characters found in string.\n";
    return 0;
}
