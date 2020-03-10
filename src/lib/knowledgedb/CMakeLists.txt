add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/linemetadata_data.cpp
    COMMAND
        line-data-generator -o ${CMAKE_CURRENT_SOURCE_DIR}/linemetadata_data.cpp
    DEPENDS
        line-data-generator
)
add_custom_target(rebuild-knowledgedb DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/linemetadata_data.cpp)
