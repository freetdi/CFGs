# Get SDCC noasm branch, patch it to dump the graphs from the stdlib, compile.

.PHONY: all clean

KNOWN_GOOD_REVISION = 10088

all:
	rm -rf sdcc-noasm && svn checkout -r $(KNOWN_GOOD_REVISION) https://svn.code.sf.net/p/sdcc/code/branches/noasm/sdcc sdcc-noasm && cd sdcc-noasm && cat ../sdcc-noasm.patch | patch -p0 && ./configure --disable-pic16-port --disable-pic14-port && make

clean:
	rm -rf sdcc-noasm

