def suffix(x):
	if(x==1):
		return "one";
	elif( x==2):
		return "two";
	elif( x==3):
		return "three";
	elif(x==4):
		return "four";
	elif(x==5):
		return "five";
	elif( x==6):
		return "six";
	elif(x==7):
		return "seven";
	elif(x==8):
		return "eight";
	elif( x==9):
		return "nine";

	return "";

def prefix(x):
	if( x==2):
		return "twenty";
	elif( x==3):
		return "thirty";
	elif( x==4):
		return "forty";
	elif( x==5):
		return "fifty";
	elif( x==6):
		return "sixty";
	elif( x==7):
		return "seventy";
	elif( x==8):
		return "eighty";
	elif(x==9):
		return "ninety";

def less20(x):
	if( x==0):
		return "zero";
	elif( x==1):
		return "one";
	elif( x== 2 ):
		return "two";
	elif( x== 3 ):
		return "three";
	elif( x== 4 ): 
		return "four";
	elif( x== 5 ): 
		return "five";
	elif( x== 6 ): 
		return "six";
	elif( x== 7 ):
		return "seven";
	elif( x== 8 ): 
		return "eight";
	elif( x== 9 ): 
		return "nine";
	elif( x== 10 ): 
		return "ten";
	elif( x== 11 ): 
		return "eleven";
	elif( x== 12 ): 
		return "twelve";
	elif( x== 13 ): 
		return "thirteen";
	elif( x== 14 ):
		return "fourteen";
	elif( x== 15 ): 
		return "fifteen";
	elif( x== 16 ): 
		return "sixteen";
	elif( x== 17 ): 
		return "seventeen";
	elif( x== 18 ): 
		return "eighteen";
	elif( x== 19 ):
		return "nineteen";
	elif( x== 20 ):
		return "twenty";

st = str( input() );

it = int( st);

if( it<=20):
	print( less20(it));
elif( st[1]=='0'):
	print( prefix( int(st[0])));
else:
	ans =  prefix( int(st[0]));
	ans+="-";
	ans+=suffix( int(st[1]));
	print(ans);
