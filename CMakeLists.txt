cmake_minimum_required(VERSION 3.1)

set(CXX_DISABLE_WERROR 1)
set(CMAKE_CXX_STANDARD 11)

set(PROJECT_NAME Test)
set(PROJECT_DESCRIPTION "Test")
set(PROJECT_URL "")

project(${PROJECT_NAME} CXX)

# Check if the project is built inside mc_rtc
if(NOT TARGET mc_rtc::mc_control)
  find_package(mc_rtc REQUIRED)
endif()

add_subdirectory(src)

set(AROBASE "@")
configure_file(etc/Test.in.yaml "${CMAKE_CURRENT_BINARY_DIR}/etc/Test.yaml")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/etc/Test.yaml" DESTINATION "${MC_CONTROLLER_RUNTIME_INSTALL_PREFIX}/etc")

install(FILES etc/hrp4.yaml DESTINATION ${MC_CONTROLLER_RUNTIME_INSTALL_PREFIX}/Test/)
install(FILES etc/jvrc1.yaml DESTINATION ${MC_CONTROLLER_RUNTIME_INSTALL_PREFIX}/Test/)
