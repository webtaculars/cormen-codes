#include<iostream>
#include<cmath>
#include<list>
#include<stack>
#include<utility>
#include<bitset>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include <map>
#define INF (1<<30)
#define null NULL
#define fi(sz) for(int i=0;i<sz;i++)
#define fj(sz) for(int j=0;j<sz;j++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define SP system("pause");
#define OP cout<<endl
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

struct node1{
       list<pair<node1* ,int> > child; // prim node child
       int index;//vertex index
       int ds;//prim dista
       node1* pd;//predecessor
       bool present;
       int fb;
       };

struct node{
node1* data;
int deg;
bool mark;
list<node* > child;//fibnacci child
node* sib;
node* prev;
node* parent;
            };


class fib_heap{
      node* min;int num;list<node* > root;
      public:

      fib_heap(){num=0;min=null;}

     void fib_consolidate(){

                        int yl=log10(num*num)/log10(2);yl=yl*yl+1;
                        node* ss=null;
          vector<node* > v(yl,ss);
          while(!root.empty()){
                      node* x=root.front();
                      root.pop_front();
                      int degree=x->deg;
                      while(v[degree]!=null){
                              node* y=v[degree];
                              if(x->data->ds>y->data->ds){
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
                  if(v[i]!=null){root.push_back(v[i]);
                                 if(min==null || v[i]->data->ds<min->data->ds){min=v[i];  }
                                 }
                  }

          }//conso finish


     void swap(node* &x,node* &y) {

          node* temp=x;
          x=y;
          y=temp;
          }//swap finish

      node* get_min(){return min;}//get min finsh

      void fib_extract_min(){

           node* z=min;

           if(z!=null){
                      z->data->present=false;
                      while(!z->child.empty()){
                                               node *temp=z->child.front();
                                               z->child.pop_front();
                                               fib_insert_ii(temp);
                                               root.push_back(temp);
                                               }
                      {
                       node* prev=z->prev;
                       node* next=z->sib;
                       prev->sib=next;
                       next->prev=prev;
                       min=next;
                       root.remove(z);
                       }

                       if(z==z->sib){min=null;}
                       else{

                             fib_consolidate();  }
                      num-=1;
                       z->data->present=false;
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
          root.push_back(x);
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

          if(x->data->ds<k){cout<<"greater key error"; return ;}
          x->data->ds=k;
          node* y=x->parent;

          if(y!=null && y->data->ds > x->data->ds){
                     cut(x,y);
                     cascading_cut(y);
                     }

          if(x->data->ds<min->data->ds){min=x;}

          }//decrease key finish

      void fib_delete(node* x){
           int p=min->data->ds-1;
           fib_decrease_key(x,p);
           fib_extract_min();
           }//fib delete finish

     bool empty(){if(min==null)return true;return false;};

     node* make_node(node1 *pp){
           node* temp=new node;
           temp->data=pp;
           temp->deg=0;
           temp->mark=false;
           temp->parent=null;
           temp->prev=null;
           temp->sib=null;
           temp->data->present=true;
           temp->data->fb=(int)temp;
        return temp;
           }//make node finish

     void fib_insert(node1 *pp){
           node* p=make_node(pp);
          fib_insert_ii(p);
          if(min==null || min->data->ds>p->data->ds){min=p;}
          root.push_back(p);
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
                return  root;}
      };

