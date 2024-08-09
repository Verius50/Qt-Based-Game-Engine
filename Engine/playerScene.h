#pragma once

#include <QPushButton>
#include <QLabel>

#include "SceneManager.h"

class PlayerScene : public Scene{
    Q_OBJECT
private:

    QLabel* backgroundImage = nullptr, *bomj = nullptr;
    
    
public:
    PlayerScene() : Scene() {
    }
    PlayerScene(QWidget* parent, SceneManager* sceneManager, EventManager* eventManager,
        Player* player, QSize screenSize = QSize(0, 0)) : Scene(parent, sceneManager, eventManager, player, screenSize)
    {

    }
    void initScene() override;

    
    ~PlayerScene() {
        clearScene();

    }

private slots:
    void update();
    void keyPressedSlot(int key);
    
};














