#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
template<class T>
class Stack
{
    public:
    T *p,*t;
    int top,l,in_capa,curpos;

    Stack(int M,int Y)
    {
        top=-1;
        l=0;
        in_capa=Y;
        p=new T[Y];



    }
    void push(T item)
    {

        if(l>=in_capa){

        memorymanagement();
        }
        if(l<in_capa){
        p[++top]=item;
        l++;

        }
    }
    T pop()
    {
        T x;
         if(l<=in_capa/2)
        {
            memorydeletion();
        }
        if(l>0){
            x=p[top];
            p[top--];
            l--;
            return x;

        }

    }
    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }
    T topValue()
    {
        if(l>0){
        return p[top];
        }
    }
    void clear()
    {
        top=-1;
        l=0;

    }
    int length()
    {
        return l;
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
