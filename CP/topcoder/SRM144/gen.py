#!/usr/bin/python
from random import *

f = open("in.txt", "w")
for len in range(1, 5):
    for j in range(1, 10):
        s = ""
        for i in range(0, len):  
            rn = randrange(4)
            s += str(rn)
        f.write(s+"\n")
f.close()

