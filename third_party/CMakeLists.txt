set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)
add_subdirectory(fmt)

set(BUILD_SHARED_LIBS ON CACHE BOOL "Build shared libraries" FORCE)
add_subdirectory(DPP)
