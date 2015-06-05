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


int main()
{
  int n;

  cin>>n;


  vector<ll> req(n);


  for(int i=0;i<n;i++)
      cin>>req[i];

   sort( req.begin() , req.end() );

   int ans = 0;

   ll wait = 0;


   for(int i=0;i<n;i++)
   {
      if( wait <= req[i])
         {
            ans++;

            wait+=req[i];
         }
   }

   cout<<ans<<endl;

   return 0;
}