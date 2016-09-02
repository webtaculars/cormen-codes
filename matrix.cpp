#include<iostream>
#include<vector>
#include<cmath>
#define null NULL
#define INFINIT 9999999
using namespace std;

vector<int> p;
int n;
void matrix_multiplication(){
     vector<vector<int> > m(n,vector<int> (n,INFINIT));
     for(int i=0;i<n;i++){m[i][i]=0;}
     
     for(int l=1;l<n;l++){
             
             for(int i=0;i<n-l;i++){
                     
                     int j=i+l;
                     for(int k=i;k<j;k++){
                              if(m[i][j]>m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1]){
                           m[i][j]=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
                           
                           }  
                             
                             }//k
                       }//i
             
             }//l
     
     cout<<m[1][4];
     }

int main(){
    cin>>n;p.resize(n+1);
    for(int i=0;i<n+1;i++){
            cin>>p[i]; }
               matrix_multiplication();
            
    
    cout<<endl;system("pause");
    return 0;
    }
