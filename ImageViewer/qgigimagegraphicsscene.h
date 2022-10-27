#ifndef QGIGIMAGEGRAPHICSSCENE_H
#define QGIGIMAGEGRAPHICSSCENE_H

#include <QFutureWatcher>
#include <QGraphicsScene>
#include <QImage>

class QGigImageGraphicsItem;
class QGraphicsRectItem;

class QGigImageGraphicsScene : public QGraphicsScene
{
	Q_OBJECT
public:
	QGigImageGraphicsScene(QObject *parent=0);
	~QGigImageGraphicsScene();

	bool loadImage(const QString& filePath);
Q_SIGNALS:
	void colorDetected(int x, int y, QColor color);
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

	QGigImageGraphicsItem* m_imageItem;
	QGraphicsRectItem* m_rubberBand;
	QGraphicsRectItem* m_roi;
	QPointF m_rubberBandOrigin;
};

#endif // QGIGIMAGEGRAPHICSSCENE_H
