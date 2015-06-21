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

vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}


/*Solution code starts here */


vector<ll> save;
int stud,pilecount;
ll allpile=0;

bool cando( ll maxtime)
{
  vector<ll> pile=save;

  ll done=0;
  int curr=1;

  for(int i=0;i<stud;i++)
  {
      ll rem = maxtime-curr+1;

      while( curr <= pilecount)
      {
        if( rem <=0 )
          break;

        rem-=1;
        ll can=min( rem , pile[curr-1] );
        pile[curr-1]-=can;
        rem-=can;

        done+=can;

        if( pile[curr-1] == 0)
          curr++;

        if( rem == 0)
          break;
      }
  }

  return (done == allpile);
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  cin>>pilecount>>stud;

  save.resize(pilecount);

  allpile=0;

  for(int i=0;i<pilecount;i++)
  {
    cin>>save[i];
    allpile+=save[i];
  }

  ll lo=0;
  ll hi=allpile+pilecount;

  while(lo<hi)
  {
    ll mid =(lo+hi)/2LL;

    if( cando(mid))
    {
      hi=mid;
    }
    else
    {
      lo=mid+1;
    }
  }

  cout<<hi<<endl;

  return 0;
}