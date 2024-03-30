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
    node *pre = NULL;
    int n=1;
    int i=0;

    while(n>0)
    {
        cout<<"Please input number(exit with 0): ";
        cin>>n;

        if(n<=0)
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
            curr = head;
            printlist(head);
        }
        else
        {
            while(n > curr->readno())
            {
                pre = curr;

                if(curr->readptr() == NULL)
                {
                    break;
                }

                curr = curr->readptr();
            }

            if(pre==NULL)
            {
                p -> writeptr(head);
                head = p;
                printlist(head);
            }
            else if (curr->readptr() == NULL && n > curr->readno())
            {
                pre -> writeptr(p);
                p -> writeptr(NULL);
                printlist(head);
            }
            else
            {
                pre-> writeptr(p);
                p->writeptr(curr);
                printlist(head);
            }
        }
        curr = head;
        pre = NULL;
        cout<<endl;

    }
}
