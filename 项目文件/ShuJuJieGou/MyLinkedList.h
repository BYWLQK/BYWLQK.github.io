
#ifndef myList
#define myList

#include <iostream>        //����ͷ�ļ�iostream
using namespace std;

template <class f>
class LinkedList     //��������LinkedList<f>�࣬�нڵ�Node����Сsize����¼ͷ��ַ��ָ��head
{
public:
    struct Node {     //����ṹ��Node���з�����ֵdata��������һ���ڵ��ַ��ָ��next�����ھ����еĵ�ָ��mat
        f coef;
        f exp;
        Node* next;
        Node(int a = 0, f b = 0) : next(nullptr), coef(0),exp(0) {}
    };

private:
    Node* head;
    int size;

public:
    //���캯��
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
    �������ܣ�ȡ�������С
    ���룺��
    ����������Сsize
    ******************************************/
    int getSize()const { return size; }

    /******************************************
    �������ܣ������������һ���ڵ�
    ���룺λ��pos���ڵ���ֵvalue
    �������
    ******************************************/
    void insert(int pos, f value1,f value2)
    {
        Node* p1 = nullptr, * p2 = nullptr;
        p1 = advance(pos - 1);
        if (p1->next == nullptr)
        {
            p1->next = new Node;
            p1->next->coef = value1;
            p1->next->exp = value2;
        }
        else
        {
            p2 = p1->next;

            p1->next = new Node;
            p1->next->next = p2;

            p1->next->coef = value1;
            p1->next->exp = value2;
        }

        size++;
    }

    void insert(Node* pos, f value1, f value2)
    {
        Node* p1 = nullptr, * p2 = nullptr;
        p1 = this->head;
        while (p1->next != pos) { p1 = p1->next; }
        if (p1->next == nullptr)
        {
            p1->next = new Node;
        }
        else
        {
            p2 = p1->next;

            p1->next = new Node;
            p1->next->next = p2;

            p1->next->coef = value1;
            p1->next->exp = value2;
        }

        size++;
    }

    void add(LinkedList& rhs) {
        Node* p = nullptr;
        Node* q=nullptr;
        p = this->head->next;
        q = rhs.head->next;
        while (p!=nullptr&&q!=nullptr) {
        
            if (p->exp < q->exp) {
                p = p->next;
            }
            else if(p->exp > q->exp){
                insert(p,q->coef,q->exp);
                q = q->next;
            }
            else if(p->exp == q->exp){
                p->coef = p->coef + q->coef;
                if (p->coef == 0) {
                    Node* t = p->next;
                    remove(p);
                    p = t;
                }
                Node* t = q->next;
                rhs.remove(q);
                q = t;
            }
        
        }
        if (q != nullptr) {
            insert(this->size,q->coef,q->exp);
        }
    }

    /******************************************
    �������ܣ�ɾ���������ĳ���ڵ�
    ���룺λ��pos
    �������
    ******************************************/
    void remove(int pos)
    {
        Node* p1 = nullptr, * p2 = nullptr;
        p1 = advance(pos - 1);
        if (p1->next->next == nullptr)
        {
            delete p1->next;
            p1->next = nullptr;
        }
        else
        {
            p2 = p1->next->next;

            delete p1->next;

            p1->next = p2;
        }

        size--;
    }

    void remove(Node* pos)
    {
        Node* p1 = nullptr, * p2 = nullptr;
        p1 = this->head;
        while (p1->next != pos) { p1 = p1->next; }
        if (p1->next->next == nullptr)
        {
            delete p1->next;
            p1->next = nullptr;

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
    �������ܣ�ȡ������ĳ�ڵ����ֵf
    ���룺λ��pos
    �������λ�õ���ֵ
    ******************************************/
    f at(int pos)const
    {
        Node* p1 = nullptr;
        p1 = advance(pos);

        return p1->data;
    }
    /******************************************
    �������ܣ��޸�ĳ���ڵ����ֵ
    ���룺λ��pos����ֵnewValue
    �������
    ******************************************/
    void modify(int pos, f newValue)
    {
        Node* p1 = nullptr;
        p1 = advance(pos);

        p1->data = newValue;
    }

    /******************************************
    �������ܣ�����Ļ�ϴ�ӡ������
    ���룺��
    �������
    ******************************************/
    void disp()const
    {
        Node* p1 = nullptr;
        p1 = head->next;
        for (; p1 != nullptr;)
        {
            cout << p1->coef<<"x"<<p1->exp << " ";
            p1 = p1->next;
        }
        cout << endl;
    }

private:
    /******************************************
    �������ܣ�ȡ��ĳ���ڵ�ĵ�ַ
    ���룺λ��pos
    �������λ�ýڵ�ĵ�ַ
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
    //���������
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

