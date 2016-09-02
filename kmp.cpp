#include<iostream>
#include<cmath>
#include<list>
#include<stack>
#include<bitset>
#include<vector>
#include<string>
#include<algorithm>
#include <map>
#include<utility>
#define INF (1<<30)
#define null NULL
#define fi(sz) for(int i=0;i<sz;i++)
#define fj(sz) for(int j=0;j<sz;j++) 
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define SP system("pause");
#define OP cout<<endl
typedef long long LL;
using namespace std;

string str;
string pattern;
vector<int> pi;


void print_vector(vector<int> &h){
fi(h.size())OP<<h[i];
}

void compute_pi(){

  int k=0;
  for(int i=1;i<pattern.length();i++){
             
           while(k>0 && pattern[k]!=pattern[i]){
               k=pi[k-1];
                 }//while finish
           if(pattern[k]==pattern[i])k+=1;
           pi[i]=k;
   }//for finish
print_vector(pi);
}//compute pi finish


void got_pattern(){

    int k=0;
    
       for(int i=0;i<str.length();i++){
              while(k>0 && pattern[k]!=str[i])k=pi[k-1];
              if(pattern[k]==str[i])k+=1;
              if(k==pattern.length()){OP<<" found at "<<(i-k+1);k=pi[k-1];}      
             }//for finish  
}//got pattern finish

int main(){
    cin>>str;
    cin>>pattern;
   cout<<str<<endl<<pattern<<endl;
    pi.resize(pattern.length(),0);
    
    compute_pi();
    got_pattern();       
    cout<<endl;
//system("pause");
    return 0;
    }
