#include <iostream>
#include <vector>
using namespace std;

class NQueens {
private:
    int n;
    vector<vector<int>> LocalBoard;
    vector<vector<int>> MarkBoard;

    void PrintBoard() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << LocalBoard[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void Mark(int i, int j, int operand) {
        for (int x = 0; x < n; x++) {
            MarkBoard[i][x] += operand;
            MarkBoard[x][j] += operand;
            int y = x + i - j;
            if (y >= 0 && y < n) MarkBoard[y][x] += operand;
            y = -x + i + j;
            if (y >= 0 && y < n) MarkBoard[y][x] += operand;
        }
    }
    void PosOfQueen(int i) {
        for (int j = 0; j < n; j++) {
            if (MarkBoard[i][j] == 0) {
                Mark(i, j, 1);
                LocalBoard[i][j] = 10;
                if (i == n - 1) {
                    PrintBoard();
                } else {
                    PosOfQueen(i + 1);
                }
                Mark(i, j, -1);
                LocalBoard[i][j] = 0;
            }
        }
    }

public:
    NQueens(int size) : n(size) {
        LocalBoard.resize(n, vector<int>(n, 0));
        MarkBoard.resize(n, vector<int>(n, 0));
    }
    void Solve() {
        PosOfQueen(0);
    }
};

int main() {
    int n;
    cout << "Nhap kich thuoc ban co (n): ";
    cin >> n;

    NQueens solver(n);
    solver.Solve();

    return 0;
}
