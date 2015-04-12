def solve():
	n = long ( input() );
	ans = long (0);
	i = long (1)
	
	while(i*i <= n):
		if( n%i==0):
			ans+=i;
			ot = n /i;
			if(ot!=i):
				ans+=ot;
		i+=1;
	print(ans);




test = int( input() );

while( test > 0):
	solve();
	test-=1;