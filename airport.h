#ifndef __AIRPORT_H_INCLUDED__
#define __AIRPORT_H_INCLUDED__

#include <iostream>
#include <string>
using namespace std;

class Airport {
private:
   string m_code;
   string m_id;
   double m_latitude;
   double m_longitude;

public:
   Airport();
   Airport(string code, string id, double lattude, double longitude);

   string getCode() {
      return m_code;
   }
   string getID() {
      return m_id;
   }
   double getLat() {
      return m_latitude;
   }
   double getLon() {
      return m_longitude;
   }
};

#endif
