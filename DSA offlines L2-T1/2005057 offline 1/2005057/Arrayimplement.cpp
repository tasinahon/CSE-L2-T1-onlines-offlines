#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
template <class T>
class MyList
{
public:

    T *p,*t;
    T l;
    int k,maxs,i,curpos,c;
    MyList(int k,int x)
    {
        p=new T[x];
        t=new T[x];
        i=0;
        maxs=x;
        c=0;
        curpos=0;
    }

    MyList(int k,int x,T ar[])
    {

       p=new T[x];
       t=new T[x];
       i=0;
       curpos=0;
       maxs=x;
       c=0;
       for(int j=0;j<k;j++)
       {
           pushBack(ar[j]);
       }
    }
    void pushBack(T data)
    {
        if(i>=maxs){

        memorymanagement();
        }
       p[i]=data;
       i++;


    }
    void push(T item)
    {
        memorymanagement();
        T temp=p[i-1];
        for(int j=size()-1;j>curpos;j--)
        {
            p[j]=p[j-1];
        }
        p[curpos]=item;
        p[i]=temp;
        i++;

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
        curpos=-1;

    }
    T erase()
    {
        T v;
        v=p[curpos];
        for(int j=curpos;j<size();j++)
        {
            p[j]=p[j+1];
        }
        i--;
        if(i<=maxs/2)
        {
            memorydeletion();
        }
        return v;

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
    T getValue()
    {
        return p[curpos];
    }
    int find(T item)
    {
        for(int j=0;j<size()-1;j++)
        {
            if(p[j]==item)
            {
                return j;
                break;
            }
        }
        return -1;
    }
    void memorymanagement()
    {

            for(int j=0;j<i;j++)
            {
                t[j]=p[j];
            }
            p=new T[2*maxs];
            for(int j=0;j<i;j++)
            {
                p[j]=t[j];

            }
            maxs=2*maxs;



    }
    void memorydeletion()
    {

        for(int i=0;i<size();i++)
        {
            t[i]=p[i];
        }
        delete(p);
        maxs=i;
        p=new T[maxs];
        for(int i=0;i<size();i++)
        {
            p[i]=t[i];

        }
    }

};
