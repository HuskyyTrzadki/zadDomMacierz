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
    Macierz2D(int param); //Main constructor
    Macierz2D(**matrix);
    void fillMatrixWith(int x);
    void setVal(int row, int col, int val); //Method to set the val of [i,j]th-entry
    void printMatrix(); //Method to display the matrix
    

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

//Main construcor
Macierz2D::Macierz2D(int param)
{   
    m_dane = new float* [nRows];
    for (int i = 0; i < nCols; i++) {
        m_dane[i] = new float[nCols];
    }

    fillMatrixWith(param);
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
    std::cout << "Hello Wddorld!\n";
}
