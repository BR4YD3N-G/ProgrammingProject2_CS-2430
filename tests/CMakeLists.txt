include(CTest)

add_executable(Test
  test.cpp
  ${CMAKE_SOURCE_DIR}/src/setOperations/RepresentationHelper.cpp
  ${CMAKE_SOURCE_DIR}/src/setOperations/Sets.cpp
  ${CMAKE_SOURCE_DIR}/src/setOperations/MultiSets.cpp
  ${CMAKE_SOURCE_DIR}/src/setOperations/FuzzySets.cpp
)

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

        # Fuzzy set tests
        fuzzySetComplement
        fuzzySetUnion
        fuzzySetIntersection
)

foreach (TEST ${TESTS})
  add_test(NAME Test_${TEST} COMMAND Test --${TEST})
endforeach ()
