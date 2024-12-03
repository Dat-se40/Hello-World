#include<iostream>
using namespace std ;
int main (){
  int arr[10] = {};
  int cnto = 0  , cntf = 0;
  for(int i = 0  ; i <10 ; i++){
	cin>>arr[i];
	int lastDig = 0 ;
	while ( arr[i] != 0 )  {
		lastDig = arr[i] % 10 ;
		arr[i]/=10 ;

	}
	if ( lastDig == 1) cnto++;
	else if (lastDig == 4) cntf++;
  }
  ( cnto == 3 && cntf == 1 ) ? cout<<"TRUE" : cout<<"FALSE";

return 0 ;
}
//Nếu một dãy 10 số tồn tại 3 số có chữ số bắt đầu là chữ số 1 và 1 số bắt đầu bằng chữ số 4 thì có thể giả định rằng dãy số đó tuân thủ theo luật Benford.
//Hãy viết chương trình kiểm tra dãy số nhập vào có thỏa luật Benford không?
