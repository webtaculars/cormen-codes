#include<iostream>
#include<cmath>
#include<list>
#include<stack>
#include<bitset>
#include<vector>
#include<string>
#include<algorithm>
#include <new>
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
       int index;
       node* pd; //predecesor
       list<pair<node* ,int> > child; // child
       int ds;  //distance
       };

class graph_alg{
      vector<node* > v;

      public:
      graph_alg(int n){v.resize(n,null);}
      
node* getelement(int i){return v[i];}

void relax(int index_v,int cost,node* u){

   if(v[index_v]->ds>u->ds+cost){
                                 v[index_v]->ds=u->ds+cost;v[index_v]->pd=v[u->index];}

}//relax finish

bool cycle_check(int index_v,int cost,node* u){

   if(v[index_v]->ds>u->ds+cost){return false;}
return true;
}//cycle check finish

void copy_node(node* a,node* b){
        a->ds=b->ds;
        a->index=b->index;}//copy node finish

bool bellman_ford(node* source){

source->ds=0;
vector<node* > a;
for(int i=0;i<v.size();i++){
        node* temp=new node;
      temp->ds=v[i]->ds;
      temp->index=i;
      temp->pd=null;
      //  copy_node(temp,v[i]);
        a.push_back(temp);
        }
for(int k=0;k<v.size()-1;k++){
         
for(int i=0;i<v.size();i++){
         
            for(list<pair<node* ,int> >:: iterator it=v[i]->child.begin();it!=v[i]->child.end();it++){
                       
                     relax((*it).first->index,(*it).second,a[i]);
                      
                    }//inner for
   }//middle for
   
 for(int i=0;i<v.size();i++){
        a[i]->ds=v[i]->ds;
        }  
}//outer for
        
for(int i=0;i<v.size();i++){
         
            for(list<pair<node* ,int> >::iterator  it=v[i]->child.begin();it!=v[i]->child.end();it++){
                      
                if(!cycle_check((*it).first->index,(*it).second,v[i]))return false;

                    }//inner for
   }//outer for

 a.clear();   
return true;
}//bellman ford finish

void make_graph(){
     get_data();
     for(int i=0;i<v.size();i++){

     cout<<"enter no. of edges connected to "<<(i)<<"th vertex and index";OP;
             int temp1;cin>>temp1;
             for(int j=0;j<temp1;j++){
                      int temp2,temp3;cin>>temp2>>temp3;
                      make_link(i,temp2,temp3);
                     }
             }
     }//make arbitrary graph

void make_link(int i,int j,int k){
     v[i]->child.push_back(make_pair(v[j],k));
     }//make link finish

node* make_node(int data){
     node* temp=new node;
     temp->index=data;
     temp->pd=null;
     temp->ds=INF;
     return temp;
     }//make node finish

void get_data(){
     cout<<"enter "<<v.size()<<" vertices value";OP;
     for(int i=0;i<v.size();i++){
             v[i]=make_node(i);
             }
     }//get data finish


      };


int main(){
    int n; 
    cin>>n;
    graph_alg ga(n);
    ga.make_graph();
    if(ga.bellman_ford(ga.getelement(n-1)))
    cout<<"no cycle";
    else cout<<"cycle is present"; OP;
    cout<<" the new ds is";OP;
    for(int i=0;i<n;i++)
    cout<<ga.getelement(i)->ds<<endl;
    OP;
    SP;
    }

/*
5
2 1 6 3 7
3 3 8 2 5 4 -4
1 1 -2
2 2 -3 4 9
2 2 7 0 2
*/


