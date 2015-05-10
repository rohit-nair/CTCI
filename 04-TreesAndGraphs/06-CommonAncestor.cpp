#include "Tree.h"

// Keeps track of number of nodes found
// so that we could bail out the moment we
// find both.
static int NODES_FOUND = 0;
// Flags which of the node is found so that
// it doesn't increment counter in case of duplicates.
// The higher node is picked in case duplicate values.
static bool PFOUND = false;
static bool QFOUND = false;

Node* DFS(Node* current, int p, int q)
{
    // The photo frame for the ancestor we are looking for.
    Node* ancestor = NULL;
    // Let's just keep track of the nodes people
    // found before here so that we could rightly
    // take the bounty if we find both!
    int nodesFoundBefore = NODES_FOUND;
    
    // Doh, Nothing to see here. Off you go.
    if (current == NULL) {
        return NULL;
    }
    
    // Ah ha, could this be it?
    if ((current->value == p && !PFOUND) || (current->value == q && !QFOUND)) {
        // Found one!
        ++NODES_FOUND;
        
        // Well let's just flag the value we found
        // so that we don't get trapped by duplicates.
        if (!PFOUND && current->value == p) {
            PFOUND = true;
        }
        else if (!QFOUND && current->value == q) {
            QFOUND = true;
        }
        
        // What! That makes it two?! Phew time to go home.
        if (NODES_FOUND == 2) {
            // Well, this completes the quest to find nodes,
            // bubble up to determine ancestor.
            return NULL;
        }
    }
    
    // Quest for nodes continues...
    ancestor = DFS(current->LChild, p, q);
    
    // Common ancestor was in the left sub-tree.
    // Let's just bubble it up. Off you go...
    if (ancestor != NULL) {
        return ancestor;
    }
    
    // Before processing this node, we hadn't found any nodes
    // but now we have found two and the ancestor is not
    // one of it's siblings. Well then, guilty as charged.
    // This is the common ancestor.
    if (NODES_FOUND == 2 && nodesFoundBefore == 0) {
        // Both these nodes were in the left sub tree.
        // This is the ancestor we were looing for. Woohoo!
        return current;
    }
    
    // Didn't find the nodes in the left sub-tree. Let's
    // try our hand on the right one. Who knows, may be
    // we will get lucky!
    ancestor = DFS(current->RChild, p, q);
    
    // Ah ha, found something in the sub-tree...
    // Let's just bubble it up. Off you go...
    if (ancestor != NULL) {
        return ancestor;
    }
    
    // Well again, before processing this node, we hadn't found any nodes
    // but now we have found two and the ancestor is not
    // one of it's siblings. Well then, guilty as charged.
    // This is the common ancestor.
    if (NODES_FOUND == 2 && nodesFoundBefore == 0) {
        // Both these nodes were in the left sub tree.
        // This is the ancestor we were looing for. Woohoo!
        return current;
    }
    
    // This is awkward. We are here, that means we didn't get
    // any fish! Let's try it a level higher.
    return NULL;
}

int main() {
    srand(time(0));
    
    // It's a BST but the algo doesn't take that into
    // consideration while determining ancestors.
    Tree* tree = new Tree();
    // Randomly initializing a tree.
    for (int i=0; i<15; i++) {
        int foo = rand() % 100;
        printf("%d, ", foo);
        tree->AddChild(foo);
    }
    
    // Printing the tree for reference.
    printf("\n\n");
    tree->PrintAll();
    
    int p = 0, q = 0;
    while (p != -1 && q != -1) {
        printf("\nEnter nodes for which to find common ancestor:\n");
        std::cin >> p >> q;
        
        if (p == q) {
            printf("Split personality, eh?");
            continue;
        }
        
        Node* ancestor = DFS(tree->root, p, q);
        if (ancestor != NULL) {
            printf("\nCommon ancestor is: %d.", ancestor->value);
        }
        else
            printf("\nNo ancestors found. Nodes not in the tree.");
        
        // Resetting.
        NODES_FOUND = 0;
        PFOUND = false;
        QFOUND = false;
    }
    
    return 0;
}

