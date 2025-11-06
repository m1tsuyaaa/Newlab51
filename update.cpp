#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    // Число 20 в этом коде означает максимально допустимый размер массивов
    int space = 20;
    int arraySize;

    cout << "Введите размер массивов (n): ";
    cin >> arraySize;

    if (arraySize < 1 || arraySize > space) {
        cout << "Некорректный размер массивов!" << endl;
        return 1;
    }

    int arrayA[space];
    int arrayB[space];
    int arrayC[space];

    cout << "\nВведите элементы массива A:" << endl;
    for (int index = 0; index < arraySize; ++index) {
        cout << "A[" << index << "]: ";
        cin >> arrayA[index];
    }

    cout << "\nВведите элементы массива B:" << endl;
    for (int index = 0; index < arraySize; ++index) {
        cout << "B[" << index << "]: ";
        cin >> arrayB[index];
    }

    for (int index = 0; index < arraySize; ++index) {
        arrayC[index] = arrayA[index] * arrayB[index];
    }

    int sumA = 0;
    int sumB = 0;
    int sumC = 0;

    for (int index = 0; index < arraySize; ++index) {
        sumA += arrayA[index];
        sumB += arrayB[index];
        sumC += arrayC[index];
    }

    cout << "Сумма элементов массива A: " << sumA << endl;
    cout << "Сумма элементов массива B: " << sumB << endl;
    cout << "Сумма элементов массива C: " << sumC << endl;

    return 0;
}