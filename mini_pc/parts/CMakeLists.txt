set(INCLUDES
  inc/bus.h
  inc/chipset.h
  inc/cpu.h
  inc/gpu.h
  inc/ram.h
  inc/rom.h
  inc/rom_bios.h
)
source_group(inc FILES ${INCLUDES})

set(SOURCES
  src/bus.cpp
  src/chipset.cpp
  src/cpu.cpp
  src/gpu.cpp
  src/ram.cpp
  src/rom.cpp
  src/rom_bios.cpp
)
source_group(src FILES ${SOURCES})

add_library(mini_pc_parts
  ${INCLUDES}
  ${SOURCES}
)

target_link_libraries(mini_pc_parts
  mini_pc_base
)
