#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include<memory>
#include "Functions.h"
#include "Errors.h"
using namespace std;

template <typename T>
CSingleLinkedList<T>::CSingleLinkedList()
{
    try {

        begin = nullptr;
        end = nullptr;
        count = 0;
    }
    catch (const  OutOfMemoryException& e)
    {
        cout << e.what();
    }

}
template <typename T>
CSingleLinkedList<T>* CSingleLinkedList<T>::getArray(int num)
{
    try
    {
        CSingleLinkedList* f = new CSingleLinkedList[num];
        return f;

    }
    catch (const bad_alloc&)
    {
        throw OutOfMemoryException();
    }
}

template <typename T>
CSingleLinkedList<T>::CSingleLinkedList(vector<T> a)
{
    try {
        count = a.size();
        Element<T>* prev = nullptr;
        for (int i = 0; i < count; i++)
        {
            Element<T>* newEl = new Element<T>;
            if (newEl == nullptr)
            {
                throw bad_alloc();
            }
            newEl->ch = a[i];
            if (i == 0)
            {
                begin = make_unique<Element<T>*>(newEl);
            }
            else {
                prev->next = newEl;
            }
            if (i == count - 1) {
                end = make_unique<Element<T>*>(newEl);
            }
            newEl->next = nullptr;
            prev = newEl;
        }
    }
    catch (const bad_alloc&)
    {
        OutOfMemoryException r;
        cout << r.what();
    }
}

template <typename T>
void CSingleLinkedList<T>::show()
{
    if (begin != nullptr) {
        cout << (*begin)->ch << endl;
        shared_ptr<Element<T>*> tmp = make_shared<Element<T>*>((*begin)->next);
        for (int i = 1; i < count - 1; i++) {
            cout << (*tmp)->ch << endl;
            tmp = make_shared<Element<T>*>((*tmp)->next);
        }
        if (count != 1)
            cout << (*end)->ch << endl;
    }
}
template <typename T>
T CSingleLinkedList<T>::getFirstEl()
{
    try {
        if (begin == nullptr) {
            throw  InvalidListSizeException();
        }
        return (*begin)->ch;
    }
    catch (InvalidListSizeException& e) {
        cout << e.what() << endl;
        return T();
    }
}
template <typename T>
T CSingleLinkedList<T>::getLastEl()
{
    try {
        if (end == nullptr) {
            throw  InvalidListSizeException();
        }
        return (*end)->ch;
    }
    catch (InvalidListSizeException& e) {
        cout << e.what() << endl;
        return T();
    }
}
template <typename T>
double CSingleLinkedList<T>::getNumOfEl()
{
    return count;
}
template <typename T>
CSingleLinkedList<T>::CSingleLinkedList(CSingleLinkedList& a)
{
    *this = a;
}
template <typename T>
CSingleLinkedList<T>::CSingleLinkedList(CSingleLinkedList&& a) noexcept
{
    begin = move(a.begin);
    end = move(a.end);
    count = a.getNumOfEl();
    a.count = 0;
}
template <typename T>
CSingleLinkedList<T> :: ~CSingleLinkedList() {}

template <typename T>
T CSingleLinkedList<T>::findMax()
{
    try {
        if (begin == nullptr) {
            throw  ReadAccesViolation();
        }
        shared_ptr<Element<T>*> tmp = make_shared<Element<T>*>((*begin)->next);
        T max;
        ((*begin)->ch >= (*end)->ch) ? max = (*begin)->ch : max = (*end)->ch;
        if (tmp != nullptr) {
            for (int i = 1; i < count - 1; i++) {
                if (max < (*tmp)->ch) { max = (*tmp)->ch; }
                tmp = make_shared<Element<T>*>((*tmp)->next);
            }
        }
        return max;
    }
    catch (ReadAccesViolation& e)
    {
        cout << e.what();
        return T();
    }
}
template <typename T>
T CSingleLinkedList<T>::findMin()
{
    try {
        if (begin == nullptr) {
            throw  ReadAccesViolation();
        }
        shared_ptr<Element<T>*> tmp = make_shared<Element<T>*>((*begin)->next);
        T min;
        ((*begin)->ch <= (*end)->ch) ? min = (*begin)->ch : min = (*end)->ch;
        if (tmp != nullptr) {
            for (int i = 1; i < count - 1; i++) {
                if (min > (*tmp)->ch) { min = (*tmp)->ch; }
                tmp = make_shared<Element<T>*>((*tmp)->next);
            }
        }
        return min;
    }
    catch (ReadAccesViolation& e)
    {
        cout << e.what();
        return T();
    }
}
template <typename T>
void CSingleLinkedList<T>::bubbleSort() {
    if (begin != nullptr) {
        int mistakeC = 0;
        do {
            mistakeC = 0;
            Element<T>* tmp = *(begin.get());
            while (tmp->next != nullptr)
            {
                if (tmp->next->ch < tmp->ch)
                {
                    mistakeC++;
                    swap(tmp->ch, tmp->next->ch);
                }
                tmp = tmp->next;
            }
        } while (mistakeC != 0);
    }
}
template <typename T>
void CSingleLinkedList<T>::choiceSort() {
    if (begin != nullptr) {
        for (Element<T>* i = *(begin.get()); i != nullptr; i = i->next)
        {
            Element<T>* max = i;
            for (Element<T>* j = i->next; j != nullptr; j = j->next)
            {
                if (j->ch > max->ch)
                {
                    max = j;
                }
            }
            if (max != i)
            {
                T tmp = i->ch;
                i->ch = max->ch;
                max->ch = tmp;
            }
        }
    }
}

template <typename T>
void CSingleLinkedList<T>::skalyar(double a)
{
    (*begin)->ch *= a;
    (*end)->ch *= a;
    shared_ptr<Element<T>*> tmp = make_shared<Element<T>*>((*begin)->next);
    for (int i = 1; i < count - 1; i++) {
        (*tmp)->ch *= a;
        tmp = make_shared<Element<T>*>((*tmp)->next);
    }
}

template <typename T>
ostream& operator << (ostream& out, const CSingleLinkedList<T>& a)
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
template <typename T>
T CSingleLinkedList<T> :: operator[](int index)
{
    try {
        if (index > count || index < 0)
        {
            throw InvalidListAccessException();
        }
        if (index == 0)
        {
            return (*begin)->ch;
        }
        if (index == count - 1)
        {
            return (*end)->ch;
        }
        shared_ptr<Element<T>*> tmp = make_shared<Element<T>*>((*begin)->next);
        for (int i = 1; i < index; i++)
        {
            tmp = make_shared<Element<T>*>((*tmp)->next);
        }
        return (*tmp)->ch;
    }
    catch (InvalidListAccessException& e)
    {
        cout << e.what();
        return T();

    }
}

template <typename T>
CSingleLinkedList<T>& CSingleLinkedList<T> :: operator=(CSingleLinkedList<T>& b) {
    try {
        count = b.count;
        Element<T>* prev = nullptr;
        for (int i = 0; i < count; i++)
        {
            Element<T>* newEl = new Element<T>;
            if (newEl == nullptr)
            {
                throw bad_alloc();
            }
            newEl->ch = b[i];
            if (i == 0)
            {
                begin = make_unique<Element<T>*>(newEl);
            }
            else if (i == count - 1) {
                end = make_unique<Element<T>*>(newEl);
                prev->next = newEl;
            }
            else {
                prev->next = newEl;
            }
            newEl->next = nullptr;
            prev = newEl;
        }
        return *this;
    }
    catch (const bad_alloc&)
    {
        OutOfMemoryException r;
        cout << r.what();
        CSingleLinkedList u;
        return u;
    }
}

template <typename T>
CSingleLinkedList<T>& CSingleLinkedList<T> :: operator=(CSingleLinkedList&& b) noexcept
{
    begin = move(b.begin);
    end = move(b.end);
    count = b.getNumOfEl();
    b.count = 0;
    return *this;
}
template <typename T>
CSingleLinkedList<T> CSingleLinkedList<T>:: operator - ()
{
    if (begin != nullptr) {
        if (count == 1)
        {
            Element<T>* u = *(begin.release());
            delete u;
            begin = nullptr;
            end = nullptr;
            count--;
            return *this;
        }
        unique_ptr<Element<T>*> tmp = make_unique<Element<T>*>((*begin)->next);
        for (int i = 1; i < count - 2; i++) {
            tmp = make_unique<Element<T>*>((*tmp)->next);
        }
        (*tmp)->next = nullptr;
        Element<T>* u = *(end.release());
        delete u;
        end = make_unique<Element<T>*>(*tmp);
        count--;
    }
    return *this;
}
template <typename T>
CSingleLinkedList<T> CSingleLinkedList<T> :: operator+(T b)
{
    Element<T>* newEl = new Element<T>;
    newEl->ch = b;
    newEl->next = nullptr;
    if (count == 0)
    {
        begin = make_unique<Element<T>*>(newEl);
    }
    else {
        (*end)->next = newEl;
    }
    end = make_unique<Element<T>*>(newEl);
    count++;
    return *this;
}
template <typename T>
CSingleLinkedList<T> CSingleLinkedList<T>::operator+(CSingleLinkedList& a)
{
    try
    {
        if (a.getNumOfEl() != count)
        {
            throw InvalidListAdditionSizeException();
        }
        vector<T> c;
        c.push_back((*begin)->ch + a.getFirstEl());
        Element<T>* r = *(a.begin.get());
        unique_ptr<Element<T>*> tmp1 = make_unique<Element<T>*>((*begin)->next);
        unique_ptr<Element<T>*> tmp2 = make_unique<Element<T>*>(r->next);
        while ((*tmp1)->next != nullptr || (*tmp2)->next != nullptr)
        {
            c.push_back((*tmp1)->ch + (*tmp2)->ch);
            tmp1 = make_unique<Element<T>*>((*tmp1)->next);
            tmp2 = make_unique<Element<T>*>((*tmp2)->next);
        }
        c.push_back((*end)->ch + a.getLastEl());
        CSingleLinkedList u(c);
        return u;
    }
    catch (InvalidListAdditionSizeException& e)
    {
        cout << e.what();
        CSingleLinkedList q;
        return q;
    }
}
template <typename T>
CSingleLinkedList<T> CSingleLinkedList<T>::operator-(CSingleLinkedList& a)
{
    try
    {
        if (a.getNumOfEl() != count)
        {
            throw InvalidListAdditionSizeException();
        }
        vector<T> c;
        c.push_back((*begin)->ch - a.getFirstEl());
        Element<T>* r = *(a.begin.get());
        unique_ptr<Element<T>*> tmp1 = make_unique<Element<T>*>((*begin)->next);
        unique_ptr<Element<T>*> tmp2 = make_unique<Element<T>*>(r->next);
        while ((*tmp1)->next != nullptr || (*tmp2)->next != nullptr)
        {
            c.push_back((*tmp1)->ch + (*tmp2)->ch);
            tmp1 = make_unique<Element<T>*>((*tmp1)->next);
            tmp2 = make_unique<Element<T>*>((*tmp2)->next);
        }
        c.push_back((*end)->ch - a.getLastEl());
        CSingleLinkedList u(c);
        return u;
    }
    catch (InvalidListAdditionSizeException& e)
    {
        cout << e.what();
        CSingleLinkedList q;
        return q;
    }
}
template <class T>
bool CSingleLinkedList<T>::operator==(CSingleLinkedList<T>& a) {
    if (count != a.count) {
        return false;
    }
    Element<T>* currThis = *(begin.get());
    Element<T>* currOther = *(a.begin.get());

    while (currThis != nullptr && currOther != nullptr)
    {
        if (currThis->ch != currOther->ch)
            return false;

        currThis = currThis->next;
        currOther = currOther->next;
    }
    return true;
}

template <typename T>
int FindElementInArray(T* array, int size, T element)
{
    for(int i = 0; i < size; i++)
            if (array[i] == element) {
                return i;
    }
    return size;
} 
