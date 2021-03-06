#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "lambrex.h"

#define CATCH_CONFIG_EXTERNAL_INTERFACES

struct AMReXListener : Catch::TestEventListenerBase {

  using TestEventListenerBase::TestEventListenerBase; // inherit constructor

  // Get rid of Wweak-tables
  ~AMReXListener();

  virtual void testRunStarting(Catch::TestRunInfo const& testRunInfo) override {
    int argc = 0;
    char **argv;
    amrex::Initialize(argc, argv, false);
  }

  virtual void testRunEnded(Catch::TestRunStats const& testRunStats) override {
    amrex::Finalize();
  }
};

CATCH_REGISTER_LISTENER(AMReXListener)

// Get rid of Wweak-tables
AMReXListener::~AMReXListener() {}
