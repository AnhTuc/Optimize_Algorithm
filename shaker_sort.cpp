#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void ShakerSort(double *a, int n){
    bool flag=true;
    int m=0;
    //Sort the array
    while(flag){
        //assumes that the array now is sorted
        flag=false;
        m++;

        for(int i=n;i>=m; i--){
            if(a[i] < a[i-1]) {
                //the array is not sorted
                flag =true;
                double temp=a[i];
                a[i]=a[i-1];
                a[i-1]=temp;
            }
        }
        
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
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
    ShakerSort(a,n);

    return 0;
}