import os,sys
from random import *


with open("data.in","w") as file:
  file.write("1\n")
  file.write("99996 99994\n")
  for i in range(2,50000):
    file.write("1 "+"2"+'\n')

  file.write("200000\n")
  for i in range(0,200000):
    j = randrange(0,2)
    file.write(str(j)+" ")
    if j == 0:
      file.write(str(randrange(1,3))+" "+str(randrange(3,100))+"\n");
    if j == 1:
      file.write( str(randrange(1,3))+"\n")
