#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<math.h>

using namespace std;


struct Point{
    int x;
    int y;
}

const double pi=3.14;
double computeAngle(Point x, Point y){
    double angle=atan2(y.y-x.y,y.x-x.x);
    return angle>0? angle: angle+2*pi;
}

Point findNextExtremePoint(Point* a, int n, Point cur, double& curAngle){
    double minAngle=2*pi;
    Point next;

    for(int i=0;i<n;i++){
        if(a[i].x==cur.x){
            if(a[0].y==cur.y) continue;
        }

        double newAngle=computeAngle(cur,a[i]);
        if(newAngle<minAngle && newAngle>=curAngle){
            minAngle=newAngle;
            next=a[i];
        }
    }
    
    curAngle=minAngle;
    return next;
}

void computeConvexHull(Point* a, int n){
    vector<Point> convexHull;
    convexHull.push_back(a[0]);

    double curAngle=0.0;
    Point cur=a[0];
    while(true){
        Point next=findNextExtremePoint(a,n,cur,curAngle);
        
        if(a[0].x==next.x){
            if(a[0].y==next.y) {
                showBounding(convexHull);
                return;

            }
        }

        convexHull.push_back(next);
        cur=next;

    }
}

void ReadFile(string input, Point* a, int& n){
    ifstream ifs(input);
    if(!ifs){
        cout<<"Error open file"<<endl;
        return;
    }
    
    int temp;
    ifs>>temp;

    if(temp){
        n=temp;
        a=new Point[n];
        for(int i=0;i<n;i++)
        {
            a.y=0;
            a.x=0;
        }
    }
    else{
        cout<<"Error reading file"<<endl;
        return;
    }//end if-else

    while(ifs && temp>0){
        temp--;
       ifs>>a[temp].x;
       ifs>>a[temp].y;
    }


}

int main(){
    Point* a;
    int n;

    ReadFile("input.txt",a,n);
    computeConvexHull(a,n);

    return 0;
}