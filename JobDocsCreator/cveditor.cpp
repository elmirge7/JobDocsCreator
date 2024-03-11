#include "cveditor.h"
#include "ui_cveditor.h"

#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <string>

CvEditor::CvEditor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CvEditor)
{
    ui->setupUi(this);
}

CvEditor::~CvEditor()
{
    delete ui;
}

void CvEditor::on_pdfButton_clicked()
{
    QPrinter printer;
    printer.setResolution(QPrinter::HighResolution);
    printer.setFullPage(true);
    QPrintDialog dialog(&printer,this);


    if(dialog.exec() == QDialog::Rejected)
        return;

    QPainter painter;
    painter.begin(&printer);

    // Création de l'en-tête

    // Rectangle en fond
    painter.setBrush(Qt::black);
    painter.drawRect(5, 0, 950, 300);

    // Création du texte prenom nom
    // définition de la police
    QFont fontName ("Poppins", 40);
    painter.setFont(fontName);

    painter.setPen(Qt::white);
    painter.drawText(200, 150, ui->nameText->toPlainText() + " " + ui->surnameText->toPlainText());


    // création du métier recherche
    QFont fontJob ("Poppins", 20);
    painter.setFont(fontJob);
    painter.setPen(Qt::gray);
    painter.drawText(200, 200, "Métier recherché");


    painter.drawLine(100,300, 100, 1500);
    painter.drawLine(700,300, 700, 1500);


    // Partie description de la personne
    painter.drawEllipse(90, 350, 20, 20);

    int maxWidthDesc = 500;
    QString loremText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";


    QFont fontDesc ("Poppins", 12);
    painter.setFont(fontDesc);
    painter.setPen(Qt::black);
    QRect textRect(130, 350, maxWidthDesc, 200);
    painter.drawText(textRect, Qt::TextWordWrap, loremText);


    // partie formation
    painter.drawEllipse(90, 630, 20, 20);
    QFont fontSubTitle ("Poppins", 14);
    fontSubTitle.setCapitalization(QFont::AllUppercase);;
    painter.setFont(fontSubTitle);
    painter.drawText(130, 650, "Formations");


         // définition de la liste des formations
    QStringList formations;
    formations << "Formation A \n2018" << "Formation B" << "Formation C";

    // Position intiale des foramtions
    int yInitPosForm = 700;
    QFont fontSubTitleList ("Poppins", 12);
    painter.setFont(fontSubTitleList);

    foreach (const QString &formation, formations) {
        QStringList lines = formation.split("\n");
        foreach (const QString &line, lines) {
            painter.drawText(130, yInitPosForm, line);
            yInitPosForm += 25;
        }
    }

    // partie expériences
    painter.drawEllipse(90, 930, 20, 20);
    fontSubTitle.setCapitalization(QFont::AllUppercase);;
    painter.setFont(fontSubTitle);
    painter.drawText(130, 950, "Expériences");


    // définition de la liste des formations
    QStringList experiences;
    experiences << "expérience A \n2018" << "expérience B" << "expérience C";

    // Position intiale des foramtions
    int yInitPosExp = 1000;
    painter.setFont(fontSubTitleList);

    foreach (const QString &experience, experiences) {
        QStringList lines = experience.split("\n");
        foreach (const QString &line, lines) {
            painter.drawText(130, yInitPosExp, line);
            yInitPosExp += 25;
        }
    }

    // Partie description de la personne
    painter.drawEllipse(700, 350, 20, 20);

    painter.setFont(fontSubTitle);
    painter.setPen(Qt::black);
    painter.drawText(750, 350, "Informations");


    // tableau

    // int startX = 100;
    // int startY = 500;
    // int cellWidth = 100;
    // int cellHeight = 20;

    // // dessiner les lignes hoizontales
    // for (int i = 0; i < 5; i++) {
    //     painter.drawLine(startX, startY + i*cellHeight, startX + 3*cellWidth, startY + i*cellHeight);
    // }

    // // dessiner les lignes verticales
    // for (int j = 0; j < 4; j++) {
    //     painter.drawLine(startX + j*cellWidth, startY, startX + j*cellWidth, startY + 4*cellHeight);
    // }

    // //remplissage du tableau avec du texte
    // for (int k = 1; k < 4; k++) {

    //     painter.drawText(startX + (k-1) * cellWidth, startY, cellWidth, cellHeight, Qt::AlignCenter, ("Colonne " + std::to_string(k)).c_str());
    // }

    painter.end();
}


void CvEditor::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}


void CvEditor::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_5);
}


void CvEditor::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_6);
}

