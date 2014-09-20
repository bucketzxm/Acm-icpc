# encoding: utf-8

import os,sys
import random
import time
for i in range(0,199999):
    with open('in',"w") as fs:
        n = random.randint(1,100000)
        m = random.randint(1,100000)
        w = random.randint(1,100000)

        fs.write(str(n)+" "+str(m)+" "+str(w)+"\n")

        for i in range(0,n):
            fs.write( str(random.randint(1,1000000000)))

    starttime = time.time()
    os.system("./CC in")
    slow = time.time()-starttime

    starttime=time.time()
    os.system("./C in")
    fast = time.time()-starttime


    #print(str(fast-slow))
    if slow>1:
        print("fuckkkkkkkkkkkkkk")
    if slow-fast<0:
        print("slow slow "+ str(slow))
    else:
        print("fast fast "+str(fast))



    out1 = open("out1")
    out2 = open("out2")

    for line in out1:
        for line2 in out2:
            if line!= line2:
                print("wrong ans")


