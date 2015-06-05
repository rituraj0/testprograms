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


vector<int> match(string text , string pat)
{
    vector<int> fall = fail(pat);

    vector<int> ans;

    int n= sz( text) , m = sz(pat);

    int len=0;//len of cuurnet matched

    for(int i=0;i<n;i++)
    {
        while( (len > 0) &&( text[i] != pat[len]) )
         len = fall[ len -1];

        len+=( text[i] == pat[len] );

        if( len == m)
        {
            ans.pb(i-m+1);
            len = fall[ len-1];
        }
    }

    //print( sz(ans));

    return ans;
}


int main()
{
    int test;

    string text,pat;


    while( cin>>test)
    {
        cin>>pat>>text;

        vector<int> ans = match( text , pat);

        for(int i=0;i<sz(ans);i++)
         cout<<ans[i]<<endl;

         cout<<endl;
    }
    return 0;
}
