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
#define OP cout<<endl
using namespace std;


struct node{string str;int cc;};
bool myfunc(node a,node b){if(a.cc==b.cc){if(a.str.compare(b.str)<0)return false;else{return true;}}return a.cc<b.cc;}
int main(){
    int tc;cin>>tc;
    map<string,int> mymap;
    for(int i=0;i<tc;i++){string s;cin>>s;
    mymap[s]+=1;}
  int p;cin>>p;
    int cnt=mymap.size();vector<node> v;
    for(map<string,int> :: iterator it=mymap.begin();it!=mymap.end();it++){
                                   node temp;temp.str=(*it).first;temp.cc=(*it).second;
                                  
                                   v.pb(temp);
                                            }
                                            
    mymap.clear(); 
                                       sort(all(v),myfunc);
                       for(int i=v.size()-1;i>=v.size()-p;i--){cout<<endl<<v[i].str;}                                                 
    OP;SP;
    return 0;
    }
