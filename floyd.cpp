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
#define INF (1<<26)
#define null NULL
#define fi(sz) for(int i=0;i<sz;i++)
#define fj(sz) for(int j=0;j<sz;j++) 
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define SP system("pause");
#define OP cout<<endl
typedef long long LL;
using namespace std;


class graph_alg{
      vector<vector<int > > v;
      vector<vector<int > > pd;
      vector<vector<bool > > tclosure;
      
      public:
      graph_alg(int n){v.resize(n,vector<int> (n,INF));tclosure.resize(n,vector<bool> (n,false));
      for(int i=0;i<n;i++){v[i][i]=0; tclosure[i][i]=true;}
      pd.resize(n,vector<int> (n,-1));
      }
      
int getelement(int i,int j){return v[i][j];}//get element finish

int getpredecessor(int i,int j){return pd[i][j];}

int min(int a,int b){return a<b?a:b;}//min finish

void floyd_warshall(){
     vector<vector<int> > temp=v;
     
     for(int k=0;k<v.size();k++){
             
             for(int i=0;i<v.size();i++){
                     
                     for(int j=0;j<v.size();j++){
                             if(temp[i][j]>temp[i][k]+temp[k][j]){
                                                          v[i][j]=temp[i][k]+temp[k][j];
                                                          pd[i][j]=k;        
                                                                  }
                             }//inner for finish
                     
                     }//mddle for finihs
             temp=v;
             }//outer for finish
     temp.clear();
     }//floyd warshall finish

void transitive_closure(){
     
     
     for(int k=0;k<v.size();k++){
             
             for(int i=0;i<v.size();i++){
                     
                     for(int j=0;j<v.size();j++){
                            tclosure[i][j]=tclosure[i][j]||(tclosure[i][k]&&tclosure[k][j]);
                             }//inner for finish
                     
                     }//mddle for finihs
             
             }//outer for finish
     
     }//transitive closure finish

void getdata(){
     cout<<"Enter no of edges : ";int e;cin>>e;OP;
     for(int i=0;i<e;i++){
     cout<<"Enter starting vertex, end vertex and cost associated ";OP;
     int temp1,temp2,temp3;cin>>temp1>>temp2>>temp3;
     v[temp1][temp2]=temp3;
     pd[temp1][temp2]=temp1;
     tclosure[temp1][temp2]=true;
     
     }//for finish
     }//getdata finish
     
void print(int kk){
     OP;int n=v.size();
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
    switch(kk){
               case 0:
    cout<<v[i][j]<<"  ";break;
               case 1:
    cout<<pd[i][j]<<"  ";break;
               case 2:
    cout<<tclosure[i][j]<<"  ";break;
}
    }OP;}
     };     
      };


int main(){
    
    int n; 
    cin>>n;
    graph_alg ga(n);
    ga.getdata();
    ga.floyd_warshall();
    ga.transitive_closure();
    ga.print(0);OP;
    ga.print(1);OP;
    ga.print(2);OP;
    SP;
    }

/*
5
9
0 1 3
0 2 8
0 4 -4
1 3 1
1 4 7
2 1 4
3 0 2 
3 2 -5
4 3 6
*/

//care for INF value

