#include <iostream>
#include <climits>
using namespace std;

int getElement(int* data, int n, int i, int j) {
    if ((i + j) % 2 == 1) {
        return 1;
    } else {
        return data[(i * n + j) / 2];
    }
}

void printMatrix(int* data, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << getElement(data, n, i, j) << " ";
        }
        cout << endl;
    }
}

int sumRowsWithoutZeros(int* data, int n) {
    int totalSum = 0;

    for (int i = 0; i < n; i++) {
        bool hasZero = false;
        int rowSum = 0;

        for (int j = 0; j < n; j++) {
            int element = getElement(data, n, i, j);
            if (element == 0) {
                hasZero = true;
                break;
            }
            rowSum += element;
        }
        if (!hasZero) {
            totalSum += rowSum;
        }
    }

    return totalSum;
}

int maxProductOfDiagonals(int* data, int n) {
    if (n <= 1) return 0;
    
    int maxProduct = INT_MIN;
    bool first = true;

    for (int k = 1; k < n; k++) {
        int product = 1;
        for (int i = 0; i < n - k; i++) {
            product *= getElement(data, n, i, i + k);
        }
        if (first || product > maxProduct) {
            maxProduct = product;
            first = false;
        }
    }

    for (int k = 1; k < n; k++) {
        int product = 1;
        for (int i = 0; i < n - k; i++) {
            product *= getElement(data, n, i + k, i);
        }
        if (first || product > maxProduct) {
            maxProduct = product;
            first = false;
        }
    }

    return maxProduct;
}

int main() {
    int n;
    cout << "Enter matrix size n (1-10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Error: n must be between 1 and 10" << endl;
        return 1;
    }

    int elementsCount = (n * n + 1) / 2;
    int* matrixData = new int[elementsCount];

    for (int i = 0; i < elementsCount; i++) {
        matrixData[i] = 0;
    }

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                cout << "m[" << i << "][" << j << "] = ";
                cin >> matrixData[(i * n + j) / 2];
            }
        }
    }

    cout << "\nMatrix:" << endl;
    printMatrix(matrixData, n);

    int sum = sumRowsWithoutZeros(matrixData, n);
    if (sum != 0){
        cout << "Sum of elements in rows without zeros: " << sum << endl;
    }
    else{
        cout << "No rows to calculate sum" << endl;
    }    

    if (n == 1) {
        cout << "No diagonals to calculate product" << endl;
    } else {
        int maxProd = maxProductOfDiagonals(matrixData, n);
        cout << "Maximum product among diagonals parallel to main: " << maxProd << endl;
    }

    delete[] matrixData;
    return 0;
}
