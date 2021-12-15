## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = smartesprit

smartesprit_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	fonction.c fonction.h \
	reclamation.c reclamation.h \
	f.c f.h \
	nutr.c nutr.h \
	pdej.c pdej.h \
	dej.c dej.h \
	din.c din.h \
	capteur.c capteur.h 

smartesprit_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

