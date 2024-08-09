#include "scene.h"

void Scene::clearScene(){
    for (int i = 0; i < objs.size(); i++){
        objs[i]->~QWidget();
    }
    objs.clear();
}

void Scene::hide() {
    for (int i = 0; i < objs.size(); i++) {
        objs[i]->hide();
    }
}

void Scene::show() {
    for (int i = 0; i < objs.size(); i++) {
        objs[i]->show();
    }
}


int Scene::getIndexOfObjectByName(QString name)
{
    for (int i = 0; i < objs.size(); i++)
        if (objs[i]->objectName() == name)
            return i;
    return -1;
}



void Scene::addPlayerValuesHUD(QSize positionFromRTCorner, QSize iconsSize, QSize spacings, float barsLenght)
{
    QLabel* icons = new QLabel[3], * horizontalBars = new QLabel[3],
        * horizontalBarsFrames = new QLabel[3], * frame = new QLabel(parentWidget);
    QPixmap tempTexture;



    icons[0].setObjectName(tr("First HUD Icon"));

    tempTexture.load(":/Heart.png");
    icons[0].setPixmap(tempTexture);
    tempTexture.load(":/Food.png");
    icons[1].setPixmap(tempTexture);
    tempTexture.load(":/Hapiness.png");
    icons[2].setPixmap(tempTexture);

    tempTexture.fill(QColor(255, 0, 0));
    horizontalBars[0].setPixmap(tempTexture);
    tempTexture.fill(QColor(255, 79, 0));
    horizontalBars[1].setPixmap(tempTexture);
    tempTexture.fill(QColor(0, 191, 255));
    horizontalBars[2].setPixmap(tempTexture);

    tempTexture.load(":/HealthBarFrame.png");
    horizontalBarsFrames[0].setPixmap(tempTexture);
    tempTexture.load(":/HungryBarFrame.png");
    horizontalBarsFrames[1].setPixmap(tempTexture);
    tempTexture.load(":/HapinessBarFrame.png");
    horizontalBarsFrames[2].setPixmap(tempTexture);

    tempTexture.load(":/Frame.png");
    frame->setPixmap(tempTexture);

    for (int i = 0; i < 3; i++) {
        icons[i].setParent(parentWidget);
        horizontalBars[i].setParent(parentWidget);
        horizontalBarsFrames[i].setParent(parentWidget);

        icons[i].setScaledContents(true);
        horizontalBars[i].setScaledContents(true);
        horizontalBarsFrames[i].setScaledContents(true);

        icons[i].setGeometry(sceneSize.width() - positionFromRTCorner.width(), 
            positionFromRTCorner.height() + spacings.height() * i, iconsSize.width(), iconsSize.height());
        horizontalBars[i].setGeometry(icons[i].geometry().x() + spacings.width(), icons[i].geometry().y(),
            barsLenght, iconsSize.height());
        horizontalBarsFrames[i].setGeometry(horizontalBars[i].geometry().x() - 5, icons[i].geometry().y() - 5,
            barsLenght + 10, iconsSize.height() + 10);

        objs.push_back(icons + i);
        objs.push_back(horizontalBars + i);
        objs.push_back(horizontalBarsFrames + i);
    }
    frame->setScaledContents(true);
    frame->setGeometry(icons[0].geometry().x() - iconsSize.width(), icons[0].geometry().y() - iconsSize.height(),
        (spacings.width() + iconsSize.width()) * 2 + barsLenght,
        3 * iconsSize.height() + 2 * (spacings.height()));
    objs.push_back(frame);

    horizontalBars[0].setFixedWidth(barsLenght * player->health / 100.0f);
    horizontalBars[1].setFixedWidth(barsLenght * player->hunger / 100.0f);
    horizontalBars[2].setFixedWidth(barsLenght * player->hapiness / 100.0f);
}
