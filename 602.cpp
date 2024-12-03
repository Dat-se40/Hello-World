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
    if ( n == 1) a[0] = 1;
    else if  ( n == 2) {
        a[0]= 2;
        a[1]= 3;
    }else {
        for ( int i = 2 ; i < n ; i++){
                a[0]= 2;
                a[1]= 3;
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
        while ( a[i] != 0 ){
          int lastDig = a[i] % 10;
          a[i]/=10;
          if ( y == lastDig )  {
            cnt++;
            break;
          }
        }
    }
    return cnt;
}
