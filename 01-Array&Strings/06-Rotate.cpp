#include <iostream>


void printMatrix(double matrix[][4], int rows)
{
    int i = 0;
    int j = 0;
    int columns = sizeof(matrix[0])/sizeof(matrix[0][0]);
    
    while (i < rows) {
        j = 0;
        while (j < columns) {
            printf("%.2f \t", matrix[i][j]);
            ++j;
        }
        std::cout << '\n';
        ++i;
    }
    std::cout << "\n\n";
}

void rotate(double img[][4], int rows)
{
    int columns = sizeof(img[0])/sizeof(img[0][0]);
    int i = 0;
    int j = 0;
    double tempRight = 0ULL;
    while (i < rows / 2)
    {
        j = i;
        while (j < columns - i - 1) {
            tempRight = img[j][columns - i - 1];
            img[j][columns - i - 1] = img[i][j];
            img[i][j] = img[rows - j - 1][i];
            img[rows - j - 1][i] = img[rows - i -1][columns - j - 1];
            img[rows - i -1][columns - j - 1] = tempRight;
            ++j;
        }
        ++i;
    }
    printMatrix(img, rows);
}

//int main()
//{
//    double img[4][4] = {0};
//    int i = 0;
//    int j = 0;
//    int counter = 0;
//    int rows = sizeof(img)/sizeof(img[0]);
//    int columns = sizeof(img[0])/sizeof(img[0][0]);
//    while (i < rows)
//    {
//        j = 0;
//        while (j < columns)
//        {
//            double foo = rand() % 100 + 1;
//            img[i][j] = counter; //foo/100;
//            ++j;
//            ++counter;
//        }
//        ++i;
//    }
//    printMatrix(img, rows);
//    rotate(img, rows);
//    return 0;
//}
