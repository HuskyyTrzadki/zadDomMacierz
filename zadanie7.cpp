//https://github.com/HuskyyTrzadki/zadanie7
#include <iostream>
#include <initializer_list>
#include <vector>
//dzien Dobry, ¿yczê mi³ego Dnia.
template <class typ = int, int wymiar=3>
class Macierz2D {
private:
    typ** m_dane;
    int nRows = wymiar;
    int nCols = wymiar;
public:
 

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
        typ res[wymiar][wymiar] = { 0 };
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
    Macierz2D() {
        //stworzylem tablice wskaznikow
        m_dane = new typ * [nRows];
        for (int i = 0; i < nCols; i++) {
            m_dane[i] = new typ[nCols];
        }

        fillMatrixWith(0);

    }
    Macierz2D(typ a, typ b, typ c, typ  d, typ e, typ f, typ g, typ h, typ i) {
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
    Macierz2D(typ a, typ b, typ c, typ  d, typ e, typ f, typ g, typ h, typ i, typ j, typ k, typ l, typ m, typ n, typ o, typ p) {
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
    ~Macierz2D() {
        for (int i = 0; i < nRows; i++)
        {

            delete[] m_dane[i];
        }
        delete[] m_dane;
    }
    Macierz2D(const std::initializer_list <typ>& newData)
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
    Macierz2D(const Macierz2D& macierz)
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
    float getDet() {
        typ det;
        if (nRows == 3) {
            det = m_dane[0][2] * m_dane[1][1] * m_dane[2][0] + m_dane[0][0] * m_dane[1][2] * m_dane[2][1] + m_dane[0][1] * m_dane[1][0] * m_dane[2][2];
        }
        if (nRows == 4) {
            int det = 0;
            int submatrix[10][10];
            if (nRows == 2)
                return ((m_dane[0][0] * m_dane[1][1]) - (m_dane[1][0] * m_dane[0][1]));
            else {
                for (int x = 0; x < 4; x++) {
                    int subi = 0;
                    for (int i = 1; i < 4; i++) {
                        int subj = 0;
                        for (int j = 0; j < 4; j++) {
                            if (j == x)
                                continue;
                            submatrix[subi][subj] = m_dane[i][j];
                            subj++;
                        }
                        subi++;
                    }
                    det = det + (pow(-1, x) * m_dane[0][x] * getDet(submatrix, nRows - 1));
                }
            }
            return det;
        }

        return det;
    }
    Macierz2D(typ param)
    {
        m_dane = new typ * [nRows];
        for (int i = 0; i < nCols; i++) {
            m_dane[i] = new typ[nCols];
        }

        fillMatrixWith(param);
    }
    Macierz2D(int** param)
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
    typ setNumberAt(int r, int c, typ num)
    {
        m_dane[r][c] = num;
    }
    typ getNumberAt(int r, int c)
    {
        return m_dane[r][c];
    }
    void printMatrix() {
        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                std::cout << m_dane[i][j] << " ";
            }
            std::cout << std::endl;
        }

    }
    void fillMatrixWith(typ x) {
        for (int i = 0; i < nRows; i++) {
            for (int w = 0; w < nCols; w++) {
                m_dane[i][w] = x;

            }

        }
    }
   void makeMatrixIdentity()
    {
        fillMatrixWith(0);
        this->m_dane[0][0] = 1;
        this->m_dane[1][1] = 1;
        this->m_dane[2][2] = 1;
    }
   void TransposeMatrix()
   {
       for (int i = 0; i < nCols; i++) {
           for (int j = 0; j < nRows; j++) {
               if (m_dane[i] > m_dane[j]) {
                   int temp;
                   temp = m_dane[i][j];
                   m_dane[i][j] = m_dane[j][i];
                   m_dane[j][i] = temp;
               }
           }
       }
   }
};
//Default constructor

std::ostream& operator<<(std::ostream& output, const Macierz2D<double> &macierz)
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
template <typename T, int wymiar >
std::istream& operator>>(std::istream& input, const  Macierz2D<T,wymiar>& macierz)
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

int main()
{   
    Macierz2D<double,4>* x = new Macierz2D<double,4>(5, 3, 1, 4, 2, 5, 4, 6, 2, 2, 5, 4, 7, 7, 5, 3);
    Macierz2D<double,4>* y = new Macierz2D<double,4>(5, 3, 1, 4, 2, 5, 4, 6, 2, 2, 5, 4, 7, 7, 5, 3);
    Macierz2D<double,4>* z = new Macierz2D<double,4>((double)0);
    std::cout << "przykladowe mnozenie macierzy\n";
    *z = *x * *y;
    std::cout << *x;
    //niestety niezbyt rozumiem o co chodzi z fragmentem polecenia o sortowaniu.



}
