#ifndef OPENGLITEM_H
#define OPENGLITEM_H

#include <QQuickFramebufferObject>
#include <OpenGLRenderer.hpp>

class OpenGLItem : public QQuickFramebufferObject
{
    Q_OBJECT
public:
    OpenGLItem() {}  // Constructor

    // Create the renderer for this item
    Renderer* createRenderer() const override {
        return new OpenGLRenderer();
    }
};

#endif // OPENGLITEM_H
