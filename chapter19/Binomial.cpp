#include<iostream>
#include<cmath>
#include<list>
#include<stack>
#include<bitset>
#include<vector>
#include<string>
#include<algorithm>
#include <map>

#define null NULL
#define fi(sz) for(int i=0;i<sz;i++)
#define fj(sz) for(int j=0;j<sz;j++) 
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define SP system("pause")
#define OP cout<<endl
using namespace std;

struct node{

int data;
int deg;
list<node* > child;
node* sib;
node* prev;
node* parent;
};

bool myfunc(node* a,node* b){return a->deg<b->deg;}

class binomial_heap{
      node* head;
      
      public:
             
             
             
             binomial_heap(){head=null;}
             
             void binomial_link(node* x,node* y){x->parent=y;
             if(y->child.empty()){x->sib=null;}
             else{
             x->sib=y->child.front();
             y->child.front()->prev=x;
             }
             x->prev=null;
             y->child.push_front(x);
             y->deg+=1;
             }//link finish
             
             void binomial_union(node* h1,node* h2){
                  vector<node *>temp;
                  node *t=h1;
                  
                  while(t!=null){
                                 temp.pb(t);
                                 t=t->sib;
                                 }
                                t=h2; 
                  while(t!=null){
                                 temp.pb(t);
                                 t=t->sib;
                                 }
                  sort(all(temp),myfunc);               
                 
                 
                 
                 for(int i=0;i<temp.size();i++){
                         if(i==0){
                                  temp[i]->prev=null;
                                }
                               else  temp[i]->prev=temp[i-1];
                                
                                  if(i+1<temp.size())
                                  temp[i]->sib=temp[i+1];
                                  else
                                  temp[i]->sib=null;
                                     }
                   if(temp.empty())return ;                  
                 head= temp[0];temp.clear();
                                 node *x=head;
                           node *next=x->sib;      
                              node* prevx=null;
                              while(next!=null){
                                                if((x->deg!=next->deg) || (next->sib!=null && x->deg==next->sib->deg)){
                                                                       prevx=x;
                                                                       x=next;
                                                                       }//if case 1 close
                                                else{
                                                     if(x->data<=next->data){
                                                                          x->sib=next->sib;
                                                                          binomial_link(next,x);
                                                                          }
                                                     else{
                                                          if(prevx==null){head=next;}
                                                          else{prevx->sib=next;}
                                                          binomial_link(x,next);
                                                          x=next;
                                                          }
                                                     }
                                                next=x->sib;
                                                }//while finish   
                          }//union finish
      
      node* gethead(){return head;}
      
      node* binomial_minimum(){
            int min=999999;
            node* x=head;node* y=null;
            while(x!=null){if(x->data<min){min=x->data;y=x;}x=x->sib;}
            return y;
            }//binomial minimum
      
      node* binomial_insert(int dat){
            node* temp=new node;
            temp->data=dat;
            temp->deg=0;
            temp->prev=null;
            temp->sib=null;
            temp->parent=null;
            binomial_union(head,temp);
            }//binomial insert finish
      
      void binomial_extract_min(){
        node* x=binomial_minimum();
        node* prevx=x->prev;
        node* next=x->sib;
        if(x!=head)
        prevx->sib=next;
        else head=x->sib;
   
   //cout<<"head  "<<head->sib->data;OP;
        next->prev=prevx;
        node* head2;
        node* temp1=x->child.back();
        if(x->child.empty()){temp1=null;}
        head2=temp1;
        while(!x->child.empty()){
                    temp1->parent=null;             
                   x->child.pop_back();
                   if(!x->child.empty()){
                   node* temp2=x->child.back();
                   temp1->sib=temp2;
                   if(temp2!=null){temp2->prev=temp1;           
                              temp1=temp2;}
                             } }
           if(temp1!=null){temp1->sib=null;temp1->parent=null;}
           
           binomial_union(head,head2);
           
           }
      
      void swap(node* a,node* b){int temp=a->data;a->data=b->data;b->data=temp;}
      
      void binomial_decrease_key(node* x,int data){
           
           if(data>x->data){cout<<"wrong entry";OP;return ;}
           x->data=data;
           node* z=x->parent;node* y=x;
           while(z!=null && z->data>y->data){
                         
                         swap(y,z);
                         y=z;
                         z=y->parent;
                         }
           }//decrease key finish
      
      void binomial_delete(node* x){
           
           binomial_decrease_key(x,binomial_minimum()->data-1);
              binomial_extract_min();
           node* p=gethead();OP;OP;
    while(p!=null){cout<<p->data;OP;p=p->sib;}
        
           }//delete finish
      
      
      };

int main(){
    int data;binomial_heap bh;
    do{cin>>data;bh.binomial_insert(data);}while(data!=18);
    binomial_heap bh1;
    do{cin>>data;bh1.binomial_insert(data);}while(data!=12);
    bh.binomial_union(bh.gethead(),bh1.gethead());
    
    node* p=bh.gethead();OP;OP;
    while(p!=null){cout<<p->data<<"   "<<p->child.front()->data;OP;p=p->sib;}
       
    OP;    OP;
    bh.binomial_delete(bh.gethead());
      p=bh.gethead();OP;OP;
    while(p!=null){cout<<p->data;OP;p=p->sib;}
    
    OP;OP;
    
    
//  
    OP;SP;
    }
