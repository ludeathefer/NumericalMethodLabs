#include <iostream>
#include <cmath>
using namespace std;

class Matrix
{
private:
    int n;
    float **mat;
    float *constMat;

public:
    Matrix()
    {
        cout << "Enter no of constants" << endl;
        cin >> n;

        mat = new float *[n];
        constMat = new float[n];
        for (int j = 0; j < n; j++)
        {
            mat[j] = new float[n];
        }
    }
    ~Matrix()
    {
        for (int j = 0; j < n; j++)
        {
            delete[] mat[j];
        }
        delete[] mat;
        delete[] constMat;
    }
    void InputMatrix()
    {
        cout << "Enter matrix coefficients" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        cout << endl
             << "Enter constants" << endl;

        for (int i = 0; i < n; i++)
        {

            cin >> constMat[i];
        }
    }
    void DisplayMat()
    {
        cout << endl
             << "The matrix is" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << "\t";
            }
            cout << constMat[i];
            cout << endl;
        }
    }
    void GaussJordan()
    {
        for (int i = 0; i < n; i++)
        {
            float div = mat[i][i];
            if (div == 0)
            {
                cout << "Error, division by zero" << endl;
                exit(1);
            }
            for (int j = 0; j < n; j++)
            {

                mat[i][j] /= div;
            }
            constMat[i] /= div;
            for (int k = 0; k < n; k++)
            {
                if (k != i)
                {
                    double factor = mat[k][i];
                    for (int j = 0; j < n + 1; j++)
                    {
                        mat[k][j] -= factor * mat[i][j];
                    }
                    constMat[k] -= factor * constMat[i];
                }
            }
        }
    }
    void DisplaySolution()
    {
        cout << "The solution is:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << constMat[i] << "\t";
        }
    }
};
int main()
{

    Matrix M;
    M.InputMatrix();
    M.DisplayMat();
    M.GaussJordan();
    M.DisplaySolution();
    return 0;
}