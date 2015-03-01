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
			Node* current = this->head;
			if (current == NULL) {
				this->head = new Node(d);
                return;
			}
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = new Node(d);
		}

		void printAll() {
			Node* current = this->head;
			while (current != NULL) {
				printf("%d,", current->data);
                current = current->next;
			}
		}

		void removeNode(Node** nodeToRemove) {
            printf("\nNode to be removed:%d\n", (*nodeToRemove)->data);
			Node* temp = (*nodeToRemove)->next;
            if (temp != NULL) {
                (*nodeToRemove)->data = temp->data;
                (*nodeToRemove)->next = temp->next;
            }
            else {
                printf("Last node cannot be removed unless the linked list is known.");
            }
            temp = NULL;
			delete temp;
		}
};


int main() {
	int listItemCount = 15;
	LinkedList* ls = new LinkedList();

    srand(time(0));
	for (int i = 0; i < listItemCount; i++) {
		ls->addToEnd(rand() % 25);
	}
    
    std::cout << "Linked list elements:\n";
	ls->printAll();
	int arbIdx = rand() % listItemCount;
	Node* nodeToRemove = ls->head;
	for (int i=0; i < listItemCount - 1; i++) {
		nodeToRemove = nodeToRemove->next;
	}

    ls->removeNode(&nodeToRemove);
    std::cout << "\nLinked list elements post node removal:\n";
    ls->printAll();
    
	return 0;
}

