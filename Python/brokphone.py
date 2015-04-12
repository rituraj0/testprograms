def solve():
	n = int( input() );
	ins = raw_input();
	lst = ins.split();
	A = list(map(int, lst));
	ans = 0 ;
	for i in range(0,n):
		can = 0 ;
		if( i > 0):
			if( A[i] != A[i-1] ):
				can = 1;

		if( i < n - 1 ):
			if( A[i] != A[i+1]):
				can = 1;
		ans+=can;
	print(ans);


test = int( input() )
while( test > 0):
	solve();
	test=test-1;
