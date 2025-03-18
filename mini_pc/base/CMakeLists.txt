set(INCLUDES
  inc/clock.h
  inc/cluster.h
  inc/cluster_set.h
  inc/component.h
  inc/component_base.h
  inc/preset_loader.h
  inc/read_only_component.h
  inc/write_only_component.h
)
source_group(inc FILES ${INCLUDES})

set(SOURCES
  src/clock.cpp
  src/cluster.cpp
  src/cluster_set.cpp
  src/component.cpp
  src/component_base.cpp
  src/preset_loader.cpp
  src/read_only_component.cpp
  src/write_only_component.cpp
)
source_group(src FILES ${SOURCES})

add_library(mini_pc_base
  ${INCLUDES}
  ${SOURCES}
)
