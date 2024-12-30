project(ChartCoreLib)

#set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(src_dir ${CMAKE_SOURCE_DIR}/Core/src)
set(header_dir ${CMAKE_SOURCE_DIR}/Core/include)
set(header_files 
    ${header_dir}/bindings.hh
    # Render
    ${header_dir}/IRenderer.hh
    ${header_dir}/D2dRenderer.hh
    ${header_dir}/GdiRenderer.hh
    ${header_dir}/RendererContext.hh)
    
set(src_files ${src_dir}/bindings.cc)

add_library(${PROJECT_NAME} SHARED ${src_files})

target_link_libraries(${PROJECT_NAME} PRIVATE gdiplus.lib)

target_include_directories(${PROJECT_NAME} PUBLIC ${header_dir})