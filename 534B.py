def input_long_array():
    inp = str( raw_input() );
    A = inp.split();
    return list(map(long, A))

uv=input_long_array();
u = uv[0] ;
v = uv[1];

td = input_long_array();
n = td[0];
d = td[1];

maxi = [ 0 for x in range(n)]
mini = [ 0 for x in range(n)]

maxi[0]=u;
mini[n-1]=v;

for i in range(1 , n):
	maxi[i] = maxi[i-1]+d;

for i in range( n - 2 , -1 , -1):
	mini[i] = mini[i+1] + d;

ans = 0;

for i in range(n):
	ans+=min( maxi[i] , mini[i] );

print( ans);

