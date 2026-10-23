/*
 *    Team name: Coding Cadets
 *    Team members: [Brayden Graham, Todd Dharni, Thaddeus Schelp]
 *    Course and section: CS 2430-002
 *    Project name: Programming Project 2 – Fall 2026
 *    Primary author: Brayden Graham
 */

#include "RepresentationHelper.h"
#include "SetsOperations.h"
#include <limits>
#include <sstream>

namespace Project2::CheckSet {

Set fuzzyComplement(const Set& A)
{
    // Since max represents membership 1, subtracting a value gives its complement.
    const uint32_t maxMembership = std::numeric_limits<uint32_t>::max();
    Set result(std::vector<uint32_t>(A.contents.size(), 0));
    for (size_t i = 0; i < A.contents.size(); ++i) {
        result.contents[i] = maxMembership - A.contents[i];
    }
    return result;
}

Set fuzzyUnion(const Set& A, const Set& B)
{
    const size_t size = Set::maxSize(A, B);
    Set result = Set(std::vector<uint32_t>(size, 0));
    for (size_t i = 0; i < size; ++i) {
        // Max membership gives the fuzzy union of the two elements.
        const uint32_t valA = (i < A.contents.size()) ? A.contents[i] : 0;
        const uint32_t valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = std::max(valA, valB);
    }
    return result;
}

Set fuzzyIntersection(const Set& A, const Set& B)
{
    const size_t size = Set::maxSize(A, B);
    Set result(std::vector<uint32_t>(size, 0));
    for (size_t i = 0; i < size; ++i) {
        // Min membership gives the fuzzy intersection of the two elements.
        const uint32_t valA = (i < A.contents.size()) ? A.contents[i] : 0;
        const uint32_t valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = std::min(valA, valB);
    }
    return result;
}

Set fuzzySum(const Set& A, const Set& B)
{
    const size_t size = Set::maxSize(A, B);
    const uint32_t maxMembership = std::numeric_limits<uint32_t>::max();
    Set result(std::vector<uint32_t>(size, 0));
    for (size_t i = 0; i < size; ++i) {
        // Add memberships, but cap the result at 1 and avoid uint32_t overflow.
        const uint32_t valA = (i < A.contents.size()) ? A.contents[i] : 0;
        const uint32_t valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = valA > maxMembership - valB ? maxMembership : valA + valB;
    }
    return result;
}

std::string runFuzzySetCheck(const Set& A, const Set& B)
{
    // The formatter converts the stored integers back to readable 0-to-1 values.
    std::ostringstream printOut;

    printOut << "========================================\n";
    printOut << "           Fuzzy Operations\n";
    printOut << "========================================\n";
    printOut << "Fuzzy A: " << helper::toFuzzysetListing(A.contents) << "\n";
    printOut << "Fuzzy B: " << helper::toFuzzysetListing(B.contents) << "\n\n";

    const Set complementA = fuzzyComplement(A);
    const Set mUnFuzzy = fuzzyUnion(A, B);
    const Set mInterFuzzy = fuzzyIntersection(A, B);
    const Set mSumFuzzy = fuzzySum(A, B);

    printOut << "Fuzzy Complement (NOT A):    " << helper::toFuzzysetListing(complementA.contents)
             << "\n";
    printOut << "Fuzzy Union (A u B):        " << helper::toBitString(mUnFuzzy.contents) << " -> "
             << helper::toFuzzysetListing(mUnFuzzy.contents) << "\n";
    printOut << "Fuzzy Intersection (A n B): " << helper::toBitString(mInterFuzzy.contents)
             << " -> " << helper::toFuzzysetListing(mInterFuzzy.contents) << "\n";
    printOut << "Fuzzy Sum (A (+) B):        " << helper::toBitString(mSumFuzzy.contents) << " -> "
             << helper::toFuzzysetListing(mSumFuzzy.contents) << "\n";

    return printOut.str();
}

} // namespace Project2::CheckSet
