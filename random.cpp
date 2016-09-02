#include<iostream>
#include<vector>
#include<cstdlib>
#define swap(x,y) x=x+y;y=x-y;x=x-y;

using namespace std;
vector<int> Randomizeinplace(vector<int> a);

int main()
{
vector<int> data;
int n;
cout<<"enter number of values: ";
cin>>n;
cout<<endl;

data.resize(n);
for(int i=0;i<n;i++){cin>>data[i];}

data=Randomizeinplace(data);
for(int i=0;i<n;i++){cout<<data[i]<<"  ";
}
cout<<endl;

return 0;
}


vector<int> Randomizeinplace(vector<int> a){

for(int i=a.size(),j=0;i>1;i--){
int p=j+(rand()%(i));
cout<<"p:"<<p<<endl;
if(p!=j){
swap(a[j],a[p]);}j++;
}

return a;
}
