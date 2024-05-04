#include<iostream>
using namespace std;
template <class T>
class Queue
{
public:
    Queue *front,*temp,*rear,*next;
    T data;
    int l,c;
    Queue()
    {
      l=0;
      c=0;
    }
    void enque(T item)
    {

        if(l==0)
        {
            Queue *newq=new Queue();
            newq->next=NULL;
            newq->data=item;
            front=rear=newq;
            l++;

        }
       /* else
        {
             Queue *newq=new Queue();
             newq->next=NULL;
             newq->data=item;
             rear->next=newq;
             rear=newq;*/
        else
        {

              rear=front;
              Queue *temp2=new Queue();
              temp2->data=item;
              temp2->next=NULL;
              while(rear->next!=NULL)
              {
                rear=rear->next;
              }

               rear->next=temp2;
               //top++;
               l++;

          }

       // }
       // l++;
    }
    T deque()
    {
        if(l>0)
       {
           if(l==1)
        {
            T d=front->data;
            delete(front);
            front=NULL;
            rear=NULL;
            l--;
            return d;
        }
        else{
        Queue *temp=front;
        T d=front->data;
        front=front->next;
        delete(temp);
        temp=NULL;
        l--;
        return d;
        }

       }
    }
    int length()
    {
        return l;
    }
    void clear()
    {
        Queue *temp=front;
        while(temp!=NULL)
        {
            temp=temp->next;
            delete(front);
            front=temp;
        }
        l=0;
    }
    bool empty()
    {
       if(l==0)
       {
           return true;
       }
       return false;
    }
    T frontValue()
    {
        if(l>0)
        return front->data;
    }
    T rearValue()
    {
        if(l>0){
            Queue *temp=front;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            return temp->data;
        }

    }
    T leaveQueue()
    {
        if(l!=0){
        if(l==1)
        {
            T data=front->data;

            delete(front);
            rear=front=NULL;
            l--;
            return data;

        }
        else{
        Queue *temp=front;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        T data=temp->next->data;
        rear=temp;
        delete(temp->next);
        temp->next=NULL;
        l--;
        return data;
        }
        }
    }

};
