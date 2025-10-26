#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x, e = 1, s = 1;
    int t, k, i = 1;
    cout << "x = " ;
    cin >> x;
    cout << "k = " ;
    cin >> k;
    cout << "Number of decimal places";
    cout << " t = " ;
    cin >> t;
    while (abs(e) > pow(10, -k)){
        e *= (-x/i);
        s += e;
        i++;
    }
    cout << "Sum of a series: e^(-x) = " << fixed << setprecision(t) << s << endl;
    cout << "Standard function: e^(-x) = " << fixed << setprecision(t) << exp(-x);
    return 0;
}
