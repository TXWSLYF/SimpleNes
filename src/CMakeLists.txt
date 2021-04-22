project (my_simple_nes_src)

add_library(${PROJECT_NAME} CPU.cpp)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)