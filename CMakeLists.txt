cmake_minimum_required(VERSION 3.5)

project(ldm_emulator LANGUAGES C)

# Src directory
add_subdirectory(src)

# Unit test module
add_subdirectory(unit_test)

add_executable(ldm_emulator main.c)
target_link_libraries(ldm_emulator)

# Enable testing
enable_testing()
add_test(NAME unit_test COMMAND unit_test)
