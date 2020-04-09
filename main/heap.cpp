//
// Created by https://prog-cpp.ru/data-heap/
//
#include <iostream>
#include <vector>

using namespace std;

//Реализация класса кучи
class Heap {
    long long *h;         // указатель на массив кучи
    long long int HeapSize; // размер кучи
public:
    explicit Heap(long long int SizeHeap);  // конструктор кучи,
    void push_heap(long long int value);  // добавление элемента кучи c сортировкой
    void push_heapNoSort(long long int value);   // добавление элемента кучи
    void BuildHeap();   // построение кучи по правилу
    long long int pop_heap();  // удаление вершины (максимального элемента)
    void heapify(long long int index);  // упорядочение кучи
    void heapify_old(long long int);  // упорядочение кучи(старая)
    long long int element_heap(long long int element); // доступ к элементам кучи(изменять нельзя)
    long long int *get_heap(long long int element); // доступ к элементам кучи(изменять можно)
    void printOut();  // вывод элементов кучи в форме массива
    void printOutHeap();  // вывод элементов кучи в форме кучи
};

//Конструктор кучи
Heap::Heap(long long int SizeHeap) {
    h = new long long int[SizeHeap];
    HeapSize = 0;
}

void Heap::push_heapNoSort(long long int value) {
    long long int i;
    i = HeapSize;
    h[i] = value;
    HeapSize++;
}

void Heap::push_heap(long long int value) {
    long long int i = HeapSize, parent, temp;
    h[i] = value;
    parent = (i - 1) / 2;
    while (parent >= 0 && i > 0) {
        if (h[i] > h[parent]) {
            temp = h[i];
            h[i] = h[parent];
            h[parent] = temp;
        }
        i = parent;
        parent = (i - 1) / 2;
    }
    HeapSize++;
}

void Heap::heapify(long long int index) {
    long long int leftChild, rightChild, temp;
    long long int largestChild;
    while (true) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        largestChild = index;
        if (leftChild < HeapSize && h[leftChild] > h[largestChild]) {
            largestChild = leftChild;
        }
        if (rightChild < HeapSize && h[rightChild] > h[largestChild]) {
            largestChild = rightChild;
        }
        if (largestChild == index) {
            break;
        }
        temp = h[index];
        h[index] = h[largestChild];
        h[largestChild] = temp;
        index = largestChild;
    }
}

//Упорядочение кучи
void Heap::heapify_old(long long int i) {
    long long int left, right;
    long long int temp;
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

void Heap::BuildHeap() {
    for (long long int i = HeapSize / 2; i >= 0; i--) {
        heapify(i);
    }
}

//Удаление вершины кучи (максимального элемента)
long long int Heap::pop_heap() {
    long long int x;
    x = h[0];
    h[0] = h[HeapSize - 1];
    HeapSize--;
    heapify(0);
    return (x);
};

long long int Heap::element_heap(long long int element) {
    return element > HeapSize ? -1 : h[element];
}

long long int *Heap::get_heap(long long int element) {
    return &h[element];
}


//Вывод элементов в форме кучи
void Heap::printOutHeap() {
    long long int i = 0, k = 1;
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
void Heap::printOut() {
    for (int i = 0; i < HeapSize; i++) {
        cout << h[i] << " ";
    }
    cout << endl;
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
    heap.printOutHeap();
    cout << endl;
    heap.printOut();
    cout << endl << "Максимальный элемент: " << heap.pop_heap();
    cout << endl << "Новая куча:" << endl;
    heap.printOutHeap();
    cout << endl;
    heap.printOut();
    cout << endl << "Максимальный элемент: " << heap.pop_heap();
    cout << endl << "Новая куча:" << endl;
    heap.printOutHeap();
    cout << endl;
    heap.printOut();
    cin.get();
    cin.get();
    return 0;
}