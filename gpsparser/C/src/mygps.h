#ifndef TEMPLATE_H
	#define TEMPLATE_H

	//INCLUDED LIBRARIRES
	#include "util.h"
	#include <getopt.h>

	//CONSTANTS
	//  -- GPGAA index values
	#define GPGAA_TIME	1
	#define GPGAA_LAT	2
	#define GPGAA_LATD	3
	#define GPGAA_LON	4
	#define GPGAA_LOND	5
	#define GPGAA_FIXQUAL	6
	#define GPGAA_NUMSAT	7
	#define GPGAA_ALTP	9
	#define GPGAA_ALT	8
	#define GPGAA_ALTU	10
	#define GPGAA_GEOID	11
	#define GPGAA_GEOIDU	12
	#define GPGAA_CHECKSUM	13

	//TYPEDEFS / STRUCTS / UNIONS
	struct NMEA_GPGGA {
		float  time;
		float   lat;
		char   latD;
		float   lon;
		char   lonD;
		int fixqual;
		int  numsat;
		float  altP;
		float   alt;
		char   altU;
		float geoid;
		char geoidU;
	};

	//FUNCTION PROTOTYPES
#endif
