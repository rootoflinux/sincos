#include "paintwidget.h"


PaintWidget::PaintWidget(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_StaticContents);
	modified = false;
	painting = false;
	myPenWidth = 1;
	myPenColor = Qt::blue;
}

bool PaintWidget::openImage(const QString &fileName)
{
	QImage loadedImage;
	if (!loadedImage.load(fileName))
		return false;

	QSize newSize = loadedImage.size();
	resizeImage(&loadedImage, newSize);
	image = loadedImage;
	this->resize(image.size());
	this->setMinimumSize(image.size());
	modified = false;
	update();
	return true;
}

bool PaintWidget::newImage(int x, int y)
{
	QImage loadedImage(x,y,QImage::Format_RGB32);
	loadedImage.fill(qRgb(255, 255, 255));
	QSize newSize = loadedImage.size();
	resizeImage(&loadedImage, newSize);
	image = loadedImage;
	this->resize(image.size());
	this->setMinimumSize(image.size());
	modified = false;
	update();
	return true;
}

bool PaintWidget::saveImage(const QString &fileName)
{
	QImage visibleImage = image;
	resizeImage(&visibleImage, size());

	if (visibleImage.save(fileName,"png")) {
		modified = false;
		return true;
	}
	else {
		return false;
	}
}

void PaintWidget::setPenColor(const QColor &newColor)
{
	myPenColor = newColor;
}

void PaintWidget::setPenWidth(int newWidth)
{
	myPenWidth = newWidth;
}

void PaintWidget::kresliOsi(int delenia)
{
	int xs = image.width();
	int ys = image.height();
	QPainter painter(&image);
	painter.setPen(QPen(QColor("black"), myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.drawLine(20,ys/2,xs-20,ys/2);
	painter.drawLine(xs/2, 20, xs/2, ys-20);
	painter.drawText(10, ys/2-10, "X");
	painter.drawText(xs/2+10, 20, "Y");
	painter.setPen(QPen(QColor("green"), myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

	for (int i = 0; i < delenia+1; i++)
	{
		int x1, y1,x2,y2;
		x1=(20 + i*((xs-40.0) / (delenia)));
		y1=(ys/2-5);
		x2=(20 + i*((xs - 40.0) / (delenia)));
		y2=(ys/2+5);
		painter.drawLine(x1,y1,x2,y2);
		x1 = (xs / 2 - 5);
		y1 = (20 + i*((ys - 40.0) / (delenia)));
		x2 = (xs / 2 + 5);
		y2 = (20 + i*((ys - 40.0) / (delenia)));
		painter.drawLine(x1, y1, x2, y2);
	}
	update();
}

void PaintWidget::kresliSinusB(int delenia, bool sinus, double rozsah)
{
	int xs = image.width();
	int ys = image.height();
	QPainter painter(&image);
	painter.setPen(QPen(QColor("red"), myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.setBrush(QBrush(QColor("red")));
	for (int i = 0; i < delenia+1; i++)
	{
		double hodnota = i*((M_PI * rozsah) / (delenia));
		double vysledok = sinus ? sin(hodnota) : cos(hodnota);
		int x1, y1;
		x1=(20 + i*((xs - 40.0) / (delenia)))-3;
		y1=((int)((vysledok + 1) * (ys/2-20)) + 20)-3;
		painter.drawEllipse(x1,y1, 6, 6);
	}
	update();
}

void PaintWidget::kresliSinusC(int delenia, bool sinus, double rozsah)
{
	int xs = image.width();
	int ys = image.height();
	QPainter painter(&image);
	painter.setPen(QPen(QColor("red"), myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	//painter.setBrush(QBrush(QColor("red")));
	for (int i = 0; i < delenia; i++)
	{
		double hodnota = i*((M_PI * rozsah) / (delenia));
		double vysledok = sinus ? sin(hodnota) : cos(hodnota);
		int x1, y1,x2,y2;
		x1=(20 + i*((xs - 40.0) / (delenia)));
		y1=((int)((vysledok + 1) * (ys / 2 - 20)) + 20);
		hodnota = (i+1)*((M_PI * rozsah) / (delenia));
		vysledok = sinus ? sin(hodnota):cos(hodnota);
		x2=(20 + (i+1)*((xs - 40.0) / (delenia)));
		y2=((int)((vysledok + 1) * (ys / 2 - 20)) + 20);
		painter.drawLine(x1, y1,x2,y2);
	}
	update();
}

void PaintWidget::kresliSinusS(int delenia, bool sinus, double rozsah)
{
	int xs = image.width();
	int ys = image.height();
	QPainter painter(&image);
	painter.setPen(QPen(QColor("red"), myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.setBrush(QBrush(QColor("red")));
	for (int i = 0; i < delenia; i++)
	{
		double hodnota = i*((M_PI * rozsah) / (delenia));
		double vysledok = sinus ? sin(hodnota) : cos(hodnota);
		int x1, y1;
		x1=(20 + i*((xs - 40.0) / (delenia)));
		y1=((int)((vysledok + 1) * (ys / 2 - 20)) + 20);
		if(y1>ys/2)painter.drawRect(x1, ys/2, ((xs - 40.0) / (delenia)), y1-ys/2);
		else painter.drawRect(x1, y1, ((xs - 40.0) / (delenia)),ys/2-y1);
	}
	update();
}

void PaintWidget::clearImage()
{
	image.fill(qRgb(255, 255, 255));
	modified = true;
	update();
}

void PaintWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		lastPoint = event->pos();
		painting = true;
	}
}

void PaintWidget::mouseDoubleClickEvent(QMouseEvent *event)
{

}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
	if ((event->buttons() & Qt::LeftButton) && painting)
		drawLineTo(event->pos());
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && painting) {
		drawLineTo(event->pos());
		painting = false;
	}
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QRect dirtyRect = event->rect();
	painter.drawImage(dirtyRect, image, dirtyRect);
}

void PaintWidget::resizeEvent(QResizeEvent *event)
{
	QWidget::resizeEvent(event);
}

void PaintWidget::drawLineTo(const QPoint &endPoint)
{
	QPainter painter(&image);
	painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.drawLine(lastPoint, endPoint);
	modified = true;

	int rad = (myPenWidth / 2) + 2;
	update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
	lastPoint = endPoint;
}

void PaintWidget::resizeImage(QImage *image, const QSize &newSize)
{
	if (image->size() == newSize)
		return;

	QImage newImage(newSize, QImage::Format_RGB32);
	newImage.fill(qRgb(255, 255, 255));
	QPainter painter(&newImage);
	painter.drawImage(QPoint(0, 0), *image);
	*image = newImage;
}

void PaintWidget::kresliTanB(int delenia, bool sinus, double rozsah)
{
	int xs = image.width();
	int ys = image.height();
	QPainter painter(&image);
	painter.setPen(QPen(QColor("red"), myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.setBrush(QBrush(QColor("red")));
	for (int i = 0; i < delenia + 1; i++)
	{
		double hodnota = i*((M_PI * rozsah) / (delenia));
		double vysledok = sinus ? tan(hodnota) : 1/tan(hodnota);
		int x1, y1;
		x1 = (20 + i*((xs - 40.0) / (delenia))) - 3;
		y1 = ((int)((vysledok + 1) * (ys / 2 - 20)) + 20) - 3;
		painter.drawEllipse(x1, y1, 6, 6);
	}
	update();
}

void PaintWidget::kresliTanC(int delenia, bool sinus, double rozsah)
{
	int xs = image.width();
	int ys = image.height();
	QPainter painter(&image);
	painter.setPen(QPen(QColor("red"), myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	//painter.setBrush(QBrush(QColor("red")));
	for (int i = 0; i < delenia; i++)
	{
		double hodnota = i*((M_PI * rozsah) / (delenia));
		double vysledok = sinus ? tan(hodnota) : 1 / tan(hodnota);
		int x1, y1, x2, y2;
		x1 = (20 + i*((xs - 40.0) / (delenia)));
		y1 = ((int)((vysledok + 1) * (ys / 2 - 20)) + 20);
		hodnota = (i + 1)*((M_PI * rozsah) / (delenia));
		vysledok = sinus ? tan(hodnota) : 1 / tan(hodnota);
		x2 = (20 + (i + 1)*((xs - 40.0) / (delenia)));
		y2 = ((int)((vysledok + 1) * (ys / 2 - 20)) + 20);
		painter.drawLine(x1, y1, x2, y2);
	}
	update();
}

void PaintWidget::kresliTanS(int delenia, bool sinus, double rozsah)
{
	int xs = image.width();
	int ys = image.height();
	QPainter painter(&image);
	painter.setPen(QPen(QColor("red"), myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.setBrush(QBrush(QColor("red")));
	for (int i = 0; i < delenia; i++)
	{
		double hodnota = i*((M_PI * rozsah) / (delenia));
		double vysledok = sinus ? tan(hodnota) : 1 / tan(hodnota);
		int x1, y1;
		x1 = (20 + i*((xs - 40.0) / (delenia)));
		y1 = ((int)((vysledok + 1) * (ys / 2 - 20)) + 20);
		if (y1>ys / 2)painter.drawRect(x1, ys / 2, ((xs - 40.0) / (delenia)), y1 - ys / 2);
		else painter.drawRect(x1, y1, ((xs - 40.0) / (delenia)), ys / 2 - y1);
	}
	update();
}

void PaintWidget::kresliPoly(int delenia, double a, double b, double c, double d, double rozsah)
{
	int xs = image.width();
	int ys = image.height();
	QPainter painter(&image);
	painter.setPen(QPen(QColor("red"), myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	//painter.setBrush(QBrush(QColor("red")));
	for (int i = 0; i < delenia; i++)
	{
		double hodnota = i*(rozsah / (delenia));
		double vysledok = ((a * (hodnota * hodnota * hodnota)) + (b * (hodnota * hodnota)) + (c * hodnota));
		int x1, y1, x2, y2;
		x1 = (20 + i*((xs - 40.0) / (delenia)));
		y1 = ((int)((vysledok + 1) * (ys / 2 - 20)) + 20);
		hodnota = (((i+1)*rozsah) / (delenia));
		vysledok = ((a * (hodnota * hodnota * hodnota)) + (b * (hodnota * hodnota)) + (c * hodnota));
		x2 = (20 + (i + 1)*((xs - 40.0) / (delenia)));
		y2 = ((int)((vysledok + 1) * (ys / 2 - 20)) + 20);
		painter.drawLine(x1, y1, x2, y2);
	}
	update();
}
void PaintWidget::kresliPolyS(int delenia, double a, double b, double c, double d, double rozsah)
{
	int xs = image.width();
	int ys = image.height();
	QPainter painter(&image);
	painter.setPen(QPen(QColor("red"), myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.setBrush(QBrush(QColor("red")));
	for (int i = 0; i < delenia; i++)
	{
		double hodnota = i*((rozsah) / (delenia));
		double vysledok = ((a * (hodnota * hodnota * hodnota)) + (b * (hodnota * hodnota)) + (c * hodnota));
		int x1, y1;
		x1 = (20 + i*((xs - 40.0) / (delenia)));
		y1 = ((int)((vysledok + 1) * (ys / 2 - 20)) + 20);
		if (y1>ys / 2)painter.drawRect(x1, ys / 2, ((xs - 40.0) / (delenia)), y1 - ys / 2);
		else painter.drawRect(x1, y1, ((xs - 40.0) / (delenia)), ys / 2 - y1);
	}
	update();
}

void PaintWidget::kresliPolyB(int delenia, double a, double b, double c, double d, double rozsah)
{
	int xs = image.width();
	int ys = image.height();
	QPainter painter(&image);
	painter.setPen(QPen(QColor("red"), myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.setBrush(QBrush(QColor("red")));
	for (int i = 0; i < delenia + 1; i++)
	{
		double hodnota = i*(( rozsah) / (delenia));
		double vysledok = ((a * (hodnota * hodnota * hodnota)) + (b * (hodnota * hodnota)) + (c * hodnota));
		int x1, y1;
		x1 = (20 + i*((xs - 40.0) / (delenia))) - 3;
		y1 = ((int)((vysledok + 1) * (ys / 2 - 20)) + 20) - 3;
		painter.drawEllipse(x1, y1, 6, 6);
	}
	update();
}