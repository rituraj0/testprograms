
n = int ( input() );
st = str( raw_input() );
aval={};
ans = 0;
#print(st);
for i in range( len(st)):
	if(i%2==0):
		if( aval.has_key(st[i])):
			aval[ st[i] ]+=1;
		else:
			aval[ st[i] ]=1;
		#print( " mila hai " + st[i] );
	else:
		req = st[i].lower();
		if( False == aval.has_key(req)):
			ans+=1;
		elif( aval[req] == 0):
			ans+=1;
		else:
			aval[ req ] -=1;
			
print(ans);			
