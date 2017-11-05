
DIRS = atomthreads contiki coremark dhrystone fuzix whetstone stdlib nuttx
ALGS = fi ex17 thorup
#ALGS = ppfi ppfitm tamaki thorup ppmd fitm

THINGS = ${DIRS:%=%.out}
SUMMARIES = ${ALGS:%=%.sum.out}
LATEXTABLES = ${ALGS:%=%.sum.tex}

.PHONY: gr clean

all: ${LATEXTABLES}
summaries: ${SUMMARIES}
tables: ${LATEXTABLES}

gr: ../convert_graph_types
	for i in ${DIRS}; do \
		( cd $$i && ../$< dot gr *.dot ); \
		touch $$i.out; \
	done
	touch gr

${THINGS}: %.out: gr
	for i in ${ALGS}; do \
		./do_it.sh $* $$i > $*.$$i.out; \
	done
	touch $@

${SUMMARIES}: %.sum.out: ${THINGS}
	echo \# number avg_bagsize max_bagsize avg_runtime > $@
	@for i in ${DIRS}; do \
		echo -n "$$i " >> $@; \
			f=$$i.$*.out; \
			grep -v "#" $$f | \
			awk '{ sum2 += $$2; sum3 += $$3; M= (M<$$2? $$2 : M) } \
			     END { Q2=sum2/NR; Q3=sum3/NR*1000.; printf("%d %f %f %f\n",NR, Q2, M, Q3) }' >> $@; \
	done

${LATEXTABLES}: %.tex: %.out
	./latextables.py $< > $@

LATEX=latex
pdf: tables.pdf
tables.pdf: tables.tex
	${LATEX} $<
	dvipdf tables

tables.pdf: ${LATEXTABLES} tables.tex
.PRECIOUS: ${LATEXTABLES} ${SUMMARIES}

clean:
	rm -rf *.out *.sum.tex tables.pdf
