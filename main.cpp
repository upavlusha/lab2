#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAX_SIZE = 100;
int main() { setlocale(LC_ALL, "Russian");
int mas[MAX_SIZE];
int n;

do {
    cout << "Введите размер массива (от 1 до " << MAX_SIZE << "): ";
    cin >> n;
    if (n < 1 || n > MAX_SIZE) {
        cout << "Ошибка: некорректный размер. Попробуйте снова." << endl;
    }
} while (n < 1 || n > MAX_SIZE);

int choice;
cout << "Выберите способ заполнения массива (1 - с клавиатуры, 2 - случайными числами): ";
cin >> choice;

if (choice == 1) {
    cout << "Введите " << n << " целых чисел:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> mas[i];
    }
} else {
    int min_val, max_val;
    cout << "Введите границы интервала [min, max]: ";
    cin >> min_val >> max_val;
    if (min_val > max_val) {
        swap(min_val, max_val);
    }

    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        mas[i] = min_val + rand() % (max_val - min_val + 1);
    }
}

cout << endl << "Исходный массив:" << endl;
for (int i = 0; i < n; ++i) {
    cout << mas[i] << " ";
}
cout << endl << endl;

int min_elem = mas[0];
for (int i = 1; i < n; ++i) {
    if (abs(mas[i]) < abs(min_elem)) {
        min_elem = mas[i];
    }
}
cout << "Минимальный по модулю элемент: " << min_elem << endl;

int last_zero_index = -1;
for (int i = 0; i < n; ++i) {
    if (mas[i] == 0) {
        last_zero_index = i;
    }
}

if (last_zero_index == -1) {
    cout << "Сумма после последнего нуля: нулевые элементы в массиве отсутствуют." << endl;
} else if (last_zero_index == n - 1) {
    cout << "Сумма после последнего нуля: последний нуль является последним элементом массива (сумма = 0)." << endl;
} else {
    long long sum_after_zero = 0;
    for (int i = last_zero_index + 1; i < n; ++i) {
        sum_after_zero += mas[i];
    }
    cout << "Сумма элементов после последнего нуля: " << sum_after_zero << endl;
}

int target_pos = 0;
for (int i = 0; i < n; ++i) {
    if (i % 2 != 0) {
        int temp = mas[i];
        for (int j = i; j > target_pos; --j) {
            mas[j] = mas[j - 1];
        }
        mas[target_pos] = temp;
        ++target_pos;
    }
}

cout << endl << "Преобразованный массив (четные номера, затем нечетные):" << endl;
for (int i = 0; i < n; ++i) {
    cout << mas[i] << " ";
}
cout << endl;

return 0;
}