#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "nonogrammodel.h"
#include "newgamedialog.h"
#include "tile.h"
#include "puzzlelist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(NonogramModel *model, QWidget *parent = nullptr);
    ~MainWindow();

private slots: 
    void on_actionNew_game_triggered();

    void on_checkButton_clicked();

    void on_actionQuit_triggered();

    void on_actionHow_to_play_triggered();

private:
    NonogramModel *model;
    int puzzleNumber;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QVector<Tile*> tiles;
    QVector<QGraphicsSimpleTextItem*> rowTexts;
    QVector<QGraphicsSimpleTextItem*> columnTexts;

    void drawScene();
    void animateScene(int time);

};
#endif // MAINWINDOW_H
