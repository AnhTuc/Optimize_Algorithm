#include<iostream>
#include<string>
#include<fstream>

using namespace std;


void MaxCountContSub(double *a, int n){
    double maxSum=0, tempSum=0;
    //indicates where the sub array
    int startTemp=0, startMax=0;
    int endMax=0;

    //dynamic version of finding the largest sub sum
    for(int i=0;i<n;i++){
        tempSum+=a[i];
        if(tempSum>maxSum){
            maxSum=tempSum;
            endMax=i;
            startMax=startTemp;
        }
        else if(tempSum<0){
            //try to find another bigger sum in the rest part of the array
            startTemp=i+1;
        }
    }

    for(int i=startMax;i<=endMax;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<maxSum<<endl;
}


void ReadFile(string input, double *a, int& n){
    ifstream ifs(input);
    if(!ifs){
        cout<<"Error open file"<<endl;
        return;
    }
    
    ifs>>n;
    if(n>=0){
        double* a=new double[n];

        for(int i=0;i<n;i++){
            char temp;
            ifs>>temp;

            double d=0.0;
            int heso1=10;
            int heso2=1;
            bool isReal=false;

            while(temp){
                if(temp=='.') {
                    heso1=1;
                    isReal=true;
                }
                else{
                    if(isReal) heso2=heso2*0.1;
                    d=d*heso1 + int(temp)*heso2;
                }

                ifs>>temp;
            }

            a[i]=d;
        }
            


    }
    else cout<<"Invalid array length"<<endl;
}

int main(){
    double *a;
    int n=0;

    ReadFile("input.txt",a,n);
    MaxCountContSub(a,n);

    return 0;
}