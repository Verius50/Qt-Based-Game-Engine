#pragma once
#include "qwidget.h"
#include "qevent.h"
#include "qtimer.h"
class EventManager : public QWidget
{
	Q_OBJECT

	QVector<QTimer*> timers;

public:
    bool eventFilter(QObject* obj, QEvent* event);

	void addTimer(int id, int interval) {
		timers.push_back(new QTimer(this));
		timers[timers.size() - 1]->start(1000);
	}


signals:
    void keyPressed(int key);
	//void timerEnd(int id);

};

