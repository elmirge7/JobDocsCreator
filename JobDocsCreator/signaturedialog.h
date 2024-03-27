#ifndef SIGNATUREDIALOG_H
#define SIGNATUREDIALOG_H

#include "ui_signaturedialog.h"
#include <QDialog>
#include <QImage>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QFileDialog>

class SignatureDialog : public QDialog {
    Q_OBJECT
public:
    explicit SignatureDialog(QWidget *parent = nullptr);

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);

private slots:
    void on_actionSave_triggered();

    void on_actionClear_triggered();

    void on_action3px_triggered();

    void on_action5px_triggered();

    void on_action7px_triggered();

    void on_action9px_triggered();

    void on_actionBlack_triggered();

    void on_actionRed_triggered();

    void on_actionWhite_triggered();

    void on_actionGreen_triggered();

    void on_actionYellow_triggered();

private:
    Ui::SignatureDialog *ui;
    QImage image;
    bool drawing;
    QPoint lastPoint;
    int brushsize;
    QColor brushColor;
};


#endif // SIGNATUREDIALOG_H
