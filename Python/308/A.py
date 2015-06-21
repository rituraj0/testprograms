rect=int( raw_input() );

cont=[ [0 for x in range(101)] for y in range(101) ];

for r in range(rect):
	x1,y1,x2,y2=map(int, (str(raw_input())).split() );
	for i in range(x1,x2+1,+1):
		for j in range(y1,y2+1,+1):
			cont[i][j]+=1;

ans=0;

for i in range(101):
	for j in range(101):
		ans+=cont[i][j];

print(ans);
