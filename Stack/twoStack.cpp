#include<iostream>
using namespace std;
#define MAX 10
class twoStacks
{
    public:
        int top1,top2,a[MAX];
        twoStacks()
        {
            top1=-1;
            top2=MAX;
            for(int i=0;i<MAX;i++)
                a[i]=0;
        }
        bool isEmpty()
        {
            if(top1==-1 && top2==MAX)
                return true;
            else
                return false;

        }
        bool isFull()
        {
            if((top1==MAX-1 && top2==0) || top2-top1==1)
                return true;
            else
                return false;
        }
        void push1(int x)
        {
            if(!isFull())
            {
                top1++;
                a[top1]=x;
            }
            else
                cout<<"\nOverflow.";
        }
        void push2(int x)
        {
            if(!isFull())
            {
                top2--;
                a[top2]=x;
            }
            else
                cout<<"\nOverflow";
        }
        void pop1()
        {
            if(!isEmpty())
            {
                cout<<"\nPop element is:"<<a[top1];
                top1--;
            }
            else
                cout<<"\nUnderflow.";
        }
        void pop2()
        {
            if(!isEmpty())
            {
                cout<<"\nPop element is:"<<a[top2];
                top2++;
            }
            else
                cout<<"\nUnderflow.";
        }
        void display()
        {
            if(!isEmpty())
            {
                cout<<"\nElement in twoStack is (if 0 show then it indicate that these positions are empty in twoStack):"<<endl;
                for(int i=0;i<MAX;i++)
                    cout<<"\t"<<a[i];
            }
            else
                cout<<"\nStack is Empty";
        }
};
main()
{
    int ch,item
    ;
    twoStacks s;
    while(1)
    {
        cout<<"\n1. Push in Stack1";
        cout<<"\t2. Pop from Stack1";
        cout<<"\n3. Display";
        cout<<"\n4. Push in Stack2";
        cout<<"\t5. Pop from Stack2";
        cout<<"\t6. Exit";
        cout<<"\nEnter your choice :";
        cin>>ch;

      switch(ch)
      {
      case 1:
        cout<<"\nEnter item :";
        cin>>item;
        s.push1(item);
        break;
      case 2:
        s.pop1();
        break;
      case 3:
        s.display();
        break;
      case 4:
        cout<<"\nEnter item :";
        cin>>item;
        s.push2(item);
        break;
      case 5:
        s.pop2();
      case 6:
        return(0);
      default:
        cout<<"Invalid choice";
      }
    }
}
