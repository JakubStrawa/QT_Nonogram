#include "newgamedialog.h"
#include "ui_newgamedialog.h"

NewGameDialog::NewGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGameDialog)
{
    ui->setupUi(this);
    ui->sizeComboBox->addItem("5x5");
    ui->sizeComboBox->addItem("10x10");
    ui->sizeComboBox->addItem("15x15");
    ui->themeComboBox->addItem("Animals");
    ui->themeComboBox->addItem("Items");
    ui->themeComboBox->addItem("Vehicles");
}

NewGameDialog::~NewGameDialog()
{
    delete ui;
}

int NewGameDialog::getLivesNumber()
{
    return this->ui->livesSpinBox->value();
}

int NewGameDialog::getSize()
{
    return this->ui->sizeComboBox->currentIndex();
}

int NewGameDialog::getTheme()
{
    return this->ui->themeComboBox->currentIndex();
}
