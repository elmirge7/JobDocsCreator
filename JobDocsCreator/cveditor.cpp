#include "cveditor.h"
#include "ui_cveditor.h"

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
