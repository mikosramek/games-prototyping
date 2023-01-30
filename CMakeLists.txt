cmake_minimum_required(VERSION 3.21)
project(SFMLPrototypes LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(SFMLPrototypes
 src/main.cpp 
 src/launcher/launcher.cpp 
 src/shared/window.cpp
)
target_link_libraries(SFMLPrototypes PRIVATE sfml-graphics)
target_compile_features(SFMLPrototypes PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET SFMLPrototypes POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:SFMLPrototypes> $<TARGET_FILE_DIR:SFMLPrototypes> COMMAND_EXPAND_LISTS)
endif()

file(COPY src/resources DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} resources)

install(TARGETS SFMLPrototypes)
