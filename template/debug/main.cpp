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

#define maxn 1005

string in[maxn];
int row, col;

bool inbound( int i , int j)//no need to implement , jsut append $ in begiining and end of inoput string
{
   return true;
}
bool needtochange( int i , int j)
{
    if( !inbound(i,j))
        return false;

    //itarete though all 2x2squres , it can be a part of


}


int main()
{

   cin>>row>>col;

   in[0]=string(col+4,'$');

  // cout<<in[0][4]<<sz(in[0])<<endl;

   for(int i=1;i<=row;i++)
   {
       cin>>in[i];
       in[i]="$"+in[i]+"$";
   }

   return 0;
}
