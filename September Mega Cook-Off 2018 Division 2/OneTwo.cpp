#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        int a[n];
        int sum=0,one=0;
        for(int j=0; j<n; j++){
            cin>>a[j];
            sum+=a[j];
            if(a[j]==1) one++;
        }
        if(one!=0){
        if(a[0]==2 && a[n-1]==2){
            cout<<sum-1<<"\n";
        }
        else{
            cout<<sum<<"\n";
        }
        }
        else{
            cout<<sum/2<<"\n";
        }
    }
    return 0;
