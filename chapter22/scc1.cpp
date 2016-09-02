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
       int data;
       node* pd; //predecesor
       list<node* > child; // child
       int color;
       int dtime;
       int ftime;
       };
class graph_alg{
vector<node* > v;int time;
public:
       graph_alg(int n){v.resize(n);time=0;}

node* getelement(int i){return v[i];}

void DFS_visit(node* x){
     
     time+=1;
     x->dtime=time;
     x->color=GRAY;
     cout<<" node visiting "<<x->data<<"  start time "<<x->dtime;OP;
     for(list<node* > :: iterator it=x->child.begin();it!=x->child.end();it++){
                    if((*it)->color==WHITE){(*it)->pd=x;DFS_visit(*it);}
                    }
          x->color=BLACK;
          x->ftime=time=time+1;          
     }//dfs visit finish
       
void DFS(){
     for(int i=0;i<v.size();i++){
             if(v[i]->color==WHITE){DFS_visit(v[i]);}
             }
     }    //DFS finish   
       
vector<node* > make_graph_complement(){
     
     
     
     }//graph complement finish

void make_graph(){
     get_data();
     for(int i=0;i<v.size();i++){

     cout<<"enter no. of edges connected to "<<(i)<<"th vertex and index";OP;
             int temp1;cin>>temp1;
             for(int j=0;j<temp1;j++){
                      int temp2;cin>>temp2;
                      make_link(i,temp2);
                     }
             }
     }//make arbitrary graph

void make_link(int i,int j){
     v[i]->child.push_back(v[j]);
     }//make link finish

node* make_node(int data){
     node* temp=new node;
     temp->data=data;
     temp->pd=null;
     temp->color=WHITE;
     temp->dtime=0;
     temp->ftime=0;
     return temp;
     }//make node finish

void get_data(){
     cout<<"enter "<<v.size()<<" vertices value";OP;
     for(int i=0;i<v.size();i++){
             int data;cin>>data;
             v[i]=make_node(data);
             }
     }//get data finish

};
int main(){
    cout<<"Enter No of vertices";OP;
    int n;cin>>n;
    graph_alg ga(n);
    ga.make_graph();
    ga.DFS();
    OP;SP;
    }
/*
6
0
1
2
3
4
5
2 1 3
1 4
2 4 5 
1 1
1 3
1 5
*/
