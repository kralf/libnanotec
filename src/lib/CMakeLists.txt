remake_find_library(
  tulibs-serial serial.h
  PACKAGE tulibs
)

remake_add_library(
  nanotec PREFIX OFF
  LINK ${TULIBS_SERIAL_LIBRARY}  
)
remake_add_headers()
