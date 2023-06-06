include_directories(${chess_SOURCE_DIR}/main/include)
set(EXECUTABLE_OUTPUT_PATH ${chess_SOURCE_DIR}/bin)
add_executable(chess main.cpp pieces.cpp bitboard.cpp)