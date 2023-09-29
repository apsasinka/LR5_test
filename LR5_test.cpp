#include <iostream>

// Функция для вычисления суммы элементов между первым и последним отрицательными элементами
int CalculateSumBetweenNegatives(int* arr, int n) {
    int firstNegativeIndex = -1;
    int lastNegativeIndex = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }
            lastNegativeIndex = i;
        }
    }

    if (firstNegativeIndex == -1 || firstNegativeIndex == lastNegativeIndex) {
        return 0;  // Отрицательных элементов нет или только один отрицательный элемент
    }

    int sum = 0;
    for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; i++) {
        sum += arr[i];
    }

    return sum;
}

// Тест на пустой массив
void TestEmptyArray() {
    int n = 0;
    int* arr = new int[n];
    int result = CalculateSumBetweenNegatives(arr, n);
    delete[] arr;

    std::cout << "Тест на пустой массив: ";
    if (result == 0) {
        std::cout << "Пройден" << std::endl;
    }
    else {
        std::cout << "Не пройден" << std::endl;
    }
}

// Тест на массив с одним отрицательным элементом
void TestOneNegativeElement() {
    int n = 1;
    int arr[] = { -3 };
    int result = CalculateSumBetweenNegatives(arr, n);

    std::cout << "Тест на массив с одним отрицательным элементом: ";
    if (result == 0) {
        std::cout << "Пройден" << std::endl;
    }
    else {
        std::cout << "Не пройден" << std::endl;
    }
}

// Тест на массив с положительными элементами
void TestAllPositiveElements() {
    int n = 4;
    int arr[] = { 3, 2, 4, 1 };
    int result = CalculateSumBetweenNegatives(arr, n);

    std::cout << "Тест на массив с положительными элементами: ";
    if (result == 0) {
        std::cout << "Пройден" << std::endl;
    }
    else {
        std::cout << "Не пройден" << std::endl;
    }
}

// Тест на массив с отрицательными элементами
void TestAllNegativeElements() {
    int n = 4;
    int arr[] = { -3, -2, -4, -1 };
    int result = CalculateSumBetweenNegatives(arr, n);

    std::cout << "Тест на массив со всеми отрицательными элементами: ";
    if (result == -6) {
        std::cout << "Пройден" << std::endl;
    }
    else {
        std::cout << "Не пройден" << std::endl;
    }
}

// Тест на массив с двумя отрицательными элементами
void TestTwoNegativeElements() {
    int n = 5;
    int arr[] = { 3, -2, -4, 1, -5 };
    int result = CalculateSumBetweenNegatives(arr, n);

    std::cout << "Тест на массив с отрицательными элементами: ";
    if (result == -3) {
        std::cout << "Пройден" << std::endl;
    }
    else {
        std::cout << "Не пройден" << std::endl;
    }
}


int main() {
    setlocale(LC_ALL, "Russian");
    TestEmptyArray();
    TestOneNegativeElement();
    TestAllPositiveElements();
    TestAllNegativeElements();
    TestTwoNegativeElements();
    // Добавьте другие функции для остальных тестов
    return 0;
}
