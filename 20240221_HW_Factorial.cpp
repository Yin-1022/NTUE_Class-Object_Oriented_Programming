#include<iostream>
using namespace std;


int main()
{
    int n;
    int value[100];
    int h=0;
    int flag=0;
    int carry=0;
    int carry2=0;
    int a=0;


    cout<<"請輸入階層數: ";
    cin>>n;

    for(int i=0;i<100;i++)
    {
        value[i]=0;
    }

    value[0]=1;

    for(int i=1;i<n+1;i++)
    {
        while(value[a]!=0 || value[a+1]!=0 || value[a+2]!=0|| value[a+3]!=0|| value[a+4]!=0|| value[a+5]!=0||
              value[a+6]!=0|| value[a+7]!=0|| value[a+8]!=0|| value[a+9]!=0 ||
              value[a+10]!=0 || value[a+11]!=0 || value[a+12]!=0|| value[a+13]!=0|| value[a+14]!=0)
        {
            a++;
        }

        while(a!=0)
        {
            if(h==0)
            {
                if(value[h]*i>10)
                {
                    carry=value[h]*i/10;
                }

                value[h]=value[h]*i%10;
                h++;
            }


            while(h>0 && a>1)
            {
                carry2 = value[h]*i/10;
                value[h]=carry+value[h]*i%10;
                if(value[h]>=10)
                {
                    carry2=carry2+value[h]/10;
                    value[h]=value[h]%10;
                }
                h++;
                carry=carry2;
                a--;
            }

            if(h>0 && a<=1)
            {
                value[h]=carry;

                if(value[h]>=10)
                {
                    value[h+1]=value[h]/10;
                    value[h]=value[h]%10;
                }
            }

            a--;
        }
        h=0;
        carry=0;
    }

    cout<<n<<"!=";

    for(int b=99;b>-1;b--)
    {
        if(value[b]!=0)
        {
            flag=1;
        }

        if(flag==1)
        {
            if(b==3 || b==7 || b==11 || b==15 || b==19 || b==23 || b==27 || b==31 || b==35 || b==39 || b==43 || b==47 || b==51 || b==55 || b==59 || b==63)
            {
                cout<<",";
            }
            cout<<value[b];
        }
    }

}
