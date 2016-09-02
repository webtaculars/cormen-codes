#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define null NULL
using namespace std;

struct node{
       int data;
       int priority;
       node* left;
       node* right;
       node* parent;
       };

class Treap{
      node* root,*nil;
      public:
             Treap(){nil=new node;nil->data=null;nil->left=null;nil->right=null;nil->parent=nil;nil->priority=0;root=nil;}
      
      void Left_Rotate(node *p){
           
      node *y=p->right;
      y->parent=p->parent;
           
           if(p->parent!=nil){if(p==(p->parent->left)){y->parent->left=y;}else{y->parent->right=y;}}
           else{root=y;}
        p->right=y->left;
        if(p->right!=nil) p->right->parent=p;
        y->left=p;
        p->parent=y;   
           
           }//left rotate close  
        
      void Right_Rotate(node *p){
           //cout<<" p right "<<p<<endl;
      node *y=p->left;
      y->parent=p->parent;
           
           if(p->parent!=nil){if(p==(p->parent->left)){y->parent->left=y;}else{y->parent->right=y;}}
           else{root=y;}
        p->left=y->right;
        if(p->left!=nil)p->left->parent=p;
        y->right=p;
        p->parent=y;   
        
          }//right rotate close  
        
        
      
      
      
      void Treap_Insert(int a){
           
           node *x=root,*y=nil;
           while(x!=nil){
                          y=x;
                          if(x->data>a){x=x->left;}
                          else{x=x->right;}
                          }
           node *temp=new node;
           temp->data=a;
           temp->left=nil;
           temp->right=nil;
           temp->parent=y;
           temp->priority=rand();
           if(temp->parent==nil){root=temp;}
           else{
                if(a<y->data){ y->left=temp; }else{y->right=temp;}}
           
           
      x=temp;
      
      while(x!=root && x->priority<x->parent->priority){
                    if(x==x->parent->left){Right_Rotate(x->parent);}
                    else{Left_Rotate(x->parent);}
                    }
                    }//treap insert finish         
  
  
  node* Treap_Minimum(node *p){if(p->left!=nil){return Treap_Minimum(p->left);}else{ return p;}}//treapS minimun clccose
        

 node* Treap_Succesor(node* p){
           
           if(p->right!=nil){return Treap_Minimum(p->right);}
           node *y=p;
           while(y!=nil && y==(y->parent)->right){ y=y->parent;  }
           return (y==nil?nil:y->parent);
           }//treap succesor cllose
      

void Treap_Delete(node* p){
     
            node *y=nil;
            if(p->left==nil || p->right==nil){y=p;}
            else{y=Treap_Succesor(p);}
            node* x=nil;
            if(y->left!=nil){ x=y->left; }
            else{x=y->right;}
            
                     x->parent=y->parent;
             
            if(y->parent==nil){
                                root=x;
                                }
            else{
                if(y==(y->parent)->left){(y->parent)->left=x;} 
                 else{(y->parent)->right=x;}
                 }
              
            if(y!=p){p->data=y->data;}  
     }//treap delete
     
     node* get_root(){return root;}
     
     
       void Preorder_walk(node *p){
           if(p!=nil){ 
                       cout<<" "<<p->data<<" ";
                       Preorder_walk(p->left);
                       Preorder_walk(p->right);
                       }
           }//preorder walk finish
     
     
      };
      
      
int main(){
    
    Treap at;
    int myint;
    do{
        cin>>myint;
        at.Treap_Insert(myint);
         at.Preorder_walk(at.get_root());cout<<endl<<"\n";
        }
        while(myint!=42);
    
    
    cout<<endl;system("pause");
    return 0;
    }
