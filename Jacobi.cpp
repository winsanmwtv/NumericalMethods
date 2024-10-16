//
// Created by PHONGSIRI on 16 ต.ค. 2024.
//
#include <iostream>
using namespace std;
int main() {
    int n = 4;
    double matrix[n][n] = {
        {5, 2, 0, 0},
        {2, 5, 2, 0},
        {0, 2, 5, 2},
        {0, 0, 2, 5}};
    double b[n] = {12, 17, 14, 7};
    double x[n] = {0, 0, 0, 0};
    int count = 0;
    double errNum = 0.000001;
    bool err = true;
    double xOld[n];
    do {
        for (int i = 0; i < n; i++) {
            xOld[i] = x[i];
        }
        for (int i = 0; i < n; i++) {
            x[i] = b[i];
            for (int j = 0; j < n; j++) {
                if (j != i) x[i] = x[i] - (matrix[i][j] * xOld[j]);
            }
            x[i] = x[i] / matrix[i][i];
            err = err && errNum < abs(x[i] - xOld[i]);
        }
        cout << "Iteration: " << ++count << endl;
        for (int i = 0; i < n; i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    } while(err);
}