#include<iostream>
using namespace std ;
int main (){
  int n ;
  cin>>n;
  int arr[n]= {}, cnt[100] ={} ;
  for ( int i =0 ; i < n ; i++) {
    cin>>arr[i];
  }
  int maxx = arr[0];
  for ( int i = 0 ; i < n ; i++ ){
    maxx = (maxx >=  arr[i]) ? maxx : arr[i];
    if( maxx == arr[i] )  cnt[maxx]++;
  }
  cout<<maxx<<endl<<cnt[maxx];
  return 0 ;
}
