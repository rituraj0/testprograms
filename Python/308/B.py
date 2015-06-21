def numbers(digit):
	return 9*pow(10,digit-1);

for i in range(20):
	print( pow(3,i));	

req=int( raw_input() );
ans=0;

digit=1;

while(req>0):
	#try to full numbers of digit
	can=numbers(digit);
	curr=min(can,req);
	req-=curr;
	ans+=curr*digit;
	digit+=1;

print(ans);