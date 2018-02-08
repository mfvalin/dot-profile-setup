/* watch -- execute a program repeatedly, displaying output fullscreen
 *
 * Based on the original 1991 'watch' by Tony Rems <rembo@unisoft.com>,
 * mods by Mike Coleman <mkc@acm.org>
 * and Albert Cahalan
 * (with mods and corrections by Francois Pinard).
 *
 * stripped to the bone to work in batch, M.Valin UQAM 2011
 */

#define VERSION "0.2.0s"

#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

static struct option longopts[] = {
	{"help", no_argument, 0, 'h'},
	{"interval", required_argument, 0, 'n'},
	{"version", no_argument, 0, 'v'},
	{0, 0, 0, 0}
};

static char usage[] =
    "Usage: %s [-hnv] [--help] [--interval=<n>] [--version] <command>\n";

static char *progname;

static void do_usage(void)
{
	fprintf(stderr, usage, progname);
	exit(1);
}

static void do_exit(int status)
{
	exit(status);
}

int
main(int argc, char *argv[])
{
	int optc;
	int option_help = 0, option_version = 0;
	double interval = 2;
	char *command;
	int command_length = 0;	/* not including final \0 */

	progname = argv[0];

	while ((optc = getopt_long(argc, argv, "+hn:v", longopts, (int *) 0))
	       != EOF) {
		switch (optc) {
		case 'h':
			option_help = 1;
			break;
		case 'n':
			{
				char *str;
				interval = strtod(optarg, &str);
				if (!*optarg || *str)
					do_usage();
				if(interval < 0.1)
					interval = 0.1;
				if(interval > ~0u/1000000)
					interval = ~0u/1000000;
			}
			break;
		case 'v':
			option_version = 1;
			break;
		default:
			do_usage();
			break;
		}
	}

	if (option_version) {
		fprintf(stderr, "%s\n", VERSION);
		if (!option_help)
			exit(0);
	}

	if (option_help) {
		fprintf(stderr, usage, progname);
		fputs("  -h, --help\t\t\t\tprint a summary of the options\n", stderr);
		fputs("  -n, --interval=<seconds>\t\tseconds to wait between updates\n", stderr);
		fputs("  -v, --version\t\t\t\tprint the version number\n", stderr);
		exit(0);
	}

	if (optind >= argc)
		do_usage();

	command = strdup(argv[optind++]);
	command_length = strlen(command);
	for (; optind < argc; optind++) {
		char *endp;
		int s = strlen(argv[optind]);
		command = realloc(command, command_length + s + 2);	/* space and \0 */
		endp = command + command_length;
		*endp = ' ';
		memcpy(endp + 1, argv[optind], s);
		command_length += 1 + s;	/* space then string length */
		command[command_length] = '\0';
	}

	for (;;) {
		int c;
		FILE *p;

		if (!(p = popen(command, "r"))) {
			perror("popen");
			do_exit(2);
		}

		c=getc(p);
		while(c != EOF) { putchar(c) ; c=getc(p);}
                fflush(stdout);

		pclose(p);

		usleep(interval * 1000000);
	}

	return 0;
}
