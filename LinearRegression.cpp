#include <iostream>
#include <cmath>
using namespace std;

// linear regression
int main() {

    int n = 9;
    int size = 2;

    int x[n] = {10, 15, 20, 30, 40, 50, 60, 70, 80};
    int y[n] = {5, 9, 15, 18, 22, 30, 35, 38, 43};

    double matrix[size][size];
    double b[size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 && j == 0) matrix[i][j] = n;
            else {
                for (int k = 0; k < n; k++) {
                    if (i == 1 && j == 1) matrix[i][j] = matrix[i][j] + pow(x[k], 2);
                    else matrix[i][j] = matrix[i][j] + x[k];

                    // if (i == j) {
                    //     if (i == 0) b[i] = b[i] + y[k];
                    //     else b[i] = b[i] + pow(y[k], 2);
                    // }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        b[0] = b[0] + y[i];
        b[1] = b[1] + (x[i] * y[i]);
    }

    cout << matrix[0][0] << " " << matrix [0][1] << "\n" << matrix[1][0] << " " << matrix[1][1] << endl;
    cout << b[0] << " " << b[1] << endl;

    double detA1, detA2, detA;

    detA = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    detA1 = b[0] * matrix[1][1] - b[1] * matrix[1][0];
    detA2 = matrix[0][0] * b[1] - matrix[0][1] * b[0];

    cout << "a0: " << detA1/detA << "\n"
         << "a1: " << detA2/detA << endl;

    int xfind = 65;

    cout << "f(" << xfind << ") = " << (detA1/detA) + ((detA2/detA)*xfind) << endl;

    return 0;
}