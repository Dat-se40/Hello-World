#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

int main (){
    int n , x, k ;
    int  arr[MAX] ={};
    cin>>n ;
    for ( int i = 0 ; i < n ; i++) cin>>arr[i];
    cin>>x>>k ;
    for ( int i = n - 1 ; i >= k  ; i--){
        arr[i+1]=arr[i];
    }
    arr[k] = x ;
    n++ ;
    for ( int i = 0 ; i < n ; i++) cout<<arr[i] << "  ";

 return 0;
}
