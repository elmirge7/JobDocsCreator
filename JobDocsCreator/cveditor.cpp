#include "cveditor.h"
#include "ui_cveditor.h"

#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <string>
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFontDialog>

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
    painter.setBrush(primaryColorCV);
    painter.drawRect(5, 0, 950, 300);

    // Création du texte prenom nom
    // définition de la police
    QFont fontName (textFont, 40);
    painter.setFont(fontName);

    painter.setPen(textColorName);
    painter.drawText(200, 150, ui->nameText->toPlainText() + " " + ui->surnameText->toPlainText());


    // Ajout de la photo téléchargée par l'utilisateur
    QPixmap photo = ui->labelPhoto->pixmap(); // Récupérer la photo téléchargée depuis le label

    if (!photo.isNull()) {
        // Définir la position et la taille de l'image dans le PDF
        int photoWidth = photo.width();
        int photoHeight = photo.height();
        int photoX = 50; // Position X où placer la photo
        int photoY = 50; // Position Y où placer la photo

        // Dessiner l'image dans le fichier PDF
        painter.drawPixmap(photoX, photoY, photoWidth, photoHeight, photo);
    }

    // création du métier recherche
    QFont fontJob (textFont, 20);
    painter.setFont(fontJob);
    painter.setPen(textColorJob);
    painter.drawText(200, 200, ui->jobEdit->toPlainText());


    painter.drawLine(100,300, 100, 1500);
    painter.drawLine(600,300, 600, 1500);


    // Partie description de la personne
    painter.drawEllipse(90, 350, 20, 20);

    int maxWidthDesc = 450;

    QFont fontDesc (textFont, 12);
    painter.setFont(fontDesc);
    painter.setPen(textColorInfos);
    QRect textRect(130, 350, maxWidthDesc, 200);
    painter.drawText(textRect, Qt::TextWordWrap, ui->textEditDesc->toPlainText());


    // partie formation
    painter.drawEllipse(90, 630, 20, 20);
    QFont fontSubTitle (textFont, 14);
    fontSubTitle.setCapitalization(QFont::AllUppercase);;
    painter.setFont(fontSubTitle);
    painter.drawText(130, 650, "Formations");


         // définition de la liste des formations

    QString formationA = ui->textEditNomDiplome->toPlainText() + "\n" +
                         ui->textEditLieuDiplome->toPlainText() + "\n" +
                         ui->dateEditDiplome->text() + "\n" +
                         ui->textEditDescDiplome->toPlainText();

    QString formationB = ui->textEditNomDiplome_2->toPlainText() + "\n" +
                         ui->textEditLieuDiplome_2->toPlainText() + "\n" +
                         ui->dateEditDiplome_2->text() + "\n" +
                         ui->textEditDescDiplome_2->toPlainText();

    QString formationC = ui->textEditNomDiplome_3->toPlainText() + "\n" +
                         ui->textEditLieuDiplome_3->toPlainText() + "\n" +
                         ui->dateEditDiplome_3->text() + "\n" +
                         ui->textEditDescDiplome_3->toPlainText();

    // Créer une QStringList pour stocker les informations sur les formations
    QStringList formations;
    formations << formationA << formationB << formationC;

    // Position intiale des foramtions
    int yInitPosForm = 700;
    QFont fontSubTitleList (textFont, 12);
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


    QString experienceA = ui->textEditNomExperience->toPlainText() + "\n" +
                          ui->textEditLieuExperience->toPlainText() + "\n" +
                          ui->dateEditExperienceStart->text() + "\n" +
                          ui->dateEditExperienceEnd->text() + "\n" +
                          ui->textEditDescExperience->toPlainText();

    QString experienceB = ui->textEditNomExperience_2->toPlainText() + "\n" +
                          ui->textEditLieuExperience_2->toPlainText() + "\n" +
                          ui->dateEditExperienceStart_2->text() + "\n" +
                          ui->dateEditExperienceEnd_2->text() + "\n" +
                          ui->textEditDescExperience_2->toPlainText();

    QString experienceC = ui->textEditNomExperience_3->toPlainText() + "\n" +
                          ui->textEditLieuExperience_3->toPlainText() + "\n" +
                          ui->dateEditExperienceStart_3->text() + "\n" +
                          ui->dateEditExperienceEnd_3->text() + "\n" +
                          ui->textEditDescExperience_3->toPlainText();


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
    painter.drawEllipse(590, 350, 20, 20);

    painter.setFont(fontSubTitle);
    painter.setPen(textColorInfos);
    painter.drawText(630, 370, "Informations");

    // définition de la liste des informations personnelles

    QString age = ui->textEditAge->toPlainText();
    QString phoneNumber = ui->textEditPhoneNumber->toPlainText();
    QString mail = ui->textEditMail->toPlainText();
    QString website = ui->textEditWebsite->toPlainText();

    QStringList informations;
    informations << age << phoneNumber << mail << website;

    // Position intiale des informations
    int yInitPosInfo = 400;
    painter.setFont(fontSubTitleList);

    foreach (const QString &information, informations) {
        painter.drawText(630, yInitPosInfo, information);
        yInitPosInfo += 35;
    }

    // Définition des compétences et de leurs niveaux
    QMap<QString, int> competences;
    competences.insert("Compétence 1", 80); // Par exemple, niveau de compétence sur 100
    competences.insert("Compétence 2", 60);
    competences.insert("Compétence 3", 90);
    competences.insert("Compétence 4", 80);
    competences.insert("Compétence 5", 60);
    competences.insert("Compétence 6", 90);

    // Définition des positions pour afficher les compétences et les barres de progression
    int startX = 630;
    int startY = 710;
    int barWidth = 200;
    int barHeight = 20;
    int barMargin = 50;

    // Définition de la police et de la taille de la police pour les compétences
    QFont fontCompetence(textFont, 10);
    painter.setFont(fontCompetence);

    // Parcourir les compétences et dessiner les noms et les barres de progression
    foreach (const QString &competence, competences.keys()) {
        // Dessiner le nom de la compétence
        painter.drawText(startX, startY, competence);

        // Dessiner la barre de progression
        int niveau = competences.value(competence);
        QRect barRect(startX, startY + 5, niveau * barWidth / 100, barHeight);
        painter.fillRect(barRect, primaryColorCV); // Vous pouvez ajuster la couleur de la barre ici

        // Mettre à jour la position Y pour la prochaine compétence
        startY += barHeight + barMargin;
    }

    // Partie description de la personne
    painter.drawEllipse(590, 650, 20, 20);

    painter.setFont(fontSubTitle);
    painter.setPen(textColorInfos);
    painter.drawText(630, 670, "Compétences");


    // Partie loisirs
    painter.drawEllipse(590, 1100, 20, 20);

    painter.setFont(fontSubTitle);
    painter.setPen(textColorInfos);
    painter.drawText(630, 1120, "Loisirs");

    // définition de la liste des informations personnelles
    QStringList loisirs;
    loisirs << "Football" << "Voyages" << "Jeux-vidéo";

    // Position intiale des informations
    int yInitPosLoi = 1140;
    painter.setFont(fontSubTitleList);

    foreach (const QString &loisir, loisirs) {
        painter.drawText(630, yInitPosLoi, loisir);
        yInitPosLoi += 35;
    }



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


void CvEditor::on_pushButton_5_clicked()
{
    QString fichierPhoto = QFileDialog::getOpenFileName(this, "Choisir une photo", QDir::homePath(), "Images (*.png, *jpg, *.jpeg");
    if (!fichierPhoto.isEmpty()) {
        QPixmap photo(fichierPhoto);
        if(!photo.isNull()) {
            ui->labelPhoto->setPixmap(photo.scaled(ui->labelPhoto->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        else {
            QMessageBox::warning(this, "Erreur", "Impossible de charger la photo.");
        }
    }
}


void CvEditor::on_buttonChoiceColor_clicked()
{
    QColor primaryColor = QColorDialog::getColor(Qt::black, this, "choisis une couleur principale pour le CV");
    if (primaryColor.isValid()) {
        QString colorString = primaryColor.name();

        // Appliquer la couleur choisie au label
        ui->colorLabel->setStyleSheet("color: " + colorString + ";");
    } else {
        return;
    }
    primaryColorCV = primaryColor;
}


void CvEditor::on_buttonChoiceColorName_clicked()
{
    QColor nameColor = QColorDialog::getColor(Qt::black, this, "choisis une couleur pour le prénom nom");
    if (nameColor.isValid()) {
        QString colorString = nameColor.name();

        // Appliquer la couleur choisie au label
        ui->colorLabelName->setStyleSheet("color: " + colorString + ";");
    } else {
        return;
    }
    textColorName = nameColor;
}


void CvEditor::on_buttonChoiceColorJob_clicked()
{
    QColor jobColor = QColorDialog::getColor(Qt::black, this, "choisis une couleur pour le métier");
    if (jobColor.isValid()) {
        QString colorString = jobColor.name();

        // Appliquer la couleur choisie au label
        ui->colorLabelJob->setStyleSheet("color: " + colorString + ";");
    } else {
        return;
    }
    textColorJob = jobColor;
}


void CvEditor::on_buttonChoiceColorInfos_clicked()
{
    QColor infosColor = QColorDialog::getColor(Qt::black, this, "choisis une couleur pour le métier");
    if (infosColor.isValid()) {
        QString colorString = infosColor.name();

        // Appliquer la couleur choisie au label
        ui->colorLabelInfos->setStyleSheet("color: " + colorString + ";");
    } else {
        return;
    }
    textColorInfos = infosColor;
}


void CvEditor::on_buttonChoiceFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Poppins", 12), this, "Choisir une police");
    if (ok) {
        QString fontName = font.family(); // Récupérer le nom de la police sélectionnée
        ui->labelFont->setFont(QFont(fontName, 12)); // Appliquer la police sélectionnée au QLabel avec une taille de police de 12
        textFont = fontName;
    }
}

void CvEditor::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_7);
}


void CvEditor::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_desc);
}


void CvEditor::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageFormations);
}


void CvEditor::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageExperiences);
}


void CvEditor::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagePerso);
}

