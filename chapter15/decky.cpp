#include<iostream>
#include<cmath>
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
#define sp system("pause");
#define op cout<<endl
using namespace std;

class DyckwordUniformer{
      
      public:
      string uniform(string dd){
             vector<string> fb;int b=0;int start=0,end=0;int ct=0;
             fi(dd.length()){
                             dd[i]=='X'?b++:b--;end++;
                             if(b==0){
                                      fb.pb(dd.substr(start,end));
                                    start=end;end=0;  }
                             }
             
             sort(all(fb));
             dd.clear();
             fi(fb.size()){
                           cout<<fb[i];op;
                           dd.append(fb[fb.size()-1-i]);
             }return dd;
             }//unifoem finfish
      };


int main(){
    
    DyckwordUniformer dc;
    cout<<dc.uniform("XXXYYYXXYXXXYYYY");
    op;sp;
    return 0;
    }
