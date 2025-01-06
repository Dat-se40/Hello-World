//Logic code mình làm nha , có mấy cái tên biến là quăng lên Claude đặc lại cho hay ::)) 
//Nếu bạn có câu hỏi thì hãy inbox mình : https://www.facebook.com/1590laupaylak

#include <iostream>
using namespace std;

struct Number {
    int tens;
    int unit;
    int value;
};

int calculateValue(const Number& num) {
    return num.tens * 10 + num.unit;
}

void findPairs(int firstDigit, int lastDigit, const Number& target) {
    Number first, second;
    int average = (firstDigit + lastDigit) / 2;
    bool used[100][100] = {false};

    for (int tens = 1; tens <= average; tens++) {
        second.tens = tens;
        first.tens = firstDigit - second.tens;
        second.unit = average - second.tens;
        first.unit = lastDigit - second.unit;
        
        first.value = calculateValue(first);
        second.value = calculateValue(second);
        
        bool isDuplicate = used[first.value][second.value] || used[second.value][first.value];
        
        if ((first.value + second.value) == target.value && 
            first.value > 9 && second.value > 9 && !isDuplicate) {
            cout << "(" << first.value << "," << second.value << ") ";
            used[first.value][second.value] = true;
        }
    }
    cout << endl;
}

int main() {
    Number target;
    // Add value initialization here
    target.value = /* your value */;
    target.tens = target.value / 10;
    target.unit = target.value % 10;

    int case1Average = target.tens + target.unit;
    int case2Average = target.tens - 1 + target.unit;

    if (case1Average % 2 == 0) {
        findPairs(target.tens, target.unit, target);
    }
    if (case2Average % 2 == 0) {
        findPairs(target.tens - 1, target.unit + 10, target);
    }

    return 0;
}
