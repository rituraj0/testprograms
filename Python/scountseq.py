mod = 1000003;
maxn = 1004;

dp = [[0]*maxn for i in range(maxn)]
def populate():
	for i in range(1,maxn):
		dp[0][i]=0;
	for i in range(maxn):
		dp[i][0]=1;
	for i in range(1,maxn):
		for j in range(1,maxn):
			dp[i][j]=(dp[i-1][j]+ dp[i-1][j-1])%mod;


def solve():
	st = raw_input();
	tp = st.split();
	A = list(map(int, tp))
	aval=A[2]-A[1]+1;
	N = A[0];
	up=(aval+1)+N-1

	#Use lucas theorm 
	ans=dp[up][N]-1;
	print(ans);


test = int( input() );
populate()

while( test > 0):
	test-=1;
	solve();
