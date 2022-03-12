
#ifndef myList
#define myList

#include <iostream>        //包含头文件iostream
using namespace std;

template <class f>
class LinkedList     //构造链表LinkedList<f>类，有节点Node、大小size、记录头地址的指针head
{
public:
    struct Node {     //构造结构体Node，有分数数值data，储存下一个节点地址的指针next，用于矩阵中的的指针mat
        f data;
        LinkedList* mat;
        Node* next;
        Node(int a = 0, Node* b = nullptr) : next(b), mat(nullptr) {}
    };

private:
    Node* head;
    int size;

public:
    //构造函数
    LinkedList()
    {
        head = new Node;
        size = 0;
    }
    LinkedList(const LinkedList& rhs)
    {
        head = new Node;
        size = 0;
        Node* p1 = nullptr, * p2 = nullptr;
        p2 = rhs.head->next;
        p1 = head;
        for (; p2 != nullptr;)
        {
            p1->next = new Node;
            p1->next->data = p2->data;
            p1 = p1->next;
            p2 = p2->next;
            size++;
        }
    }
    LinkedList(f const a[], int n)
    {
        head = new Node;
        size = 0;
        Node* p1 = nullptr;

        p1 = head;
        for (int i = 0; i < n; i++)
        {
            p1->next = new Node;
            p1->next->data = a[i];
            p1 = p1->next;

            size++;
        }
    }
    LinkedList(int n, f value)
    {
        head = new Node;
        size = 0;
        Node* p1 = nullptr;

        p1 = head;
        for (int i = 0; i < n; i++)
        {
            p1->next = new Node;
            p1->next->data = value;
            p1 = p1->next;

            size++;
        }
    }
    ~LinkedList()
    {

        Node* p1 = nullptr, * p2 = nullptr;
        p1 = head;
        for (; p1 != nullptr;)
        {
            p2 = p1->next;
            delete p1;
            p1 = p2;

        }

    }

    /******************************************
    函数功能：取得链表大小
    输入：无
    输出：链表大小size
    ******************************************/
    int getSize()const { return size; }

    /******************************************
    函数功能：往链表里插入一个节点
    输入：位置pos，节点数值value
    输出：无
    ******************************************/
    void insert(int pos, f value)
    {
        Node* p1 = nullptr, * p2 = nullptr;
        p1 = advance(pos - 1);
        if (p1->next == nullptr)
        {
            p1->next = new Node;
        }
        else
        {
            p2 = p1->next;

            p1->next = new Node;
            p1->next->next = p2;

            p1->next->data = value;
        }

        size++;
    }

    /******************************************
    函数功能：删除链表里的某个节点
    输入：位置pos
    输出：无
    ******************************************/
    void remove(int pos)
    {
        Node* p1 = nullptr, * p2 = nullptr;
        p1 = advance(pos - 1);
        if (p1->next->next == nullptr)
        {
            delete p1->next;
        }
        else
        {
            p2 = p1->next->next;

            delete p1->next;

            p1->next = p2;
        }

        size--;
    }

    /******************************************
    函数功能：取得链表某节点的数值f
    输入：位置pos
    输出：此位置的数值
    ******************************************/
    f at(int pos)const
    {
        Node* p1 = nullptr;
        p1 = advance(pos);

        return p1->data;
    }
    /******************************************
    函数功能：修改某个节点的数值
    输入：位置pos，数值newValue
    输出：无
    ******************************************/
    void modify(int pos, f newValue)
    {
        Node* p1 = nullptr;
        p1 = advance(pos);

        p1->data = newValue;
    }

    /******************************************
    函数功能：往屏幕上打印该链表
    输入：无
    输出：无
    ******************************************/
    void disp()const
    {
        Node* p1 = nullptr;
        p1 = head->next;
        for (; p1 != nullptr;)
        {
            cout << p1->data << " ";
            p1 = p1->next;
        }
        cout << endl;
    }

private:
    /******************************************
    函数功能：取得某个节点的地址
    输入：位置pos
    输出：该位置节点的地址
    ******************************************/
    Node* advance(int pos)const
    {
        Node* p1 = nullptr;
        p1 = head;
        for (int i = -1;; i++)
        {
            if (i == pos)
            {
                return p1;
            }
            p1 = p1->next;
        }
    }

public:
    //运算符重载
    LinkedList<f>& operator = (const LinkedList<f>& rhs);
    LinkedList<f>& operator += (const LinkedList<f>& rhs);

};

template <class f>
LinkedList<f>& LinkedList<f>::operator = (const LinkedList<f>& rhs)
{
    this->~LinkedList<f>();
    head = new Node;
    size = 0;
    Node* p1 = nullptr, * p2 = nullptr;
    p2 = rhs.head->next;
    p1 = head;
    for (; p2 != nullptr;)
    {
        p1->next = new Node;
        p1->next->data = p2->data;
        p1 = p1->next;
        p2 = p2->next;
        size++;
    }
    return *this;
}

template <class f>
LinkedList<f>& LinkedList<f>::operator += (const LinkedList<f>& rhs)
{

    Node* p1 = nullptr, * p2 = nullptr;
    p2 = rhs.head->next;
    p1 = head;
    for (;;)
    {
        if (p1->next == nullptr)
        {
            break;
        }
        p1 = p1->next;
    }
    for (; p2 != nullptr;)
    {
        p1->next = new Node;
        p1->next->data = p2->data;
        p1 = p1->next;
        p2 = p2->next;
        size++;
    }
    return *this;
}

template <class f>
const LinkedList<f> operator + (const LinkedList<f>& lhs, const LinkedList<f>& rhs)
{
    LinkedList<f> t;
    t = lhs;
    t += rhs;
    return t;
}

template <class f>
bool operator == (const LinkedList<f>& lhs, const LinkedList<f>& rhs)
{
    if (lhs.getSize() == rhs.getSize())
    {
        int m;
        m = lhs.getSize();
        for (int i = 0; i < m; i++)
        {
            if (lhs.at(i) != rhs.at(i))
            {
                return 0;
            }
        }
        return 1;
    }
    else
        return 0;
}

template <class f>
bool operator != (const LinkedList<f>& lhs, const LinkedList<f>& rhs)
{
    if (lhs == rhs)
    {
        return 0;
    }
    else
        return 1;
}

template <class f>
bool operator < (const LinkedList<f>& lhs, const LinkedList<f>& rhs)
{
    int m;
    if (lhs.getSize() == rhs.getSize())
    {
        m = lhs.getSize();
        for (int i = 0; i < m; i++)
        {
            if (lhs.at(i) < rhs.at(i))
            {
                return 1;
            }
        }
        return 0;
    }
    else
    {
        if (lhs.getSize() < rhs.getSize())
        {
            m = lhs.getSize();
        }
        else
        {
            m = rhs.getSize();
        }
        for (int i = 0; i < m; i++)
        {
            if (lhs.at(i) > rhs.at(i))
            {
                return 0;
            }
        }
        if (lhs.getSize() < rhs.getSize())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

template <class f>
bool operator <= (const LinkedList<f>& lhs, const LinkedList<f>& rhs)
{
    return (lhs < rhs || lhs == rhs);
}

template <class f>
bool operator > (const LinkedList<f>& lhs, const LinkedList<f>& rhs)
{
    return !(lhs <= rhs);
}

template <class f>
bool operator >= (const LinkedList<f>& lhs, const LinkedList<f>& rhs)
{
    return !(lhs < rhs);
}

template <class f>
int zeroNum(LinkedList<f>& lhs)
{
    int n = 0;
    f x;
    for (int i = 1; i <= lhs.size; i++)
    {
        if (lhs[i].data == x)
        {
            n++;
        }
    }
    return n;
}

template <class f>
ostream& operator << (ostream& os, const LinkedList<f>& rhs)
{
    rhs.disp();
    return os;
}


#endif

