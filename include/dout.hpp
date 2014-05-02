#pragma once
#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <sstream>

namespace dout{

  struct nullstream : std::ostream {
    nullstream() : std::ostream(0) {}
  };

  enum Flags{
    QUIET = 0,
    ERROR = 1,
    WARN  = 2,
    INFO  = 4,
    STAT  = 8,
    DEBUG = 16,

    ALL   = ~0
  };

  enum Colors{
    NOCOLOR = 0,

    BLACK   = 30,
    RED     = 31,
    GREEN   = 32,
    YELLOW  = 33,
    BLUE    = 34,
    MAGENTA = 35,
    CYAN    = 36,
    GRAY    = 37
  };


  class Dout{

    unsigned verbosity;
    Colors colors;
    std::map<unsigned const, std::string> colormap;
    std::map<unsigned const, std::string> labelmap;

    void operator=(Dout const&); // private assignment

    // private constructor
    Dout() : verbosity(~0) {
      colormap.insert(std::make_pair(Flags::ERROR, colorString(Colors::RED)));
      colormap.insert(std::make_pair(Flags::WARN,  colorString(Colors::YELLOW)));
      colormap.insert(std::make_pair(Flags::INFO,  colorString(Colors::NOCOLOR)));
      colormap.insert(std::make_pair(Flags::STAT,  colorString(Colors::NOCOLOR)));
      colormap.insert(std::make_pair(Flags::DEBUG, colorString(Colors::CYAN)));

      labelmap.insert(std::make_pair(Flags::ERROR, "[ERROR]     "));
      labelmap.insert(std::make_pair(Flags::WARN,  "[WARNING]   "));
      labelmap.insert(std::make_pair(Flags::INFO,  "[INFO]      "));
      labelmap.insert(std::make_pair(Flags::STAT,  "[STATISTIC] "));
      labelmap.insert(std::make_pair(Flags::DEBUG, "[DEBUG]     "));
    }

    inline std::ostream& mkLabel(unsigned const flag, bool const useLabel){
        std::string label = useLabel ? labelmap[flag] : "";
        return std::cerr << colormap[flag] << label;
    }

    inline std::string colorString(unsigned const color){
      if(color==0) return "\033[0m";
      assert(color >= 30 && color <=37);

      std::stringstream ss;
      ss << "\033[0;";
      ss << color;
      ss << "m";
      return ss.str();
    }


    public:

    // Singleton
    static Dout& getInstance(){
      static Dout instance;
      return instance;
    }

    inline std::ostream& operator()(unsigned const urgency=Flags::INFO, bool const useLabel=true) {

      // if the verbosity does not match any of the flags, don't print anything
      if(!(urgency & verbosity)){
        static nullstream dummy;
        return dummy;
      }
      
      // if you have defined additional flags, add them here. Order matters,
      // if dout() is called with multiple verbosity flags.
      if(urgency &     Flags::ERROR){
        return mkLabel(Flags::ERROR, useLabel);
      }

      if(urgency &     Flags::WARN){
        return mkLabel(Flags::WARN, useLabel);
      }

      if(urgency &     Flags::INFO){
        return mkLabel(Flags::INFO, useLabel);
      }

      if(urgency &     Flags::STAT){
        return mkLabel(Flags::STAT, useLabel);
      }

      if(urgency &     Flags::DEBUG){
        return mkLabel(Flags::DEBUG, useLabel);
      }

      // if the urgency flag matches the verbosity, but no flag fits, print to
      // stdout
      return std::cout;
    }

    inline unsigned addVerbosity(unsigned const newFlag){
      verbosity |= newFlag;
      return verbosity;
    }

    inline unsigned removeVerbosity(unsigned const flag){
      verbosity &= ~flag;
      return verbosity;
    }

    inline unsigned setVerbosity(unsigned const newVerbosityFlags){
      verbosity = newVerbosityFlags;
      return verbosity;
    }

    inline unsigned getVerbosity(){
      return verbosity;
    }

    inline void setColor(unsigned const flag, unsigned const color){
      assert(colormap.find(flag) != colormap.end());
      colormap[flag] = colorString(color);
    }

    inline std::string getColor(unsigned const flag){
      assert(colormap.find(flag) != colormap.end());
      return colormap[flag];
    }

    inline void setLabel(unsigned const flag, std::string const label){
      assert(labelmap.find(flag) != labelmap.end());
      labelmap[flag] = label;
    }

    inline std::string getLabel(unsigned const flag){
      assert(labelmap.find(flag) != labelmap.end());
      return labelmap[flag];
    }

  };
}
