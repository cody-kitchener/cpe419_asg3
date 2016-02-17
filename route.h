#ifndef __ROUTE_H_INCLUDE__
#define __ROUTE_H_INCLUDE__

class Airport;

#include <iostream>
using namespace std;

#include "airport.h"

class Route {
private:
   Airport *m_source;
   Airport *m_destination;
   double m_distance;

public:
   Route();

   void setSource(Airport *source);
   void setDest(Airport *destination);

   Airport *getSource() {
      return m_source;
   }
   Airport *getDest() {
      return m_destination;
   }
   double getDist() {
      return m_distance;
   }
};

#endif
