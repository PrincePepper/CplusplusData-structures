#include <iostream>
using namespace std;


/*
* односвязный список
* реализация
*/


template<typename T>
class List
{
public:
    List();
    ~List();

    //удаление первого элемента в списке
    void pop_front();

    //добавление элемента в конец списка
    void push_back(T data);

    // очистить список
    void clear();

    // получить количество елементов в списке
    int GetSize() { return Size; }

    // перегруженный оператор []
    T& operator[](int index);

    //добавление элемента в начало списка
    void push_front(T data);

    //добавление элемента в список по указанному индексу
    void insert(T data, int index);

    //удаление элемента в списке по указанному индексу
    void removeAt(int index);

    //удаление последнего элемента в списке
    void pop_back();

private:


    template<typename t>
    class Node
    {
    public:
        Node* pNext;
        t data;

        explicit Node(t data = t(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T>* head;
};


template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}


template<typename T>
List<T>::~List()
{
    clear();
}


template<typename T>
void List<T>::pop_front()
{
    Node<T>* temp = head;

    head = head->pNext;

    delete temp;

    Size--;

}

template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::push_back(T data)
{

    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;

        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);

    }

    Size++;
}




template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;

    Node<T>* current = this->head;

    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        auto newNode = new Node<T>(data, previous->pNext);

        previous->pNext = newNode;

        Size++;
    }





}

template<typename T>
void List<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }


        Node<T>* toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;

        Size--;
    }

}

template<typename T>
void List<T>::pop_back()
{
    removeAt(Size - 1);
}



int main()
{

    setlocale(LC_ALL, "ru");


    List<int> lst;
    lst.push_front(5);
    lst.push_front(7);
    lst.push_front(101);

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    cout << endl << "pop_back " << endl << endl;

    lst.pop_back();

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    return 0;
}