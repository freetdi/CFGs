#!/bin/bash

dir=$1
out=$1.out

alg=$2

echo \# bagsize runtime
for i in $( cd $dir; ls *.gr ); do
   echo -n "$i "
   tdecomp -L --$alg < $dir/$i 2>/dev/null | \
      grep -e '^s' -e bagsize | tr ',' ' ' | tr '\n' ' '| \
	 	awk '{ printf("%d %f %d\n", $5, $7, $11); }'
done
