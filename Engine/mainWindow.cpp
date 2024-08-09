#include "mainWindow.h"
#include "mainMenuScene.h"
#include "playerScene.h"


Window::Window(QWidget *parent)
    : QMainWindow(parent){

    QPixmap iconTexture(":/Icon.png");
    QIcon icon(iconTexture);
    this->setWindowIcon(icon);
    this->setWindowFlags(Qt::WindowMinimizeButtonHint);

    screenSize = QSize(QGuiApplication::primaryScreen()->size().width(),
                       QGuiApplication::primaryScreen()->size().height());
    player = new Player();

    this->installEventFilter(&eventManager);

    sceneManager.scenes.push_back(new MainMenuScene(this, &sceneManager, &eventManager, player, screenSize));
    sceneManager.scenes.push_back(new PlayerScene(this, &sceneManager, &eventManager, player, screenSize));
    


    sceneManager.goToScene(0);
    
}

Window::~Window() {
    delete sceneManager.currentScene;
}
