//
// Created by https://prog-cpp.ru/data-heap/
//
#include <iostream>

using namespace std;

//Реализация класса кучи
class Heap {
    static const int SIZE = 100000; // максимальный размер кучи
    int *h;         // указатель на массив кучи
    int HeapSize; // размер кучи
public:
    explicit Heap(unsigned int SizeHeap);  // конструктор кучи,
    void push_heap(int);  // добавление элемента кучи
    void outHeap();  // вывод элементов кучи в форме кучи
    void out();  // вывод элементов кучи в форме массива
    int getMax();  // вывод максимального элемента(вершины)
    void heapify(int);  // упорядочение кучи
    int pop_heap();  // удаление вершины (максимального элемента)

    int element_heap(unsigned int element); // доступ к элементам кучи
};

//Конструктор кучи
Heap::Heap(unsigned int SizeHeap) {
    h = new int[SizeHeap];
    HeapSize = 0;
}

void Heap::push_heap(int n) {
    int i, parent;
    i = HeapSize;
    h[i] = n;
    parent = (i - 1) / 2;
    while (parent >= 0 && i > 0) {
        if (h[i] > h[parent]) {
            int temp = h[i];
            h[i] = h[parent];
            h[parent] = temp;
        }
        i = parent;
        parent = (i - 1) / 2;
    }
    HeapSize++;
}

//Вывод элементов в форме кучи
void Heap::outHeap() {
    int i = 0;
    int k = 1;
    while (i < HeapSize) {
        while ((i < k) && (i < HeapSize)) {
            cout << h[i] << " ";
            i++;
        }
        cout << endl;
        k = k * 2 + 1;
    }
}

//Вывод элементов кучи в форме массива
void Heap::out() {
    for (int i = 0; i < HeapSize; i++) {
        cout << h[i] << " ";
    }
    cout << endl;
}

//Упорядочение кучи
void Heap::heapify(int i) {
    int left, right;
    int temp;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (left < HeapSize) {
        if (h[i] < h[left]) {
            temp = h[i];
            h[i] = h[left];
            h[left] = temp;
            heapify(left);
        }
    }
    if (right < HeapSize) {
        if (h[i] < h[right]) {
            temp = h[i];
            h[i] = h[right];
            h[right] = temp;
            heapify(right);
        }
    }
}

//Возвращение вершины
int Heap::getMax() {
    return (h[0]);
}


//Удаление вершины кучи (максимального элемента)
int Heap::pop_heap() {
    int x;
    x = h[0];
    h[0] = h[HeapSize - 1];
    HeapSize--;
    heapify(0);
    return (x);
};

int Heap::element_heap(unsigned int element) {
    return element > HeapSize ? -1 : h[element];
}

int main() {
    Heap heap(5);
    int k;
    system("chcp 1251");
    system("cls");
    for (int i = 0; i < 16; i++) {
        cout << "Введите элемент" << i + 1 << ": ";
        cin >> k;
        heap.push_heap(k);
    }
    heap.outHeap();
    cout << endl;
    heap.out();
    cout << endl << "Максимальный элемент: " << heap.getMax();
    cout << endl << "Новая куча:" << endl;
    heap.outHeap();
    cout << endl;
    heap.out();
    cout << endl << "Максимальный элемент: " << heap.getMax();
    cout << endl << "Новая куча:" << endl;
    heap.outHeap();
    cout << endl;
    heap.out();
    cin.get();
    cin.get();
    return 0;
}