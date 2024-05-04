#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
template <class T>
class BST
{

    void preordershow(BST *root,string &spre)
    {
        if(root==NULL)
        {
            return ;
        }
        spre+=to_string(root->data)+" ";
        preordershow(root->left,spre);
        preordershow(root->right,spre);
    }

    void postordershow(BST *root,string &spost)
    {
        if(root==NULL)
        {
            return;
        }
        postordershow(root->left,spost);
        postordershow(root->right,spost);
        spost+=to_string(root->data)+" ";
    }

    void inordershow(BST *root,string &sin)
    {
        if(root==NULL)
        {
            return;
        }

        inordershow(root->left,sin);
        sin+=to_string(root->data)+" ";
        inordershow(root->right,sin);
    }

    public:
    T data;
    BST *left,*right,*root,*temp;
    string str;
    int c,d,i,f;
    BST()
    {
       c=0;
       str="";
       d=0;
       i=0;
       f=0;
       root=NULL;
    }
    string Insert(T data)
    {

     if(c==0)
        {

           root=new BST();
           root->data=NULL;
           root->left=NULL;
           root->right=NULL;
           root->data=data;
           temp=root;
           c++;

        }

    else{
           temp=root;
           BST *newn=new BST();
           newn->data=data;
           newn->left=NULL;
           newn->right=NULL;
        while(temp!=NULL){
          if(data<temp->data)
           {
              if(temp->left==NULL)
                {
                   temp->left=newn;
                   break;

                }
              temp=temp->left;
           }
         else if(data>temp->data)
           {
               if(temp->right==NULL)
                {
                  temp->right=newn;
                  break;
                }
              temp=temp->right;
           }
          }
          c++;
       }
       cout<<c<<endl;


         str="";
         string s=print(root);




         return s;

    }

    string Delete(T data)
    {
      BST *temp1=root;
      BST *p=NULL;
      int f=0;
      string s;
      if(temp1==NULL)
      {
          return "Invalid Operation";
      }

      while(temp1!=NULL)
      {

          if(c==1 && temp1->data==data && temp->left==NULL && temp->right==NULL)
          {
               cout<<data;
               s="";
               c=0;
               d=0;
               root=NULL;
              break;

          }
           if(temp1->data!=data)
          {

              f=1;
          }
          if(data<temp1->data)
          {

              p=temp1;
              temp1=temp1->left;
          }
          else if(data>temp1->data)
          {

              p=temp1;
              temp1=temp1->right;
          }
          else if(data=temp1->data)
          {
             // cout<<c<<endl;
              f=0;
              if(temp1->right==NULL && temp1->left==NULL)
              {

                  if(p->right==temp1)
                  {

                      p->right=NULL;
                  }
                  else if(p->left==temp1)
                  {

                      p->left=NULL;
                  }



                   str="";
                   c--;
                   if(c==1)
                   {
                       d=0;
                   }
                   s=print(root);
                   delete(temp1);





              }
              else if(temp1->right!=NULL || temp1->left!=NULL)
              {
                  s="Invalid Operation";
              }

              break;
          }

      }
      if(f==1)
      {

          s="Invalid Operation";
      }


       return s;
    }

    string Find(T data)
    {
        BST *x=NULL;
       if(root!=NULL){
         x=finditem(root,data);
       }

       if(x==NULL)
       {

           return "False";
       }
       else
       {

           return "True";
       }


    }
    BST* finditem(BST *root,T data)
    {
        if(root==NULL)
        {

            return NULL;
        }
         if(data==root->data)
        {

            return root;
        }

        if(data<root->data)
        {
           return finditem(root->left,data);
        }
        if(data>root->data)
        {
           return finditem(root->right,data);
        }


    }
    string Preorder()
    {

        string spre="";
        preordershow(root,spre);
        return spre;
    }

    string Postorder()
    {
        string spost="";
        postordershow(root,spost);
        return spost;
    }

    string Inorder()
    {
        string sin="";
        inordershow(root,sin);
        return sin;
    }

    string print(BST *root)
    {
        if (root == NULL)
        return "";


    str +=to_string(root->data);


    if(d!=0)
    if (root->left == NULL && root->right == NULL)
        return "";

    if(d==0)
    {
         if (root->left == NULL && root->right == NULL)
            d++;
        return str;
    }


        str += ('(');
        print(root->left);
        str += (')');



        str += ('(');
        print(root->right);
        str += (')');

    return str;
    }


};
