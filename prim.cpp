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
#include "fibonacci.cpp"


    
class graph_alg{
vector<node1* > v;int time; 
vector<pair<pair<int,int> ,int> > gmatrix;
vector<node1* > mst;
fib_heap *fh;
public:
      graph_alg(int n,fib_heap gg){fh=&gg;v.resize(n,null);time=0;}

      node1* getelement(int i){return v[i];}

 
void make_graph_matrix(){
     get_data();
     cout<<endl<<"Enter no of edges ";int temp;cin>>temp;
     for(int i=0;i<temp;i++){
             int temp1,temp2,temp3;
             cout<<"Enter starting vertex , ending vertex and edge cost ";OP;
             cin>>temp1>>temp2>>temp3;
             gmatrix.push_back(make_pair(make_pair(temp1,temp2),temp3));
             }//for dinish
     }//make graph matrix finish

void l(string s){cout<<s;OP;}

pair<vector<node1* >,int> prim_MST(){
     if(v.empty()){cout<<"empty graph";return make_pair(mst,0);}
     v[0]->ds=0;
     for(int i=0;i<v.size();i++){
             fh->fib_insert(v[i]);
             }//for finsh
                   int t_cost=0;               
    
     while(!fh->empty()){
                         node1 *x=fh->get_min()->data;
                         fh->fib_extract_min();
                         mst.push_back(x);
                          
                          t_cost+=x->ds;
        
          
                         for(list<pair<node1* ,int> > :: iterator it=x->child.begin();it!=x->child.end();it++){
                                          
                                              if((*it).first->present && (*it).second<(*it).first->ds){
                                                                      (*it).first->pd=x;
                                                                      node* tr=(node* )(*it).first->fb;
                                                                        fh->fib_decrease_key(tr,(*it).second);
                                                                      }//fi
                                              }//for finish
                         
                         }//while finish
   // */                     
     return make_pair(mst,t_cost);
     }//prim mst finish 
     
void make_graph(){
     get_data();
     for(int i=0;i<v.size();i++){

     cout<<"enter no. of edges connected to "<<(i)<<"th vertex,index and the edge cost";OP;
             int temp1;cin>>temp1;
             for(int j=0;j<temp1;j++){
                      int temp2,temp3;cin>>temp2>>temp3;;
                      make_link(i,temp2,temp3);
                     }
             }
     }//make arbitrary graph

void make_link(int i,int j,int k){
     v[i]->child.push_back(make_pair(v[j],k));
     }//make link finish

node1* make_node(){
     node1* temp=new node1;
     temp->ds=INF;
     temp->pd=null;
     return temp;
     }//make node1 finish

node1* make_index(int i){
       
       node1* temp=make_node();
       temp->index=i;
       return temp;
}//make index finsh

void get_data(){
     cout<<"enter "<<v.size()<<" vertices value";OP;
     for(int i=0;i<v.size();i++){
             v[i]=make_index(i);
             }
     }//get data finish

};
int main(){
    cout<<"Enter No of vertices";OP;
    fib_heap fh;
    int n;cin>>n;
    graph_alg ga(n,fh);
    ga.make_graph();
    pair<vector<node1* >,int> temp=ga.prim_MST();
    cout<<"path: ";
    for(int i=0;i<temp.first.size();i++)cout<<temp.first[i]->index<<"->";
    OP;cout<<" total cost is "<<temp.second;
    OP;
    OP;SP;
    }
/*
9
14
2 1 4 7 8
3 0 4 7 11 2 8
4 1 8 8 2 5 4 3 7
3 2 7 5 14 4 9
2 3 9 5 10
4 6 2 2 4 3 14 4 10
3 7 1 8 6 5 2
4 0 8 1 11 8 7 6 1
3 2 2 6 6 7 7
*/
