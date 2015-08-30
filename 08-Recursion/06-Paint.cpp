#include <iostream>

const int SIZE = 10;
static char Bitmap[SIZE][SIZE];

void Print() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << Bitmap[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void PaintFill(int i, int j, char color, char repColor) {
    if (i < 0 || j < 0 || i >= SIZE || j >= SIZE) {
        return;
    }
    
    if (Bitmap[i][j] == color) {
        Bitmap[i][j] = repColor;
        PaintFill(i-1, j, color, repColor);     //Left
        PaintFill(i+1, j, color, repColor);     //Right
        PaintFill(i-1, j-1, color, repColor);   //TopLeft
        PaintFill(i-1, j+1, color, repColor);   //BottomLeft
        PaintFill(i, j-1, color, repColor);     //Top
        PaintFill(i, j+1, color, repColor);     //Bottom
        PaintFill(i+1, j-1, color, repColor);     //TopRight
        PaintFill(i+1, j+1, color, repColor);     //BottomRight
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            char c = 65 + rand() % 5;

            std::cout << c << "\t";
            Bitmap[i][j] = c;
        }
        std::cout << "\n";
    }
    
    char color = ' ';
    char repColor = ' ';
    int pointX = 0, pointY = 0;
    
    while (pointX >= 0 && pointX < SIZE) {
        std::cout << "Enter color to replace. \n";
        std::cin >> color;
        
        std::cout << "Enter replacement color. \n";
        std::cin >> repColor;
        
        std::cout << "Enter X, Y coordinates. \n";
        std::cin >> pointX >> pointY;
        
        PaintFill(pointX, pointY, color, repColor);
        Print();
    }
    
    
    return 0;
}
