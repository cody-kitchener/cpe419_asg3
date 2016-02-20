#ifndef __PARSE_H_INCLUDED__
#define __PARSE_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define EARTH_RADIUS 6371
#define AIRPORTS "airports.dat"
#define ROUTES "routes.dat"
// Indexes for each line of "airports.dat"
#define AIRPORT_ID_INDEX 0
#define AIRPORT_NAME_INDEX 1
#define AIRPORT_CITY_INDEX 2
#define AIRPORT_COUNRTY_INDEX 3
#define AIRPORT_IATA_INDEX 4
#define AIRPORT_ICAO_INDEX 5
#define AIRPORT_LAT_INDEX 6
#define AIRPORT_LONG_INDEX 7
#define AIRPORT_ALT_INDEX 8
// Indexes for each line of "routes.dat"
#define ROUTE_SOURCE_INDEX 2
#define ROUTE_SOURCE_ID_INDEX 3
#define ROUTE_DEST_INDEX 4
#define ROUTE_DEST_ID_INDEX 5

double haversine(double latSource, double lonSource, double latDest, double lonDest);

#endif
