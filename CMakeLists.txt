project(moteur_onea)
cmake_minimum_required(VERSION 2.8)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)

aux_source_directory(. SRC_LIST)
aux_source_directory(src SRC_LIST)
aux_source_directory(src/Physique SRC_LIST)
aux_source_directory(src/Carte SRC_LIST)
aux_source_directory(src/Animation SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

include_directories(include)
link_directories(lib)
target_link_libraries(${PROJECT_NAME}
    sfml-graphics sfml-window sfml-system tinyxml)
