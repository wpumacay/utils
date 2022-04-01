// clang-format off
#include <cassert>
#include <sstream>

#include <loco/utils/common.hpp>
// clang-format on

namespace loco {
namespace utils {

auto Split(const std::string &txt, char separator) -> std::vector<std::string> {
    std::vector<std::string> vec_str;

    // --------------------------------
    // Just in case, if the separator was not found, just return vec[txt]
    size_t curr_pos = txt.find(separator);
    if (curr_pos == std::string::npos) {
        vec_str.push_back(txt);
        return vec_str;
    }

    // --------------------------------
    // If found the separator, there might be various occurrences, so look for
    // it one by one iteratively, until all occurrences are accounted for
    size_t last_pos = 0;
    while (curr_pos != std::string::npos) {
        // The 'curr_pos' index is always bigger than the 'last_pos' index
        assert(curr_pos > last_pos);

        // Grab the last occurrence and place it into our results vector
        vec_str.push_back(txt.substr(last_pos, curr_pos - last_pos));

        // Continue looking for the separator in the next portion of the string
        last_pos = curr_pos + 1;

        // Find the next occurrence of the separator in the remainder string
        curr_pos = txt.find(separator, last_pos);
    }

    // --------------------------------
    // Process the remainder (word leftover, or empty string)
    if (last_pos < txt.size()) {
        vec_str.push_back(txt.substr(last_pos, txt.size() - last_pos));
    }

    return vec_str;
}

auto PointerToHexAddress(const void *ptr) -> std::string {
    std::stringstream ss;
    // NOLINTNEXTLINE : allow reinterpret_cast just for this
    ss << "0x" << std::hex << reinterpret_cast<std::intptr_t>(ptr);
    return ss.str();
}

}  // namespace utils
}  // namespace loco