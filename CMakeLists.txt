cmake_minimum_required(VERSION 3.11)
project(FlappyBirdVultureChase C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)
find_package(raylib QUIET)

if (NOT raylib_FOUND)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
    )
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(raylib)
endif()

add_executable(flappy
    src/main.c
    src/engine/bird.c
    src/engine/time.c
    src/engine/collision.c
    src/engine/game.c
    src/gameplay/pipe.c
    src/gameplay/coin.c
    src/gameplay/safezone.c
    src/gameplay/vulture.c
    src/renderer/render.c
    src/score.c
)

target_include_directories(flappy PRIVATE include)
target_link_libraries(flappy raylib)

if (WIN32)
    target_link_libraries(flappy winmm gdi32 opengl32)
elseif (APPLE)
    target_link_libraries(flappy "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
elseif (UNIX)
    target_link_libraries(flappy GL m pthread dl rt X11)
endif()

set_target_properties(flappy PROPERTIES OUTPUT_NAME "flappy")