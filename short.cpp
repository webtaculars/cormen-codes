#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
vector<int> a;

bool writes(int i,int j,int len){
     //cout<<i<<" "<<j<<" "<<len<<endl;
     for(int p=i;p<(i+len);p++){if(a[p]>=j+1){return false;}}
     for(int p=i;p<(i+len);p++){a[p]=j+1;}return true;
          }

 
int main(){
    
    string str;
   
    char c;do{
                   c=getchar();
                   if(c!='\n'&&c!='.'&&c!=' '){
                   c=tolower(c);str.push_back(c);a.push_back(0);}
                   
                   }
                   
        while(c!='\n');
        //cout<<str;
    //a.resize(str.length());
   //memset(&a,0,sizeof(a));
   int tc;cin>>tc;
   vector<string> substrc;substrc.resize(tc);
   vector<vector<int> > substri;substri.resize(tc);
   for(int i=0;i<tc;i++){cin>>substrc[i];transform(substrc[i].begin(), substrc[i].end(), substrc[i].begin(), ::tolower);}
   
 //   for(int i=0;i<tc;i++){cout<<endl<<substrc[i]<<endl;}
   for(int i=0;i<str.length();i++){
           
           for(int j=0;j<substrc.size();j++){
                   if(str.compare(i,substrc[j].length(),substrc[j])==0){ 
               //   cout<<endl<<substrc[j].length()<<i<<"j,i";
                                                                     if(writes(i,j,substrc[j].length()))
                                                                     substri[j].push_back(i);
                                                                     }
                   
                   }
           
           }
           
           int min_index=0;
           int min=str.length();int sum_i=0;
           vector<vector<bool> > occur;
           for(int i=0;i<substrc.size();i++){sum_i=sum_i+substri[i].size();//cout<<"sum "<<sum_i<<"\t";
           if(min>substri[i].size()){min=substri[i].size();min_index=i;}}
occur.resize(sum_i);
             if(min==0){cout<<"NO SUBSEGMENT FOUND";return 0;}
          vector<int> min_int;
          vector<int> max_int;     
 for(int i=0;i<sum_i;i++){ min_int.push_back(0);max_int.push_back(0);for(int j=0;j<substrc.size();j++){occur[i].push_back(false);}}
          vector<int> min_min;min_min.resize(sum_i);
                      
                
          vector<int> sum_min;sum_min.resize(sum_i);
                      int yu=0;
                  for(int i=0;i<sum_i;i++){sum_min[i]=0;min_min[i]=0;}    
          for(int k=0;k<str.size();k++){yu=0;
           for(int i=0;i<substrc.size();i++){
                   
                   for(int j=0;j<substri[i].size();j++){
                           
                           if(k>=substri[i][j]&&(sum_min[yu]!=(substrc.size()*(substrc.size()+1))/2)){
                                     if(k>=substri[i][j]&&a[k]!=0&&!occur[yu][a[k]-1]){
                                     sum_min[yu]=sum_min[yu]+a[k];occur[yu][a[k]-1]=true;max_int[yu]=k;
                                        //  cout<<"i,j"<<i<<j<<" pos "<<k<<"\t";         
                                                                                      }
                                                                                
                                                                min_min[yu]++;                         }
                           
                                                     yu++; }
                   
                   } //cout<<endl;
                                      } 
                   
                int io=0;int x,y,z,jk=str.length();
                  for(int i=0;i<substrc.size();i++){
                   
                   for(int pk=0;pk<substri[i].size();pk++){
                           
                           int j;for(j=0;j<substrc.size();j++){//cout<<occur[i][j]<<" ";
                  
                 if(!occur[io][j])break;
                  }io++;
                  if(j==substrc.size())
                 {if(jk>(substrc[a[max_int[io-1]]-1].length()+max_int[io-1]-substri[i][pk])){
                                                                                           jk= (substrc[a[max_int[io-1]]-1].length()+max_int[io-1]-substri[i][pk]);
                                                                                             x=i;y=pk;} 
                //cout<<endl<<"minmin: "<<min_min[i]<<str.substr(substri[i][pk],(substrc[a[max_int[io-1]]-1].length()+max_int[io-1]-substri[i][pk]));
                 }//cout<<endl;
                  }
                  }
                  cout<<str.substr(substri[x][y],jk);
          // cout<<min<<"  "<<substrc[min_index];
           if(min==0){cout<<"NO SUBSEGMENT FOUND";return 0;}
           int len_min=str.length(),min_i,min_j;
           
           
         
         //for(int j=0;j<substrc.size();j++){cout<<substri[j].size()<<endl;}  
         cout<<endl;
//for(int i=0;i<a.size();i++)cout<<a[i];
  cout<<endl;  system("pause");
    return 0;
    }
