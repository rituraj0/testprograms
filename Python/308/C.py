import sys;


maxpow=100;
value = [ 0 for x in range(101) ];
maskvalue=[ 0 for x in range(1<<17)];
req=0;
W=0;
opt=[];


def solve(done, A , B):
	if( done == maxpow ):
		mila = maskvalue[A] - maskvalue[B];
		if( mila == req):
			print("YES");
			sys.exit(0);
		return;

	solve(done+1,  A           , B );
	solve(done+1,  A|(1<<done) , B  );
	solve(done+1,  A           , B|(1<<done) );
	return;


if( __name__ == '__main__' ):
	W,req=map(long , ( str(raw_input())).split() );

	if( W<=3):
		print("YES");
		sys.exit();

	value[0]=1;
	for i in range(1,100,1):
		value[i]=value[i-1]*W;
		if( value[i] >= 2*req):
			maxpow=i;
			break;

	for i in range(1<<maxpow):
		for j in range(maxpow):
			if( i & (1<<j)):
				maskvalue[i]+=value[j];

	#for i in range(1<<maxpow):
	#	print( maskvalue[i]);
	#print(maxpow);
	solve(0,0,0);

	print("NO");