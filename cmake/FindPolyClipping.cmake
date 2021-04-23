# SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

find_package(PkgConfig QUIET)
pkg_check_modules(PolyClipping polyclipping QUIET)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(PolyClipping
    FOUND_VAR
        PolyClipping_FOUND
    REQUIRED_VARS
        PolyClipping_LIBRARIES
        PolyClipping_INCLUDE_DIRS
    VERSION_VAR
        PolyClipping_VERSION
)

if (PolyClipping_FOUND AND NOT TARGET PolyClipping::PolyClipping)
    add_library(PolyClipping::PolyClipping UNKNOWN IMPORTED)
    set_target_properties(PolyClipping::PolyClipping PROPERTIES
        IMPORTED_LOCATION "${PolyClipping_LINK_LIBRARIES}"
        INTERFACE_COMPILE_OPTIONS "${PolyClipping_CFLAGS}"
        INTERFACE_INCLUDE_DIRECTORIES "${PolyClipping_INCLUDE_DIRS}"
    )
endif()

mark_as_advanced(PolyClipping_LIBRARIES PolyClipping_INCLUDE_DIRS PolyClipping_VERSION)

include(FeatureSummary)
set_package_properties(PolyClipping PROPERTIES
    DESCRIPTION "A library for clipping and offsetting lines and polygons"
    URL "http://www.angusj.com/delphi/clipper.php"
)
