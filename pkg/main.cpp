#include <iostream>
#include <limits>

using namespace std;

const int MAX_SIZE = 100;

int main() {
    int n;

    // Ввод размера матрицы
    while (true) {
        cout << "Enter matrix size n (1-" << MAX_SIZE << "): ";
        cin >> n;

        if (cin.fail()) {
            cout << "Error: enter an integer number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (n < 1 || n > MAX_SIZE) {
            cout << "Error: size must be between 1 and " << MAX_SIZE << ".\n";
            continue;
        }

        break;
    }

    int a[MAX_SIZE][MAX_SIZE];

    // Ввод элементов матрицы
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            while (true) {
                cout << "a[" << i << "][" << j << "] = ";
                cin >> a[i][j];

                if (cin.fail()) {
                    cout << "Error: enter an integer.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    break;
                }
            }
        }
    }

    // Обработка столбцов
    for (int j = 0; j < n; j++) {
        bool hasNegative = false;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (a[i][j] < 0) {
                hasNegative = true;
                break;
            }
            sum += a[i][j];
        }

        if (!hasNegative) {
            a[j][j] = sum;
        }
    }

    // Вывод результата
    cout << "\nResult matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    string str;
    cin >> str;
    cin >> str;

    return 0;
}
