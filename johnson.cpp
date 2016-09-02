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
#define INF (1<<26)
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

struct pairs{
       int u;
       int v;
       int cost;
       };
    
class graph_alg{
vector<node1* > v;int time; 
vector<pair<pair<int,int> ,int> > gmatrix;
vector<vector<int>  > ans;
vector<pairs> edge; 
fib_heap *fh;
public:
      graph_alg(int n,fib_heap gg){fh=&gg;v.resize(n,null);time=0;ans.resize(n,vector<int> (n,INF));
      for(int i=0;i<n;i++)ans[i][i]=0;
      }

      node1* getelement(int i){return v[i];}
      int getanswer(int i,int j){return ans[i][j];}
       
void print_vector(vector<node1* > &b){
     OP<<" IN PRINT VECTOR \nvector value :";
     for(int i=0;i<b.size();i++){
     OP<<b[i]->index<<" -> "<<b[i]->ds;
   //   cout<<" child ";
   //  for(list<pair<node1* ,int> > :: iterator it=b[i]->child.begin();it!=b[i]->child.end();it++){
     //            cout<<"  "<<(*it).first->index<<" -> "<<(*it).second;OP;
       //                     }
     }
     OP;
     }//print vector finish

void data_set(int ik,vector<node1* > &vv){
     for(int i=0;i<vv.size();i++){
                                    vv[i]->ds=vv[i]->ds+v[i]->ds-v[ik]->ds;
                                    ans[ik][i]=vv[i]->ds;
             }//outer for finihs
     }//data set finish
 

void johnson_algorithm(){
     
     node1* temp=new node1;temp->ds=0;temp->index=v.size();temp->pd=null;temp->fb=0;
        for(int i=0;i<v.size();i++){temp->child.push_back(make_pair(v[i],0));}
        v.push_back(temp);
          
     if(!bellman_ford(v.back(),v)){
                                       cout<<" contain negative weight cycle";return ;
                                       }//fi
     
    
      v.pop_back();
      
      for(int i=0;i<v.size();i++){
              for(list<pair<node1* ,int> >:: iterator it=v[i]->child.begin();it!=v[i]->child.end();it++){
                                   (*it).second=(*it).second+v[i]->ds-(*it).first->ds;
                                   }//inner for finish
              }//outer for finish
       
      vector<node1* > use=make_copy(v,false);        
      
         for(int i=0;i<use.size();i++){
                 Dijkstra(use[i],use);
      //           print_vector(use);
                 data_set(i,use);
       
                 data_copy(use,v);
                 }
     
     }//johnson finish 

void data_copy(vector<node1* > &source,vector<node1* > &dest){
              
              for(int i=0;i<source.size();i++){
                      copy_node(source[i],dest[i]);
                      copy_child(source[i],dest[i],dest);
                      }
              
              }//data copy finish 
 
vector<node1* > make_copy(vector<node1* > &tt,bool extra){
     
     vector<node1* > a;
     
     for(int i=0;i<tt.size();i++){
             node1* temp=new node1;
             copy_node(temp,tt[i]);
             a.push_back(temp);
             }
     
     for(int i=0;i<tt.size();i++){
             copy_child(a[i],tt[i],a);
             }
        if(extra){node1* temp=new node1;temp->ds=0;temp->index=tt.size();temp->pd=null;temp->fb=0;
        for(int i=0;i<a.size();i++){temp->child.push_back(make_pair(a[i],0));}
        a.push_back(temp);
        }
     return a;        
     }//make copy finish 

bool cycle_check(node1* index_v,int cost,node1* u){

   if(index_v->ds>u->ds+cost){return false;}
return true;
}//cycle check finish

void copy_node(node1* a,node1* b){
        a->ds=INF;
        a->index=b->index;
        a->fb=b->fb;
        a->pd=null;
  }//copy node1 finish

void copy_child(node1* a,node1* b,vector<node1* > &c){
     
     for(list<pair<node1* ,int> > :: iterator it=b->child.begin();it!=b->child.end();it++){
          a->child.push_back(make_pair(c[(*it).first->index],(*it).second));
           
           }//for finish
     
     }//copy child finish

 
void relax(node1* index_v,int cost,node1* u){

   if(index_v->ds>u->ds+cost){
                                 index_v->ds=u->ds+cost;index_v->pd=u;}

}//relax finish


bool bellman_ford(node1* source,vector<node1* > &vv){

//cout<<" source "<<source->index<<" -> "<<source->child.size();OP;
source->ds=0;
vector<node1* > a;
for(int i=0;i<vv.size();i++){
      node1* temp=new node1;
      temp->ds=vv[i]->ds;
      temp->index=i;
      temp->pd=null;
      a.push_back(temp);
        }
   
        
for(int k=0;k<vv.size()-1;k++){
        
for(int i=0;i<vv.size();i++){
         
            for(list<pair<node1* ,int> >:: iterator it=vv[i]->child.begin();it!=vv[i]->child.end();it++){
                        relax((*it).first,(*it).second,a[i]);
                      
                    }//inner for
}//middle for
   
for(int i=0;i<vv.size();i++){
        a[i]->ds=vv[i]->ds;
        }  
}//outer for

for(int i=0;i<vv.size();i++){
            for(list<pair<node1* ,int> >::iterator  it=vv[i]->child.begin();it!=vv[i]->child.end();it++){
                      
            if(!cycle_check((*it).first,(*it).second,vv[i])){return false;}
                     
                    }//inner for
   }//outer for

a.clear();   
return true;
}//bellman ford finish


void relax(node1* u,node1* vv,int cost){
     if(vv->ds>u->ds+cost){
                          fh->fib_decrease_key((node* )vv->fb,u->ds+cost);
                            }
     }//relax finish

void Dijkstra(node1* source,vector<node1* > &vv){
     
     source->ds=0;
     for(int i=0;i<vv.size();i++){
             fh->fib_insert(vv[i]);
             }
     
     while(!fh->empty()){
                         node1 *x=fh->get_min()->data;
                         fh->fib_extract_min();
                     
                     for(list<pair<node1* ,int> > :: iterator it=x->child.begin();it!=x->child.end();it++){
                                         relax(x,(*it).first,(*it).second); 
                                          }//for finish
                     
                     }//while finish 
     }//dijkstra finish

void make_graph(){
     get_data();
     for(int i=0;i<v.size();i++){

     cout<<"enter no. of edges connected to "<<(i)<<"th vertex,index and the edge cost";OP;
             int temp1;cin>>temp1;
             for(int j=0;j<temp1;j++){
                      int temp2,temp3;cin>>temp2>>temp3;;
                      make_link(i,temp2,temp3);
                     pairs temp;
                     temp.u=i;
                     temp.v=temp2;
                     temp.cost=temp3;
                     edge.push_back(temp);
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
    ga.johnson_algorithm();
    cout<<"node are: ";OP;
    for(int i=0;i<n;i++){for(int j=0;j<n;j++){cout<<ga.getanswer(i,j)<<"  ";}OP;};
 
    OP;
    OP;SP;
    }
/*
5
3 1 3 2 8 4 -4
2 4 7 3 1
1 1 4 
2 0 2 2 -5
1 3 6
*/
