#include <iostream>
#include <vector>
#include <algorithm>

// Используем стандартные модули вектор и алгоритм из STL 

using namespace std;

int main() {
    // Создаем генерацию случайних чисел
    srand(time(NULL));

    setlocale(LC_ALL, "RUSSIAN");
    // Пусть дан массив из 10 элементов
    int n = 10;
    vector<int> arr(n);

    // Заполнение массива случайными числами от 0 до 9
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;
    }

    cout << "Массив до операций:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    // Вставка перед каждым 3 элементом 100
    for (int i = 3; i < arr.size(); i += 4) {
        arr.insert(arr.begin() + i, 100);
    }

    cout << "Массив после вставки:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    // Удаление всех кратных 3
    arr.erase(remove_if(arr.begin(), arr.end(), [](int x) { return x % 3 == 0; }), arr.end());

    cout << "Массив после удаления:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    // Сортировка первой половины по убыванию
    // Делим длину пополам и сортируем только первую часть
    sort(arr.begin(), arr.begin() + arr.size() / 2, greater<int>());

    cout << "Массив после сортировки:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}
