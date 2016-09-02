#include<iostream>
#include<vector>
#define swap(x,y) {x=x+y;y=x-y;x=x-y;}

using namespace std;
vector<int> A;
void stooge_sort(int i,int j){
     
    if(A[i]>A[j])swap(A[i],A[j]);
    if(i+1>=j)return ;
int    k=(j-i+1)/3;
    stooge_sort(i,j-k);
    stooge_sort(i+k,j);
    stooge_sort(i,j-k); 
     
     }

int main(){
    
        
    A.push_back(1);
    A.push_back(5);
    A.push_back(61);
    A.push_back(51);
    A.push_back(41);
    A.push_back(1);
    
    stooge_sort(0,A.size()-1);
    for(int i=0;i<A.size();i++)cout<<A[i]<<"\n";
    cout<<endl;
   
    
    cout<<endl;
    system("pause");
    return 0;
    }
