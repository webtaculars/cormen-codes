#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<map>
using namespace std;
vector<int> a;
map<string,int> index;
    string str;
void writes(int i,int j,int len){
  for(int p=i;p<(i+len);p++){a[p]=j+1;}    
     }

bool comp(int i,string substr){   
int p;
for( p=0;p<substr.length();p++){
        if(!(str[i+p]==substr[p]||str[i+p]==(substr[p]+32)||str[i+p]==(substr[p]-32)))
        return false;
        }
      if(str[i+p]!=' ')return false;
return true;
}

int main(){
    
   
    char c;do{
                   c=getchar();
                   if(c!='\n'&&c!='.'){
                   str.push_back(c);a.push_back(0);
                   }
                   
                   }
                   
        while(c!='\n');
        a.resize(str.length());
       int tc;cin>>tc;
   vector<string> substrc;substrc.resize(tc);
   vector<vector<int> > substri;substri.resize(tc);
   for(int i=0;i<tc;i++){cin>>substrc[i];index[substrc[i]]+=1;}
   
 //   for(int i=0;i<tc;i++){cout<<endl<<substrc[i]<<endl;}
 int num_count=0;
   for(int i=0;i<str.length();i++){
           
           for(int j=0;j<substrc.size();j++){
                   if(comp(i,substrc[j])){ 
               //   cout<<endl<<substrc[j].length()<<i<<"j,i";
                                                                     writes(i,j,substrc[j].length());
                                                                     substri[j].push_back(i);
                                                                     num_count++;
                                                                    i=i+substrc[j].length();
                                                                     break;
                                                                     }
                   
                   }
           
           }
        
        
           
          int min_length=str.length();
           for(int im=0;im<substrc.size();im++)
           {if(min_length>substri[im].size()){min_length=substri[im].size();}}
            if(min_length==0){cout<<"NO SUBSEGMENT FOUND";return 0;}
     //over subtr
     vector<vector<int> > occur;occur.resize(num_count);
     vector<int> sum;sum.resize(num_count);
     vector<int> min_val;min_val.resize(num_count);
     int var1;
     for(int i=0;i<num_count;i++){sum[i]=0;min_val[i]=0;occur[i].resize(substrc.size());
     for(int j=0;j<substrc.size();j++)occur[i][j]=index[substrc[j]];}
     var1=0;
     
     //start
     for(int k=0;k<str.length();k++){var1=0;bool brk=false;
     for(int i=0;i<substrc.size();i++){
             
             for(int j=0;j<substri[i].size();j++){
                     
                     if(k>=substri[i][j]&& sum[var1]!=(substrc.size()*(substrc.size()+1))/2){
                                           if(a[k]!=0&&!occur[var1][a[k]-1]){sum[var1]=sum[var1]+a[k];occur[var1][a[k]-1]=true;}
                                           min_val[var1]++;
                                           //k=k+substrc[i].length()-1;
                                          // brk=true;
                                          // break;
                                           }
                     
                                         var1++; }
            // if(brk)break;
                                   } }
           //end
           int find_min=str.length(),x=0,y=0;int j=0;
for(int pq=0;pq<substrc.size();pq++){
                   
                   for(int pk=0;pk<substri[pq].size();pk++){int i;
            for(i=0;i<substrc.size();i++){if(!occur[j][i])break;}
            if(i==substrc.size()){
           
              min_val[j]=min_val[j]+substrc[a[min_val[j]+substri[pq][pk]-1]-1].length()-1;
            //  cout<<min_val[j]<<endl;         
            if(find_min>min_val[j]){find_min=min_val[j];x=pq;y=pk;}
            
          }
            j++;}}  
            
            cout<<endl<<str.substr(substri[x][y],find_min);
            
         cout<<endl;
//for(int i=0;i<a.size();i++)cout<<a[i];
    cout<<endl;
    system("pause");
    return 0;
    }
