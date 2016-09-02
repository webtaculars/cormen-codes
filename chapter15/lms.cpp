#include<vector>
#include<iostream>

using namespace std;
vector<int> sequence;
vector<int> b;
void LMS(){
     vector<int> p(sequence.size(),0);
     if (sequence.empty()) return;
     b.push_back(0);
     
     for(int i=1;i<sequence.size();i++){
             
             if(sequence[b.back()]<sequence[i]){
                                                p[i]=b.back();
                                                b.push_back(i);
                                                continue;
                                                }
             
             int u=0,v=b.size()-1;
             while(u<v){
                        int c=(u+v)/2;
                        if(sequence[b[c]]<sequence[i]){
                                                       u=c+1;
                                                        }//fi
                        else{v=c;}                                
                        }
             
             if(sequence[b[u]]>sequence[i]){
                                      if(u>0)p[i]=b[u-1];
                                      b[u]=i;     
                                           }
             
             }
     int pb=b[b.size()-1];
     for(int i= b.size()-1;i>0;i--){b[i]=pb;pb=p[pb];}
     
     }//LMS finsih



int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){int p;cin>>p;sequence.push_back(p);}
    LMS();
    for(int i=0;i<b.size();i++){cout<<"\nk "<<sequence[b[i]];}
    cout<<endl;system("pause");
    return 0;
    }
