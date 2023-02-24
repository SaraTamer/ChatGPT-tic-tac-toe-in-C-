cmake_minimum_required(VERSION 3.21)
project(ChatGPT)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChatGPT main.cpp Game.h Player.h Board.h XOGame.h XOBoard.h XOPlayer.h)
