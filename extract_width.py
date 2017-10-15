import os

for root, subdirs, files in os.walk("./extractgraphs"):
    for file in files:
        if ".dot" in file and "dec" in file and not "naddr" in file and not "lospre" in file:
            maximum = 0

            fin = open(root+'/'+file, 'r')
            for line in fin:
                if "label" not in line:
                    continue

                a = line.find('|')
                b = line.find(':')
                relevant = line[a+1:b-1]

                s = relevant.split(' ')[1:]

                maximum = len(s) if len(s) > maximum else maximum

            print(str(file) + " " + str(maximum))

            fin.close()

    
