#pragma once
#ifndef MyDoublyLinkedList
#define MyDoublyLinkedList

#include<iostream>
using namespace std;

template <typename T> class DoublyLinkedList;

template<typename T>
class Node {
    friend class DoublyLinkedList<T>;

private:
    T _value;
    Node* _pPrior, * _pNext;

public:
    Node() :_pPrior(NULL), _pNext(NULL) {}
    explicit Node(const T& value) :_value(value), _pPrior(NULL), _pNext(NULL) {}

    T& getValue() {
        return _value;
    }

    Node<T>* getPrior() {
        return _pPrior;
    }

    Node<T>* getNext() {
        return _pNext;
    }
};

template <typename T>
class DoublyLinkedList {

private:
    int _size;
    Node<T>* _pFirst;
    Node<T>* _pLast;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void clear();
    bool insert(const size_t pos, const T& value);
    void Ldisplay();
    void Rdisplay();
    bool remove(const size_t pos);
    Node<T>* search(const T& value);
    T getValue(size_t pos);
};

#endif
