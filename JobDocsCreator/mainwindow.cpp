#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "cveditor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Définition d'un arrière-plan plus sombre pour le centralwidget
    ui->centralwidget->setStyleSheet("background-color: #10002b");

    // Centrage horizontal du bouton dans le layout vertical
    ui->verticalLayout->setAlignment(ui->pushButton, Qt::AlignHCenter);

    // Définition d'un style plus sombre pour le bouton "Créer un CV"
    ui->pushButton->setMinimumWidth(200);
    ui->pushButton->setStyleSheet(
        "#pushButton {"
        "   color: #FEFEFE;"
        "   background-color: #5a189a;"
        "   border: 0px solid transparent;"
        "   border-radius: 25px;"
        "}"
        "#pushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );

    // Changement de la couleur du titre
    ui->appName->setStyleSheet("color: #FEFEFE;");

    // Changement de la couleur du sous-titre
    ui->slogan->setStyleSheet("color: #FEFEFE;");


    setWindowTitle("JobDocs : Créateur de CV");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    CvEditor Cveditor;
    Cveditor.setModal(true);
    hide();
    Cveditor.exec();
}

