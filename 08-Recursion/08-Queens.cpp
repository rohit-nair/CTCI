#include <iostream>
#include <vector>

class Point {
public:
    int X = 0;
    int Y = 0;
    
    Point() { }
    
    Point(int x, int y){
        X = x;
        Y = y;
    }
    
    void Print() {
        std::cout << "(" << std::to_string(X) << "," << std::to_string(Y) << "),";
    }
};

void Print(Point queens[8]) {
    for (int i=0; i<8; i++)
        queens[i].Print();
    std::cout << "\n";
}

void Setup(Point* queens, bool* x, bool* y) {
    for (int i=0; i<8; i++) {
        queens = new Point(0, i);
        queens++;
        *x++ = false;
        *y++ = false;
    }
}

void PerfSeperation(bool xArray[8], bool yArray[8], Point queens[8], int queen) {
    for (int i=0; i<8; i++){
        if (!xArray[i]) {
            bool temp[8];
            std::copy(xArray, xArray+8, temp);
            
            queens[queen].X = i;
            temp[i] = true;
            if (queen < 7)
                PerfSeperation(temp, yArray, queens, queen+1);
            else
                Print(queens);
        }
    }
}


int main() {
    bool xArray[8];
    bool yArray[8];
    Point queens[8];
    
    Setup(&queens[0], &xArray[0], &yArray[0]);
    PerfSeperation(xArray, yArray, queens, 0);
    return 0;
}
