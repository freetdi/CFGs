# Extract contiki-2.5, patch it to work with current SDCC and dump the graphs, compile.

.PHONY: all clean

# Final make fails, since we are not actually building any app,so there is no link script.
all:
	rm -rf contiki-2.5 && tar -xzf contiki-2.5.tar.gz && cd contiki-2.5 && cat ../contiki-2.5.patch | patch -p1 && cd platform/pc-6001 && make; true

clean:
	rm -rf contiki-2.5

