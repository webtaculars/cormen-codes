#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<string>
#define swap(x,y) {x=x+y;y=x-y;x=x-y;}

using namespace std;

vector<string> gud(vector<string> str,map<string,int> mymap,int tc,int cnt){
       
      int siz1=tc;
        int count=0,count1=0,min=cnt,min_i=0;
        int start=0,point=0;bool first=true,neww=true; 
        list<string> window;//cout<<"language count"<<mymap["language"];
        bool prev=false;//cout<<endl;
	for(int i=1;i<str.size();i++){string sr=str[i];transform(sr.begin(), sr.end(), sr.begin(), ::tolower);

                             if(first){ if( mymap.count(sr)>0){
                                    mymap[sr]-=1;point=i;start=sr.length();window.push_back(sr);first=false;count++;}
                             }else{    
                                  
                             if(prev && count==tc){if(min>start){min=start;min_i=point;}
                           // for(list<string>::iterator it=window.begin();it!=window.end();it++){cout<<endl<<*it<<endl;}
                             }
                        
                                    if(mymap.count(sr)>0){
                                              prev=true;
                                                     if(mymap[sr]>0){start+=sr.length();window.push_back(sr);count++;mymap[sr]-=1;
                                                   //  cout<<"first: "<<sr<<" count "<<count<<endl;
                                                     }
                                                     else if((!window.empty()) && (sr.compare(window.front())==0)){
                                                     //     cout<<"popping & inserting11 "<<sr<<endl;
                                                          point++;window.pop_front();window.push_back(sr);
                                                          while((!window.empty()) && (mymap.count(window.front())<1)){point++;start-=window.front().length();
                                                       //   cout<<"popping "<<window.front()<<endl;
                                                          window.pop_front();}
                                                          while((!window.empty()) && (mymap[window.front()]<0) ){point++;start-=window.front().length();mymap[window.front()]+=1;
                                                         // cout<<"popping "<<window.front()<<endl;
                                                          window.pop_front();
                                                                                                                  while((!window.empty()) && (mymap.count(window.front())<1)){point++;start-=window.front().length();
                                                                                                                  //cout<<"popping "<<window.front()<<endl;
                                                                                                                  window.pop_front();}
                                                          }
                                                          }//else if clse
                                                     else{start+=sr.length();//cout<<"popping "<<sr<<endl; 
                                                     window.push_back(sr);
                                                     mymap[sr]-=1;prev=false;   }
                                              
                                              }
                                     else{prev=false;window.push_back(sr);start+=sr.length();
                                   //  cout<<"inserting "<<sr<<endl;
                                     }
                             
                                  
                                  
                                  }
                                  }
                                  //cout<<"count "<<count<<endl;
       if(prev && count==tc){if(min>start){min=start;min_i=point;}
                            //for(list<string>::iterator it=window.begin();it!=window.end();it++){cout<<endl<<*it<<endl;}
                             }
                        
       if(count!=tc){cout<<"NO SUBSEGMENT FOUND";vector<string> f;f.push_back("");return f;}
           
 //cout<<"min size: "<<min<<" min_i "<<min_i<<endl;
                                  
           int uo=0;//mmm=min;
           vector<string> give;give.push_back("");
    for(int i=min_i;i<str.size();i++){
            if(uo>=min)break;
            uo+=str[i].length();
            give.push_back(str[i]);}
                   
       return give;
       }

int main(){
    
    vector<string> str;
    str.push_back("");
    char c='a';int cnt=0;
    string st;
   do{
                   c=getchar();
                   if(c!='.'){
                        if(c==' '){if(!st.empty())str.push_back(st);
                        //mymap[ff].push_back(cnt);
                        cnt+=st.length();
                        //ff.clear();
                        st.clear();}
                        else{if((c>='A' &&c<='Z')||(c>='a' &&c<='z'))st.push_back(c);//if(c>='A'&&c<='Z'){c=c+32;}ff.push_back(c);
                        }               
                   }
                   
            }
         while(c!='\n');
               str.push_back(st); cnt+=st.length();
    map<string,int> mymap;
    int tc;cin>>tc; // vector<string> substr;
    for(int i=0;i<tc;i++){string st;cin>>st;
transform(st.begin(), st.end(), st.begin(), ::tolower);//substr.push_back(st);
mymap[st]+=1;}
    int siz1=tc;
        int count=0,count1=0,min=cnt,min_i;
        int start=0,point=0;bool first=true,neww=true; 
        list<string> window;//bool firs=true;int begin_i=1;
        
        vector<string> sp=gud(str,mymap,tc,cnt+1);           
   // if(sp.size()!=1){vector<string> stc;bool chk=true;
     //          while(stc.size()!=sp.size()){if(chk){chk=false;stc=gud(sp,mymap,tc,cnt);}else{chk=true;sp=stc;stc=gud(sp,mymap,tc,cnt);}}
               
              
            for(int i=1;i<sp.size();i++){cout<<sp[i]<<" ";}  
       //     }  
               
    cout<<endl;
    system("pause");
    return 0;
    }
