def solve( text , A, B):
	am=-1;
	
	for i in range( ( len(text) -1) ):
		if( (text[i] == A[0]) and( text[i+1] == A[1]) ):
			am=i+2;
			break;

	#print(am);

	if( am ==-1):
		return False;

	for i in range( am , (len(text)-1) , 1):
		if( (text[i]==B[0]) and ( text[i+1] == B[1]) ):
			return True;

	return False;


if(__name__ == '__main__'):
	input=str( raw_input() );
	if( solve(input,"AB" ,"BA") or solve(input ,"BA" ,"AB") ):
		print("YES");
	else:
		print("NO");