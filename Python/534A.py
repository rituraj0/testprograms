def solve():
	n = int ( input() );

	if( n <= 2):
		print("1");
		print("1");
		return;
	elif( n==3):
		print("2");
		print("1 3");
		return;
	elif( n==4):
		print("4");
		print( "3 1 4 2");
		return;

	ans = [ -10 for x in range(n+10) ]

	j =1;
	for i in range( 1, n+1 , +2):
		ans[i]=j;
		j+=1;

	for i in range( 2 , n+1 , +2 ):
		ans[i]=j;
		j+=1;

	print(n);
	for i in range(1,n+1):
			print( ans[i]),

#print( ans )

solve();