add_executable(humanDetect main.cpp cam.cpp cascade.cpp rectplot.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

target_include_directories(humanDetect PUBLIC ${CMAKE_SOURCE_DIR}/include
						${CMAKE_SOURCE_DIR}/include/Eigen
						${OpenCV_INCLUDE_DIRS})

target_link_libraries(humanDetect ${OpenCV_LIBS} )
