#include "RandomTree.h"

#include <iostream>
#include <vector>

void PrintPathsEquallingSum(Node* node, std::vector<int> ledger, int checkSum) {
    if (node == NULL)
        return;
    
    ledger.push_back(node->Value);
    std::vector<int>::reverse_iterator it = ledger.rbegin();
    int sum = 0;
    do {
        sum += *it;
        if (sum == checkSum) {
            std::vector<int>::reverse_iterator itRunner = it;
            int dec = sum;
            do {
                printf("%d,", *itRunner);
                dec -= *itRunner;
                --itRunner;
            } while (dec != 0);
            printf("\n");
        }
    } while (++it != ledger.rend());
    PrintPathsEquallingSum(node->LChild, ledger, checkSum);
    PrintPathsEquallingSum(node->RChild, ledger, checkSum);
}

void PrintPathsEquallingSum(int checkSum, RandomTree* tree){
    if (tree == NULL || tree->Root == NULL) {
        printf("No nodes found.");
        return;
    }
    
    std::vector<int> ledger;
    PrintPathsEquallingSum(tree->Root, ledger, checkSum);
}

const int NODES_COUNT = 20;

int main() {
    RandomTree* tree = new RandomTree();
    tree->Blossom(NODES_COUNT);

    tree->PrintAll();
    int checkSum = 0;
    while (true) {
        std::cout << "Enter sum for which paths need to be found. Enter -1 to exit. \n";
        std::cin >> checkSum;
        
        if (checkSum == -1) {
            break;
        }
        
        PrintPathsEquallingSum(checkSum, tree);
    }
}

