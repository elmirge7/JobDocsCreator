#ifndef CVEDITOR_H
#define CVEDITOR_H

#include <QDialog>

namespace Ui {
class CvEditor;
}

class CvEditor : public QDialog
{
    Q_OBJECT

public:
    explicit CvEditor(QWidget *parent = nullptr);
    ~CvEditor();

private:
    Ui::CvEditor *ui;
};

#endif // CVEDITOR_H
