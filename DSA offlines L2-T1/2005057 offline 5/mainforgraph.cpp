#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<queue>
#include "graphoffline.cpp"
using namespace std;
int main()
{

    ifstream in("input.txt");
    string str;
    int c=0;
    int u,v;
    getline(in,str);
    istringstream s(str);
    int n,m;
    s>>n;
    s>>m;
    Graph<int> g(n,m);
    while(c!=m)
    {
        getline(in,str);
        istringstream sa(str);
        sa>>u;
        sa>>v;
        g.adjacency_list[u].pushBack(v);
        c++;
    }
    getline(in,str);
    istringstream sa(str);
    int source;
    sa>>source;
    g.set_source(source);
    g.bfsshow();
    g.dfs();
    g.print();


}

