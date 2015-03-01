#include <iostream>

class Node {
    public:
    int data;
    Node* next;

    Node() { }
    Node(int d) { data = d; }
};

class LinkedList {
    public:
    Node* head;

    void addToEnd(int d) {
        Node* current = new Node(d);
        Node* runner = this->head;
        if (this->head == NULL) {
            this->head = current;
            return;
        }

        while (runner->next != NULL) {
            runner = runner->next;
        }
        runner->next = current;
    }

    void printAll() {
        if (this->head == NULL) {
            std::cout << "No nodes found in List.";
        }
        Node* current = this->head;
        while (current != NULL) {
            printf("%d,", current->data);
            current = current->next;
        }
    }
    LinkedList* AddLists(LinkedList* b) {
        LinkedList* result = new LinkedList();
        Node* currentA = this->head;
        Node* currentB = b->head;
        int aVal, bVal, sum, carry = 0;
        
        std::cout << currentA;
        std::cout << currentB;
        
        
        do {
            if (currentA != NULL) {
                aVal = currentA->data;
                printf("CurrentA: %d\n", currentA->data);
                currentA = currentA->next;
            }
            else{
                aVal= 0;
            }
            
            if (currentB != NULL) {
                bVal = currentB->data;
                printf("CurrentB: %d\n", currentB->data);
                currentB = currentB->next;
            }
            else {
                bVal = 0;
            }
            
            sum = aVal + bVal + carry;
            
            printf("%d, %d, %d, %d\n", aVal, bVal, carry, sum);
            
            result->addToEnd(sum % 10);
            carry = sum / 10;
        }
        while (currentA != NULL || currentB != NULL || carry != 0);
        
        return result;
    };

};

int main() {
    int a, b;
    LinkedList* als = new LinkedList();
    LinkedList* bls = new LinkedList();
    
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;

    int arem = a, brem = b;
    int divisor = 10;
    
    while (arem%divisor != 0) {
        als->addToEnd(arem%divisor);
        arem = arem/divisor;
    }
    
    while (brem%divisor != 0) {
        bls->addToEnd(brem%divisor);
        brem = brem/divisor;
    }
    
    als->printAll();
    bls->printAll();
    
    LinkedList* res = als->AddLists(bls);
    
    std::cout << "Printing result;\n";
    res->printAll();
}
