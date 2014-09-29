remake_find_package(tulibs CONFIG)

remake_include(${TULIBS_INCLUDE_DIRS})
remake_add_directories(lib)
remake_add_directories(bin COMPONENT utils)
remake_pkg_config_generate(REQUIRES tulibs)
