import os,sys
from random import randint


with open("bin","w") as fs:
  for i in range(0,10):
    print(str(i))
    N = randint(1,1000)
    fs.write(str(N)+"\n")
    for k in range(0,N):
      w = randint(1,10000)
      s = randint(1,1000000000)
      fs.write(str(w)+" "+str(s)+"\n")
