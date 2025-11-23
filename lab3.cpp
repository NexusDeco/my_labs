#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Write n (1-10) = ";
    cin >> n;

    if ((n<1)||(n>10)){
        cout << "Mistake, need to be from 1 to 10";
        return 0;
    }

    int** m = new int*[n];
    for (int i = 0; i<n; i++){
        m[i] = new int[n];
    }

    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if ((i+j) % 2 == 1){
                m[i][j] = 1;
            } else {
                cout << "m[" << i << "]" << "[" << j << "] = ";
                cin >> m[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    int s{};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (m[i][j]==0){
                break;
            }else{
                s+= m[i][j];
            }

        }
    }

    cout << "Sum of elements in rows without zeros: " << s << endl;

    int d = 1;
    for (int i = 1; i < n; i++){
        int p = 1;
        for (int j = 0; j < n-i; j++){
            p *= m[i+j][j];
        }
        if (p > d){
            d = p;
        }
    }
    for (int j = 1; j < n; j++){
        int p = 1;
        for (int i = 0; i < n-j; i++){
            p *= m[i][j+i];
        }
        if (p > d){
            d = p;
        }
    }
    if (n == 1){
        cout << "There are no diagonals to calculate the product" << endl;
    }
    cout << "Maximum product of among of current diagonals: " << d << endl;

    for (int i = 0; i<n; i++){
        delete[] m[i];
    }
    delete[] m;
    return 0;
}
