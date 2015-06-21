def input_array():
    inp = str( raw_input() );
    A = inp.split();
    return list(map(long, A));

pilecount=0;
allpile=0;
stud=0;
input=[];

def printGlobal():
	print(n);
	print(m);

def cando(maxtime):
	pile=list(input);
	done=0;
	curr=1;
	for i in range(stud):
		rem=maxtime-curr+1;

		while( curr <= pilecount):
			if( rem <=0 ):
				break;
			rem-=1;
			can=min( rem , pile[curr-1]);
			rem-=can;
			pile[curr-1]-=can;
			done+=can;

			if( pile[curr-1] ==0):
				curr+=1;
			if( rem ==0):
				break;
	return (done==allpile);


if __name__ == '__main__':
	nm=input_array();
	pilecount=nm[0];
	stud=nm[1];
	input=input_array();

	for i in range(pilecount):
		allpile+=input[i];

	assert( cando(allpile+pilecount) == True);#ek hi student all work

	lo=0;
	
	hi = (allpile/stud) + (pilecount) + 1;

	while(lo<hi):
		mid=(lo+hi)/2;

		if( cando(mid) ):
			hi=mid;
		else:
			lo=mid+1;
	print(hi);