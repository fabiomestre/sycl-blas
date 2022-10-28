#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SYCL_BLAS::sycl_blas" for configuration ""
set_property(TARGET SYCL_BLAS::sycl_blas APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SYCL_BLAS::sycl_blas PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libsycl_blas.so.0.1.0"
  IMPORTED_SONAME_NOCONFIG "libsycl_blas.so.0.1.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS SYCL_BLAS::sycl_blas )
list(APPEND _IMPORT_CHECK_FILES_FOR_SYCL_BLAS::sycl_blas "${_IMPORT_PREFIX}/lib/libsycl_blas.so.0.1.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
