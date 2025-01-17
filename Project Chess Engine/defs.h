#ifndef DEFS_H
#define DEFS_H

// Define a type alias for an unsigned long long
typedef unsigned long long U64;

// Macro definitions for the program
#define NAME "Vice 1.0"
#define BRD_SQ_NUM 120

// Enumeration for chess pieces
enum {
    EMPTY,   // No piece
    wP,      // White Pawn
    wN,      // White Knight
    wB,      // White Bishop
    wR,      // White Rook
    wQ,      // White Queen
    wK,      // White King
    bP,      // Black Pawn
    bN,      // Black Knight
    bB,      // Black Bishop
    bR,      // Black Rook
    bQ,      // Black Queen
    bK       // Black King
};

// Enumeration for chessboard files (columns)
enum {
    FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE
};

// Enumeration for chessboard ranks (rows)
enum {
    RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE
};

// Enumeration for player sides
enum {
    WHITE, BLACK, BOTH
};

// Enumeration for chessboard squares
enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8,
    NO_SQ
};

// Enumeration for boolean values
enum {
    FALSE, TRUE
};

#endif // DEFS_H
