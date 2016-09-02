#include<iostream>
#include<vector>


using namespace std;

int merge_inversion(int p,int q,int r);

int count_inversion(int p,int  r);
vector<int> A;
 
int main()
{
    int n;
    cin>>n;A.push_back(0);
    for(int i=1;i<=n;i++){int y;cin>>y;A.push_back(y);
}
    cout<<endl<<count_inversion(1,n)<<endl<<endl;
    cout<<endl<<"printing arrary"<<endl;
    for(int i=1;i<=n;i++){cout<<A[i]<<"\t";}
    cout<<endl;
        system("pause");
    return 0;
    }
    
    
 int count_inversion(int  p,int  r){
     int inversion=0;
     if(p<r){
int             q=(p+r)/2;
             inversion=inversion+count_inversion(p,q);
             inversion=inversion+count_inversion(q+1,r);
             inversion=inversion+merge_inversion(p,q,r);
             
             }
     return inversion;
     }   

int merge_inversion(int p,int q,int r){
    
    int n1=q-p+1;int n2=r-q;

vector<int> l1;
vector<int> l2;
l1.resize(n1+2);
l2.resize(n2+2);

    for(int i=1;i<=n1;i++){l1[i]=A[p+i-1];}
    for(int i=1;i<=n2;i++){l2[i]=A[q+i];}
    
    l1[n1+1]=99999970;
    l2[n2+1]=99999970;
    
    int i=1,j=1;
    
    int inversion=0;bool counts=false;
    
    for(int k=p;k<=r;k++){
            
            if(!counts && l2[j]<l1[i]){inversion = inversion+n1+1-i;counts=true;}
            if(l1[i]<=l2[j]){A[k]=l1[i];i++;}
            else{A[k]=l2[j];j++;counts=false;}
            }
    
    return inversion;
    
    }
