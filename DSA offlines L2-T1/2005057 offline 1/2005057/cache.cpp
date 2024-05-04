#include<iostream>
#include<fstream>
#include<sstream>
#include "LinkedLists.cpp"
//#include "Arrayimplement.cpp"
using namespace std;

template <class X,class Y>
class Cachedata
{
    X key;
    Y value;

public:


    void setkey(X key)
    {
        this->key=key;
    }
    void setvalue(Y value)
    {
        this->value=value;
    }
    X getkey()
    {
        return key;
    }
    Y getvalue()
    {
       return value;
    }
};

template <class X,class Y>
class LRUCache
{
   //MyList<Cachedata<X,Y>>l=MyList<Cachedata<X,Y> >(20,100);
   MyList<Cachedata<X,Y>>l;
   Cachedata<X,Y> c;
   Cachedata<X,Y> y;
   int capacity;
public:
    LRUCache(int capacity)
    {

        this->capacity=capacity;
    }
   X get(X key)
    {
        int cp=l.currPos();
        int counts=0;
        while(counts<=l.size()-1)
        {

            if(l.getValue().getkey()==key)
               {


                    X val=l.getValue().getvalue();
                    y=l.getValue();
                    l.erase();
                    l.setToPos(0);
                    l.push(y);

                    return val;

               }

               counts++;
               l.setToPos(counts);

        }
                   l.setToPos(cp);
                   return -1;



    }
    void put(X key,Y value)
    {

        c.setkey(key);
        c.setvalue(value);
       if(l.size()<capacity)
        {

          l.push(c);

        }
        else if(l.size()>=capacity)
        {

              l.setToEnd();
              l.erase();
              l.setToPos(0);
              l.push(c);

        }

    }
};
int main()
{

    ifstream in("lru_input.txt");
    ofstream out("lru_output.txt");
    int si,x,ch,k,val;
    string s1,s2,s3;
    getline(in,s1);
    istringstream s(s1);
    s>>si;
    LRUCache<int,int> b(si);
    getline(in,s2);
    istringstream c(s2);
    c>>x;
    while(x!=0)
    {
        getline(in,s3);
        istringstream v(s3);
        v>>ch;
        if(ch==2)
        {
            v>>k;
            v>>val;
            b.put(k,val);
        }
        else if(ch==1)
        {
            v>>k;
            out<<b.get(k)<<"\n";
        }
        x--;
    }





}
