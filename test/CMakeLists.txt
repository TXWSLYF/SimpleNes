project (my_simple_nes_test)

add_executable(CPU_test CPU_test.cpp)

target_link_libraries(CPU_test
    my_simple_nes_src
)