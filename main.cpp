#include "mainwindow.h"
#include "nonogrammodel.h"
#include "puzzlelist.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // setting up model
    PuzzleList puzzles = PuzzleList();
    NonogramModel* model = new NonogramModel(puzzles.puzzles);

    // creating main application window
    MainWindow w(model);
    w.show();
    return a.exec();
}
