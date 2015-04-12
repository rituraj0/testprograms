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

ll solve( ll in)
{
    ll ans =0 ;

    for(ll i=1;i*i<=in;i++)
       if( in%i==0)
       {
           ans += i;

           ll ot = in/i;

           if( ot !=i)
             ans+= ot;
       }

    return ans;
}
int main()
{

  int test;

  cin>>test;

  while( test--)
  {
      ll x;
      cin>>x;
      cout<<solve(x)<<endl;
  }

}
