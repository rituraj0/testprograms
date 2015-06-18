def input_array():
    inp = str( raw_input() );
    A = inp.split();
    return list(map(int, A));

cont = [ 0 for x in range(2005)]

n= int( raw_input() );
rate = input_array();

for i in range(n):
	cont[ rate[i] ]+=1;

for i in range(2001,0 ,-1):
	cont[i]+=cont[i+1];

for i in range(n):
	print( cont[ rate[i] +1 ] + 1),


