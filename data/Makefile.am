
SUBDIRS = icons

@INTLTOOL_DESKTOP_RULE@

desktop_in_files = mnote.desktop.in
desktop_files    = $(desktop_in_files:.desktop.in=.desktop)

desktopdir   = $(datadir)/applications
desktop_DATA = $(desktop_files)


#pkgconfigdir = $(libdir)/pkgconfig
#pkgconfig_in_files = tomboy-addins.pc.in
#pkgconfig_DATA = $(pkgconfig_in_files:.pc.in=.pc)


schemasdir	 = $(MATECONF_SCHEMA_FILE_DIR)
schemas_in_files = mnote.schemas.in
schemas_DATA     = $(schemas_in_files:.schemas.in=.schemas)

@INTLTOOL_SCHEMAS_RULE@

if MATECONF_SCHEMAS_INSTALL
install-data-local:
	MATECONF_CONFIG_SOURCE=$(MATECONF_SCHEMA_CONFIG_SOURCE) \
	$(MATECONFTOOL) --makefile-install-rule $(schemas_DATA)
endif


if HAVE_DBUS
dbusservicedir       = $(DBUS_SERVICE_DIR)
dbusservice_in_files = org.mate.Mnote.service.in
dbusservice_DATA     = $(dbusservice_in_files:.service.in=.service)

$(dbusservice_DATA): $(dbusservice_in_files) Makefile
	sed -e "s|\@bindir\@|$(bindir)|g"	\
	    -e "s|\@wrapper\@|mnote|g"		\
	    < $< > $@
endif

if HAVE_MATEPANELAPPLET
serverdir       = $(PANELAPPLET_SERVER_DIR)
server_in_files = MATE_MnoteApplet.server.in
server_DATA     = $(server_in_files:.server.in=.server)

$(server_in_files): $(server_in_files:.server.in=.server.in.in) Makefile
	sed -e "s|\@libexecdir\@|$(libexecdir)|g"	\
	    -e "s|\@wrapper\@|mnote-applet|g"		\
	    < $< > $@
endif

@INTLTOOL_SERVER_RULE@


man_MANS = mnote.1

mnotedatadir = @datadir@/mnote
mnotedata_DATA = UIManagerLayout.xml \
	MATE_MnoteApplet.xml

noinst_DATA = 			


EXTRA_DIST = 					\
	UIManagerLayout.xml                     \
	MATE_MnoteApplet.xml                   \
	$(desktop_in_files)     		\
	$(pkgconfig_in_files)			\
	$(schemas_in_files)     		\
	$(man_MANS)				\
	$(noinst_DATA)				\
	MATE_MnoteApplet.server.in.in		\
	$(dbusservice_in_files)

DISTCLEANFILES = 				\
	$(desktop_files)       			\
	$(pkgconfig_DATA)			\
	$(schemas_DATA)				\
	$(server_in_files) 			\
	$(server_DATA)				\
	$(dbusservice_DATA)
