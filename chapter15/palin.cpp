#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
class PalindromeMaker{
public:
PalindromeMaker(){}
string make(string b){
vector<int> tr(26,0);
for(int i=0;i<b.length();i++){
tr[b[i]-'A']+=1;
}
bool chk=false;
int start=0,end=b.length()-1;
for(int i=0;i<26;i++){
if(tr[i]&1){if(chk)return "";else{chk=true;}b[b.length()/2]='A'+i;tr[i]-=1; }
for(int j=0;j<tr[i]/2;j++){b[start++]='A'+i;b[end--]='A'+i;}
}
return b;
}//func finish

};

int main(){
    PalindromeMaker pm;
    cout<<pm.make("AAABB");
    cout<<endl;system("pause");
    return 0;
    }
