#include<iostream>
#include<vector>
#include<string>
#include<stack>
#define null NULL
#define black true
#define red false

using namespace std;

struct node{
       
       int data;
       bool color;
       node *left;
       node *right;
                   
       };

class Red_Black_Tree{
      
      node *root,*root1,*nil;stack<node *> stc;
      public:
             Red_Black_Tree(){nil=new node;nil->data=null;nil->left=null;nil->right=null;root=new node;root=nil;}
        
      void Left_Rotate(node *p,node* parent){
           
      node *y=p->right;
      //y->parent=p->parent;
           
          if(parent!=nil){if(p==(parent->left)){parent->left=y;}else{parent->right=y;}}
           else{root=y;}
        p->right=y->left ;
      //  if(p->right!=nil) p->right->parent=p;
        y->left=p;
        //p->parent=y;   
           }//left rotate close  
        
      void Right_Rotate(node *p,node* parent){
           //cout<<" p right "<<p<<endl;
      node *y=p->left;
     // y->parent=p->parent;
           
           if(parent!=nil){if(p==(parent->left)){parent->left=y;}else{parent->right=y;}}
           else{root=y;}
        p->left=y->right;
        //if(p->left!=nil)p->left->parent=p;
        y->right=p;
        //p->parent=y;   
           }//right rotate close  
        
        
      void Red_Black_Insert(int a){
           while(!stc.empty())stc.pop();
           stc.push(nil);
           node *x=root,*y=nil;
           while(x!=nil){
                          y=x;
                          stc.push(y);
                          if(x->data>a){x=x->left;}
                          else{x=x->right;}
                          }
           node *temp=new node;
           temp->data=a;
           temp->left=nil;
           temp->right=nil;
           //temp->parent=y;
           temp->color=red;
           
           if(stc.top()==nil){root=temp;}
           else{
                if(a<y->data){ y->left=temp; }else{y->right=temp;}}
     Redify(temp);
           }//red black insert close
     
      void Redify(node *p){
           node *parent=nil,*parent_parent=nil;
           node *z=p;
          parent=stc.top();stc.pop();
           while(parent->color==red){
                    parent_parent=stc.top();stc.pop();
                    if(parent_parent->left==parent){ //cout<<"\nparent left\n";
                                                           if( parent_parent->right->color==red){
                                                                                //case 1                    
                                                                                 parent->color=black;
                                                                                 parent_parent->right->color=black;
                                                                                 z=parent_parent;                   
                                                                                 z->color=red;
                                                                                 parent=stc.top();stc.pop();                  
                                                                                //cout<<"\nparent right red\n";       
                                                                                             }//case 1 finishh
                                                           else{
                                                                                //case 2
                                                                                if(z==parent->right){node *temp=z;
                                                                                                     z=parent;
                                                                                                     parent=parent_parent;
                                                                                                     Left_Rotate((z),parent);
                                                                                                     parent=temp;
                                                                                //cout<<"\nself right\n";
                                                                                }
                                                                                //case 3
                                                                                //cout<<"\nself left\n";
                                                                                 parent->color=black;
                                                                                 parent_parent->color=red;
                                                                                 node* temp=stc.top();stc.pop();
                                                                                 Right_Rotate(parent_parent,temp);
                                                                
                                                                }//case 2 and 3 ends
                                                             }  // first left if finish  
                         
                        else{
                             
                             if(parent_parent->left->color==red){
                                                                                //case 1                    
                                                                                 parent->color=black;
                                                                                 parent_parent->left->color=black;
                                                                                 z=parent_parent;                   
                                                                                 z->color=red;                   
                                                                                   parent=stc.top();stc.pop();                }//case 1 finishh
                                                           else{
                                                                                //case 2
                                                                                if(z==parent->left){node* temp=z;
                                                                                                    z=parent;
                                                                                                     parent=parent_parent;Right_Rotate(z,parent);
                                                                                                     parent=temp;
                                                                                                     }
                                                                                //case 3
                                                                                 parent->color=black;
                                                                                 parent_parent->color=red;
                                                                                 node* temp=stc.top();stc.pop();
                                                                                 Left_Rotate(parent_parent,temp);
                                                                
                                                                }//case 2 and 3 ends
                             
                             }//else close 
                         
                         }//while close
           root->color=black;
           }     // Redify finish
           
       node* get_root(){return root;}
       
       node* Red_Black_Minimum(node *p){if(p->left!=nil){stc.push(p);return Red_Black_Minimum(p->left);}else{ return p;}}//red black minimun clccose
    
    
     node* Red_Black_Succesor(node* p){
           
           if(p->right!=nil){return Red_Black_Minimum(p->right);}
           node *y=p;
//           while(y!=nil && y==(y->parent)->right){ y=y->parent;  }
  //         return (y->parent);
           }//red black succesor cllose
      
       void Red_Black_Search(node* q,node* p){
            if(q==p){return ;}
            stc.push(q);
            return Red_Black_Search(q->data>p->data?q->left:q->right,p);
            }
       
       void Red_Black_Delete(node* p){
            while(!stc.empty())stc.pop();
           stc.push(nil);
           Red_Black_Search(root,p);
            node* x=nil,*y=nil;
            if(p->left==nil ||p->right==nil){y=p;}else{
                            stc.push(p);
                            y=Red_Black_Minimum(p->right);}
            if(y->left!=nil){x=y->left;}else{x=y->right;}
           // x->parent=y->parent;
            cout<<" x data "<<x->data<<"\n";
            node* parent=stc.top();
            if(parent==nil){root=x;}
            else{if(y==parent->left){parent->left=x;}else{parent->right=x;}}
            if(y!=p){p->data=y->data;}
            if(y->color==black){Delete_Redify(x);}
            }//red black delete finish
    
      void Delete_Redify(node* p){
           
            node* w=nil;node* parent_parent=nil;
            node* parent=stc.top();stc.pop();
            while(p!=root && p->color==black){
                         parent_parent=stc.top();
                         if(parent->left==p){
                                                w=parent->right;
                                                //case 1
                                                if( w->color==red ){w->color=black;parent->color=red;
                                                Left_Rotate(parent,parent_parent);
                                                parent_parent=w;
                                                stc.push(w);
                                                w=parent->right;}
                                                //case 1 ends
                                                else{
                                                     //case 2
                                                     if(w->left->color==black && w->right->color==black){
                                                                              
                                                                              w->color=red;
                                                                              p=parent; 
                                                                              parent=parent_parent;
                                                                              stc.pop();
                                                                              }//case 2 ends
                                                     
                                                     else {//case 3
                                                          if(w->left->color==red && w->right->color==black){
                                                                                 w->color=red;w->left->color=black;Right_Rotate(w,parent);
                                                                                 w=parent->right;}
                                                          //case 4
                                                     w->color=parent->color;parent->color=black;w->right->color=black;
                                                     Left_Rotate(parent,parent_parent);p=root;
                                                     }//case 3 4 ensd
                                                     }//else finish
                                                
                                                
                                                }//if finish
                         else{
                              w=parent->left;
                              //case 1
                              if(w->color==red){parent->color=red;w->color=black;
                              Right_Rotate(parent,parent_parent);
                                                parent_parent=w;
                                                stc.push(w);
                              w=parent->left;}
                              //case 1 ends
                              else{//case 2
                                   if(w->left->color==black && w->right->color==black){
                                           w->color=red;
                                           p=parent; 
                                                                              parent=parent_parent;
                                                                              stc.pop();                 
                                                            }//case 2 ends
                                   else{
                                        //case 3
                                        if(w->right->color==red && w->left->color==black){w->color=red;
                                        w->right->color=black;
                                        Left_Rotate(w,parent);
                                        w=parent->left;}
                                        //case 4
                                        w->color=parent->color;parent->color=black;w->left->color=black;
                                        Left_Rotate(parent,parent_parent);p=root;
                                        //case 3 and 4 ends
                                        }
                                   
                                   }
                              
                              } 
                         
                         
                         }//while fingish
           
           p->color=black;
           
           } //delete redify finish       
//     */ 
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
    
  //  rbt.Inorder_walk(rbt.get_root());cout<<endl<<"\n";
    rbt.Red_Black_Delete(rbt.get_root());
    cout<<"\nk 1\n";
         rbt.Preorder_walk(rbt.get_root());cout<<endl<<"\n";
    rbt.Red_Black_Delete(rbt.get_root());
    cout<<"\nk 2\n";
         rbt.Preorder_walk(rbt.get_root());cout<<endl<<"\n";
    rbt.Red_Black_Delete(rbt.get_root());
    cout<<"\nk 3\n";
         rbt.Preorder_walk(rbt.get_root());cout<<endl<<"\n";
    cout<<endl;system("pause");
    return 0;
    }
