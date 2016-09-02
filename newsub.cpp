#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#define swap(x,y) {x=x+y;y=x-y;x=x-y;}

using namespace std;

struct node {
       int fpos;
       int which;
       int last;
       };

int main(){
    
    vector<string> str,substr;
     str.push_back("");
     char c='a';string st;
   do{
                   c=getchar();
                   if(c!='.'){
                        if(c==' '){str.push_back(st);
                        //mymap[ff].push_back(cnt);
                        //cnt+=st.length();ff.clear();
                        st.clear();}
                        else{st.push_back(c);//if(c>='A'&&c<='Z'){c=c+32;}ff.push_back(c);
                        }               
                   }
                   
            }
         while(c!='\n');
               str.push_back(st);     
     int tc ;cin>>tc;
     int cnt=1;vector<bool> ifthere;
     for(int i=0;i<tc;i++){string sr;cin>>sr;
transform(sr.begin(), sr.end(), sr.begin(), ::tolower);substr.push_back(sr);ifthere.push_back(false);}
     vector<struct node> merge;
     
    // for(int i=1;i<str.size();i++)cout<<str[i];
     int cntt=0;
     for(int i=1;i<str.size();i++){string sr=str[i];
transform(sr.begin(), sr.end(), sr.begin(), ::tolower);
//     transform(ss.begin(),ss.end(),ss.begin,::tolower);
             for(int j=0;j<substr.size();j++){
                     if(sr.compare(substr[j])==0){cntt++;
                                                      struct node temp;
                                                      temp.fpos=cnt;
                                                      temp.which=j;temp.last=0;
                                                      merge.push_back(temp);
                                                      ifthere[j]=true;
                                                      }
                     }cnt+=str[i].size();}
                     
                  for(int i=0;i<tc;i++){if(!ifthere[i]){cout<<"NO SUBSEGMENT FOUND";
                  //system("pause");
                  return 0;}}   
                   //  cout<<endl;
//        cout<<"count"<<cntt<<"\n";
        vector<vector<bool> > occur(merge.size(),vector<bool> (substr.size(),0));vector<int> count(merge.size(),0);
       // for(int i=0;i<merge.size();i++){occur[i].resize(substr.size());count[i]=0;}
        //for(int j=0;j<substr.size();j++){occur[i][j]=false;}
        //}             
        int siz1=merge.size(),siz2=substr.size();
        
       //cout<<"merge size"<<siz1;
        
        for(int i=0;i<siz1;i++){
                
                for(int j=0;j<=i;j++){
                        
                        if((i==j||merge[j].fpos!=merge[i].fpos) && !occur[j][merge[i].which]){
                        occur[j][merge[i].which]=true;count[j]++;
                        merge[j].last=i;
                        }
                        
                        }
                
                }
                int min=cnt;int min_i=0;//cout<<endl;
   //for(int i=0;i<siz1;i++)cout<<"merge first "<<merge[i].fpos<<"  merge last "<<merge[i].last<<"  count"<<count[i]<<"\n";
      for(int i=0;i<siz1-substr.size()+1;i++){
              if(count[i]==tc){int cal=merge[merge[i].last].fpos-merge[i].fpos+substr[merge[merge[i].last].which].length()-1;
     //         cout<<endl<<"cal "<<cal;
              if(min>cal){min=cal;min_i=i;}
              }
              }  
              
       //     cout<<"minimum length "<<min<<"  "<<min_i<<"\n";   
                   int u=1;int ui=merge[min_i].fpos;
                   for(int i=1;i<str.size();i++){
                          if(u>=ui&&u<=ui+min){cout<<str[i]<<" ";} 
                           u=u+str[i].length();
                           if(u>ui+min)break;
                           }             
     
   cout<<endl;
    system("pause");
    return 0;
    }
