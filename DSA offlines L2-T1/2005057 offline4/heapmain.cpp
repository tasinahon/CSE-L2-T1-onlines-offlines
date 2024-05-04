#include<iostream>
#include<cmath>
#include<fstream>
#include<sstream>
#include "Minheap.cpp"
using namespace std;
int main()
{

    ifstream in("input.txt");
    ofstream out("output.txt");
    string str;
    int b;
    MinHeap mh;
    while(!in.eof())
    {
        getline(in,str);

        if(str[0]=='I')
        {
            string sd="";
            for(int i=3;i<str.size();i++)
              {
                 sd+=str[i];
              }
            istringstream s(sd);
            s>>b;
            mh.Insert(b);
            out<<"INSERTED"<<" "<<b<<"\n";

        }
        else if(str[0]=='F')
        {
            out<<"FindMin returned"<<" "<<mh.FindMin()<<"\n";
        }
        else if(str[0]=='E')
        {

            out<<"ExtractMin returned"<<" "<<mh.ExtractMin()<<"\n";

        }
        else if(str[0]=='D')
        {

            string store="";
            int prev,newk;
           for(int i=3;i<str.size();i++)
           {
               store+=str[i];
           }
           istringstream s(store);
           s>>prev;
           s>>newk;
           mh.DecreaseKey(prev,newk);
           out<<prev<<" "<<"decreased to"<<" "<<newk<<"\n";
        }
        else if(str[0]=='P')
        {
            out<<mh.print();
        }
    }

}
