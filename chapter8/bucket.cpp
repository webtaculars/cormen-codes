#include<iostream>
#include<vector>
#include<cmath>
#define swap(x,y) {x=x+y;y=x-y;x=x-y;}

using namespace std;

vector<double> A;

void bucket_sort(){
     vector<vector<double> >B;
	 int n=A.size();
	 B.resize(n);         
              for(int i=0;i<A.size();i++){
                      B[n*A[i]].push_back(A[i]);} 
             
              for(int i=0;i<n;i++){
                     
                     for(int j=0;j<B[i].size();j++){
                             for(int k=j-1;k>=0;k--){
                                     if(B[i][j]>B[i][k]){swap(B[i][j],B[i][k]);break;}
                                     }
                             
                             }// sort finish
                     
                     }
			  int pp=0;
              for(int i=0;i<n;i++){for(int j=0;j<B[i].size();j++){A[pp++]=B[i][j];}}                            
              
              
              }


int main(){
    
    double myint;//int min=1<<30,max=0;
    do{
		cin>>myint;
		A.push_back(myint);
		}
	while(myint!=.42);
    
    bucket_sort();
    cout<<endl<<"starting"<<endl;
    for(int i=0;i<A.size();i++){
		cout<<A[i]<<endl;
		}
    
    cout<<endl;system("pause");
    return 0;
    }
