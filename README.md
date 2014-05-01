dout
======================

Basic wrapper around std::cerr to provide a more structured way to print output
in C++ programs. This


Installation
------------
Currently, installation is only available from source.

###Dependencies
 - uses features from ```C++03```
 - ```cmake``` >= 2.8.5
 - ```clang``` >= 3.4 or ```g++``` >= 4.8.2
 - ```boost``` >= 1.55

###Build:
```bash
git clone https://github.com/slizzered/dout.git
cd dout
cmake .
make
```

Usage
-----

You always need the instance of ```Dout```, which you can handily obtain by
calling ```Dout::getInstance()```.  

Per default, Dout is set to print with maximum verbosity. You can change the
verbosity flags that are honored by using one of the following functions:  
setVerbosity()  
addVerbosity()  
removeVerbosity()  
getVerbosity()  

You can change the colors for each flag with  
setColor()  

You can change the label text for each flag with  
setLabel()  


###Examples
```c++
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

Copyright (c) 2014 Carlchristian Eckert  
Licensed under the MIT license.  
Free as in beer.
