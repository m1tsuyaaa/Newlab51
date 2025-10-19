/*************************
 * Name:    Katkov Stepan*
 * Project: Lab04        *
 * Var 8                 *
 *************************/
#include <iostream>
#include <iomanip>

using namespace std;

const int minSize = 1;
const int maxSize = 20;
const int columnWidth = 8;
const int numberOfArrays = 3;
const int startIndex = 0;

// Прототипы функций
int* createArray(int size);
void fillArray(int* array, int size, const char* arrayName);
int* multiplyArrays(const int* arrayA, const int* arrayB, int size);
int calculateSum(const int* array, int size);
void printArrays(const int* arrayA, const int* arrayB, const int* arrayC, int size);
void printResults(int sumA, int sumB, int sumC);

int main() {
    int arraySize;
    
    cout << "Введите размер массивов (n): ";
    cin >> arraySize;
    
    if (arraySize < minSize || arraySize > maxSize) {
        cout << "Некорректный размер массивов!" << endl;
        return 1;
    }
    
    // Создание массивов с помощью функций
    int* arrayA = createArray(arraySize);
    int* arrayB = createArray(arraySize);
    
    // Заполнение массивов
    fillArray(arrayA, arraySize, "A");
    fillArray(arrayB, arraySize, "B");
    
    // Создание массива C путем умножения
    int* arrayC = multiplyArrays(arrayA, arrayB, arraySize);
    
    // Вывод массивов
    printArrays(arrayA, arrayB, arrayC, arraySize);
    
    // Вычисление сумм
    int sumA = calculateSum(arrayA, arraySize);
    int sumB = calculateSum(arrayB, arraySize);
    int sumC = calculateSum(arrayC, arraySize);
    
    // Вывод результатов
    printResults(sumA, sumB, sumC);
    
    // Освобождение памяти
    delete[] arrayA;
    delete[] arrayB;
    delete[] arrayC;
    
    return startIndex;
}

// Функция создания массива
int* createArray(int size) {
    return new int[size];
}

// Функция заполнения массива
void fillArray(int* array, int size, const char* arrayName) {
    cout << "\nВведите элементы массива " << arrayName << ":" << endl;
    for (int index = startIndex; index < size; ++index) {
        cout << arrayName << "[" << index << "]: ";
        cin >> array[index];
    }
}

// Функция умножения массивов (создание массива C)
int* multiplyArrays(const int* arrayA, const int* arrayB, int size) {
    int* resultArray = new int[size];
    for (int index = startIndex; index < size; ++index) {
        resultArray[index] = arrayA[index] * arrayB[index];
    }
    return resultArray;
}

// Функция вычисления суммы элементов массива
int calculateSum(const int* array, int size) {
    int sum = startIndex;
    for (int index = startIndex; index < size; ++index) {
        sum += array[index];
    }
    return sum;
}

// Функция вывода массивов в табличном формате
void printArrays(const int* arrayA, const int* arrayB, const int* arrayC, int size) {
    cout << "\nРезультирующие массивы:" << endl;
    cout << setw(columnWidth) << "Индекс" 
         << setw(columnWidth) << "A[i]" 
         << setw(columnWidth) << "B[i]" 
         << setw(columnWidth) << "C[i]" << endl;
    cout << string(columnWidth * numberOfArrays, '-') << endl;
    
    for (int index = startIndex; index < size; ++index) {
        cout << setw(columnWidth) << index 
             << setw(columnWidth) << arrayA[index] 
             << setw(columnWidth) << arrayB[index] 
             << setw(columnWidth) << arrayC[index] << endl;
    }
}

// Функция вывода результатов
void printResults(int sumA, int sumB, int sumC) {
    cout << "\n=== РЕЗУЛЬТАТЫ ===" << endl;
    cout << "Сумма элементов массива A: " << sumA << endl;
    cout << "Сумма элементов массива B: " << sumB << endl;
    cout << "Сумма элементов массива C: " << sumC << endl;
}