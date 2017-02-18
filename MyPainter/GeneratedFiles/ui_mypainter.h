/********************************************************************************
** Form generated from reading UI file 'mypainter.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPAINTER_H
#define UI_MYPAINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyPainterClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionClear;
    QAction *actionNew;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label_3;
    QSpinBox *spinBox;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QFormLayout *formLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEffects;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyPainterClass)
    {
        if (MyPainterClass->objectName().isEmpty())
            MyPainterClass->setObjectName(QStringLiteral("MyPainterClass"));
        MyPainterClass->resize(999, 460);
        actionOpen = new QAction(MyPainterClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MyPainterClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionClear = new QAction(MyPainterClass);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionNew = new QAction(MyPainterClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        centralWidget = new QWidget(MyPainterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        formLayout->setWidget(3, QFormLayout::FieldRole, radioButton_3);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(20);
        spinBox->setMaximum(500);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBox);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit);


        verticalLayout_2->addWidget(groupBox);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(-1, -1, -1, 0);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pushButton_2);


        verticalLayout_2->addLayout(formLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 484, 397));
        scrollArea->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout->addWidget(scrollArea);


        verticalLayout->addLayout(horizontalLayout);

        MyPainterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyPainterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 999, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEffects = new QMenu(menuBar);
        menuEffects->setObjectName(QStringLiteral("menuEffects"));
        MyPainterClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MyPainterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyPainterClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEffects->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuEffects->addAction(actionClear);

        retranslateUi(MyPainterClass);
        QObject::connect(actionOpen, SIGNAL(triggered()), MyPainterClass, SLOT(ActionOpen()));
        QObject::connect(actionSave, SIGNAL(triggered()), MyPainterClass, SLOT(ActionSave()));
        QObject::connect(actionClear, SIGNAL(triggered()), MyPainterClass, SLOT(EffectClear()));
        QObject::connect(actionNew, SIGNAL(triggered()), MyPainterClass, SLOT(ActionNew()));
        QObject::connect(pushButton, SIGNAL(clicked()), MyPainterClass, SLOT(KresliClicked()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MyPainterClass, SLOT(EffectClear()));

        QMetaObject::connectSlotsByName(MyPainterClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyPainterClass)
    {
        MyPainterClass->setWindowTitle(QApplication::translate("MyPainterClass", "MyPainter", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MyPainterClass", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MyPainterClass", "Save", Q_NULLPTR));
        actionClear->setText(QApplication::translate("MyPainterClass", "Clear", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MyPainterClass", "New", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MyPainterClass", "Nastavenia", Q_NULLPTR));
        label->setText(QApplication::translate("MyPainterClass", "Graf", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MyPainterClass", "S\303\255nus", Q_NULLPTR)
         << QApplication::translate("MyPainterClass", "Kos\303\255nus", Q_NULLPTR)
         << QApplication::translate("MyPainterClass", "Tangens", Q_NULLPTR)
         << QApplication::translate("MyPainterClass", "Kotangens", Q_NULLPTR)
         << QApplication::translate("MyPainterClass", "polynom", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("MyPainterClass", "Typ grafu", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MyPainterClass", "Bodov\303\275", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MyPainterClass", "\304\214iarov\303\275", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MyPainterClass", "St\304\272pcov\303\275", Q_NULLPTR));
        label_3->setText(QApplication::translate("MyPainterClass", "Delenie", Q_NULLPTR));
        label_5->setText(QApplication::translate("MyPainterClass", "rizssah v rad", Q_NULLPTR));
        label_4->setText(QApplication::translate("MyPainterClass", "polynom", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("MyPainterClass", "2", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MyPainterClass", "Kresli", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MyPainterClass", "Vyma\305\276", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MyPainterClass", "File", Q_NULLPTR));
        menuEffects->setTitle(QApplication::translate("MyPainterClass", "Effects", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyPainterClass: public Ui_MyPainterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPAINTER_H
