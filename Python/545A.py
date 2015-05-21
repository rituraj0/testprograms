import sys;

def input_array():
    inp = str( raw_input() );
    A = inp.split();
    return list(map(int, A));

if __name__ == '__main__':
	n= int( raw_input());
	mat=[]
	for i in range(n):
		mat.append( input_array() );

	turned=[ False for i in range(n)];# not [False]

	#for i in range(n):
	#	print( turned[i]);


	for i in range(n):
		#print();
		for j in range(n):
			#print(mat[i][j]),
			if(mat[i][j]==1):
				turned[i]=True;
			if( mat[i][j]==2):
				turned[j]=True;
			if( mat[i][j]==3):
				turned[i]=True;
				turned[j]=True;

	ans=[];

	for i in range(n):
		#print( turned[i]);
		if( turned[i] == False):
			ans.append(i+1);

	print( len(ans));
	for i in ans:
		print(i),;

