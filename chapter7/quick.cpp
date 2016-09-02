#include<iostream>
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


void quicksort(int p,int r)
{
     if(p<r){
	 	int q=partition(p,r);
		cout<<"q:"<<q<<"\n";
        quicksort(p,q-1);
	    quicksort(q+1,r);
     }
}

int main(){
   // clock_t start=clock(),end;
    A.push_back(1);
    A.push_back(1);
    A.push_back(21);
    A.push_back(1);
    
    quicksort(0,A.size()-1);
    
    for(int i=0;i<A.size();i++)cout<<A[i]<<endl;
    cout<<endl;
    system("pause");
    return 0;
    }
