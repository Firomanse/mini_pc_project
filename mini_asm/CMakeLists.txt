set(INCLUDES
  inc/interpreter.h
)
source_group(inc FILES ${INCLUDES})

set(SOURCES
  src/interpreter.cpp
)
source_group(src FILES ${SOURCES})

add_library(mini_asm_lib
  miasm.h
  miasm.cpp
  ${INCLUDES}
  ${SOURCES}
)
