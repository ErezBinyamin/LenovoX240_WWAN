#include <getopt.h>
#include <unistd.h>
#include "util.h"

#define _GNU_SOURCE

#define BEL 7

/************************************************************************
	Manually implemented beep command
************************************************************************/
int main(int argc, char* argv[]){
	/* * / // GETOPT
	int count, delay;
	count = 1;
	delay = 0;


	// getopt_long stores the option index here.
	int option_index = 0;
	int rc;

	// Short parameters list
	char *getoptOptions = "c:d:";

	// Long command line parameter list, it should mostly match the short list
	struct option long_options[] = {
		{"count",     required_argument, 0, 'c'},
		{"delay",     required_argument, 0, 'd'},
		{0, 0, 0, 0}
	};

	opterr = 1;	//Enable automatic error reporting
	while ((rc = getopt_long_only(argc, argv, getoptOptions, long_options,&option_index)) != -1) {
		switch (rc){
			case 'c':			// Count
				count = atoi(optarg);
				break;
			case 'd':			// Delay
				delay = atoi(optarg);
				break;
			case '?':			// Handled by the default error handler
				break;
			default:
				printf ("Internal error: undefined option %0xX\n", rc);
				count=0;
				return PGM_ERROR;
		}
	}
	//------------------------------------------------------------------------
	//	Check for command line syntax errors
	//------------------------------------------------------------------------
	if (optind < argc || count < 0 || delay < 0){
		fprintf(stderr, "\n\nusage: %s -c[ount] -d[elay]\n", argv[0]);
		fprintf(stderr, "  e.g:\n\t%s -count 2 -d 1\n", argv[0]);
		fflush(stderr);
		return PGM_ERROR;
	}
	// */ // GETOPT

	/*------------------------------------------------------------------------
		MAIN PROGRAM CALLS
	------------------------------------------------------------------------*/
	char arg1[50];
	if(argc < 2){
		scanf("%s", &arg1);
		printf("%s\n", arg1);
	}
	else
		printf("%s\n", argv[1]);

	return PGM_SUCESS;
}
