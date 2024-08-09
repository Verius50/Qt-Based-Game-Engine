#pragma once

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include "qlabel.h"
#include "Player.h"
#include "eventManager.h"

class Scene : public QObject{
    Q_OBJECT
protected:
    
public:
    QSize sceneSize;
    QWidget* parentWidget;
    QVector<QWidget*> objs;
    Player* player;
    QObject* sceneManager;
    EventManager* eventManager;

    Scene() { parentWidget = nullptr; player = nullptr; sceneManager = nullptr; eventManager = nullptr; }

    Scene(QWidget* parent, QObject* sceneManager, EventManager* eventManager, Player* player, QSize screenSize = QSize(0, 0)) {
        parentWidget = parent;
        this->sceneManager = sceneManager;
        sceneSize = screenSize;
        this->player = player;
        this->eventManager = eventManager;
    }
    
    virtual void initScene() = 0;
    
    
    void hide();
    void show();
    void clearScene();
    int getIndexOfObjectByName(QString name);

    void addPlayerValuesHUD(QSize positionFromRTCorner = {350, 80}, 
        QSize iconsSize = { 40, 40 }, QSize spacings = {50, 80}, float barsLenght = 200);

    

    ~Scene() {
    }
};
