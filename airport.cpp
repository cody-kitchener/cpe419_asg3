#include <iostream>
#include <string>
using namespace std;

#include "airport.h"

Airport::Airport() {}

Airport::Airport(string code, string id, double latitude, double longitude) {
   m_code = code;
   m_id = id;
   m_latitude = latitude;
   m_longitude = longitude;
}
