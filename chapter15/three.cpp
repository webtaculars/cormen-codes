#include<iostream>
#include<string>

#define SP system("pause")
#define OP cout<<endl
using namespace std;
string* v;int n,start,endd;int len;
void app(int t){len+=t;
     len=len>n?n:len;
     for(int i=0;i<t;i++){
             endd=(endd+1)%n;
             if(endd==start){start=(start+1)%n;}
             string temp;cin>>temp;v[endd]=temp;
                if(start==-1 && endd>0)start=0;}if(start==-1)start=0;
                //cout<<" start "<<start<<"  end "<<endd<<"  ";
     }

void rem(int t){len-=t;
     start=(start+t)%n;    
     if(len==0)start=endd=-1;
     
               // cout<<" start "<<start<<"  end "<<endd<<"  ";
     }

void ls(){
     
             //   cout<<" start "<<start<<"  end "<<endd<<"  ";
     for(int i=0;i<len;i++){
             
             cout<<endl<<v[(start+i)%n];
             }
     
     }

int main(){
    cin>>n;
    v=new string[n];
    start=-1;endd=-1;len=0;
    char ch;
    cin>>ch;
    while(ch!='Q'){
                   switch(ch){
                              case 'A':
                              {int t;cin>>t;app(t);}
                              break;
                              case 'R':
                             {int t;cin>>t;rem(t);}
                             break;
                             case 'L':
                             ls();
                             break;
                             case 'Q':
                                  break;
                              }
                              cin>>ch;
                   }
                   delete[] v;
    SP;OP;
    return 0;
    }
