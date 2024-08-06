#include <catch2/catch_session.hpp>

int main( int argc, char* argv[] ) {
  // your setup ...
  Catch::Session session;

  int height = 0;

  using namespace Catch::Clara;
  auto cli
    = session.cli()           // Get Catch2's command line parser
    | Opt( height, "height" ) // bind variable to a new option, with a hint string
        ["-g"]["--height"]    // the option names it will respond to
        ("how high?");        // description string for the help outpu

  session.cli( cli );

  session.run();

  return 0;
}
