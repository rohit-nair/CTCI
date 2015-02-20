#include <iostream>

void replaceWith20(char *str)
{
    int spaces = 0;
    int length = 1;
    char *temp = str;
    // Pass 1: Count spaces
    while (*temp != '\0')
    {
        if (*temp == ' ')
            ++spaces;
        ++length;
        ++temp;
    }
    char* runner = temp;
    for (int i = 0; i < spaces * 2; i++)
    {
        ++runner;
    }
    
    for (int j = 0; j < length; j++)
    {
        if (*temp == ' ')
        {
            *runner = '0';
            *(--runner) = '2';
            *(--runner) = '%';
        }
        else    
            *runner = *temp;

        --runner;
        --temp;
    }
}

int main()
{
    std::string str = "This is a string to replace.";
    char *strToReplace = &str[0];
    replaceWith20(strToReplace);
    std::cout << strToReplace;
    return 0;
}
