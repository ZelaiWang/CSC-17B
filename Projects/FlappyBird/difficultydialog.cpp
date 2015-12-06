#include "difficultydialog.h"
#include "ui_difficultydialog.h"

DifficultyDialog::DifficultyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DifficultyDialog)
{
    ui->setupUi(this);

    ui->dComboBox->addItem(GameLevel::EASY.getLevelN());
    ui->dComboBox->addItem(GameLevel::MEDIUM.getLevelN());
    ui->dComboBox->addItem(GameLevel::HARD.getLevelN());
}

DifficultyDialog::~DifficultyDialog()
{
    delete ui;
}

void DifficultyDialog::on_startButton_clicked()
{
    GameLevel::setLevelN(ui->dComboBox->currentText());
    emit startGame();
}
