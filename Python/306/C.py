import sys;

num=str( raw_input() );
n=len(num);
#
for i in range(n):
	if( int(num[i])%8==0):
		print("YES");
		print(num[i]);
		sys.exit();

for i in range(n):
	for j in range(i+1,n):
		tp=10*int(num[i]) + int(num[j]);
		if(tp%8==0):
			print("YES");
			print(tp);
			sys.exit();

for i in range(n):
	for j in range(i+1,n):
		for k in range(j+1,n):
			tp=100*int(num[i]) + 10*int(num[j]) + int(num[k]);
			if(tp%8==0):
				print("YES");
				print(tp);
				sys.exit();

print("NO");

	