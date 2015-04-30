
if __name__ == '__main__':
	n  = int( raw_input() );
	A = raw_input();
	B = raw_input();
	ans =0 ;
	for i in range(0,n):
		dist = abs( int(A[i]) - int( B[i]) );
		ans+=min( 10-dist , dist);
	
	print(ans);