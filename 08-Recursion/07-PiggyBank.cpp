#include <iostream>
#include <vector>

int DENOMINATIONS[3] = { 5, 10, 25 };

void CalcAmount(int sum, int deno, int target, std::string path) {
    int tot = sum + deno;
    path += std::to_string(deno) + ",";

    if (tot > target)
        return;
    if (tot == target) {
        std::cout << path << "\n";
        return;
    }

    CalcAmount(tot, 5, target, path);
    CalcAmount(tot, 10, target, path);
    CalcAmount(tot, 25, target, path);
}



int main() {
    int target = 0;
    while (true) {
        std::cout << "Enter target amount. \n";
        std::cin >> target;
        CalcAmount(0, DENOMINATIONS[rand() % 3], target, "");
    }

    return 0;
}
