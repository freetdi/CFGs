# Get NuttX, patch it to dump the graphs, compile.
# Needs kconfig-frontends installed.

.PHONY: all clean

KNOWN_GOOD_REVISION = cd417249c913d964e44a73cac0aa5b86b45fc897
KNOWN_GOOD_REVISION_APPS = 1db7d34a8449b91d863d5a8d1981fc8936fb40e3

# Final make fails, since we are not actually building any app,so there is no link script.
all:
	rm -rf nuttx apps && git clone https://bitbucket.org/nuttx/apps.git && cd apps && git checkout $(KNOWN_GOOD_REVISION_APPS) && cd .. && git clone https://bitbucket.org/nuttx/nuttx.git && cd nuttx && git checkout $(KNOWN_GOOD_REVISION) && cat ../nuttx.patch | patch -p0 && LD_LIBRARY_PATH=/usr/local/lib tools/configure.sh z80sim/ostest && make; true

clean:
	rm -rf nuttx apps

