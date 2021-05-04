#ifndef PUZZLELIST_H
#define PUZZLELIST_H

#include "puzzle.h"

class PuzzleList
{
public:
    QVector<Puzzle> puzzles;

    PuzzleList();
    ~PuzzleList();

    Puzzle getPuzzle(QString theme, int size);
    void addPuzzle(Puzzle puzzle);
};

#endif // PUZZLELIST_H
