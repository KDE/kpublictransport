# SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

gradle_add_aar(publictransport_onboard_aar BUILDFILE ${CMAKE_CURRENT_SOURCE_DIR}/build.gradle NAME KPublicTransportOnboard)
gradle_install_aar(publictransport_onboard_aar DESTINATION jar)

install(FILES KPublicTransportOnboard-android-dependencies.xml DESTINATION ${KDE_INSTALL_LIBDIR} RENAME KPublicTransportOnboard_${CMAKE_ANDROID_ARCH_ABI}-android-dependencies.xml)
