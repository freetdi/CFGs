

DIRS = atomthreads contiki coremark dhrystone fuzix whetstone
ALGS = fipptm tamaki thorup

THINGS = ${DIRS:%=%.out}
SUMMARIES = ${ALGS:%=%.sum.out}

all: ${THINGS}
summaries: ${SUMMARIES}

${THINGS}: %.out:
	for i in ${ALGS}; do \
		./do_it.sh $* $$i > $*.$$i.out; \
	done
	touch $@

${SUMMARIES}: %.sum.out:
	echo \# avg_bagsize avg_runtime > $@
	@for i in ${DIRS}; do \
		echo -n "$$i " >> $@; \
			f=$$i.$*.out; \
			grep -v "#" $$f | \
			awk '{ sum2 += $$2; sum3 += $$3 } \
			     END { Q2=sum2/NR; Q3=sum3/NR; printf("%f %f\n",Q2, Q3) }' >> $@; \
	done

clean:
	rm -rf *.out
