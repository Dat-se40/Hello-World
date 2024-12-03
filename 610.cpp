#include <iostream>
using namespace std;


void input(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int main() {
    int m, n;
    cin >> m;
    int* a = new int[m]; 
    input(a, m);
    cin >> n;
    int* b = new int[n]; 
    input(b, n);
    int i = 0, k = 0;
    while (i < m && k < n) {
        if (a[i] > b[k]) {
            cout << b[k] << " ";
            k++;
        } else {
            cout << a[i] << " ";
            i++;
        }
    }

    while (i < m) {
        cout << a[i] << " ";
        i++;
    }
    while (k < n) {
        cout << b[k] << " ";
        k++;
    }
    delete[] a;
    delete[] b;

    return 0;
}
