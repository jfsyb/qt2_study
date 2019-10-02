#include "startform.h"
#include "ui_startform.h"
#include "mainwindow.h"

StartForm::StartForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartForm)
{
    ui->setupUi(this);

    QPalette background;
    background.setBrush(QPalette::Background, QBrush(QPixmap(":/images/images/setbg.png")));
    this->setPalette(background);
}

StartForm::~StartForm()
{
    delete ui;
}

void StartForm::on_pushButton_clicked()
{
    MainWindow::instance()->_switch_main_page();
}

