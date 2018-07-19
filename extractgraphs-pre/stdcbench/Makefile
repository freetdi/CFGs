# Get stdcbench, patch it to dump the graphs, compile.

.PHONY: all clean

KNOWN_GOOD_REVISION = 46 # 0.5

all:
	rm -rf stdcbench && svn co -r $(KNOWN_GOOD_REVISION)  https://svn.code.sf.net/p/stdcbench/code/trunk/stdcbench && cd stdcbench && cat ../stdcbench.patch | patch -p0 && make -f examples/Makefile.SDCC-STM8AF

clean:
	rm -rf stdcbench

