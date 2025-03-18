cmake_minimum_required(VERSION 3.13)

set(LOCAL_PROJECT_NAME "mini_pc_project")

project(${LOCAL_PROJECT_NAME}
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(mini_pc)
add_subdirectory(mini_asm)

add_executable(${LOCAL_PROJECT_NAME}
  main.cpp
)

target_link_libraries(${LOCAL_PROJECT_NAME} PUBLIC
  mini_pc_lib
  mini_asm_lib
)

install(TARGETS ${LOCAL_PROJECT_NAME}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
