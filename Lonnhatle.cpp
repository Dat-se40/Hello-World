/* Tinh so m < n , sao cho moi chu so trong m khong phai la so chan */
#include <iostream>
#include <cmath>
using namespace std;

// Hàm gán tất cả các chữ số phía sau vị trí hiện tại thành 9
void fillWithNine(int digits[], int &index) {
    index--;
    for (index; index >= 0; index--) digits[index] = 9;
}

// Hàm xử lý trường hợp chữ số là 0 và cần giảm chữ số liền trước
void handleZero(int digits[], int currentIndex, int totalDigits) {
    if (currentIndex + 1 < totalDigits) {
        digits[currentIndex + 1]--;
        if (digits[currentIndex + 1] % 2 == 0 && digits[currentIndex + 1] != 0) 
            digits[currentIndex + 1] -= 1;
        if (digits[currentIndex + 1] == 0) 
            handleZero(digits, currentIndex + 1, totalDigits);
    }
}

int main() {
    int inputNumber, numDigits = 0, digitArray[100];
    cin >> inputNumber;

    int temp = inputNumber;
    while (temp != 0) {
        digitArray[numDigits] = temp % 10;
        temp /= 10;
        numDigits++;
    }

    for (int i = numDigits - 1; i >= 0; i--) {
	    //Neu chu so do la so chan -> thay doi thanh le , tat ca chu so phia sau = 9 
        if (digitArray[i] % 2 == 0 && digitArray[i] != 0) { 
            digitArray[i] -= 1; 
            fillWithNine(digitArray, i); 
        } else if (digitArray[i] % 2 != 0) {
            continue; 
        //Bo qua cac chu so le
        } else if (digitArray[i] == 0) { 
        //0 la chan dac biet 
            digitArray[i] = 9; 
            handleZero(digitArray, i, numDigits); // 0 ->9 , nho muon 1 
	    //nen tru 1 don vi 
            fillWithNine(digitArray, i); 
        }
    }  
    for (int i = numDigits - 1; i >= 0; i--) {
    //Vi dung sau khi thuc hien o tren : numDigits[0,.. ,.. ,..] . thi khong can in ra so 0 ban dau .
    
        if (digitArray[i] != 0) cout << digitArray[i];
    }

    return 0;
}
