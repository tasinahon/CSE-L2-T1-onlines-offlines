#include<iostream>
using namespace std;
template <class T>
class Stack
{
    public:
    Stack *head,*temp,*next,*p;
    T data;
    int curpos,l,c,top;
    Stack()
    {
        l=0;
        top=-1;
        c=0;
    }
    void push(T item)
    {
        if(c==0)
        {

            head=new Stack();
            head->data=item;
            head->next=NULL;
            temp=head;
            top++;
            l++;

        }
        else
        {

              p=head;
              Stack *temp2=new Stack();
              temp2->data=item;
              temp2->next=NULL;
              while(p->next!=NULL)
              {
                p=p->next;
              }

               p->next=temp2;
               top++;
               l++;

          }

           c++;
        }


    T pop()
    {
    if(l!=0)
    {

        if(l==1)
        {


            T d=head->data;
            delete(head);
            head=NULL;
            l--;
            c=0;
            top=-1;
            return d;
        }
        else{
        Stack *p=head;
        int s=l-1;
        while(s!=1)
        {
            p=p->next;
            s--;
        }
        Stack *x=p->next;
        T va=x->data;
        p->next=NULL;
        delete(x);
        x=NULL;
        top--;
        l--;
        return va;
        }

    }
    }
    void clear()
    {

         Stack *temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            delete(head);
            head=temp;
        }
        l=0;
        c=0;
        top=-1;
    }
    T topValue()
    {
        if(l!=0){
        Stack *p=head;
        int index=0;
        while(index!=top)
        {
            p=p->next;
            index++;
        }
        return p->data;
        }
    }
    int length()
    {
        return l;
    }

};
