
#include <iostream>
#include <cmath>
#include <vector>
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
// вывод доски
void print1(int** mat) {
    cout << "----------------------------------------------------------------" << endl;
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

// расстановка
void passtonovka(int str1, int** mat) {
    if (str1 == N) {  // Все ферзи расставлены
        scount++; // счетчик решений
        print1(mat);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (pos(mat, str1, col)) {
            mat[str1][col] = 1;          
            passtonovka(str1 + 1, mat);        
            mat[str1][col] = 0;          
        }
    }
}
//====================================================================================================================================
// 2 СПОСОБ 
int scount2 = 0;
int N2;

vector<int> S;  
vector<int> R;  
vector<int> L;  
vector<int> Q;  

// вывод
void print2() {
    cout << "----------------------------------------------------------------" << endl;
    for (int i = 1; i <= N2; i++) {
        for (int j = 1; j <= N2; j++) {
            if (Q[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void passtanovka2(int j) {  // j — тек строка
    if (j > N2) {
        scount2++;
        print2();
        return;
    }

    for (int i = 1; i <= N2; i++) {  // i — столбец
        if (S[i] == 0 && R[j - i + N2] == 0 && L[j + i] == 0) {
            S[i] = 1;
            R[j - i + N2] = 1;
            L[j + i] = 1;       // диагонали через j i - заняты
            Q[j] = i;

            passtanovka2(j + 1);

            S[i] = 0; 
            R[j - i + N2] = 0;   // бэк
            L[j + i] = 0;
        }
    }
}



int main()
{
 // Метод матрицей
    cout << "1 СПОСОБ(матрица) " << endl;
    cout << "Введите кол-во ферзей(n): ";
    cin >> N;

    if (N <= 0) {
        cout << "N должно быть больше 0 ";
        return 1;
    }

    int** mat = new int* [N];
    for (int i = 0; i < N; i++) {
        mat[i] = new int[N];
        for (int j = 0; j < N; j++) {
            mat[i][j] = 0; 
        }
    }

    scount = 0;
    passtonovka(0, mat);
    cout << "Решений для " << N << " ферзей: " << scount << endl;

    for (int i = 0; i < N; i++) {
        delete[] mat[i];
    }
    delete[] mat;


    cout << "==========================================================" << endl;
    cout << "2 СПОСОБ(АЛГОРИТМ)" << endl;
    //==========================================================
    // 2 способ 


    cout << "Введите кол-во ферзей (оптимизированный способ): ";
    cin >> N2;

    if (N2 <= 0) {
        cout << "N должно быть больше 0" << endl;
        return 1;
    }

    S.resize(N2 + 1, 0);
    Q.resize(N2 + 1, 0);
    R.resize(2 * N2 + 5, 0);   // заполнение массивов 0 
    L.resize(2 * N2 + 5, 0);

    scount2 = 0;
    passtanovka2(1);

    cout << "Решений для " << N2 << " ферзей: " << scount2 << endl;

    return 0;

}
