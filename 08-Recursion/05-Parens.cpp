#include <iostream>


void printParen(int l, int r, char[6] str, int count) {
    if (l < 0 || r < l) return; // invalid state
    if (l == 0 && r == 0) {
        printf(str); // found one, so print it
    else {
        if (l > 0) { // try a left paren, if there are some available
            str[count] = ‘(‘;
            printPar(l - 1, r, str, count + 1);
        }
        if (r > l) { // try a right paren, if there’s a matching left
            str[count] = ‘)’;
            printPar(l, r - 1, str, count + 1);
        }
    }
}


int main() {
    int n = 3;
    char str[6];
    printParen(n, n, str, 0);
    return 0;
}
