#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setStyleSheet("background-color: #FEFEFE");
    ui->verticalLayout->setAlignment(ui->pushButton, Qt::AlignHCenter);
    ui->pushButton->setMinimumWidth(200);
    ui->pushButton->setStyleSheet("#pushButton {"
        "color: #111111;"
        "background-color: #CCD5AE;"
        "border: 0;"
        "transition-duration: 1s"
        "}"
                                  "#pushButton:hover {"
                                  "color: #111111;"
                                  "background-color: #E9EDC9;"
                                  "border: 0;"
                                  "transition-duration: 1s"
                                  "}"
                                  );
}

MainWindow::~MainWindow()
{
    delete ui;
}
