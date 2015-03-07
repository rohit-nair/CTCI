#include <iostream>

class Stack {
    class Item {
        public:
        // Ctor
        Item() {}
        Item(int i) { data = i; }

        int data;
        Item* next;
    };
    public:
    Item* head;
    Item* min;

    void Push(int d) {
        Item* newItem = new Item(d);
        if (this->head != NULL) {
            newItem->next = this->head;
        }
        this->head = newItem;

        // Handling minimums
        int currentMin = Minimum();
        if (currentMin == -1) {
            this->min = new Item(d);
        }
        else {
            if (d <= currentMin) {
                Item* temp = this->min;
                this->min = new Item(d);
                this->min->next = temp;
            }
        }
    }

    int Peek() {
        if (this->head == NULL) {
            return -1;
        }
        return this->head->data;
    }

    int Pop() {
        if (this->head == NULL) {
            return -1;
        }
        Item* temp = this->head;
        this->head = temp->next;
        int valToReturn = temp->data;
        
        if (temp->data == Minimum()) {
            Item* tempMin = this->min;
            this->min = tempMin->next;
            delete tempMin;
        }

        delete temp;
        return valToReturn;
    }

    int Minimum() {
        if (this->min == NULL) {
            return -1;
        }
        return this->min->data;
    }
};



int main() {
    srand(time(0));
    Stack taskList;
    for (int i = 0; i < 10; i++) {
        int item = rand() % 10000;
        taskList.Push(item);

        printf("Pushing %d to stack.\n", item);
    }

    std::string a, min;
    int res1 = 0;
    a = min = "";
    for (int i=0; i< 10; i++) {
        if (res1 != -1) {
            res1 = taskList.Pop();
            a += std::to_string(res1) + ",";
        }        min += std::to_string(taskList.Minimum()) + ",";
        if (res1 == -1){
            break;
        }
    }
    printf("Stack 1: %s.\n", a.c_str());
    printf("Minimums: %s.\n", min.c_str());



    return 0;
}
