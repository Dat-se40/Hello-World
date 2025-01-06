#include <iostream>
using namespace std;

#define MAX 1000000
int soUoc[MAX + 1] = {0}; 
//Tinh uoc cac so <= n 
void preprocess(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            soUoc[j]++;
        }
    }
}

int main() {
    int n;
    long long socap = 0;
    cin >> n;

    preprocess(n); 
    int middle = n / 2;

// n = u + i . Ma u,i tinh theo tich -> uoc so 
    for (int i = 1; i < middle; i++) {
        int u = n - i;
        socap += 2LL * (soUoc[u] * soUoc[i]);
    }

//Doi xung phep congcong
    int temp = soUoc[middle];
    if (n % 2 == 0) {
        socap += 1LL * temp * temp;
    } else {
        socap += 2LL * temp * soUoc[n - middle];
    }

    cout << socap << endl;
    return 0;
}