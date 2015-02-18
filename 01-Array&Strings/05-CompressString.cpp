#include <iostream>

void compress(std::string extStr)
{
    int counter = 0;
    int runner = 0;
    unsigned long length = extStr.length();
    std::string res = "";
    while (runner < length)
    {
        counter = 1;
        char current = extStr[runner];
        while(extStr[++runner] == current)
        {
            ++counter;
        }
        res += current;
        res += std::to_string(counter);
    }
    std::cout << res;
}


//int main()
//{
//    std::string str = "abbcccddddeeeeeffffffggggggg         ";
//    compress(str);
//    return 0;
//}
