with open('routes.txt','r', buffering = 4096) as f:
	text = f.read().splitlines()
	# print (text)
	countLen = [0,0,0,0,0,0,0,0,0]
	for i in text:
		i = i.split(',')
		# print (i)
		aux = 0
		for j in i:
			if (len(j) >= countLen[aux]):
				countLen[aux] = len(j)
				# if (countLen[aux] == 35):
				# 	print (j)
			aux += 1
print (countLen)	