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
       int index;//vertex index
       int dtime;//discovery time
       int ftime;//finishing time
       };

bool myfunc(node* a,node* b){return a->ftime>b->ftime;}

class graph_alg{
vector<node* > v;int time;
public:
       graph_alg(int n){v.resize(n);time=0;}

node* getelement(int i){return v[i];}

void find_SSC( ){

DFS(v);
vector<node* > temp=v;
sort(all(temp),myfunc);
vector<node* > tv=make_graph_complement(v);

/*

for(int i=0;i<tv.size();i++){OP;cout<<tv[i]->index<<" -> ";
   for(list<node* > :: iterator it=tv[i]->child.begin();it!=tv[i]->child.end();it++){cout<<"  "<<(*it)->index;}
}
*/
vector<vector<node* > > ret=DFS_C(tv);

///*
for(int i=0;i<ret.size();i++){OP;
   for(int j=0;j<ret[i].size();j++){
           cout<<ret[i][j]->index;                        
                                   }OP;
                             }
//*/
}//find ssc finish


void DFS_visit(node* x,bool b,vector<node* > &tt){
     
     time+=1;
     x->dtime=time;
     x->color=GRAY;
     if(b){tt.push_back(x);} 
     cout<<" node visiting "<<x->data<<"  start time "<<x->dtime;OP;
     for(list<node* > :: iterator it=x->child.begin();it!=x->child.end();it++){
                    if((*it)->color==WHITE){(*it)->pd=x;
                                               
                                                DFS_visit(*it,b,tt);}
                    }
          x->color=BLACK;
          x->ftime=time=time+1;          
     }//dfs visit finish
       
void DFS(vector<node* > &vv){
     for(int i=0;i<vv.size();i++){vector<node* > bb;
             if(vv[i]->color==WHITE){DFS_visit(vv[i],false,bb);}
             }
     }    //DFS finish   
       
vector<vector<node* > > DFS_C(vector<node* > &vv){
    vector<vector<node* > >  ret;
     for(int i=0;i<vv.size();i++){
             if(vv[i]->color==WHITE){
                vector<node* > temp;
                DFS_visit(vv[i],true,temp);
                ret.push_back(temp);   
                                     }
             }
return ret;
     }    //DFS finish   
       
vector<node* > make_graph_complement(vector<node* > &vv){
     
     vector<node* > tv;
         
     for(int i=0;i<vv.size();i++){
          tv.push_back(make_index(i,vv[i]->data));         
         }
     
     for(int i=0;i<vv.size();i++){
         for(list<node* >::iterator it=vv[i]->child.begin();it!=vv[i]->child.end();it++){
              tv[(*it)->index]->child.push_back(tv[i]);
                     }//inner for finish
              }//outer for finish
    return tv;
    
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

node* make_index(int i,int data){
node* temp=make_node(data);
temp->index=i;
}//make index finsh

void get_data(){
     cout<<"enter "<<v.size()<<" vertices value";OP;
     for(int i=0;i<v.size();i++){
             int data;cin>>data;
             v[i]=make_index(i,data);
             }
     }//get data finish

};
int main(){
    cout<<"Enter No of vertices";OP;
    int n;cin>>n;
    graph_alg ga(n);
    ga.make_graph();
    ga.find_SSC();
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
1 1 
3 2 4 5
2 3 6 
2 2 7
2 0 5
1 6
2 5 7
1 7
*/
