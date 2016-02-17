#ifndef __AIRPORT_H_INCLUDED__
#define __AIRPORT_H_INCLUDED__

#include <iostream>
#include <string>
using namespace std;

class Airport {
private:
   string m_code;
   double m_latitude;
   double m_longitude;

public:
   Airport(string code, double lattude, double longitude);

   string getCode() {
      return m_code;
   }
   double getLat() {
      return m_latitude;
   }
   double getLong() {
      return m_longitude;
   }
};

#endif
