#include<iostream>
#include<vector>

using namespace std;
vector<vector<int> >A;
vector<vector<bool> >test;
vector<vector<bool> >test1;
int sum_max=0;
int m,n;
vector<vector<bool> > stamp;
void color1(int i,int j,vector<vector<bool> >temp_vector,vector<vector<bool> > st,int summ){
     
       temp_vector[i][j]=false;summ+=A[i][j];st[i][j]=true;
 //1.1
  if(i+1<m && temp_vector[i+1][j]){
       if(test1[i+1][j]){
                         if(sum_max<(summ)){sum_max=summ;stamp=st;}
                         }    
    else{color1(i+1,j,temp_vector,st,summ);}
    }
   //1.2
   if(i+1<m){if(!temp_vector[i+1][j]){ if(sum_max<(summ)){sum_max=summ;}}} 
   if(i+1>=m){if(sum_max<(summ)){sum_max=summ;}} 
    
    //2
     if(i-1>=0 && temp_vector[i-1][j]){
              if(test1[i-1][j]){
                         if(sum_max<(summ)){sum_max=summ;}
                         }    
    else{ color1(i-1,j,temp_vector,st,summ);}
     }
   //2.2
   if(i-1>=0){if(!temp_vector[i-1][j]){ if(sum_max<(summ)){sum_max=summ;}}}
      if(i-1<0){if(sum_max<(summ)){sum_max=summ;}} 
     
     //3
     if(j+1<n && temp_vector[i][j+1]){
        if(test1[i][j+1]){
                         if(sum_max<(summ)){sum_max=summ;}
                         }    
    else{      color1(i,j+1,temp_vector,st,summ);}}
      //3.2
   if(j+1<n){if(!temp_vector[i][j+1]){ if(sum_max<(summ)){sum_max=summ;}}}
      if(j+1>=n){if(sum_max<(summ)){sum_max=summ;}} 
     
     //4
     if(j-1>=0 && temp_vector[i][j-1]){
        if(test1[i][j-1]){
                         if(sum_max<(summ)){sum_max=summ;}
                         }    
    else{       color1(i,j-1,temp_vector,st,summ);}}
    //4.2
   if(j-1>=0){if(!temp_vector[i][j-1]){ if(sum_max<(summ)){sum_max=summ;}}}
      if(j+1<0){if(sum_max<(summ)){sum_max=summ;}} 
     
     }


void color(int i,int j){
   test[i][j]=false;
  if(i+1<m && test[i+1][j]){
    color(i+1,j);}
     if(i-1>=0 && test[i-1][j]){
               color(i-1,j);
     }
     if(j+1<n && test[i][j+1]){
              color(i,j+1);}
     if(j-1>=0 && test[i][j-1]){color(i,j-1);}
    
    }

int main(){
    int tc;cin>>tc;
    for(int i=0;i<tc;i++){
            int mp,np;
            cin>>mp;
            cin>>np;m=mp;n=np;A.resize(m);test.resize(m);test1.resize(m);int sum=0;
            vector<bool> ha1(m,1);
            vector<bool> ha2(n,1);
            for(int i=0;i<m;i++){A[i].resize(n);test[i].resize(n);test1[i].resize(n);
                    for(int j=0;j<n;j++){
                            cin>>A[i][j];sum+=A[i][j];
                                                        test[i][j]=true;test1[i][j]=false;
                                                        if(A[i][j]==0){test[i][j]=false;ha1[i]=false;ha2[j]=false;}
                            }
                    }cout<<endl;
                   for(int i=0;i<m;i++){cout<<"  "<<ha1[i];} cout<<endl;
                   for(int i=0;i<n;i++){cout<<"  "<<ha2[i];} cout<<endl;
                  cout<<"sum "<<sum<<"\n";
                    int temp_sum=0;
                     for(int i=0;i<m;i++){
                                    for(int j=0;j<n;j++){//if(A[i][j]<=8845){cout<<"\nk "<<A[i][j]<<"  "<<(8845-A[i][j]);}
                                            if(test[i][j]){
                                                           if((i-1)>=0 && test[i-1][j] && (i+1)<m && test[i+1][j] && (j-1)>=0 && test[i][j-1] && (j+1)<n && test[i][j+1] && test[i-1][j-1] && test[i-1][j+1]&& test[i+1][j-1] && test[i+1][j+1]){
                                                                       temp_sum+=A[i][j];test1[i][j]=true;}
                                                           
                                                           }
                                                         //  cout<<test1[i][j]<<"    ";
                                            }//cout<<"\n";
                                            }
                    
    //         /*
                     for(int i=0;i<m;i++){
                                    for(int j=0;j<n;j++){
                                            
                                            if(test1[i][j]){if(!((test1[i-1][j]||test1[i+1][j]) && (test1[i][j-1]||test1[i][j+1]))){
                                                                                             temp_sum-=A[i][j];   test1[i][j]=false;}
                                            }
                                            
                                                          //
                                                       //    cout<<test1[i][j]<<"    ";
                                            }//
                                           // cout<<"\n";
                                            }
      //              */
                    
                   //cout<<"\n temp_sum is "<<temp_sum<<endl;
                   vector<vector<bool> > st(m,vector<bool>(n,0));st=test1;
                     for(int i=0;i<m;i++){
                                    for(int j=0;j<n;j++){
                                            if(test[i][j] && (!test1[i][j])){
                                                           color1(i,j,test,st,0);
                                                           
                                                           }}}
                     
                //    cout<<"\nsum is "<<(sum_max+temp_sum)<<endl<<endl;
                cout<<(sum_max+temp_sum)<<endl;
          for(int i=0;i<m;i++){
                                  for(int j=0;j<n;j++){cout<<stamp[i][j]<<"  ";}cout<<endl;}
//            cout<<max<<endl;
            A.clear();
            test.clear();
            test1.clear();
            sum_max=0;
            }
    
    
    cout<<endl;system("pause");
    return 0;
    }
