#include<iostream>
#include<vector>
#define swap(x,y) x=x+y;y=x-y;x=x-y;

using namespace std;


int main()
{
vector<int> data;
int n;
cout<<"enter number of values: ";
cin>>n;
cout<<endl;

data.resize(n+1);
for(int i=0;i<n;i++)cin>>data[i];

for(int i=0;i<n;i++){
for(int j=0;j<n-i-1;j++){
if(data[j]>data[j+1]){swap((data[j]),(data[j+1]));}
}}

for(int i=0;i<n;i++)cout<<data[i];
return 0;
}









