#ifndef LOCATION_H
#define LOCATION_H
#include <fstream>
#include <sstream>
#include <string>

using std::getline;
using std::ifstream;
using std::stringstream;
using std::string;

struct Location {
  string name;
  string address;
  string city;
  long postalCode;
  string province;
  double longitude;
  double latitude;
  int priceRangeMin;
  int priceRangeMax;
};


#endif /* end of include guaef  */
