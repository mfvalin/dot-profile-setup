BINDIR=../hostbin/$(PLATFORM)
CCLARGS_VERSION=300

all:	$(BINDIR)/cclargs $(BINDIR)/cclargs_lite $(BINDIR)/cclargs_lite_curses_$(CCLARGS_VERSION) \
	$(BINDIR)/cclargs $(BINDIR)/cclargs_lite+ \
	$(BINDIR)/r.kill0 $(BINDIR)/r.read_link $(BINDIR)/r.seq $(BINDIR)/true_path \
	$(BINDIR)/s.path_cleanup $(BINDIR)/s.get_nb_of_cpus $(BINDIR)/r.echo $(BINDIR)/repeat_command

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

$(BINDIR)/r.echo: r.echo.c
	cc -o $(BINDIR)/r.echo r.echo.c
	strip $(BINDIR)/r.echo

$(BINDIR)/r.kill0: r.kill0.c
	cc -o $(BINDIR)/r.kill0 r.kill0.c
	strip $(BINDIR)/r.kill0

$(BINDIR)/r.read_link: r.read_link.c
	cc -o $(BINDIR)/r.read_link r.read_link.c
	strip $(BINDIR)/r.read_link

$(BINDIR)/r.seq: r.seq.c
	cc -o $(BINDIR)/r.seq r.seq.c
	strip $(BINDIR)/r.seq

$(BINDIR)/repeat_command: repeat_command.c
	cc -o $(BINDIR)/repeat_command repeat_command.c
	strip $(BINDIR)/repeat_command

$(BINDIR)/true_path: true_path.c
	cc -o $(BINDIR)/true_path true_path.c
	strip $(BINDIR)/true_path

$(BINDIR)/s.path_cleanup: s.path_cleanup.c
	cc -O -o $(BINDIR)/s.path_cleanup s.path_cleanup.c
	strip $(BINDIR)/s.path_cleanup

$(BINDIR)/s.get_nb_of_cpus: s.get_nb_of_cpus.c
	cc -O -o $(BINDIR)/s.get_nb_of_cpus s.get_nb_of_cpus.c
	strip $(BINDIR)/s.get_nb_of_cpus
