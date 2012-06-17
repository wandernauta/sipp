#include "sipp.h"
#include <iostream>

using namespace std;
using namespace si;

def_unit(qlength, mi, 1.609344_km);

int main() {
  qspeed v = 180_km/h;
  cout << "- Driving at " << v << " m/s is usually considered speeding." << endl;

  cout << "- Is 100m less than 1km? " << ((100_m < 1_km) ? "Yes." : "No.") << endl;

  qlength tour = 3430.5_km;
  qtime lance = 41.7_km/h;
  qtime swallow = 11_m/s;
  cout << "- Who would finish the Tour de France first, Lance Armstrong or a swallow? " << (((tour / lance) < (tour / swallow)) ? "Lance." : "The bird.") << endl;

  qtemperature water = 100_C;
  cout << "- Water boils at " << water << " degrees Kelvin." << endl;

  cout << "- Detroit's 8 Mile Road is " << (8_mi) / 1_km << " km long." << endl;
}
