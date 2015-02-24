#include <iostream>

class Node {
    public:
    int data;
    Node* next;
    
    // Ctor
    Node() : next(NULL) { }
    Node (int d) : next(NULL)
    {
        data = d;
        next = nullptr;
    }
    
    // Methods
    void deleteAll()
    {
        Node* current = this;
        while (current != NULL) {
        
            if (current->next != NULL)
            {
                current->next->deleteAll();
            
                printf("Deleting %d \n", current->next->data);
                delete current->next;
                return;
            }
            else {
                return;
            }
        }
    }

};

class LinkedList {
    public:
    Node *head;
    
    // Ctor
    LinkedList()
    {
        
    }
    
    LinkedList(int val)
    {
        head = new Node(val);
    }
    
    // Methods
    void appendToTail(int d) {
        Node* n = new Node(d);
        if (head == NULL)
        {
            head = n;
            return;
        }
        
        Node* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = n;
    }
    
    void printAll() {
        Node* current = head;
        while (current != NULL) {
            printf("%d,", current->data);
            
            current = current->next;
        }
        printf("\n");
    }
    
    void RemoveDuplicates() {
        Node* previous = head;
        Node* current = head->next;
        Node* runner = head;
        
        while (current != NULL) {
            runner = head;
            while (runner != current) {
                if (runner->data == current->data)
                {
                    printf("Removing duplicate %d.\n", current->data);
                    Node* temp = current;
                    previous->next = current->next;
                    current = current->next;
                    delete temp;
                    break;
                }
                runner = runner->next;
            }
            if (runner == current)
            {
                previous = current;
                current = current->next;
            }
        }
    }

    
    void deleteAll() { head->deleteAll(); }

    Node* nthElement(int n)
    {
        int i = 0;
        Node* current = head;
        Node* runner = head;

        while (i < n) {
            runner = runner->next;
            i++;
            if (runner == NULL) {
                printf("List has less than %d elements.\n", n);
                return runner;
            }
        }

        while (runner != NULL) {
            runner = runner->next;
            current = current->next;
        }

        return current;
    }

    
};

int main()
{
    LinkedList* ls = new LinkedList();
    
    srand(time(0));
    for (int i = 0; i < 15; i++) {
        ls->appendToTail(rand() % 25);
    }

    ls->printAll();
    
    Node* nthElement = ls->nthElement(25);
    if (nthElement != NULL)
        printf("%dth element from end is %d.\n", 3, nthElement->data);
    
    ls->RemoveDuplicates();
    ls->printAll();
    
    ls->deleteAll();
    printf("Deleting %d \n", ls->head->data);
    
    delete ls;
}
