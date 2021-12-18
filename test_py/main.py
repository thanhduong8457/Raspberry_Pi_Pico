import os
import struct
import binascii
import random

mystr = ""
for i in range(100):
    n = random.randint(100, 9999)
    mystr = mystr + str(n) + " "

print(mystr)