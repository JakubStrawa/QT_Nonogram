#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QDialog>

namespace Ui {
class NewGameDialog;
}

class NewGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewGameDialog(QWidget *parent = nullptr);
    ~NewGameDialog();

    int getLivesNumber();
    int getSize();
    int getTheme();

private:
    Ui::NewGameDialog *ui;
};

#endif // NEWGAMEDIALOG_H
