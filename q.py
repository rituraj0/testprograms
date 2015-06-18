import Queue
from bs4 import BeautifulSoup
from urllib2 import urlopen

Q = Queue.Queue();
Q.put("http://www.dmoz.org/")

done = {};

while not Q.empty():
	curr=Q.get();

	if done.has_key(curr):
		continue;

	print(" *****  {0}   *****".format(curr));
	page=urlopen(curr);
	soup=BeautifulSoup(page,"html.parser");
	urls=soup.findAll('a' , href=True);
	for xy in urls:
		Q.put(xy['href']);
		print( xy['href']);




