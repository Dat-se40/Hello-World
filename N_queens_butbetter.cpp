#include <iostream>
#include <vector>
using namespace std;

class NQueens {
private:
    int n;                      // Kích thước bàn cờ
    vector<vector<int>> Chess; // Bàn cờ
    vector<int> col;           // Đếm số lần cột bị đánh dấu
    vector<int> diag1;         // Đếm số lần đường chéo chính bị đánh dấu
    vector<int> diag2;         // Đếm số lần đường chéo phụ bị đánh dấu

    // In bàn cờ ra màn hình
    void PrintChess() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << Chess[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Giải bài toán N quân hậu
    void Solve(int i) {
        if (i == n) {
            PrintChess();
            return;
        }

        for (int j = 0; j < n; j++) {
            // Kiểm tra xem ô (i, j) có an toàn không
            if (col[j] == 0 && diag1[i - j + n - 1] == 0 && diag2[i + j] == 0) {
                // Đặt quân hậu tại (i, j)
                Chess[i][j] = 10;
                col[j]++;
                diag1[i - j + n - 1]++;
                diag2[i + j]++;

                // Đệ quy đặt quân hậu tiếp theo
                Solve(i + 1);

                // Gỡ quân hậu khỏi (i, j)
                Chess[i][j] = 0;
                col[j]--;
                diag1[i - j + n - 1]--;
                diag2[i + j]--;
            }
        }
    }

public:
    // Constructor để khởi tạo các mảng
    NQueens(int size) 
        : n(size), 
          Chess(size, vector<int>(size, 0)), 
          col(size, 0), 
          diag1(2 * size - 1, 0), 
          diag2(2 * size - 1, 0) 
    {}
    // Hàm bắt đầu giải bài toán
    void SolveNQueens() {
        Solve(0);
    }
};

int main() {
    int size;
    cout << "Nhap kich thuoc ban co (n): ";
    cin >> size;

    NQueens solver(size); // Tạo đối tượng solver với kích thước nhập từ người dùng
    solver.SolveNQueens(); // Bắt đầu giải bài toán

    system("pause");
    return 0;
}
