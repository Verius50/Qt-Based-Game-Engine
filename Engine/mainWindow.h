#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>

#include "SceneManager.h"
#include "scene.h"
#include "eventManager.h"

class Window : public QMainWindow{
    Q_OBJECT
public:
    Window(QWidget *parent = nullptr);
    ~Window();
private:
    Player* player;

    QSize screenSize;
    SceneManager sceneManager;
    EventManager eventManager;

private slots:

};
#endif // MAINWINDOW_H
