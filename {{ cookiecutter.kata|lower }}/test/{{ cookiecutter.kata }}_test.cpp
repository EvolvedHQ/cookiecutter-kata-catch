#include "catch.hpp"
#include "trompeloeil.hpp"
#include "{{ cookiecutter.kata }}.hpp"

extern template struct trompeloeil::reporter<trompeloeil::specialized>;
