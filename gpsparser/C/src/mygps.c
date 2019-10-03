#include "mygps.h"

/************************************************************************
	Example template program
	Programs should have a basic description block comment
	at the top before the main function
************************************************************************/
int main(int argc, char* argv[]){
	struct NMEA_GPGGA packet = {0,0,0,0,0,0,0,0,0,0,0};
	char str_arg[50];
	int index = 0;

	argc--;

	index = GPGAA_TIME;
	if(argc < index)
		scanf("%s", str_arg);
	packet.time = atof((argc<index) ? str_arg : argv[index]);

	index = GPGAA_LAT;
	if(argc < index)
		scanf("%s", str_arg);
	packet.lat = atof((argc<index) ? str_arg : argv[index]);
	packet.lat *= (((argc<index) ? str_arg[0] : argv[index][0]) == '0') ? -0.01 : 0.01;

	index = GPGAA_LATD;
	if(argc < (index))
		scanf("%s", str_arg);
	packet.latD = (argc<index) ? str_arg[0] : argv[index][0];

	index = GPGAA_LON;
	if(argc < (index))
		scanf("%s", str_arg);
	packet.lon = atof((argc<index) ? str_arg : argv[index]);
	packet.lon *= (((argc<index) ? str_arg[0] : argv[index][0]) == '0') ? -0.01 : 0.01;

	index = GPGAA_LOND;
	if(argc < (index))
		scanf("%s", str_arg);
	packet.lonD = (argc<index) ? str_arg[0] : argv[index][0];

	index = GPGAA_FIXQUAL;
	if(argc < (index))
		scanf("%s", str_arg);
	packet.fixqual = atoi((argc<index) ? str_arg : argv[index]);

	index = GPGAA_NUMSAT;
	if(argc < (index))
		scanf("%s", str_arg);
	packet.numsat = atoi((argc<index) ? str_arg : argv[index]);

	index = GPGAA_ALTP;
	if(argc < (index))
		scanf("%s", str_arg);
	packet.altP = atof((argc<index) ? str_arg : argv[index]);

	index = GPGAA_ALT;
	if(argc < (index))
		scanf("%s", str_arg);
	packet.alt = atof((argc<index) ? str_arg : argv[index]);

	index = GPGAA_ALTU;
	if(argc < (index))
		scanf("%s", str_arg);
	packet.altU = (argc<index) ? str_arg[0] : argv[index][0];

	index = GPGAA_GEOID;
	if(argc < (index))
		scanf("%s", str_arg);
	packet.geoid = atof((argc<index) ? str_arg : argv[index]);

	index = GPGAA_GEOIDU;
	if(argc < (index))
		scanf("%s", str_arg);
	packet.geoidU = (argc<index) ? str_arg[0] : argv[index][0];


	printf("\nTIME:\t%f", packet.time);
	printf("\nLAT:\t%f", packet.lat);
	printf("\nLON:\t%f", packet.lon);
	printf("\nALT:\t%f", packet.alt);
	printf("\nNUMSAT:\t%d", packet.numsat);
	putchar('\n');
	return PGM_SUCESS;
}

