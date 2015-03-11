#include <iostream>
using namespace std;

class Stack {
    private:
    class Item {
        public:
        // Ctor
        Item() { }
        Item(int d) {
            value = d;
        }
        
        ~Item() {
            next = NULL;
        }
        
        int value;
        Item* next;
    };
    Item* top;

    public:
    void Push(int data) {
        Item* newItem = new Item(data);
        if (this->top != NULL) {
            newItem->next = this->top;
        }
        this->top = newItem;
    }

    int Peek() {
        if (top == NULL)
            return -1;

        return top->value;
    }

    int Pop() {
        Item* toPop = this->top;
        if (toPop ==  NULL) return -1;
        int toReturn = toPop->value;
        this->top = toPop->next;
        delete toPop;
        return toReturn;
    }

};

class Queue {
    private:
    Stack* pushStack;
    Stack* popStack;

    public:
    Queue() {
        pushStack = new Stack();
        popStack = new Stack();
    }
    
    ~Queue() {
        pushStack = NULL;
        popStack = NULL;
    }

    void Enqueue (int value) {
        pushStack->Push(value);
    }

    int Dequeue() {
        if (pushStack->Peek() == -1) {
            return NULL;
        }

        while (pushStack->Peek() != -1) {
            popStack->Push(pushStack->Pop());
        }

        int valueToReturn = popStack->Pop();
        int val = -1;

        while (popStack->Peek() != -1) {
            val = popStack->Pop();
            pushStack->Push(val);
        }

        return valueToReturn;
    }
};


int main() {
    int items = 15;
    int itemToQueue;
    Queue que;

    srand(time(0));
    for (int i=0; i<items; i++) {
        itemToQueue = rand() % 1000;
        printf("%d - Queueing %d.\n", i+1, itemToQueue);
        que.Enqueue(itemToQueue);
    }

    for (int j=0; j < items; j++) {
        printf("%d - Value dequeued is %d.\n", j, que.Dequeue());
    }

    return 0;
}
