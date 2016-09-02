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
       int index;
       node* pd; //predecesor
       list<pair<node* ,pair<int,int> > > child; // child
       int color;
       int dis;  //distance
       int fl;
       };

typedef pair<node* ,pair<int,int> > pairs;       
class graph_alg{
vector<node* > v;
public:
       graph_alg(int n){v.resize(n);}

node* getelement(int i){return v[i];}


void copy_node(node* a,node* b){
        a->index=b->index;
        a->color=b->color;
        a->dis=b->dis;
        a->pd=null;
        a->fl=0;
  }//copy node1 finish

pairs make_pairs(node* a,int b,int c){
                     return make_pair(a,make_pair(b,c));
                     }//make pair finish

void copy_child(node* a,node* b,vector<node* > &c){
     
     for(list<pairs> :: iterator it=b->child.begin();it!=b->child.end();it++){
                    a->child.push_back(make_pairs(c[(*it).first->index],(*it).second.first,(*it).second.second));
           }//for finish
     
     }//copy child finish


vector<node* > make_copy(vector<node* > &tt){
     
     vector<node* > a;
     
     for(int i=0;i<tt.size();i++){
             node* temp=new node;
             copy_node(temp,tt[i]);
             a.push_back(temp);
             }
     
     for(int i=0;i<tt.size();i++){
             copy_child(a[i],tt[i],a);
             }
       
     return a;        
     }//make copy finish 

void print_vector(vector<node* > &b){
     OP<<" IN PRINT VECTOR \nvector value :";
     for(int i=0;i<b.size();i++){
     OP<<b[i]->index<<" -> "<<b[i]->fl;
    cout<<" child ";
    for(list<pairs > :: iterator it=b[i]->child.begin();it!=b[i]->child.end();it++){
              cout<<"  "<<(*it).first->index<<" -> "<<(*it).second.first;OP;
                       }
     }
     OP;
     }//print vector finish

void simple_print(vector<node* > &c){
     for(int i=0;i<c.size();i++)
     cout<<" index "<<c[i]->index;
     }//simple print finish


void ford_fulkerson(int s,int d){
     
     vector<node* > a=make_copy(v);
     
while(BFS(a[s],a[d])){
     vector<node* > l;
   
     int min=INF;
     print_path(a[s],a[d],l,min);       OP;  
simple_print(l);
     for(int i=0;i<l.size()-1;i++){
            
             for(list<pairs>::iterator it=l[i]->child.begin();it!=l[i]->child.end();it++){
                                       if((*it).first==l[i+1]){(*it).second.first+=min;
                                                                (*it).second.second-=min; 
                                                                
                                                   bool chk=false;
             for(list<pairs>::iterator it1=(*it).first->child.begin();it1!=(*it).first->child.end();it1++){             
                                                            if((*it1).first==l[i]){
                                                                          chk=true;
                                                                (*it1).second.second+=min;
                                                                break;
                                                                            } }
                                  if(!chk){
                                          (*it).first->child.push_back(make_pairs(l[i],0,min)); 
                                           }                                                  
                
                if((*it).second.second==0){
                                             l[i]->child.remove(*it);
                                             
                                             }                      
                                      break;
                                       }//fi
                                       }//inner for finish
             }//outer for finish
                    
           clear(a);        
           
                    }//while finish
    int sum=0;
     for(list<pairs>::iterator it=a[0]->child.begin();it!=a[0]->child.end();it++){sum+=(*it).second.first;}
    OP;cout<<" flow is "<<sum;
     }//ford fulkerson finish

bool clear(vector<node* > &b){
     
     for(int i=0;i<b.size();i++){
             b[i]->color=WHITE;
        b[i]->dis=INF;
        b[i]->pd=null;
        b[i]->fl=0;
             }
     
     }//clear finish
       
bool BFS(node* source,node* end){
   source->color=GRAY;
   source->dis=0;
     
   queue<node* > q;
   q.push(source);
   while(!q.empty()){
                     
                     node* x=q.front();
                     q.pop();
                     
                     if(x==end)return true;
                     list<pairs> :: iterator it;
                     for(it=x->child.begin();it!=x->child.end();it++){
                                                              if((*it).first->color==WHITE){      
                                                               (*it).first->color=GRAY;
                                                               (*it).first->pd=x;
                                                               (*it).first->dis=x->dis+1;
                                                               (*it).first->fl=(*it).second.second;
                                                               
                                                               q.push(((*it).first));}
                                                                     }//for finish
                                x->color=BLACK;                                     
                                                                     
                     }//while finish  
     return false;
     }//BFS close

void print_path(node* source,node* visit,vector<node* > &ll,int &min){
     if(visit==source){ll.push_back(visit);return ;}
     if(visit->pd==null){cout<<"no path exist";OP;return ;}
     print_path(source,visit->pd,ll,min);
     if(min>visit->fl && visit->fl!=0){min=visit->fl;
    
     }
     ll.push_back(visit);
     }//print pathh finish

void make_graph(){
     get_data();
     for(int i=0;i<v.size();i++){

     cout<<"enter no. of edges connected to "<<(i)<<"th vertex,index and edge cost";OP;
             int temp1;cin>>temp1;
             for(int j=0;j<temp1;j++){
                      int temp2,temp3;cin>>temp2>>temp3;
                      make_link(i,temp2,temp3);
                     }
             }
     }//make arbitrary graph

void make_link(int i,int j,int k){
     v[i]->child.push_back(make_pairs(v[j],0,k));
     }//make link finish

node* make_node(int data){
     node* temp=new node;
     temp->index=data;
     temp->pd=null;
     temp->color=WHITE;
     temp->dis=INF;
     temp->fl=0;
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
    cout<<"Enter No of vertices";OP;
    int n;cin>>n;
    graph_alg ga(n);
    ga.make_graph();
    ga.ford_fulkerson(0,n-1);
    OP;SP;
    }
/*
6
2 1 16 3 13
2 2 12 3 10
2 3 9 5 20
2 1 4 4 14
2 5 4 2 7
0
*/
