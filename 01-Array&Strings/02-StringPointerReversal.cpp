#include<iostream>

void reverse(char* str)
{
    char* foo = str;
    if (str ==  NULL)
        return;
    
    int count = 0;
    char* s = str;
    while (*s)
    {
        count++;
        s++;
    }

    printf("%d characters in string. \n", count);

    char temp;
    --s;
    while (str < s)
    {        
        temp = *str;
        *str++ = *s;
        *s-- = temp;
    }

    printf(foo);
}

//int main()
//{
//    std::string str = "This is a character string.";
//    reverse(&str[0]);
//    return 0;
//}
