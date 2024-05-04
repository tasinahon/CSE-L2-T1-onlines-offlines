#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
template <class X>
class MyList
{
public:

    X data;
    MyList *nexts;
    MyList *head,*temp,*p;
    int i,k,curpos;


    MyList()
    {



        i=0;
        curpos=0;

    }
    MyList(int k,X a[])
    {
       i=0;
       curpos=0;
       for(int j=0;j<k;j++)
       {
           pushBack(a[j]);
       }

    }

    void pushBack(X data)
    {

       if(i==0)
        {
             head=new MyList();
            head->data=data;
            head->nexts=NULL;
             temp=head;
             p=head;

        }

        else
        {
             p=head;
       MyList *temp2=new MyList();
       temp2->data=data;
       temp2->nexts=NULL;
       while(p->nexts!=NULL)
       {
           p=p->nexts;
       }

      p->nexts=temp2;

        }
        i++;

    }
    void push(X item)
    {
       if(curpos==0)
       {
           MyList *newn=new MyList();
           newn->data=item;
           newn->nexts=NULL;
           MyList *m=head;
           head=newn;
           head->nexts=m;
           i++;

       }
       else if(curpos==size()-1)
       {
           MyList *t=head;
           while(t->nexts!=NULL)
           {
               t=t->nexts;

           }
            MyList *newn=new MyList();
                newn->data=item;
                newn->nexts=NULL;
                t->nexts=newn;
                i++;

       }
       else
       {

           int li=curpos;
           MyList *t=head;
           MyList *newn=new MyList();
           newn->data=item;
           newn->nexts=NULL;

           while(li!=1)
           {
              t=t->nexts;
              li--;
          }

           newn->nexts=t->nexts;
           t->nexts=newn;
           i++;

       }
    }
    void setToPos(int pos)
    {
        curpos=pos;

    }

    int size()
    {
        return i;
    }
    void clear()
    {
        i=0;
        MyList *t=head;
        while(t!=NULL)
        {
            t=t->nexts;
            delete(head);
            head=t;
        }
        curpos=-1;

    }
    X erase()
    {

    if(i!=0)
    {

       MyList *pre,*cur;
       pre=head;
       cur=head;
       if(curpos==0)
       {

           head=cur->nexts;
           X kj=cur->data;
           delete(cur);
           cur=NULL;
           i--;
           return kj;
       }
      else
       {


           int li=curpos+1;
           while(li!=1)
           {
               pre=cur;
               cur=cur->nexts;
               li--;
           }
           pre->nexts=cur->nexts;
           X kj=cur->data;
           delete(cur);
           cur=NULL;
           i--;
           if(curpos==size())
        {
           curpos--;
       }

           return kj;
       }
    }


    }
    void setToBegin()
    {
        curpos=0;

    }
    void setToEnd()
    {
        curpos=size()-1;

    }
    void prev()
    {
        if(curpos!=0)
        {
            curpos=curpos-1;
        }

    }
    void next()
    {
        if(curpos!=i-1)
        {
            curpos=curpos+1;
        }

    }
    int currPos()
    {
        return curpos;
    }
    int find(X item)
    {
        int c=-1;
        MyList *p=head;
        while(p!=NULL)
        {
            c++;

            if(p->data==item)
            {

                return c;
               break;
            }

            p=p->nexts;
        }
        return -1;


    }
    X getValue()
    {

        int c=0;
        MyList *t=head;
        while(c!=curpos)
        {
            t=t->nexts;
            c++;
        }
        return t->data;
    }



};
