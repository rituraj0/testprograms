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

ll req=0;
ll W=0;

ll value[101];
ll maskval[1<<20];

bool mila=false;

vector<int> opt;

int maxlen=100;

void solve(int len , int A, int B)
{
    if( len == maxlen)
       {
         if( maskval[A] - maskval[B] == req)
         {
          cout<<"YES\n";
          exit(0);
         }
         return;
       }

    solve( len +1 , A, B );
    solve( len+1 , A|(1<<len)  ,  B);
    solve( len+1 , A           ,  B|(1<<len) );
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  cin>>W>>req;

  if( W <= 3)
  {
    cout<<"YES\n";
    return 0;
  }

  value[0]=1;

  for(int i=1;i<100;i++)
  {
    value[i]=value[i-1]*W;

    if( value[i] >= 2LL*req)
    {
        maxlen=i;
        break;
    }
  }

  fill(maskval ,0);

  for(int i=0;i<(1<<maxlen);i++)
  {
     for(int j=0;j<maxlen;j++)
       if( i & (1<<j))
         maskval[i]+=value[j];
  }

  //print(maxlen);
  //print( pow(3,16));
  //print(sz(opt));

  solve(0,0,0);

  cout<<"NO\n";

  return 0;
}