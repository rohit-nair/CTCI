/*
    ADDED igraph HOMEBREW INSTALL LOCATION TO 
    PROJECT'S HEADER PATH.
*/

#include <iostream>

const int NUMBER_VERTICES = 5;

class Queue {
    private:
        class Node {

            public:
                int value;
                Node* next;
                Node() {
                    value = -1;
                    next = NULL;
                }
                Node(int val) {
                    value = val;
                    next = NULL;
                }

                ~Node() {
                    next = NULL;
                }
        };
        Node* head;
        Node* tail;

    public:
    Queue() {
        head = NULL;
        tail = NULL;
    }
    ~Queue() {
        head = NULL;
        tail = NULL;
    }
        void Enqueue(int val) {
            Node* foo = new Node(val);
            if (head == NULL) {
                head = foo;
                tail = foo;
                return;
            }
            tail->next = foo;
            tail = foo;
        }
        int Dequeue() {
            if (head == NULL) {
                return -1;
            }
            Node* toReturn = head;
            int valToReturn = head->value;
            head = head->next;
            delete toReturn;
            return valToReturn;
        }
        int Peek() {
            if (head != NULL) {
                return head->value;
            }
            
            return -1;
        }

};


void printAll(int** matrix) {
    for (int i=0;i<NUMBER_VERTICES;i++) {
        for (int j=0; j<NUMBER_VERTICES; j++) {
            std::cout << matrix[i][j] << ",";
        }
        std::cout << "\n";
//        ++matrix;
    }
}

// Performs depth first search.
bool doesRouteExistsDFS(int** matrix, bool visited[], int fNode, int tNode) {
    if (matrix[fNode][tNode] == 1) {
        return true;
    }
    if (visited[fNode])
        return false;
    
    for (int i = 0; i<NUMBER_VERTICES; i++) {        
        if (matrix[fNode][i]==1) {
            bool res = doesRouteExistsDFS(matrix, visited, i, tNode);
            if (res == true) {
                return true;
            }
        }
    }
    
    visited[fNode] = true;
    return false;
}

// Performs depth first search.
bool doesRouteExistsBFS(int** matrix, int fNode, int tNode) {
    Queue que;
    bool visited[NUMBER_VERTICES] = {};
    que.Enqueue(fNode);
    
    while (que.Peek() != -1) {
        int curNode = que.Dequeue();
        if (visited[curNode])
            continue;
        
        if (matrix[curNode][tNode] == 1) {
            return true;
        }

        for(int i=0;i<NUMBER_VERTICES;i++) {
            if (matrix[curNode][i] == 1) {
                que.Enqueue(i);
            }
        }
        visited[curNode] = true;
    }
    
    return false;
}


int main() {
    srand(time(0));
    int fromNode, toNode;
    fromNode = toNode = -1;
    int** adjMatrix;
    adjMatrix = new int*[NUMBER_VERTICES];
    for (int i=0; i<NUMBER_VERTICES; i++) {
        int* foo = new int[NUMBER_VERTICES];
        for (int j=0; j<NUMBER_VERTICES; j++) {
            foo[j] = i == j ? 0 : rand() % 2;
        }
        adjMatrix[i] = foo;
    }

    printAll(adjMatrix);
    
    char cont = 'y';
    
    while (cont == 'y') {
        std::cout << "Enter nodes for which to check for route:";
        if (!(std::cin >> fromNode) || !(std::cin >> toNode))
            break;
        else if ((fromNode > NUMBER_VERTICES-1 || fromNode < 0) ||
                 (toNode > NUMBER_VERTICES || toNode < 0))
        {
            std::cout << "Invalid input.\n";
            break;
        }
    
        if (fromNode == toNode)
            std::cout << "Route exists.\n";
        else {
            bool visited[NUMBER_VERTICES] = {};
            bool res = doesRouteExistsDFS(adjMatrix, visited, fromNode, toNode);
            std::cout << "Route result: " << std::boolalpha << res << "\n";
    
            bool res1 = doesRouteExistsBFS(adjMatrix, fromNode, toNode);
            std::cout << "Route result: " << std::boolalpha << res1 << "\n";
        }
        
//        std::cout << "Do you want to continue? y/n \n";
//        std::cin >> cont;
    }

    delete adjMatrix;
    return 0;
}

