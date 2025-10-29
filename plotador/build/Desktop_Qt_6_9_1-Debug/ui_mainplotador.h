/********************************************************************************
** Form generated from reading UI file 'mainplotador.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPLOTADOR_H
#define UI_MAINPLOTADOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPlotador
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QLabel *grafico;
    QFrame *frame;
    QMenuBar *menubar;
    QMenu *menuPlotador_de_Fun_es;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainPlotador)
    {
        if (MainPlotador->objectName().isEmpty())
            MainPlotador->setObjectName("MainPlotador");
        MainPlotador->resize(800, 600);
        centralwidget = new QWidget(MainPlotador);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        grafico = new QLabel(centralwidget);
        grafico->setObjectName("grafico");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(grafico->sizePolicy().hasHeightForWidth());
        grafico->setSizePolicy(sizePolicy);
        grafico->setMinimumSize(QSize(540, 540));
        grafico->setFrameShape(QFrame::Shape::Box);
        grafico->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(grafico);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(190, 540));
        frame->setFrameShape(QFrame::Shape::Box);
        frame->setFrameShadow(QFrame::Shadow::Plain);

        horizontalLayout->addWidget(frame);

        MainPlotador->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainPlotador);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuPlotador_de_Fun_es = new QMenu(menubar);
        menuPlotador_de_Fun_es->setObjectName("menuPlotador_de_Fun_es");
        MainPlotador->setMenuBar(menubar);
        statusbar = new QStatusBar(MainPlotador);
        statusbar->setObjectName("statusbar");
        MainPlotador->setStatusBar(statusbar);

        menubar->addAction(menuPlotador_de_Fun_es->menuAction());

        retranslateUi(MainPlotador);

        QMetaObject::connectSlotsByName(MainPlotador);
    } // setupUi

    void retranslateUi(QMainWindow *MainPlotador)
    {
        MainPlotador->setWindowTitle(QCoreApplication::translate("MainPlotador", "MainPlotador", nullptr));
        grafico->setText(QCoreApplication::translate("MainPlotador", "GRAFICO", nullptr));
        menuPlotador_de_Fun_es->setTitle(QCoreApplication::translate("MainPlotador", "Plotador de Fun\303\247\303\265es", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPlotador: public Ui_MainPlotador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPLOTADOR_H
