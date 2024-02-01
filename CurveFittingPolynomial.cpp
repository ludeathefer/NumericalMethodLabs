#include <iostream>
#include <cmath>
using namespace std;

void polynomial(int d, int n, float x[], float y[])
{
    float mat[d + 1][d + 2];
    for (int i = 0; i <= d; i++)
    {
        for (int j = 0; j <= d; j++)
        {
            mat[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                mat[i][j] += pow(x[k], i + j);
            }
        }
        mat[i][d + 1] = 0;
        for (int k = 0; k < n; k++)
        {
            mat[i][d + 1] += pow(x[k], i) * y[k];
        }
    }

    for (int j = 0; j <= d; j++)
    {
        if (fabs(mat[j][j]) <= 0.0005)
        {
            cout << "Error" << endl;
            exit(1);
        }
        for (int i = 0; i <= d; i++)
        {
            if (i != j)
            {
                float ratio = mat[i][j] / mat[j][j];
                for (int k = 0; k <= d + 1; k++)
                {
                    mat[i][k] = mat[i][k] - ratio * mat[j][k];
                }
            }
        }
    }
    for (int i = 0; i <= d; i++)
    {
        mat[i][d + 1] = mat[i][d + 1] / mat[i][i];
        cout << "a" << i << "= " << mat[i][d + 1] << "\t";
    }
}

int main()
{
    int d, n;

    cout << "Degree: ";
    cin >> d;
    cout << "No of data: ";
    cin >> n;
    if (n > d)
    {
        cout << "Enter in (x,y) format: " << endl;
        float x[n], y[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }
        polynomial(d, n, x, y);
    }
    else
    {
        cerr << "Invalid input" << endl;
        exit(1);
    }
    return 0;
}