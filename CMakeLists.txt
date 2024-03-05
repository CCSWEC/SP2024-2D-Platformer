cmake_minimum_required(VERSION 3.16)
project(Platformer2D LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Platformer2D
    src/main.cpp
    src/player.cpp
    src/components/Ground.cpp
    src/components/Player.cpp
    src/scene/Component.cpp
    src/scene/Entity.cpp
    src/scene/components/Transform.cpp
    src/scene/components/renderables/ShapeRenderable.cpp
    src/scene/renderers/ShapeRenderer.cpp
)
target_link_libraries(Platformer2D PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_features(Platformer2D PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET Platformer2D
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Platformer2D>
        VERBATIM)
endif()

install(TARGETS Platformer2D)
