#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


bool Change_making(vector<int> a, int value, int i, int start, int[][] temp){
    //to find the smallest coin denomination

    //base condition when we can or cannot find
    if(i>a.size() && value>0){
        i=0;
        return false;
    }
    if(value==0){
        i=0;
        for(int k=0;k<i;k++){
            cout<<temp[k][0]<<":"<<temp[k][1]<<endl;
        }
        return true;
    }
    else if(value< *(a.end())) {
        i=0;
        return false;
    }

    for(int k=start;k<=a.size();k++){
        temp[i][0]=a[k];
        temp[i][1]=value/a[k];
        value%=a[k];
        Change_making(a,value,i+1,k+1, temp);
    }
    
}


void ReadFile(string input, vector<int> a, int& value){
    ifstream ifs(input);
    if(!ifs){
        cout<<"Error open file"<<endl;
        return;
    }
    
    int temp;
    ifs>>temp;
    while(ifs){
        a.push_back(temp);
        ifs>>temp;
    }

    value=*(a.end());
    a.pop_back();

}

int main(){
    vector<int> a;
    int value=0;

    ReadFile("input.txt",a,value);
    ShakerSort(a,n);

    return 0;
}