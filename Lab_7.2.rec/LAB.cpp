#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int** a, const int n, const int Low, const int High, int i, int j);
void Print(int** a, const int n, int i, int j);
int sumDiagonal(int** matrix, int n, int m, int i);

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int Low = 7;
    int High = 65;
    int n;

    cout << "n = ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High, 0, 0);
    Print(a, n, 0, 0);

    int diagonalSum = sumDiagonal(a, n, n, 0 );
    cout << " sumDiagonal " << diagonalSum << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int Low, const int High, int i, int j)
{
    a[i][j] = Low + rand() % (High - Low + 1);
    if (j < n - 1)
        Create(a, n, Low, High, i, j + 1);
    else
        if (i < n - 1)
            Create(a, n, Low, High, i + 1, 0);
}
void Print(int** a, const int n, int i, int j)
{
    cout << setw(4) << a[i][j];
    if (j < n - 1)
        Print(a, n, i, j + 1);
    else
        if (i < n - 1)
        {
            cout << endl;
            Print(a, n, i + 1, 0);
        }
        else
            cout << endl << endl;
}

int sumDiagonal(int** matrix, int n, int m, int i)
{
    int diagonalSum = 0;
    int minDim = min(n, m);

    if(i < minDim-1)
    {
       return matrix[i][i] + sumDiagonal( matrix, n,  m, i + 1);
    }
    else
    {
        return matrix[i][i];
    }
}

