#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(NonogramModel *newModel, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model(newModel)
{
    ui->setupUi(this);
    this->ui->checkButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_game_triggered()
{
    NewGameDialog* newGameDialog = new NewGameDialog();
    newGameDialog->show();

    if(newGameDialog->exec() == QDialog::Accepted)
    {
        // setting up labels and button
        this->ui->livesLeftLabel->setText(QString::number(newGameDialog->getLivesNumber()));
        this->ui->mistakesAmountLabel->setText(QString("Press check"));
        this->ui->checkButton->setEnabled(true);
        // saving puzzle number in model
        this->puzzleNumber = model->getPuzzleRowNumber(newGameDialog->getTheme(), newGameDialog->getSize());
        drawScene();
    }
}

void MainWindow::on_checkButton_clicked()
{
    int livesNum = this->ui->livesLeftLabel->text().toInt();
    // prepare user solution
    QVector<int> userSolution;
    for(auto t : tiles)
    {
        if(t->getIfLeftButtonPressed() == true)
        {
            userSolution.append(1);
        }
        else
        {
            userSolution.append(0);
        }
    }

    // save user solution in model and check amount of mistakes
    QModelIndex idx = model->index(this->puzzleNumber, 5, model->parent(QModelIndex()));
    model->setData(idx, QVariant::fromValue(userSolution), 1);
    int mistakes = model->puzzles()[this->puzzleNumber].checkSolution();
    // solution is incorrect
    if(mistakes != 0)
    {
        animateScene(1000);
        userSolution.clear();
        livesNum--;
        this->ui->mistakesAmountLabel->setText(QString::number(mistakes));
        QMessageBox msgBox;
        msgBox.setText("Your solution is incomplete");
        msgBox.exec();
    }
    // solution is correct
    else if (mistakes == 0)
    {
        // disabling all tiles
        for(auto t : tiles) t->setEnabled(false);
        animateScene(30000);
        userSolution.clear();
        this->ui->mistakesAmountLabel->setText(QString::number(mistakes));
        QMessageBox youWinMsgBox;
        youWinMsgBox.setText("You Won! \nCongratulations!");
        youWinMsgBox.exec();
        // disabling check button
        this->ui->checkButton->setEnabled(false);
    }
    // no lives left
    if(livesNum < 1)
    {
        QMessageBox youLostMsgBox;
        youLostMsgBox.setText("You lost! \nYou don't have any lives left.");
        youLostMsgBox.exec();
        // disabling check button
        this->ui->checkButton->setEnabled(false);
    }
    else
    {
        this->ui->livesLeftLabel->setText(QString::number(livesNum));
    }
}

void MainWindow::drawScene()
{
    rowTexts.clear();
    columnTexts.clear();
    tiles.clear();

    // fetching puzzle size, rows and columns descriptions from model
    QModelIndex idx = model->index(this->puzzleNumber, 1, model->parent(QModelIndex()));
    QVariant tmp = model->data(idx, 1);
    int size = tmp.toInt();

    idx = model->index(this->puzzleNumber, 3, model->parent(QModelIndex()));
    tmp = model->data(idx, 1);
    QList<QString> rows = tmp.toStringList();

    idx = model->index(this->puzzleNumber, 4, model->parent(QModelIndex()));
    tmp = model->data(idx, 1);
    QList<QString> columns = tmp.toStringList();

    // creating QGraphicsScene
    scene = new QGraphicsScene(this);
    ui->mainGraphicsView->setScene(scene);

    QFont serifFont("Times", 10, QFont::DemiBold);

    // creating and placing tiles and descriptions
    for (int i = 0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            Tile *tile = new Tile();
            scene->addItem(tile);
            tile->setPos(-150 + j*30, 150 + i*30);
            tiles.append(tile);
        }

        QGraphicsSimpleTextItem* simpleRowText = scene->addSimpleText(rows[i], serifFont);
        qreal width = simpleRowText->boundingRect().width();
        simpleRowText->setPos(-155 - width,155 + i*30);
        rowTexts.append(simpleRowText);
        QGraphicsSimpleTextItem* simpleColumnText = scene->addSimpleText(columns[i], serifFont);
        qreal height = simpleColumnText->boundingRect().height();
        simpleColumnText->setPos(-140 + i*30, 145 - height);
        columnTexts.append(simpleColumnText);
    }
}

void MainWindow::animateScene(int time)
{
    // simple tile spining animation
    for (int i=0; i < tiles.size(); i++)
    {
        QTimeLine* timer = new QTimeLine(time);
        timer->setFrameRange(0, 100);
        QGraphicsItemAnimation* animation = new QGraphicsItemAnimation;
        animation->setItem(tiles[i]);
        animation->setTimeLine(timer);
        animation->setRotationAt(1, 360);
        timer->start();
    }
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_actionHow_to_play_triggered()
{
    QMessageBox howToPlayMsgBox;
    howToPlayMsgBox.setText("Hello!\nNonogram (also known as 'Paint By Numbers', 'Japanese Crossword', 'Griddler', 'CrossPix' or 'Hanjie')"
                            " is a puzzle where it is necessary to draw an image in accordance with the numbers outside the grid. "
                            "The image is made up of blue and white/red squares. The numbers indicate how many groups of blue squares are in each row or column. "
                            "For example in 15x15 puzzle if a row is described by '1 3 5' we have 3 groups of blue squares containing 1, 3 and 5 "
                            "blue squares, so 9 blue squares in total in that row. Same applies to columns. "
                            "Each group of blue squares has to be separated by at least 1 white/red square.\nClick LMB to change its colot to blue or RMB to chnage it to red. "
                            "Use red to paint tiles which you think are not blue ones.\n\nTo see your result press \"Check\" button.\nHave fun!");
    howToPlayMsgBox.setWindowTitle("How to play");
    howToPlayMsgBox.exec();
}
