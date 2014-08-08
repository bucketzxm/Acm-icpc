#!/usr/bin/env python
# encoding: utf-8

str = input()

def isP(s):
    return s==s[::-1]


print(isP(str))

