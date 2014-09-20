import os,sys
from random import randint
import test

with open("in","w") as fs:
  for i in range( 0, 1):
    N = randint(5,100000-1)
    M = randint(5,100000-1)
    tN = N
    #print(str(N)+" "+str(M))
    fs.write( str(N)+" "+str(M)+"\n")

    for k in range(0,M):
      op = randint(0,1)
      if op == 0:
        x = randint(1,tN)
        y = randint(1,tN)
        if x == y :
          k-=1
          continue
        fs.write(str(op)+" "+str(x)+" "+str(y)+"\n")
        N-=1
      else:
        k = randint(1,min(10,N))
        fs.write(str(op)+" "+str(k)+"\n")
