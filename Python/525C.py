def input_int_array():
	inp = str( raw_input() );
	A = inp.split();
	return list(map(int, A))


maxn = 1000000
n = int( input() );
cont = [ 0 for x in range(maxn+1)];
prev = [ 0 for x in range(maxn+1)];


inp = input_int_array();

#print( len(inp));

for i in range(n):
	cont[ inp[i] ]+=1;



for i in range(maxn,0,-1):
	if( ((cont[i] + prev[i])%2) == 1):
		if( cont[i] >= 1):
			cont[i]-=1;
			prev[i-1]+=1;

ans= 0;

rem_id = maxn +1 ;
rem_cont = 0; # can be maximum 2 , if more than 2 ie. 4 , 6 then we ould like to make a rectangle there itself

for i in range( maxn , 0 , -1):
	total = cont[i] + prev[i];

	if( total >=2 ):
		if( rem_cont > 0):
			total-=2;
			ans+=i*rem_id;
			rem_cont=0;

	#form a group of 4
	aval = total /4;
	ans+=aval*i*i;
	total-=aval*4;

	#update rem
	if( total >=2): # can be 3 in some places 
		rem_id=i;
		rem_cont=2;


print(ans);

#algo should first try to make 2-curr , 2 agge as much as psooible
# then try 4 of same lenght

'''
	if( (cont[i]%4)==0):#same lenght ka char mil gaya
	    aval=cont[i]/4;
		ans+=(i*i)*aval;
		cont[i]-=aval*4;
	elif( ((cont[i]%2)==0)) and ( i<maxn) ):
		here=(cont[i]==2);
		prev=(cont[i+1]==2);
		if( here and prev ):
			ans+=i*(i+1);
			cont[i]-=2;
			cont[i+2]-=2;
'''


