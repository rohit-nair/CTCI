#include <iostream>
using namespace std;

class Stack {
    class Item {
        public:
        //Ctor
        Item() { }
        Item(int data) {
            value = data;
        }

        //D'ctor
        ~Item() {
            next = NULL;
        }

        int value;
        Item* next;
    };
    
    public:
    ~Stack() {
        this->head = NULL;
    }
    
    Item* head = NULL;
    

    // Methods
    void Push(int valToPush) {
        Item* val = new Item(valToPush);
        if (this->head != NULL) {
            val->next = this->head;
        }
        this->head = val;
    }

    int Peek() {
        if (this->head == nullptr) {
            return -1;
        }
        return this->head->value;
    }

    int Pop() {
        if (this->head == NULL) {
            return -1;
        }

        Item* toPop = this->head;
        this->head = toPop->next;
        int val = toPop->value;
        delete toPop;
        return val;
    }
    
    bool IsEmpty() {
        return this->head == NULL;
    }
    
    Stack Sort() {
        Stack buffer;
        
        while (!this->IsEmpty()) {
            int currentItem = this->Pop();
            while (!buffer.IsEmpty() && buffer.Peek() < currentItem) {
                this->Push(buffer.Pop());
            }
            buffer.Push(currentItem);
        }
        return buffer;
    }
    
    void PrintAll() {
        int idx = 1;
        Item* top = this->head;
        while (top != NULL) {
            printf("Item %d is %d.\n", idx++, top->value);
            top = top->next;
        }
    }
};


int main() {
    int itemsOnStack = 13;
    Stack stack;
    
    srand(time(0));

    for (int i=0; i<itemsOnStack; i++) {
        int val = rand() % 1000;
        printf("%d - Pushing value %d.\n", i+1, val);
        stack.Push(val);
    }
    
//    for (int i=0; i<itemsOnStack; i++) {
//        printf("Poping value %d.\n", stack.Pop());
//    }
    
    Stack sortedStack = stack.Sort();
    sortedStack.PrintAll();
    
    return 0;
}
