#!/usr/bin/python3

with open('airlines.txt','r', buffering = 4096) as myFile:
    listStrings = myFile.read().splitlines() #.splitlines() 'splits' the file into a list 
    # print(listStrings) show the content of the file in a list
    # print (myFile)
    count = 0
    for i in listStrings:
        i = i.replace('"','').split(',')
        # print(i) show the content of the file in a list of lists
        if (i[6] == "Brazil"):
        	count += 1
print("Brazilian airlines on .txt:")
print(count)        