#include <iostream>
#include <stdio.h>
#include <queue>

const int NUMBER_NODES = 10;

class Node
{
public:
    Node* left = NULL;
    Node* right = NULL;
    int value = -1;
    int level = -1;
    bool isLeft = NULL;
    
    Node(int val, int lev, bool left)
    {
        value = val;
        level = lev;
        isLeft = left;
    }
    ~Node()
    {
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    Node* root;
    
    void AddNode(int val, int level)
    {
        if (root == NULL)
            root = new Node(val, level, NULL);
        else
            AddNode(val, root, level+1);
    }
    
    void AddNode(int val, Node* node, int level)
    {
        if (node->value > val)
        {
            if (node->left == NULL)
                node->left = new Node(val, level, true);
            else
                AddNode(val, node->left, level+1);
        }
        else
        {
            if (node->right == NULL)
                node->right = new Node(val, level, false);
            else
                AddNode(val, node->right, level+1);
        }
    }
    
    void PrintAll()
    {
        int level = 0;
        std::queue<Node*> parentQueue;
        std::queue<Node*> childQueue;
        
        if (this->root == NULL)
        {
            std::cout << "No nodes in tree.";
            return;
        }
        
        int prevLevel = -1;
        Node* currentNode;
        
        parentQueue.push(this->root);
        
        while (!parentQueue.empty())
        {
            currentNode = parentQueue.front();
            parentQueue.pop();
            
            if (currentNode->level != prevLevel)
            {
                std::cout << "\nNew level " << currentNode->level << "\n";
                prevLevel = currentNode->level;
            }
            std::cout << (currentNode->isLeft == NULL ? "" : currentNode->isLeft == true ? "L" : "R") << currentNode->value << ",";
            
            if (currentNode->left != NULL)
                parentQueue.push(currentNode->left);
            if (currentNode->right != NULL)
                parentQueue.push(currentNode->right);
        }
    }
};

int main()
{
    srand(time(0));
    BST* tree = new BST();
//    int level = 0;
    for (int i=0; i<NUMBER_NODES; i++)
    {
        tree->AddNode(rand() % 100, 0);
    }
    
    tree->PrintAll();
    return 0;
}
