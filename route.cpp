#include <iostream>
using namespace std;

#include "airport.h"
#include "route.h"

Route::Route() {}

void Route::setSource(Airport *source) {
   if (!m_source)
      m_source = source;
   else
      cout << "Source has already been set!";
}

void Route::setDest(Airport *destination) {
   if (!m_destination)
      m_destination = destination;
   else
      cout << "Destination has already been set!";
}
