#include <iostream>
#include <fstream>
using namespace std;

// Step size
#define h 10
// Constant k
#define k_init 20
// Voltage
#define S_init 50
// Reaction time
#define R_init 180
// Initial voltage
#define S_start 50
// End voltage
#define S_finish 550

// Weber-Fechner low
double f(double X) { return (k_init / X); }

// Runge-Kutta function
void runge() {

  double x, y, x2, y2, x3, y3, s1, s2, s3, s4;
  int i = S_start;
  x = S_init;
  y = R_init;

  ofstream out("weberfechner.dat");

  if (!out) {
    cout << "Cannot open file.\n";
  }

  do {
    out << i << " " << y << endl;

    s1 = f(x);
    s2 = f(x + h / 2.0);
    s3 = f(x + h / 2.0);
    s4 = f(x + h);
    y += h * (s1 + 2.0 * s2 + 2.0 * s3 + s4) / 6.0;
    x += h;

    i += h;

  } while (i <= S_finish);

  out.close();
}

int main() {

  runge();

  return 0;
}
