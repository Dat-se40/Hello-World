#include<iostream >
using namespace std;
void pos( char s1[] , char s2[]){
    int i =0 , j =0 , sum_s2 = 0 ;
    while ( s2[j] !='\0'){;
        sum_s2+=int(s2[j]);
        j++;
    }
    while ( s1[i] !='\0'){
        if (s1[i] == s2[0]){
            int  sum_temp = 0 ;
            for ( int t = i ; t < i+j ; t++) sum_temp +=(int)s1[t];
            (sum_temp == sum_s2) ? cout<<i<<endl : cout<<endl;
        }
        i++;
    }
}
int main(){
    char s1[]="Nguyen Dat Dat";
    char s2[]="Dat";
    pos(s1, s2);
return 0;
}
