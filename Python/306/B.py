n=0;
l=0;
r=0;
x=0;

input=[];

def inputArray():
	temp=str( raw_input() );
	A=map(int,temp.split());
	return list(A);

def cool(mask):
	mx=0;mn=(1<<20);
	sm=0;
	onbit=0;
	for i in range(n):
		if( mask&(1<<i)):
			mx=max(mx,input[i]);
			mn=min(mn,input[i]);
			sm+=input[i];
			onbit+=1;

	if( (onbit >=2) and (l<=sm) and (sm<=r) and(mx-mn >= x) ):
		return 1;
     
	return 0;

if( __name__ == "__main__" ):
	input=inputArray();
	n=input[0];
	l=input[1];
	r=input[2];
	x=input[3];
	input=inputArray();

	ans=0;

	for i in range(1<<n):
		ans+=cool(i);

	print(ans);