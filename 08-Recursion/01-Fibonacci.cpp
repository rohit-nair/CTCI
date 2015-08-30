#include <iostream>
#include <vector>

static int COUNTER = 0;

int Fibonacci(int n, std::vector<int>* cache, bool useCache) {
    if (n==2 || n==1)
        return 1;
    
    if ((*cache)[n] != 0 && useCache) {
        return (*cache)[n];
    }
    ++COUNTER;
    
    
    int res = Fibonacci(n-1, cache, useCache) + Fibonacci(n-2, cache, useCache);
    (*cache)[n] = res;
    return res;
}



int main() {
    int n = 1;
    bool useCache = false;
    char foo;
    while (true) {
        printf("Enter the fibonacci number to find. Enter -1 to exit.\n");
        std::cin>>n;
        printf("Use cache?\n");
        std::cin>>useCache;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        if (n < 1) break;
        COUNTER = 0;
        std::vector<int> cache(n);
        std::cout << "\nFibonacci Number: " << Fibonacci(n, &cache, useCache) << "\n";
        std::cout << "Iterations: " << COUNTER << "\n";
        std::cout << "Press any key\n";
        std::cin >> foo;
    }

    return 0;
}
