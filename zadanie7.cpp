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
#include <initializer_list>
//dzien Dobry, �ycz� mi�ego Dnia.
class Macierz2D {
private:
    float** m_dane;
    int nRows = 3;
    int nCols = 3;
public:
    Macierz2D(); //Default constructor
    Macierz2D(int); //Main constructor
    Macierz2D(float**);
    Macierz2D(float&);//adres zmiennje
    Macierz2D(const Macierz2D&);
    Macierz2D(float,float,float,float,float,float,float,float,float);
    Macierz2D(const std::initializer_list <float>& newData);
    ~Macierz2D();
    void setNumberAt(int, int, float);
    int getNumberAt(int, int);
    void makeMatrixIdentity();
    float getDet();
    void TransposeMatrix();
    

    
    void fillMatrixWith(float);
    void printMatrix(); //Method to display the matrix
 
    Macierz2D operator/(float liczba)
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
    Macierz2D operator-(float liczba)
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

    Macierz2D operator*(float liczba)
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
    Macierz2D operator+(float liczba)
    {
        for (int i = 0; i < nRows; i++)
        {
            for (int g = 0; g < nCols; g++)
            {
                m_dane[i][g] = (m_dane[i][g]) * liczba;
            }
        }
        return *this;


    }
   /* Macierz2D operator +(Macierz2D macierz) {
        return Macierz2D(macierz.m_dane[0][0] + m_dane[0][0], macierz.m_dane[0][1] + m_dane[0][1], macierz.m_dane[0][2] + m_dane[0][2],
            macierz.m_dane[1][0] + m_dane[1][0], macierz.m_dane[1][1] + m_dane[1][1], macierz.m_dane[1][2] + m_dane[1][2],
            macierz.m_dane[2][0] + m_dane[2][0], macierz.m_dane[2][1] + m_dane[2][1], macierz.m_dane[2][2] + m_dane[2][2]);
    }*/
    Macierz2D& operator =(const Macierz2D macierz)
    {
        for (int i = 0; i < nRows; i++)
        {
            for (int g = 0; g < nCols; g++)
            {
                this->m_dane[i][g] = macierz.m_dane[i][g];
            }




        }
        return *this;
    }

    Macierz2D operator+=(const Macierz2D& x) {
        for (int i = 0; i < nRows; i++)
        {
            for (int g = 0; g < nCols; g++)
            {
                m_dane[i][g] += x.m_dane[i][g];
            }

        }
        return *this;
    }
    Macierz2D operator-=(const Macierz2D& x) {
        for (int i = 0; i < nRows; i++)
        {
            for (int g = 0; g < nCols; g++)
            {
                    m_dane[i][g] -= x.m_dane[i][g];
            }
        }
        return *this;
    }

    Macierz2D operator++(int) //post
    {
        Macierz2D przed = *this;

        for (int i = 0; i < nRows; i++)
        {
            for (int g = 0; g < nCols; g++)
            {
                m_dane[i][g] += 1;
            }
        }

        return przed;
    }
    Macierz2D operator--(int)
    {
        Macierz2D przed = *this;

        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                m_dane[i][j] -= 1;
            }
        }

        return przed;
    }
    Macierz2D operator++() //post
    {

        for (int i = 0; i < nRows; i++)
        {
            for (int g = 0; g < nCols; g++)
            {
                m_dane[i][g] += 1;
            }
        }

        return *this;
    }
    Macierz2D operator--()
    {
        

        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                m_dane[i][j] -= 1;
            }
        }

        return *this;
    }
    Macierz2D operator*(const Macierz2D& macierz)
    {
        float res[3][3] = {0};
        for (int i = 0; i < nRows; i++)
        {
            for (int g = 0; g < nCols; g++)
            {
                for (int k = 0; k < 3; k++)
                {
                    res[i][g] += m_dane[i][k] * m_dane[k][g];
                }
            }
        }

        return Macierz2D(res[0][0], res[0][1], res[0][2],
            res[1][0], res[1][1], res[1][2],
            res[2][0], res[2][1], res[2][2]);
    }
    Macierz2D& operator *=(const Macierz2D& m)
    {
        this->fillMatrixWith(0);

        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    this->m_dane[i][j] += this->m_dane[i][k] * m.m_dane[k][j];
                }
            }
        }

        return *this;
    }
  


    friend std::istream& operator >>(std::istream& input, const Macierz2D& macierz);
    friend std::ostream& operator <<(std::ostream& output, const Macierz2D& macierz);
    

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

std::ostream& operator<<(std::ostream& output,const Macierz2D& macierz)
{  
   
    for (int i = 0; i < macierz.nRows; i++)
    {
        for (int j = 0; j < macierz.nCols; j++)
        {
            output << macierz.m_dane[i][j] << " ";
        }
        output<< std::endl;
    }

    return output;
}
std::istream& operator>>(std::istream& input,const  Macierz2D& macierz)
{
    for (int i = 0; i < macierz.nRows; i++)
    {
        for (int j = 0; j < macierz.nCols; j++)
        {
            input >> macierz.m_dane[i][j];
        }
        
    }

    return input;
}
//to dla mnie
Macierz2D::Macierz2D(float a, float b, float c, float d, float e, float f, float g, float h, float i) {
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
Macierz2D::~Macierz2D() {
        for (int i = 0; i < nRows; i++)
        {
           
            
            delete[] m_dane[i];
        }
        delete[] m_dane;
}
//lista inicjalizacyjna
Macierz2D::Macierz2D(const std::initializer_list <float>& newData)
{
    m_dane = new float* [nRows];

    for (int i = 0; i < nRows; i++)
    {
        m_dane[i] = new float[nRows];
    }

    int i = 0;
    int j = 0;

    for (auto element : newData)
    {
        if (j == 3)
        {
            j = 0;
            i++;
        }

        float temp = element;

        m_dane[i][j] = temp;

        j++;
    }
}

Macierz2D::Macierz2D(const Macierz2D& macierz)
{
    Macierz2D *nowa = new Macierz2D(0);
    for (int i = 0; i < nRows; i++)
    {
        for (int g = 0; g < nCols; g++)
        {
            nowa->m_dane[i][g] = macierz.m_dane[i][g];
        }
    }
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
float Macierz2D::getDet(){
   
    float det = m_dane[0][2] * m_dane[1][1] * m_dane[2][0] + m_dane[0][0] * m_dane[1][2] * m_dane[2][1] + m_dane[0][1] * m_dane[1][0] * m_dane[2][2];
    return det;
}
void Macierz2D::printMatrix() {
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            std::cout << m_dane[i][j]<<" ";
        }
        std::cout <<std:: endl;
    }

}

void Macierz2D::setNumberAt(int r, int c, float num)
{
    m_dane[r][c] = num;
}
int Macierz2D::getNumberAt(int r, int c)
{
    return m_dane[r][c];
}
void Macierz2D::fillMatrixWith(float x) {
    for (int i = 0; i < nRows; i++) {
        for (int w = 0; w < nCols; w++) {
            m_dane[i][w] = x;
        
        }
    
    }

}
void Macierz2D::makeMatrixIdentity()
{
    fillMatrixWith(0);
    this->m_dane[0][0] = 1;
    this->m_dane[1][1] = 1;
    this->m_dane[2][2] = 1;
}
void Macierz2D::TransposeMatrix()
{
    //zamiana jak z liczbami //0110
    float temp = m_dane[0][1];
    m_dane[0][1] = m_dane[1][0];
    m_dane[1][0] = temp;

    temp = m_dane[2][0];
    m_dane[2][0] = m_dane[0][2];
    m_dane[0][2] = temp;

    temp = m_dane[2][1];
    m_dane[2][1] = m_dane[1][2];
    m_dane[1][2] = temp;
}
int main()
{
    Macierz2D* x = new Macierz2D(1, 2, 3, 4, 5, 6, 7, 8, 9);
    Macierz2D* y = new Macierz2D(5,6,3,2,1,4,6,8,9);
    Macierz2D* z = new Macierz2D(0);
    std::cout << "przykladowe mnozenie macierzy\n";
    *z=*x * *y;
    std::cout << *z;
    //niestety niezbyt rozumiem o co chodzi z fragmentem polecenia o sortowaniu.


   
}
