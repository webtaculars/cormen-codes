#include<cstdio>
#include<vector>
#include<iostream>
#include <fstream>
#include <string>
#include<sstream>
#include<map>
#include<algorithm>
#define FI(sz) for(int i=0;i<sz;i++)
#define FORI(ini,sz) for(int i=ini;i<sz;i++)
#define FJ(sz) for(int j=0;j<sz;j++)
#define FORJ(ini,sz) for(int j=ini;j<sz;j++)
#define FNI(sz) for(int i=sz-1;i>=0;i--)
#define FNJ(sz) for(int j=sz-1;j>=0;j--)
#define PB push_back
#define ALL(v) (v).begin(),(v).end()
//#define debug
using namespace std;

char* filename="bill.txt";
string content="";
vector<string> names;
map<string,int> debit,credit;

string toString(int num){
       string temp="";string temp1="";
       if(num&(1<<31)){temp1=temp1+"-";num=-num;}
       while(num!=0){
                     char ch=(num%10)+'0';
                     temp=ch+temp;
                     num=num/10;
                     }
       temp=temp1+temp;
       return temp;
}

int toNumber(string str){
   
    int temp=0;
    FI(str.length())
                    temp=temp*10+str[i]-'0';
    return temp;                        
}//tonumber finish

string lowercase(string str){
     FI(str.length())
           if(str[i]<='Z')
                    str[i]=str[i]+'a'-'A';
return str;
}//lowercase finsih

void writeFile(string cont){
     ofstream myfile;
     myfile.open ("output.txt", ios::out | ios::app);
     myfile <<cont;
     myfile.close();
}//writefile finsh

void readFile(){

string line;
  ifstream myfile(filename);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      content=content+line;
      content+="\n";
    }
    myfile.close();
  }

  else cout << "Unable to open file";
}//readfile finish

void parse(){
     stringstream sin;
     sin.str(content);
     int n;
     sin>>n;
     #ifdef debug
     cout<<n;
     #endif
     string temp;
     FI(n){
             
             sin>>temp;
             names.push_back(temp);
             credit[temp]=0;
             debit[temp]=0;
             #ifdef debug
             cout<<endl<<temp;
             writeFile(temp+"\n");
             #endif
             }
           
     while(true){
             sin>>temp;
             
             #ifdef debug
             cout<<endl<<temp;
             writeFile(temp+"\n");
             #endif
             if(lowercase(temp)=="exit"){
                                         break;
                                         }
             int amount=toNumber(temp);
             string paidBy;
             sin>>paidBy;
             
             #ifdef debug
             cout<<endl<<paidBy;
             writeFile(paidBy+"\n");
             #endif
             credit[paidBy]+=amount;
             int how_many_distribute;
             sin>>how_many_distribute;
             
             
             #ifdef debug
             cout<<endl<<how_many_distribute;
             writeFile(toString(how_many_distribute));
             #endif
             if(how_many_distribute==n){
                        FI(n){debit[names[i]]+=(amount/how_many_distribute);}                
                                        }//if n finsih
             else{
                  FI(how_many_distribute){
                                          string payee;
                                          sin>>payee;
                                         
                                           
                                         #ifdef debug
                                         cout<<endl<<payee;
                                         writeFile(payee);
                                         #endif                  
                                          debit[payee]+=(amount/how_many_distribute);
                  }
                  }//else finsh
             }
     
}//parse finishs


void logic(){
     writeFile("Name\t\t\tDebit\t\t\tCredit\t\t\tTotal\n");
     FI(names.size()){
             string temp=names[i];
                     temp=temp+"  \t\t";
                     temp=temp+toString(debit[names[i]]);
                     temp=temp+"\t\t\t";
                     temp=temp+toString(credit[names[i]]);
                     temp=temp+"\t\t\t";
                     temp=temp+toString(credit[names[i]]-debit[names[i]]);
                     temp=temp+"\n";
                     writeFile(temp);
                     }
         
}

int main(){
   readFile();
   parse();
   logic();
system("pause");    
return 0;
}
/*
1. First Enter number of person participated
2. then their respective name
3. then amount paid, name of person who paid the amount, how many involved,(conditional: if all involved then no need else) write each participated member name
4. write as many entries as you like. only follow protocol define at step 3
5. write exit
*/
/*
e.g.
4
sandesh praveen wasif shyam
10 sandesh 2 praveen sandesh
exit
*/
