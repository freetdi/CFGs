#!/usr/bin/env python

from __future__ import print_function
from dataparse import datafile_by_index
from sys import argv

d=datafile_by_index(argv[1], [0, "number", "avg_bagsize", "max_bagsize", "avg_runtime"])

print("\\begin{tabular}{|l|l|l|l|r|}")
print("\hline")
print("package & \\#CFGs & avg width & max width & avg time[ms] \\\\")
print("\hline")
print("\hline")

for i in d:
	print(i[0], "&", int(i[1]))
	print("&", i[2]-1, "&", int(i[3]-1))
	print("&", i[4])
	print("\\\\")
print("\hline")

print("\end{tabular}")
