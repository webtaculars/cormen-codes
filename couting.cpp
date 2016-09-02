#include<iostream>
#include<vector>
#include<cmath>


using namespace std;

vector<int> A;

void counting_sort(int start,int end){
     
     vector<int> v(end-start+1,0);
     
     for(int i=0;i<A.size();i++){
	 	v[A[i]-start]+=1;
		}
 
     for(int i=1;i<(end-start+1);i++){
	 	v[i]=v[i]+v[i-1];
		}
     vector<int> B(A.size());
     for(int i=B.size()-1;i>=0;i--){
      B[v[A[i]-start]-1]=A[i];    
      v[A[i]-start]-=1;
	  }
     for(int i=0;i<B.size();i++){
	 	cout<<endl<<B[i];
		} 
 }

int main(){
    int myint;int min=1<<30,max=0;
    do{cin>>myint;A.push_back(myint);if(min>myint){min=myint;}if(max<myint){max=myint;}}while(myint!=42);
    counting_sort(min,max);
    cout<<endl;system("pause");
    return 0;
    }
