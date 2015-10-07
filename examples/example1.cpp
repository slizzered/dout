#include <iostream>
#include "dout/dout.hpp"

using dout::Flags;
using dout::Colors;

int main(){
  dout::Dout dout = dout::Dout::getInstance();

  dout(Flags::WARN) << "test" << std::endl;

  return 0;
}
