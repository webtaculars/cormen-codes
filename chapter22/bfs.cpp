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
       int dis;  //distance
       };
class graph_alg{
vector<node* > v;
public:
       graph_alg(int n){v.resize(n);}

node* getelement(int i){return v[i];}
       
void BFS(node* source){
   source->color=GRAY;
   source->dis=0;
     
   queue<node* > q;
   q.push(source);
   
   while(!q.empty()){
                     
                     node* x=q.front();
                     q.pop();
                     cout<<" BFS "<<x->data;OP;
                     list<node* > :: iterator it;
                     for(it=x->child.begin();it!=x->child.end();it++){
                                                              if((*it)->color==WHITE){      
                                                               (*it)->color=GRAY;
                                                               (*it)->pd=x;
                                                               (*it)->dis=x->dis+1;
                                                               q.push((*it));}
                                                                     }//for finish
                                x->color=BLACK;                                     
                                                                     
                     }//while finish  
     
     }//BFS close

void print_path(node* source,node* visit){
     if(visit==source){cout<<source->data<<"  dis "<<source->dis;OP;return ;}
     if(visit->pd==null){cout<<"no path exist";OP;return ;}
     print_path(source,visit->pd);
     cout<<visit->data<<"  dis "<<visit->dis;OP;
     }//print pathh finish

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
     temp->dis=INF;
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
    ga.BFS(ga.getelement(1));
    ga.print_path(ga.getelement(1),ga.getelement(n-1));
    OP;SP;
    }
/*
8
0
1
2
3
4
5
6
7
2 1 4
2 0 5
3 5 6 3
3 2 6 7
1 0
3 1 2 6
4 5 2 3 7
2 6 3
*/
