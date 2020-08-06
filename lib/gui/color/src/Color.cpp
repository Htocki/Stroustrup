#include "Color.h"

Color::Color(Name name)
    : _name { name }
{}

Color::Color(Name name, Visibility visibility)
    : _name { name }
    , _visibility { visibility }
{}

Color::Color(Visibility visibility)
    : _visibility { visibility }
{}

