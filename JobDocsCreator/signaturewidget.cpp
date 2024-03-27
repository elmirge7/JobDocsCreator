#include "signaturewidget.h"
#include <QMouseEvent>
#include <QPainter>

SignatureWidget::SignatureWidget(QWidget *parent) : QWidget(parent) {
    setFixedSize(300, 150);
    setStyleSheet("border: 1px solid black;");
    signature = QPixmap(size());
    signature.fill(Qt::white); // Remplit la signature avec un fond blanc au début
}

QPixmap SignatureWidget::getSignature() const {
    return signature;
}

void SignatureWidget::mousePressEvent(QMouseEvent *event) {
    lastPoint = event->pos();
}

void SignatureWidget::mouseMoveEvent(QMouseEvent *event) {
    if (!lastPoint.isNull()) {
        QPainter painter(&signature);
        painter.setPen(Qt::black); // Couleur du crayon
        painter.drawLine(lastPoint, event->pos());
        lastPoint = event->pos();
        update();
    }
}

void SignatureWidget::mouseReleaseEvent(QMouseEvent *event) {
    lastPoint = QPoint();
}

void SignatureWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, signature);
}
