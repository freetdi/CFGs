# Get FUZIX, patch it to dump the graphs, compile.
# Problem: Building FUZIX needs write access to /opt

.PHONY: all clean

KNOWN_GOOD_REVISION = fbd09fb50c652b3ba0cf4d3785d5ee02265c86fe

# Final make fails, since we are not actually building any app,so there is no link script.
all:
	rm -rf FUZIX && git clone https://github.com/EtchedPixels/FUZIX.git && cd FUZIX && git checkout $(KNOWN_GOOD_REVISION) && cat ../fuzix.patch | patch -p0 && make TARGET=z80pack

clean:
	rm -rf FUZIX

