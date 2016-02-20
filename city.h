#ifndef __CITY_H_INCLUDED__
#define __CITY_H_INCLUDED__

class Route;

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "route.h"

class City {
private:
   string m_name;
   vector<Route> m_routes;

public:
   City();
   City(string name);

   void setName(string name);
   void addRoute(Route route);

   string getName() {
      return m_name;
   }
   int getNumRoutes() {
      return m_routes.size();
   }
};

#endif
