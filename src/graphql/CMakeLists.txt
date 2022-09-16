# SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_library(KGraphQL STATIC
    kgraphql.cpp
    kgraphqlminimizer.cpp
    kgraphql.h
    kgraphqlminimizer_p.h
)
target_link_libraries(KGraphQL PUBLIC Qt::Network)
set_target_properties(KGraphQL PROPERTIES POSITION_INDEPENDENT_CODE ON)

if (NOT BUILD_SHARED_LIBS)
    install(TARGETS KGraphQL EXPORT KPublicTransportTargets ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
endif()
