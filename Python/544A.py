import sys;

if __name__ == '__main__':
	req= int( raw_input() );
	Q = str( raw_input());
	N = len(Q);
	unq={}

	for i in range(N):
		unq[ Q[i ] ]=True;

	if( len(unq) < req):
		print("NO");
		sys.exit();

	print("YES");

	st=0;

	done={};

	for cn in range(req):
		ed=st;
		done[ Q[st] ]=True;
		while( (ed<N) and ( done.has_key( Q[ed] ) == True) ):
			ed+=1;
		if(cn==req-1):
			ed=N;
		#print(st);
		#print(ed);
		#print("**");
		print(Q[st:ed]);
		st=ed;
