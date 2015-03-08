#include <iostream>
using namespace std;

static const int MAX_CAPACITY = 10;


class Stack {
    private:
    class Item {
        public:
        
        //Ctor
        Item() { }
        Item(int data) { value = data; }

        int value;
        Item* next;
    };

    Item* topItem;
    Stack* topStack;
    Stack* nextStack;  
    int currentStackItemCounter = -1;

    
    void PushItem(int d) {
        Item* toAdd = new Item(d);
        if (this->topItem != NULL) {
            toAdd->next = this->topItem;
        }
        this->topItem = toAdd;
    }
    int PopItem() {
        Item* toPop = this->topItem;
        if (toPop ==  NULL) return -1;
        int toReturn = toPop->value;
        this->topItem = toPop->next;
        delete toPop;
        return toReturn;
    }
    int PeekItem() {
        if (this->topItem == NULL) return -1;
        return this->topItem->value;
    }


    public:
    void Push(int d) {
        if (this->topStack == NULL) {
            this->topStack = new Stack();
        }
        this->topStack->PushItem(d);
        if (++this->currentStackItemCounter % MAX_CAPACITY == 0 &&
            this->currentStackItemCounter != 0) {
            Stack* newStack = new Stack();
            newStack->nextStack = this->topStack;
            this->topStack = newStack;
            cout << "Adding stack.\n";
        }
    }
    int Pop() {
        if (this->currentStackItemCounter == -1) return -1;
        
        int valToReturn = topStack->PopItem();
        if (--this->currentStackItemCounter % MAX_CAPACITY == 0 &&
            this->currentStackItemCounter != 0) {
            Stack* toDelete = this->topStack;
            this->topStack = toDelete->nextStack;
            delete toDelete;
            cout << "Deleting stack.\n";
        }
        
        return valToReturn;
    }
    int Peek() {
        return topStack->PeekItem();
    }
};


int main() {
    int itemsOnStack = 105;
    Stack stack;
    
    srand(time(0));
    for (int i = 0; i < itemsOnStack; i++) {
        int item = rand() % 10000;
        stack.Push(item);
        
        printf("%d Pushing %d to stack.\n", i, item);
    }
    
    std::string a;
    int res1 = 0;
    a = "";
    for (int i=0; i< itemsOnStack; i++) {
        if (res1 != -1) {
            res1 = stack.Pop();
            a += std::to_string(res1) + ",";
        }
        if (res1 == -1){
            break;
        }
    }
    printf("Values in Stack are: %s.\n", a.c_str());

    return 0;
}
