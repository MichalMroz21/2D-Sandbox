#ifndef OPENGL_RENDERER_HPP
#define OPENGL_RENDERER_HPP

#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>
#include <QOpenGLFramebufferObject>
#include <QOpenGLFunctions_2_0>
#include <GL/gl.h>

class OpenGLRenderer : public QQuickFramebufferObject::Renderer, protected QOpenGLFunctions_2_0
{
public:
    OpenGLRenderer();
    void render() override;
    QOpenGLFramebufferObject* createFramebufferObject(const QSize &size) override;
    void synchronize(QQuickFramebufferObject *item) override {};
    void releaseResources();

signals:
};

#endif // OPENGLRENDERER_HPP
