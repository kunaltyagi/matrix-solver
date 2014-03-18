#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
    typedef std::vector<double> Row;
    typedef Row Column;

    Row& operator[] (const int index)
    {
        if(index < M)
        {
            return matrix[rowIndex[index]];
        }
        else
        {
            Matrix temp(1,1);
            return temp[0];
        }
    }
/*    friend double& operator[] (Row& row, const int index)
    {
        if(index < N)
        {
            return row[columnIndex[index]];
        }
    }*/
    Matrix& operator* (const Matrix B)
    {
        if(this->N == B.M)
        {
            Matrix temp(this->M, B.N);
            for(int i = 0; i < this->M; ++i)
            {
                for(int j = 0; j < this->N; ++j)
                {
                    for(int k = 0; k < B.N; ++k)
                    {
                        temp[i][j] += (this->matrix[i][k])*(B[k][j]);
                    }
                }
        }
        else
        {
            Matrix temp(0,0);
        }
        return temp;
    }

    Matrix()
    {
        M = N = 0;
        transposed = false;
    }
    Matrix(int m, int n)
    {
        M = m;
        N = n;
        transposed = false;
        zero();
    }
    void zero()
    {
        Row temp;
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                temp.push_back(0);
            }
            matrix.push_back(temp);
        }
    }
    void zero(int m, int n = -1)
    {
        if(n < 0)
        {
            n = m;
        }
        setM(m);
        setN(n);
    }
    int getM()
    {
        return M;
    }
    void setM(int m)
    {
        if(m > 0 && M != m)
        {
            M = m;
            zero();
        }
    }
    int getN()
    {
        return N;
    }
    void setN(int n)
    {
        if(n > 0 && N != n)
        {
            N = n;
            zero();
        }
    }
    void transpose()
    {
        transposed = 1 - transposed;
    }
    bool setMatrix()
    {
        if(matrix.empty() == false)
        {
            matrix.clear();
        }
        Row temp;
        double element;
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                cin >> element;
                temp.push_back(element);
            }
            matrix.push_back(temp);
            temp.clear();
        }
        return true;
    }
    bool setMatrix(int m, int n = -1)
    {
        if(m > 0)
        {
            if(n > 0)
            {
                M = m;
                N = n;
                return setMatrix();
            }
            else
            {
                M = m;
                N = m;
                return setMatrix();
            }
        }
        return false;
    }
    void printMatrix()
    {
        cout << "Row,\t" << M << ",\tColumn,\t" << N << ",\t" << endl;
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                cout << matrix[i][j] << ",\t";
            }
            cout << endl;
        }
    }
    bool underDetermined()
    {
        if(M < N-1)
        {
            return true;
        }
    }
    bool overDetermined()
    {
        if(M > N-1)
        {
            return true;
        }
    }

private:
    int M,N;
    bool transposed;
    vector<Row> matrix;
    Row rowIndex;
    Column columnIndex;

    void initRow()
    {
        if(rowIndex.empty() == false)
        {
            rowIndex.clear();
        }
        for(int i = 0; i < M; ++i)
        {
            rowIndex.push_back(i);
        }
    }
    void initColumn()
    {
        if(columnIndex.empty() == false)
        {
            columnIndex.clear();
        }
        for(int i = 0; i < M; ++i)
        {
            columnIndex.push_back(i);
        }
    }

protected:
};


#endif
