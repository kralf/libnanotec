cmake_minimum_required(VERSION 2.6)

include(ReMake)

remake_project(
  libnanotec
  VERSION 0.1
  RELEASE alpha
  SUMMARY "Driver library for the Nanotec PDx-1 motor."
  AUTHOR "Ralf Kaestner"
  AUTHOR "Stefan Gaechter"
  AUTHOR "Jan Weingarten"
  CONTACT "ralf.kaestner@gmail.com"
  HOME "http://aslforge.ethz.ch/projects/libnanotec"
  LICENSE "GNU Lesser General Public License (LGPL)"
  PREFIX nanotec-
  INSTALL /usr
)

remake_doc(
  man INSTALL share
  html
)

remake_pack_deb(tulibs)
remake_pack_deb(COMPONENT dev tulibs-dev)
remake_pack_deb(ARCH all COMPONENT doc)
