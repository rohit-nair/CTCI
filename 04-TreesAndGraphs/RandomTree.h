#include <iostream>

class Node {
    public:
    int Value = 0;
    Node* LChild = NULL;
    Node* RChild = NULL;

    Node(int val);
    void AddNode(int value);
    Node* FindNode(int value);
};

class RandomTree {
    public:
    Node* Root = NULL;
    void PrintAll();
    void Blossom();
    Node* FindNode(int value);
};
