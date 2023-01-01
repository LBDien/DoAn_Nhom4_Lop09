#include <iostream>
#include "graphics.h"
#include <dos.h>
#include <conio.h>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* link;

    Node(int n)
    {
        this->data = n;
        this->link = NULL;
    }
};
struct LinkedList {
    Node* head;
    Node* tail;
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void AddHead(Node* node)
    {

        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->link = head;
            head = node;
        }
    }
    void AddTail(Node* node)
    {

        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->link = node;
            tail = node;
        }
    }
    void AddAfterQ(Node* p, Node* q)
    {

        if (q != NULL)
        {
            p->link = q->link;
            q->link = p;
            if (tail == q)
                tail = p;
        }
        else
        {
            AddHead(p);
        }
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    Node* peek(int index)
    {
        Node* node = head;
        int i = 0;
        while (node != NULL && i != index)
        {
            node = node->link;
            i++;
        }
        if (i == index && node != NULL)
            return node;
        return NULL;
    }

    int DelHead()
    {
        int result = 0;//Tra ve 0 thi List rong
        if (!isEmpty())
        {
            Node* node = head;
            result = node->data;
            head = node->link;
            delete node;
            if (isEmpty())
                tail = NULL;
        }
        return result;
    }
    int DelTail()
    {
        int result = 0;//Tra ve 0 thi List rong
        if (!isEmpty())
        {
            for (Node* k = head; k != NULL; k = k->link)
            {
                if (k->link == tail)
                {
                    delete tail;
                    k->link = NULL;
                    tail = k;
                }
            }
        }
        return result;
    }
    int DelAfterQ(Node* q)
    {
        int result = 0;//Tra ve 0 thi List rong
        if (q != NULL)
        {
            Node* p = q->link;
            if (p != NULL)
            {
                if (tail == p)
                    tail = q;
                q->link = p->link;
                result = p->data;
                delete p;

            }
        }
        return result;
    }
    int size()
    {
        Node* temp;
        temp = head;
        int s = 0;
        while (temp != NULL) {
            s++;
            temp = temp->link;
        }
        return s;

    }
};
LinkedList S1;
int N;


void VeNode(int i, char* char_type, Node* node)
{
    setcolor(3);
    int posX = 500 + i * 170;
    int posY = 500;
    rectangle(posX, posY, posX + 150, posY + 50); 
    drawText(posX + 32, posY + 8, char_type);
    circle(posX+125, posY+25, 7);
    line(posX + 100, posY, posX + 100, posY + 50);
    if (node->link != NULL)
    {
        setcolor(7);
        line(posX + 125, posY + 25, posX+175, posY+25);
    }
    
}
void Ve()
{
    system("cls");
    setcolor(3);
    int i = 0;
    N = S1.size();
    for (i; i < N; i++)
    {
        int number = S1.peek(i)->data;
        stringstream strs;
        strs << number;
        string temp_str = strs.str();
        char* char_type = (char*)temp_str.c_str();
        VeNode(i, char_type, S1.peek(i));
    }
}

void Them(int t, Node* node)
{
    int t1 = -1;
    
        cout << "1. Them dau\n";
        cout << "2. Them giua\n";
        cout << "3. Them cuoi\n";
        cout << "Lua Chon: ";
        cin >> t1;
    
    if (t1 == 1)
        S1.AddHead(node);
    if (t1 == 3)
        S1.AddTail(node);
    if (t1 == 2)
    {
        cout << "Them node vao sau vi tri: ";
        int vt;
        cin >> vt;
        Node* q = S1.peek(vt);
        S1.AddAfterQ(node, q);
    }
}
void Xoa()
{
    int t1 = -1;

    cout << "1. Xoa dau\n";
    cout << "2. Xoa giua\n";
    cout << "3. Xoa cuoi\n";
    cout << "Lua Chon: ";
    cin >> t1;

    if (t1 == 1)
        S1.DelHead();
    if (t1 == 3)
        S1.DelTail();
    if (t1 == 2)
    {
        cout << "Xoa node o sau vi tri: ";
        int vt;
        cin >> vt;
        Node* q = S1.peek(vt);
        S1.DelAfterQ(q);
    }
}
void Nhap() {
    int t = 1;
    while (t == 1 || t == 2)
    {
        
        cout << "Danh sach lua chon\n";
        cout << "1. Them\n";
        cout << "2. Xoa\n";
        cout << "3. Thoat\n";
        cout << "Lua chon: ";

        cin >> t;
        while (t > 3 || t < 1)
        {
            cout << "Nhap lai: ";
            cin >> t;
        }
        if (t == 1)
        {
            cout << "Gia tri node: ";
            int n;
            cin >> n;
            Node* node = new Node(n);
            Them(t, node);
            
            Ve();
        }
        if (t == 2)
        {
            if (N==0)
            {
                cout << "OVERFLOW" << endl;
            }
            else
            {
                Xoa();
                Ve();
            }
        }
    }

}

int main() {
    
    initgraph();
    Nhap();
    
    
}
