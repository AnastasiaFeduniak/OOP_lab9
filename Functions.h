#pragma once
#include <iostream>
#include <vector>
#include "Errors.h"

using namespace std;
template <typename T>
struct Element
{
    T ch;
    Element* next;
};
template <class T>
class CSingleLinkedList
{
private:
    unique_ptr<Element<T>*> begin;
    unique_ptr<Element<T>*> end;
    int count;
public:
    CSingleLinkedList();
    CSingleLinkedList(vector<T> a);
    CSingleLinkedList(CSingleLinkedList& a);
    CSingleLinkedList(CSingleLinkedList&& a) noexcept;
    ~CSingleLinkedList();
    void show();
    T getFirstEl();
    T getLastEl();
    double getNumOfEl();
    T findMax();
    T findMin();
    void bubbleSort();
    void choiceSort();
    void skalyar(double a);
    T operator[](int index);
    CSingleLinkedList& operator=(CSingleLinkedList<T>& b);
    bool operator==(CSingleLinkedList<T>& a);
    bool operator!=(const T& a);
    bool operator!=(const CSingleLinkedList<T>& a) const;
    CSingleLinkedList& operator=(CSingleLinkedList&& b) noexcept;
    CSingleLinkedList operator - ();
    CSingleLinkedList operator+(T b);
    CSingleLinkedList operator+(CSingleLinkedList& a);
    CSingleLinkedList operator-(CSingleLinkedList& a);
    CSingleLinkedList* getArray(int num);

    //work
    friend istream& operator >> (istream& in, CSingleLinkedList<T>& a)
    {
        try {
            cout << "Enter number of elements" << endl;
            in >> a.count;
            if (!in)
            {
                throw InvalidInputException();
            }
            T s;
            Element<T>* pointer = nullptr;
            cout << "Enter " << a.count << " elements" << endl;
            for (int i = 0; i < a.count; i++)
            {
                in >> s;
                if (!in)
                {
                    throw InvalidInputException();
                }
                Element<T>* newEl = new Element<T>;
                newEl->ch = s;
                newEl->next = nullptr;
                if (i == 0) { a.begin = make_unique<Element<T>*>(newEl); }
                else
                {
                    pointer->next = newEl;
                }
                if (i == a.count - 1)
                {
                    a.end = make_unique<Element<T>*>(newEl);
                }
                pointer = newEl;
            }
            return in;
        }
        catch (InvalidInputException& e)
        {
            cout << e.what();
        }
    }

    //work
    friend ostream& operator << (ostream& out, const CSingleLinkedList<T>& a)
    {
        Element<T>* curr = nullptr;
        if (a.begin != nullptr) {
            curr = *(a.begin.get());
        }
        for (int i = 0; i < a.count; i++) {
            out << curr->ch << " ";
            curr = curr->next;
        }
        out << endl;
        return out;
    }
};


template <typename T>
int FindElementInArray(T* array, int size, T element);