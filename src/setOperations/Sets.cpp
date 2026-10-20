/*
 *    Team name: Coding Cadets
 *    Team members: [Brayden Graham, Todd Dharni, Thaddeus Schelp]
 *    Course and section: CS 2430-002
 *    Project name: Programming Project 2 – Fall 2026
 *    Primary author: Brayden Graham
 */

#include "RepresentationHelper.h"
#include "SetsOperations.h"
#include <sstream>

namespace Project2::CheckSet {

// Implementation
Set complement(const Set& A, size_t universalSize)
{
    Set result(std::vector<uint32_t>(universalSize, 0));
    for (size_t i = 0; i < universalSize; ++i) {
        const uint32_t val = (i < A.contents.size()) ? A.contents[i] : 0;
        result.contents[i] = !val;
    }
    return result;
}

Set setUnion(const Set& A, const Set& B)
{
    const size_t size = Set::maxSize(A, B);
    Set result(std::vector<uint32_t>(size, 0));
    for (size_t i = 0; i < size; ++i) {
        const uint32_t valA = (i < A.size()) ? A.contents[i] : 0;
        const uint32_t valB = (i < B.size()) ? B.contents[i] : 0;
        result.contents[i] = (valA || valB) ? 1 : 0;
    }
    return result;
}

Set setIntersection(const Set& A, const Set& B)
{
    const size_t size = Set::maxSize(A, B);
    Set result(std::vector<uint32_t>(size, 0));
    for (size_t i = 0; i < size; ++i) {
        const uint32_t valA = (i < A.contents.size()) ? A.contents[i] : 0;
        const uint32_t valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = (valA && valB) ? 1 : 0;
    }
    return result;
}

Set setDifference(const Set& A, const Set& B)
{
    const size_t size = Set::maxSize(A, B);
    Set result(std::vector<uint32_t>(size, 0));
    for (size_t i = 0; i < size; ++i) {
        const uint32_t valA = (i < A.contents.size()) ? A.contents[i] : 0;
        const uint32_t valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = (valA && !valB) ? 1 : 0;
    }
    return result;
}

Set symmetricDifference(const Set& A, const Set& B)
{
    const size_t size = Set::maxSize(A, B);
    Set result(std::vector<uint32_t>(size, 0));
    for (size_t i = 0; i < size; ++i) {
        const uint32_t valA = (i < A.contents.size()) ? A.contents[i] : 0;
        const uint32_t valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = (valA ^ valB) ? 1 : 0;
    }
    return result;
}

std::string runSetCheck(const Set& A, const Set& B, size_t universalSize)
{
    std::ostringstream out;
    out << "========================================\n";
    out << "     Ordinary Set Operations (n = " << universalSize << ")\n";
    out << "========================================\n";
    out << "Set A Bit Array: " << helper::toBitString(A.contents) << " -> "
        << helper::toElementListing(A.contents) << "\n";
    out << "Set B Bit Array: " << helper::toBitString(B.contents) << " -> "
        << helper::toElementListing(B.contents) << "\n\n";

    const Set notA = complement(A, universalSize);
    const Set un = setUnion(A, B);
    const Set inter = setIntersection(A, B);
    const Set diff = setDifference(A, B);
    const Set sym = symmetricDifference(A, B);

    out << "NOT(A):        " << helper::toBitString(notA.contents) << " -> "
        << helper::toElementListing(notA.contents) << "\n";
    out << "A U B:         " << helper::toBitString(un.contents) << " -> "
        << helper::toElementListing(un.contents) << "\n";
    out << "A n B:         " << helper::toBitString(inter.contents) << " -> "
        << helper::toElementListing(inter.contents) << "\n";
    out << "A - B:         " << helper::toBitString(diff.contents) << " -> "
        << helper::toElementListing(diff.contents) << "\n";
    out << "A (+) B:       " << helper::toBitString(sym.contents) << " -> "
        << helper::toElementListing(sym.contents) << "\n";

    return out.str();
}

} // namespace Project2::CheckSet
