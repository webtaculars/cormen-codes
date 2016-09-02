#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > a;
//vector<vector<int> > b;

void color(int i,int j,int n){
     
     a[i][j]=false;
     
     if(i+1<=n && a[i+1][j])color(i+1,j,n);
     if(i-1>=1 && a[i-1][j])color(i-1,j,n);
     if(j+1<=n && a[i][j+1])color(i,j+1,n);
     if(j-1>=1 && a[i][j-1])color(i,j-1,n);
     if(i+1<=n && j+1<=n && a[i+1][j+1])color(i+1,j+1,n);
     if(i-1>=1 && j-1>=1 && a[i-1][j-1])color(i-1,j-1,n);
     if(i-1>=1 && j+1<=n && a[i-1][j+1])color(i-1,j+1,n);
     if(i+1<=n && j-1>=1 && a[i+1][j-1])color(i+1,j-1,n);
     }


int main(){
    
    
    int tc;
    cin>>tc;
    
    for(int i=0;i<tc;i++)
    {
            int count=0;
            int n;cin>>n;
            a.resize(n+1);
            for(int j=1;j<n+1;j++){
                               a[j].resize(n+1);
                              for(int k=1;k<n+1;k++){
                                 cin>>a[j][k]; 
                                                      
                    }
                    }
            
            
            for(int j=1;j<n+1;j++){
                              for(int k=1;k<n+1;k++){
                                      if(a[j][k]){count++;color(j,k,n);}}}
            cout<<count<<endl;
            
            a.clear();
            
            }
    
    cout<<endl;system("pause");
    return 0;
    }
