#include "05-FindSuccessor.h"

#include <iostream>
#include <queue>

void Node::SetNull() {
    value = 0;
    Parent = NULL;
    LChild = NULL;
    RChild = NULL;
    
}

Node::Node(int val, Node* parent) {
    SetNull();
    value = val;
    Parent = parent;
}

void Node::AddChild(int val) {
    if (val < value) {
        if (LChild != NULL)
            LChild->AddChild(val);
        else
            LChild = new Node(val, this);
    }
    else {
        if (RChild != NULL)
            RChild->AddChild(val);
        else
            RChild = new Node(val, this);
    }
}

Node* Node::FindNode(int val) {
    if (value == val)
        return this;
    
    Node* found = NULL;
    if (LChild != NULL)
        found = LChild->FindNode(val);
    if (found != NULL)
        return found;
    if (RChild != NULL)
        found = RChild->FindNode(val);

    return found;
}

void Tree::AddChild(int val){
    if (root == NULL) {
        root = new Node(val, NULL);
        return;
    }

    root->AddChild(val);
}

void Tree::PrintAll() {
    if (root ==  NULL) {
        printf("No items in tree.");
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        unsigned long items = q.size();
        while(items > 0) {
            Node* node = q.front();
            q.pop();
            if (node == NULL) {
                --items;
                continue;
            }

            printf("%d, ",node->value);

            q.push(node->LChild);
            q.push(node->RChild);


            --items;
        }
        std::cout << "\n";
    }


}

Node* Tree::FindNode(int val) {
    if (root == NULL)
        return NULL;
    
    return root->FindNode(val);
}
    
Node* Tree::FindSuccessor(Node* node, Node* from) {
    Node* successor = NULL;
    
    if (node != NULL) {
        // If has right child, return left most node or right child
        if (node->RChild != NULL) {
            successor = node->RChild;
            while (successor->LChild != NULL) {
                successor = successor->LChild;
            }
        }
        // Find the parent for first left branch.
        else {
            while (node->Parent != NULL && node->Parent->RChild == node) {
                node = node->Parent;
            }
            successor = node->Parent;
        }
        // Buggy code
//            // If has Right child, it's successor
//            if (node->RChild != NULL && node->RChild != from)
//                successor = node->RChild;
//            // If current node is left child, successor is parent
//            else if (node->Parent != NULL && node == node->Parent->LChild)
//                successor = node->Parent;
//            // Else successor is the parent of the last left child
//            else {
//                successor = FindSuccessor(node->Parent, node);
//            }
    }
    return successor;
}
    
void Tree::FindSuccessor(int val) {
    Node* successor = NULL;
    Node* node = FindNode(val);
    
    if (node == NULL) {
        printf("Invalid Node.");
        return;
    }
    
    successor = FindSuccessor(node, NULL);
    
    if (successor != NULL) {
        printf("\nSuccessor: %d.\n", successor->value);
    }
    else
        printf("\nNo successor.");
}

int main() {
    srand(time(0));
    Tree* tree = new Tree();

    for (int i=0; i<10; i++) {
        int foo = rand() % 100;
        printf("%d, ", foo);
        tree->AddChild(foo);
    }
    printf("\n\n");
    tree->PrintAll();
    
    int nodeSuccessor = -1;
    
    while (nodeSuccessor != 0) {
        printf("\nNode: ");
        std::cin >> nodeSuccessor;
    
        tree->FindSuccessor(nodeSuccessor);
    }
    return 0;
}
