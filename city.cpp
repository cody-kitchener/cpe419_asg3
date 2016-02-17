#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "route.h"
#include "city.h"

City::City() {}

void City::setName(string name) {
   m_name = name;
}

void City::addRoute(Route route) {
   m_routes.push_back(route);
}
