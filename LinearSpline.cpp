// Linear Spline
#include <iostream>
using namespace std;

// m finder function
double m(double y, double yold, double x, double xold) {
    return (y-yold) / (x-xold);
}

// x find in between
bool xbetween(double x, double xold, double xfind) {
    return xold <= xfind && xfind <= x;
}

// main function
int main() {

    // how many i
    int
    n;
    cout << "Enter i: ";
    cin >> n;

    // receive x and f(x)
    double x[n]; double y[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter x[" << i << "]: ";
        cin >> x[i];
        cout << "Enter f(x[" << i << "]): ";
        cin >> y[i];
    }

    // x they want to find (Interpolation)
    double xsum;
    cout << "Enter x you want to find: ";
    cin >> xsum;

    // cal sum
    double sumM[n];
    double sum[n];
    for (int i = 1; i < n; i++) {
        sumM[i] = m(y[i], y[i-1], x[i], x[i-1]);
    }

    // find x in between
    int xcal;
    for (int i = 1; i < n; i++) {
        if (xbetween(x[i], x[i-1], xsum)) {
            xcal = i;
            break;
        }
    }

    // calculation
    double finalSum = y[xcal-1]+sumM[xcal]*(xsum-x[xcal-1]);
    cout << "The answer is: " << finalSum << endl;
}