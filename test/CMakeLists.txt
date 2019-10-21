set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    camtest.cpp
    cascadetest.cpp
    rectplottest.cpp 
   ${CMAKE_SOURCE_DIR}/app/cam.cpp 
   ${CMAKE_SOURCE_DIR}/app/cascade.cpp
   ${CMAKE_SOURCE_DIR}/app/rectplot.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})
target_link_libraries(cpp-test PUBLIC gtest
				${OpenCV_LIBS})
