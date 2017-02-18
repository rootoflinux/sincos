#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <QtWidgets>
#include <cmath>
#include <iostream>

class PaintWidget : public QWidget
{
	Q_OBJECT

public:
	PaintWidget(QWidget *parent = 0);

	bool openImage(const QString &fileName);
	bool newImage(int x, int y);
	bool saveImage(const QString &fileName);
	void setPenColor(const QColor &newColor);
	void setPenWidth(int newWidth);
	void kresliOsi(int delenia);
	void kresliSinusB(int delenia, bool sinus, double rozsah);
	void kresliSinusC(int delenia, bool sinus, double rozsah);
	void kresliSinusS(int delenia, bool sinus, double rozsah);

	void kresliTanB(int delenia, bool sinus, double rozsah);
	void kresliTanC(int delenia, bool sinus, double rozsah);
	void kresliTanS(int delenia, bool sinus, double rozsah);

	void kresliPoly(int delenia, double a, double b, double c, double d, double rozsah);
	void kresliPolyB(int delenia, double a, double b, double c, double d, double rozsah);
	void kresliPolyS(int delenia, double a, double b, double c, double d, double rozsah);

	bool isModified() const { return modified; }
	QColor penColor() const { return myPenColor; }
	int penWidth() const { return myPenWidth; }

	public slots:
	void clearImage();

protected:
	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
	void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
	void mouseDoubleClickEvent(QMouseEvent *event);

private:
	void drawLineTo(const QPoint &endPoint);
	void resizeImage(QImage *image, const QSize &newSize);

	bool modified;
	bool painting;
	int myPenWidth;
	QColor myPenColor;
	QImage image;
	QPoint lastPoint;
};

#endif // PAINTWIDGET_H
