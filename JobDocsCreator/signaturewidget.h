#ifndef SIGNATUREWIDGET_H
#define SIGNATUREWIDGET_H

#include <QWidget>
#include <QPixmap>

class SignatureWidget : public QWidget {
    Q_OBJECT
public:
    explicit SignatureWidget(QWidget *parent = nullptr);
    QPixmap getSignature() const;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap signature;
    QPoint lastPoint;
};

#endif // SIGNATUREWIDGET_H
