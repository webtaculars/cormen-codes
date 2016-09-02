#include<iostream>
#include<cmath>
#include<list>
#include<stack>
#include<bitset>
#include<vector>
#include<string>
#include<algorithm>
#include <map>

#define null NULL
#define fi(sz) for(int i=0;i<sz;i++)
#define fj(sz) for(int j=0;j<sz;j++) 
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define SP system("pause");
#define OP cout<<endl;
using namespace std;

struct node{
       int s;
       int f;
       };
list<node> a;
list<node> ans;
bool myfunc(node x,node y){return x.f<y.f;}

void recurse_activity(int finish){
    if(a.empty())return ;
    node temp=a.front(); 
     while((!a.empty()) && temp.s<finish){
                      a.pop_front();
                      temp=a.front();
                      }
             ans.pb(temp);
                  
      if(!a.empty()){recurse_activity(temp.f);}                
     }

void select_activity(){
     a.sort(myfunc);
     recurse_activity(0);
    ans.pop_back();
     }

int main(){
    int x,y;
    do{cin>>x>>y;node temp;temp.s=x;temp.f=y;a.pb(temp);}while(x!=12);
    select_activity();
    OP
    OP
    while(!ans.empty()){cout<<ans.front().s<<"  "<<ans.front().f<<endl;ans.pop_front();}  
    
    OP SP
    }
