//https://github.com/HuskyyTrzadki/zadanie7
#include <iostream>
#include <initializer_list>
#include <vector>
//dzien Dobry, ¿yczê mi³ego Dnia.
template <class typ = int, int wymiar = 3>
class Macierz2D {
private:
    typ** m_dane;
    wymiar nRows = wymiar;
    wymiar nCols = wymiar;
public:
    //pierwzy to typ, drugi to rozmiar 
    //konstrukcja templatkowa, ze nie ma kodu wczesniej i kompilator go tworzy
    Macierz2D(); //Default constructor
    Macierz2D(typ); //Main constructor
    Macierz2D(typ**);
    Macierz2D(typ&);//adres zmiennje
    Macierz2D(const Macierz2D&);
    Macierz2D(typ, typ, typ, typ, typ, typ, typ, typ, typ);
    Macierz2D(typ, typ, typ, typ, typ, typ, typ, typ, typ, typ, typ, typ, typ, typ, typ, typ);
    Macierz2D(const std::initializer_list <float>& newData);
    ~Macierz2D();
    void setNumberAt(int, int, typ);
    int getNumberAt(int, int);
    void makeMatrixIdentity();
    float getDet();
    void TransposeMatrix();



    void fillMatrixWith(typ);
    void printMatrix(); //Method to display the matrix

    Macierz2D operator/(typ liczba)
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
    Macierz2D operator-(typ liczba)
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

    Macierz2D operator*(typ liczba)
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
    Macierz2D operator+(typ liczba)
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
        float res[nRows][y] = { 0 };
        for (int i = 0; i < nRows; i++)
        {
            for (int g = 0; g < nCols; g++)
            {
                for (int k = 0; k < nRows; k++)
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


        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                for (int k = 0; k < nRows; k++)
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
template <class typ>
Macierz2D<typ>::Macierz2D() {
    //stworzylem tablice wskaznikow
    m_dane = new typ * [nRows];
    for (int i = 0; i < nCols; i++) {
        m_dane[i] = new typ[nCols];
    }

    fillMatrixWith(0);

}

std::ostream& operator<<(std::ostream& output, const Macierz2D& macierz)
{

    for (int i = 0; i < macierz.nRows; i++)
    {
        for (int j = 0; j < macierz.nCols; j++)
        {
            output << macierz.m_dane[i][j] << " ";
        }
        output << std::endl;
    }

    return output;
}
std::istream& operator>>(std::istream& input, const  Macierz2D& macierz)
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
template <class typ = int>
Macierz2D<typ>::Macierz2D(typ a, typ b, typ c, typ  d, typ e, typ f, typ g, typ h, typ i) {
    m_dane = new typ * [nRows];
    for (int i = 0; i < nCols; i++) {
        m_dane[i] = new typ[nCols];
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
template <class typ = int>
Macierz2D<typ>::Macierz2D(typ a, typ b, typ c, typ  d, typ e, typ f, typ g, typ h, typ i, typ j, typ k, typ l, typ m, typ n, typ o, typ p) {
    m_dane = new typ * [nRows];
    for (int i = 0; i < nCols; i++) {
        m_dane[i] = new typ[nCols];
    }
    m_dane[0][0] = a;
    m_dane[0][1] = b;
    m_dane[0][2] = c;
    m_dane[0][3] = d;
    m_dane[1][0] = e;
    m_dane[1][1] = f;
    m_dane[1][2] = g;
    m_dane[1][3] = h;
    m_dane[2][0] = i;
    m_dane[2][1] = j;
    m_dane[2][2] = k;
    m_dane[2][3] = l;
    m_dane[3][0] = m;
    m_dane[3][1] = n;
    m_dane[3][2] = o;
    m_dane[3][3] = p;



}

Macierz2D::~Macierz2D() {
    for (int i = 0; i < nRows; i++)
    {

        delete[] m_dane[i];
    }
    delete[] m_dane;
}
//lista inicjalizacyjna
template<class typ = int>
Macierz2D<typ>::Macierz2D(const std::initializer_list <typ>& newData)
{
    m_dane = new typ * [nRows];

    for (int i = 0; i < nRows; i++)
    {
        m_dane[i] = new typ[nRows];
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

        typ temp = element;

        m_dane[i][j] = temp;

        j++;
    }
}

Macierz2D::Macierz2D(const Macierz2D& macierz)
{
    Macierz2D* nowa = new Macierz2D(0);
    for (int i = 0; i < nRows; i++)
    {
        for (int g = 0; g < nCols; g++)
        {
            nowa->m_dane[i][g] = macierz.m_dane[i][g];
        }
    }
}
template<class typ = int>
Macierz2D<typ>::Macierz2D(typ param)
{
    m_dane = new typ * [nRows];
    for (int i = 0; i < nCols; i++) {
        m_dane[i] = new typ[nCols];
    }

    fillMatrixWith(param);
}
template<class typ = int>
Macierz2D<typ>::Macierz2D(typ** param)
{
    m_dane = new typ * [nRows];
    for (int i = 0; i < nCols; i++) {
        m_dane[i] = new typ[nCols];
    }
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            m_dane[i][j] = param[i][j];
        }
    }


}
//template class cpp
template<class typ = int>
Macierz2D<typ>::getDet() {
    typ det;
    if (nRows == 3) {
        det = m_dane[0][2] * m_dane[1][1] * m_dane[2][0] + m_dane[0][0] * m_dane[1][2] * m_dane[2][1] + m_dane[0][1] * m_dane[1][0] * m_dane[2][2];
    }
    if (nRows == 4) {
        int det = 0;
        int submatrix[10][10];
        if (n == 2)
            return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
        else {
            for (int x = 0; x < 4; x++) {
                int subi = 0;
                for (int i = 1; i < 4; i++) {
                    int subj = 0;
                    for (int j = 0; j < 4; j++) {
                        if (j == x)
                            continue;
                        submatrix[subi][subj] = matrix[i][j];
                        subj++;
                    }
                    subi++;
                }
                det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
            }
        }
        return det;
    }

    return det;
}
void Macierz2D::printMatrix() {
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            std::cout << m_dane[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

void Macierz2D::setNumberAt(int r, int c, typ num)
{
    m_dane[r][c] = num;
}
int Macierz2D::getNumberAt(int r, int c)
{
    return m_dane[r][c];
}
template<class typ = int>
void Macierz2D<typ>::fillMatrixWith(typ x) {
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
    for (int i = 0; i < nCols; i++) {
        for (int j = 0; j < NRows; j++) {
            if (m_dane[i] > m_dane[j]) {
                int temp;
                temp = m_dane[i][j];
                m_dane[i][j] = m_dane[j][i];
                m_dane[j][i] = temp;
            }
        }
    }
}
int main()
{
    Macierz2D* x = new<int> Macierz2D(5, 3, 1, 4, 2, 5, 4, 6, 2, 2, 5, 4, 7, 7, 5, 3);
    Macierz2D* y = new<float> Macierz2D(5, 3, 1.3, 8.8, 7, 3.4, 2.1, 6.5, 2.2, 2, 1.8, 4, 1, 7, 5, 3);
    Macierz2D* z = new<float> Macierz2D(0);
    std::cout << "przykladowe mnozenie macierzy\n";
    *z = *x * *y;
    std::cout << *z;
    //niestety niezbyt rozumiem o co chodzi z fragmentem polecenia o sortowaniu.



}
