#include "cveditor.h"
#include "ui_cveditor.h"
#include "dragdroplabel.h"

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
    m_layout = new QGridLayout;

    // Création des objets DragDropLabel
    m_dragdroplabel1 = new DragDropLabel(true, false);
    m_dragdroplabel2 = new DragDropLabel(true, false);
    m_dragdroplabel3 = new DragDropLabel(true, false);
    m_dragdroplabel4 = new DragDropLabel(true, false);
    m_dragdroplabel5 = new DragDropLabel(true, false);
    m_dragdroplabel6 = new DragDropLabel(true, false);
    m_dragdroplabelresult1 = new DragDropLabel(false, true);
    m_dragdroplabelresult2 = new DragDropLabel(false, true);
    m_dragdroplabelresult3 = new DragDropLabel(false, true);
    m_dragdroplabelresult4 = new DragDropLabel(false, true);
    m_dragdroplabelresult5 = new DragDropLabel(false, true);
    m_dragdroplabelresult6 = new DragDropLabel(false, true);

    // Assignation des pixmap aux objets DragDropLabel
    m_dragdroplabel1->setPixmap(QPixmap("C:/Users/gerov/Pictures/QtPictures/image_jobdocs_description.jpg"));
    m_dragdroplabel2->setPixmap(QPixmap("C:/Users/gerov/Pictures/QtPictures/image_jobdocs_formations.jpg"));
    m_dragdroplabel3->setPixmap(QPixmap("C:/Users/gerov/Pictures/QtPictures/image_jobdocs_experiences.jpg"));
    m_dragdroplabel4->setPixmap(QPixmap("C:/Users/gerov/Pictures/QtPictures/image_jobdocs_info_perso.jpg"));
    m_dragdroplabel5->setPixmap(QPixmap("C:/Users/gerov/Pictures/QtPictures/image_jobdocs_competences.jpg"));
    m_dragdroplabel6->setPixmap(QPixmap("C:/Users/gerov/Pictures/QtPictures/image_jobdocs_loisirs.jpg"));
    m_dragdroplabelresult1->setPixmap(QPixmap("C:/Users/gerov/Pictures/QtPictures/image_jobdocs_empty.jpg"));
    m_dragdroplabelresult2->setPixmap(QPixmap("C:/Users/gerov/Pictures/QtPictures/image_jobdocs_empty.jpg"));
    m_dragdroplabelresult3->setPixmap(QPixmap("C:/Users/gerov/Pictures/QtPictures/image_jobdocs_empty.jpg"));
    m_dragdroplabelresult4->setPixmap(QPixmap("C:/Users/gerov/Pictures/QtPictures/image_jobdocs_empty.jpg"));
    m_dragdroplabelresult5->setPixmap(QPixmap("C:/Users/gerov/Pictures/QtPictures/image_jobdocs_empty.jpg"));
    m_dragdroplabelresult6->setPixmap(QPixmap("C:/Users/gerov/Pictures/QtPictures/image_jobdocs_empty.jpg"));


    m_layout->addWidget(m_dragdroplabel1,0,0);
    m_layout->addWidget(m_dragdroplabel2,1,0);
    m_layout->addWidget(m_dragdroplabel3,2,0);
    m_layout->addWidget(m_dragdroplabel4,3,0);
    m_layout->addWidget(m_dragdroplabel5,4,0);
    m_layout->addWidget(m_dragdroplabel6,5,0);
    m_layout->addWidget(m_dragdroplabelresult1,1,1);
    m_layout->addWidget(m_dragdroplabelresult2,1,2);
    m_layout->addWidget(m_dragdroplabelresult3,2,1);
    m_layout->addWidget(m_dragdroplabelresult4,2,2);
    m_layout->addWidget(m_dragdroplabelresult5,3,1);
    m_layout->addWidget(m_dragdroplabelresult6,3,2);

    int pageIndex = ui->stackedWidget->indexOf(ui->pageTemplate);
    if (pageIndex != -1) {
        QWidget *page = ui->stackedWidget->widget(pageIndex);
        page->setLayout(m_layout);
    }

    // les images de base

    start1previous = m_dragdroplabel1->imageStart;

    m_dragdroplabel1->setScaledContents(true);
    if (m_dragdroplabel1->imageStart != start1previous) {
        start1next = m_dragdroplabel1->imageStart;
    }

    start2previous = m_dragdroplabel2->imageStart;
    m_dragdroplabel2->setScaledContents(true);
    if (m_dragdroplabel2->imageStart != start2previous) {
        start2next = m_dragdroplabel2->imageStart;
    }

    start3previous = m_dragdroplabel3->imageStart;
    m_dragdroplabel3->setScaledContents(true);
    if (m_dragdroplabel3->imageStart != start3previous) {
        start3next = m_dragdroplabel3->imageStart;
    }

    start4previous = m_dragdroplabel4->imageStart;
    m_dragdroplabel4->setScaledContents(true);
    if (m_dragdroplabel4->imageStart != start4previous) {
        start4next = m_dragdroplabel4->imageStart;
    }

    start5previous = m_dragdroplabel5->imageStart;
    m_dragdroplabel5->setScaledContents(true);
    if (m_dragdroplabel5->imageStart != start5previous) {
        start5next = m_dragdroplabel5->imageStart;
    }

    start6previous = m_dragdroplabel6->imageStart;
    m_dragdroplabel6->setScaledContents(true);
    if (m_dragdroplabel6->imageStart != start6previous) {
        start6next = m_dragdroplabel6->imageStart;
    }

    // Les résultats

    result1previous = m_dragdroplabelresult1->imageResult;
    if (m_dragdroplabelresult1->imageResult != result1previous || m_dragdroplabelresult1->imageResult != result1next) {
        result1next = m_dragdroplabelresult1->imageResult;
    }



    result2previous = m_dragdroplabelresult2->imageResult;
    if (m_dragdroplabelresult2->imageResult != result2previous || m_dragdroplabelresult2->imageResult != result2next) {
        result2next = m_dragdroplabelresult2->imageResult;
    }


    result3previous = m_dragdroplabelresult3->imageResult;
    if (m_dragdroplabelresult3->imageResult != result3previous || m_dragdroplabelresult3->imageResult != result3next) {
        result3next = m_dragdroplabelresult3->imageResult;
    }

    result4previous = m_dragdroplabelresult4->imageResult;
    if (m_dragdroplabelresult4->imageResult != result4previous || m_dragdroplabelresult4->imageResult != result4next) {
        result4next = m_dragdroplabelresult4->imageResult;
    }

    result5previous = m_dragdroplabelresult5->imageResult;
    if (m_dragdroplabelresult5->imageResult != result5previous || m_dragdroplabelresult5->imageResult != result5next) {
        result5next = m_dragdroplabelresult5->imageResult;
    }

    result6previous = m_dragdroplabelresult6->imageResult;
    if (m_dragdroplabelresult6->imageResult != result6previous || m_dragdroplabelresult6->imageResult != result6next) {
        result6next = m_dragdroplabelresult6->imageResult;
    }

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

    int positionDescX;
    int positionDescY;

    int positionFormationX;
    int positionFormationY;

    int positionExperienceX;
    int positionExperienceY;

    int positionInfoPersoX;
    int positionInfoPersoY;

    int positionCompetenceX;
    int positionCompetenceY;

    int positionLoisirX;
    int positionLoisirY;


    // Calcul des positions
    switch (positionDescription) {
    case 1:
        positionDescX = 90;
        positionDescY = 350;
        break;
    case 2:
        positionDescX = 630;
        positionDescY = 370;
        break;
    case 3:
        positionDescX = 130;
        positionDescY = 650;
        break;
    case 4:
        positionDescX = 630;
        positionDescY = 670;
        break;
    case 5:
        positionDescX = 130;
        positionDescY = 1000;
        break;
    case 6:
        positionDescX = 630;
        positionDescY = 1000;
        break;
    default:
        positionDescX = 9999;
        positionDescY = 9999;
        break;
    }

    switch (positionFormation) {
    case 1:
        positionFormationX = 90;
        positionFormationY = 350;
        break;
    case 2:
        positionFormationX = 630;
        positionFormationY = 370;
        break;
    case 3:
        positionFormationX = 130;
        positionFormationY = 650;
        break;
    case 4:
        positionFormationX = 630;
        positionFormationY = 670;
        break;
    case 5:
        positionFormationX = 130;
        positionFormationY = 1000;
        break;
    case 6:
        positionFormationX = 630;
        positionFormationY = 1000;
        break;
    default:
        positionFormationX = 9999;
        positionFormationY = 9999;
        break;
    }

    switch (positionExperience) {
    case 1:
        positionExperienceX = 90;
        positionExperienceY = 350;
        break;
    case 2:
        positionExperienceX = 630;
        positionExperienceY = 370;
        break;
    case 3:
        positionExperienceX = 130;
        positionExperienceY = 650;
        break;
    case 4:
        positionExperienceX = 630;
        positionExperienceY = 670;
        break;
    case 5:
        positionExperienceX = 130;
        positionExperienceY = 1000;
        break;
    case 6:
        positionExperienceX = 630;
        positionExperienceY = 1000;
        break;
    default:
        positionExperienceX = 9999;
        positionExperienceY = 9999;
        break;
    }

    switch (positionInfoPerso) {
    case 1:
        positionInfoPersoX = 90;
        positionInfoPersoY = 350;
        break;
    case 2:
        positionInfoPersoX = 630;
        positionInfoPersoY = 370;
        break;
    case 3:
        positionInfoPersoX = 130;
        positionInfoPersoY = 650;
        break;
    case 4:
        positionInfoPersoX = 630;
        positionInfoPersoY = 670;
        break;
    case 5:
        positionInfoPersoX = 130;
        positionInfoPersoY = 1000;
        break;
    case 6:
        positionInfoPersoX = 630;
        positionInfoPersoY = 1000;
        break;
    default:
        positionInfoPersoX = 9999;
        positionInfoPersoY = 9999;
        break;
    }

    switch (positionCompetence) {
    case 1:
        positionCompetenceX = 90;
        positionCompetenceY = 350;
        break;
    case 2:
        positionCompetenceX = 630;
        positionCompetenceY = 370;
        break;
    case 3:
        positionCompetenceX = 130;
        positionCompetenceY = 650;
        break;
    case 4:
        positionCompetenceX = 630;
        positionCompetenceY = 670;
        break;
    case 5:
        positionCompetenceX = 130;
        positionCompetenceY = 1000;
        break;
    case 6:
        positionCompetenceX = 630;
        positionCompetenceY = 1000;
        break;
    default:
        positionCompetenceX = 9999;
        positionCompetenceY = 9999;
        break;
    }

    switch (positionLoisir) {
    case 1:
        positionLoisirX = 90;
        positionLoisirY = 350;
        break;
    case 2:
        positionLoisirX = 630;
        positionLoisirY = 370;
        break;
    case 3:
        positionLoisirX = 130;
        positionLoisirY = 650;
        break;
    case 4:
        positionLoisirX = 630;
        positionLoisirY = 670;
        break;
    case 5:
        positionLoisirX = 130;
        positionLoisirY = 1000;
        break;
    case 6:
        positionLoisirX = 630;
        positionLoisirY = 1000;
        break;
    default:
        positionLoisirX = 9999;
        positionLoisirY = 9999;
        break;
    }

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
    QRect textRect(positionDescX, positionDescY, maxWidthDesc, 200);
    painter.drawText(textRect, Qt::TextWordWrap, ui->textEditDesc->toPlainText());


    // partie formation
    painter.drawEllipse(90, 630, 20, 20);
    QFont fontSubTitle (textFont, 14);
    fontSubTitle.setCapitalization(QFont::AllUppercase);;
    painter.setFont(fontSubTitle);
    painter.drawText(positionFormationX, positionFormationY, "Formations");


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
    int yInitPosForm = positionFormationY + 50;
    QFont fontSubTitleList (textFont, 12);
    painter.setFont(fontSubTitleList);

    foreach (const QString &formation, formations) {
        QStringList lines = formation.split("\n");
        foreach (const QString &line, lines) {
            painter.drawText(positionFormationX, yInitPosForm, line);
            yInitPosForm += 25;
        }
    }

    // partie expériences
    painter.drawEllipse(90, 930, 20, 20);
    fontSubTitle.setCapitalization(QFont::AllUppercase);;
    painter.setFont(fontSubTitle);
    painter.drawText(positionExperienceX, positionExperienceY, "Expériences");


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
    experiences << experienceA << experienceB << experienceC;

    // Position intiale des foramtions
    int yInitPosExp = positionExperienceY + 50;
    painter.setFont(fontSubTitleList);

    foreach (const QString &experience, experiences) {
        QStringList lines = experience.split("\n");
        foreach (const QString &line, lines) {
            painter.drawText(positionExperienceX, yInitPosExp, line);
            yInitPosExp += 25;
        }
    }

    // Partie informations perso de la personne
    painter.drawEllipse(590, 350, 20, 20);

    painter.setFont(fontSubTitle);
    painter.setPen(textColorInfos);
    painter.drawText(positionInfoPersoX, positionInfoPersoY, "Informations");

    // définition de la liste des informations personnelles

    QString age = ui->textEditAge->toPlainText();

    if (ui->checkBoxAge->isChecked()) {
        age = NULL;
    }
    QString phoneNumber = ui->textEditPhoneNumber->toPlainText();
    if (ui->checkBoxPhoneNumber->isChecked()) {
        phoneNumber = NULL;
    }
    QString mail = ui->textEditMail->toPlainText();
    if (ui->checkBoxMail->isChecked()) {
        mail = NULL;
    }
    QString website = ui->textEditWebsite->toPlainText();
    if (ui->checkBoxWebsite->isChecked()) {
        website = NULL;
    }

    QStringList informations;
    informations << age << phoneNumber << mail << website;

    // Position intiale des informations
    int yInitPosInfo = positionInfoPersoY + 50;
    painter.setFont(fontSubTitleList);

    foreach (const QString &information, informations) {
        if (information.isNull() || information.isEmpty()) {
            yInitPosInfo += 0;
        } else {
            painter.drawText(positionInfoPersoX, yInitPosInfo, information);
            yInitPosInfo += 35;
        }
    }

    // Définition des compétences et de leurs niveaux

    QString competence1 = ui->textEditCompetence->toPlainText();
    int levelComp1 = ui->spinBoxCompetence->value();
    if (ui->checkBoxCompetence->isChecked()) {
        competence1 = NULL;
        levelComp1 = NULL;
    }

    QString competence2 = ui->textEditCompetence_2->toPlainText();
    int levelComp2 = ui->spinBoxCompetence_2->value();
    if (ui->checkBoxCompetence_2->isChecked()) {
        competence2 = NULL;
        levelComp2 = NULL;
    }

    QString competence3 = ui->textEditCompetence_3->toPlainText();
    int levelComp3 = ui->spinBoxCompetence_3->value();
    if (ui->checkBoxCompetence_3->isChecked()) {
        competence3 = NULL;
        levelComp3 = NULL;
    }

    QString competence4 = ui->textEditCompetence_4->toPlainText();
    int levelComp4 = ui->spinBoxCompetence_4->value();
    if (ui->checkBoxCompetence_4->isChecked()) {
        competence4 = NULL;
        levelComp4 = NULL;
    }

    QString competence5 = ui->textEditCompetence_5->toPlainText();
    int levelComp5 = ui->spinBoxCompetence_5->value();
    if (ui->checkBoxCompetence_5->isChecked()) {
        competence1 = NULL;
        levelComp1 = NULL;
    }
    QString competence6 = ui->textEditCompetence_6->toPlainText();
    int levelComp6 = ui->spinBoxCompetence_6->value();
    if (ui->checkBoxCompetence_6->isChecked()) {
        competence6 = NULL;
        levelComp6 = NULL;
    }

    QMap<QString, int> competences;
    competences.insert(competence1, levelComp1); // Par exemple, niveau de compétence sur 100
    competences.insert(competence2, levelComp2);
    competences.insert(competence3, levelComp3);
    competences.insert(competence4, levelComp4);
    competences.insert(competence5, levelComp5);
    competences.insert(competence6, levelComp6);

    // Définition des positions pour afficher les compétences et les barres de progression
    int startX = positionCompetenceX;
    int startY = positionCompetenceY + 50;
    int barWidth = 200;
    int barHeight = 20;
    int barMargin = 50;

    // Définition de la police et de la taille de la police pour les compétences
    QFont fontCompetence(textFont, 10);
    painter.setFont(fontCompetence);

    // Parcourir les compétences et dessiner les noms et les barres de progression
    foreach (const QString &competence, competences.keys()) {

        if (competence.isNull() || competence.isEmpty()) {
            startY += 0;
        } else {
            // Dessiner le nom de la compétence
            painter.drawText(startX, startY, competence);

            // Dessiner la barre de progression
            int niveau = competences.value(competence);
            QRect barRect(startX, startY + 5, niveau * barWidth / 100, barHeight);
            painter.fillRect(barRect, primaryColorCV); // Vous pouvez ajuster la couleur de la barre ici

            // Mettre à jour la position Y pour la prochaine compétence
            startY += barHeight + barMargin;
        }
    }

    // Partie description de la personne
    painter.drawEllipse(590, 650, 20, 20);

    painter.setFont(fontSubTitle);
    painter.setPen(textColorInfos);
    painter.drawText(positionCompetenceX, positionCompetenceY, "Compétences");


    // Partie loisirs
    painter.drawEllipse(590, 1100, 20, 20);

    painter.setFont(fontSubTitle);
    painter.setPen(textColorInfos);
    painter.drawText(positionLoisirX, positionLoisirY, "Loisirs");

    QString loisir1 = ui->textEditActivite->toPlainText();
    if (ui->checkBoxActivite->isChecked()) {
        loisir1 = NULL;
    }

    QString loisir2 = ui->textEditActivite_2->toPlainText();
    if (ui->checkBoxActivite_2->isChecked()) {
        loisir2 = NULL;
    }

    QString loisir3 = ui->textEditActivite_3->toPlainText();
    if (ui->checkBoxActivite_3->isChecked()) {
        loisir3 = NULL;
    }

    // définition de la liste des informations personnelles
    QStringList loisirs;
    loisirs << loisir1 << loisir2 << loisir3;

    // Position intiale des informations
    int yInitPosLoi = positionLoisirY + 50;
    painter.setFont(fontSubTitleList);

    foreach (const QString &loisir, loisirs) {
        if (loisir.isNull() || loisir.isEmpty()) {
            yInitPosLoi += 0;
        }

        painter.drawText(positionLoisirX, yInitPosLoi, loisir);
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


void CvEditor::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageSkills);
}


void CvEditor::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageActivity);
}


void CvEditor::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageTemplate);
}


void CvEditor::on_pushButton_13_clicked()
{



    if (m_dragdroplabel1->pixmap().toImage() == m_dragdroplabelresult1->pixmap().toImage())
    {
        positionDescription = 1;
    }
    else if (m_dragdroplabel1->pixmap().toImage() == m_dragdroplabelresult2->pixmap().toImage())
    {
        positionDescription = 2;
    }
    else if (m_dragdroplabel1->pixmap().toImage() == m_dragdroplabelresult3->pixmap().toImage())
    {
        positionDescription = 3;
    }
    else if (m_dragdroplabel1->pixmap().toImage() == m_dragdroplabelresult4->pixmap().toImage())
    {
        positionDescription = 4;
    }
    else if (m_dragdroplabel1->pixmap().toImage() == m_dragdroplabelresult5->pixmap().toImage())
    {
        positionDescription = 5;
    }
    else if (m_dragdroplabel1->pixmap().toImage() == m_dragdroplabelresult6->pixmap().toImage())
    {
        positionDescription = 6;
    }

    if (m_dragdroplabel2->pixmap().toImage() == m_dragdroplabelresult1->pixmap().toImage())
    {
        positionFormation = 1;
    }
    else if (m_dragdroplabel2->pixmap().toImage() == m_dragdroplabelresult2->pixmap().toImage())
    {
        positionFormation = 2;
    }
    else if (m_dragdroplabel2->pixmap().toImage() == m_dragdroplabelresult3->pixmap().toImage())
    {
        positionFormation = 3;
    }
    else if (m_dragdroplabel2->pixmap().toImage() == m_dragdroplabelresult4->pixmap().toImage())
    {
        positionFormation = 4;
    }
    else if (m_dragdroplabel2->pixmap().toImage() == m_dragdroplabelresult5->pixmap().toImage())
    {
        positionFormation = 5;
    }
    else if (m_dragdroplabel2->pixmap().toImage() == m_dragdroplabelresult6->pixmap().toImage())
    {
        positionFormation = 6;
    }

    // Pour m_dragdroplabel3
    if (m_dragdroplabel3->pixmap().toImage() == m_dragdroplabelresult1->pixmap().toImage())
    {
        positionExperience = 1;
    }
    else if (m_dragdroplabel3->pixmap().toImage() == m_dragdroplabelresult2->pixmap().toImage())
    {
        positionExperience = 2;
    }
    else if (m_dragdroplabel3->pixmap().toImage() == m_dragdroplabelresult3->pixmap().toImage())
    {
        positionExperience = 3;
    }
    else if (m_dragdroplabel3->pixmap().toImage() == m_dragdroplabelresult4->pixmap().toImage())
    {
        positionExperience = 4;
    }
    else if (m_dragdroplabel3->pixmap().toImage() == m_dragdroplabelresult5->pixmap().toImage())
    {
        positionExperience = 5;
    }
    else if (m_dragdroplabel3->pixmap().toImage() == m_dragdroplabelresult6->pixmap().toImage())
    {
        positionExperience = 6;
    }

    // Pour m_dragdroplabel4
    if (m_dragdroplabel4->pixmap().toImage() == m_dragdroplabelresult1->pixmap().toImage())
    {
        positionInfoPerso = 1;
    }
    else if (m_dragdroplabel4->pixmap().toImage() == m_dragdroplabelresult2->pixmap().toImage())
    {
        positionInfoPerso = 2;
    }
    else if (m_dragdroplabel4->pixmap().toImage() == m_dragdroplabelresult3->pixmap().toImage())
    {
        positionInfoPerso = 3;
    }
    else if (m_dragdroplabel4->pixmap().toImage() == m_dragdroplabelresult4->pixmap().toImage())
    {
        positionInfoPerso = 4;
    }
    else if (m_dragdroplabel4->pixmap().toImage() == m_dragdroplabelresult5->pixmap().toImage())
    {
        positionInfoPerso = 5;
    }
    else if (m_dragdroplabel4->pixmap().toImage() == m_dragdroplabelresult6->pixmap().toImage())
    {
        positionInfoPerso = 6;
    }

    // Pour m_dragdroplabel5
    if (m_dragdroplabel5->pixmap().toImage() == m_dragdroplabelresult1->pixmap().toImage())
    {
        positionCompetence = 1;
    }
    else if (m_dragdroplabel5->pixmap().toImage() == m_dragdroplabelresult2->pixmap().toImage())
    {
        positionCompetence = 2;
    }
    else if (m_dragdroplabel5->pixmap().toImage() == m_dragdroplabelresult3->pixmap().toImage())
    {
        positionCompetence = 3;
    }
    else if (m_dragdroplabel5->pixmap().toImage() == m_dragdroplabelresult4->pixmap().toImage())
    {
        positionCompetence = 4;
    }
    else if (m_dragdroplabel5->pixmap().toImage() == m_dragdroplabelresult5->pixmap().toImage())
    {
        positionCompetence = 5;
    }
    else if (m_dragdroplabel5->pixmap().toImage() == m_dragdroplabelresult6->pixmap().toImage())
    {
        positionCompetence = 6;
    }

    // Pour m_dragdroplabel6
    if (m_dragdroplabel6->pixmap().toImage() == m_dragdroplabelresult1->pixmap().toImage())
    {
        positionLoisir = 1;
    }
    else if (m_dragdroplabel6->pixmap().toImage() == m_dragdroplabelresult2->pixmap().toImage())
    {
        positionLoisir = 2;
    }
    else if (m_dragdroplabel6->pixmap().toImage() == m_dragdroplabelresult3->pixmap().toImage())
    {
        positionLoisir = 3;
    }
    else if (m_dragdroplabel6->pixmap().toImage() == m_dragdroplabelresult4->pixmap().toImage())
    {
        positionLoisir = 4;
    }
    else if (m_dragdroplabel6->pixmap().toImage() == m_dragdroplabelresult5->pixmap().toImage())
    {
        positionLoisir = 5;
    }
    else if (m_dragdroplabel6->pixmap().toImage() == m_dragdroplabelresult6->pixmap().toImage())
    {
        positionLoisir = 6;
    }


    qInfo() << "DESCRIPTION EST EN POSITION " << positionDescription
            << "FORMATION EST EN POSITION " << positionFormation
            << "EXPERIENCE EST EN POSITION " << positionExperience
            << "INFOPERSO EST EN POSITION " << positionInfoPerso
            << "COMPETENCE EST EN POSITION " << positionCompetence
            << "Loisir EST EN POSITION " << positionLoisir
        ;



}

