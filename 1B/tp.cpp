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

#define maxn (1000)

int ulta[maxn];

inline void rever( int in)
{
   int ans =0;
   int save= in;

   while(in!=0)
   {
      ans = ans * 10;
      ans = ans + in%10;
      in = in/10;
   }

   ulta[save]=ans;
}

int dist[maxn];
int done[maxn];
int prev[maxn];


queue<int> Q;

void path( int in)
{
    cout<<"********  "<<in<<"       "<<endl;
   while( in >= 0)
   {
       cout<<in<<" ";
       in=prev[in];
   }
}

void process()
{
   fill(dist,-1);
   fill(done,0);
   fill(prev,-1);

   dist[1]=1;
   Q.push(1);

   int mx =0;
   int id=-1;

   vector<int> tp;

   while(!Q.empty())
   {
       int curr= Q.front(); Q.pop();

       if( curr >= maxn)
         continue;

       //add 1
       if( dist[curr+1]==-1)
       {
         dist[curr+1]=dist[curr]+1;
         done[curr+1]=done[curr];
         prev[curr+1]=curr;
         Q.push(curr+1);
       }

       if( dist[ ulta[curr] ]==-1)
       {
           dist[ ulta[curr] ] = dist[curr]+1;
           Q.push( ulta[curr] );
           done[ ulta[curr] ]=done[curr]+1;
           prev[ ulta[curr] ]=curr;

           if( mx < done[ ulta[curr] ] )
           {
               mx = done[ ulta[curr] ];
               id= ulta[curr];
           }

           //assert( (ulta[curr]))
            tp.pb( ulta[curr]);
           //cout<<ulta[curr]<<" D:"<<dist[ ulta[curr] ]<<"***"<<curr<<" D:"<<dist[curr]<<endl;
       }
   }

    sort(tp.bg,tp.en);

   for(int i=0;i<sz(tp);i++)
    cout<<tp[i]<<endl;



}

void solve(int test)
{
   int ans=0;

   int in;

   cin>>in;

   printf("Case #%d: %d\n",test,dist[in]);

}


int main()
{

    for(int i=1;i<maxn;i++)
      rever(i);

     process();

    int test;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        solve(i);
    }

    return 0;
}
