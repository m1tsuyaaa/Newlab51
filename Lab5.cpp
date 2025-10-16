#include <iostream>
#include <iomanip>

using namespace std;

const int minSize = 1;
const int maxSize = 20;
const int columnWidth = 8;
const int numberOfArrays = 3;
const int startIndex = 0;

int main() {
    int arraySize;
    
    cout << "Введите размер массивов (n): ";
    cin >> arraySize;
    
    if (arraySize < minSize || arraySize > maxSize) {
        cout << "Некорректный размер массивов!" << endl;
        return 1;
    }
    
    int* arrayA = new int[arraySize];
    int* arrayB = new int[arraySize];
    int* arrayC = new int[arraySize];
    
    cout << "\nВведите элементы массива A:" << endl;
    for (int index = startIndex; index < arraySize; ++index) {
        cout << "A[" << index << "]: ";
        cin >> arrayA[index];
    }
    
    // Ввод элементов массива B
    cout << "\nВведите элементы массива B:" << endl;
    for (int index = startIndex; index < arraySize; ++index) {
        cout << "B[" << index << "]: ";
        cin >> arrayB[index];
    }
    
    for (int index = startIndex; index < arraySize; ++index) {
        arrayC[index] = arrayA[index] * arrayB[index];
    }
    
    // Вывод массивов
    cout << "\nРезультирующие массивы:" << endl;
    cout << setw(columnWidth) << "Индекс" 
         << setw(columnWidth) << "A[i]" 
         << setw(columnWidth) << "B[i]" 
         << setw(columnWidth) << "C[i]" << endl;
    cout << string(columnWidth * numberOfArrays, '-') << endl;
    
    for (int index = startIndex; index < arraySize; ++index) {
        cout << setw(columnWidth) << index 
             << setw(columnWidth) << arrayA[index] 
             << setw(columnWidth) << arrayB[index] 
             << setw(columnWidth) << arrayC[index] << endl;
    }
    
    // Вычисление сумм
    int sumA = startIndex;
    int sumB = startIndex;
    int sumC = startIndex;
    
    for (int index = startIndex; index < arraySize; ++index) {
        sumA += arrayA[index];
        sumB += arrayB[index];
        sumC += arrayC[index];
    }
    
    // Вывод результатов
    cout << "\n=== РЕЗУЛЬТАТЫ ===" << endl;
    cout << "Сумма элементов массива A: " << sumA << endl;
    cout << "Сумма элементов массива B: " << sumB << endl;
    cout << "Сумма элементов массива C: " << sumC << endl;
    
    // Освобождение памяти
    delete[] arrayA;
    delete[] arrayB;
    delete[] arrayC;
    
    return startIndex;
}