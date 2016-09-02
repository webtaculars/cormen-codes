#include<iostream>
#include<vector>
#include<cmath>
#define null NULL

using namespace std;
int s1,s2,e1,e2,n;
vector<int> a1;
vector<int> a2;
vector<int> t1;
vector<int> t2;

void Assembly_Line(){
     vector<int> f1(n,0),f2(n,0);
     f1[0]=s1+a1[0];
     f2[0]=s2+a2[0];
     
     for(int i=1;i<n;i++){
             
             if(f1[i-1]<f2[i-1]+t2[i-1]){f1[i]=f1[i-1]+a1[i];}
             else{f1[i]=f2[i-1]+t2[i-1]+a1[i];}
             if(f2[i-1]<f1[i-1]+t1[i-1]){f2[i]=f2[i-1]+a2[i];}
             else{f2[i]=f1[i-1]+t1[i-1]+a2[i];}
             
             }
     if(f1[n-1]+e1<f2[n-1]+e2){cout<<"min cost "<<f1[n-1]+e1;}
     else{cout<<"min cost "<<f2[n-1]+e2;}
     }


int main(){
    cin>>s1>>s2>>e1>>e2>>n;
    a1.resize(n);a2.resize(n);t1.resize(n-1);t2.resize(n-1);
    for(int i=0;i<n-1;i++){
            cin>>a1[i]>>a2[i]>>t1[i]>>t2[i];
            }
    cin>>a1[n-1]>>a2[n-1];
    
    Assembly_Line();
    cout<<endl;system("pause");
    return 0;
    }
