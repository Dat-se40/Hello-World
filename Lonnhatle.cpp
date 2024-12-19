/* Tinh so m < n , sao cho moi chu so trong m khong phai la so chan */
#include<iostream>
#include<cmath>
using namespace std;
void arrNine( int arr[] , int &i ){
    i--;
    for (  i;  i >= 0 ; i--) arr[i]=9;
}
void arrZero( int arr[] , int k , int m  ){
    if ( k+1 < m ){
       arr[k+1]--;
       if ( arr[k+1] %2 == 0 && arr[k+1] != 0 ) arr[k+1] -= 1;
       if ( arr[k+1] == 0 ) arrZero( arr , k+1 , m );
    }
}
int main(){
    int n  , m  = 0 , arrDig[100]  ;
    cin>>n ;
    int temp = n ;
    while ( temp != 0 ){
        arrDig[m]= temp % 10 ;
        temp /=10;
        m++;
    }
    for (  int i = m - 1 ; i >= 0 ; i--){
        if ( arrDig[i] %2 == 0 && arrDig[i] != 0 ){
            arrDig[i] -= 1;
            arrNine(arrDig , i);
        }else if ( arrDig[i]%2 != 0 ) continue ;
         else if ( arrDig[i]%2 == 0 ){
                arrDig[i] = 9 ;
                int k = i ;
                arrZero( arrDig , k , m );
                arrNine(arrDig, i);
        }
    }
    for ( int i = m - 1 ; i >= 0 ; i--) if ( arrDig[i] !=0 ) cout<<arrDig[i];
 return 0 ;
}
