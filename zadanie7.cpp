
#include <iostream>

class Macierz2D {       // The class
public:
    Macierz2D(); //Default constructor
    Macierz2D(int* paraml); //Main constructor
    void setVal(int row, int col, int val); //Method to set the val of [i,j]th-entry
    void printMatrix(); //Method to display the matrix
    

private:
    int row, col;
    float** matrix;

    //allocate the array

};
//Default constructor
Macierz2D::Macierz2D(){
    Macierz2D(0);
}

//Main construcor
Macierz2D::Macierz2D(int param)
{   
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            *(*(matrix + i) + j) = 0;
        }
    }
}

int main()
{
    std::cout << "Hello Wddorld!\n";
}
