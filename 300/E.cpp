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

#define maxn 200009

vector<int> child[maxn];

int child_count[maxn];


int total_child(int u)
{
   if( sz(child[u])==0)
      return child_count[u]=1;

    child_count[u]=0;

    for(int i=0;i<sz(child[u]);i++)
       child_count[u]+=total_child(  child[u][i] );

     return child_count[u];
}

int find_mini( int u , int turn );

int find_maxi( int u , int turn)//0 => filled to maximize maxi , 1 => minimize maxi
{
  if( sz( child[u] ) == 0)
     return 1;

  int ans1=0,ans2=0;


  for(int i=0; i < sz( child[u] ) ;i++)
     {
       int v= child[u][i];

       if( turn == 0)
         {
           ans1 = max( ans1 , child_count[u] - child_count[v] + find_mini( v , turn)  );//apne hisab se rakh lo
         }
      else
        {
          ans2+= find_mini( v , turn );//jo minimuym rakh sakta hai ,usme last
        }
     }

     if( turn ==0)
       return ans1;
     else
        return ans2;
}


int find_mini( int u , int turn )
{
   if( sz( child[u]) ==0 )
     return 1;

   int ans1=1 , ans2=(1<<20);

   for(int i=0; i < sz( child[u] ); i++)
     {
           int v= child[u][i];


           if( turn == 0)
           {
              ans1+= find_maxi( v, turn ) - 1;
           }
          else
            {
                ans2 = min( ans2 , find_maxi(v, turn) );
            }

     }

     if( turn == 0)
        return ans1;
     else
        return ans2;
}

int main()
{
  int N,a,b;

  cin>>N;

  for(int i = 1; i<N; i++)
  {
    cin>>a>>b;

    child[a].pb(b);
  }

  total_child(1);

  cout<<find_maxi(1,0)<<" "<<find_mini(1,1)<<endl;

  return 0;
}