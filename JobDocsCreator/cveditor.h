#ifndef CVEDITOR_H
#define CVEDITOR_H

#include <QDialog>
#include <QObject>
#include <QLabel>
#include <QGridLayout>
#include "dragdroplabel.h"

namespace Ui {
class CvEditor;
}

class CvEditor : public QDialog
{
    Q_OBJECT

public:
    explicit CvEditor(QWidget *parent = nullptr);
    ~CvEditor();

private slots:
    void on_pdfButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_buttonChoiceColor_clicked();

    void on_buttonChoiceColorName_clicked();

    void on_buttonChoiceColorJob_clicked();

    void on_buttonChoiceColorInfos_clicked();

    void on_buttonChoiceFont_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::CvEditor *ui;
    QColor primaryColorCV; // Déclaration de la couleur principale du CV
    QColor textColorName; // Déclaration de la couleur du prénom - nom
    QColor textColorJob; // Déclaration de la couleur du job
    QColor textColorInfos; // Déclaration de la couleur des autres textes du CV
    QString textFont; // Déclaration de la police utilisée dans le CV
    QString jobName; // Déclaration du métier recherché dans le CV
    QString description; // Déclaration de la description dans le CV

protected:
    QGridLayout *m_layout;
    DragDropLabel *m_dragdroplabel1;
    DragDropLabel *m_dragdroplabel2;
    DragDropLabel *m_dragdroplabel3;
    DragDropLabel *m_dragdroplabel4;
    DragDropLabel *m_dragdroplabel5;
    DragDropLabel *m_dragdroplabel6;
    DragDropLabel *m_dragdroplabelresult1;
    DragDropLabel *m_dragdroplabelresult2;
    DragDropLabel *m_dragdroplabelresult3;
    DragDropLabel *m_dragdroplabelresult4;
    DragDropLabel *m_dragdroplabelresult5;
    DragDropLabel *m_dragdroplabelresult6;

};

#endif // CVEDITOR_H
