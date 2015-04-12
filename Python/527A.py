def input_long_array():
    inp = str( raw_input() );
    A = inp.split();
    return list(map(long, A))

def solve( a, b):
	if( (a==0) or (b==0)):
		return 0;
	if( a==b):
		return 1;
	mn = min( a, b);
	mx = max( a ,b);
	rem = mx % mn;
	can = mx / mn;
	return  can + solve(rem, mn);

ab = input_long_array();
print( solve( ab[0] , ab[1]) );