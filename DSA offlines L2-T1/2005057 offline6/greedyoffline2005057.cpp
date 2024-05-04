#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
using namespace std;
ofstream out("output.txt");
class Service
{
public:

    vector<pair<int,int>>store;
    vector<pair<int,int>>result;
    int cus_no;
    Service(int no)
    {
        cus_no=no;
    }
    static bool sorting(pair<int,int>&a,pair<int,int>&b)
    {

        if(a.second==b.second)
        {
            return a.first<b.second;
        }
        return a.second<b.second;

    }
    void maximum_service()
    {
        sort(store.begin(),store.end(),sorting);

        int min_start,min_end;
        result.push_back({store[0].first,store[0].second});
        min_end=store[0].second;

        for(int i=1; i<store.size(); i++)
        {
            if(store[i].first>=min_end)
            {
                result.push_back(store[i]);
                min_end=store[i].second;
            }
        }

    }
    void print()
    {
        out<<result.size()<<"\n";
        for(auto it:result)
        {
            out<<it.first<<" "<<it.second<<"\n";
        }
    }
};
/*int main()
{
    ifstream in("input.txt");
    string str;
    int no;
    getline(in,str);
    istringstream s(str);
    s>>no;
    Service sc(no);
    for(int i=0; i<no; i++)
    {
        getline(in,str);
        int b,e;
        istringstream s(str);
        s>>b;
        s>>e;
        sc.store.push_back({b,e});
    }
    sc.maximum_service();
    sc.print();




}*/
