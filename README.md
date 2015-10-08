dout
======================

Basic wrapper around std::cerr to provide a more structured way to print output
in C++ programs. This is implemented as a header-only library.

Installation
------------
Currently, installation is available from source and as an ArchLinux AUR package.

###Dependencies
 - `cmake` >= 3.0.2
 - `g++``` >= 4.8.2 or some other C++11 compatible compiler

###Example Build:
```bash
git clone https://github.com/slizzered/dout.git
cd dout
mkdir build && cd build
cmake ..
make example
```

### Install
```bash
git clone https://github.com/slizzered/dout.git
cd dout
mkdir build && cd build
cmake ..
make install
```

### Installation also available for ArchLinux AUR
Package: `dout-git`


###Use as a library
*dout* ships a [CMake-Configfile](https://cmake.org/cmake/help/v3.4/manual/cmake-packages.7.html#config-file-packages), that can be used if your project is built with *CMake*. Depending on how/where *dout* is installed, there are 2 main possibilities to include it in your projects:

####local install in a custom folder
Assuming that you cloned the repository to `$HOME/dout`, you can instruct CMake to use that folder by adding `$HOME/dout/cmake` to your `CMAKE_PREFIX_PATH`. Inside your CMakeLists.txt, use findPackage(dout).

####global install (e.g. using the ArchLinux AUR package)
By default, the package will install the library files under `<prefix>/lib/dout` and the configfile at `<prefix>/lib/dout/cmake`. `<prefix>` should be set to some path that is looked for by CMake. For Unix installations, that would be `/usr`. Afterwards, all you have to do in your project is to call `findPackage(dout)` to add *dout* to your project.


Usage
-----
You always need the instance of ```Dout```, which you can handily obtain by
calling ```Dout::getInstance()```.  

Per default, Dout is set to print with maximum verbosity. You can change the
verbosity flags that are honored by using the following functions

| Name              |
| :------------     |
| setVerbosity()    |
| addVerbosity()    |
| removeVerbosity() |
| getVerbosity()    |

You can change the colors for each flag with  

| Name         |
| :----------- |
| setColor()   |

You can change the label text for each flag with  

| Name         |
| :----------- |
| setLabel()   |  

###Examples
```c++
#include "dout/dout.hpp"
using namespace dout;

Dout dout = Dout::getInstance();

dout.setVerbosity(Flags::WARN | Flags::ERROR);
dout.addVerbosity(Flags::DEBUG);

dout(Flags::WARN) << "This is a warning" << std::endl;
dout(Flags::DEBUG) << "This is some debug output" << std::endl;

dout.removeVerbosity(Flags::DEBUG);
dout(Flags::DEBUG) << "This output will not appear" << std::endl;

dout.setColor(Flags::WARN, Colors::RED);
dout(Flags::WARN) << "This is a warning in red" << std::endl;
```

License
-------
Copyright (c) 2014-2015 Carlchristian Eckert
Licensed under the MIT license.  
Free as in beer.
