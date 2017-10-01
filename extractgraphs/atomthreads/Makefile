# Get atomthreads, patch it to dump the graphs, compile.

.PHONY: all clean

KNOWN_GOOD_REVISION = 1a2f9bae753b5ed171bbbde94a97d8484a7bca55

# Final make fails, since we are not actually building any app,so there is no link script.
all:
	rm -rf atomthreads && git clone https://github.com/kelvinlawson/atomthreads.git && cd atomthreads && git checkout $(KNOWN_GOOD_REVISION) && cat ../atomthreads.patch | patch -p0 && cd ports/stm8 && make -f sdcc.mak

clean:
	rm -rf atomthreads

