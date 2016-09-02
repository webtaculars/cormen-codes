#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;
vector<int> A;
vector<int> Quantile;
int cl; 
void swap(int &a,int &b){int temp=a;a=b;b=temp;}

int Partition(int p,int r){
//    swap()
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

void Quantiles(int p,int r,int prev_k,int k){
    if(k!=1 ){int n=A.size();
             int i=(k)/2;
             int x=Randomize_Select(p,r,(i+prev_k)*(n/cl));
        Quantiles(p,(i+prev_k)*(n/cl)-1,0,i); 
             Quantile.push_back(x);
             cout<<"x "<<x<<"\n";
       
             
            Quantiles((i+prev_k)*(n/cl)+1,r,i+prev_k,k-i); 
             }
     }

int main(){
      A.push_back(0);
int myint; while(myint!=42){
    cin>>myint;A.push_back(myint);
    }          
    cout<<"size "<<A.size()<<endl;
    int k;
    cin>>k;cl=k;
           Quantile.push_back(0);
      
    //Quantile.resize(k);
    Quantiles(1,A.size()-1,0,k);
   //int pq=Randomize_Select(0,6,3);cout<<"start\n";    
    for(int i=1;i<Quantile.size();i++)cout<<" "<<Quantile[i]<<"  ";   
//    cout<<"\nvalue select : "<<pq;
    cout<<endl;system("pause");
    return 0;
    }
 
