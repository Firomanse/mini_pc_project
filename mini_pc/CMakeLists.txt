add_subdirectory(base)
add_subdirectory(parts)

add_library(mini_pc_lib
  computer.h
  computer.cpp
)

target_link_libraries(mini_pc_lib PUBLIC
  mini_pc_base
  mini_pc_parts
)
