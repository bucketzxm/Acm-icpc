#!/usr/bin/env python
import os

rootdir = os.getcwd()

def clean(rootdir):
    #print("In dir: "+rootdir)
    for dirpath,dirname,filename in os.walk(rootdir):
      for file in filename:
        if file[-3:] == "exe" or file[-1:] == "o" or '.' not in file:
          print("removed" + rootdir+"/"+file)
          os.remove(rootdir+"/"+file)
      for dirp in dirname:
        if dirp == '.git':
          continue
        clean(rootdir+"/"+dirp)

clean(rootdir)
