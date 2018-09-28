#include <iostream>
#include <stdio.h>
#include <string.h> 
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        long long int N;
        long long int N1;
        cin>>N;
        N1=N;
        long long int A[N+1];
        long long int i;
        memset(A,0,sizeof(A));
        for(i=0;i<N;i++)
        {
            long long int p;
            cin>>p;
            if(p<=N)
            {
                A[p]++;
            }
        }
        int count=0;
        for(i=1;i<N;i++)
        {
            if(A[i]==0 && N1>1)
            {
                count++;
                N1--;
            }
            else if(A[i]>1 && N1>1)
            {
                count=count+(A[i]-1);
                N1=N1-(A[i]-1);
            }
        }
        cout<<count<<endl;
        
    }
	return 0;
}
