cmake_minimum_required(VERSION 3.24)
project(Projet C)

set(CMAKE_C_STANDARD 11)

# region SDL2 generic configuration
set(SDL2_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(SDL2_LIBRARIES_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/x64")
    set(SDL2_DYNAMIC_LIB_DIR "${CMAKE_CURRENT_LIST_DIR}/bin/x64")
else ()
    set(SDL2_LIBRARIES_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/x86")
    set(SDL2_DYNAMIC_LIB_DIR "${CMAKE_CURRENT_LIST_DIR}/bin/x86")
endif ()

set(SDL2_LIBRARIES SDL2main SDL2)
set(SDL2_DYNAMIC_LIB "SDL2.dll")
string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
#endregion
include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIBRARIES_DIR})
link_libraries(mingw32 ${SDL2_LIBRARIES})
#
add_executable(Projet main.c fenetres_Menus.c Fenetres_Menus.h fonctions_party.c party.h Event_party.c Event_party.h sauv.c sauv.h Victoire.c Victoire.h Coord.c Coord.h )

# Copy the right DLL into the cmake-build-debug folder
add_custom_command(TARGET Projet
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${SDL2_DYNAMIC_LIB_DIR}/${SDL2_DYNAMIC_LIB}" ${CMAKE_BINARY_DIR}/.
        )
