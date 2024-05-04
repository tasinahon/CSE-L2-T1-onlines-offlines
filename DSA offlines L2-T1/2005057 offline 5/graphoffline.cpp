#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<queue>
#include "LinkedLists.cpp"
#include "llbasedqueue.cpp"
using namespace std;
ofstream out("output.txt");
template<class T>
class Graph
{
public:
    MyList<int>*adjacency_list;
    vector<int>*adj;
    int *visited;
    int n,m,j,k;
    int source;
    int *store_dfs;
    vector<pair<int,int>>store_bfs_tree;
    vector<pair<int,int>>store_dfs_tree;
    Queue<int>Q;
    int *stores_bfs;
    vector<int>store_bfs;
    Graph(int n,int m)
    {
        this->n=n;
        this->m=m;
        adj=new vector<int>[n+1];
        visited=new int[n+1];
        stores_bfs=new int[n+1];
        for(int i=0;i<n;i++)
        {
            stores_bfs[i]=0;
        }
        for(int i=0;i<=n;i++)
        {
            visited[i]=0;
        }
        store_dfs=new int[n+1];
        k=0;

    }

    void set_source(int source)
    {
        this->source=source;
    }
    void bfsshow()
    {

        bfs(source);
         for(int i=0;i<n;i++)
        {
            adjacency_list[i].curpos=0;
        }
    }
    void bfs(int data)
    {

        Q.enque(data);
        visited[data]=1;
        k=0;
        while(!Q.empty())
        {

            int data=Q.frontValue();
            store_bfs.push_back(data);
            stores_bfs[k]=data;
            k++;
            Q.deque();

           while(adjacency_list[data].curpos!=adjacency_list[data].i)
            {
                int r=adjacency_list[data].getValue();
                adjacency_list[data].curpos++;
                if(!visited[r])
                {
                    Q.enque(r);
                    store_bfs_tree.push_back({data,r});
                    visited[r]=1;
                }
            }
        }
    }

    void dfs()
    {
      for(int i=0;i<=n;i++)
        {
            visited[i]=0;
        }
        j=0;
        dfsshow(source);
        for(int i=0;i<n;i++)
        {
            adjacency_list[i].curpos=0;
        }
    }
    void dfsshow(int data)
    {
        visited[data]=1;
        store_dfs[j]=data;
        j++;

         while(adjacency_list[data].curpos!=adjacency_list[data].i)
            {
                int r=adjacency_list[data].getValue();
                adjacency_list[data].curpos++;
                if(!visited[r])
                {
                    visited[r]=1;
                    store_dfs_tree.push_back({data,r});
                    dfsshow(r);
                }
            }

    }
    void print()
    {
        out<<"Breadth-First-Search"<<"\n"<<"\n";
        out<<"Set of vertices:"<<"\n";
        for(int i=0;i<k;i++)
        {
            out<<store_bfs[i]<<" ";
        }
        out<<"\n"<<"\n";
        out<<"Set of edges:"<<"\n";
        for(auto it:store_bfs_tree)
         {
            out<<"("<<it.first<<"-->"<<it.second<<")"<<"\n";
         }
         out<<"\n"<<"\n";
         out<<"Depth-First-Search"<<"\n"<<"\n";
         out<<"Set of vertices:"<<"\n";
        for(int i=0;i<j;i++)
        {
            out<<store_dfs[i]<<" ";
        }
        out<<"\n"<<"\n";
        out<<"Set of edges:"<<"\n";

        for(auto it:store_dfs_tree)
        {
            out<<"("<<it.first<<"-->"<<it.second<<")"<<"\n";
        }
    }
};

