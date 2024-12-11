#include<iostream>
#include<string.h>
#define MAX 80
using namespace std;
int main(){
    char s1[MAX];
    fgets(s1, 80, stdin); // Ký tự \n sẽ được đưa vào cuối chuỗi
    int i =0  , maxletter = 0 ;
    bool flag = false ;
    while ( s1[i] != '\0'){
        int cnt= 0 ;
        if ( (i == 0 && !flag) || isspace(s1[i-1]) && !isspace(s1[i]) ){
            flag = true ;
            cout<<i<<" ";
            while (!isspace(s1[i])){
                cnt++ ;
                i++;
            }
            cout<<cnt<<endl;
        }else i++;
        maxletter = max(maxletter, cnt);

    }
    cout<<endl<<maxletter;
return 0 ;
}
