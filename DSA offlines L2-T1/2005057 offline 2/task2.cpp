#include<iostream>
#include<fstream>
#include<sstream>
#include "llbasedqueue.cpp"
#include "llbasedstack.cpp"
using namespace std;
class gamerinfo
{
    public:
    int starttime;
    int duration;
    int total,f,id;
    gamerinfo()
    {

    }
    gamerinfo(int x,int y)
    {
        starttime=x;
        duration=y;
        f=0;

    }
    int totals()
    {
        total=starttime+duration;
        return total;
    }
    void setid(int no)
    {
        id=no;
    }
    int getid()
    {
        return id;
    }

};
int f1=0,f2=0;
int main()
{
    ofstream out("output_task2.txt");
    ifstream in("input_task2.txt");
    int x,y,a[100],j=0,bs[10];
    Queue<gamerinfo>q;
    Stack<gamerinfo>s;
    int sa,d;
    string str1,str2;
    getline(in,str1);
    istringstream str(str1);
    str>>sa;
    str>>d;
    getline(in,str2);
    istringstream strr(str2);
    strr>>x;
    strr>>y;
    gamerinfo c1(x,y);
    int time=c1.totals();
    c1.setid(1);
    a[j]=time;
    j++;
    int time2,f1=1,f2=0,l=0,man=0,flag=0;
    int count=0,c=0,i=2,b=0;
    while(b!=sa-1){
            int x,y;
            string newstr;
            getline(in,newstr);
            istringstream sf(newstr);
            sf>>x;
            sf>>y;
            gamerinfo c2(x,y);
            c2.setid(i++);

     if(q.length()==3 && c==0 && c2.starttime<time) //stack er 1st person,l=1,m=1
    {


            if(c2.totals()<=d){
            a[c2.getid()-1]=c2.totals();
            time2=c2.totals();
            }
            else
            {
                a[c2.getid()-1]=d;
                time2=d;
            }
            l=1;

            c++;
    }
    if(q.length()<3 && c2.starttime<time)  //kom time r count check cz kom time hoilao queue full thakle stack a jaite hbe
    {

        if(c2.starttime<time)
        {

            if(count<3)
            {

                q.enque(c2);
                flag=0;
                count++;
            }
        }

    }

    else if(c2.starttime>=time)
        {

            if(q.length()!=0)
            {
                if(q.frontValue().duration+time<=d){
                      a[q.frontValue().getid()-1]=q.frontValue().duration+time;
                      time=time+q.frontValue().duration;
                }
                else
                {
                   a[q.frontValue().getid()-1]=d;
                   time=d;
                }
               count--;
               j++;
               q.deque();
               q.enque(c2);
               f2=1;
            }
            else    //jodi length 0 hoi and or time beshi thake tkhn or start and end time + hbe
            {
                if(c2.duration+c2.starttime<=d){
                   a[c2.getid()-1]=c2.duration+c2.starttime;
                   time=c2.duration+c2.starttime;
                }
                else
                {
                  a[c2.getid()-1]=d;
                  time=d;
                }
            }



        }



    if(c2.starttime<time2 && man==1 && flag!=0 && f2!=1)  //nijer kom time hoile to w8 krbei
        {

            s.push(c2);

        }
    else if(c2.starttime>time2 && man==1 && f2!=1)   //jodi dkhe or ager joner agei sesh hoise taile
        {

               if(s.length()==0)      //0 length hoile to nijei dhukbe
               {
                    if(c2.duration+c2.starttime<=d){
                   a[c2.getid()-1]= c2.duration+c2.starttime;
                   time2=c2.duration+c2.starttime;
                    }
                    else
                    {
                        a[c2.getid()-1]=d;
                        time2=d;
                    }
               }
               else if(s.topValue().duration+time2<=d){    //na hoile amn hoite pare stack theke aker odhik khelte pare tai while
                  while(time2<c2.starttime){
                       a[s.topValue().getid()-1]= s.topValue().duration+time2;
                       time2=s.topValue().duration+time2;
                       s.pop();

                }

                s.push(c2);
                }
              else
                {
                a[s.topValue().getid()-1]=d;
                time2=d;
                s.pop();
                s.push(c2);
                }

         }
    else if(c2.starttime==time2 && man==1 && f2!=1)
         {
            if(c2.duration+time2<=d){
               a[c2.getid()-1]= c2.duration+time2;
               time2=c2.duration+time2;
            }
            else
            {
               a[c2.getid()-1]=d;
               time2=d;
            }
         }


        if(l==1)
        {
            man=1;
        }
        b++;
        flag=1;
        f2=0;

    }



    while(s.length()!=0)
    {

        if(s.topValue().duration+time2<=d){
            if(s.topValue().starttime<=time2){

             a[s.topValue().getid()-1]=s.topValue().duration+time2;
             time2=s.topValue().duration+time2;
            }
             else
             {
                 a[s.topValue().getid()-1]=s.topValue().starttime+s.topValue().duration;
                 time2=s.topValue().starttime+s.topValue().duration;
             }
        }
        else
        {
           a[s.topValue().getid()-1]=d;
           time2=d;
        }
        s.pop();
    }
    while(q.length()!=0)
    {
        if(q.frontValue().duration+time<=d){

                if(q.frontValue().starttime<=time){
             a[q.frontValue().getid()-1]=q.frontValue().duration+time;
             time=q.frontValue().duration+time;
                }
                else
                {
                      a[q.frontValue().getid()-1]=q.frontValue().duration+q.frontValue().starttime;
                      time=q.frontValue().duration+q.frontValue().starttime;
                }
        }
        else
        {
            a[q.frontValue().getid()-1]=d;
            time=d;
        }
        q.deque();
    }

    for(int i=0;i<sa;i++)
    {
        out<<i+1<<" "<<">"<<" "<<a[i]<<endl;
    }


}
