#ifndef PAINTERWIDGET_H
#define PAINTERWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class SignatureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SignatureWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    bool painting;
    QPoint lastPoint;
    QPixmap pixmap;
    QPainter painter;
};

#endif // PAINTERWIDGET_H
