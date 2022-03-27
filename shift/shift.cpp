#include <iostream>
using namespace std;

void fill(int** arr, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void print(int** arr, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    
    /*Задание 3. Дана матрица порядка M×N (M строк, N столбцов). Необходимо заполнить ее значениями и написать 
    функцию, осуществляющую циклический сдвиг строк 
    и/или столбцов массива указанное количество раз и в указанную сторону*/

    srand(time(NULL));

    int M, N;
    cout << "M - ";
    cin >> M;
    cout << "N - ";
    cin >> N;

    int** matr = new int* [M];
    for (int i = 0; i < M; i++) {
        matr[i] = new int [N];
    }

    int* buf = nullptr;

    int step, n = 1, key, bufer;

    fill(matr, M, N);
    print(matr, M, N);

    

    while (n != 0) {
        cout << "------------------------------" << endl;
        cout << "step - ";
        cin >> step;
        cout << "------------------------------" << endl;
        cout << "1 - up" << endl;
        cout << "2 - down" << endl;
        cout << "3 - left" << endl;
        cout << "4 - right" << endl;
        cout << "0 - exit" << endl;
        cout << "Enter : ";
        cin >> key;
        cout << "------------------------------" << endl;

        switch (key) {
        case 1:
            for (int i = 0; i < step; i++) {

                buf = new int[N];

                for (int j = 0; j < N; j++) {
                    buf[j] = matr[0][j];
                }

                for (int j = 0; j < M- 1; j++) {
                    for (int t = 0; t < N; t++) {
                        matr[j][t] = matr[j + 1][t];
                    }
                }

                for (int j = 0; j < N; j++) {
                    matr[M - 1][j] = buf[j];
                }

                delete[]buf;

            }
            print(matr, M, N);
            break;
        case 2:
            for (int i = 0; i < step; i++) {

                buf = new int[N];

                for (int j = 0; j < N; j++) {
                    buf[j] = matr[M-1][j];
                }

                for (int j = M-1; j > 0; j--) {
                    for (int t = 0; t < N; t++) {
                        matr[j][t] = matr[j - 1][t];
                    }
                }

                for (int j = 0; j < N; j++) {
                    matr[0][j] = buf[j];
                }

                delete[]buf;

            }
            print(matr, M, N);
            break;

        case 3:
            for (int i = 0; i < step; i++) {
                
                for (int j = 0; j < M; j++) {
                    bufer = matr[j][0];
                    for (int t = 0; t < N-1; t++) {
                        matr[j][t] = matr[j][t + 1];
                    }
                    matr[j][N - 1] = bufer;
                }


            }
            print(matr, M, N);
            break;
        case 4:
            for (int i = 0; i < step; i++) {

                for (int j = 0; j < M; j++) {
                    bufer = matr[j][N-1];
                    for (int t = N - 1; t > 0; t--) {
                        matr[j][t] = matr[j][t - 1];
                    }
                    matr[j][0] = bufer;
                }

            }
            print(matr, M, N);
            break;
        case 0: n = 0;
            break;
        }



    }


    
    for (int i = 0; i < M; i++) {
        delete[] matr[i];
    }

    delete[]matr;

}

