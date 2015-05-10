#include "Tree.h"

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


