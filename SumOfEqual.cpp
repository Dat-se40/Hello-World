#include <iostream>
//bai tap 2 con tro 
//sumofequal
using namespace std;
void input(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int main() {
    int m, n;
    cin >> n ;
    int* a = new int[n];
    input(a, n);
    cin>>m ;
    int* b = new int[m];
    input(b, m) ;
    int i = 0, j = 0 , sum = 0;
    while (i < n && i <  m ) {

        if ( a[i] < b[j]) i++;
        else if ( a[i] > b[j]) j++;
         int cnti = 0 , cntj = 0;
         while ( a[i] == b[j]){
            cnti++; i++;
         }
         while ( b[j] == a[i-1]){
            cntj++ ; j++;
         }
         sum +=cnti*cntj;
        }
    cout<<sum;
    delete[] a;
    delete[] b;

    return 0;
}
