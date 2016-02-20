#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

#include "airport.h"
#include "route.h"
#include "city.h"
#include "parse.h"

double haversine(double latSource, double lonSource, double latDest, double lonDest) {
   double radius;
   double deltaLat;
   double deltaLon;
   double a;
   double b;
   double c;
   double d;

   // define the radius to be the radius of the Earth
   radius = EARTH_RADIUS;
   // get the change in latitude
   deltaLat = latDest - latSource;
   // get the change in longitude
   deltaLon = lonDest - lonSource;
   // calculate the change in angle
   a = pow(sin(deltaLat / 2.0), 2.0);
   b = a + cos(latSource) * cos(latDest) * pow(sin(deltaLon / 2.0), 2.0);
   c = 2.0 * atan2(sqrt(b), sqrt(b - 1.0));
   d = radius * c;

   return d;
}

void split(string toSplit, vector<string> &splitString) {
   istringstream iss (toSplit);
   string cursor;
   
   while (getline(iss, cursor, ','))
      splitString.push_back(cursor);
}

string getCode(vector<string> &splitString) {
   string empty;
   string NA;
   string comp1;
   string comp2;
   string result;

   empty = "\"\"";
   NA = "\\N";
   comp1 = splitString.at(AIRPORT_IATA_INDEX);
   comp2 = splitString.at(AIRPORT_ICAO_INDEX);
   result = empty.compare(comp1) == 0 ? comp2 : comp1;
   result = result.compare(NA) == 0 ? "Not Applicable" : result;

   return result;
}

double stringToDouble(string toConvert) {
   double result;
   stringstream convert(toConvert);

   return convert >> result ? result : 0;
}

void test_airports(vector<Airport> &airports) {
   int size = airports.size();

   cout << "airports size: " << size << '\n';
}

void addRoutes(vector<City> &cities, vector<Airport> &airports, vector<string> &splitString, map<string, City> &ids) {
   map<string, City>::iterator itIDs;
   vector<City>::iterator itCities;
   vector<Airport>::iterator itAirports;
   City find;
   Airport source;
   Airport dest;
   string sourceID;
   string destID;
   
   sourceID = splitString.at(ROUTE_SOURCE_ID_INDEX);
   destID = splitString.at(ROUTE_DEST_ID_INDEX);
   itIDs = ids.find(sourceID);
   
   if (itIDs != ids.end()) {
      find = ids[sourceID];
      //cout << find.getName() << '\n';
   }
}

int main() {
   string line;
   ifstream airportsData (AIRPORTS);
   ifstream routesData (ROUTES);
   vector<string> splitString;
   vector<string>& r_splitString = splitString;
   vector<City> cities;
   vector<City>& r_cities = cities;
   vector<Airport> airports;
   vector<Airport>& r_airports = airports;
   map<string, City> ids;
   map<string, City>& r_ids = ids;

   if (airportsData.is_open()) {
      int counter = 0;
      while (getline(airportsData, line)) {
         cout << counter++ << '\n';
         split(line, r_splitString);
         string id = splitString.at(AIRPORT_ID_INDEX);
         string name = splitString.at(AIRPORT_CITY_INDEX);
         string code = getCode(r_splitString);
         double lat = stringToDouble(splitString.at(AIRPORT_LAT_INDEX));
         double lon = stringToDouble(splitString.at(AIRPORT_LONG_INDEX));
         City city (name);
         Airport airport (code, id, lat, lon);

         cities.push_back(city);
         airports.push_back(airport);
         ids.insert(pair<string, City>(id, city));

         splitString.clear();
      }
   }
   test_airports(airports);
   if (routesData.is_open()) {
      while (getline(routesData, line)) {
         split(line, r_splitString);
         addRoutes(r_cities, r_airports, r_splitString, r_ids);
 
         splitString.clear();
      }
   }
}
