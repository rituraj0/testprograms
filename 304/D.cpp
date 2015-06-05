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

#define maxn (5000009)

int cont[maxn];
bool prime[maxn];

int main()
{ 

  fill(cont,0);
  fill(prime, true);

  for(int i=2 ;i<maxn;i++)
      if( prime[i])
         {
              cont[i]=1;

             for(int j=i+i;j<maxn;j+=i)
               {
                  prime[j]=false;

                  int cn = 0;

                  int tp=j;

                  while( (tp % i )==0)
                  {
                    cn++;
                    tp=tp/i;
                  }

                  cont[j]+=cn;
               }
         }

  for(int i=1;i<maxn;i++)
    cont[i]+=cont[i-1];

  int test,a,b;

  scanf("%d",&test);

  while(test--)
  {
      scanf("%d%d",&a,&b);

      printf("%d\n",cont[a]-cont[b]);
    //cout<<<<endl;
  }

}