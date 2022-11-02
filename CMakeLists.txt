cmake_minimum_required(VERSION 3.1...3.24)

project(
    Feather-Engine
    VERSION 1.0
    LANGUAGES CXX
)

set(SOURCES
    feather/debug.cpp
    feather/entity.cpp
    feather/input.cpp
    feather/main.cpp
    feather/rigidentity.cpp
    feather/serial.cpp
    feather/sound.cpp
    feather/tag.cpp
    feather/text.cpp
    feather/timer.cpp
    feather/transform.cpp
    feather/util.cpp
    feather/vector.cpp
    feather/view.cpp
    game.cpp
)

find_library(LIB_IMAGE SDL2_image ./lib/Unix/lib_image)
find_library(LIB_MIXER SDL2_mixer ./lib/Unix/lib_mixer)
find_library(LIB_TTF SDL2_ttf ./lib/Unix/lib_ttf)

find_path(LIB_INCLUDES SDL_image.h ./include/Unix/SDL2)
message(${LIB_INCLUDES})
include_directories(${LIB_INCLUDES})

add_executable(game 
    ${SOURCES}
)

target_include_directories(game
    PRIVATE
        ${PROJECT_SOURCE_DIR}/feather
)

target_link_libraries(game
    SDL2
    ${LIB_IMAGE}
    ${LIB_MIXER}
    ${LIB_TTF}
)