#include "helper.h"
#include <iostream>
#include <fstream>

Helper::Helper() {
    x = 0;
}

void Helper::install_() {
    ++x;
}

void Helper::delete_() {
    ++x;
}

int Helper::getx_() const {
    return x;
}
