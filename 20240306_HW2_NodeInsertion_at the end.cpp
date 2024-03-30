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
    node *curr = NULL;
    node *p;
    int n=1;

    while(n>0)
    {
        cout<<"Please input number(exit with 0): ";
        cin>>n;

        if(n==0)
        {
            cout<<"Program ends"<<endl<<"Link Result: ";
            printlist(head);
            return 0;
        }

        p = new node;
        p->writeno(n);
        p->writeptr(NULL);

        if(head == NULL)
        {
            head = p;
        }
        else
        {
            curr->writeptr(p);
        }
        curr = p;
    }
}
