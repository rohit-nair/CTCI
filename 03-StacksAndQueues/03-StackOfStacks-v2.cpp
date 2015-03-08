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
        if (++this->currentStackItemCounter % MAX_CAPACITY == 9) {
            Stack* newStack = new Stack();
            newStack->nextStack = this->topStack;
            this->topStack = newStack;
            cout << "Adding stack.\n";
        }
    }
    int Pop() {
        if (this->currentStackItemCounter == -1) return -1;
        
        int valToReturn = topStack->PopItem();
        if (--this->currentStackItemCounter % MAX_CAPACITY == 9) {
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

    int Peek(int index) {
        int stackNumber = this->currentStackItemCounter / MAX_CAPACITY - index / MAX_CAPACITY;
        int idxOnStack = (stackNumber == 0 ? this->currentStackItemCounter % MAX_CAPACITY : MAX_CAPACITY - 1) - (index % MAX_CAPACITY);
        Stack* currentStack = this->topStack;
        Item* currentItem = nullptr;

        for (int i = 0; i < stackNumber; i++) {
            currentStack = currentStack->nextStack;
        }

        currentItem = currentStack->topItem;
        for (int j = 0; j < idxOnStack; j++) {
            currentItem = currentItem->next;
        }
        return currentItem->value;
    }
};


int main() {
    int itemsOnStack = 15;
    Stack stack;
    
    srand(time(0));
    for (int i = 0; i < itemsOnStack; i++) {
        int item = rand() % 10000;
        printf("%d Pushing %d to stack.\n", i, item);
        stack.Push(item);
    }

    int indexToPeek = rand() % itemsOnStack - 1;
    printf("Item at %d is %d.\n", indexToPeek, stack.Peek(indexToPeek));
    
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
