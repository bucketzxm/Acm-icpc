#!/usr/bin/env python
# encoding: utf-8

from math import pow

a = [1,1,1,1,1,0,0,1,1]

ans= 0;
for i in range(0,1,1e-4):
    for k in a:
        ans+= pow(k-i,2)
    if  ans-1.428571)<1e-4:
        print(i)

