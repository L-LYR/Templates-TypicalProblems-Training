#include <iostream>
using namespace std;
class linkList
{
    struct node
    {
        int val;
        node *next;
        node(int _val)
        {
            val = _val;
            next = nullptr;
        }
    };
    node *head;
    int size;

public:
    linkList() : size(0) { head = new node(0); }
    ~linkList()
    {
        node *p = head;
        while (p)
        {
            node *d = p;
            p = p->next;
            delete d;
        }
        head = nullptr;

        size = 0;
    }
    void addAtTail(int val)
    {
        node *p = head;
        while (p->next)
            p = p->next;
        node *newNode = new node(val);
        p->next = newNode;
        ++size;
    }
    void show(void)
    {
        node *p = head->next;
        if (p)
        {
            cout << p->val;
            p = p->next;
        }
        while (p)
        {
            cout << " " << p->val;
            p = p->next;
        }
        cout << endl;
    }
    void removeVal(int val)
    {
        node *last = head, *p = head->next;
        while (p)
        {
            if (p->val == val)
            {
                node *temp = p;
                p = p->next;
                last->next = p;
                delete temp;
                --size;
            }
            else
            {
                last = p;
                p = p->next;
            }
        }
    }
    int getSize(void)
    {
        return size;
    }
};

int main(void)
{
    int n, m, t;
    while (cin >> n)
    {
        linkList a;
        for (int i = 0; i < n; ++i)
        {
            cin >> t;
            a.addAtTail(t);
        }
        cout << a.getSize() << endl;
        a.show();
        cin >> m;
        a.removeVal(m);
        cout << a.getSize() << endl;
        a.show();
    }
    return 0;
}