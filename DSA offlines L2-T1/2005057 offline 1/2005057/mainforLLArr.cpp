#include<iostream>
#include<fstream>
#include<sstream>
#include "LinkedLists.cpp"
//#include "Arrayimplement.cpp"


ofstream out("list_output.txt");
void print(MyList<int> a)
{
        int j=0;
        a.temp=a.head;
        out<<"<"<<" ";
        while(a.temp!=NULL)
        {
            if(j==a.currPos())
            {
                out<<"|"<<" ";
            }
            out<<a.temp->data<<" ";
            j++;
            a.temp=a.temp->nexts;
           // cout<<p<<endl;

        }
        out<<">"<<endl;
}
/*void print(MyList<int> a)
    {
        out<<"< ";
        for(int j=0;j<a.size();j++)
        {
            if(j==a.curpos)
            {
                out<<"|"<<" ";
            }
            out<<a.p[j]<<" ";
        }
        out<<" >"<<endl;
    }*/

int main()
{
    ifstream in("list_input.txt");
    string str1,str2;
    int g[2];
    getline(in,str1);
    istringstream s(str1);
    int x,i=0;
    while(s>>x)
    {
        g[i]=x;
        i++;


    }
    int l=g[0];
    int li=g[1];
    int b[l],j=0,d,e;
    MyList<int> a;  //Linked List !st constructor
   // MyList<int>a(l,li); //Array 1st constructor
    getline(in,str2);
    istringstream s2(str2);
    while(s2>>x)
    {
       b[j]=x;
       j++;
    }

    for(int i=0;i<l;i++)
    {
        a.pushBack(b[i]);  //For First Constructor,comment for 2nd constructor
    }
   // MyList<int>a(l,b);  //Linked List 2nd constructor
   // MyList<int>a(l,li,b); // Array 2nd constructor
     print(a);
    in>>x;
   while(x!=0)
    {
        in>>d>>e;
        if(d==1)
        {

        print(a);
        out<<a.size()<<"\n";

        }
        else if(d==2)
        {
            a.push(e);

        print(a);
        out<<-1<<"\n";
        }
         else if(d==3)
        {
            a.pushBack(e);

        print(a);
        out<<-1<<"\n";
        }
         else if(d==4)
        {
            int h=a.erase();

        print(a);
        out<<h<<"\n";
        }
         else if(d==5)
        {
            a.setToBegin();

        print(a);
        out<<-1<<"\n";
        }
         else if(d==6)
        {
            a.setToEnd();

        print(a);
        out<<-1<<"\n";
        }
         else if(d==7)
        {
            a.prev();

        print(a);
        out<<-1<<"\n";
        }
         else if(d==8)
        {
            a.next();

        print(a);
        out<<-1<<"\n";
        }
         else if(d==9)
        {
           int v= a.currPos();

        print(a);
        out<<v<<"\n";
        }
         else if(d==10)
        {
            a.setToPos(e);

        print(a);
        out<<-1<<"\n";
        }
         else if(d==11)
        {
           int v= a.getValue();

        print(a);
        out<<v<<"\n";
        }
         else if(d==12)
        {
           int m= a.find(e);

        print(a);
        out<<m<<"\n";
        }
         else if(d==13)
        {
            a.clear();

        print(a);
        out<<-1<<"\n";
        }
        x--;
    }
}
