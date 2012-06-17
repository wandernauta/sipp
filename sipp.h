/* Define base quantity names used in the SI as types. */
typedef long double quantity;
typedef quantity qlength;
typedef quantity qmass;
typedef quantity qtime;
typedef quantity qcurrent;
typedef quantity qtemperature;
typedef quantity qintensity;
typedef quantity qamount;

/* Define some additional quantity names. */
typedef quantity qspeed;

#define suffix constexpr quantity operator ""

#define base_unit(quantity, unit) \
  def_unit(quantity,  y##unit, 0.000000000000000000000001L)   \
  def_unit(quantity,  z##unit, 0.000000000000000000001L)      \
  def_unit(quantity,  a##unit, 0.000000000000000001L)         \
  def_unit(quantity,  f##unit, 0.000000000000001L)            \
  def_unit(quantity,  p##unit, 0.000000000001L)               \
  def_unit(quantity,  n##unit, 0.000000001L)                  \
  def_unit(quantity,  u##unit, 0.000001L)                     \
  def_unit(quantity,  m##unit, 0.001L)                        \
  def_unit(quantity,  c##unit, 0.01L)                         \
  def_unit(quantity,  d##unit, 0.1L)                          \
  def_unit(quantity,     unit, 1.0L)                          \
  def_unit(quantity, da##unit, 10.0L)                         \
  def_unit(quantity,  h##unit, 100.0L)                        \
  def_unit(quantity,  k##unit, 1000.0L)                       \
  def_unit(quantity,  M##unit, 1000000.0L)                    \
  def_unit(quantity,  G##unit, 1000000000.0L)                 \
  def_unit(quantity,  T##unit, 1000000000000.0L)              \
  def_unit(quantity,  P##unit, 1000000000000000.0L)           \
  def_unit(quantity,  E##unit, 1000000000000000000.0L)        \
  def_unit(quantity,  Z##unit, 1000000000000000000000.0L)     \
  def_unit(quantity,  Y##unit, 1000000000000000000000000.0L)

#define def_unit(quantity, unit, factor) \
  suffix _##unit (quantity x) { return x * factor; } \
  suffix _##unit (unsigned long long x) { return (quantity)x * factor; }

/* Define the base units */
base_unit(qlength, m);
base_unit(qmass, g);
base_unit(qtime, s);
base_unit(qcurrent, A);
base_unit(qtemperature, K);
base_unit(qintensity, cd);
base_unit(qamount, mol);
/* FIXME: SI defines the kg, not the g, as the base unit of mass. */

/* Define some other useful units accepted for use with the SI. */
def_unit(qtime, min, 60_s);
def_unit(qtime, h, 60_min);
def_unit(qtime, d, 24_h);
def_unit(qmass, t, 1000_kg);

/* Define Fahrenheit and Celsius to Kelvin utility conversion operators. */
suffix _F (long double F) { return (F + 459.67) * (5.0/9.0); }
suffix _F (unsigned long long F) { return (F + 459.67) * (5.0/9.0); }

suffix _C (long double C) { return (C + 273.15); }
suffix _C (unsigned long long C) { return (C + 273.15); }

/* Define some units as constants */
namespace si {
  const qtime s = 1_s;
  const qtime min = 1_min;
  const qtime h = 1_h;
  const qtime d = 1_d;
}

/* Define some other constants */
namespace si {
  const qspeed c0 = 299792458_m/s;
}
