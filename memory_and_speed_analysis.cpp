#include <iostream>
#include <vector>
#include <list>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    // Программа для анализа занимаемой памяти
    cout << "Размер вектора: " << sizeof(vector<int>) << " байт" << endl;
    cout << "Размер списка: " << sizeof(list<int>) << " байт" << endl;

    // Программа, демонстрирующая скорость работы вставки и удаления для вектора и списка
    const int N = 1000000; // Количество элементов
    vector<int> vec;
    list<int> lst;

    // Замер времени вставки элементов в вектор
    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        vec.push_back(i);
    }
    auto stop = high_resolution_clock::now();
    auto duration_vector = duration_cast<milliseconds>(stop - start);

    // Замер времени вставки элементов в список
    start = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        lst.push_back(i);
    }
    stop = high_resolution_clock::now();
    auto duration_list = duration_cast<milliseconds>(stop - start);

    cout << "Время вставки " << N << " элементов:" << endl;
    cout << "Вектор: " << duration_vector.count() << " мс" << endl;
    cout << "Список: " << duration_list.count() << " мс" << endl;

    return 0;
}
