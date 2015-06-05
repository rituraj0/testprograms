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

#define maxn 505
int mod ;
int lines;
int max_bug;
int N;
int cost[maxn];

ll memo[2][maxn][maxn];

ll solve( int p , int l , int b)
{
   if( b > max_bug)
     return 0;

   if( l > lines)
     return 0;

   if( p==N)
   {
     if( (l==lines) && (b<=max_bug))
       return 1;

     return 0;
   }

   int curr =  (p&1);//relcae it by p&1

   if( memo[curr][l][b]!=-1)
      return memo[curr][l][b];

   ll ans =0;

   //dont write cuurent line
   ans+=solve(p+1,l,b);

   //write cuuuent line
   ans+=solve( p , l+1 , b+ cost[p]);

   return  memo[curr][l][b] = (ans%mod);
}

int main()
{
  cin>>N>>lines>>max_bug>>mod;

  for(int i=0;i<N;i++)
    cin>>cost[i];


  fill(memo,-1);

  for(int p=N-1;p>=0;p--)
    {
      int curr=(p&1);//replcave by p&1

      fill( memo[curr] , -1);

     for(int l=lines;l>=0;l--)
       for(int b=max_bug;b>=0;b--)
          solve(p,l,b);
    }


    cout<<solve(0,0,0)<<endl;

}
