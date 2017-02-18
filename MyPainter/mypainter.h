#ifndef MYPAINTER_H
#define MYPAINTER_H

#include <QString>
#include <QtWidgets/QMainWindow>
#include "ui_mypainter.h"
#include "paintwidget.h"
#include <vector>


class MyPainter : public QMainWindow
{
	Q_OBJECT

public:
	MyPainter(QWidget *parent = 0);
	~MyPainter();

public slots:
	void ActionOpen();
	void ActionSave();
	void EffectClear();
	void ActionNew();
	void KresliClicked();

private:
	Ui::MyPainterClass ui;
	PaintWidget paintWidget;
	

	void Polynom(QString poly, double *cleny);
};

#endif // MYPAINTER_H
