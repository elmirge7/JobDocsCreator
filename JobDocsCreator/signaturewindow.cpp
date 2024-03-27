#include "qevent.h"
#include <QPainter>
#include <QEvent>
#include "signaturewindow.h"

SignatureWidget::SignatureWidget(QWidget *parent) : QWidget(parent), painting(false)
{
    setAttribute(Qt::WA_StaticContents);
    pixmap = QPixmap(size());

    pixmap.fill(Qt::white); // Remplir le pixmap avec une couleur de fond blanc
}

void SignatureWidget::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    QRect dirtyRect = event->rect();
    paint.drawPixmap(dirtyRect, pixmap, dirtyRect);
}

void SignatureWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        painting = true;
    }
}

void SignatureWidget::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && painting) {
        QPainter paint(&pixmap);
        paint.setPen(Qt::black);
        paint.drawLine(lastPoint, event->pos());
        lastPoint = event->pos();
        update();
    }
}

void SignatureWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && painting) {
        QPainter paint(&pixmap);
        paint.setPen(Qt::black);
        paint.drawLine(lastPoint, event->pos());
        lastPoint = event->pos();
        painting = false;
        update();
    }
}
