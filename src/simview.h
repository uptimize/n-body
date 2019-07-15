#ifndef SIMVIEW_H
#define SIMVIEW_H

#include "rendering/Renderer.h"
#include "Engine.h"
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <memory>

class SimView : public QOpenGLWidget {
    Q_OBJECT

  public:
    explicit SimView(QWidget *parent = nullptr);
    ~SimView();

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

  private:
    std::unique_ptr<Renderer> m_renderer;
    EngineThread m_engineThread;
};

#endif // SIMVIEW_H
