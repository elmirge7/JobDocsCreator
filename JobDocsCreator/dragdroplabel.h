#ifndef DRAGDROPLABEL_H
#define DRAGDROPLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class DragDropLabel: public QLabel
{
public:
    DragDropLabel();
    DragDropLabel(bool dragValue, bool dropValue);
    void setAcceptDrag(bool value);
    void setAcceptDrop(bool value);
    bool getAcceptDrag(void);
    bool getAcceptDrop(void);
    QString imageName; // récupérer le nom de l'image

    QImage imageStart;
    QImage imageResult;

    QPixmap start;
    QPixmap result;

    
protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    bool m_acceptDrag;
    bool m_acceptDrop;

};

#endif // DRAGDROPLABEL_H
