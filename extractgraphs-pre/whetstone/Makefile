# Extract Whetstone 1.2, patch it to dump the graphs, compile.
# To be independent of Whetstone 1.2 release tarball availability, we keep a copy with our code.

.PHONY: all clean

# Final make fails, since we are not actually building any app,so there is no link script.
all:
	rm -rf whetstone-stm8af5288-usart3-sdcc-3.6.0 && tar -xzf whetstone-stm8af5288-usart3-sdcc-3.6.0.tar.gz && cd whetstone-stm8af5288-usart3-sdcc-3.6.0 && cat ../whetstone-1.2.patch | patch -p0 && make

clean:
	rm -rf whetstone-stm8af5288-usart3-sdcc-3.6.0

