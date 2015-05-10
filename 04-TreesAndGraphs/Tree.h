#include <iostream>
#include <queue>

class Node;
class Tree;

class Node {
    public:
        int value;
        Node* Parent;
        Node* LChild;
        Node* RChild;
    
    Node(int val, Node* parent);
    
    void SetNull();
    void AddChild(int val);
    Node* FindNode(int val);

};

class Tree {
    private:
        class Item {
            int value;
        };

    public:
        Node* root;

        void AddChild(int val);
        void PrintAll();
        Node* FindNode(int val);
};

