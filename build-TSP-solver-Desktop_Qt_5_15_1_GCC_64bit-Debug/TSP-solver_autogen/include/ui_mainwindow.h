/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *TimeLabel;
    QSlider *TimeSlider;
    QTextEdit *TimeText;
    QSpacerItem *ThreadsAndTimeSpacer;
    QLabel *ThreadsLabel;
    QSlider *ThreadsSlider;
    QTextEdit *ThreadsText;
    QPushButton *RunButton;
    QWidget *layoutWidget1;
    QVBoxLayout *MapButtons;
    QPushButton *AddVertexButton;
    QPushButton *RemoveVertexButton;
    QPushButton *ClearVerticlesButton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *TabuCheckBox;
    QCheckBox *ACOCheckBox_2;
    QCheckBox *PSOCheckBox_3;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QLabel *CostLabel;
    QTextEdit *CostText;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_4;
    QLabel *RouteLabel;
    QPlainTextEdit *RouteText;
    QLabel *MapOfPoland;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1408, 684);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMouseTracking(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 290, 231, 252));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        TimeLabel = new QLabel(layoutWidget);
        TimeLabel->setObjectName(QString::fromUtf8("TimeLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TimeLabel->sizePolicy().hasHeightForWidth());
        TimeLabel->setSizePolicy(sizePolicy1);
        TimeLabel->setFrameShape(QFrame::Box);
        TimeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(TimeLabel);

        TimeSlider = new QSlider(layoutWidget);
        TimeSlider->setObjectName(QString::fromUtf8("TimeSlider"));
        TimeSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(TimeSlider);

        TimeText = new QTextEdit(layoutWidget);
        TimeText->setObjectName(QString::fromUtf8("TimeText"));
        sizePolicy1.setHeightForWidth(TimeText->sizePolicy().hasHeightForWidth());
        TimeText->setSizePolicy(sizePolicy1);
        TimeText->setFocusPolicy(Qt::StrongFocus);
        TimeText->setReadOnly(true);

        verticalLayout->addWidget(TimeText);

        ThreadsAndTimeSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(ThreadsAndTimeSpacer);

        ThreadsLabel = new QLabel(layoutWidget);
        ThreadsLabel->setObjectName(QString::fromUtf8("ThreadsLabel"));
        ThreadsLabel->setFrameShape(QFrame::Box);
        ThreadsLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(ThreadsLabel);

        ThreadsSlider = new QSlider(layoutWidget);
        ThreadsSlider->setObjectName(QString::fromUtf8("ThreadsSlider"));
        ThreadsSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(ThreadsSlider);

        ThreadsText = new QTextEdit(layoutWidget);
        ThreadsText->setObjectName(QString::fromUtf8("ThreadsText"));
        sizePolicy1.setHeightForWidth(ThreadsText->sizePolicy().hasHeightForWidth());
        ThreadsText->setSizePolicy(sizePolicy1);
        ThreadsText->setReadOnly(true);

        verticalLayout->addWidget(ThreadsText);

        RunButton = new QPushButton(centralwidget);
        RunButton->setObjectName(QString::fromUtf8("RunButton"));
        RunButton->setGeometry(QRect(540, 580, 301, 51));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 40, 161, 231));
        MapButtons = new QVBoxLayout(layoutWidget1);
        MapButtons->setSpacing(20);
        MapButtons->setObjectName(QString::fromUtf8("MapButtons"));
        MapButtons->setSizeConstraint(QLayout::SetNoConstraint);
        MapButtons->setContentsMargins(0, 0, 0, 0);
        AddVertexButton = new QPushButton(layoutWidget1);
        AddVertexButton->setObjectName(QString::fromUtf8("AddVertexButton"));
        sizePolicy1.setHeightForWidth(AddVertexButton->sizePolicy().hasHeightForWidth());
        AddVertexButton->setSizePolicy(sizePolicy1);

        MapButtons->addWidget(AddVertexButton);

        RemoveVertexButton = new QPushButton(layoutWidget1);
        RemoveVertexButton->setObjectName(QString::fromUtf8("RemoveVertexButton"));
        sizePolicy1.setHeightForWidth(RemoveVertexButton->sizePolicy().hasHeightForWidth());
        RemoveVertexButton->setSizePolicy(sizePolicy1);

        MapButtons->addWidget(RemoveVertexButton);

        ClearVerticlesButton = new QPushButton(layoutWidget1);
        ClearVerticlesButton->setObjectName(QString::fromUtf8("ClearVerticlesButton"));
        sizePolicy1.setHeightForWidth(ClearVerticlesButton->sizePolicy().hasHeightForWidth());
        ClearVerticlesButton->setSizePolicy(sizePolicy1);

        MapButtons->addWidget(ClearVerticlesButton);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(80, 560, 208, 83));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        TabuCheckBox = new QCheckBox(layoutWidget2);
        TabuCheckBox->setObjectName(QString::fromUtf8("TabuCheckBox"));

        verticalLayout_2->addWidget(TabuCheckBox);

        ACOCheckBox_2 = new QCheckBox(layoutWidget2);
        ACOCheckBox_2->setObjectName(QString::fromUtf8("ACOCheckBox_2"));

        verticalLayout_2->addWidget(ACOCheckBox_2);

        PSOCheckBox_3 = new QCheckBox(layoutWidget2);
        PSOCheckBox_3->setObjectName(QString::fromUtf8("PSOCheckBox_3"));

        verticalLayout_2->addWidget(PSOCheckBox_3);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(1040, 100, 258, 95));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        CostLabel = new QLabel(layoutWidget3);
        CostLabel->setObjectName(QString::fromUtf8("CostLabel"));

        verticalLayout_3->addWidget(CostLabel);

        CostText = new QTextEdit(layoutWidget3);
        CostText->setObjectName(QString::fromUtf8("CostText"));
        CostText->setReadOnly(true);

        verticalLayout_3->addWidget(CostText);

        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(1040, 240, 258, 217));
        verticalLayout_4 = new QVBoxLayout(layoutWidget4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        RouteLabel = new QLabel(layoutWidget4);
        RouteLabel->setObjectName(QString::fromUtf8("RouteLabel"));

        verticalLayout_4->addWidget(RouteLabel);

        RouteText = new QPlainTextEdit(layoutWidget4);
        RouteText->setObjectName(QString::fromUtf8("RouteText"));
        RouteText->setReadOnly(true);

        verticalLayout_4->addWidget(RouteText);

        MapOfPoland = new QLabel(centralwidget);
        MapOfPoland->setObjectName(QString::fromUtf8("MapOfPoland"));
        MapOfPoland->setEnabled(true);
        MapOfPoland->setGeometry(QRect(390, 30, 581, 511));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(MapOfPoland->sizePolicy().hasHeightForWidth());
        MapOfPoland->setSizePolicy(sizePolicy2);
        MapOfPoland->setCursor(QCursor(Qt::CrossCursor));
        MapOfPoland->setMouseTracking(true);
        MapOfPoland->setFrameShape(QFrame::NoFrame);
        MapOfPoland->setPixmap(QPixmap(QString::fromUtf8("../map_of_poland.png")));
        MapOfPoland->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1408, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        TimeLabel->setText(QCoreApplication::translate("MainWindow", "Czas oczekiwania:", nullptr));
        ThreadsLabel->setText(QCoreApplication::translate("MainWindow", "Liczba w\304\205tk\303\263w", nullptr));
        RunButton->setText(QCoreApplication::translate("MainWindow", "RUN!", nullptr));
        AddVertexButton->setText(QCoreApplication::translate("MainWindow", "Dodaj punkt na mapie", nullptr));
        RemoveVertexButton->setText(QCoreApplication::translate("MainWindow", "Usu\305\204 punkt z mapy", nullptr));
        ClearVerticlesButton->setText(QCoreApplication::translate("MainWindow", "Wyczy\305\233\304\207 map\304\231", nullptr));
        TabuCheckBox->setText(QCoreApplication::translate("MainWindow", "Przeszukiwanie z zakazami", nullptr));
        ACOCheckBox_2->setText(QCoreApplication::translate("MainWindow", "Kolonia mr\303\263wek", nullptr));
        PSOCheckBox_3->setText(QCoreApplication::translate("MainWindow", "R\303\263j cz\304\205stek", nullptr));
        CostLabel->setText(QCoreApplication::translate("MainWindow", "Szacowany czas przejazdu:", nullptr));
        RouteLabel->setText(QCoreApplication::translate("MainWindow", "Sugerowana trasa:", nullptr));
        MapOfPoland->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
