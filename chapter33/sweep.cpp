#include<iostream>
#include<cmath>
#include<list>
#include<stack>
#include<utility>
#include<bitset>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include <map>
#define INF (1<<30)
#define null NULL
#define FI(sz) for(int i=0;i<sz;i++)
#define FJ(sz) for(int j=0;j<sz;j++) 
#define PB push_back
#define ALL(v) (v).begin(),(v).end()
#define SP system("pause");
#define OP cout<<endl
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NEGATIVE 0
#define POSITIVE 1
#define PARALLEL 2
#define MIN(x,y)  (x<y?x:y)
#define MAX(x,y)  (x>y?x:y)

#define TWO_SEGMENTS 4
using namespace std;


struct Point{

       int x;
       int y;

       Point(){x=0;y=0;}

	   

       Point(int xx,int yy){
                 x=xx;
                 y=yy;
                 }

       void operator= (Point &arg){
          	 x=arg.x;
		     y=arg.y;
             }

       Point operator+ (Point &arg){
             Point temp;
             temp.x=x+arg.x;
             temp.y=y+arg.y;
             return temp;
             }

       Point operator- (Point &arg){
             Point temp;
             temp.x=x-arg.x;
             temp.y=y-arg.y;
             return temp;
             }
  
       //cross product
      int operator* (Point &arg){
            return (x*arg.y-arg.x*y);
       }

       //dot product
       int operator/ (Point &arg){
          return (x*arg.x+arg.y*y);
        }
    };



int main(){
    
    
        
    system("pause");
    return 0;
    }
