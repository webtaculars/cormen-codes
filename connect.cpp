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
#define INF (1<<30)
#define null NULL
#define fi(sz) for(int i=0;i<sz;i++)
#define fj(sz) for(int j=0;j<sz;j++) 
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define SP system("pause");
#define OP cout<<endl
typedef long long LL;
using namespace std;

struct node{
       int data;
       node* parent;
       int rank;
       };

class graph_alg{
      
      public:
      graph_alg(){}
      
      node* make_set(int data){
            
            node* temp=new node;
            temp->data=data;
            temp->parent=temp;
            temp->rank=0;
            return temp;
            }//make set finish
      
      node* link(node* x,node* y){
            if(x->rank>y->rank){y->parent=x;return x;}
            else{
                 x->parent=y;
                 if(x->rank==y->rank)y->rank+=1;
                 return y;}
            }//link finish
      
      node* union_set(node* x,node* y){return link(find_set(x),find_set(y));}//union finish
      
      node* find_set(node* x){
            if(x!=x->parent)return (x->parent=find_set(x->parent));
            return x;
            }//find set close
      
      };


int main(){
    
    graph_alg ga;
    
    OP;
    SP;
    }

