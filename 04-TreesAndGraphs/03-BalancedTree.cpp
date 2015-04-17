#include <iostream>

int NUMBER_ARRAY_ITEMS = 7;

class Node
{
    private:
    
public:
    int value;
    Node* left;
    Node* right;
        Node(int val)
        {
            value = val;
        }
};

class Queue
{
    class Item
    {
    public:
        int value;
        Item* next;
        Item(int val)
        {
            value = val;
        }
        ~Item()
        {
            next = NULL;
        }
    };
    
    
    Item* head;
    Item* last;
    
public:
    Queue()
    {
        head = NULL;
        last = NULL;
    }
    ~Queue()
    {
        head = NULL;
        last = NULL;
    }
    void Enqueue(int val)
    {
        Item* item = new Item(val);
        if (head == NULL)
        {
            head = item;
            last = item;
        }
        last->next = item;
        last = item;
    }
    
    int Dequeue()
    {
        if (head == NULL)
            return -1;
        Item* toReturn = head;
        head = toReturn->next;
        int valToReturn = toReturn->value;
        delete toReturn;
        return valToReturn;
    }
    
    int Peek()
    {
        if (head == NULL)
            return -1;
        return head->value;
    }
};

void addBF(Node* node, Queue* q)
{
    if (node == NULL)
        return;
    
    q->Enqueue(node->value);
    addBF(node->left, q);
    addBF(node->right, q);
}
void Print(Node* node)
{
    Queue* q = new Queue();
    addBF(node, q);
    
    while (q->Peek() != -1) {
        std::cout << q->Dequeue() << ",";
    }
}

void PrintAll(int items[]) {
    for (int i=0; i<NUMBER_ARRAY_ITEMS; i++)
        std::cout << items[i] << ",";
    std::cout << '\n';
}

void Quicksort(int items[], int start, int end) {
    if (start >= end)
        return;
    
    int pivot = (start+end)/2;
    int pivotValue = items[pivot];
    
    int i,j;
    i = start;
    j = end;
    
    while (i<j) {
        while (items[i] < pivotValue)
            i++;
        
        while (items[j] > pivotValue)
            j--;
        
        int temp = items[i];
        items[i] = items[j];
        items[j] = temp;
        
        i++; j--;
    }
    Quicksort(items, start, j);
    Quicksort(items, i, end);
}

Node* CreateBalancedTree(int items[], int left, int right)
{
    if (left > right)
        return NULL;
    
    int mid, midValue;
    mid = (left + right)/2;
    midValue = items[mid];
    
    Node* n = new Node(midValue);
    n->left = CreateBalancedTree(items, left, mid-1);
    n->right = CreateBalancedTree(items, mid+1, right);
    
    return n;
}

int main() {
    srand(time(0));
    int items[NUMBER_ARRAY_ITEMS];
    for (int i = 0; i<NUMBER_ARRAY_ITEMS; i++) {
        items[i] = rand() % 50;
    }
    
    Quicksort(items, 0, NUMBER_ARRAY_ITEMS-1);
    PrintAll(items);
    Node* tree = CreateBalancedTree(items, 0, NUMBER_ARRAY_ITEMS);
    
    Print(tree);
    
    return 0;
}
