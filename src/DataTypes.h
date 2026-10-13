/*
 *    Team name: Coding Cadets
 *    Team members: [Brayden Graham, Todd Dharni, Thaddeus Schelp]
 *    Course and section: CS 2430-002
 *    Project name: Programming Project 2 – Fall 2026
 *    Primary author: Brayden Graham
 */

#pragma once

#include <algorithm>
#include <initializer_list>
#include <vector>

struct Set
{
    std::vector<uint32_t> contents{};

    Set(const std::initializer_list<uint32_t> list) : contents(list) {}
    explicit Set(std::vector<uint32_t>&& vec) : contents(vec) {}

    [[nodiscard]] uint32_t size() const { return contents.size(); }

    static uint32_t maxSize(const Set& A, const Set& B)
    {
        return std::max(A.contents.size(), B.contents.size());
    }
};
