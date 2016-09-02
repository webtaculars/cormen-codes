#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define INFY 1000.0
using namespace std;
struct node{
       int x;
       int y;
       };
vector<node> bitour;
bool myfunc (node i,node j) { return (i.x<j.x); }
double euc(node i,node j){
       return sqrt((i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y));
       }

void Bitonic_Tour(){
     
     
     sort(bitour.begin(),bitour.end(),myfunc);
    int n=bitour.size()-1;
    if(n==0){return ;}
    vector<vector<double> > b(n+1,vector<double>(n+1,INFY));
    b[0][1]=euc(bitour[0],bitour[1]);
    for(int j=2;j<=n;j++){
            
            for(int i=0;i<j-1;i++){
                    b[i][j]=b[i][j-1]+euc(bitour[j-1],bitour[j]);
                    }
            
            for(int k=0;k<j-1;k++){
                    double q=b[k][j-1]+euc(bitour[k],bitour[j]);
                    if(q<b[j-1][j]){b[j-1][j]=q;}
                    }
            }//j finish
     b[n][n]=b[n-1][n]+euc(bitour[n-1],bitour[n]);
     cout<<b[n][n];
     }

int main(){
    int k,l;
    do{
        cin>>k>>l;
        node temp;
        temp.x=k;
        temp.y=l;
        bitour.push_back(temp);
        }while(k!=8);
    Bitonic_Tour();
    cout<<endl;system("pause");
    return 0;
    }
