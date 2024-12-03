#include <iostream>
#include <cmath>
using namespace std;
bool isPrime( int n ){
    if ( n < 2) return false ;
    else {
        for ( int i  = 2 ; i <= sqrt(n) ; i++ ){
            if ( n%i == 0) return false ;
        }
    }
    return true ;
}
void NhapmangSNT(int a[], int &n){
    cin>>n ;
    if ( n >= 1) a[0] =2 ;
    if ( n >= 2) a[1]= 3
    }else {
        for ( int i = 2 ; i < n ; i++){
                a[i] = a[i-1] + 2;
                while ( isPrime(a[i]) == false) {
                    a[i]+=2;
                }
        }
    }
}
int SoPhanTuChuaY(int a[], int n,int y){
    int cnt = 0 ;
    for ( int i =0 ; i < n ; i++){
        int temp = a[i];
        while ( temp != 0 ){
          int lastDig = a[i] % 10;
          temp/=10;
          if ( y == lastDig )  {
            cnt++;
            break;
          }
        }
    }
    return cnt;
}
int main() {
    int a[100], n, y;
    NhapmangSNT(a, n);
    cout << "Nhap so y: ";
    cin >> y;
    cout << "So phan tu trong mang chua y: " << SoPhanTuChuaY(a, n, y) << endl;
    return 0;
}
