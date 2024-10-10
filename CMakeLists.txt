cmake_minimum_required(VERSION 3.29)
project(BLACKJACK_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(Diagramas)
include_directories("avance codigo")
include_directories(prueba)
include_directories(PseudoCodigo)

add_executable(BLACKJACK_cpp
    .idea/.gitignore
    .idea/BLACKJACK.cpp.iml
    .idea/dbnavigator.xml
    .idea/discord.xml
    .idea/editor.xml
    .idea/material_theme_project_new.xml
    .idea/misc.xml
    .idea/modules.xml
    .idea/vcs.xml
    .idea/workspace.xml
    "Diagramas/Diagrama de flujo BlackJack.jpg"
    "Diagramas/Diagramas Proyecto.drawio"
    Diagramas/machine_turn.png
    "Diagramas/PLAYER_TURN( ).jpg"
    "Diagramas/Subproceso CARD.jpg"
    "avance codigo/main.cpp"
    prueba/dksaj
    PseudoCodigo/proyecto.txt
    .gitignore
    "face of the croupier.png"
    LICENSE
    README.md
        "avance codigo/main.cpp")
