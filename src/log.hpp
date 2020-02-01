#pragma once

#include <string>

enum log_level {
    debug,
    error,
    warning
};

void log(log_level,std::string txt);