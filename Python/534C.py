def input_long_array():
    inp = str( raw_input() );
    A = inp.split();
    return list(map(long, A))

na = input_long_array();
n = na[0];
A = na [1];

inp = input_long_array();

all_sum =0;

for i in range(n):
	all_sum+=inp[i];

for i in range(n):
	# max reuired
	max_req = A - (n-1);
	max_req = min( inp[i] , max_req);
	 # other sum
	o_sum = all_sum - inp[i];
	min_req= max( 1 , A - o_sum);
	#can o
	can = max_req - min_req +1;
	print( inp[i] - can),

