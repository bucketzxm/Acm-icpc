#!/usr/bin/env python
# encoding: utf-8


import re

n = int(input())
P = re.compile('^'+input()+'$')
S =  ["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]

for i in S:
    if P.match(i):
        print(i)
