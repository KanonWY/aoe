find_package(Threads REQUIRED)

set(cur_root ${CMAKE_CURRENT_SOURCE_DIR}/test)

file(
        GLOB             cpp_names
        LIST_DIRECTORIES true
        RELATIVE         ${cur_root}
        ${cur_root}/*
)

foreach(cpp_name ${cpp_names})
    get_filename_component(pure_name ${cpp_name} NAME_WE)
    add_executable(${pure_name})
    target_sources(${pure_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/test/${cpp_name})
    target_link_libraries(${pure_name} PRIVATE Threads::Threads)
endforeach()