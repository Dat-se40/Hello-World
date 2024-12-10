#include <iostream>
using namespace std ;
void standard( char s[]){
    int  lenS = 0;
    int i = 0 , j = 0 , k = 0;
    bool flag = false;
    //su li khoano trang giua 2 chu
    while ( s[i] !='\0'){
        if (  (s[i]==s[i+1] && s[i]==' ') || (s[i] ==' ' && !flag) ) {
         i++;
         continue;
        }else {
            flag= true;
            s[j]=s[i];
            j++;
        }
        i++;
    }
    s[j]='\0';
    cout<<s;
}
int main(){
   char s[]="(*)";//(*): your test case !!!!!
   standard(s);
return 0 ;
}

