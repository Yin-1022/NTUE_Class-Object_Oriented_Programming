#include<iostream>
using namespace std;


class node
{
    int no;
    node *ptr;

    public:

    void writeno(int a)
    {
        no = a;
    }

    int readno()
    {
        return no;
    }

    void writeptr(node *b)
    {
        ptr=b;
    }

    node *readptr()
    {
        return ptr;
    }
};

void printlist(node *p)
{
    cout<<"head->";
    while(p)
    {
        cout<<p->readno()<<"->";
        p=p->readptr();
    }
    cout<<"||"<<endl;
}

int main()
{
    node *head = NULL;
    node *p;
    int n;
    int i;
    int times = 1;

    cout<<"Please input number: ";
    cin>>n;
    i=n;

    while(i>0)
    {
        p = new node;
        p->writeno(times);
        p->writeptr(head);
        head=p;

        times++;
        i--;
    }

    printlist(p);
}
