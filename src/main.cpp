#include <cassert>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <vector>

class Set {
    static constexpr std::uint64_t size_factor = sizeof(std::uint64_t) * 8;

    std::vector<std::uint64_t> set;
    std::size_t size = 0;

public:
    Set(const std::initializer_list<bool> initializer) {
        std::uint64_t* current = nullptr;
        for (const bool value : initializer) {
            const std::uint64_t position = size % size_factor;
            if (position == 0) current = &set.emplace_back();
            *current |= static_cast<std::uint64_t>(value) << position;
            ++size;
        }
    }

    explicit Set(const std::size_t size) : size(size) {
        for (std::size_t i = 0; i < size / size_factor + static_cast<std::uint64_t>(size % size_factor > 0); ++i)
            set.emplace_back();
    }

    Set operator!() const noexcept {
        Set result(size);
        for (std::size_t i = 0; i < set.size(); ++i)
            result.set.at(i) = ~set.at(i);
        return result;
    }

    Set operator&(const Set& other) const noexcept {
        assert(set.size() == other.set.size());
        Set result(size);
        for (std::size_t i = 0; i < set.size(); ++i)
            result.set.at(i) = set.at(i) & other.set.at(i);
        return result;
    }

    Set operator|(const Set& other) const noexcept {
        assert(set.size() == other.set.size());
        Set result(size);
        for (std::size_t i = 0; i < set.size(); ++i)
            result.set.at(i) = set.at(i) | other.set.at(i);
        return result;
    }

    Set operator-(const Set& other) const noexcept {
        assert(set.size() == other.set.size());
        Set result(size);
        for (std::size_t i = 0; i < set.size(); ++i)
            result.set.at(i) = set.at(i) & ~other.set.at(i);
        return result;
    }

    Set operator^(const Set& other) const noexcept {
        assert(set.size() == other.set.size());
        Set result(size);
        for (std::size_t i = 0; i < set.size(); ++i)
            result.set.at(i) = set.at(i) ^ other.set.at(i);
        return result;
    }

    bool operator[](std::size_t index) const {
        const std::uint64_t position = index % size_factor;
        index /= size_factor;
        return static_cast<bool>(set.at(index) & (1U << position));
    }

    [[nodiscard]] std::size_t length() const noexcept {
        return size;
    }
};

class MultiSet {
    std::vector<std::uint64_t> set;

public:
    MultiSet(const std::initializer_list<std::uint64_t> list) : set(list) {}
    explicit MultiSet(const std::size_t size) : set(size) {}

    MultiSet operator|(const MultiSet& other) const noexcept {
        assert(set.size() == other.set.size());
        MultiSet result(set.size());
        for (std::size_t i = 0; i < set.size(); ++i)
            result.set.at(i) = std::max(set.at(i), other.set.at(i));
        return result;
    }

    MultiSet operator&(const MultiSet& other) const noexcept {
        assert(set.size() == other.set.size());
        MultiSet result(set.size());
        for (std::size_t i = 0; i < set.size(); ++i)
            result.set.at(i) = std::min(set.at(i), other.set.at(i));
        return result;
    }

    MultiSet operator-(const MultiSet& other) const noexcept {
        assert(set.size() == other.set.size());
        MultiSet result(set.size());
        for (std::size_t i = 0; i < set.size(); ++i)
            result.set.at(i) = set.at(i) > other.set.at(i) ? set.at(i) - other.set.at(i) : 0;
        return result;
    }

    MultiSet operator+(const MultiSet& other) const noexcept {
        assert(set.size() == other.set.size());
        MultiSet result(set.size());
        for (std::size_t i = 0; i < set.size(); ++i)
            result.set.at(i) = set.at(i) + other.set.at(i);
        return result;
    }

    std::uint64_t operator[](const std::size_t index) const {
        return set.at(index);
    }

    [[nodiscard]] std::size_t length() const noexcept {
        return set.size();
    }
};

static std::ostream& operator <<(std::ostream& stream, const Set& set) {
    stream << "{ ";
    for (std::size_t i = 0; i < set.length(); ++i)
        stream << set[i] << " ";
    stream << "}";
    return stream;
}

static std::ostream& operator <<(std::ostream& stream, const MultiSet& set) {
    stream << "{ ";
    for (std::size_t i = 0; i < set.length(); ++i)
        stream << set[i] << " ";
    stream << "}";
    return stream;
}

int main() {
    const Set setA{false, true, false, true};
    const Set setB{false, false, true, true};
    std::cout << "inverse of " << setA << " : " << !setA << "\n"
    << "inverse of " << setB << ": " << !setB << "\n"
    << "union of " << setA << " and " << setB << " : " << (setA | setB) << "\n"
    << "intersection of " << setA << " and " << setB << " : " << (setA & setB) << "\n"
    << "difference of " << setA << " and " << setB << " : " << (setA - setB) << "\n"
    << "symmetric difference of " << setA << " and " << setB << " : " << (setA ^ setB) << "\n"


    << "\n\nMulti-set Operations\n\n\n";
    const MultiSet mSetA{1, 2, 3, 4};
    const MultiSet mSetB{0, 6, 5, 6};
    std::cout << "union of " << mSetA << " and " << mSetB << " : " << (mSetA | mSetB) << "\n"
    << "intersection of " << mSetA << " and " << mSetB << " : " << (mSetA & mSetB) << "\n"
    << "difference of " << mSetA << " and " << mSetB << " : " << (mSetA - mSetB) << "\n"
    << "symmetric difference of " << mSetA << " and " << mSetB << " : " << (mSetA + mSetB) << "\n";
}
