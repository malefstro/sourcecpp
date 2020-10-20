#include <sstream>
#include <iostream>
#include "var_utils_01.hpp"
using namespace std;

/*!
 * safe parse a string to an unsigned long
 *
 * @param incoming
 * @return optional unsigned long
 */
std::optional<uint64_t> varu::safe_parse_str_to_uint64_t(const std::string &incoming) {

    std::optional<uint64_t> maybe_uint64_t {nullopt};

    try {

        auto res = stol(incoming);

        if (res>=0) {
            maybe_uint64_t = res;
        }

    } catch ( exception& ex ) {
        cout << "safe_parse_str_to_uint64_t exception " << ex.what() << " for " << incoming << endl;
    }

    return maybe_uint64_t;
}
