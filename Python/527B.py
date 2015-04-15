def solve():
	ID = [ [-1 for x in range(27)] for x in range(27)]

	n = int( input() );
	A = str( raw_input() );
	B = str( raw_input() );

	ham = 0;
	for i in range(n):
		if( A[i] != B[i] ):
			ham+=1;

	for i in range(n):
		ID[ ord(A[i]) - ord('a') ][ ord(B[i]) - ord('a') ]=i;

	# try to decrese by swapping (a,b) /(b,a) condition
	for i in range(26):
		for j in range(26):
			if( i !=j ):
				if( ID[i][j]!=-1):
					if( ID[j][i]!=-1):
						ham-=2;
						print(ham);
						print("%s %s"%(ID[i][j]+1 , 1+ID[j][i]));
						return;

	# now try to decares by 1 swappping (a,b) / (x,a) condition
	for a in range(26):
		for b in range(26):
			for x in range(26):
				if( (a!=b) and (b!=x) and (a!=x) ):
					if( ID[a][x]!=-1):
						if( ID[b][a]!=-1):
							ham-=1;
							print(ham);
							print("%s %s" %(ID[a][x]+1 ,1+ ID[b][a]));
							return;

	print(ham);
	print("-1 -1");

solve();