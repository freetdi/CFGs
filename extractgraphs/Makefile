# Compile C code from various sources while extracting the control-flow graphs, as used in register allocation.

GRAPHS = graphs/whetstone graphs/dhrystone graphs/contiki graphs/atomthreads graphs/nuttx graphs/stdlib

.PHONY: all clean

all: $(GRAPHS)

graphs/whetstone:
	cd whetstone && make && cd .. && mkdir $@ && cp `find whetstone -name "*dumpralloccfg*"` $@/

graphs/dhrystone:
	cd dhrystone && make && cd .. && mkdir $@ && cp `find dhrystone -name "*dumpralloccfg*"` $@/

graphs/coremark:
	cd coremark && make && cd .. && mkdir $@ && cp `find coremark -name "*dumpralloccfg*"` $@/

graphs/contiki:
	cd contiki && make && cd .. && mkdir $@ && cp `find contiki -name "*dumpralloccfg*"` $@/

graphs/fuzix:
	cd fuzix && make && cd .. && mkdir $@ && cp `find fuzix -name "*dumpralloccfg*"` $@/; true

graphs/atomthreads:
	cd atomthreads && make && cd .. && mkdir $@ && cp `find atomthreads -name "*dumpralloccfg*"` $@/

graphs/nuttx:
	cd nuttx && make && cd .. && mkdir $@ && cp `find nuttx -name "*dumpralloccfg*"` $@/

graphs/stdlib:
	cd stdlib && make && cd .. && mkdir $@ && cp `find stdlib -name "*dumpralloccfg*"` $@/

clean:
	rm -rf graphs/* && cd whetstone && make clean && cd .. && cd dhrystone && make clean && cd .. && cd coremark && make clean && cd .. && cd contiki && make clean && cd .. && cd nuttx && make clean && cd .. && cd stdlib && make clean

