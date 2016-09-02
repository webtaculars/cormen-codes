#include<iostream>
#include<vector>
#include<cmath>


using namespace std;

vector<int> A;

void counting_sort(int d,int which){
     
     int p=1;
     for(int j=0;j<d;j++){
     vector<int> v(which,0);
     
     for(int i=0;i<A.size();i++){v[((A[i]/p)%10)]+=1;}
 
     for(int i=1;i<which;i++){v[i]=v[i]+v[i-1];}
     vector<int> B(A.size());
     for(int i=B.size()-1;i>=0;i--){
      B[v[((A[i]/p)%10)]-1]=A[i];    
      v[((A[i]/p)%10)]-=1;}
      A=B;
      p*=10;
     }//j close
    
         }

int main(){
    int d;cin>>d;int which;
    
    int myint;int min=1<<30,max=0;
    do{cin>>myint;A.push_back(myint);if(min>myint){min=myint;}if(max<myint){max=myint;}}while(myint!=42);
    
    counting_sort(2,10);
    cout<<endl<<"starting"<<endl;
    for(int i=0;i<A.size();i++){cout<<A[i]<<endl;}
    
    cout<<endl;system("pause");
    return 0;
    }
