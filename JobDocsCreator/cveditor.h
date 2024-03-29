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

    void on_pushButton_14_clicked();

    void on_backToIntro_clicked();

    void on_backToColor_clicked();

    void on_backToFont_clicked();

    void on_backToFont_2_clicked();

    void on_backToPicture_clicked();

    void on_backToJob_clicked();

    void on_backToDesc_clicked();

    void on_backToFormations_clicked();

    void on_backToExperiences_clicked();

    void on_backToInfoPerso_clicked();

    void on_backToSkills_clicked();

    void onButtonBackClicked();

    void on_imageExport_clicked();

    void onButtonContinueClicked();

private:

    Ui::CvEditor *ui;
    QColor primaryColorCV; // Déclaration de la couleur principale du CV
    QColor textColorName; // Déclaration de la couleur du prénom - nom
    QColor textColorJob; // Déclaration de la couleur du job
    QColor textColorInfos; // Déclaration de la couleur des autres textes du CV
    QString textFont; // Déclaration de la police utilisée dans le CV
    QString jobName; // Déclaration du métier recherché dans le CV
    QString description; // Déclaration de la description dans le CV

    // Pour récupérer les positions dans le template
    int positionDescription;
    int positionFormation;
    int positionExperience;
    int positionInfoPerso;
    int positionCompetence;
    int positionLoisir;

    QImage start1previous;
    QImage start1next;
    QImage start2previous;
    QImage start2next;
    QImage start3previous;
    QImage start3next;
    QImage start4previous;
    QImage start4next;
    QImage start5previous;
    QImage start5next;
    QImage start6previous;
    QImage start6next;

    QImage result1previous;
    QImage result1next;
    QImage result2previous;
    QImage result2next;
    QImage result3previous;
    QImage result3next;
    QImage result4previous;
    QImage result4next;
    QImage result5previous;
    QImage result5next;
    QImage result6previous;
    QImage result6next;

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
