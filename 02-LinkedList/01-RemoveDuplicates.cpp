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

    
};

int main()
{
    LinkedList* ls = new LinkedList();
    
    for (int i = 0; i < 10; i++) {
        ls->appendToTail(rand() % 9);
    }
    
    ls->printAll();
    ls->RemoveDuplicates();
    ls->printAll();
    
    ls->deleteAll();
    printf("Deleting %d \n", ls->head->data);
    
    delete ls;
}
