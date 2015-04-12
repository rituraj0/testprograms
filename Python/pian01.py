def solve():
	st = raw_input();
	req=0;
	for i in range( len(st)):
		if( st[i]=='S'):
			req+=1;
		else:
		 	req+=2;

	n = int(input());

	aval = n*12;
	ans=0
	for i in range(1,aval):
		can = aval-i;
		ans+=can/req;
	print(ans);


test = int( input() );

while( test > 0):
	test-=1;
	solve();
