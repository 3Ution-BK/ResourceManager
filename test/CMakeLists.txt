macro(add_unittest test_name)
    set(UNITTEST_NAME ${test_name})

    include(${${PROJECT_NAME}_MODULE_DIR}/CompilerOptions.cmake)

    add_executable(${UNITTEST_NAME} ${ARGN})

    target_link_libraries(${UNITTEST_NAME}
        PUBLIC
            ${PROJECT_NAME}
            gtest
            gtest_main
    )

    target_include_directories(${UNITTEST_NAME}
        PUBLIC
            ${${PROJECT_NAME}_INCLUDE_DIR}
    )

    target_compile_features(${UNITTEST_NAME}
        PUBLIC
            cxx_std_11
    )

    set_target_properties(${LIBRARY_NAME}
        PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/test/$<CONFIG>
            LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/test/$<CONFIG>
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test/$<CONFIG>
            TIMEOUT 5
    )

    target_compile_options(${UNITTEST_NAME}
        PUBLIC
            "$<$<CONFIG:DEBUG>:${${PROJECT_NAME}_CXX_FLAGS_DEBUG}>"
            "$<$<CONFIG:RELEASE>:${${PROJECT_NAME}_CXX_FLAGS_RELEASE}>"
    )
endmacro(add_unittest)

include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY
        https://github.com/google/googletest.git
    GIT_TAG
        release-1.10.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_unittest(BasicResourceTest BasicResourceTest/main.cpp)
add_unittest(DuplicateResourceTest DuplicateResourceTest/main.cpp)
