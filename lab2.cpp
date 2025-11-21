#include <iostream>
#include <ctime>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    const int MAX_SIZE = 100;
    cout << "MAX_SIZE = " << MAX_SIZE << endl;
    double min, max, s, p, min_otr, max_otr;
    int c, t, g, count;
    count = 0;
    g = 1;
    s = 0;
    p = 1;
    double a[MAX_SIZE];
    while (true){
        cout << "c = ";
        cin >> c;
        if (c > MAX_SIZE){
            cout << "c need to be < MAX_SIZE" << endl;
            return 0;
        }
        if (c < 1){
            cout << "c need to be >= 1" << endl;
            return 0;
        }
        if (c < MAX_SIZE)
            break;
    }
    cout << "1 - print, 2 - random" << endl;
    cin >> t;
    if (t == 1){
        for (int i = 0; i < c; i++){
            cout << "a[" << i << "] = ";
            cin >> a[i];
        }
    }
    else{
        srand(time(0));
        cout << "Print interval for numbers" << endl;
        cout << "Left edge = ";
        cin >> min;
        cout << "Right edge = ";
        cin >> max;
        for (int i = 0; i < c; i++){
            a[i] = (double) rand()/RAND_MAX*(max-min)+min;
            cout << "a[" << i << "] = " << a[i] << endl;
        }
    }
    for (int i = 0; i < c; i++){
        if (i % 2 == 1)
            s += a[i];
    }
    cout << "s = " << s << endl;
    for (int i = 0; i < c - 1; i++){
        if (a[i] < 0){
            min_otr = i;
            break;
        }
        else
            min_otr = 0;
    }

    for (int i = c - 1 ; i > -1; i--){
        if (a[i] < 0){
            max_otr = i;
            break;
        }
        else
            max_otr = 0;
    }

    for (int i = min_otr+1; i < max_otr; i++){
            p *= a[i];
    }

    if (min_otr == max_otr)
        cout << "p doesn't exist" << endl;
    else
        cout << "p = " << p << endl;

    for (int i = 0; i < c; i++) {
        if (abs(a[i]) >= 1) {
            a[count] = a[i];
            count++;
        }
    }

    for (int i = count; i < c; i++) {
        a[i] = 0;
    }

    for (int i = 0; i < c; i++){
        cout << "a[" << i << "] = " << a[i] << endl;
    }
    return 0;
}
