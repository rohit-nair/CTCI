#include <iostream>
#include <vector>

void printArray(int **array, int rows, int columns)
{
    int * row;
    for (int i=0; i<rows; i++)
    {
        row = array[i];
        for (int j=0; j<columns; j++)
        {
            printf("%i \t", *row++);
        }
        printf("\n");
    }
}

void SetToZero(int **array, int rows, int columns)
{
    std::vector<bool> rowFlags (rows, false);
    std::vector<bool> colFlags (columns, false);
    int* row;
    
    for (int i=0; i<rows; i++)
    {
        row = array[i];
        for (int j=0; j<columns; j++)
        {
            if (*row++ == 0)
            {
                colFlags[j] = true;
                rowFlags[i] = true;
            }
        }
    }
    
    for (int i=0; i<rows; i++)
    {
        row = array[i];
        for (int j=0; j<columns; j++)
        {
            if (rowFlags[i] || colFlags[j])
            {
                *row = 0;
            }
            row++;
        }
    }
    
    printArray(array, rows, columns);
}

int main()
{
    int **array;
    int rows = 0;
    int columns = 0;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;

    std::cout << "Enter number of columns: ";
    std::cin >> columns;

    array = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[columns];
        
        for (int j = 0; j < columns; j++)
        {
            array[i][j] = rand() % 10;
        }
    }

    printArray(array, rows, columns);
    
    printf("\n");
    
    SetToZero(array, rows, columns);
    
    for(int i = 0; i < rows; ++i){
        delete array[i];//deletes an inner array of integer;
    }
    delete array;
    
    return 0;
}
