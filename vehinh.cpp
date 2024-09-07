#include <iostream >
using namespace std;
void tamgiac(int day){
int n=day;
int m=0;
 while(day>0){
    for (int i=1;i<=m;i++){ //thut le ne ::)) 
        cout<<" ";
    }
    for (int j=1;j<=day;j++){ //in so ne
        cout<<j;        
    }
m++; //bien dem cho le
day-=2; // giam dan canh day
cout<<endl;
    }
 }
int main(){
int doi,day; //ve tam giac can 
int buttom=1;
while (buttom==1){
 cout<<"nhan chieu dai canh day cua tam giac can ";cin>>day;
  if (day%2==1){
    tamgiac(day);
 }else {
    cout<<"Moi ban nhap lai\n";
 }
 cout<<"Ban co muon ve tiep hinh hay khong voi 1 la co , so bat ki de dung\n"; 
 cin>>buttom;
}
cout<<" enter any symbols  to close program";
cin>>doi;
  return 0; // ::)) Mac met 
}