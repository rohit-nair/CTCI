#include <iostream>
using namespace std;

class Tree {
    class Node {
        public:
        Node() { }
        Node(int d) {
            value = d;
            leftNode = NULL;
            rightNode = NULL;
        }

        ~Node() {
            leftNode = NULL;
            rightNode = NULL;
        }

        int value;
        Node* leftNode;
        Node* rightNode;

        void AddNode(int val) {
            if (val > this->value) {
                if (this->rightNode != NULL) {
                    this->rightNode->AddNode(val);
                }
                else {
                    this->rightNode = new Node(val);
                }
            }
            else {
                if (this->leftNode != NULL) {
                    this->leftNode->AddNode(val);
                }
                else {
                    this->leftNode = new Node(val);
                }
            }
        }

        bool Print(int level) {
            if (this == NULL) { return false; };
            
            if (level == 0) {
                printf("%d\t", this->value);
                return !(this->leftNode == NULL && this->rightNode == NULL);
            }
            else {
                bool leftHasChild = this->leftNode->Print(level-1);
                bool rightHasChild = this->rightNode->Print(level-1);
                return leftHasChild || rightHasChild;
            }
        }
        
        int MinLevel() {
            int leftDepth, rightDepth;
            leftDepth = rightDepth = 0;
            
            if (this->leftNode != NULL) {
                leftDepth = this->leftNode->MinLevel();
            }
            if (this->rightNode != NULL) {
                rightDepth = this->rightNode->MinLevel();
            }
            
            int foo = 1 + (leftDepth < rightDepth ? leftDepth : rightDepth);
            return foo;
        }
        
        int MaxLevel() {
            int leftDepth, rightDepth;
            leftDepth = rightDepth = 0;
            
            if (this->leftNode != NULL) {
                leftDepth = this->leftNode->MaxLevel();
            }
            if (this->rightNode != NULL) {
                rightDepth = this->rightNode->MaxLevel();
            }
            
            return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
        }

    };
    
    public:
    Tree() {
        root = NULL;
    }
    ~Tree() {
        delete root;
    }

    Node* root;

    void AddNode(int val) {
        if (this->root == NULL) {
            this->root = new Node(val);
        }
        else {
            this->root->AddNode(val);
        }
    }

    void Print() {  // Breadth first print.
        int level = 0;
        bool hasChild = this->root != NULL;
        
        while (hasChild) {
            hasChild = this->root->Print(level);
            ++level;
            cout << "\n";
        }
    }
    
    int MinLevel() {
        int level = 0;
        if (this->root != NULL) {
            level = this->root->MinLevel();
        }
        return level;
    }
    
    int MaxLevel() {
        int level = 0;
        if (this->root != NULL) {
            level = this->root->MaxLevel();
        }
        return level;
    }
    
    bool IsBalanced() {
        return MaxLevel() - MinLevel() <= 1;
    }
};


int main() {
    int nodeCount = 15;
    Tree* binaryTree = new Tree();

    srand(time(0));
    
    for (int i=0; i< nodeCount; i++) {
        int nodeVal = rand() % 1000;
        printf("%d - Adding value: %d.\n", i, nodeVal);
        binaryTree->AddNode(nodeVal);
    }

    binaryTree->Print();
    
    printf("Min depth: %d \t Max depth: %d.\n", binaryTree->MinLevel(), binaryTree->MaxLevel());
    
    printf("Is tree balanced: %s.\n", binaryTree->IsBalanced() ? "True" : "False");

    delete binaryTree;
}
