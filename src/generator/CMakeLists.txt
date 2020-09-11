# SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_executable(line-data-generator
    generator.cpp
    indexeddatatable.cpp
    lineinfo.cpp
)
target_link_libraries(line-data-generator KOSM KWikidata Qt5::Gui)
