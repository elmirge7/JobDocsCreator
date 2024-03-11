#include "cveditor.h"
#include "ui_cveditor.h"

#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

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
    printer.setPrinterName("Test imprimante");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec() == QDialog::Rejected) return;
    ui->textEdit->print(&printer);
}

