import sys;
pat ="CODEFORCES"

if __name__ == '__main__':
	inp = str( raw_input() );
	for i in range(len(pat)+1):#itna begining me
		prev=inp[:i]
		rem=len(pat)-i;
		last="";
		if(rem>0):
			last=inp[-rem:]
		if( prev+last == pat):
			print("YES");
			sys.exit();
	print("NO");




