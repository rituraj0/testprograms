if __name__ == '__main__':
	inp=str( raw_input());
	mx=0;
	for i in range( len(inp)):
		mx=max(mx, ord(inp[i])-ord('0'));
	ans = [ ['0'for x in range(len(inp))] for x in range(mx)]
	for i in range(len(inp)):
		for j in range( ord(inp[i])-ord('0') ):
			ans[j][i]='1';
	print(mx);
	for i in range(mx):
		st=''.join(ans[i]);
		print(st.lstrip("0")),