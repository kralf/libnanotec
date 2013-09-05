cmake_minimum_required(VERSION 2.6)

include(ReMake)

remake_project(
  libnanotec
  VERSION 0.1
  RELEASE alpha
  SUMMARY "Driver library for the Nanotec PDx-1 stepper motor."
  AUTHOR "Ralf Kaestner"
  AUTHOR "Stefan Gaechter"
  AUTHOR "Jan Weingarten"
  CONTACT "ralf.kaestner@gmail.com"
  HOME "http://github.com/kralf/libnanotec"
  LICENSE "GNU Lesser General Public License (LGPL)"
  PREFIX nanotec-
  INSTALL /usr
)

remake_doc(
  man INSTALL share
  html
)

remake_pack_deb(
  DEPENDS tulibs
)
remake_pack_deb(
  COMPONENT utils
  DESCRIPTION "utilities"
  DEPENDS libnanotec
)
remake_pack_deb(
  COMPONENT dev
  DESCRIPTION "development headers"
  DEPENDS libnanotec tulibs-dev
)
remake_pack_deb(
  ARCH all
  COMPONENT doc
  DESCRIPTION "documentation"
)

remake_distribute_deb(
  DISTRIBUTION lucid
  SECTION libs
  UPLOAD ppa:kralf/asl
  DEPENDS tulibs-dev remake pkg-config doxygen
  PASS CMAKE_BUILD_TYPE LIBNANOTEC_GIT_REVISION
  EXCLUDE "vendor"
)
remake_distribute_deb(
  DISTRIBUTION precise
  SECTION libs
  UPLOAD ppa:kralf/asl
  DEPENDS tulibs-dev remake pkg-config doxygen
  PASS CMAKE_BUILD_TYPE LIBNANOTEC_GIT_REVISION
  EXCLUDE "vendor"
)
