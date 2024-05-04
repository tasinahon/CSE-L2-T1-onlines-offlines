#include<iostream>
#include<cmath>
#include<fstream>
#include<sstream>
using namespace std;
class MinHeap
{
    int *a;
    int len,count,max_size;
public:
    MinHeap()
    {
        max_size=50;
        a=new int[50];
        len=0;
        count=0;
    }
    ~MinHeap()
    {
        delete(a);
    }
    int left_child(int index)
    {
        return 2*index+1;
    }
    int right_child(int index)
    {
        return 2*index+2;
    }
    int parent(int index)
    {
        return floor((index-1)/2);
    }
    void makeheap(int index)
    {
        int minimum=index;
        int left=left_child(index);
        int right=right_child(index);
        if(left<len)
        {
            if(a[minimum]>a[left])
            {
                minimum=left;
            }
        }
        if(right<len)
        {
            if(a[right]<a[minimum])
            {
                minimum=right;
            }
        }
        if(minimum!=index)
        {
            int temp=a[index];
            a[index]=a[minimum];
            a[minimum]=temp;
            makeheap(minimum);
        }
    }
    void Insert(int key)
    {
        a[len]=key;
        len++;
        count++;
        if(len>max_size)
        {
            int arr[max_size];
            max_size=max_size*2;
            for(int i=0;i<len;i++)
            {
                arr[i]=a[i];
            }
            a=new int[max_size];
            for(int i=0;i<len;i++)
            {
                a[i]=arr[i];
            }

        }
        int i=len-1;
        while(i!=0 && a[parent(i)]>a[i])
        {
            int temp=a[parent(i)];
            a[parent(i)]=a[i];
            a[i]=temp;
            i=parent(i);
        }
    }
    int FindMin()
    {
        if(len!=0){
        return a[0];
        }
        return -1;
    }
    int ExtractMin()
    {
        if(len!=0){
        int r=a[0];
        a[0]=a[len-1];
        len--;
        makeheap(0);
        return r;
        }
        return -1;

    }
    void DecreaseKey(int prevKey,int newKey)
    {
        int x;
        for(int i=0;i<len;i++)
        {
            if(a[i]==prevKey)
            {
                a[i]=newKey;
                x=i;
            }
        }
        while(x!=0 && a[parent(x)]>a[x])
        {
            int temp=a[parent(x)];
            a[parent(x)]=a[x];
            a[x]=temp;
            x=parent(x);
        }

    }
    string print(){
        string str="";
        str+="Printing the binary heap...";
        str+="\n";
        str+="- - - - - - - - - - - - - - - - - - - - - - - - - -";
        str+="\n";
        if(len!=0){
        str+=std::string("Level")+ " " + "0" + ":" +to_string(a[0]);
        }
        int j=1;
       int fp=left_child(0);
       for(int i=1;i<len;i++)
       {
           if(i==fp)
           {
               str+=std::string("\n")+"Level"+" "+to_string(j)+":"+to_string(a[i])+" ";
               fp=left_child(i);
               j++;
           }
           else
           {
               str+=to_string(a[i])+" ";
           }
       }
       str+=std::string("\n")+"- - - - - - - - - - - - - - - - - - - - - - - - - -";
       str+="\n";
       return str;
    }

};

