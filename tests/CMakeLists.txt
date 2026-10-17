include(CTest)

add_executable(Test test.cpp ${CMAKE_SOURCE_DIR}/src/CheckSet.cpp)

set(TESTS
        # Set Tests
        setComplement
        setUnion
        setIntersection
        setDifference
        setSymmetricDifference

        # Multiset tests
        multisetUnion
        multisetIntersection
        multisetDifference
        multisetSum
)

foreach (TEST ${TESTS})
    add_test(NAME Test_${TEST} COMMAND Test --${TEST})
endforeach ()
