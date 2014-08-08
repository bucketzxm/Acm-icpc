#!/usr/bin/env python
# encoding: utf-8

def C(m,n):
    ret =1
    for i in range(m-n+1,m+1):
        ret = ret*i
    for i in range(1,n+1):
        ret = ret/i
    return ret
