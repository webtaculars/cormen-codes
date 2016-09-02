#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#define null NULL

using namespace std;
struct node{
       int c;
       char chk;
       node(int ck,char chkk){c=ck;chk=chkk;}
       };
 string s,d;
void Print(vector<vector<node> > &l,int i,int j){
     if(i<1 || j<1)return ;
     
     if(l[i][j].chk=='@')Print(l,i,j-1);
     else if(l[i][j].chk=='#')Print(l,i-1,j);
     else{Print(l,i-1,j-1);cout<<endl<<s[i-1];}
     }       

void LCS(string a,string b){
     
     vector<vector<node> >l (a.length()+1,vector<node> (b.length()+1,node(0,'!')));
     
     for(int i=0;i<a.length();i++){
             for(int j=0;j<b.length();j++){
                     
                     if(a[i]==b[j]){l[i+1][j+1].c=l[i][j].c+1;l[i+1][j+1].chk='!';}
                     else{
                          if(l[i+1][j].c>l[i][j+1].c){l[i+1][j+1].c=l[i+1][j].c;l[i+1][j+1].chk='@';}
                          else{l[i+1][j+1].c=l[i][j+1].c;l[i+1][j+1].chk='#';}
                          }
                     }//j
             }//i
     Print(l,a.length(),b.length());
     }

int main(){
    
    cin>>s>>d;
    LCS(s,d);
    cout<<endl;system("pause");
    return 0;
    }
