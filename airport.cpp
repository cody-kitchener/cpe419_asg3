#include <iostream>
#include <string>
using namespace std;

#include "airport.h"

Airport::Airport(string code, double latitude, double longitude) {
   m_code = code;
   m_latitude = latitude;
   m_longitude = longitude;
}
