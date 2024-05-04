#include<iostream>
using namespace std;
template <class T>
class Queue
{
    public:
    T *p,*t;
    int front,rear,in_capa;
    int l,c;
    Queue(int K,int L)
    {
        p=new T[L];
        front=-1;
        rear=-1;
        l=0;
        c=0;
        in_capa=L;
    }
    void enque(T item)
    {
         if(l>=in_capa){

        memorymanagement();
        }
        if(rear<in_capa-1){
        if(l==0){
                front++;
        }
        p[++rear]=item;
        l++;
        }

    }
    T deque()
    {
         if(l<=in_capa/2)
        {
            memorydeletion();
        }
        if(l>0){
        T x;
        if(l==1)
        {
             x=p[front];
             front=-1;
             rear=-1;
             l--;
             return x;
        }
    else {

            x=p[front];
            front++;
            l--;
            return x;

    }
        }

    }
    int length()
    {
        return l;
    }
    T frontValue()
    {
        if(l>0){
        return p[front];
        }
    }
    T rearValue()
    {
        if(l>0)
        {
            return p[rear];
        }
    }
    T leaveQueue()
    {
        if(l>0){
        return p[rear--];
        }
    }
    void clear()
    {
        l=0;
        front=-1;
        rear=-1;
    }
    void memorymanagement()
    {

            t=new T[in_capa];

            for(int j=0;j<l;j++)
            {
                t[j]=p[j];
            }
            p=new T[2*in_capa];
            for(int j=0;j<l;j++)
            {
                p[j]=t[j];

            }
            delete []t;
            in_capa=2*in_capa;

    }
     void memorydeletion()
    {
        //cout<<"L";
        t=new T[l];
        for(int i=0;i<length();i++)
        {
            t[i]=p[i];
        }
        delete(p);
        in_capa=l;
        p=new T[in_capa];
        for(int i=0;i<length();i++)
        {
            p[i]=t[i];

        }
    }




};
