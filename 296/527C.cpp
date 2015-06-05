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
#define maxn  200009

bool row_in[maxn] , col_in[maxn];

int row_L[maxn] , row_R[maxn];

int col_L[maxn] , col_R[maxn];

int row,col,Q;


vector< pair<char,int> > query;

int main()
{
  cin>>col>>row>>Q;//Width,

  query.resize(Q);

  fill( row_in,0);
  fill( col_in,0);


  fill( row_R , -1);
  fill( row_L , -1);

  fill( col_L , -1);
  fill( col_R , -1);

  row_in[0]=row_in[row]=true;

  col_in[0]=col_in[col]=true;

  for(int i=0;i<Q;i++)
  {
      cin>>query[i].X>>query[i].Y;

      if( query[i].X == 'H' )
        row_in[ query[i].Y ] =true;
      else
        col_in[ query[i].Y ] = true;
  }


  //Make row_in 

  int prev=-1;

  for(int i=0;i<=row;i++)
    if( row_in[i])
    {
       if( prev !=-1 )
        { row_L[i]=prev;
          row_R[ prev] =i;
        }

        prev=i;
    }

  //Make col in

  prev = -1;

  for(int i=0;i<=col;i++) 
     if( col_in[i] )
       {
          if( prev != -1)
          {
            col_L[i] = prev;
            col_R[ prev ] = i;
          }

          prev=i;
       }

  vector<ll> ans;

  //for last 
   ll max_row = 0 ,  max_col=0;

  for(int i=1;i<=row;i++)
      if( row_in[i] )
          {
              max_row = max( max_row ,  (ll)(i - row_L[i] ));
          }

  for( int i=1 ;i<=col;i++)
      if( col_in[i] )
      {
        max_col = max( max_col , (ll)(i - col_L[i] ));
      }

  ans.pb( max_col * max_row);


  for(int i = sz( query) -1 ; i>0 ;i--)
  {
     //merger cuurent
     if( query[i].X == 'H')//row wise
     {
        ll curr = query[i].Y;
        ll prev= row_L[curr];
        ll next = row_R[curr];

        max_row = max( max_row , next - prev);

        row_L[next]=prev;
        row_R[prev]=next;
     }
    else
    {
        ll curr = query[i].Y;

        ll prev = col_L[curr];
        ll next = col_R[curr];

        max_col = max( max_col , next - prev);

        col_L[next]=prev;
        col_R[prev]=next;
    }

      ans.pb( max_col * max_row);
  }

  for(int i= sz(ans)-1 ; i>=0 ;i--)
    cout<<ans[i]<<endl;

   return 0;
}