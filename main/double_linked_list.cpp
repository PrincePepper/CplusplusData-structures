//
// Created by semyo on 11.03.2020.
//
#include <iostream>

using namespace std;

/*
Double linked list
*/


template<typename T>
class List {
public:

    int GetSize() { return Size; }

    void clear();

    void push_front(T data);

    void push_back(T data);

    void pop_front();

    void pop_back();

    void insert(T data, int index);

    void removeAt(int index);

    T &operator[](const int index);

    void PrintFromHead();

    void PrintFromTail();

    List<T>();

    ~List<T>();

private:

    template<typename t>
    class Node {
    public:
        Node(t data = t(), Node *pNext = nullptr, Node *pPrev = nullptr) {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }

        t data;
        Node *pNext;
        Node *pPrev;
    };

    Node<T> *head;
    Node<T> *tail;
    int Size;
};

template<typename T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
    Size = 0;
}

template<typename T>
List<T>::~List() {
    clear();
}

template<typename T>
void List<T>::clear() {
    while (Size) {
        pop_front();
    }
}

template<typename T>
void List<T>::push_front(T data) {
    if (Size > 1) {
        Node<T> *temp = head;
        head = new Node<T>(data, head);
        temp->pPrev = head;
    } else if (Size == 1) {
        head = new Node<T>(data, head);
        tail->pPrev = this->head;
    } else {
        head = tail = new Node<T>(data, head, tail);
    }
    Size++;
}

template<typename T>
void List<T>::push_back(T data) {
    if (Size > 1) {
        Node<T> *temp = tail;
        tail = new Node<T>(data, nullptr, tail);
        temp->pNext = tail;
    } else if (Size == 1) {
        tail = new Node<T>(data, nullptr, tail);
        head->pNext = this->tail;
    } else {
        head = tail = new Node<T>(data, head, tail);
    }
    Size++;
}

template<typename T>
void List<T>::pop_front() {
    if (Size > 1) {
        Node<T> *temp = head;
        head = head->pNext;
        delete temp;
    } else if (Size == 1) {
        Node<T> *temp = head;
        tail = head = head->pNext;
        delete temp;
    }

    Size--;
}

template<typename T>
void List<T>::pop_back() {
    if (Size > 1) {
        Node<T> *temp = tail;
        tail = tail->pPrev;
        delete temp;
    } else if (Size == 1) {
        Node<T> *temp = tail;
        tail = head = tail->pPrev;
        delete temp;
    }

    Size--;
}

template<typename T>
void List<T>::insert(T data, int index) {
    if (index == 0) push_front(data);

    else if (index == Size || index > Size) push_back(data);
        /*здесь можно реализовать проверку, if(index > Size) то кидать исключение, с сообщением пользователю -
        - что он хочет добавить узел по индексу, до которого список еще не дорос. Либо оставить данную реализацию,
        в которой узел просто добавляется в конец*/

    else if (index <= Size / 2) {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        Node<T> *newNode = new Node<T>(data, previous->pNext, previous);

        previous->pNext = newNode;
        Node<T> *next = newNode->pNext;
        next->pPrev = newNode;

        Size++;
    } else if (index > Size / 2) {
        Node<T> *next = this->tail;
        for (int i = Size - 1; index < i; i--) {
            next = next->pPrev;
        }

        Node<T> *newNode = new Node<T>(data, next, next->pPrev);

        next->pPrev = newNode;
        Node<T> *previous = newNode->pPrev;
        previous->pNext = newNode;

        Size++;
    }
}

template<typename T>
void List<T>::removeAt(int index) {
    if (index == 0) pop_front();

    else if (index == Size || index > Size) pop_back();
/*здесь можно реализовать проверку, if(index > Size) то кидать исключение, с сообщением пользователю -
- что он хочет удалить узел по индексу, которого не существует. Либо оставить данную реализацию,
в которой просто удаляется последний узел*/

    else if (index <= Size / 2) {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        Node<T> *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        Node<T> *next = toDelete->pNext;
        delete toDelete;
        next->pPrev = previous;

        Size--;
    } else if (index > Size / 2) {
        Node<T> *next = this->tail;
        for (int i = Size - 1; index < i; i--) {
            next = next->pPrev;
        }

        Node<T> *toDelete = next->pPrev;
        next->pPrev = toDelete->pPrev;
        Node<T> *previous = toDelete->pPrev;
        delete toDelete;
        previous->pNext = next;

        Size--;
    }
}

template<typename T>
T &List<T>::operator[](const int index) {
    if (index <= Size / 2) {
        int counter = 0;
        Node<T> *current = this->head;

        while (current != nullptr) {
            if (counter == index) return current->data;
            current = head->pNext;
            counter++;
        }
    } else {
        int counter = Size - 1;
        Node<T> *current = this->tail;

        while (current != nullptr) {
            if (counter == index) return current->data;
            current = head->pPrev;
            counter--;
        }
    }
}

template<typename T>
void List<T>::PrintFromHead() {
    cout << "Come the method PrintFromHead:" << endl;
    Node<T> *print = head;
    while (print) {
        cout << print->data << endl;
        print = print->pNext;
    }
    cout << endl;
}

template<typename T>
void List<T>::PrintFromTail() {
    cout << "Come the method PrintFromTail:" << endl;
    Node<T> *print = tail;
    while (print) {
        cout << print->data << endl;
        print = print->pPrev;
    }
    cout << endl;
}

int main() {
    List<int> lst;


    lst.insert(1, 0);
    lst.insert(2, 1);
    lst.insert(4, 3);
    lst.insert(3, 2);

    lst.PrintFromHead();
    lst.PrintFromTail();

    lst.removeAt(3);

    lst.PrintFromHead();

    lst.removeAt(1);


    return 0;
}