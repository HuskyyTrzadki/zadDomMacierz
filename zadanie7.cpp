//S
//Prosz� stworzy� w jednym pliku klas� Macierz2D, kt�ra b�dzie mog�a przechowywa� macierze kwadratowe o rozmiarach 3 na 3 z elementami typu float(float** m_dane).Ponadto w klasie nale�y :
//Stworzy� konstruktory :
//-Bez parametr�w.
//- Z jednym parametrem typu float.
//- Przyjmuj�cy jako argument tablic� dwuwymiarow� element�w typu float.
//- Przyjmuj�cy jako argument list� inicjuj�c�.
//Przeci��y� operatory :
//-przypisania =
//-dodawania +
//-dodawania z przypisaniem +=
//-odejmowania -
//-odejmowania z przypisaniem -=
//-Post i pre zar�wno inkrementacji jak i dekrementacji++ --
//- mno�enia * (przez liczb� ca�kowit�)
//- mno�enia z przypisaniem *= (przez liczb� ca�kowit�)
//- mno�enia * (macierzy)
//-mno�enia z przypisaniem *= (macierzy)
//-operatory strumieniowego wej�cia i wyj�cia >> << (wy�wietlanie powinno by� sformatowane)
//Doda� metody realizuj�ce :
//-Ustawianie i zwracanie konkretnych element�w macierzy.
//- Stworzenie macierzy jednostkowej.
//- Transponowanie macierzy.
//
//W przypadku tych operator�w, kt�re mog� by� przeci��one zar�wno poza jak i w klasie mog� Pa�stwo wybra� dowolnie.
//Prosz� r�wnie� zaimplementowa� w main tablic� przechowuj�c� trzy r�ne macierze typu Macierz2D.Prosz� posortowa� t� tablic� za pomoc� sortowania z biblioteki standardowej.
//W main prosz� umie�ci� przyk�adowe mno�enie macierzy ��cznie z wypisaniem operand�w i wyniku.
//Nale�y zadba� o poprawn� obs�ug� obiekt�w klasy Macierz2D.
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
