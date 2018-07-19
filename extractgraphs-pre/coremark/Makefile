# Extract Coremark 1.0, patch it to compile with current SDCC and dump the graphs, compile.
# This requires the Coremark 1.0 release tarball, coremark_v1.0.tgz from http://www.eembc.org/coremark/
# Since Coremark is non-free, we can't include the release tarball here.

.PHONY: all clean

# Final make fails, since we are not actually building any app,so there is no link script.
all:
	rm -rf coremark_v1.0 && tar -xzf coremark_v1.0.tgz && cp Makefile.coremark coremark_v1.0/Makefile && cd coremark_v1.0 && cp barebones/core_portme.? ./ && cat ../coremark-1.0.patch | patch -p0 && make SDCCFLAGS="-mstm8  --nogcse --dump-graphs"

clean:
	rm -rf coremark_v1.0
