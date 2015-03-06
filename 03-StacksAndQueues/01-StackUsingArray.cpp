#include <iostream>

class Item {
    public:
    int data;
    int indexPrevItem;

    Item() { }
    Item(int i, int prevIndex) { 
        data = i;
        indexPrevItem = prevIndex;
    }
};

class Stack {
    static const int NUMBER_STACKS = 3;
    int currentIdx = 0;
    int stackLastIdx[NUMBER_STACKS] = { -1, -1, -1 };
    Item* stack[300] = { };


    public:
    void Push(int item, int stackIdx) {

        Item* task = new Item(item, stackLastIdx[stackIdx]);
        stack[currentIdx] = task;
        stackLastIdx[stackIdx] = currentIdx++;


    }

    int Pop(int stackIdx) {
        int idxToPop = stackLastIdx[stackIdx];
        if (idxToPop == -1) {
            return -1;
        }
        
        Item* itemToPop = stack[idxToPop];
        stackLastIdx[stackIdx] = itemToPop->indexPrevItem;
        int returnVal = itemToPop->data;
        delete itemToPop;
        return returnVal;
    }
};

int main() {
    srand(time(0));
    Stack taskList;
    for (int i = 0; i < 10; i++) {
        int item = rand() % 10000;
        int stack = rand() % 3;
        taskList.Push(item, stack);

        printf("Pushing %d to stack %d.\n", item, stack+1);
    }

    std::string a, b, c;
    int res1, res2, res3;
    a = b = c = "";
    res1 = res2 = res3 = 0;
    for (int i=0; i< 10; i++) {
        if (res1 != -1) {
            res1 = taskList.Pop(0);
            a += std::to_string(res1) + ",";
        }
        if (res2 != -1) {
            res2 = taskList.Pop(1);
            b += std::to_string(res2) + ",";
        }
        if (res3 != -1) {
            res3 = taskList.Pop(2);
            c += std::to_string(res3) + ",";
        }
    }
    printf("Stack 1: %s.\n", a.c_str());
    printf("Stack 2: %s.\n", b.c_str());
    printf("Stack 3: %s.\n", c.c_str());
    
    return 0;
}


