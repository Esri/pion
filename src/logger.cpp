// ---------------------------------------------------------------------
// pion:  a Boost C++ framework for building lightweight HTTP interfaces
// ---------------------------------------------------------------------
// Copyright (C) 2007-2014 Splunk Inc.  (https://github.com/splunk/pion)
//
// Distributed under the Boost Software License, Version 1.0.
// See http://www.boost.org/LICENSE_1_0.txt
//

#include <pion/logger.hpp>

namespace pion {    // begin namespace pion


// static members of logger
#if defined(PION_USE_OSTREAM_LOGGING)
logger::log_priority_type    logger::m_priority = logger::LOG_LEVEL_INFO;
#elif defined(PION_DISABLE_LOGGING)
   
  class NullLogSink : public LogSink
  {
    std::string _name;

  public:
    NullLogSink(const char* name) : _name(name)
    {
    }

    ~NullLogSink()
    {
      // Nothing to do
    }

    void Log(int level, const char* message) {}
    bool IsEnabled(int level) { return false; }
  };

  class NullLogFactory : public LogFactory
  {
  public:
    LogSink* GetLogger(const char* name)
    {
      return new NullLogSink(name);
    }
  };


  LogFactory* logger::_factory = new NullLogFactory();

#endif

    
}   // end namespace pion
