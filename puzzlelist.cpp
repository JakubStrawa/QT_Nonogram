#include "puzzlelist.h"

PuzzleList::PuzzleList()
{
    //pig 5x5
    Puzzle puzzle1(5);
    puzzle1.setTheme("Animals");
    QVector<int> sol = {1,1,1,1,0,
                           0,1,1,1,1,
                           1,1,0,1,0,
                           1,1,1,1,1,
                           1,1,1,1,0};
    puzzle1.addSolution(sol);
    QVector<QString> rows = {"4","4","2 1","5","4"};
    QVector<QString> columns = {"1\n3","5","2\n2","5","1\n1"};
    puzzle1.addRowDescription(rows);
    puzzle1.addColumnDescription(columns);
    puzzles.append(puzzle1);
    sol.clear();
    rows.clear();
    columns.clear();


    //rose 5x5
    Puzzle puzzle2(5);
    puzzle2.setTheme("Items");
    sol = {1,1,1,1,1,
           1,1,0,1,1,
           0,1,1,1,0,
           0,0,1,0,0,
           1,1,1,1,1};
    puzzle2.addSolution(sol);
    rows = {"5","2 2","3","1","5"};
    columns = {"2\n1","3\n1","1\n3","3\n1","2\n1"};
    puzzle2.addRowDescription(rows);
    puzzle2.addColumnDescription(columns);
    puzzles.append(puzzle2);
    sol.clear();
    rows.clear();
    columns.clear();


    //bike 5x5
    Puzzle puzzle3(5);
    puzzle3.setTheme("Vehicles");
    sol = {1,1,0,0,0,
           0,1,0,1,1,
           0,0,1,0,0,
           1,1,0,1,1,
           1,1,0,1,1};
    puzzle3.addSolution(sol);
    rows = {"2","1 2","1","2 2","2 2"};
    columns = {"1\n2","2\n2","1","1\n2","1\n2"};
    puzzle3.addRowDescription(rows);
    puzzle3.addColumnDescription(columns);
    puzzles.append(puzzle3);
    sol.clear();
    rows.clear();
    columns.clear();


    //panda 10x10
    Puzzle puzzle4(10);
    puzzle4.setTheme("Animals");
    sol = {1,1,1,1,0,0,1,1,0,0,
           0,1,0,1,0,0,0,0,0,0,
           1,0,0,1,1,0,0,0,0,1,
           1,1,0,1,1,1,0,1,0,1,
           1,1,0,1,1,0,1,0,0,1,
           1,1,0,1,0,0,0,0,0,0,
           1,1,0,0,0,1,1,1,1,0,
           1,1,0,0,0,0,1,1,0,0,
           1,0,0,0,0,0,1,0,0,0,
           1,0,0,0,0,0,0,0,0,0};
    puzzle4.addSolution(sol);
    rows = {"4 2","1 1","1 2 1","2 3 1 1","2 2 1 1","2 1","2 4","2 2","1 1","1"};
    columns = {"1\n8","2\n5","1","6","3","1\n1","1\n1\n3","1\n1\n2","1","3"};
    puzzle4.addRowDescription(rows);
    puzzle4.addColumnDescription(columns);
    puzzles.append(puzzle4);
    sol.clear();
    rows.clear();
    columns.clear();


    //question mark 10x10
    Puzzle puzzle5(10);
    puzzle5.setTheme("Items");
    sol = {0,0,1,1,1,1,1,1,0,0,
           0,1,1,0,0,0,0,1,1,0,
           0,1,1,0,0,0,0,1,1,0,
           0,0,0,0,0,0,0,1,1,0,
           0,0,0,0,0,0,1,1,1,0,
           0,0,0,0,1,1,1,1,0,0,
           0,0,0,0,1,1,0,0,0,0,
           0,0,0,0,0,0,0,0,0,0,
           0,0,0,0,1,1,0,0,0,0,
           0,0,0,0,1,1,0,0,0,0};
    puzzle5.addSolution(sol);
    rows = {"6","2 2","2 2","2","3","4","2","0","2","2"};
    columns = {"0","2","3","1","1\n2\n2","1\n2\n2","1\n2","6","4","0"};
    puzzle5.addRowDescription(rows);
    puzzle5.addColumnDescription(columns);
    puzzles.append(puzzle5);
    sol.clear();
    rows.clear();
    columns.clear();


    //helicopter 10x10
    Puzzle puzzle6(10);
    puzzle6.setTheme("Vehicles");
    sol = {0,0,0,0,0,1,0,0,0,0,
           0,0,1,1,1,1,1,1,1,0,
           0,0,0,0,0,1,0,0,0,0,
           0,0,0,0,0,1,0,0,0,0,
           0,0,0,0,1,1,1,0,0,0,
           0,0,0,0,1,0,0,1,0,0,
           0,0,1,1,1,0,0,0,1,1,
           1,1,1,1,1,1,1,1,1,1,
           0,0,0,1,0,0,0,1,0,0,
           1,1,1,1,1,1,1,1,1,1};
    puzzle6.addSolution(sol);
    rows = {"1","7","1","1","3","1 1","3 2","10","1 1","10"};
    columns = {"1\n1","1\n1","1\n2\n1","1\n4","1\n4\n1","5\n1\n1","1\n1\n1\n1","1\n1\n3","1\n2\n1","2\n1"};
    puzzle6.addRowDescription(rows);
    puzzle6.addColumnDescription(columns);
    puzzles.append(puzzle6);
    sol.clear();
    rows.clear();
    columns.clear();


    //deer 15x15
    Puzzle puzzle7(15);
    puzzle7.setTheme("Animals");
    sol = {1,1,0,1,1,0,0,0,0,0,0,1,1,0,1,
           1,1,0,1,1,0,1,0,0,1,0,1,1,0,1,
           0,1,1,1,1,0,1,0,0,1,0,1,1,0,1,
           0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,
           0,0,0,0,1,1,0,1,1,1,1,1,0,0,0,
           0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,
           0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,
           0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
           0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
           0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
           0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,
           0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,
           0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,
           0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,
           0,0,0,0,0,0,0,0,0,1,1,1,1,1,1};
    puzzle7.addSolution(sol);
    rows = {"2 2 2 1","2 2 1 1 2 1","4 1 1 2 1","5 5","2 5","7","1 1 5","11","12","13","8 5","1 3 5","5 5","3 6","6"};
    columns = {"2","3\n3","2\n2\n2","4\n6","5\n7","2\n7","3\n1\n4","7","2\n4","2\n6\n2","12","15","4\n10","1\n9","4\n8"};
    puzzle7.addRowDescription(rows);
    puzzle7.addColumnDescription(columns);
    puzzles.append(puzzle7);
    sol.clear();
    rows.clear();
    columns.clear();


    //hotdog 15x15
    Puzzle puzzle8(15);
    puzzle8.setTheme("Items");
    sol = {0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,
           0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,
           0,0,0,0,0,0,0,0,1,1,1,0,1,0,1,
           0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,
           0,0,0,0,0,0,0,1,1,0,1,0,0,1,1,
           0,0,0,0,0,0,1,1,0,0,1,0,1,1,1,
           0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,
           0,0,0,1,1,1,0,1,0,0,1,1,1,1,1,
           0,1,1,1,1,1,1,1,0,1,1,1,1,0,1,
           1,1,1,0,1,0,0,0,1,1,1,1,1,1,1,
           1,1,0,0,0,1,1,1,1,1,1,0,1,0,1,
           1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,
           0,1,1,0,0,1,1,1,1,0,1,0,1,0,0,
           0,1,1,1,1,1,1,0,1,1,1,1,0,0,0,
           0,0,1,1,1,1,1,1,1,1,0,0,0,0,0};
    puzzle8.addSolution(sol);
    rows = {"4","3 1","3 1 1","5 1","2 1 2","2 1 3","5 4","3 1 5","7 4 1","3 1 7","2 6 1 1","2 9","2 4 1 1","6 4","8"};
    columns = {"3","6","2\n3","2\n2","3\n2","3\n5","2\n1\n5","5\n3\n1","3\n1\n6","3\n1\n4\n2","6\n7","2\n1\n4\n1\n1","1\n2\n8","1\n4\n1\n1","10"};
    puzzle8.addRowDescription(rows);
    puzzle8.addColumnDescription(columns);
    puzzles.append(puzzle8);
    sol.clear();
    rows.clear();
    columns.clear();


    //train 15x15
    Puzzle puzzle9(15);
    puzzle9.setTheme("Vehicles");
    sol = {1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,
           0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
           1,1,0,1,1,0,0,0,0,0,0,0,1,1,1,
           0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,
           0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,
           0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
           0,1,0,0,0,0,1,1,1,1,1,0,0,1,0,
           1,0,0,0,0,0,0,1,0,0,1,0,0,1,1,
           1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,
           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
           1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,
           1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
           1,0,1,0,0,1,0,1,1,1,1,0,0,1,1,
           1,1,1,1,1,1,1,1,1,0,0,1,1,0,0};
    puzzle9.addSolution(sol);
    rows = {"2 2","1 1","2 2 3","1 6","3 7","13","1 5 1","1 1 1 2","1 1 5","15","15","1 4 8","13","1 1 1 4 2","9 2"};
    columns = {"1\n1\n8","1\n1\n2\n2\n1\n1","1\n3\n6","1\n1\n2\n4\n1","1\n1\n2\n4\n1","1\n6","2\n2\n1\n1","10","3\n6","4\n5","11","3\n5\n1","4\n5\n1","10\n1","4\n5\n1"};
    puzzle9.addRowDescription(rows);
    puzzle9.addColumnDescription(columns);
    puzzles.append(puzzle9);
    sol.clear();
    rows.clear();
    columns.clear();
}

PuzzleList::~PuzzleList()
{
}

Puzzle PuzzleList::getPuzzle(QString theme, int size)
{
    for(auto p : puzzles)
    {
        if(p.getSize() == size && p.getTheme() == theme)
        {
            return p;
        }
    }
    return 3;
}

void PuzzleList::addPuzzle(Puzzle puzzle)
{
    puzzles.append(puzzle);
}
