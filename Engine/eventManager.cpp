#include "eventManager.h"

bool EventManager::eventFilter(QObject* obj, QEvent* event)
{
    switch (event->type())
    {
    case QEvent::KeyPress:
        emit keyPressed(static_cast<QKeyEvent*>(event)->key());
        return true;
	case QEvent::MouseMove:
        break;
	case QEvent::MouseButtonPress:
		break;
	case QEvent::MouseButtonRelease:
        break;
	//case QEvent::Timer:
		//emit timerEnd(static_cast<QTimerEvent*>(event)->timerId());
    default:
        return QObject::eventFilter(obj, event);
    }

    return false;
}
