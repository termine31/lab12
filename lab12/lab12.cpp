
#include <iostream>
#include <cmath>
using namespace std;

int scount = 0;
int N;

// СПОСОБ 1 МАТРИЦЫ
// Проверка
bool pos(int** mat, int str1, int stol) {
    // Пр. по столбцу 
    for (int i = 0; i < str1; i++) {
        if (mat[i][stol] == 1) {
            return false;
        }
    }

    // Пр. главной диагонали (вверх-влево)
    for (int i = str1, j = stol; i >= 0 && j >= 0; i--, j--) {
        if (mat[i][j] == 1) {
            return false;
        }
    }

    // Пр. побочной диагонали (вверх-вправо)
    for (int i = str1, j = stol; i >= 0 && j < N; i--, j++) {
        if (mat[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void printBoard(int** mat) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}







int main()
{
 







}
