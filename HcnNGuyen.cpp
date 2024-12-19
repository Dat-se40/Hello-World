/*Hcn gom chieu rong a , chieu dai b , duong cheo c , dien tich S
  Tinh tat ca cac hinh chu nhat co s < n , ma a , b , c la so nguyen 
  xuat ra man hinh la bo 4 so (a,b,c,d) do 
  va so hinh chu nhat tim duoc
*/
using namespace std;
int main(){
    int n , sum = 0 ; ;
    cin>>n ;
    int pytago[3][4]={ {3,4,5,12},
                       {5,12,13,60},
                       {7,24,25,168},
                    };
    for ( int i = 0 ; i< 3; i++){
        int  k = (int)sqrt(n/pytago[i][3]);
        sum += k ;
        for ( int j = 1 ; j <= k ; j++) cout<<"("<<j*pytago[i][0]<<","<<j*pytago[i][1]<<","<<j*pytago[i][2]<<","<<j*pytago[i][3]<<") ";
    }
    cout<<endl<<"Co "<<sum<<" hinh chu nhat thoa yeu cau";
return 0 ;
