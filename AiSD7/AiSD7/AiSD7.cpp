#include <iostream>
#include <stack>
#include <locale>
//7 вариант средний уровень

int partition(int arr[], int low, int high) { //разделение массива
    int pivot = arr[high]; //опорный элемент (последний)
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1; //позиция опорного элемента
}

void quickSortIterative(int arr[], int low, int high) { //итеративная быстрая сортировка
    std::stack<int> stack; //ручной стек для хранения границ
    stack.push(low);
    stack.push(high);

    while (!stack.empty()) { //пока стек не пуст
        high = stack.top(); stack.pop();
        low = stack.top(); stack.pop();

        if (low < high) {
            int pi = partition(arr, low, high); //находим опорный элемент
            //добавляем в стек левую и правую части
            stack.push(low);
            stack.push(pi - 1);
            stack.push(pi + 1);
            stack.push(high);
        }
    }
}

void printArray(int arr[], int n) { //вывод массива
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

using namespace std; //разрешаем std в main

int main() {
    setlocale(LC_ALL, "ru");

    int arr[] = { 64, 34, 25, 12, 22, 11, 90, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "== Итеративная быстрая сортировка ==" << endl;
    cout << "Исходный массив: ";
    printArray(arr, n);

    quickSortIterative(arr, 0, n - 1);

    cout << "Отсортированный массив: ";
    printArray(arr, n);

    return 0;
}