cmake_minimum_required(VERSION 3.12)
project(Minesweeper)

set(CMAKE_CXX_STANDARD 11)

# SFML'in yüklü olduğu yolu belirtin
set(SFML_DIR "SFML'in/Yüklü/Olduğu/Dizin")

# Kaynak dosyalarını ekleyin
set(SOURCES
    src/main.cpp
    src/game.cpp
    src/board.cpp
    src/MSBoardTextView.cpp
    src/MSTextController.cpp
    src/MSSFMLView.cpp
    src/MSBoardView.cpp
    src?sfmlMain.cpp
)

# İlgili hedefi oluşturun
add_executable(Minesweeper ${SOURCES})

# SFML kütüphanesini ekleyin
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Minesweeper ${SFML_LIBRARIES})
else()
    message(FATAL_ERROR "SFML not found")
endif()