import math
cas = raw_input()
for k in range(int(cas)):
	line = raw_input()
	a = line.split()
	r = int(a[0])
	t = int(a[1])
	ans = int((-(2*r-1)+math.sqrt((2*r-1)**2 + 4*2*t)) / 4)
	a0 = ans - 2
	a1 = ans - 1
	a2 = ans + 1
	a3 = ans + 2
	if ((2*r+2*a3-1)*a3 <= t):
		print "Case #"+str(k+1)+": "+str(a3)
	elif ((2*r+2*a2-1)*a2 <= t):
		print "Case #"+str(k+1)+": "+str(a2)
	elif ((2*r+2*ans-1)*ans <= t):
		print "Case #"+str(k+1)+": "+str(ans)
	elif ((2*r+2*a1-1)*a1 <= t):
		print "Case #"+str(k+1)+": "+str(a1)
	elif ((2*r+2*a0-1)*a0 <= t):
		print "Case #"+str(k+1)+": "+str(a0)
