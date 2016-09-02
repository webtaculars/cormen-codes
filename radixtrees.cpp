#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define null NULL
using namespace std;

struct node{
       
       string data;
       node *left;
       node *right;
                    
       };
       
class Radix_Tree{
    node *root;
      public:
    
      Radix_Tree(){root=new node;root->data="";root->left=null;root->right=null;}
             
      void Radix_Tree_Insert(string str){
           node* p=root;int i=0;
           for(i=0;i<str.length();i++){
                   if(str[i]=='1'){if(p->right==null){node *temp=new node;temp->data="";temp->left=null;temp->right=null;p->right=temp;}
                   if(i==str.length()-1){p->data=str;}
                   p=p->right;}
                   else{if(p->left==null){node *temp=new node;temp->data="";temp->left=null;temp->right=null;p->left=temp;}
                   if(i==str.length()-1){p->data=str;}
                   p=p->left;}
                   }
                   //cout<<"\tst"<<str[i]<<"\n";
              
           }//radix_Insert close
      
     
      node* get_root(){return root;} //get root finish
      
                
      void Preorder_walk(node *p){
           if(p!=null){ 
                     if(p->data!="")
                       cout<<" "<<p->data<<" ";

                       Preorder_walk(p->left);
                     
                       Preorder_walk(p->right);
                       }
           }//preorder walk finish
     
    
      };


int main(){
    
    string myint;Radix_Tree rt;
    do{
        cin>>myint;
        rt.Radix_Tree_Insert(myint);
        }
        while(myint!="0000");
    cout<<"\nkk\n";
    rt.Preorder_walk(rt.get_root());
      cout<<endl;system("pause");
    return 0;
    }
