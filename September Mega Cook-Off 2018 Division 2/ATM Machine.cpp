#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        long long int N,K,i;
        cin>>N>>K;
        long long int val;
        for(i=0;i<N;i++)
        {
            cin>>val;
            if(K>=val)
            {
                cout<<"1";
                K=K-val;
            }
            else
            {
                cout<<"0";
            }
        }
        cout<<endl;
    }
	return 0;
}
