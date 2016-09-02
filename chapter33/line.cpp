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



Point p[TWO_SEGMENTS+1];

//GIVES anticlockwise from p2
int cross_product(Point p1,Point p2){
	int temp=p1*p2;
	if(temp>0){return NEGATIVE;}
	if(temp<0){return POSITIVE;}
	return PARALLEL;
}//cross product finish

//vector reference from pi i.e. pj-pi and pk-pi
//return: NEGATIVE if pk-pi is anticlockwise from pj-pi 
int direction(Point pi,Point pj,Point pk){
    return cross_product(pk-pi,pj-pi);
}

//point pk is on the segment pj,pi or not
bool on_segment(Point pi,Point pj,Point pk){
	if((MIN(pi.x,pj.x)<=pk.x && pk.x<=MAX(pi.x,pj.x)) && ((MIN(pi.y,pj.y)<=pk.y && pk.y<=MAX(pi.y,pj.y)))){return true;}
	return false;
}

//return p2-p1 segment and p4-p3 segments intersects or not
bool segments_intersect(Point p1,Point p2,Point p3,Point p4){

    int d1=direction(p3,p4,p1);
	int d2=direction(p3,p4,p2);
    int d3=direction(p1,p2,p3);
	int d4=direction(p1,p2,p4);

    if(((d1 == NEGATIVE && d2 == POSITIVE) || (d1 == POSITIVE && d2 == NEGATIVE)) &&
            ((d3 == NEGATIVE && d4 == POSITIVE) || (d3 == POSITIVE && d4 == NEGATIVE))){
                 return true;
                 } 
    if((d1 == 0) && on_segment(p3,p4,p1)){
           return true;
           } 
    if((d2 == 0) && on_segment(p3,p4,p2)){
           return true;
           }               
    if((d3 == 0) && on_segment(p1,p2,p3)){
           return true;
           } 
    if((d4 == 0) && on_segment(p1,p2,p4)){
           return true;
           } 
return false;	
}//segments intersect finish



void Input_two_segments(){

	FI(TWO_SEGMENTS){
		int x,y;
		cin>>x>>y;
		p[i+1].x=x;
		p[i+1].y=y;
	}
}//input two segment finish

 

int main(){

Input_two_segments();
cout<<(segments_intersect(p[1],p[2],p[3],p[4])?"INTERSECT ":"DON\"' INTERSECT");

SP;
return 0;
}

