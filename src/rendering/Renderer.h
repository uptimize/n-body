#pragma once

#include <QMouseEvent>
#include <QObject>
#include <QOpenGLFunctions_4_1_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QVector3D>
#include <QWheelEvent>
#include <engine/Engine.h>
#include <memory>

class Renderer : public QObject, protected QOpenGLFunctions_4_1_Core {
    Q_OBJECT

  public:
    explicit Renderer(QOpenGLWidget *openGLView);

    void initialize();
    void render();

    void wheelEvent(QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    inline void resize(int width, int height) noexcept {}

  public slots:
    void updateParams(RendererInterface params);
    void renderReady();

  private:
    QOpenGLWidget *m_openGLView;
    std::unique_ptr<QOpenGLShaderProgram> m_program{};

    RendererInterface m_engineParams{};

    std::unique_ptr<QMatrix4x4> m_mvp{};
    int m_mvp_loc{};
    bool m_mvp_changed = false;
    GLfloat m_zoom = zoomDefault;
    QVector3D m_translation = translationDefault;
    GLfloat m_radius = 0.02f;
    GLfloat m_camX = 0.0f;
    GLfloat m_camY = 0.0f;

    GLuint m_vao{};
    GLuint m_vbo{};
    GLuint m_eab{};
    GLuint m_obo{};
    GLuint m_rbo{};

    static constexpr GLfloat zoomDefault = 1.0f;
    static constexpr QVector3D translationDefault = QVector3D(0, 0, 0);
    static constexpr GLfloat zoomScale = 0.01f;
    static constexpr GLfloat movScale = 0.001f;

    QVector3D m_mousePos;
    QVector3D m_camPos;
};
