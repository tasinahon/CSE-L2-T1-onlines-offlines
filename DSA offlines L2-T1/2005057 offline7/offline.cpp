#include<iostream>
#include<vector>
using namespace std;
class count_inversion
{
public:
    int* input_array;
    vector<int>temp;
    vector<pair<int,int>>s;
    int len;
    int count;
    count_inversion(int l)
    {
        len=l;
        input_array=new int[len];
        count=0;
    }
    void mergeing()
    {
        cout<<sort_and_count(input_array,0,len-1)<<endl;

    }
    int sort_and_count(int input_array[],int left,int right)
    {
        int count_left=0;
        int count_right=0;
        int count_merge=0;

        if(left<right)
        {
            int mid=(left+right)/2;
            count_left=count_left+sort_and_count(input_array,left,mid);
            count_right=count_right+sort_and_count(input_array,mid+1,right);

            count_merge=count_merge+count_in(input_array,left,mid,right);
        }
        return count_left+count_right+count_merge;
    }
    int count_in(int input_array[],int left,int mid,int right)
    {

       int store[len];
       int a=left;
       int b=mid+1;
       int i=left;
       int k=left;
       int c=0;
       while(a<=mid && b<=right)
       {

           if(input_array[a]<=input_array[b])
           {

               store[i]=input_array[a];
               i++;
               a++;

           }
           else
           {

               store[i]=input_array[b];
               i++;
               b++;
               c=c+((mid+1)-a);
           }

       }
       if(a>mid){


       while(b<=right)
       {
            store[i]=input_array[b];
            i++;
            b++;

       }
       }
       else
       {
          while(a<=mid){

           store[i]=input_array[a];
           i++;
           a++;
       }
       }


       for(int j=k;j<=right;j++)
       {
           input_array[j]=store[j];

       }

       return c;
    }
    void print()
    {
     for(int i=0;i<len;i++)
     {
         for(int j=i+1;j<len;j++)
         {
             if(temp[i]>temp[j])
             {
                 s.push_back({temp[i],temp[j]});
             }
         }
     }
     cout<<"The inverted pairs are:"<<" ";
     for(auto it:s)
     {
         cout<<"("<<it.first<<","<<it.second<<")"<<",";
     }

    }

};
int main()
{
    int l,data;
    cin>>l;
    count_inversion in(l);
    for(int i=0;i<l;i++)
    {
        cin>>data;
        in.input_array[i]=data;
        in.temp.push_back(data);
    }
    in.mergeing();
    in.print();

}
