#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
typedef long long ll;
#define pdd pair<double,double>
#define pb push_back
#define mp make_pair
#define X  first
#define Y second
#define pll pair<ll,ll> 



pdd init;



double angle( pdd  a)
 {
 	 pdd temp=mp(a.X-init.X , a.Y-init.Y);
 	 
 	 return acos( a.X /sqrt( a.X*a.X + a.Y*a.Y) );
 }

bool comp(pdd a , pdd b )
{
	 return ( angle(a) <angle(b) );
	
}

int cross_product( pdd a , pdd b , pdd c)
{
	 return ( b.X-a.X)*(c.Y-a.Y)-(b.Y-a.Y)*(c.X-a.X);
}


ll area( pll a, pll b, pll c)
{
	ll x1= a.X , x2= b.X , x3= c.X;
	ll y1= b.Y , y2= b.Y , y3= c.Y;

   return x1*(y2-y3) + x2*( y3-y1) + x3*(y1-y2);
}

vector<pll>  solve( vector<pdd> input)
{
	init.X=init.Y=(1LL<<55);
    
    int n = input.size();

    init.X=init.Y=(1LL<<55);

	for(int i=0;i<n;i++)
	 {
	   
	    if( input[i].Y > init.Y)
	     init=input[i];
	    else if( input[i].Y==init.Y && input[i].X < init.Y)  
	        init=input[i];      
	         
     }
	 
	 sort( input.begin() , input.end() , comp );
	 

    vector< pll > ans;
	 
	for(int i=0;i<3;i++)
	 ans.pb( mp(input[i].X , input[i].Y) );
	 
	 for(int i=3;i<n;i++)
	  {
	  	 while(  ans.size() >= 2 && cross_product( ans[ ans.size()-2], ans[ ans.size()-1] , input[i]  ) <= 0 )
	  	   ans.pop_back();
	  	   
	  	   ans.pb( mp(input[i].X , input[i].Y) );
	  }

//	  for(int i=0;i<((int)ans.size());i++)
//	  	cout<<ans[i].X<<"  "<<ans[i].Y<<endl;

	  return ans;
}


vector< pll> conv[1<<16];

void go(int test)
{
	 int n;
	
	 cin>>n;

	 vector<pdd> input;

	  input.resize(n);

	 for(int i=0;i<n;i++)
	 {
	    cin>>input[i].X>>input[i].Y;
	   //cin>>>>;
	 	//input[i].X=i;
	 	//input[i].Y=0;
	}

	if( n <=3)
	{
		printf("Case #%d:\n",test);

		for(int i=0;i<n;i++)
			cout<<"0\n";
		return;
	}

	vector<pll> dum;

	for(int i=0;i<(1<<16);i++)
		 conv[i]=dum;

	cout<<conv[5].size()<<endl;

	for(int mask=0;mask<(1<<n);mask++)//
	{
		if( __builtin_popcount(mask) <= 3)
			continue;

		vector< pdd> tp;

		for(int i=0;i<n;i++)
			 if( mask &(1<<i))
			 	  tp.pb( input[i] );

	   conv[mask]=solve(tp);
	}

	printf("Case #%d:\n",test);

	for(int t=0;t<n;t++)//for each tree
	{
		int ans = 1000;

		pll curr = mp( input[t].X , input[t].Y );

		for(int mask=0;mask<(1<<n);mask++)//for each subset
			 if( mask & (1<<t))
			 	 if( conv[mask].size() >=2)//can all be linear
			 	 	 {
			 	 	 	vector< pll> pt = conv[mask];
			 	 	 	int cn = pt.size();

			 	 	 	bool mila = false;

			 	 	 	for(int i=0;i<cn-1;i++)//i & i+1 k bich me shayad
			 	 	 		  if( area( pt[i] , pt[i+1] , curr  ) ==0 )
			 	 	 		  	 {
			 	 	 		  	  mila=true;
			 	 	 		  	  break;
			 	 	 		  	}

			 	 	     int ps = 	__builtin_popcount(mask);
			 	 	     
			 	 	     ans = min( ans , n - ps)	  	;
			 	 	 }

		assert( ans != 1000);

		cout<<ans<<endl;

	}


}
int main()
{
	ios_base::sync_with_stdio(false);

	int test;

	cin>>test;

	for(int i=1;i<=test;i++)
	  go(i);

	return 0;
}