#include<iostream>
using namespace std;


class node
{
    int no;
    node *ptr;
    char name[10];
    int prg;
    int cmp;

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

    void writename(char a[])
    {
        for(int i=0;i<10;i++)
        {
            name[i]=a[i];
        }
    }

    char readname()
    {
        for(int i=0;i<10;i++)
        {
            cout<<name[i];
        }
    }

    void writeprg(int a)
    {
        prg = a;
    }

    int readprg()
    {
        return prg;
    }

    void writecmp(int a)
    {
        cmp = a;
    }

    int readcmp()
    {
        return cmp;
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
    char name[10];
    int prg;
    int cmp;

    for(int i=0;i<10;i++)
    {
        name[i] = ' ';
    }

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
            cout<<"Please input the name(10 words): ";
            cin >> name;
            p->writename(name);

            cout<<"Please input the first score: ";
            cin>> prg;
            p->writeprg(prg);

            cout<<"Please input the second score: ";
            cin>> cmp;
            p->writecmp(cmp);

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

            if(n == curr->readno())
            {
                cout<<"Data has repeated"<<endl;
                printlist(head);
                cout<<endl;
                continue;
            }

            cout<<"Please input the name(10 words): ";
            cin >> name;
            p->writename(name);

            cout<<"Please input the first score: ";
            cin>> prg;
            p->writeprg(prg);

            cout<<"Please input the second score: ";
            cin>> cmp;
            p->writecmp(cmp);

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
