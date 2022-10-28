#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SYCL_BLAS::sycl_blas" for configuration "Debug"
set_property(TARGET SYCL_BLAS::sycl_blas APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SYCL_BLAS::sycl_blas PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libsycl_blas.so.0.1.0"
  IMPORTED_SONAME_DEBUG "libsycl_blas.so.0.1.0"
  )

list(APPEND _cmake_import_check_targets SYCL_BLAS::sycl_blas )
list(APPEND _cmake_import_check_files_for_SYCL_BLAS::sycl_blas "${_IMPORT_PREFIX}/lib/libsycl_blas.so.0.1.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
