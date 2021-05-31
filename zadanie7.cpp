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
#include <initializer_list>
//dzien Dobry, ¿yczê mi³ego Dnia.
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
