#include<iostream>
#include<vector>
#include<algorithm>
#define null NULL
using namespace std;

struct node{
       
       int data;
       node *left;
       node *right;
       node *parent;
             
       };
       
class BST{
    node *root,*nil;
      public:
    
      BST(){nil=new node;nil->data=null;nil->left=null;nil->right=null;nil->parent=null;root=nil;}
             
      void BST_Insert(int a){
           
           if(root==nil){
                          node *temp=new node;
                          temp->data=a;
                          temp->left=nil;
                          temp->right=nil;
                          temp->parent=nil;
                          root=temp;
                          //cout<<root->data<<endl;
                          }
           else{
              Recurse_insert(root,a);
                               
                }
           
           }//BST_Insert close
      
      void Recurse_insert(node *x,int key){
           
           if(x->data>key){
		   	if(x->left!=nil){
				Recurse_insert(x->left,key);
				}
			else{
				node *temp=new node;
                temp->data=key;
                temp->left=nil;
                temp->right=nil;
                temp->parent=x;
                x->left=temp;
                }
			}
           else{
		   	if(x->right!=nil){
				Recurse_insert(x->right,key);
				}
			else{
				node *temp=new node;
                temp->data=key;
                temp->left=nil;
                temp->right=nil;
                temp->parent=x;
                x->right=temp;
                          }
			}
           
           }//recurse insert finish
      
      node* get_root(){return root;} //get root finish
      
                
      void Inorder_walk(node *p){
           if(p!=nil){ 
                       Inorder_walk(p->left);
                       cout<<" "<<p->data<<" ";
                       Inorder_walk(p->right);
                       }
           }//inorder walk finish
     
     node* BST_Minimum(node *p){if(p->left!=nil){return BST_Minimum(p->left);}else{ return p;}}//BST minimun clccose
    
     node* BST_Maximum(node *p){if(p->right!=nil)return BST_Maximum(p->right);else return p;}//BST max clccose
    
     node* BST_Succesor(node* p){
           
           if(p->right!=nil){return BST_Minimum(p->right);}
           node *y=p;
           while(y!=nil && y==(y->parent)->right){ y=y->parent;  }
           return (y==nil?nil:y->parent);
           }//bst succesor cllose
      
      
      node* BST_Predecessor(node *p){
            if(p->left!=nil){return BST_Maximum(p->left);}
            
            while(p!=nil && p==(p->parent)->left){p=p->parent;}
            return (p==nil?nil:p->parent);
            }//bst predecessor close
       
      node* BST_Search(node *p,int key){
            
            if(p==nil||p->data==key){return p;}
            if(p->data>key){return BST_Search(p->left,key);}
            else{return BST_Search(p->right,key);}
            
            }//bst search close
      
      void BST_Delete(node* p){
            
            node *y=nil;
            if(p->left==nil || p->right==nil){y=p;}
            else{y=BST_Succesor(p);}
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
          
            }//bst delete finish
      
      };


int main(){
    
    int myint;BST bs;
    do{
        cin>>myint;
        bs.BST_Insert(myint);
        }
        while(myint!=42);
    
    bs.Inorder_walk(bs.get_root());
     
      cout<<endl<<((bs.BST_Maximum(bs.get_root()))->data);
    cout<<endl<<(bs.BST_Succesor(bs.get_root()))->data;
    cout<<endl<<(bs.BST_Predecessor(bs.get_root()))->data;
    bs.BST_Delete(bs.get_root());
    cout<<endl<<"\n";
    bs.Inorder_walk(bs.get_root());
    
    cout<<endl;system("pause");
    return 0;
    }
