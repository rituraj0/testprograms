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

vector<int> fail(string in)
{
    int n=sz(in);

    vector<int> ans(n,0);//store the lenght of prefix == suffix

    for(int i=1;i<n;i++)
    {
      ans[i]=ans[i-1];

      while( (ans[i] > 0) && ( in[ ans[i] ] != in[i]) )
        ans[i]=ans[ ans[i] -1 ];

     ans[i]+=( in[ ans[i] ] == in[i] );
    }

    return ans;
}


#define maxn (1<<20)
int said[maxn];
int sum[maxn];
bool good[maxn];

vector<int> tp ;
string pat;

int main()
{
    fill(said,0);
    fill(sum,0);
    fill(good,0);

    int N,m;

    cin>>N>>m;

    cin>>pat;

    for(int i=1;i<=m;i++)
      cin>>said[i];

   vector<int> tp = fail(pat);


   //for(int i=0;i<sz(pat);i++)
    //cout<<tp[i]<<" ";

   int curr = tp[ sz(pat)-1 ];

   while( curr > 0)
   {
      //   print(curr);

        good[ curr ]=true;
        curr=tp[curr-1];
   }


   for(int i=2;i<=m;i++)
   {
       int len = (said[i-1] + sz(pat) -1) - said[i] + 1 ;//overlapping

       if( len <= 0)
        continue;//no overlapping

       if( !good[len])
        {
            cout<<"0\n";
            return 0;
        }

   }

   for(int i=1;i<=m;i++)
   {
       sum[ said[i ] ]++;
       sum[ said[i] + sz(pat) ]--;
   }

   int cn = 0;

   for(int i=1;i<=N;i++)
   {
       sum[i]+=sum[i-1];

       if(sum[i] == 0)
        cn++;
   }

   ll ans =1;

   for(int i=1;i<=cn;i++)
     {
         ans = (ans *(26LL) )%(1000000007LL);
     }

    cout<<ans<<endl;

    return 0;
}
