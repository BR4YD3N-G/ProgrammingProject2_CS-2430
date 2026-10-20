/*
 *    Team name: Coding Cadets
 *    Team members: [Brayden Graham, Todd Dharni, Thaddeus Schelp]
 *    Course and section: CS 2430-002
 *    Project name: Programming Project 2 – Fall 2026
 *    Primary author: Brayden Graham
 */

#include "RepresentationHelper.h"
#include <limits>

namespace Project2::CheckSet::helper {

std::string toBitString(const std::vector<uint32_t>& contents)
{
    std::string s = "[";
    for (size_t i = 0; i < contents.size(); ++i) {
        s += std::to_string(contents[i]);
        if (i + 1 < contents.size()) {
            s += ", ";
        }
    }
    s += ']';
    return s;
}

std::string toElementListing(const std::vector<uint32_t>& contents)
{
    std::string s = "{";
    bool first = true;
    for (size_t i = 0; i < contents.size(); ++i) {
        if (contents[i] != 0) {
            if (!first) {
                s += ", ";
            }
            s += "e" + std::to_string(i);
            first = false;
        }
    }
    s += '}';
    return first ? "∅" : s;
}

std::string toMultisetListing(const std::vector<uint32_t>& contents)
{
    std::string s = "{";
    bool first = true;
    for (size_t i = 0; i < contents.size(); ++i) {
        if (contents[i] > 0) {
            if (!first) {
                s += ", ";
            }
            s += std::to_string(contents[i]) + "·e" + std::to_string(i);
            first = false;
        }
    }
    s += '}';
    return first ? "∅" : s;
}

std::string toFuzzysetListing(const std::vector<uint32_t>& contents)
{
    std::string s = "{";
    bool first = true;
    for (size_t i = 0; i < contents.size(); ++i) {
        if (contents[i] > 0) {
            if (!first) {
                s += ", ";
            }
            s += std::to_string(static_cast<double>(contents[i]) /
                                std::numeric_limits<uint32_t>::max()) +
                 "·e" + std::to_string(i);
            first = false;
        }
    }
    s += '}';
    return first ? "∅" : s;
}

} // namespace Project2::CheckSet::helper
