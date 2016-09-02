#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    vector<int> prime;
    vector<bool> temp;
    int n;cin>>n;temp.resize(n);
    for(int i=0;i<n;i++)temp[i]=true;
    
    for(int i=2;i<=n;i++){
            
            if(temp[i]){prime.push_back(i);
            
            for(int j=2;i*j<=n;j++){temp[i*j]=false;}}}
         
         for(int i=0;i<prime.size();i++)cout<<prime[i]<<endl;   
    
    system("pause");
    return 0;
    }
