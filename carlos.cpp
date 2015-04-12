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

#define maxc 205
#define maxn 200005

bool can[maxc][maxc];//(i , j ), can tranfrom (i->j )
int  just[maxc][maxc];//i  prev ,j curr , find smallest gretart than k such that can[j][k] and k > i

int memo[maxn][maxc];
int  M , K , N;

int in[maxn];

int solve( int curr , int prev)
{
    if( curr == N +1)
     return 0;

    if( memo[curr][prev] != -1)
      return  memo[curr][prev] ;

    int ans = (1<<20) ;
    memo[curr][prev] = ans;

    int here = in[curr];//original char at this poistion

     //try just larger than this
     //if we are going to change current ,
     // its always optimal to replcae withsmaleest possible higher
     if( just[prev][ here ]  <= M )
        {
             int tp = solve( curr + 1, just[prev][ here ] );

             if( just[prev][ here ] !=  here )
                tp++;

             ans = min( ans , tp );
        }

     //try same letter
     if( here >= prev )
        {
            int tp = solve( curr+1 , here );

            ans = min( ans , tp );
        }

    return memo[curr][prev] = ans;
}

void process()
{
    scanf("%d%d%d",&M,&K,&N);

    fill( can , 0);

    for(int i=1;i<=M;i++)
        can[i][i]=true;

    int a, b;

    for(int i=1;i<=K;i++)
    {
        scanf("%d%d",&a,&b);

        can[a][b]=true;
    }

    //floyd warshall

    for(int k=1;k<=M;k++)
      for(int i=1;i<=M;i++)
       for(int j=1;j<=M;j++)
         can[i][j] = ( can[i][j] || ( can[i][k] && can[k][j] ) );



    // find  prev, curr , just
    for(int p=1;p<=M;p++)
     for(int c=1;c<=M;c++)
       {
           just[p][c]= M + 10;

             for(int k = p ;k<=M;k++)
                if( can[c][k] )
                 {
                     just[p][c]=k;
                     break;
                 }
       }

    /*cout<<" can \n";

    for(int i=1;i<=M;i++,cout<<endl)
      for(int j=1;j<=M;j++)
        cout<<can[i][j]<<"  ";

     cout<<"  \njust \n";
     for(int i=1;i<=M;i++,cout<<endl)
      for(int j=1;j<=M;j++)
        cout<<just[i][j]<<" ";

     cout<<"   \n\n ";
*/

   //take input

   for(int i=1;i<=N;i++)
     scanf("%d",&in[i]);

   //start dp

   fill( memo , -1 );

   int ans = (1<<20);

   for(int i=1;i<=M;i++)
     if( can[ in[1] ][i] )
        {
            int tp = solve(2,i);

            if( i != in[1] )
              tp++;

             ans = min(ans , tp);
        }

    if( ans > N)
      {
          cout<<"-1"<<endl;
     //     printf("-1\n");
      }
    else
    {
        cout<<ans<<endl;

      // printf("%d\n",ans);
    }


}

int main()
{
  int test;

  scanf("%d",&test);

  while(test--)
  {
      process();
  }

  return 0;
}


