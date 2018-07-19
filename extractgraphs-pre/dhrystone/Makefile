# Extract Dhrystone 2.1, patch it to dump the graphs, compile.
# To be independent of Dhrystone 2.1 release tarball availability, we keep a copy with our code.

.PHONY: all clean

# Final make fails, since we are not actually building any app,so there is no link script.
all:
	rm -rf dhrystone-stm8af5288-usart3-sdcc-3.6.0 && tar -xzf dhrystone-stm8af5288-usart3-sdcc-3.6.0.tar.gz && cd dhrystone-stm8af5288-usart3-sdcc-3.6.0 && cat ../dhrystone-2.1.patch | patch -p0 && make

clean:
	rm -rf dhrystone-stm8af5288-usart3-sdcc-3.6.0

