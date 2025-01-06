#include<iostream>
#include<climits>
#define MAX 1000 
using namespace std;
int main(){
   int n , maxA = INT_MIN, minB = INT_MAX , i = 0 , j =0  ; 
   cin>>n;
   int a[MAX] , b[MAX];
   for (i ; i < n ; i++) {
       cin>>a[i];
       if (a[i] >= maxA ) maxA = a[i];
   }
   for ( j ; j < n ; j++){
        cin>>b[j];
        if (b[j] <= minB ) minB = b[j];
   }
    if (minB - maxA + 1 < 0) cout<<0;
    else cout<<minB - maxA + 1; 
    system("pause"); 
    return 0 ;
}   