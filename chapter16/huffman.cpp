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
#define SP system("pause")
#define OP cout<<endl
using namespace std;

struct node{
char ch;
int freq;
struct node* left;
struct node* right;
};
vector<node *> v;
node* root;

bool myfunc(node* a,node* b){return a->freq>b->freq;}

void Huffman(){
     int n=v.size();
     make_heap(v.begin(),v.end(),myfunc);
     for(int i=0;i<n-1;i++){
             node *z=new node;
             z->left=v.front();pop_heap(all(v),myfunc);v.pop_back();
             z->right=v.front();pop_heap(all(v),myfunc);v.pop_back();
             z->ch='1';
             z->freq=z->left->freq + z->right->freq;
             v.push_back(z);
             push_heap(all(v),myfunc);
             }
     //cout<<v.front()->freq<<"  "<<v.front()->left->freq;OP;
     }

int main(){
    map<char,int> mymap;
    char c;
    do{cin>>c;mymap[c]+=1;}while(mymap['a']!=45);
    
    for(map<char,int> :: iterator it=mymap.begin();it!=mymap.end();it++){
                 node* temp=new node;     
                      temp->ch=(*it).first;
                      temp->freq=(*it).second;
                      temp->left=null;
                      temp->right=null;
                      v.pb(temp);
                      }
    mymap.clear();
    Huffman();
    
    OP;
    OP;
//  
    OP;SP;
    }
