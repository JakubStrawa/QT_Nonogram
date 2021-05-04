#include "mainwindow.h"
#include "nonogrammodel.h"
#include "puzzlelist.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PuzzleList puzzles = PuzzleList();
    NonogramModel* model = new NonogramModel(puzzles.puzzles);
    MainWindow w(model);
    w.show();
    return a.exec();
}
