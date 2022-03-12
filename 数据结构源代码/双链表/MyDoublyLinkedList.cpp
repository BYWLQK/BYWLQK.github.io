#include"MyDoublyLinkedList.h"

template <typename T>
void DoublyLinkedList<T>::clear() {
    Node<T>* p1 = _pFirst->_pNext;
    for (int i = 0; i < _size; i++) {
        Node<T>* pt = p1;
        p1 = p1->_pNext;
        delete pt;
    }
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    _size = 0;
    _pFirst = new Node<T>();
    _pLast = new Node<T>();
    _pFirst->_pNext = _pLast;
    _pLast->_pPrior = _pFirst;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
    _size = 0;
    delete _pFirst;
    delete _pLast;
}

template <typename T>
bool DoublyLinkedList<T>::insert(const size_t pos, const T& value) {
    if (pos > _size) {
        return insert(_size, value);
    }
    Node<T>* p1 = NULL;
    if (pos > _size / 2) {
        p1 = _pLast;
        for (int i = _size; i >= pos; i--) { p1 = p1->_pPrior; }
    }
    else {
        p1 = _pFirst;
        for (int i = 0; i < pos; i++) { p1 = p1->_pNext; }
    }
    Node<T>* pt = p1->_pNext;
    p1->_pNext = new Node<T>(value);
    p1->_pNext->_pPrior = p1;
    p1->_pNext->_pNext = pt;
    pt->_pPrior = p1->_pNext;
    _size++;
    return true;
}

template <typename T>
void DoublyLinkedList<T>::Ldisplay() {
    Node<T>* p1 = _pFirst;
    for (int i = 0; i < _size; i++) {
        p1 = p1->_pNext;
        cout << p1->getValue() << " ";
    }
}

template <typename T>
void DoublyLinkedList<T>::Rdisplay() {
    Node<T>* p1 = _pLast;
    for (int i = 0; i < _size; i++) {
        p1 = p1->_pPrior;
        cout << p1->getValue() << " ";
    }
}

template <typename T>
bool DoublyLinkedList<T>::remove(const size_t pos) {
    if (pos > _size) {
        return remove(_size);
    }
    Node<T>* p1 = NULL;
    if (pos > _size / 2) {
        p1 = _pLast;
        for (int i = _size; i >= pos; i--) { p1 = p1->_pPrior; }
    }
    else {
        p1 = _pFirst;
        for (int i = 0; i < pos; i++) { p1 = p1->_pNext; }
    }
    Node<T>* pt = p1->_pNext;
    p1->_pNext = pt->_pNext;
    pt->_pNext->_pPrior = p1;
    delete pt;
    _size--;
    return true;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::search(const T& value) {
    Node<T>* p1 = _pFirst;
    for (int i = 0; i < _size; i++) {
        p1 = p1->_pNext;
        if (p1->getValue() == value) {
            return p1;
        }
    }
    return NULL;
}