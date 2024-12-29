project(App)

find_library(CHART_CORE_LIB_PATH 
    NAMES ChartCoreLib 
    HINTS ${CMAKE_BINARY_DIR}/Core 
    NO_CACHE 
    REQUIRED)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/Test/app.cc)

add_custom_target(copy_dll ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_BINARY_DIR}/Core/ChartCoreLib.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
)

add_dependencies(${PROJECT_NAME} ChartCoreLib)
add_dependencies(copy_dll ${PROJECT_NAME})

if(CHART_CORE_LIB_PATH)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${CHART_CORE_LIB_PATH})
else()
    message(FATAL_ERROR "ChartCoreLib library not found!")
endif()

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Core/include)



