#include <iostream>
#include <bitset>


int main() {
    int x = ~0;
    int y = 384783874;
    int z = 13;
    
    int i=14, j=11;
    
    int rightShiftedZ = z<<j;
    int maskY = x<<(i+1) | (x^(x<<j));
    int clearedOutY = y & maskY;
    int res = clearedOutY | rightShiftedZ;
    
    std::bitset<32> a(x);
    std::bitset<32> b(y);
    std::bitset<32> c(z);
    
    std::cout << a << "\n" << b << "\n" << c << "\n";
    
    std::bitset<32> d(rightShiftedZ);
    std::bitset<32> e(maskY);
    std::bitset<32> f(clearedOutY);
    std::bitset<32> g(res);
    
    std::cout << d << "\n" << e << "\n" << f << "\n" << g;
    
    pow(2,-1)+pow(2,-2)+pow(2,-5)+pow(2,-8)
    
    return 0;
}