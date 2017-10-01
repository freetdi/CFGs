# Compile C code from various sources while extracting the control-flow graphs, as used in register allocation.

GRAPHSOURCES = whetstone dhrystone coremark contiki fuzix atomthreads nuttx

.PHONY: all $(GRAPHSOURCES)

all: $(GRAPHSOURCES)

whetstone:
	cd whetstone && make

dhrystone:
	cd dhrystone && make

coremark:
	cd coremark && make

contiki:
	cd contiki && make

fuzix:
	cd fuzix && make

atomthreads:
	cd atomthreads && make

nuttx:
	cd nuttx && make

