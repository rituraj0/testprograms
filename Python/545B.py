import sys;

A=str( raw_input());
B=str( raw_input());

n = len(A);

ans=[ '0' for i in range(n) ];

unmat=0;

for i in range(n):
	if( A[i]!=B[i]):
		unmat+=1;

if( unmat%2 ==1):
	print("impossible");
	sys.exit();

unmat=unmat/2;

for i in range(n):
	if( A[i]==B[i]):
		ans[i]=A[i];
	else:
		if( unmat > 0):
			ans[i]=A[i];
		else:
			ans[i]=B[i];
		unmat-=1;

print( ''.join(ans));