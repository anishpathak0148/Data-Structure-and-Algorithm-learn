#include<iostream>
#define MAX 10
using namespace std;
class MinStack
{
public:
    int top1,top2,a[MAX],b[MAX];
    MinStack()
    {
        top1=-1;
        top2=-1;
    }
    bool isEmpty()
    {
        if(top1==-1)
            return true;
        else
            return false;
    }
    void push(int x)
    {
        if(top1!=MAX-1)
        {
            top1++;
            a[top1]=x;
            if(top2==-1)
            {
                top2++;
                b[top2]=x;
            }
            else if(a[top1]<b[top2])
            {
                top2++;
                b[top2]=x;
            }
        }
    }
    void pop()
    {
       if(!isEmpty())
       {
           cout<<"\nPop element is:"<<a[top1];
           if(a[top1]==b[top2])
           {
               top2--;
           }
           top1--;
       }
    }
    void minimum()
    {
        cout<<"\nMinimum element is:"<<a[top2]<<endl;
    }
    void display()
    {
        if(!isEmpty())
        {
            cout<<"\nCurrent element in the stack is :-"<<endl;
            for(int i=top1;i>=0;i--)
                cout<<"\t"<<a[i];
        }
        else
            cout<<"\nStack is Empty.";
    }
};
main()
{
    int item,ch;
    MinStack s;
    while(1)
    {
        cout<<"\n1. Push or Insert";
        cout<<"\t2. Pop or Delete";
        cout<<"\t3. Display";
        cout<<"\t4. Minimum Element";
        cout<<"\t5. Exit";
        cout<<"\nEnter your choice :";
        cin>>ch;

      switch(ch)
      {
      case 1:
        cout<<"\nEnter item :";
        cin>>item;
        s.push(item);
        break;
      case 2:
        s.pop();
        break;
      case 3:
        s.display();
        break;
      case 4:
        s.minimum();
        break;
      case 5:
        return(0);
      default:
        cout<<"Invalid choice";
      }
    }
}
