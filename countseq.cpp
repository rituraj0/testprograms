#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
#define sz(s) ((int)(s.size()))

#define mod 1000003
/* This function calculates (a^b)%MOD */
long long pow(int a, int b, ll MOD)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n, ll MOD)
{
    return pow(n,MOD-2,MOD);
}

long long C(int n, int r, ll MOD)
{
    vector<long long> f(n + 1,1);
    for (ll i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}



long long Lucas(int n, int m, ll p)
{
    if (n==0 && m==0) return 1;
    int ni = n % p;
    int mi = m % p;
    if (mi>ni) return 0;
    return (Lucas(n/p, m/p, p) * C(ni, mi, p))%p;
}

long long Cs(int n, int r, ll MOD)
{
    return Lucas(n, r, MOD);
}


void solve()
{
    int n,l,r;

    cin>>n>>l>>r;

    int aval = r-l+1;

    cout<<(Cs(aval+1+n-1 , n  , mod)-1+mod+mod)%mod<<endl;

}





int main()
{

    int test;

    cin>>test;

    while(test--)
    {
        solve();
    }
}
