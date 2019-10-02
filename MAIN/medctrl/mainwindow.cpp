#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow *pMainWindow = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pMainWindow = this;
    _switch_main_page();
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow * MainWindow::instance()
{
    return pMainWindow;
}

void MainWindow::_switch_page(int page)
{
    current_page = page;
    ui->stackedWidget->setCurrentIndex(page);
}

void MainWindow::_switch_main_page()
{
    _switch_page(1);
}

void MainWindow::_switch_start_page()
{
    _switch_page(0);
}




