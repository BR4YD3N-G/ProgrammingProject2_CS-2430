#include "../src/setOperations/SetsOperations.h"

#include <cstdint>
#include <iostream>
#include <iomanip>

static constexpr std::initializer_list<uint32_t> setA = {0, 1, 0, 1};
static constexpr std::initializer_list<uint32_t> setB = {0, 0, 1, 1};
static constexpr std::initializer_list<uint32_t> multisetA = {0, 1, 2, 3, 4};
static constexpr std::initializer_list<uint32_t> multisetB = {4, 3, 2, 1, 0};
constexpr uint32_t max = std::numeric_limits<uint32_t>::max();
static constexpr std::initializer_list<uint32_t> fuzzysetA = {max, max/2, max/4};
static constexpr std::initializer_list<uint32_t> fuzzysetB = {max/4, max/2, max};

/**
 * Compares two sets for equivalence.
 * If they are the same, returns -1. Otherwise, returns the first index where the two sets differ.
 * @param set The set to compare.
 * @param expected The expected value for the set.
 * @return The first index where the two sets differ, or -1 if they are the same.
 */
static constexpr int assertEquals(const Set& set, const Set& expected)
{
    for (int i = 0; i < Set::maxSize(set, expected); ++i) {
        if (i >= set.size() || i >= expected.size()) {
            std::cerr << "Set has " << set.size() << " elements. Expected: " << expected.size();
            return i;
        }
        if (set.contents[i] != expected.contents[i]) {
            std::cerr << "Sets differ at index " << i << ": (" << set.contents[i]
                      << " != " << expected.contents[i] << ")" << std::endl;
            return i;
        }
    }
    return -1;
}

/**
 * Compares two sets for equivalence, and displays the results as fuzzy sets.
 * If they are the same, returns -1. Otherwise, returns the first index where the two sets differ.
 * @param set The set to compare.
 * @param expected The expected value for the set.
 * @return The first index where the two sets differ, or -1 if they are the same.
 */
static constexpr int assertEqualsFuzzy(const Set& set, const Set& expected)
{
    for (int i = 0; i < Set::maxSize(set, expected); ++i) {
        if (i >= set.size() || i >= expected.size()) {
            std::cerr << "Set has " << set.size() << " elements. Expected: " << expected.size();
            return i;
        }
        if (set.contents[i] != expected.contents[i]) {
            std::cerr << std::setprecision(15) << "Sets differ at index " << i << ": (" << static_cast<double>(max)/set.contents[i]
                      << " != " << static_cast<double>(max)/expected.contents[i] << ")" << std::endl;
            return i;
        }
    }
    return -1;
}

static int testSetComplement()
{
    const Set a = setA;
    const Set expected = {1, 0, 1, 0};
    const Set set = Project2::CheckSet::complement(a, a.size());
    if (assertEquals(set, expected) == -1)
        return 0;
    return -1;
}

static int testSetUnion()
{
    const Set a = setA;
    const Set b = setB;
    const Set expected = {0, 1, 1, 1};
    const Set set = Project2::CheckSet::setUnion(a, b);
    if (assertEquals(set, expected) == -1)
        return 0;
    return -1;
}

static int testSetIntersection()
{
    const Set a = setA;
    const Set b = setB;
    const Set expected = {0, 0, 0, 1};
    const Set set = Project2::CheckSet::setIntersection(a, b);
    if (assertEquals(set, expected) == -1)
        return 0;
    return -1;
}

static int testSetDifference()
{
    const Set a = setA;
    const Set b = setB;
    const Set expected = {0, 1, 0, 0};
    const Set set = Project2::CheckSet::setDifference(a, b);
    if (assertEquals(set, expected) == -1)
        return 0;
    return -1;
}

static int testSetSymmetricDifference()
{
    const Set a = setA;
    const Set b = setB;
    const Set expected = {0, 1, 1, 0};
    const Set set = Project2::CheckSet::symmetricDifference(a, b);
    if (assertEquals(set, expected) == -1)
        return 0;
    return -1;
}

static int testMultisetUnion()
{
    const Set a = multisetA;
    const Set b = multisetB;
    const Set expected = {4, 3, 2, 3, 4};
    const Set set = Project2::CheckSet::multisetUnion(a, b);
    if (assertEquals(set, expected) == -1)
        return 0;
    return -1;
}

static int testMultisetIntersection()
{
    const Set a = multisetA;
    const Set b = multisetB;
    const Set expected = {0, 1, 2, 1, 0};
    const Set set = Project2::CheckSet::multisetIntersection(a, b);
    if (assertEquals(set, expected) == -1)
        return 0;
    return -1;
}

static int testMultisetDifference()
{
    const Set a = multisetA;
    const Set b = multisetB;
    const Set expected = {0, 0, 0, 2, 4};
    const Set set = Project2::CheckSet::multisetDifference(a, b);
    if (assertEquals(set, expected) == -1)
        return 0;
    return -1;
}

static int testMultisetSum()
{
    const Set a = multisetA;
    const Set b = multisetB;
    const Set expected = {4, 4, 4, 4, 4};
    const Set set = Project2::CheckSet::multisetSum(a, b);
    if (assertEquals(set, expected) == -1)
        return 0;
    return -1;
}

static int testFuzzySetComplement()
{
    const Set a = fuzzysetA;
    const Set expected = {0, max/2 + 1, (max/4+1) * 3};
    const Set set = Project2::CheckSet::fuzzyComplement(a);
    if (assertEqualsFuzzy(set, expected) == -1)
        return 0;
    return -1;
}

static int testFuzzySetUnion()
{
    const Set a = fuzzysetA;
    const Set b = fuzzysetB;
    const Set expected = {max, max/2, max};
    const Set set = Project2::CheckSet::fuzzyUnion(a, b);
    if (assertEqualsFuzzy(set, expected) == -1)
        return 0;
    return -1;
}

static int testFuzzySetIntersection()
{
    const Set a = fuzzysetA;
    const Set b = fuzzysetB;
    const Set expected = {max/4, max/2, max/4};
    const Set set = Project2::CheckSet::fuzzyIntersection(a, b);
    if (assertEqualsFuzzy(set, expected) == -1)
        return 0;
    return -1;
}
/**
 * Finds the fnv1-a hash of a null terminated string.
 * @param str The null terminated string to hash.
 * @return The fnv1-a hash of str.
 */
static constexpr uint64_t fnv1a(const char* str)
{
    uint64_t hash = 0xcbf29ce484222325;
    while (*str) {
        hash ^= *str++;
        hash *= 0x100000001b3;
    }
    return hash;
}

int main(const int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Exactly one test must be specified.";
        return -1;
    }
    switch (fnv1a(argv[1]))
    {
        // set tests
        case fnv1a("--setComplement"): return testSetComplement();
        case fnv1a("--setUnion"): return testSetUnion();
        case fnv1a("--setIntersection"): return testSetIntersection();
        case fnv1a("--setDifference"): return testSetDifference();
        case fnv1a("--setSymmetricDifference"): return testSetSymmetricDifference();

        // multiset tests
        case fnv1a("--multisetUnion"): return testMultisetUnion();
        case fnv1a("--multisetIntersection"): return testMultisetIntersection();
        case fnv1a("--multisetDifference"): return testMultisetDifference();
        case fnv1a("--multisetSum"): return testMultisetSum();

        // fuzzy set tests
        case fnv1a("--fuzzySetComplement"): return testFuzzySetComplement();
        case fnv1a("--fuzzySetUnion"): return testFuzzySetUnion();
        case fnv1a("--fuzzySetIntersection"): return testFuzzySetIntersection();

        default:
            std::cerr << "Unknown test: " << argv[1];
            return -1;
    }
}
