#include<iostream>
#include<cstdlib>
#include<vector>
#define swap(x,y) {x=x+y;y=x-y;x=x-y;}

using namespace std;

vector<int> A;


int partition(int p,int r){
    
    int i=p+1,j=r;
    while(true){
                while(i<r&&A[i]<=A[p])i++;
                while(j>p&&A[j]>=A[p])j--;
                if(i<j){swap(A[i],A[j]);}
                else {if(j>p&&j<=r)swap(A[p],A[j]);return j;}
                }
    
    }

int randomize_partition(int p,int r){
     int i=p+(rand()%(r-p+1));
     swap(A[p],A[i]);
     return partition(p,r);
     }

void quicksort(int p,int r)
{
     if(p<r){
	 	int q=randomize_partition(p,r);
     	quicksort(p,q-1);
	 	quicksort(q+1,r);
     }
}

int main(){
    
    A.push_back(1);
    A.push_back(5);
    A.push_back(61);
    A.push_back(51);
    A.push_back(41);
    A.push_back(123);
    
    quicksort(0,A.size()-1);
    for(int i=0;i<A.size();i++)cout<<A[i]<<"\n";
    cout<<endl;
    system("pause");
    return 0;
}
