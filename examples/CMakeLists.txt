# ~~~
# CMake configuration for C++ examples
# ~~~

if(NOT TARGET utils::utils)
  loco_message("Examples require the [utils::utils] target to be defined"
               LOG_LEVEL WARNING)
  return()
endif()

# -------------------------------------
# List of all examples to be built
set(UTILS_EXAMPLES_LIST
    ${CMAKE_CURRENT_SOURCE_DIR}/example_logger_console.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/example_logger_file.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/example_path_handling.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/example_perlin_noise.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/example_profiler_external_chrome.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/example_smart_pointers_macro.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/example_raii_helper_macros.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/example_timing.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/example_obj_loader.cpp)

# -------------------------------------
# Create all the examples targets
foreach(example_filepath IN LISTS UTILS_EXAMPLES_LIST)
  loco_setup_single_file_example(${example_filepath} TARGET_DEPENDENCIES
                                 utils::utils)
endforeach()
