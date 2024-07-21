#pragma once

#include <QLabel>
#include "SceneManager.h"
#include "scene.h"

class HappinnesScene : public Scene{
    Q_OBJECT
private:
    QLabel* icons = nullptr;
    QLabel* backgroundImage = nullptr;
    //SceneManager* sceneManager = nullptr;

public:
    HappinnesScene() : Scene() {
    }

    HappinnesScene(QWidget* parent, SceneManager* sceneManager, InputController* inputController,
        Player* player, QSize screenSize = QSize(0, 0)) : Scene(parent, sceneManager, inputController, player, screenSize)
    {

    }

    void initScene() override;
    void hide() override;
    void show() override;

    ~HappinnesScene() {
        clearScene();
    }

public slots:
   
};





