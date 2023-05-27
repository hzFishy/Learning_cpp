#include <iostream>

int main() {
  double tempf = 66;
  double tempc = 0;
  
  tempc = (tempf-32)/1.8;
  
  std::cout << "The temp is " << tempc << " degrees Celsius.\n";
}
