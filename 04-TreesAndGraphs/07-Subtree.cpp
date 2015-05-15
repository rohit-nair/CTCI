//Finding whether x is a sub-tree of y
//1. Iterate through nodes of y searching for
//    a node that is same as root of the x
//2. iterate through each node of x comparing to 
//    the sub-tree of the node found in 1.


#include "RandomTree.h"

#include <iostream>
#include <chrono>
#include <thread>


bool MatchWholeTree(Node* node, Node* subTreeNode) {
    if (node == NULL && subTreeNode == NULL)
        return true;
    if (node == NULL)
        return false;
    if (node->Value != subTreeNode->Value)
        return false;
    
    bool res = true;
    if (subTreeNode->LChild != NULL)
        res = res && MatchWholeTree(node->LChild, subTreeNode->LChild);
    if (subTreeNode->RChild != NULL)
        res = res && MatchWholeTree(node->RChild, subTreeNode->RChild);
    
    return res;
}


bool IsSubTree(Node* node, Node* subTree) {
    if (node == NULL)
        return false;
    if (node->Value == subTree->Value) {
        bool res = MatchWholeTree(node, subTree);
        if (res) {
            return true;
        }
    }
    
    return IsSubTree(node->LChild, subTree) || IsSubTree(node->RChild, subTree);
}



int main() {
    RandomTree* hugeTree = new RandomTree();
    hugeTree->Blossom(50);
    
//    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    
    RandomTree* subTree = new RandomTree();
    subTree->Blossom(5);
    
    printf("Main tree:\n");
    hugeTree->PrintAll();
    
    printf("Sub tree:\n");
    subTree->PrintAll();
    
    if (IsSubTree(hugeTree->Root, subTree->Root)) {
        printf("\nIs sub tree!");
    }
    else
        printf("\nNot a sub tree.");
    
    return 0;
}


