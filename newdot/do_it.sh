#!/bin/bash

dir=$1
out=$1.out

alg=$2

echo \# bagsize runtime
for i in $( cd $dir; ls *.dot ); do
	echo -n "$i "
  	tdecomp --dot -q -L --$alg < $dir/$i 2>/dev/null | \
		grep bagsize | tr ',' ' ' |  awk '{ printf("%d %f\n", $5, $7); }'
done
