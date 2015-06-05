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

#define maxn 3005

vector<int> graf[maxn];
int dist[maxn][maxn];

bool done[maxn];

void bfs( int u )
{
  queue<int> Q;

  fill( done , 0);

  Q.push(u);
  dist[u][u]=0;


  while(!Q.empty())
  {
    int curr = Q.front() ; Q.pop();

    if( done[curr])
       continue;

    done[curr]=true;

    int d= dist[u][curr];

     for(int i=0;i < sz( graf[curr]) ; i++)
        {
          int v = graf[curr][i];

          if( dist[u][v] == -1)
             {
               dist[u][v]=d+1;
               Q.push(v);
             }
        }
  }

}

int a,b,x;
int c,d,y;
int N,m;


int solve( )
{
  int ans = (1<<25);

  for(int e=1;e<=N;e++)
      for(int f=1;f<=N;f++)
          {
            int ab = dist[a][e] + dist[e][f] + dist[f][b];
            int cd = dist[c][e] + dist[e][f] + dist[f][d];

            if( (ab <=x ) && (cd<=y))
            {
               int tp = ab + cd - dist[e][f];

               ans= min( ans , tp);
            }
          }

  return ans;
}



int main()
{

  cin>>N>>m;

  int s,t;

  for(int i=0;i<m;i++)
    {
      cin>>s>>t;

      graf[s].pb(t);
      graf[t].pb(s);
    }

  fill( dist , -1);

  for(int i=1;i<=N;i++)
    bfs(i);


  for(int i=1;i<=N;i++)
     for(int j=1;j<=N;j++)
        {
            if( dist[i][j] != dist[j][i] )
             print("lol");

            if( dist[i][j] == -1)
                dist[i][j]=(1<<25);
        }


  cin>>a>>b>>x;

  cin>>c>>d>>y;

 // print( dist[a][b]);
  //print( dist[c][d]);

  int ans = (1<<25);

  //direct path

  if( (dist[a][b] <= x) && (dist[c][d] <=y))
   ans = min( ans ,  dist[a][b] + dist[c][d]);

//0 - 0
  ans = min( ans , solve() );

//1 - 0
  swap(a,b);
  ans = min( ans , solve() );

//1 - 1
  swap(c,d);
  ans = min( ans , solve() );

//0 -1
  swap(a,b);
  ans = min( ans , solve() );


  if( ans > m )
  {
    cout<<"-1\n";
    return 0;
  }

  cout<<m-ans<<endl;

  return 0;
}
