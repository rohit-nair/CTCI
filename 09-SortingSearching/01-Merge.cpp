#include <iostream>
#include <stdio>

const int MAX_SIZE = 100;

void Print(int* start, int count){
    
}

int BinarySearch(int A[MAX_SIZE], int b, int start, int end) {
    
}

void Merge(int A[MAX_SIZE], int B[10]) {
    int currentPos = 19, lesserAPos = 9;
    for (int i=9; i>=0; i--) {
        // Find index of element in A less than current B element
        // Move all elements to the right since previous move
        // Insert B's element in right position
        lesserAPos = BinarySearch(A, B[i], 0, lesserAPos);
    }
}

int main() {
    int A[MAX_SIZE];
    int B[10];

    for (int i=0; i<10; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    Print(&A, 10);
    Print(&B, 10);

    Merge(A, B);

    return 0;
}
