remotecontrol-glue.hpp: mnote-introspect.xml
	dbusxx-xml2cpp $^ --adaptor=$@

remotecontrol-client-glue.hpp: mnote-introspect.xml
	dbusxx-xml2cpp $^ --proxy=$@

BUILT_SOURCES = remotecontrol-glue.hpp remotecontrol-client-glue.hpp
CLEANFILES = $(BUILT_SOURCES)

dist-hook:
	cd $(distdir); rm -f $(BUILT_SOURCES)

EXTRA_DIST = mnote-introspect.xml
