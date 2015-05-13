#include "RandomTree.h"

#include <iostream>
#include <queue>

Node::Node(int val) {
    Value = val;
    LChild = RChild = NULL;
}

void Node::AddNode(int val) {
    bool left = rand() % 2;

    if (left) {
        if (LChild != NULL)
            LChild->AddNode(val);
        else
            LChild = new Node(val);
    }
    else {
        if (RChild != NULL)
            RChild->AddNode(val);
        else
            RChild = new Node(val);
    }
}

void RandomTree::PrintAll() {
    if (Root ==  NULL) {
        printf("No items in tree.");
    }

    std::queue<Node*> q;
    q.push(Root);

    while (!q.empty()) {
        unsigned long items = q.size();
        while(items > 0) {
            Node* node = q.front();
            q.pop();
            if (node == NULL) {
                --items;
                continue;
            }

            printf("%d, ",node->Value);

            q.push(node->LChild);
            q.push(node->RChild);


            --items;
        }
        std::cout << "\n";
    }

}

void RandomTree::Blossom() {
    srand(time(0));

    for (int i=1; i<15; i++) {
        int val = rand() % 11;
        if (Root == NULL) {
            Root = new Node(val);
            continue;
        }

        Root->AddNode(val);
    }
}

Node* Node::FindNode(int value) {
    if (Value == value)
        return this;
    
    Node* found = NULL;
    if (LChild != NULL)
        found = LChild->FindNode(value);
    if (found != NULL)
        return found;
    if (RChild != NULL)
        found = RChild->FindNode(value);

    return found;
}
