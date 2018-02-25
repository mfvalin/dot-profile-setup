BINDIR=../hostbin/$(PLATFORM)
CCLARGS_VERSION=300

all:	$(BINDIR) $(BINDIR)/cclargs $(BINDIR)/cclargs_lite $(BINDIR)/cclargs_lite_curses_$(CCLARGS_VERSION) \
	$(BINDIR)/cclargs $(BINDIR)/cclargs_lite+ \
	$(BINDIR)/r.kill0 $(BINDIR)/r.read_link $(BINDIR)/r.seq $(BINDIR)/true_path \
	$(BINDIR)/s.path_cleanup $(BINDIR)/s.get_nb_of_cpus $(BINDIR)/r.echo $(BINDIR)/repeat_command \
	$(BINDIR)/arbre $(BINDIR)/grepdep $(BINDIR)/r.isowner \
	$(BINDIR)/traffic $(BINDIR)/r.ucanrm $(BINDIR)/r.crc $(BINDIR)/r.basename

$(BINDIR):
	mkdir -p ${BINDIR}

$(BINDIR)/cclargs: $(BINDIR)/cclargs_lite
	cp $(BINDIR)/cclargs_lite $(BINDIR)/cclargs

$(BINDIR)/cclargs_lite: cclargs_lite.c
	cc -o $(BINDIR)/cclargs_lite -DVERSION=$(CCLARGS_VERSION) -DNOUI cclargs_lite.c
	strip $(BINDIR)/cclargs_lite

$(BINDIR)/cclargs_lite+: cclargs_lite+.c
	cc -o $(BINDIR)/cclargs_lite+ -DVERSION=$(CCLARGS_VERSION) -DNOUI cclargs_lite+.c
	strip $(BINDIR)/cclargs_lite+

$(BINDIR)/cclargs_lite_curses_$(CCLARGS_VERSION): cclargs_lite.c progmenu.c
	-cc -o $(BINDIR)/cclargs_lite_curses_$(CCLARGS_VERSION) -DVERSION=$(CCLARGS_VERSION) cclargs_lite.c progmenu.c -lcurses
	-strip $(BINDIR)/cclargs_lite_curses_$(CCLARGS_VERSION)

$(BINDIR)/r.basename: r.basename.c
	cc -o $@ $<
	strip $@

$(BINDIR)/r.echo: r.echo.c
	cc -o $@ $<
	strip $@

$(BINDIR)/r.kill0: r.kill0.c
	cc -o $@ $<
	strip $@

$(BINDIR)/r.read_link: r.read_link.c
	cc -o $@ $<
	strip $@

$(BINDIR)/r.seq: r.seq.c
	cc -o $@ $<
	strip $@

$(BINDIR)/repeat_command: repeat_command.c
	cc -o $@ $<
	strip $@

$(BINDIR)/true_path: true_path.c
	cc -o $@ $<
	strip $@

$(BINDIR)/s.path_cleanup: s.path_cleanup.c
	cc -O -o $@ $<
	strip $@

$(BINDIR)/s.get_nb_of_cpus: s.get_nb_of_cpus.c
	cc -O -o $@ $<
	strip $@

$(BINDIR)/arbre: arbre.c
	cc -o $@ $<
	strip $@

$(BINDIR)/grepdep: grepdep.c
	cc -o $@ $<
	strip $@

$(BINDIR)/r.isowner: r.isowner.c
	cc -o $@ $<
	strip $@

$(BINDIR)/traffic: traffic.c
	cc -o $@ $<
	strip $@

$(BINDIR)/r.ucanrm: r.ucanrm.c
	cc -o $@ $<
	strip $@

$(BINDIR)/r.crc: r.crc.c
	cc -o $@ $<
	strip $@

distclean:
	rm -rf ../hostbin
