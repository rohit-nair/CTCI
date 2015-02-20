// Permutation also called Anagrams.

#include<iostream>

// Wrong
bool isPermutation(std::string s1, std::string s2)
{
    // Find unique characters in s1 and s2
    char s1Uniq [s1.length()], s2Uniq [s2.length()];
    char* s1Runner = &s1[0];
    char* s2Runner = &s2[0];
    
    int s1Tracker, s2Tracker = 0;
    int counter = 0;
    int val;
    while (*s1Runner)
    {
        val = *s1Runner - 'a';
        if (!(s1Tracker & (1 << val)))
        {
            s1Uniq[counter] = *s1Runner;
            s1Tracker |= (1 << val);
            ++counter;
        }
    }

    counter = 0; val = 0;
    while (*s2Runner)
    {
        val = *s2Runner - 'a';
        if (!(s2Tracker & (1 << val)))
        {
            s2Uniq[counter] = *s2Runner;
            s2Tracker |= (1 << val);
            ++counter;
        }
    }

    // If one is a subset of another then it's a permutation
    //      Find intercept of array.
    
    return false;
}

// Right
bool anagram(std::string s1, std::string s2)
{
    if (s1.empty() || s2.empty())
        return false;

    if (s1.length() != s2.length())
        return false;

    int charCounter [256] = { 0 };
    char* ptr = &s1[0];
    while (*ptr)
    {
        ++charCounter[*ptr];
        ++ptr;
    }

    ptr = &s2[0];
    while (*ptr)
    {
        if (--charCounter[*ptr] < 0)
            return false;
        ++ptr;
    }
    return true;
}

int main()
{
    std::string s1 = "god";
    std::string s2 = "dog";
    bool res = anagram(s1, s2);
    if (res)
        printf("%s and %s strings are anagram.\n", s1.c_str(), s2.c_str());
    else
        printf("%s & %s strings are not anagrams.\n", s1.c_str(), s2.c_str());

    return 0;
}
