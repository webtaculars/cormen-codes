#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define null NULL
using namespace std;

struct node{
       int data;
       int height;
       node* left;
       node* right;
       node* parent;
       };


class AVL_Tree{
      node* root,*nil;
      public:
      AVL_Tree(){nil=new node;nil->data=null;nil->left=null;nil->right=null;nil->parent=nil;nil->height=0;root=nil;}
            
         node* make_node(int a){
               node* temp=new node;
               temp->data=a;
               temp->height=1;
               temp->left=nil;
               temp->right=nil;
               temp->parent=nil;
              return temp; 
               }
         
         void Left_Rotate(node *p){
           
      node *y=p->right;
      y->parent=p->parent;
           
           if(p->parent!=nil){if(p==(p->parent->left)){y->parent->left=y;}else{y->parent->right=y;}}
           else{root=y;}
        p->right=y->left;
        if(p->right!=nil) p->right->parent=p;
        y->left=p;
        p->parent=y;   
        p->height=max(p->left->height,p->right->height)+1;
        y->height=max(y->left->height,y->right->height)+1;
           
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
        
        p->height=max(p->left->height,p->right->height)+1;
        y->height=max(y->left->height,y->right->height)+1;
           }//right rotate close  
        
        
          void AVL_Tree_Insert(int a){ root=AVL_Tree_Inser(root,a);}
            
         node* AVL_Tree_Inser(node* p,int a){
              if(p==nil){
			  	p=make_node(a);
                return p;
                         }
              if(a<p->data){
                          p->left=AVL_Tree_Inser(p->left,a);
                          p->left->parent=p;
                          p->height=p->left->height+1;
                            }
              else{
                   p->right=AVL_Tree_Inser(p->right,a);
                          p->right->parent=p;
                          p->height=p->right->height+1;
                  }  
              p=AVL_Tree_Balance(p);                  
              return p;      
              }//avl insert finish
            
           node* AVL_Tree_Balance(node* p){
                
                if(1>=(int)fabs(p->left->height-p->right->height)){cout<<"yes";return p;}
                if(p->left->height>p->right->height){node* y=p->left;
                                                     if(y->right->height>y->left->height){
                                                                                       Left_Rotate(y);   
                                                                                          }
                                                     Right_Rotate(p);
                                                     p=p->parent;
                                                     }
                else{
                     node* y=p->right;
                                                     if(y->left->height>y->right->height){
                                                                                       Right_Rotate(y);   
                                                                                          }
                                                     Left_Rotate(p);
                                                     p=p->parent;
                     
                     
                     }
                     
                  return p;   
                } // avl balance finish
      
       void Preorder_walk(node *p){
           if(p!=nil){ 
                       cout<<" "<<p->data<<" ";
                       Preorder_walk(p->left);
                       Preorder_walk(p->right);
                       }
           }//preorder walk finish
     
     node* get_root(){return root;}
      
      };




int main(){
    AVL_Tree at;
    int myint;
    do{
        cin>>myint;
        at.AVL_Tree_Insert(myint);
         at.Preorder_walk(at.get_root());cout<<endl<<"\n";
        }
        while(myint!=10);
    
    cout<<endl;system("pause");
    return 0;
    }
