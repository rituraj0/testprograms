
all = set()

def solve( pos , num):
	if( pos==9):# 9 done
		all.add(num);
		return;
	solve( pos+1 , num);
	solve( pos+1, 10*num+4);
	solve( pos+1 , 10*num+7);
	return;


solve(1,4);
solve(1,7);

n = int( input() );

all = sorted(all);

#print( len(all));
#print(all);

for i in range( len(all)):
	if( all[i]==n):
		print(i+1);
		break;
