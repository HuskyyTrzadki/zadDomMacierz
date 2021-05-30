//S
//Proszê stworzyæ w jednym pliku klasê Macierz2D, która bêdzie mog³a przechowywaæ macierze kwadratowe o rozmiarach 3 na 3 z elementami typu float(float** m_dane).Ponadto w klasie nale¿y :
//Stworzyæ konstruktory :
//-Bez parametrów.
//- Z jednym parametrem typu float.
//- Przyjmuj¹cy jako argument tablicê dwuwymiarow¹ elementów typu float.
//- Przyjmuj¹cy jako argument listê inicjuj¹c¹.
//Przeci¹¿yæ operatory :
//-przypisania =
//-dodawania +
//-dodawania z przypisaniem +=
//-odejmowania -
//-odejmowania z przypisaniem -=
//-Post i pre zarówno inkrementacji jak i dekrementacji++ --
//- mno¿enia * (przez liczbê ca³kowit¹)
//- mno¿enia z przypisaniem *= (przez liczbê ca³kowit¹)
//- mno¿enia * (macierzy)
//-mno¿enia z przypisaniem *= (macierzy)
//-operatory strumieniowego wejœcia i wyjœcia >> << (wyœwietlanie powinno byæ sformatowane)
//Dodaæ metody realizuj¹ce :
//-Ustawianie i zwracanie konkretnych elementów macierzy.
//- Stworzenie macierzy jednostkowej.
//- Transponowanie macierzy.
//
//W przypadku tych operatorów, które mog¹ byæ przeci¹¿one zarówno poza jak i w klasie mog¹ Pañstwo wybraæ dowolnie.
//Proszê równie¿ zaimplementowaæ w main tablicê przechowuj¹c¹ trzy ró¿ne macierze typu Macierz2D.Proszê posortowaæ tê tablicê za pomoc¹ sortowania z biblioteki standardowej.
//W main proszê umieœciæ przyk³adowe mno¿enie macierzy ³¹cznie z wypisaniem operandów i wyniku.
//Nale¿y zadbaæ o poprawn¹ obs³ugê obiektów klasy Macierz2D.
#include <iostream>


class Macierz2D {       // The class
public:
    Macierz2D(); //Default constructor
    Macierz2D(int); //Main constructor
    Macierz2D(float**);
    Macierz2D(float&);//adres zmiennje
    Macierz2D(int, int, int, int, int, int, int, int, int);
    void fillMatrixWith(int);
    void setVal(int row, int col, int val); //Method to set the val of [i,j]th-entry
    void printMatrix(); //Method to display the matrix
 
    Macierz2D operator/(int liczba)
    {
        if (liczba != 0) {
            for (int i = 0; i < nRows; i++)
            {
                for (int j = 0; j < nCols; j++)
                {
                    m_dane[i][j] = (m_dane[i][j]) / liczba;
                }
            }
            return *this;
        }
        return 0;

    }
    Macierz2D operator-(int liczba)
    {
        if (liczba != 0) {
            for (int i = 0; i < nRows; i++)
            {
                for (int j = 0; j < nCols; j++)
                {
                    m_dane[i][j] = (m_dane[i][j]) - liczba;
                }
            }
            return *this;
        }

    }
    Macierz2D operator+(int liczba)
    {
        if (liczba != 0) {
            for (int i = 0; i < nRows; i++)
            {
                for (int j = 0; j < nCols; j++)
                {
                    m_dane[i][j] = (m_dane[i][j]) + liczba;
                }
            }
            return *this;
        }

    }
    Macierz2D operator*(int liczba)
    {
            for (int i = 0; i < nRows; i++)
            {
                for (int j = 0; j < nCols; j++)
                {
                    m_dane[i][j] = (m_dane[i][j]) * liczba;
                }
            }
            return *this;
       

    }

private:
    float** m_dane;
    int nRows = 3;
    int nCols = 3;
    

    //allocate the array

};
//Default constructor
Macierz2D::Macierz2D(){
    //stworzylem tablice wskaznikow
    m_dane = new float*[nRows];
    for (int i = 0; i < nCols; i++) {
        m_dane[i] = new float[nCols];
    }

    fillMatrixWith(0);

}
//to dla mnie
Macierz2D::Macierz2D(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    m_dane = new float* [nRows];
    for (int i = 0; i < nCols; i++) {
        m_dane[i] = new float[nCols];
    }
    m_dane[0][0] = a;
    m_dane[0][1] = b;
    m_dane[0][2] = c;
    m_dane[1][0] = d;
    m_dane[1][1] = e;
    m_dane[1][2] = f;
    m_dane[2][0] = g;
    m_dane[2][1] = h;
    m_dane[2][2] = i;
   

}




Macierz2D::Macierz2D(int param)
{
    m_dane = new float* [nRows];
    for (int i = 0; i < nCols; i++) {
        m_dane[i] = new float[nCols];
    }

    fillMatrixWith(param);
}
Macierz2D::Macierz2D(float** param)
{
    m_dane = new float* [nRows];
    for (int i = 0; i < nCols; i++) {
        m_dane[i] = new float[nCols];
    }
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            m_dane[i][j] = param[i][j];
        }
    }

    
}
void Macierz2D::printMatrix() {
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            std::cout << m_dane[i][j]+" ";
        }
    }

}
void Macierz2D::fillMatrixWith(int x) {
    for (int i = 0; i < nRows; i++) {
        for (int w = 0; w < nCols; w++) {
            m_dane[i][w] = x;
        
        }
    
    }

}
int main()
{
    Macierz2D* x = new Macierz2D(1, 2, 3, 4, 5, 6, 7, 8, 9);
    *x + 4;
    x->printMatrix();
}
