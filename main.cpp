#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x, e = 1, s = 1;
    int k, i = 1;
    cout << "x = " ;
    cin >> x;
    cout << "k = " ;
    cin >> k;
    while (abs(e) > pow(10, -k)){
        e *= (-x/i);
        s += e;
        i++;
    }
    cout << "Sum of a series: e^(-x) = " << s << endl;
    cout << "Standard function: e^(-x) = " << exp(-x);
    return 0;
}
