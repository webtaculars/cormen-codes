#include<iostream>
#include<vector>
#include<string>
#define null NULL
#define black true
#define red false

using namespace std;

struct node{
       
       int data;
       bool color;
       node *left;
       node *right;
       node *parent;
             
       };

class Red_Black_Tree{
      
      node *root,*nil;
      public:
             Red_Black_Tree(){nil=new node;nil->data=null;nil->left=null;nil->right=null;nil->parent=null;root=nil;}
        
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
        
        
      void Red_Black_Insert(int a){
           
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
           temp->color=red;
           if(temp->parent==nil){root=temp;}
           else{
                if(a<y->data){ y->left=temp; }else{y->right=temp;}}
     Redify(temp);
           }//red black insert close
     
      void Redify(node *p){
           
           node *z=p;
           while(z!=nil && z->parent!=nil&& z->parent->parent!=nil && z->parent->color==red){
                    
                    if(z->parent->parent->left==z->parent){ //cout<<"\nparent left\n";
                                                           if(z->parent->parent->right!=nil && z->parent->parent->right->color==red){
                                                                                //case 1                    
                                                                                 z->parent->color=black;
                                                                                 z->parent->parent->right->color=black;
                                                                                 z=z->parent->parent;                   
                                                                                 z->color=red;                   
                                                                                //cout<<"\nparent right red\n";       
                                                                                             }//case 1 finishh
                                                           else{
                                                                                //case 2
                                                                                if(z==z->parent->right){Left_Rotate((z=z->parent));
                                                                                //cout<<"\nself right\n";
                                                                                }
                                                                                //case 3
                                                                                //cout<<"\nself left\n";
                                                                                 z->parent->color=black;
                                                                                 z->parent->parent->color=red;
                                                                                 Right_Rotate(z->parent->parent);
                                                                
                                                                }//case 2 and 3 ends
                                                             }  // first left if finish  
                         
                        else{
                             
                             if(z->parent->parent->left!=nil && z->parent->parent->left->color==red){
                                                                                //case 1                    
                                                                                 z->parent->color=black;
                                                                                 z->parent->parent->left->color=black;
                                                                                 z=z->parent->parent;                   
                                                                                 z->color=red;                   
                                                                                                    }//case 1 finishh
                                                           else{
                                                                                //case 2
                                                                                if(z==z->parent->left){Right_Rotate((z=z->parent));}
                                                                                //case 3
                                                                                 z->parent->color=black;
                                                                                 z->parent->parent->color=red;
                                                                                 Left_Rotate(z->parent->parent);
                                                                
                                                                }//case 2 and 3 ends
                             
                             }//else close 
                         
                         }//while close
           root->color=black;
           }     // Redify finish
           
       node* get_root(){return root;}
       
       node* Red_Black_Minimum(node *p){if(p->left!=nil){return Red_Black_Minimum(p->left);}else{ return p;}}//red black minimun clccose
    
    
     node* Red_Black_Succesor(node* p){
           
           if(p->right!=nil){return Red_Black_Minimum(p->right);}
           node *y=p;
           while(y!=nil && y==(y->parent)->right){ y=y->parent;  }
           return (y==nil?nil:y->parent);
           }//red black succesor cllose
      
       
       
       void Red_Black_Delete(node* p){
            
            node* x=nil,*y=nil;
            if(p->left==nil ||p->right==nil){y=p;}else{y=Red_Black_Succesor(p);}
            if(y->left!=nil){x=y->left;}else{x=y->right;}
            x->parent=y->parent;
            
            if(y->parent==nil){root=x;}
            else{if(y==y->parent->left){x->parent->left=x;}else{x->parent->right=x;}}
            if(y!=p){p->data=y->data;}
            if(y->color==black){Delete_Redify(x);}
            }//red black delete finish
    
      void Delete_Redify(node* p){
           
           node* w=nil;
           
           while(p!=root && p->color==black){
                         
                         if(p->parent->left==p){
                                                w=p->parent->right;
                                                //case 1
                                                if( w->color==red ){w->color=black;w->parent->color=red;Left_Rotate(w->parent);
                                                w=p->parent->right;}
                                                //case 1 ends
                                                else{
                                                     //case 2
                                                     if(w->left->color==black && w->right->color==black){
                                                                              
                                                                              w->color=red;
                                                                              p=p->parent; 
                                                                              }//case 2 ends
                                                     
                                                     else {//case 3
                                                          if(w->left->color==red && w->right->color==black){w->color=red;
                                                          w->left->color=black;Right_Rotate(w);w=p->parent->right;}
                                                          //case 4
                                                     w->color=p->parent->color;p->parent->color=black;w->right->color=black;Left_Rotate(w->parent);p=root;
                                                     }//case 3 4 ensd
                                                     }//else finish
                                                
                                                
                                                }//if finish
                         else{
                              w=p->parent->left;
                              //case 1
                              if(w->color==red){w->parent->color=red;w->color=black;Right_Rotate(p->parent);w=p->parent->left;}
                              //case 1 ends
                              else{//case 2
                                   if(w->left->color==black && w->right->color==black){
                                           w->color=red;p=p->parent;                 
                                                            
                                                            }//case 2 ends
                                   else{
                                        //case 3
                                        if(w->right->color==red && w->left->color==black){w->color=red;w->right->color=black;
                                        Left_Rotate(w);
                                        w=p->parent->left;}
                                        //case 4
                                        w->color=w->parent->color;w->parent->color=black;w->left->color=black;Right_Rotate(w->parent);p=root;
                                        //case 3 and 4 ends
                                        }
                                   
                                   }
                              
                              } 
                         
                         
                         }//while fingish
           
           p->color=black;
           
           } //delete redify finish       
      
       void Inorder_walk(node *p){
           if(p!=nil){ 
                       Inorder_walk(p->left);
                       cout<<" "<<p->data<<" ";
                       Inorder_walk(p->right);
                       }
           }//inorder walk finish
     
     void Preorder_walk(node *p){
           if(p!=nil){ 
                       cout<<" "<<p->data<<" ";
                       Preorder_walk(p->left);
                       Preorder_walk(p->right);
                       }
           }//preorder walk finish
     
      
      
      
      };

int main(){
   
    Red_Black_Tree rbt;
    
     int myint;
    do{
        cin>>myint;
        rbt.Red_Black_Insert(myint);
         rbt.Preorder_walk(rbt.get_root());cout<<endl<<"\n";
        }
        while(myint!=42);
    
    rbt.Inorder_walk(rbt.get_root());cout<<endl<<"k1\n";
    rbt.Red_Black_Delete(rbt.get_root());
     rbt.Preorder_walk(rbt.get_root());cout<<endl<<"k2\n";
    rbt.Red_Black_Delete(rbt.get_root());
     rbt.Preorder_walk(rbt.get_root());cout<<endl<<"3\n";
    rbt.Red_Black_Delete(rbt.get_root());
         rbt.Preorder_walk(rbt.get_root());cout<<endl<<"\n";
    cout<<endl;system("pause");
    return 0;
    }
