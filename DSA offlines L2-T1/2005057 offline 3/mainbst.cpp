#include<iostream>
#include<fstream>
#include<sstream>
#include "offline.cpp"
using namespace std;
int main()
{
    string a,str;
    int b;
    ifstream in("inp.txt");
    ofstream out("out.txt");
    BST<int> bst;

    while(!in.eof())
    {
        getline(in,str);


    if(str[0]!='T')
    {
        string sd="";
        for(int i=2;i<str.size();i++)
        {
            sd+=str[i];
        }
        istringstream s(sd);
        s>>b;


    }
    else if(str[0]=='T')
    {

        if(str[2]=='P'&& str[3]=='o')
        {

            out<<bst.Postorder()<<"\n";
        }
        else if(str[2]=='I')
        {
            out<<bst.Inorder()<<"\n";
        }
        else
        {
            out<<bst.Preorder()<<"\n";
        }
    }
    if(str[0]=='I')
    {

        out<<bst.Insert(b)<<"\n";
    }
    else if(str[0]=='F')
    {
        out<<bst.Find(b)<<"\n";
    }
    else if(str[0]=='D')
    {
        out<<bst.Delete(b)<<"\n";
    }

    }

}
