st = str(  raw_input() );

n = int( input() );

cont = {}

inp = str( raw_input() );
A = inp.split();
inp = list(map(int, A))

for i in range(n):
	tp = inp[i];
	if( cont.has_key(tp)):
		cont[tp]+=1;
	else:
		cont[tp]=1;

arr =[]

for key in cont:
	if( cont[key]%2==1):
		key-=1;
		arr.append(key);

arr=sorted(arr)

ans = list(st);

#print( "ans is %s and its size is %s" % (ans , len(ans)) );

stlen = len(st)

for i in range( len(arr)):
	if( (i%2)==0):
		bg = arr[i];#swap from here 
		to = (stlen /2);# to to exclusing to
		if( i+1 < len(arr)):
			to = arr[i+1];
			#print( "adding to %s" %to);
		#print( "bs is %s and to is %s" %(bg,to) );
		for j in range(bg , to):
			corres = stlen -1 - j;
			#print(" j is %s %s" %(j , corres) );
			ans[j],ans[corres ] = ans[corres],ans[j];
			#print(" %s %s" %(j,stlen -1-j) );

print( ''.join(ans) );




