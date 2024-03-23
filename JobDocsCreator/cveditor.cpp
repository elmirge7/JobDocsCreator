#include "cveditor.h"
#include "ui_cveditor.h"
#include "dragdroplabel.h"

#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFontDialog>

CvEditor::CvEditor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CvEditor)
{
    ui->setupUi(this);

    // Style de la page d'introduction

    // Style pour le fond de la fenêtre
    this->setStyleSheet("background-color: #10002b; color: #FEFEFE;");

    // Style pour le fond des pages du stacked widget
    ui->stackedWidget->setStyleSheet("background-color: #10002b; color: #FEFEFE; font-family:'Poppins', sans-serif;");

    // Style pour le texte d'introduction
    ui->label->setStyleSheet("color: #FEFEFE; font-size: 18px;");

    // Style pour le bouton "Continuer"
    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #5a189a;"
        "   border: 1px solid #FEFEFE;"
        "   color: #FEFEFE;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );

    // Page choix des couleurs :

    // Style pour le texte d'introduction de la deuxième page
    ui->label_2->setStyleSheet("color: #FEFEFE; font-size: 18px;");

    // Style pour les boutons de choix de couleur
    QStringList buttonNames = {"buttonChoiceColor", "buttonChoiceColorName", "buttonChoiceColorJob", "buttonChoiceColorInfos", "buttonChoiceFont"};
    for (const auto& buttonName : buttonNames) {
        QPushButton *button = findChild<QPushButton*>(buttonName);
        if (button)
            button->setStyleSheet(
                "QPushButton {"
                "   background-color: #7b2cbf;"
                "   border: 1px solid #7b2cbf;"
                "   color: #FEFEFE;"
                "   border-radius: 5px;"
                "}"
                "QPushButton:hover {"
                "   background-color: #9d4edd;"
                "}"
                );
    }

    ui->pushButton_2->setStyleSheet(
        "QPushButton {"
        "   background-color: #5a189a;"
        "   border: 1px solid #FEFEFE;"
        "   color: #FEFEFE;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );

    ui->pushButton_3->setStyleSheet(
        "QPushButton {"
        "   background-color: #5a189a;"
        "   border: 1px solid #FEFEFE;"
        "   color: #FEFEFE;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );

    ui->label_58->setStyleSheet("color: #FEFEFE; font-size: 18px;");

    // Style pour la troisième page
    ui->label_4->setStyleSheet("color: #FEFEFE; font-size: 18px;");
    ui->label_5->setStyleSheet("color: #FEFEFE;");
    ui->label_6->setStyleSheet("color: #FEFEFE;");

    // Style pour les champs de texte
    QStringList textEditNames = {"nameText", "surnameText"};
    for (const auto& textEditName : textEditNames) {
        QTextEdit *textEdit = findChild<QTextEdit*>(textEditName);
        if (textEdit)
            textEdit->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    }

    // Style pour le bouton "Continuer"
    ui->pushButton_4->setStyleSheet(
        "QPushButton {"
        "   background-color: #5a189a;"
        "   border: 1px solid #FEFEFE;"
        "   color: #FEFEFE;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );

    // Style pour la page relative à la photo
    ui->label_59->setStyleSheet("color: #FEFEFE; font-size: 18px;");
    ui->labelPhoto->setStyleSheet("color: #FEFEFE; font-size: 16px;");
    ui->pushButton_5->setStyleSheet(
        "QPushButton {"
        "   background-color: #5a189a;"
        "   border: 1px solid #FEFEFE;"
        "   color: #FEFEFE;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );
    ui->pushButton_14->setStyleSheet(
        "QPushButton {"
        "   background-color: #5a189a;"
        "   border: 1px solid #FEFEFE;"
        "   color: #FEFEFE;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );

    // Style pour la page relative au métier recherché
    ui->label_7->setStyleSheet("color: #FEFEFE;");
    ui->jobEdit->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->pushButton_6->setStyleSheet(
        "QPushButton {"
        "   background-color: #5a189a;"
        "   border: 1px solid #FEFEFE;"
        "   color: #FEFEFE;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );
    ui->label_60->setStyleSheet("color: #FEFEFE; font-size: 16px;");

    // Style pour la page de description
    ui->label_8->setStyleSheet("color: #FEFEFE;");
    ui->textEditDesc->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->pushButton_7->setStyleSheet(
        "QPushButton {"
        "   background-color: #5a189a;"
        "   border: 1px solid #FEFEFE;"
        "   color: #FEFEFE;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );
    ui->label_61->setStyleSheet("color: #FEFEFE; font-size: 16px;");

    // Style pour la page de formations
    ui->label_10->setStyleSheet("color: #FEFEFE; font-size: 16px;");
    ui->label_12->setStyleSheet("color: #FEFEFE;");
    ui->label_13->setStyleSheet("color: #FEFEFE;");
    ui->label_14->setStyleSheet("color: #FEFEFE;");
    ui->label_15->setStyleSheet("color: #FEFEFE;");
    ui->label_16->setStyleSheet("color: #FEFEFE;");
    ui->label_17->setStyleSheet("color: #FEFEFE;");
    ui->label_18->setStyleSheet("color: #FEFEFE;");
    ui->label_19->setStyleSheet("color: #FEFEFE;");
    ui->label_20->setStyleSheet("color: #FEFEFE;");
    ui->label_21->setStyleSheet("color: #FEFEFE;");
    ui->label_22->setStyleSheet("color: #FEFEFE;");
    ui->label_23->setStyleSheet("color: #FEFEFE;");

    ui->textEditNomDiplome->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditLieuDiplome->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditDescDiplome->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->dateEditDiplome->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditNomDiplome_2->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditLieuDiplome_2->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditDescDiplome_2->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->dateEditDiplome_2->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditNomDiplome_3->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditLieuDiplome_3->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditDescDiplome_3->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->dateEditDiplome_3->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");

    ui->pushButton_8->setStyleSheet(
        "QPushButton {"
        "   background-color: #5a189a;"
        "   border: 1px solid #FEFEFE;"
        "   color: #FEFEFE;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );


    // Style pour la page des expériences
    ui->label_25->setStyleSheet("color: #FEFEFE;");
    ui->label_26->setStyleSheet("color: #FEFEFE;");
    ui->label_27->setStyleSheet("color: #FEFEFE;");
    ui->label_28->setStyleSheet("color: #FEFEFE;");
    ui->label_29->setStyleSheet("color: #FEFEFE;");
    ui->label_30->setStyleSheet("color: #FEFEFE;");
    ui->label_31->setStyleSheet("color: #FEFEFE;");
    ui->label_32->setStyleSheet("color: #FEFEFE;");
    ui->label_33->setStyleSheet("color: #FEFEFE;");
    ui->label_34->setStyleSheet("color: #FEFEFE;");
    ui->label_35->setStyleSheet("color: #FEFEFE;");
    ui->label_36->setStyleSheet("color: #FEFEFE;");
    ui->label_37->setStyleSheet("color: #FEFEFE;");
    ui->label_38->setStyleSheet("color: #FEFEFE;");
    ui->label_39->setStyleSheet("color: #FEFEFE;");
    ui->label_40->setStyleSheet("color: #FEFEFE; font-size: 16px;");

    ui->textEditDescExperience->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditNomExperience->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditLieuExperience->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->dateEditExperienceStart->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->dateEditExperienceEnd->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditNomExperience_2->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditLieuExperience_2->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditDescExperience_2->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->dateEditExperienceStart_2->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->dateEditExperienceEnd_2->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditNomExperience_3->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditLieuExperience_3->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditDescExperience_3->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->dateEditExperienceStart_3->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->dateEditExperienceEnd_3->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");

    ui->pushButton_9->setStyleSheet(
        "QPushButton {"
        "   background-color: #5a189a;"
        "   border: 1px solid #FEFEFE;"
        "   color: #FEFEFE;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );


    // Style pour la page des informations personnelles
    ui->label_42->setStyleSheet("color: #FEFEFE; font-size: 16px;");
    ui->label_43->setStyleSheet("color: #FEFEFE;");
    ui->label_44->setStyleSheet("color: #FEFEFE;");
    ui->label_45->setStyleSheet("color: #FEFEFE;");
    ui->label_46->setStyleSheet("color: #FEFEFE;");
    ui->checkBoxAge->setStyleSheet("color: #FEFEFE;");
    ui->checkBoxPhoneNumber->setStyleSheet("color: #FEFEFE;");
    ui->checkBoxMail->setStyleSheet("color: #FEFEFE;");
    ui->checkBoxWebsite->setStyleSheet("color: #FEFEFE;");
    ui->textEditAge->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditPhoneNumber->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditMail->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditWebsite->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->pushButton_10->setStyleSheet(
        "QPushButton {"
        "   background-color: #5a189a;"
        "   border: 1px solid #FEFEFE;"
        "   color: #FEFEFE;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );

    // Style pour la page des compétences
    ui->label_47->setStyleSheet(
        "QLabel {"
        "   color: #333333;"
        "   font-size: 20px;"
        "   font-weight: bold;"
        "}"
        );
    ui->label_48->setStyleSheet("QLabel { color: #333333; }");
    ui->label_49->setStyleSheet("QLabel { color: #333333; }");
    ui->label_50->setStyleSheet("QLabel { color: #333333; }");
    ui->label_51->setStyleSheet("QLabel { color: #333333; }");
    ui->label_52->setStyleSheet("QLabel { color: #333333; }");
    ui->label_53->setStyleSheet("QLabel { color: #333333; }");
    ui->textEditCompetence->setStyleSheet(
        "QTextEdit {"
        "   color: #333333;"
        "   background-color: #F5F5F5;"
        "   border: 1px solid #BDBDBD;"
        "}"
        );
    ui->textEditCompetence_2->setStyleSheet(
        "QTextEdit {"
        "   color: #333333;"
        "   background-color: #F5F5F5;"
        "   border: 1px solid #BDBDBD;"
        "}"
        );
    ui->textEditCompetence_3->setStyleSheet(
        "QTextEdit {"
        "   color: #333333;"
        "   background-color: #F5F5F5;"
        "   border: 1px solid #BDBDBD;"
        "}"
        );
    ui->textEditCompetence_4->setStyleSheet(
        "QTextEdit {"
        "   color: #333333;"
        "   background-color: #F5F5F5;"
        "   border: 1px solid #BDBDBD;"
        "}"
        );
    ui->textEditCompetence_5->setStyleSheet(
        "QTextEdit {"
        "   color: #333333;"
        "   background-color: #F5F5F5;"
        "   border: 1px solid #BDBDBD;"
        "}"
        );
    ui->textEditCompetence_6->setStyleSheet(
        "QTextEdit {"
        "   color: #333333;"
        "   background-color: #F5F5F5;"
        "   border: 1px solid #BDBDBD;"
        "}"
        );
    ui->spinBoxCompetence->setStyleSheet("QSpinBox { color: #333333; }");
    ui->spinBoxCompetence_2->setStyleSheet("QSpinBox { color: #333333; }");
    ui->spinBoxCompetence_3->setStyleSheet("QSpinBox { color: #333333; }");
    ui->spinBoxCompetence_4->setStyleSheet("QSpinBox { color: #333333; }");
    ui->spinBoxCompetence_5->setStyleSheet("QSpinBox { color: #333333; }");
    ui->spinBoxCompetence_6->setStyleSheet("QSpinBox { color: #333333; }");
    ui->checkBoxCompetence->setStyleSheet("QCheckBox { color: #333333; }");
    ui->checkBoxCompetence_2->setStyleSheet("QCheckBox { color: #333333; }");
    ui->checkBoxCompetence_3->setStyleSheet("QCheckBox { color: #333333; }");
    ui->checkBoxCompetence_4->setStyleSheet("QCheckBox { color: #333333; }");
    ui->checkBoxCompetence_5->setStyleSheet("QCheckBox { color: #333333; }");
    ui->checkBoxCompetence_6->setStyleSheet("QCheckBox { color: #333333; }");
    ui->pushButton_11->setStyleSheet(
        "QPushButton {"
        "   background-color: #5a189a;"
        "   border: 1px solid #FEFEFE;"
        "   color: #FEFEFE;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );
    ui->label_62->setStyleSheet("QLabel { color: #FEFEFE; }");
    ui->label_63->setStyleSheet("QLabel { color: #FEFEFE; }");
    ui->label_64->setStyleSheet("QLabel { color: #FEFEFE; }");
    ui->label_65->setStyleSheet("QLabel { color: #FEFEFE; }");
    ui->label_66->setStyleSheet("QLabel { color: #FEFEFE; }");
    ui->label_67->setStyleSheet("QLabel { color: #FEFEFE; }");

    // Style pour la page des compétences
    ui->label_47->setStyleSheet("color: #FEFEFE; font-size: 16px;"); // Titre centré
    ui->label_48->setStyleSheet("color: #FEFEFE;");
    ui->label_49->setStyleSheet("color: #FEFEFE;");
    ui->label_50->setStyleSheet("color: #FEFEFE;");
    ui->label_51->setStyleSheet("color: #FEFEFE;");
    ui->label_52->setStyleSheet("color: #FEFEFE;");
    ui->label_53->setStyleSheet("color: #FEFEFE;");
    ui->textEditCompetence->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditCompetence_2->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditCompetence_3->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditCompetence_4->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditCompetence_5->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditCompetence_6->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->spinBoxCompetence->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->spinBoxCompetence_2->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->spinBoxCompetence_3->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->spinBoxCompetence_4->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->spinBoxCompetence_5->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->spinBoxCompetence_6->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->checkBoxCompetence->setStyleSheet("color: #FEFEFE;");
    ui->checkBoxCompetence_2->setStyleSheet("color: #FEFEFE;");
    ui->checkBoxCompetence_3->setStyleSheet("color: #FEFEFE;");
    ui->checkBoxCompetence_4->setStyleSheet("color: #FEFEFE;");
    ui->checkBoxCompetence_5->setStyleSheet("color: #FEFEFE;");
    ui->checkBoxCompetence_6->setStyleSheet("color: #FEFEFE;");
    ui->pushButton_11->setStyleSheet(
        "QPushButton {"
        "   background-color: #5a189a;"
        "   border: 1px solid #FEFEFE;"
        "   color: #FEFEFE;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );

    // Style pour la page des activités
    ui->label_54->setStyleSheet("color: #FEFEFE; font-size: 16px;"); // Titre centré
    ui->label_55->setStyleSheet("color: #FEFEFE;");
    ui->label_56->setStyleSheet("color: #FEFEFE;");
    ui->label_57->setStyleSheet("color: #FEFEFE;");
    ui->textEditActivite->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditActivite_2->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->textEditActivite_3->setStyleSheet("color: #FEFEFE; background-color: #7b2cbf;");
    ui->checkBoxActivite->setStyleSheet("color: #FEFEFE;");
    ui->checkBoxActivite_2->setStyleSheet("color: #FEFEFE;");
    ui->checkBoxActivite_3->setStyleSheet("color: #FEFEFE;");
    ui->pushButton_12->setStyleSheet(
        "QPushButton {"
        "   background-color: #5a189a;"
        "   border: 1px solid #FEFEFE;"
        "   color: #FEFEFE;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7b2cbf;"
        "}"
        );



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


    // Création des layouts pour les zones gauche et droite
    QHBoxLayout *mainLayout = new QHBoxLayout;
    QVBoxLayout *leftLayout = new QVBoxLayout;
    QGridLayout *rightLayout = new QGridLayout;

    // Ajout des DragDropLabel à la zone gauche
    leftLayout->addWidget(m_dragdroplabel1);
    leftLayout->addWidget(m_dragdroplabel2);
    leftLayout->addWidget(m_dragdroplabel3);
    leftLayout->addWidget(m_dragdroplabel4);
    leftLayout->addWidget(m_dragdroplabel5);
    leftLayout->addWidget(m_dragdroplabel6);

    // Ajout des DragDropLabelResult à la zone droite
    rightLayout->addWidget(m_dragdroplabelresult1, 0, 0);
    rightLayout->addWidget(m_dragdroplabelresult2, 0, 1);
    rightLayout->addWidget(m_dragdroplabelresult3, 1, 0);
    rightLayout->addWidget(m_dragdroplabelresult4, 1, 1);
    rightLayout->addWidget(m_dragdroplabelresult5, 2, 0);
    rightLayout->addWidget(m_dragdroplabelresult6, 2, 1);

    // Ajout des espacements entre les éléments
    leftLayout->addStretch(1);
    rightLayout->setRowStretch(3, 1); // Espacement pour la troisième ligne

    // Ajout des layouts gauche et droite au layout principal
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    // Configuration du layout de la page
    int pageIndex = ui->stackedWidget->indexOf(ui->pageTemplate);
    if (pageIndex != -1) {
        QWidget *page = ui->stackedWidget->widget(pageIndex);
        page->setLayout(mainLayout);
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
        positionDescX = 130;
        positionDescY = 370;
        break;
    case 2:
        positionDescX = 580;
        positionDescY = 370;
        break;
    case 3:
        positionDescX = 130;
        positionDescY = 750;
        break;
    case 4:
        positionDescX = 580;
        positionDescY = 750;
        break;
    case 5:
        positionDescX = 130;
        positionDescY = 1130;
        break;
    case 6:
        positionDescX = 580;
        positionDescY = 1130;
        break;
    default:
        positionDescX = 9999;
        positionDescY = 9999;
        break;
    }

    switch (positionFormation) {
    case 1:
        positionFormationX = 130;
        positionFormationY = 370;
        break;
    case 2:
        positionFormationX = 580;
        positionFormationY = 370;
        break;
    case 3:
        positionFormationX = 130;
        positionFormationY = 750;
        break;
    case 4:
        positionFormationX = 580;
        positionFormationY = 750;
        break;
    case 5:
        positionFormationX = 130;
        positionFormationY = 1130;
        break;
    case 6:
        positionFormationX = 580;
        positionFormationY = 1130;
        break;
    default:
        positionFormationX = 9999;
        positionFormationY = 9999;
        break;
    }

    switch (positionExperience) {
    case 1:
        positionExperienceX = 130;
        positionExperienceY = 370;
        break;
    case 2:
        positionExperienceX = 580;
        positionExperienceY = 370;
        break;
    case 3:
        positionExperienceX = 130;
        positionExperienceY = 750;
        break;
    case 4:
        positionExperienceX = 580;
        positionExperienceY = 750;
        break;
    case 5:
        positionExperienceX = 130;
        positionExperienceY = 1130;
        break;
    case 6:
        positionExperienceX = 580;
        positionExperienceY = 1130;
        break;
    default:
        positionExperienceX = 9999;
        positionExperienceY = 9999;
        break;
    }

    switch (positionInfoPerso) {
    case 1:
        positionInfoPersoX = 130;
        positionInfoPersoY = 370;
        break;
    case 2:
        positionInfoPersoX = 580;
        positionInfoPersoY = 370;
        break;
    case 3:
        positionInfoPersoX = 130;
        positionInfoPersoY = 750;
        break;
    case 4:
        positionInfoPersoX = 580;
        positionInfoPersoY = 750;
        break;
    case 5:
        positionInfoPersoX = 130;
        positionInfoPersoY = 1130;
        break;
    case 6:
        positionInfoPersoX = 580;
        positionInfoPersoY = 1130;
        break;
    default:
        positionInfoPersoX = 9999;
        positionInfoPersoY = 9999;
        break;
    }

    switch (positionCompetence) {
    case 1:
        positionCompetenceX = 130;
        positionCompetenceY = 370;
        break;
    case 2:
        positionCompetenceX = 580;
        positionCompetenceY = 370;
        break;
    case 3:
        positionCompetenceX = 130;
        positionCompetenceY = 750;
        break;
    case 4:
        positionCompetenceX = 580;
        positionCompetenceY = 750;
        break;
    case 5:
        positionCompetenceX = 130;
        positionCompetenceY = 1130;
        break;
    case 6:
        positionCompetenceX = 580;
        positionCompetenceY = 1130;
        break;
    default:
        positionCompetenceX = 9999;
        positionCompetenceY = 9999;
        break;
    }

    switch (positionLoisir) {
    case 1:
        positionLoisirX = 130;
        positionLoisirY = 370;
        break;
    case 2:
        positionLoisirX = 580;
        positionLoisirY = 370;
        break;
    case 3:
        positionLoisirX = 130;
        positionLoisirY = 750;
        break;
    case 4:
        positionLoisirX = 580;
        positionLoisirY = 750;
        break;
    case 5:
        positionLoisirX = 130;
        positionLoisirY = 1130;
        break;
    case 6:
        positionLoisirX = 580;
        positionLoisirY = 1130;
        break;
    default:
        positionLoisirX = 9999;
        positionLoisirY = 9999;
        break;
    }

    // Création de l'en-tête

    // Rectangle en fond
    painter.setBrush(primaryColorCV);
    painter.setPen(primaryColorCV);
    painter.drawRect(5, 0, 950, 300);

    // Création du texte prenom nom
    // définition de la police
    QFont fontName (textFont, 40);
    painter.setFont(fontName);

    painter.setPen(textColorName);
    painter.drawText(300, 150, ui->nameText->toPlainText() + " " + ui->surnameText->toPlainText());


    // Ajout de la photo téléchargée par l'utilisateur
    QPixmap photo = ui->labelPhoto->pixmap(); // Récupérer la photo téléchargée depuis le label

    if (!photo.isNull()) {
        // Définir la position et la taille de l'image dans le PDF
        int photoWidth = 200;
        int photoHeight = 200;
        int photoX = 75; // Position X où placer la photo
        int photoY = 50; // Position Y où placer la photo

        // Dessiner l'image dans le fichier PDF
        painter.drawPixmap(photoX, photoY, photoWidth, photoHeight, photo);
    }

    // création du métier recherche
    QFont fontJob (textFont, 20);
    painter.setFont(fontJob);
    painter.setPen(textColorJob);
    painter.drawText(300, 200, ui->jobEdit->toPlainText());


    painter.setPen(primaryColorCV);
    painter.drawLine(100,300, 100, 1500);
    painter.drawLine(550,300, 550, 1500);

    painter.setBrush(primaryColorCV);
    // Partie description de la personne
    painter.drawEllipse(90, 350, 20, 20);

    int maxWidthDesc = 400;

    painter.setPen(textColorInfos);
    QFont fontSubTitle (textFont, 14);
    QFont fontDesc (textFont, 12);
    fontSubTitle.setCapitalization(QFont::AllUppercase);;

    painter.setFont(fontSubTitle);

    painter.drawText(positionDescX, positionDescY, "Description");
    painter.setFont(fontDesc);
    painter.setPen(textColorInfos);
    QRect textRect(positionDescX, positionDescY + 10, maxWidthDesc, 200);
    painter.drawText(textRect, Qt::TextWordWrap, ui->textEditDesc->toPlainText());


    // partie formation
    painter.setPen(primaryColorCV);
    painter.drawEllipse(90, 730, 20, 20);
    painter.setPen(textColorInfos);
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
    formations << formationA << formationB;

    // Position intiale des foramtions
    int yInitPosForm = positionFormationY + 50;
    int yInitPosLineForm = yInitPosForm + 25;
    QFont fontSubTitleList (textFont, 12);
    painter.setFont(fontSubTitleList);

    foreach (const QString &formation, formations) {
        QStringList lines = formation.split("\n");
        foreach (const QString &line, lines) {
            painter.drawText(positionFormationX, yInitPosLineForm, line);
            yInitPosLineForm += 25;
        }
        yInitPosForm = yInitPosForm + yInitPosLineForm + 100;

    }

    // partie expériences
    painter.setPen(primaryColorCV);
    painter.drawEllipse(90, 1110, 20, 20);
    painter.setPen(textColorInfos);

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

    // QString experienceC = ui->textEditNomExperience_3->toPlainText() + "\n" +
    //                       ui->textEditLieuExperience_3->toPlainText() + "\n" +
    //                       ui->dateEditExperienceStart_3->text() + "\n" +
    //                       ui->dateEditExperienceEnd_3->text() + "\n" +
    //                       ui->textEditDescExperience_3->toPlainText();


    // définition de la liste des expériences
    QStringList experiences;
    experiences << experienceA << experienceB;

    // Position intiale des foramtions
    int yInitPosExp = positionExperienceY + 50;
    int yInitPosLineExp = yInitPosExp + 25;
    painter.setFont(fontSubTitleList);

    foreach (const QString &experience, experiences) {
        QStringList lines = experience.split("\n");
        foreach (const QString &line, lines) {
            painter.drawText(positionExperienceX, yInitPosLineExp, line);
            yInitPosLineExp += 25;
        }
        yInitPosExp += 50;
    }

    // Partie informations perso de la personne
    painter.setPen(primaryColorCV);

    painter.drawEllipse(540, 350, 20, 20);

    painter.setPen(textColorJob);
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
    // competences.insert(competence4, levelComp4);
    // competences.insert(competence5, levelComp5);
    // competences.insert(competence6, levelComp6);

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

    painter.setPen(primaryColorCV);

    painter.drawEllipse(540, 730, 20, 20);
    painter.setPen(textColorInfos);

    painter.setFont(fontSubTitle);
    painter.setPen(textColorInfos);
    painter.drawText(positionCompetenceX, positionCompetenceY, "Compétences");


    // Partie loisirs
    painter.setPen(primaryColorCV);

    painter.drawEllipse(540, 1110, 20, 20);
    painter.setPen(textColorJob);

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
    ui->stackedWidget->setCurrentWidget(ui->pagePhoto);
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

    ui->stackedWidget->setCurrentWidget(ui->pagePrint);


}


void CvEditor::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_7);
}

