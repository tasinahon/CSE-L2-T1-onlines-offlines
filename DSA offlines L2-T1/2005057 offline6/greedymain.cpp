#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include "greedyoffline2005057.cpp"
int main()
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




}
