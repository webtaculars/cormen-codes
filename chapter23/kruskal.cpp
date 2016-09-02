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


struct node{
       list<pair<node* ,int> > child; // child
       node* parent;
       int rank;
       int index;//vertex index
        };

bool myfunc(pair<pair<int,int> ,int> a,pair<pair<int,int> ,int> b){return a.second<b.second;}

class graph_alg{
vector<node* > v;int time; 
vector<pair<pair<int,int> ,int> > gmatrix;

public:
       graph_alg(int n){v.resize(n,null);time=0;}

      node* getelement(int i){return v[i];}

 
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
     
vector<pair<pair<int,int> ,int> > kruskal_MST_matrix(){
     vector<pair<pair<int,int> ,int> > temp;
   sort(gmatrix.begin(),gmatrix.end(),myfunc); 
   //cout<<"start";OP;    
   for(int i=0;i<gmatrix.size();i++){
           //cout<<gmatrix[i].first.first<<" "<<gmatrix[i].first.second<<"  "<<v[gmatrix[i].first.first]->data;
           if(find_set(v[gmatrix[i].first.first])!=find_set(v[gmatrix[i].first.second])){
              //                    cout<<"start";
                                  temp.push_back(gmatrix[i]);
                                  union_set(v[gmatrix[i].first.first],v[gmatrix[i].first.second]);                                            
                                                                              }//if finsh
           }//for finsh  
    
    return temp;       
     }//kruskal mst finish     

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
     
vector<pair<pair<int,int> ,int> >  kruskal(){
     
     for(int i=0;i<v.size();i++){
             for(list<pair<node* ,int> > :: iterator it=v[i]->child.begin();it!=v[i]->child.end();it++){
                                 gmatrix.push_back(make_pair(make_pair(i,(*it).first->index),(*it).second));
                                 }//inner for finsh
             }//outer for funsh
     return kruskal_MST_matrix();
     }     
     
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

node* make_node(){
     node* temp=new node;
     temp->parent=temp;
     temp->rank=0;
     return temp;
     }//make node finish

node* make_index(int i){
node* temp=make_node();
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
    int n;cin>>n;
    graph_alg ga(n);
    ga.make_graph_matrix();OP;
    cout<<" going kruskal ";OP;
    vector<pair<pair<int,int> ,int> > gmatrix=ga.kruskal_MST_matrix();
    for(int i=0;i<gmatrix.size();i++){
          cout<<endl<<gmatrix[i].first.first<<"  "<<gmatrix[i].first.second<<"  "<<gmatrix[i].second;
        } 
    OP;SP;
    }
/*
9
14
0 1 4
1 2 8
2 3 7
3 4 9
4 5 10
5 6 2
6 7 1
7 0 8
1 7 11
7 8 7
8 2 2
8 6 6
2 5 4
3 5 14 
*/
