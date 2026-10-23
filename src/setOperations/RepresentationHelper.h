#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace Project2::CheckSet::helper {

// These formatters are shared by the ordinary, multiset, and fuzzy reports.
std::string toBitString(const std::vector<uint32_t>& contents);
std::string toElementListing(const std::vector<uint32_t>& contents);
std::string toMultisetListing(const std::vector<uint32_t>& contents);
std::string toFuzzysetListing(const std::vector<uint32_t>& contents);

} // namespace Project2::CheckSet::helper
