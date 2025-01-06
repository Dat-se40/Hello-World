#include<iostream>
#include<climits>
#define MAX 100000
using namespace std;
int main(){
    long long arr[MAX];
    int n, m ;
    cin>>n>>m; 
    long long sum = 0 , shipped = 0 , minHeight = INT_MAX ;
    for ( long long  i = 0 ; i < m*n ; i++){
        cin>>arr[i];
        sum += arr[i];
        minHeight = min(minHeight,arr[i]);
    }
    cout<<sum - m*n*minHeight; 
    return 0;
}

