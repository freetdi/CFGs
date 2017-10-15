# Get SDCC noasmbranch, patch it to dump the graphs from the stdlib, compile.

.PHONY: all clean

KNOWN_GOOD_REVISION = 10046

# Final make fails, since we are not actually building any app,so there is no link script.
all:
	rm -rf sdcc-noasm && svn checkout -r $(KNOWN_GOOD_REVISION) https://svn.code.sf.net/p/sdcc/code/branches/noasm/sdcc sdcc-noasm && cd sdcc-noasm && cat ../sdcc-noasm.patch | patch -p0 && ./configure --disable-pic16-port --disable-pic14-port && make

clean:
	rm -rf sdcc-noasm

