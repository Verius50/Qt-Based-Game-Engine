#include "playerScene.h"
#include "qevent.h"
#include   "Qtimer"

void PlayerScene::initScene() {

    backgroundImage = new QLabel(parentWidget);
    bomj = new QLabel(parentWidget);


    QPixmap tempTexture(":/PlayerBack.png");
    
    backgroundImage->setPixmap(tempTexture);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, sceneSize.width(), sceneSize.height());
    objs.push_back(backgroundImage);

    addPlayerValuesHUD();

 //   eventManager->addTimer(1, 1000 / 60);

	//QTimer* timer = new QTimer(this);
	//connect(timer, &QTimer::timeout, this, &PlayerScene::update);
	//timer->start(1000 / 60);
	//connect(eventManager, &EventManager::timerEnd, this, &PlayerScene::update);

    //connect(eventManager, &EventManager::keyPressed, this, &PlayerScene::keyPressedSlot);

    QPushButton* exitButton = new QPushButton("return to menu", parentWidget);
    objs.push_back(exitButton);

    connect(objs[objs.indexOf(exitButton)], SIGNAL(pressed()), sceneManager, SLOT(goToMenuScene())); 

}







void PlayerScene::update() {
    int HUDindex = getIndexOfObjectByName(tr("First HUD Icon"));
    if (HUDindex != -1) {
        objs[HUDindex + 1]->setFixedWidth(objs[HUDindex + 2]->geometry().width() * player->health / 100.0f);
        objs[HUDindex + 4]->setFixedWidth(objs[HUDindex + 2]->geometry().width() * player->hunger / 100.0f);
        objs[HUDindex + 7]->setFixedWidth(objs[HUDindex + 2]->geometry().width() * player->hapiness / 100.0f);
    }
}
void PlayerScene::keyPressedSlot(int key)
{
    if (key == Qt::Key_Up) {
        player->health++;
    }
    if (key == Qt::Key_Down) {
        player->health--;
    }
    //update();
}