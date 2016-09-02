#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#define swap(x,y) x=x+y;y=x-y;x=x-y;

using namespace std;


class heap_ds{
vector<int> data;
public:
heap_ds(vector<int> a){data=a;}

int Parent(int i){return (int)floor(i/2);}

int Left(int i){return (2*i);}

int Right(int i){return (2*i+1);}

void Max_heapify(int i,int sizes){
   //  cout<<"i: "<<i<<endl;
     int l=Left(i);
     int r=Right(i);
     int largest=i;
        if(l<=sizes&& data[largest]<data[l]){largest=l;}
        if(r<=sizes && data[largest]<data[r]){largest=r;} 
        if(largest!=i){
			swap(data[i],data[largest]);
     		Max_heapify(largest,sizes);
			}
     
     }

void Build_max_heap(){
          int p=data.size();
          p=(p-1)/2;
  //        cout<<endl<<p<<"  "<<data[1]<<"  "<<data.size();
     for(int i=p;i>=1;i--){
            //cout<<i<<"  "<<(data.size()-1);
             Max_heapify(i,data.size()-1);
             
             }}
             
             
vector<int> Heapsort(){
            Build_max_heap();
            for(int i=data.size()-1;i>1;i--){
                    swap(data[1],data[i]);
                    Max_heapify(1,i-1);
                    //cout<<"data1 "<<data[1]<<"  datai "<<data[i];
                    }
           return data;         
            }     
            
vector<int> Extract_max_heap(){
            Build_max_heap();
            return data;
            }
            
int Extract_max_element(){
    int val=data[1];
    swap(data[1],data[data.size()-1]);
    data.erase(data.begin()+(data.size()-1));
    return val;
    }
 
 vector<int> Current_heap(){return data;}
 
 void Heap_increase_key(int i,int new_value){
      if(data[i]>new_value)return ;
      data[i]=new_value;
      while(i>1 && data[Parent(i)]<new_value){swap(data[Parent(i)],data[i]);i=Parent(i);}
      }
      
 void Heap_insert(int value){
      data.resize(data.size()+1);
      data[(data.size()-1)]=value;
      Heap_increase_key((data.size()-1),value);
      }    
          
     void Heap_decrease_key(int i,int new_value){
      if(data[i]<new_value)return ;
      data[i]=new_value;
      bool thr=false;
      while(i<data.size() && Left(i)<data.size() && data[Left(i)]>new_value){thr=true;swap(data[Left(i)],data[i]);i=Left(i);}
      while(!thr && i<data.size() && Right(i)<data.size() && data[Right(i)]>new_value){swap(data[Right(i)],data[i]);i=Right(i);}
      }
};

int main()
{
vector<int> data;
int n;
cout<<"enter number of values: ";
cin>>n;
//cout<<n;

data.resize(n+1);
data[0]=-1;
for(int i=1;i<=n;i++){cin>>data[i];}
//cout<<"initial"<<data.size()<<"\n";
heap_ds hp(data);

data=hp.Extract_max_heap();
hp.Heap_insert(7);
data=hp.Current_heap();
//cout<<hp.Extract_max_element();
//data=hp.Heapsort();

for(int i=1;i<data.size();i++){cout<<endl<<"data:"<<data[i];}

cout<<endl;
system("pause");
return 0;
}
