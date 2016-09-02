#include<iostream>
#include<vector>


using namespace std;

void insertion_sort(vector<int>::iterator p,int y);
void print(vector<int>::iterator p,int y);

int main(){
    vector<int> elements;
    int n;
    cin>>(n);// no of elements
    
    for(int i=0;i<n;i++){int p;cin>>p;elements.push_back(p);}
    
    insertion_sort(elements.begin(),elements.size());
    
    print(elements.begin(),elements.size());
    
    system("pause");
    return 0;}
    
void insertion_sort(vector<int>::iterator pp,int size)
{
     
     for(int i=1;i<size;i++){
             int key=pp[i];
             int j=i-1;
             while(j>=0&&key<pp[j]){
                                       pp[j+1]=pp[j];
                                       j--;}
             pp[j+1]=key; 
                                    }
     
     }

void print(vector<int>::iterator p,int size){
     
    
     for(int i=0;i<size;i++){
     cout<<p[i];}
     }
