#include<iostream>
#include<cmath>
#include<list>
#include<stack>
#include<bitset>
#include<vector>
#include<string>
#include<algorithm>
#include <map>
#include<utility>
#define null NULL
#define fi(sz) for(int i=0;i<sz;i++)
#define fj(sz) for(int j=0;j<sz;j++) 
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define SP system("pause");
#define OP cout<<endl
using namespace std;

struct node{

int data;
int deg;
bool mark;
list<node* > child;
node* sib;
node* prev;
node* parent;
            };


class fib_heap{
      node* min;int num;
      public:
     
      fib_heap(){num=0;min=null;}
     
     void fib_consolidate(){
          node* it1=min;node* it2=min->prev;
          list<node* > l;
          int max_degree=0;
          
                  
          while(true){
                      l.push_back(it1);
                      if(max_degree<it1->deg){max_degree=it1->deg;}
                      if(it1==it2)break;
                      it1=it1->sib;
                      
                      }
                     
                        max_degree+=1;
                        int yl=max_degree*l.size()+1;
                        node* ss=null;
          vector<node* > v(yl,ss);
          while(!l.empty()){
                      node* x=l.front();
                      l.pop_front();
                      int degree=x->deg;
                      while(v[degree]!=null){
                              node* y=v[degree];
                             
                              
                              if(x->data>y->data){
                                                  swap(x,y);                    
                                                  }
                             fib_link(y,x);
                              v[degree]=null;
                              degree+=1;
                              }//inner while finish
                          v[degree]=x;
                          
                      }//while finish
          min=null;
          
          for(int i=0;i<v.size();i++){
                  if(v[i]!=null){
                                 if(min==null || v[i]->data<min->data){min=v[i];  }         
                                 }
                  }
          
          }//conso finish 
     
      
     void swap(node* &x,node* &y) {
           
          node* temp=x;
          x=y;
          y=temp;
          }//swap finish
       
      
      void fib_extract_min(){
             
           node* z=min;
                      
           if(z!=null){
                      
                      while(!z->child.empty()){
                                               cout<<"err ";OP;
                                               node *temp=z->child.front();
                                               z->child.pop_front();
                                               fib_insert_ii(temp);
                                               }
                      { node* prev=z->prev;
                       node* next=z->sib;
                       prev->sib=next;
                       next->prev=prev;
                       min=next;
                       }
                       
                       if(z==z->sib){min=null;}
                       else{ 
                            
                             fib_consolidate();  }
                      num-=1;
                       }
           }//fin extract min 
      
      void fib_link(node* z,node* y){
             node* prev=z->prev;
                       node* next=z->sib;
                       prev->sib=next;
                       next->prev=prev;
                       z->parent=y;
                       if(!y->child.empty()){
                       z->sib=y->child.front();
                       y->child.front()->prev=z;
                       z->prev=y->child.back();
                       y->child.back()->sib=z;
                       }else{z->sib=null;z->prev=null;}
                       z->mark=false;
                    y->child.push_front(z);
                    y->deg+=1;   
           }//fib link close
      
     void cut(node* x,node* y){
          y->child.remove(x);
          fib_insert_ii(x);
          x->mark=false;
          }//cut finish
      
     void cascading_cut(node* y){
          node* z=y->parent;
          if(z!=null){
                      if(!y->mark){y->mark=true;}
                      else{
                           cut(y,z);
                           cascading_cut(z);
                           }
                      }
          }//ccut finish 
      
     void fib_decrease_key(node* x,int k){
          
          if(x->data<k){cout<<"greater key error"; return ;}
          x->data=k;
          node* y=x->parent;
          
          if(y!=null && y->data > x->data){
                     cut(x,y);
                     cascading_cut(y);
                     }
          if(x->data<min->data){min=x;}
          }//decrease key finish 
      
      void fib_delete(node* x){
           int p=min->data-1;
           fib_decrease_key(x,p);
           fib_extract_min();
           }//fib delete finish
      
     
    
     node* make_node(int k){
           node* temp=new node;
           temp->data=k;
           temp->deg=0;
           temp->mark=false;
           temp->parent=null;
           temp->prev=null;
           temp->sib=null;
        return temp;   
           }//make node finish 
      
     void fib_insert(int k){
           node* p=make_node(k);
          fib_insert_ii(p);
          if(min==null || min->data>p->data){min=p;}
          num+=1;
          }//fin insert finish 
      
     void fib_insert_ii(node* p){
          node* prev=null;
          if(min!=null){
          prev=min->prev;
          prev->sib=p;
          p->prev=prev;
          min->prev=p;
          p->sib=min;
          }else{p->prev=p;p->sib=p;}
          p->parent=null;
           }//insert ii  finish 
      
     list<node* > gethead(){
                node *it1=min,*it2=min->prev;
                list<node* > l;
                while(true){
                      l.push_back(it1);
                      if(it1==it2)break;
                      it1=it1->sib;
                      }
                return  l;} 
      };
      
      
      
int main ()
{
   int data;fib_heap bh;
    do{cin>>data;bh.fib_insert(data);}while(data!=18);
    //fib_heap bh1;
    //do{cin>>data;bh1.fib_insert(data);}while(data!=12);
    //bh.binomial_union(bh.gethead(),bh1.gethead());
    list<node* > p=bh.gethead();OP;OP;
    while(!p.empty()){cout<<p.front()->data;OP;p.pop_front();}
    OP;
    bh.fib_extract_min();
                             list<node* > pp=bh.gethead();
     OP; bh.fib_decrease_key(pp.front(),1);
                      for(list<node* > :: iterator it=pp.begin();it!=pp.end();it++){cout<<" d "<<(*it)->data;OP;}
           
   
  /*
    bh.fib_extract_min();
    list<node* > p1=bh.gethead();OP;OP;
    while(!p1.empty()){cout<<p1.front()->data;OP;p1.pop_front();}
    OP;
    bh.fib_extract_min();
    list<node* > p2=bh.gethead();OP;OP;
    while(!p2.empty()){cout<<p2.front()->data;OP;p2.pop_front();}
    OP;   
*/
cout<<endl;system("pause");
    return 0;
    }
