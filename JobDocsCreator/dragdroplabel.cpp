#include "dragdroplabel.h"
#include <QtWidgets>

DragDropLabel::DragDropLabel(): QLabel(),
    m_acceptDrag(true),
    m_acceptDrop(true)
{
    setAcceptDrops(true);
}

DragDropLabel::DragDropLabel(bool dragValue, bool dropValue): QLabel(),
    m_acceptDrag(dragValue),
    m_acceptDrop(dropValue)
{
    setAcceptDrops(dropValue);
}

void DragDropLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if (event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else {
            event->acceptProposedAction();
        }
    }
    else {
        event->ignore();
    }
}

void DragDropLabel::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if(event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void DragDropLabel::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        
        QPixmap pixmap;
        QPoint offset;
        
        dataStream >> pixmap >> offset;
        
        this->setPixmap(pixmap);

        qInfo() << "pixmap de dropevent : " << pixmap.toImage();
        imageResult = pixmap.toImage();


        // if (result == start) {
        //     qDebug() << "Le start et le result sont identiques";
        // } else {
        //     qDebug() << "Ils ne le sont pas"
        //              << "Voici start : " << start
        //              << "et voici result : " << result;
        // }
        
        if (event->source() == this)
        {
            event->setDropAction(Qt::CopyAction);
            event->accept();
        }
        else {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }    
}

void DragDropLabel::mousePressEvent(QMouseEvent *event)
{
    if(m_acceptDrag == true)
    {
        DragDropLabel *child = this;
        
        if(!child) return;
        QPixmap pixmap = child->pixmap();
        
        QByteArray itemData;
        QDataStream dataStream(&itemData, QIODevice::WriteOnly);
        dataStream << pixmap << QPoint(event->pos());

        
        QMimeData *mimeData = new QMimeData;
        mimeData->setData("application/x-dnditemdata", itemData);
                
        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(pixmap);
        drag->setHotSpot(event->pos());
        
        QPixmap tempPixmap = pixmap;
        QPainter painter;
        painter.begin(&tempPixmap);
        painter.fillRect(pixmap.rect(), QColor(120,120,120,120));
        painter.end();

        child->setPixmap(tempPixmap);

        if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
        {
            child->close();
        }
        else
        {
            child->show();
            child->setPixmap(pixmap);
            qInfo() << "pixmap de mousepressevent : " << pixmap.toImage();
            imageStart = pixmap.toImage();
        }
    }
}

void DragDropLabel::setAcceptDrag(bool value)
{
    m_acceptDrag = value;
}

bool DragDropLabel::getAcceptDrag(void)
{
    return m_acceptDrag;
}

void DragDropLabel::setAcceptDrop(bool value)
{
    m_acceptDrop = value;
}

bool DragDropLabel::getAcceptDrop(void)
{
    return m_acceptDrop;
}
