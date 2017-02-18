#include "mypainter.h"

MyPainter::MyPainter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.scrollArea->setWidget(&this->paintWidget);
	ui.scrollArea->setBackgroundRole(QPalette::Dark);
	paintWidget.newImage(800, 600);
	paintWidget.kresliOsi(this->ui.spinBox->value());
}

MyPainter::~MyPainter()
{

}

void MyPainter::ActionOpen()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "image files (*.png *.jpg *.bmp)");
	if (!fileName.isEmpty())
		paintWidget.openImage(fileName);
}

void MyPainter::ActionSave()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), "untitled.png", tr("png Files (*.png)"));
	if (fileName.isEmpty()) {
		return;
	}
	else {
		paintWidget.saveImage(fileName);
	}
}

void MyPainter::EffectClear()
{
	paintWidget.clearImage();
}

void MyPainter::ActionNew()
{
	paintWidget.newImage(800, 600);
}

void MyPainter::KresliClicked()
{
	QString rozsah = ui.lineEdit->text();
	

	paintWidget.clearImage();
	paintWidget.kresliOsi(ui.spinBox->value());
	


	if (ui.comboBox->currentIndex() == 0)
	{
		if (ui.radioButton->isChecked())paintWidget.kresliSinusB(ui.spinBox->value(), true, rozsah.toDouble());
		if (ui.radioButton_2->isChecked())paintWidget.kresliSinusC(ui.spinBox->value(), true, rozsah.toDouble());
		if (ui.radioButton_3->isChecked())paintWidget.kresliSinusS(ui.spinBox->value(), true, rozsah.toDouble());
	}
	else if (ui.comboBox->currentIndex() == 1)
	{
		if (ui.radioButton->isChecked())paintWidget.kresliSinusB(ui.spinBox->value(),false, rozsah.toDouble());
		if (ui.radioButton_2->isChecked())paintWidget.kresliSinusC(ui.spinBox->value(), false, rozsah.toDouble());
		if (ui.radioButton_3->isChecked())paintWidget.kresliSinusS(ui.spinBox->value(), false, rozsah.toDouble());
	}
	else if (ui.comboBox->currentIndex() == 2)
	{
		if (ui.radioButton->isChecked())paintWidget.kresliTanB(ui.spinBox->value(), true, rozsah.toDouble());
		if (ui.radioButton_2->isChecked())paintWidget.kresliTanC(ui.spinBox->value(), true, rozsah.toDouble());
		if (ui.radioButton_3->isChecked())paintWidget.kresliTanS(ui.spinBox->value(), true, rozsah.toDouble());
	}

	else if (ui.comboBox->currentIndex() == 3)
	{
		if (ui.radioButton->isChecked())paintWidget.kresliTanB(ui.spinBox->value(), false, rozsah.toDouble());
		if (ui.radioButton_2->isChecked())paintWidget.kresliTanC(ui.spinBox->value(), false, rozsah.toDouble());
		if (ui.radioButton_3->isChecked())paintWidget.kresliTanS(ui.spinBox->value(), false, rozsah.toDouble());
	}
	else if (ui.comboBox->currentIndex() == 4)
	{
		
		double cleny[4];
		QString poly=ui.lineEdit_2->text();
		this->Polynom(poly, cleny);

		//paintWidget.kresliPoly(ui.spinBox->value(), cleny[3], cleny[2], cleny[1], cleny[0], rozsah.toDouble());
		//paintWidget.kresliPoly(ui.spinBox->value(), 0, 1, 0, 0, rozsah.toDouble());
		if (ui.radioButton->isChecked())paintWidget.kresliPolyB(ui.spinBox->value(), cleny[3], cleny[2], cleny[1], cleny[0], rozsah.toDouble());
		if (ui.radioButton_2->isChecked())paintWidget.kresliPoly(ui.spinBox->value(), cleny[3], cleny[2], cleny[1], cleny[0], rozsah.toDouble());
		if (ui.radioButton_3->isChecked())paintWidget.kresliPolyS(ui.spinBox->value(), cleny[3], cleny[2], cleny[1], cleny[0], rozsah.toDouble());
	}

}


void MyPainter::Polynom(QString poly, double *cleny)
{
	
	QStringList split = poly.split('x');
	//cleny.resize(split.length());
	int counter = 0;
	for (int i = split.length() - 1; i >= 1; i--)
	{
		QStringList tmpspl = split[i].split('+');
		if (tmpspl.length() == 2)
			cleny[counter] = tmpspl[1].toDouble();
		else
		{
			tmpspl = split[i].split('-');
			cleny[counter] = -tmpspl[1].toDouble();
		}
		counter++;
	}
	cleny[counter] = split[0].toDouble();
}