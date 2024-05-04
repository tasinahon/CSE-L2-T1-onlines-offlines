#include<iostream>
#include<fstream>
#include<sstream>
#include "llbasedstack.cpp"
#include "llbasedqueue.cpp"
//#include "Arraybasedstack.cpp"
//#include "Arrbasedqueue.cpp"
using namespace std;
ofstream out("output_file.txt");
void prints(Stack<int> a)
{
        int j=0;
        a.temp=a.head;
        out<<"<"<<" ";
        while(a.temp!=NULL)
        {
            if(j==a.top)
            {
                out<<"|"<<" ";
            }
            out<<a.temp->data<<" ";
            j++;
            a.temp=a.temp->next;


        }
        out<<">"<<endl;
}
void printq(Queue<int> a)
{
    int j=0;
    a.temp=a.front;
    out<<"<"<<" ";
     while(a.temp!=NULL)
        {
            if(j==0)
            {
                out<<"|"<<" ";
            }
            out<<a.temp->data<<" ";
            j++;
            a.temp=a.temp->next;

        }
        out<<">"<<endl;
}
/*void printq(Queue<int> &a)
{
    if(a.front==-1 && a.rear==-1)
    {
        out<<"<"<<" "<<">";
        out<<endl;
    }
    else{
    out<<"<";
    for(int i=a.front;i<a.rear+1;i++)
    {
        if(i==a.front)
        {
            out<<"|";
        }
        out<<a.p[i]<<" ";
    }
    out<<">";
    out<<endl;
    }
}
void prints(Stack<int> &a)
    {
        out<<"< ";
        for(int j=0;j<a.length();j++)
        {
            if(j==a.top)
            {
                out<<"|"<<" ";
            }
            out<<a.p[j]<<" ";
        }
        out<<" >"<<endl;
    }*/
int main()
{
    ifstream in("in.txt");
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
    int b[l],j=0,d,e,k=0;
   // Queue<int> a(l,li);//queue for array
    Queue<int>a;     //queue for linked list
    getline(in,str2);
    istringstream s2(str2);
    while(s2>>x)
    {
       b[j]=x;
       j++;
    }

    for(int i=0;i<l;i++)
    {
        a.enque(b[i]);
    }

    getline(in,str2);
    istringstream s3(str2);
    int m=0;
    while(s3>>x)
    {
        g[m]=x;
        m++;
    }
    int sl=g[0];
    int sli=g[1];
    //Stack<int>st(sl,sli);//stack for array
    Stack<int>st;   // stack for linked list
    getline(in,str2);
    istringstream s4(str2);
    int sar[sl];
     while(s4>>x)
    {
       sar[k]=x;
       k++;
    }
    for(int i=0;i<sl;i++)
    {
        st.push(sar[i]);
    }
     printq(a);
     prints(st);

    in>>x;
   while(x!=0)
    {
        in>>d>>e;
        if(d==1)
        {
          a.clear();
          printq(a);
          out<<-1<<"\n";


        }
        else if(d==2)
        {
            a.enque(e);

            printq(a);
            out<<-1<<"\n";


        }
         else if(d==3)
        {
            int t=a.deque();

            printq(a);
            out<<t<<"\n";


        }
         else if(d==4)
        {
            int h=a.length();

            printq(a);
            out<<h<<"\n";


        }
         else if(d==5)
        {
            int x=a.frontValue();

            printq(a);
            out<<x<<"\n";


        }
         else if(d==6)
        {
            int y=a.rearValue();

           printq(a);
           out<<y<<"\n";


        }
         else if(d==7)
        {
            int y=a.leaveQueue();
            printq(a);
            out<<y<<"\n";




        }
         else if(d==8)
        {
            st.clear();

            prints(st);
            out<<-1<<"\n";


        }
         else if(d==9)
        {
            st.push(e);

            prints(st);
            out<<-1<<"\n";


        }
         else if(d==10)
        {
            int v=st.pop();

            prints(st);
            out<<v<<"\n";


        }
         else if(d==11)
        {
           int v= st.length();

           prints(st);
           out<<v<<"\n";


        }
         else if(d==12)
        {
           int m= st.topValue();

           prints(st);
           out<<m<<"\n";


        }

        x--;
    }
}


