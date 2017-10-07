#pragma once

#include <cstdint>
#include <cassert>
#include "bitboard-enums.h"

using U64 = uint64_t;

#define WIDTH 8
#define HEIGHT 8


enum boardset
{
    White,     // any white piece
    Black,     // any black piece
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King
};


class BitBoard {

private:

    U64 pieceBB[14];
    U64 emptyBB;
    U64 occupiedBB;
    int lookup[WIDTH][HEIGHT];

    BitBoard() {
        for (int i = 0; i < WIDTH; ++i)
            for (int j = 0; j < HEIGHT; ++j)
                lookup[i][j] = HEIGHT * i + j;
        emptyBB = -1;
        occupiedBB = 0;
    };
    ~BitBoard() {};


    void setPiece(U64 position, BoardSet set) {
        pieceBB[set] = pieceBB[set] || position;
        emptyBB = emptyBB || position;
        occupiedBB = occupiedBB || position;
    }

    U64 positionToBitBoard(int file, int rank) {
        assert(file < WIDTH);
        assert(rank < HEIGHT);
        return UINT64_C(1) << lookup[file][rank];
    }

public:

    bool isOccupied(int file, int rank) {
        U64 mask = positionToBitBoard(file, rank);
        return mask && occupiedBB;
    }

    BoardSet getColourAt(int file, int rank) {
        U64 mask = positionToBitBoard(file, rank);
        if (mask && occupiedBB) {
            if (mask && pieceBB[BoardSet::White])
                return BoardSet::White;
            else
                return BoardSet ::Black;
        } else {
            return nullptr;  // empty square
        }
    }

    BoardSet getPieceTypeAt(int file, int rank) {
        U64 mask = positionToBitBoard(file, rank);
        if (mask && occupiedBB) {
            if (mask && pieceBB[BoardSet::Pawn])
                return BoardSet::Pawn;
            else if (mask && pieceBB[BoardSet::Rook])
                return BoardSet::Rook;
            else if (mask && pieceBB[BoardSet::Knight])
                return BoardSet::Knight;
            else if (mask && pieceBB[BoardSet::Bishop])
                return BoardSet::Bishop;
            else if (mask && pieceBB[BoardSet::Queen])
                return BoardSet::Queen;
            else if (mask && pieceBB[BoardSet::King])
                return BoardSet::King;
        } else {
            return nullptr;  // empty square
        }
    }
};

