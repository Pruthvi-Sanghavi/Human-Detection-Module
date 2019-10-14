add_executable(humanDetect main.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

target_include_directories(humanDetect PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(humanDetect ${OpenCV_LIBS} )
