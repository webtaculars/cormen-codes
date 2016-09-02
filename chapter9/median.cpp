#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstdlib>


using namespace std;

void swap(int &a,int &b){int temp=a;a=b;b=temp;}
vector<int> A;
vector<int> Median;

int Partition(int p,int r){
    
    int key=A[p];
    
    int i=p+1,j=r;
    while(i<j){
    //        cout<<" \ni "<<i<<"  j "<<j<<"\n";
               while(i<r && A[i]<key)i++;
               while(j>p && A[j]>key)j--;
               if(i<j){swap(A[i],A[j]);}
               
               }
     if(j<=r && j>=p){if(A[p]>=A[j]){swap(A[j],A[p]);return j;}}
       return p;
    }

int Partition_Modified(int p,int r,int tem){
    
    int key=tem;
    int i=p+1,j=r;
    int mm=p+1;
    while(i<=r){
                if(A[i]==key){swap(A[p],A[i]);}
                if(A[i]<key){swap(A[mm],A[i]);mm++;}
              i++;  }
    if(mm-1>=p && mm-1<=r){
    swap(A[mm-1],A[p]);
  //  cout<<"mm "<<(mm-1)<<"\n";
    return (mm-1);
    }
    return p;
    }


int Randomized_partition(int p,int r){
    int i=p+(rand()%(r-p+1));
    //cout<<"\ni "<<i;;
    swap(A[i],A[p]);
    return Partition(p,r);
    }


int Randomize_Select(int p,int r,int m){
    
    if(p==r){return A[p];}
    
    int q;
    q=Randomized_partition(p,r);
    //cout<<"\nq "<<q<<"\n";
    if(q==m){return A[q];}
    else if(m<q){return Randomize_Select(p,q-1,m);}
    else{return Randomize_Select(q+1,r,m);}
}

int Partition_Median(int p,int r){
    
    int key=Median[p];
    int i=p+1,j=r;
    while(i<j){
               //cout<<"h";
               while(i<r && Median[i]<key)i++;
               while(j>p && Median[j]>key)j--;
               if(i<j){swap(Median[i],Median[j]);}
               
               }
     if(j<=r && j>=p){//cout<<"j median "<<j<<endl;
     if(Median[p]>=Median[j]){swap(Median[j],Median[p]);return j;}}
       return p;
    }


int Randomized_partition_Median(int p,int r){
    
    int i=p+(rand()%(r-p+1));
    swap(Median[i],Median[p]);
    return Partition_Median(p,r);
    
    }


int Randomize_Select_Median(int p,int r,int m){
    
    if(p==r){return Median[p];}
    
    int q;
    q=Randomized_partition_Median(p,r);
    if(q==m){return Median[q];}
    else if(m<q){return Randomize_Select_Median(p,q-1,m);}
    else{return Randomize_Select_Median(q+1,r,m);}

}


void Get_Median_Select(int m){
     
     int n=A.size();

    for(int i=0;i<=ceil(n/5);i++){
		int j;
        for(j=5*i;j<5*i+5 && j<n;j++){
                    for(int k=j-1;k>=5*i && A[k]>A[k+1];k--){
						swap(A[k],A[k+1]);
						}
                    }
                    int ty=A[5*i+((j-1-5*i)/2)];
                    //cout<<"median : "<<ty<<endl;
            Median.push_back(ty);
            
            }
     
     int mp=(Median.size()-1)/2;
     int tem=Randomize_Select_Median(0,Median.size()-1,mp);
     //swap(A[0],A[mp]);
     //cout<<"tem "<<tem<<endl;
     int y=Partition_Modified(0,A.size()-1,tem);
     
    // cout<<"y "<<y<<endl;
     if(y==m)   {cout<<"value positioned at : "<<A[y]<<endl;}
     else if(m<y) {cout<<Randomize_Select(0,y-1,m);}
     else{cout<<Randomize_Select(y+1,A.size()-1,m);}
     
     }

int main(){
      
int myint; while(myint!=42){
    cin>>myint;A.push_back(myint);
        }          
    
    Get_Median_Select(3);
    
//    int pq=Randomize_Select(0,A.size()-1,A.size()/2);    
  //  cout<<"\nvalue selected : "<<pq;
    cout<<endl;system("pause");
    return 0;
    }

