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


pair<int,string> next ( pair<int,string> in)
{
   string a= in.Y.substr( 0 ,in.X);

   string b = in.Y.substr( in.X);

   if( a[0] < b[0] )
   {
      b=b+a[0]+b[0];
      b=b.substr(1);
      a=a.substr(1);
      in.X--;
   }
   else
   {
     a=a+b[0]+a[0];
     a=a.substr(1);
     b=b.substr(1);
     in.X++;
   }

   return mp( in.X , a+b);
}


map< pair<int,string> , bool > done;

int main()
{
   int n;
   
   cin>>n;
   
   int k;

   cin>>k;

   string curr = string(k,'.');

   for(int i=0,a=0;i<k;i++)
   {
       cin>>a;

       curr[i]=(char)('a'+(a-1));
   }


   int k2;

   cin>>k2;

   string sec = string(k2,'.');

   for(int i=0,a=0;i<k2;i++)
   {
       cin>>a;

       sec[i]=(char)('a'+(a-1));
   }

//   print(curr);
  // print(sec);

   curr+=sec;

   pair<int,string> st=mp(k,curr);

   int step=0;

   while(1)
   {
      step++;

      st = next(st);

      if( st.X == 0 )
      {
         cout<<step<<" 2"<<endl;
         return 0;
      }
      else if( st.X == n)
      {
         cout<<step<<" 1"<<endl;
         return 0;
      }

      if( done.count(st))
      {
         cout<<"-1"<<endl;
         return 0;
      }

      done[st]=true;
   }


   return 0;
}