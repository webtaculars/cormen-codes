#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

vector<int> A;
int Partition(int p,int r){
    
    int key=A[p];
   // cout<<"key "<<key<<"\n";
    int i=p+1,j=r;
    while(i<j){
               //cout<<"h";
               while(i<r && A[i]<key)i++;
               while(j>p && A[j]>key)j--;
               if(i<j){swap(A[i],A[j]);}
               
               }
     if(j<=r && j>=p){
           //  cout<<"j"<<j;
             if(A[p]>=A[j]){
                            swap(A[j],A[p]);return j;
                            }}
       return p;
    }


int Randomized_partition(int p,int r){
    int i=p+(rand()%(r-p+1));
    swap(A[i],A[p]);
    int temp=Partition(p,r);//cout<<"\ntemp "<<temp<<endl;
    return temp;
    }


int Randomize_Select(int p,int r,int m){

    if(p==r){return A[p];}
    
    int q;
    q=Randomized_partition(p,r);
    //cout<<"q "<<q<<"\n";
    if(q==m){return A[q];}
    else if(m<q){return Randomize_Select(p,q-1,m);}
    else{return Randomize_Select(q+1,r,m);}
}


int main(){
      
int myint;cin>>myint; int i=0;while(i<myint){
    int temp;cin>>temp;
   A.push_back(temp);
        }          
      
    //cout<<"size "<<A.size()<<endl;
   int pq=Randomize_Select(0,A.size()-1,3);  
    cout<<"\nvalue select : "<<pq;
    cout<<endl;system("pause");
    return 0;
    }

