
find_path(
        asio_INCLUDE_DIR
        NAMES asio.hpp
)
if (asio_INCLUDE_DIR-NOTFOUND)
    message(FATAL_ERROR "Could not find asio library")
    set(asio_FOUND FALSE)
else ()
    set(asio_FOUND TRUE)
    set(ASIO_INCLUDE_DIR ${asio_INCLUDE_DIR})
endif ()

if (asio_FOUND)
    if (asio_INCLUDE_DIR AND EXISTS "${asio_INCLUDE_DIR}/asio/version.hpp")
        file(STRINGS "${asio_INCLUDE_DIR}/asio/version.hpp" ASIO_VERSION_RAW REGEX "^#define ASIO_VERSION[ \t]+([0-9]+) // ([^\n\r]+)$")
        if (ASIO_VERSION_RAW)
            string(REGEX REPLACE "^#define ASIO_VERSION[ \t]+([0-9]+) // ([^\n\r]+)$" "\\1" ASIO_VERSION "${ASIO_VERSION_RAW}")
            message(STATUS "[==> Find ASIO: Asio version: ${ASIO_VERSION} <==]")
        endif ()
    endif ()

    include(FindPackageHandleStandardArgs)
    find_package_handle_standard_args(asio
            REQUIRED_VARS asio_INCLUDE_DIR)
    if (NOT TARGET asio::asio)
        set(asio_INCLUDE_DIRS ${asio_INCLUDE_DIR})
        add_library(asio::asio INTERFACE IMPORTED)
        set_target_properties(asio::asio PROPERTIES
                INTERFACE_INCLUDE_DIRECTORIES ${asio_INCLUDE_DIR}
                INTERFACE_COMPILE_DEFINITIONS ASIO_STANDALONE)
        mark_as_advanced(asio_INCLUDE_DIR)
    endif ()
endif ()