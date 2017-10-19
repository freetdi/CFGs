# Get NuttX, patch it to dump the graphs, compile.
# Needs kconfig-frontends installed.

.PHONY: all clean

KNOWN_GOOD_REVISION = ffca71b9bf7e91926684ca08d768cf2b817b5309
KNOWN_GOOD_REVISION_APPS = 63e086d1f76627693613daf98e426a1efadcc5be

# Final make fails, since we are not actually building any app,so there is no link script.
all:
	rm -rf nuttx apps && git clone https://bitbucket.org/nuttx/apps.git && cd apps && git checkout $(KNOWN_GOOD_REVISION_APPS) && cd .. && git clone https://bitbucket.org/nuttx/nuttx.git && cd nuttx && git checkout $(KNOWN_GOOD_REVISION) && cat ../nuttx.patch | patch -p0 && LD_LIBRARY_PATH=/usr/local/lib tools/configure.sh z80sim/ostest && make; true

clean:
	rm -rf nuttx apps

