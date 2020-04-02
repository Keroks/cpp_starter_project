#include <functional>
#include <iostream>

#include <spdlog/spdlog.h>


#include <docopt/docopt.h>

#include <iostream>

static constexpr auto USAGE =
  R"(cpp_starter_project

    Usage:
          cpp_starter_project
          cpp_starter_project (-h | --help)
          cpp_starter_project --version
    Options:
          -h --help     Show this screen.
          --version     Show version.
          --valueWithDefault=<value>  Some Value [default: 0].
)";

int main(int argc, const char **argv)
{
  std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
    { std::next(argv), std::next(argv, argc) },
    true,// show help if requested
    "cpp_starter_project 1.0");// version string

  for (auto const &arg : args) {
    std::cout << arg.first << arg.second << std::endl;
  }


  //Use the default logger (stdout, multi-threaded, colored)
  spdlog::info("Hello, {}!", "World");

  fmt::print("Hello, from {}\n", "{fmt}");
}
