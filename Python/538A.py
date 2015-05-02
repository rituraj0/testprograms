import sys;
pat ="CODEFORCES"

if __name__ == '__main__':
	inp = str( raw_input() );
	j=0;
	index=[]
	for i in range(len(pat)):
		mila=False;
		while(j<len(inp)):
			if( inp[j] == pat[i] ):
				mila=True;				
				break;
			j+=1;
		if(mila==False):
			print("NO");
			sys.exit();
	print("YES");




