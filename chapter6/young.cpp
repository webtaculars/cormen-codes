#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#define swap(x,y) x=x+y;y=x-y;x=x-y;
#define INFINIT 2<<14
using namespace std;


class Young_Tableau{
	
vector<vector<int> > data;
int m,n;

public:

Young_Tableau(int mn,int nm){
                  m=mn;n=nm;
                  data.resize(m);
for(int i=0;i<m;i++){
	data[i].resize(n); 
	for(int j=0;j<n;j++){
		data[i][j]=INFINIT;
		}
	}
}//young_tableau finsih


void Youngify(int i,int j){
   //  cout<<"i: "<<i<<endl;
    
     int smallesti=i;
     int smallestj=j;
     
        if(i+1<m && data[smallesti][smallestj]>data[i+1][j]){
                             smallesti=i+1;
     }
        if(j+1<n && data[smallesti][smallestj]>data[i][j+1]){  
			smallesti=i;
			smallestj=j+1;
			} 
        if(!(smallesti==i && smallestj==j)){
			swap(data[i][j],data[smallesti][smallestj]);
            Youngify(smallesti,smallestj);
			}
 y}

void Youngify_Up(int i,int j){
   //  cout<<"i: "<<i<<endl;
    
     int smallesti=i;
     int smallestj=j;
     
        if(i-1>=0 && data[smallesti][smallestj]<data[i-1][j]){
                             smallesti=i-1;
     }
        if(j-1>=0 && data[smallesti][smallestj]<data[i][j-1]){  smallesti=i;smallestj=j-1;} 
        if(!(smallesti==i && smallestj==j)){swap(data[i][j],data[smallesti][smallestj]);
                      
                      Youngify_Up(smallesti,smallestj);}
          }



             
             
vector<vector<int> > Young_Tableau_sort(){
           
            while((Extract_min_element())!=INFINIT);
           return data;         
            }     
            
vector<vector<int> > Extract_Young_Tableau(vector<int> p){
            for(int i=0;i<p.size();i++){
                    Young_Tableau_insert(p[i]);
                    }
            return data;
            }
            
int Extract_min_element(){
    int val=data[0][0];
    data[0][0]=INFINIT;
    Youngify(0,0);
    return val;
    }
 
vector<vector<int> >  Current_Young_Tableau(){return data;}
 
 void Young_Tableau_increase_key(int i,int j,int new_value){
      if(data[i][j]>new_value)return ;
      data[i][j]=new_value;
      Youngify(i,j);
      }
      
 void Young_Tableau_insert(int value){
      data[m-1][n-1]=value;
      Youngify_Up(m-1,n-1);
      }    
          
     void Young_Tableau_decrease_key(int i,int j,int new_value){
      if(data[i][j]<new_value)return ;
      data[i][j]=new_value;
      Youngify_Up(i,j);
      }
};

int main()
{
    vector<vector<int> > data;

int n,m,p;
cout<<"enter m and n: ";
cin>>m>>n;
cout<<endl<<"enter number of values to  insert: ";
cin>>p;
//cout<<n;
vector<int> dat;dat.resize(p);
for(int i=0;i<p;i++){
        cin>>dat[i];
        }

//cout<<"initial"<<data.size()<<"\n";
Young_Tableau yt(m,n);

data=yt.Extract_Young_Tableau(dat);

for(int i=0;i<m;i++){
	cout<<endl;
	for(int j=0;j<n;j++){
		cout<<data[i][j]<<"  ";
		}
	}


cout<<endl;
system("pause");
return 0;
}
