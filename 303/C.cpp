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

#define maxn 100009
ll pos[maxn], ht[maxn];
int N;

int memo[maxn][3];

int solve( int curr  , int pd)//current node and our last tree deciiosn 0 , uncut  1 m faalen to left , 2 fallenn to right
{
   if( curr >= N)
      return 0;

    if( memo[curr][pd] !=-1 )
        return memo[curr][pd];

    int ans = 0;

    memo[curr][pd]=ans;

    //dont curt his tree

    ans = max( ans , solve( curr + 1 , 0) );


 // ****
    int last = pos[curr-1];

    if( pd==2)
      last+=ht[curr-1];  
    //if possible , cut to left
     if( last < pos[curr] - ht[curr)
        ans = max( ans , solve(curr + 1 ,1 ) +1 );

    //if possible , cut to right

    if( pos[curr] + ht[curr] < pos[curr+1] )
       ans = max( ans , solve( curr +1  , 2) +1 );

    return memo[curr][pd]=ans; 
 

}

int main()
{


  cin>>N;

  for(int i=1;i<=N;i++)
      cin>>pos[i]>>ht[i];

    if( N <=2 )
       {
         cout<<N<<endl;
         return 0;

       }

  fill( memo , -1);

  int ans = solve(2,1)+2;//1 to left , last to right    
  
   cout<<ans<<endl;

   return 0;
}