# Compile C code from various sources while extracting the control-flow graphs, as used in register allocation.

# TODO: Add clean target that invoced "make clean" in all subdirectories from $(GRAPHSOURCES).

GRAPHSOURCES = whetstone dhrystone coremark contiki fuzix atomthreads

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

