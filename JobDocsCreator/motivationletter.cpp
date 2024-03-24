#include "motivationletter.h"
#include "qpainter.h"
#include "signaturewindow.h"
#include "ui_motivationletter.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextCursor>
#include <QPrinter>
#include <QPainter>

MotivationLetter::MotivationLetter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MotivationLetter)
{
    ui->setupUi(this);

    // Création de l'éditeur de texte pour la lettre de motivation
    setCentralWidget(ui->textEdit); // Définir l'éditeur de texte comme widget central

    // Configurer les options de l'éditeur de texte
    QFont font("Arial", 12); // Police et taille par défaut
    ui->textEdit->setFont(font);

    // Initialiser le contenu de la lettre de motivation
    QString initialText = "Nom : [Votre nom]\n"
                          "Prénom : [Votre prénom]\n"
                          "Adresse e-mail : [Votre adresse e-mail]\n"
                          "Téléphone : [Votre numéro de téléphone]\n\n"
                          "Objet : [Objet de la lettre de motivation]\n\n"
                          "Madame, Monsieur,\n\n"
                          "[Corps de la lettre de motivation]\n\n"
                          "Je vous prie d'agréer, Madame, Monsieur, l'expression de mes salutations distinguées.";
    ui->textEdit->setText(initialText);

    // Connecter des signaux et des slots
    connect(ui->actionSauvegarder, &QAction::triggered, this, &MotivationLetter::saveLetter);
    connect(ui->actionImporter, &QAction::triggered, this, &MotivationLetter::importText);
    connect(ui->actionSoulign, &QAction::triggered, this, &MotivationLetter::setUnderline);
    connect(ui->actionGras, &QAction::triggered, this, &MotivationLetter::setBold);
    connect(ui->actionItalique, &QAction::triggered, this, &MotivationLetter::setItalic);
    connect(ui->actionGauche, &QAction::triggered, this, &MotivationLetter::alignLeft);
    connect(ui->actionDroite, &QAction::triggered, this, &MotivationLetter::alignRight);
    connect(ui->actionCentre, &QAction::triggered, this, &MotivationLetter::alignCenter);
    connect(ui->actionJustifi, &QAction::triggered, this, &MotivationLetter::alignJustify);
    connect(ui->actionExporter_en_PDF, &QAction::triggered, this, &MotivationLetter::exportToPDF);

}

MotivationLetter::~MotivationLetter()
{
    delete ui;
}

void MotivationLetter::saveLetter()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer la lettre"), "", tr("Fichiers texte (*.txt);;Tous les fichiers (*)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Erreur"), tr("Impossible d'enregistrer le fichier."));
        return;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
}

void MotivationLetter::importText()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Importer un fichier texte"), "", tr("Fichiers texte (*.txt);;Tous les fichiers (*)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Erreur"), tr("Impossible d'ouvrir le fichier."));
        return;
    }

    QTextStream in(&file);
    ui->textEdit->setPlainText(in.readAll());
    file.close();
}

void MotivationLetter::setUnderline()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat format;
    format.setFontUnderline(true);
    cursor.mergeCharFormat(format);
    ui->textEdit->setTextCursor(cursor);
}

void MotivationLetter::setBold()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat format;
    format.setFontWeight(QFont::Bold);
    cursor.mergeCharFormat(format);
    ui->textEdit->setTextCursor(cursor);
}

void MotivationLetter::setItalic()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat format;
    format.setFontItalic(true);
    cursor.mergeCharFormat(format);
    ui->textEdit->setTextCursor(cursor);
}

void MotivationLetter::alignLeft()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

void MotivationLetter::alignRight()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}

void MotivationLetter::alignCenter()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

void MotivationLetter::alignJustify()
{
    ui->textEdit->setAlignment(Qt::AlignJustify);
}


// Ajoutez un slot dans la classe MotivationLetter pour gérer l'exportation en PDF :
void MotivationLetter::exportToPDF() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exporter en PDF"), "", tr("Fichiers PDF (*.pdf)"));

    if (fileName.isEmpty())
        return;

    // Création du document PDF
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    // Ouverture du document PDF
    QPainter painter;
    painter.begin(&printer);

    // Dessin du contenu de la lettre de motivation
    QTextDocument doc;
    doc.setPlainText(ui->textEdit->toPlainText());
    doc.drawContents(&painter);


    painter.end();
}

