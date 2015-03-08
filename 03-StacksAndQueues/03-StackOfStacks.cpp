#include <iostream>
using namespace std;

static const int MAX_CAPACITY = 10;

class Stacks {
    private:
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
        Item* head;

        public:
        Stack* nextStack;
        void Push(int d) {
            Item* toAdd = new Item(d);
            if (this->head != NULL) {
                toAdd->next = this->head;
            }
            this->head = toAdd;
        }
        int Pop() {
            Item* toPop = this->head;
            if (toPop ==  NULL) return -1;
            int toReturn = toPop->value;
            this->head = toPop->next;
            delete toPop;
            return toReturn;
        }
        int Peek() {
            if (this->head == NULL) return -1;
            return this->head->value;
        }
    };
    Stack* topStack;
    int currentStackItemCounter = -1;

    public:
    //Ctor
    Stacks () { topStack = new Stack(); }
    
    void Push(int d) {
        this->topStack->Push(d);
        if (++this->currentStackItemCounter % MAX_CAPACITY == 0 &&
            this->currentStackItemCounter != 0) {
            Stack* newStack = new Stack();
            newStack->nextStack = this->topStack;
            this->topStack = newStack;
            cout << "Adding stack.\n";
        }
    }
    int Pop() {
        if (this->currentStackItemCounter == 0) return -1;
        
        int valToReturn = topStack->Pop();
        if (--this->currentStackItemCounter % MAX_CAPACITY == 0) {
            Stack* toDelete = this->topStack;
            this->topStack = toDelete->nextStack;
            delete toDelete;
            cout << "Deleting stack.\n";
        }
        
        return valToReturn;
    }
    int Peek() {
        return topStack->Peek();
    }
};


int main() {
    int itemsOnStack = 25;
    Stacks stack;
    
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
