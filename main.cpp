#include "matrix.h"

int main()
{
    int m,n;
    cin >> m >> n;
    Matrix A(m,n);

    A.setMatrix();
    A.printMatrix();
    cout << A[1][0];
    A[1][0] = 6;
    A.printMatrix();

    return 0;
}
