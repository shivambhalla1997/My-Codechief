#include <bits/stdc++.h>
#define start_routine clock_t begin = clock();
#define end_routine clock_t end = clock(); double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC; fprintf(stderr, "\nTime elapsed : %.3f seconds\n", elapsed_secs);return 0;
#define ll long long
#define mod 1000000007
#define upperlimit 1000100
#define INF 1000000100
#define INFL 1000000000000000100LL
#define eps 1e-8
#define endl '\n'
#define sd(n) scanf("%d",&n)
#define slld(n) scanf("%lld",&n)
#define pd(n) printf("%d",n)
#define plld(n) printf("%lld",n)
#define pds(n) printf("%d ",n)
#define pllds(n) printf("%lld ",n)
#define pdn(n) printf("%d\n",n)
#define plldn(n) printf("%lld\n",n)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define all(v) v.begin(), v.end() 
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define F first
#define S second
#define clr(a) memset(a,0,sizeof(a))
#define FILEIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);

using namespace std;

ll gcd(ll n1,ll n2){
    if(!n1)return n2;
    if(!n2)return n1;
    if(n1%n2==0)return n2;
    return gcd(n2,n1%n2);
}
ll powmod(ll base,ll exponent){
    base%=mod;
    ll ans=1;
    while(exponent){
        if(exponent&1)ans=(ans*base)%mod;
        base=(base*base)%mod;
        exponent/=2;
    }
    ans%=mod;
    return ans;
}
int arr[upperlimit+1];
int cnt[4];
int compress(int a,int b,int c,int d){
    return (a+(cnt[0]+1)*b+(cnt[0]+1)*(cnt[1]+1)*c+(cnt[0]+1)*(cnt[1]+1)*(cnt[2]+1)*d);
}
bitset < 76*76*76*76 > win;
bitset < 76*76*76*76 > visited;
void dfs(int a,int b,int c,int d){
    visited[compress(a,b,c,d)]=true;
    if(a==cnt[0] && b==cnt[1] && c==cnt[2] && d==cnt[3]){
        int temp=(a*0+b*1+c*2+d*3)&3;
        if(temp==2)win[compress(a,b,c,d)]=true;
        else win[compress(a,b,c,d)]=false;
        return;
    }
    int temp=(a*0+b*1+c*2+d*3)&3;
    if(temp==2)win[compress(a,b,c,d)]=true;
    else{
        win[compress(a,b,c,d)]=false;
        if(a!=cnt[0]){
            if(!visited[compress(a+1,b,c,d)])dfs(a+1,b,c,d);
            if(!win[compress(a+1,b,c,d)]){
                win[compress(a,b,c,d)]=true;
                return;
            }
        }if(b!=cnt[1]){
            if(!visited[compress(a,b+1,c,d)])dfs(a,b+1,c,d);
            if(!win[compress(a,b+1,c,d)]){
                win[compress(a,b,c,d)]=true;
                return;
            }
        }if(c!=cnt[2]){
            if(!visited[compress(a,b,c+1,d)])dfs(a,b,c+1,d);
            if(!win[compress(a,b,c+1,d)]){
                win[compress(a,b,c,d)]=true;
                return;
            }
        }if(d!=cnt[3]){
            if(!visited[compress(a,b,c,d+1)])dfs(a,b,c,d+1);
            if(!win[compress(a,b,c,d+1)]){
                win[compress(a,b,c,d)]=true;
                return;
            }
        }
    }

}
int main()
{
    start_routine;

    int t,i,j,k,n,a,b,c,d;
    sd(t);
    // t=1;
    while(t--){
        sd(n);
        // n=300;
        clr(cnt);
        for(i=1;i<=n;i++){
            sd(arr[i]);
            // arr[i]=i;
            arr[i]%=4;
            cnt[arr[i]]++;
        }
        win.reset();
        visited.reset();
        dfs(0,0,0,0);
        if(win[0])printf("Ghayeeth\n");
        else printf("Siroj\n");
    }

    end_routine;
}
