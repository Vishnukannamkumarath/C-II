def gcd(18,25):
	cf=[]
	for i in range (1,min(m,n)+1):
		if (m%i)==0 &&(n%i)==0:
			cf.append(i)
			return (cf[-1])

