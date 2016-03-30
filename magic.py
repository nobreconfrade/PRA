#!/usr/bin/python3

with open('airlines.txt','r') as myFile:
    listStrings = myFile.read().splitlines() 
    #print(listStrings)
    count = 0
    for i in listStrings:
        i = i.replace('"','').split(',')
        # print(i)
        if (i[6] == "Brazil"):
        	count += 1
print("Brazil occurrences on .txt:")
print(count)        
myFile.close()	