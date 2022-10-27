#ifndef RENDERER_H
#define RENDERER_H

#include <QObject>
#include <QVector>
#include "tiledimagegraphicsitem.h"
#include "qgigimagegraphicsitem.h"
#include "gigbmpimage.h"
#include "renderqueue.h"
#include "gigrenderthread.h"

class Renderer : public QObject
{
	Q_OBJECT
public:
	Renderer(QObject *parent);
	~Renderer();

	bool openImage(const QString& filePath);
	void closeImage(void);
	void render(TiledImageGraphicsItem* item, int priority=0);
	QImage cachedRawImageOf(TiledImageGraphicsItem* item);
	void cacheRawImage(TiledImageGraphicsItem* item);
signals:
	void renderedImage(TiledImageGraphicsItem* item, QImage scaleDown);
	void cachedImage(TiledImageGraphicsItem* item);

private:
    QMutex m_cacheLock;
	GigBmpImage* m_image;
    GigRenderThread::CacheDataList m_cache;
    QVector<RenderQueueItem> m_eventQueue;
};

#endif // RENDERER_H
