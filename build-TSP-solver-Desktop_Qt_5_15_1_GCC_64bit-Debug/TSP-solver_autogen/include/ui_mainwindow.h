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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TSPSolver
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *Sliders;
    QLabel *TimeLabel;
    QSlider *TimeSlider;
    QLineEdit *TimeText;
    QSpacerItem *ThreadsAndTimeSpacer;
    QLabel *ThreadsLabel;
    QSlider *ThreadsSlider;
    QLineEdit *ThreadsText;
    QPushButton *RunButton;
    QWidget *layoutWidget1;
    QVBoxLayout *GraphButtons;
    QPushButton *AddVertexButton;
    QPushButton *RemoveVertexButton;
    QPushButton *ClearVerticlesButton;
    QWidget *layoutWidget2;
    QVBoxLayout *AlgoLayout;
    QCheckBox *SACheckBox;
    QCheckBox *ACOCheckBox;
    QCheckBox *PSOCheckBox;
    QWidget *layoutWidget3;
    QVBoxLayout *CostLayout;
    QLabel *CostLabel;
    QLineEdit *CostText;
    QSpacerItem *InfoSpacer;
    QLabel *ImprovementsLabel;
    QLineEdit *ImprovementsText;
    QSpacerItem *progressSpacer;
    QProgressBar *AlgorithmsProgressBar;
    QLabel *MapOfPoland;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TSPSolver)
    {
        if (TSPSolver->objectName().isEmpty())
            TSPSolver->setObjectName(QString::fromUtf8("TSPSolver"));
        TSPSolver->setEnabled(true);
        TSPSolver->resize(1408, 684);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TSPSolver->sizePolicy().hasHeightForWidth());
        TSPSolver->setSizePolicy(sizePolicy);
        TSPSolver->setMouseTracking(false);
        TSPSolver->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	background-color: rgb(146, 183, 108);\n"
"}"));
        centralwidget = new QWidget(TSPSolver);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 290, 231, 211));
        Sliders = new QVBoxLayout(layoutWidget);
        Sliders->setObjectName(QString::fromUtf8("Sliders"));
        Sliders->setContentsMargins(0, 0, 0, 0);
        TimeLabel = new QLabel(layoutWidget);
        TimeLabel->setObjectName(QString::fromUtf8("TimeLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TimeLabel->sizePolicy().hasHeightForWidth());
        TimeLabel->setSizePolicy(sizePolicy1);
        TimeLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color: white;\n"
"}"));
        TimeLabel->setFrameShape(QFrame::WinPanel);
        TimeLabel->setAlignment(Qt::AlignCenter);

        Sliders->addWidget(TimeLabel);

        TimeSlider = new QSlider(layoutWidget);
        TimeSlider->setObjectName(QString::fromUtf8("TimeSlider"));
        TimeSlider->setStyleSheet(QString::fromUtf8(""));
        TimeSlider->setMinimum(3);
        TimeSlider->setMaximum(15);
        TimeSlider->setOrientation(Qt::Horizontal);

        Sliders->addWidget(TimeSlider);

        TimeText = new QLineEdit(layoutWidget);
        TimeText->setObjectName(QString::fromUtf8("TimeText"));
        TimeText->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: rgb(135, 243, 96);\n"
"}"));
        TimeText->setAlignment(Qt::AlignCenter);

        Sliders->addWidget(TimeText);

        ThreadsAndTimeSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Sliders->addItem(ThreadsAndTimeSpacer);

        ThreadsLabel = new QLabel(layoutWidget);
        ThreadsLabel->setObjectName(QString::fromUtf8("ThreadsLabel"));
        ThreadsLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color: white;\n"
"}"));
        ThreadsLabel->setFrameShape(QFrame::WinPanel);
        ThreadsLabel->setAlignment(Qt::AlignCenter);

        Sliders->addWidget(ThreadsLabel);

        ThreadsSlider = new QSlider(layoutWidget);
        ThreadsSlider->setObjectName(QString::fromUtf8("ThreadsSlider"));
        ThreadsSlider->setStyleSheet(QString::fromUtf8("QSlider{\n"
"	selection-color: green;\n"
"}"));
        ThreadsSlider->setOrientation(Qt::Horizontal);

        Sliders->addWidget(ThreadsSlider);

        ThreadsText = new QLineEdit(layoutWidget);
        ThreadsText->setObjectName(QString::fromUtf8("ThreadsText"));
        ThreadsText->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: rgb(135, 243, 96);\n"
"}"));
        ThreadsText->setAlignment(Qt::AlignCenter);

        Sliders->addWidget(ThreadsText);

        RunButton = new QPushButton(centralwidget);
        RunButton->setObjectName(QString::fromUtf8("RunButton"));
        RunButton->setGeometry(QRect(540, 580, 301, 51));
        RunButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(115, 210, 22);\n"
"	color: white;\n"
"	border: 2px solid white;\n"
"}"));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 40, 161, 231));
        GraphButtons = new QVBoxLayout(layoutWidget1);
        GraphButtons->setSpacing(20);
        GraphButtons->setObjectName(QString::fromUtf8("GraphButtons"));
        GraphButtons->setSizeConstraint(QLayout::SetNoConstraint);
        GraphButtons->setContentsMargins(0, 0, 0, 0);
        AddVertexButton = new QPushButton(layoutWidget1);
        AddVertexButton->setObjectName(QString::fromUtf8("AddVertexButton"));
        sizePolicy1.setHeightForWidth(AddVertexButton->sizePolicy().hasHeightForWidth());
        AddVertexButton->setSizePolicy(sizePolicy1);
        AddVertexButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(115, 210, 22);\n"
"	color: white;\n"
"	border: 2px solid white;\n"
"}"));

        GraphButtons->addWidget(AddVertexButton);

        RemoveVertexButton = new QPushButton(layoutWidget1);
        RemoveVertexButton->setObjectName(QString::fromUtf8("RemoveVertexButton"));
        sizePolicy1.setHeightForWidth(RemoveVertexButton->sizePolicy().hasHeightForWidth());
        RemoveVertexButton->setSizePolicy(sizePolicy1);
        RemoveVertexButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(115, 210, 22);\n"
"	color: white;\n"
"	border: 2px solid white;\n"
"}"));

        GraphButtons->addWidget(RemoveVertexButton);

        ClearVerticlesButton = new QPushButton(layoutWidget1);
        ClearVerticlesButton->setObjectName(QString::fromUtf8("ClearVerticlesButton"));
        sizePolicy1.setHeightForWidth(ClearVerticlesButton->sizePolicy().hasHeightForWidth());
        ClearVerticlesButton->setSizePolicy(sizePolicy1);
        ClearVerticlesButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(115, 210, 22);\n"
"	color: white;\n"
"	border: 2px solid white;\n"
"}"));

        GraphButtons->addWidget(ClearVerticlesButton);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(80, 550, 208, 83));
        AlgoLayout = new QVBoxLayout(layoutWidget2);
        AlgoLayout->setObjectName(QString::fromUtf8("AlgoLayout"));
        AlgoLayout->setContentsMargins(0, 0, 0, 0);
        SACheckBox = new QCheckBox(layoutWidget2);
        SACheckBox->setObjectName(QString::fromUtf8("SACheckBox"));
        SACheckBox->setChecked(false);
        SACheckBox->setTristate(false);

        AlgoLayout->addWidget(SACheckBox);

        ACOCheckBox = new QCheckBox(layoutWidget2);
        ACOCheckBox->setObjectName(QString::fromUtf8("ACOCheckBox"));

        AlgoLayout->addWidget(ACOCheckBox);

        PSOCheckBox = new QCheckBox(layoutWidget2);
        PSOCheckBox->setObjectName(QString::fromUtf8("PSOCheckBox"));

        AlgoLayout->addWidget(PSOCheckBox);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(1040, 100, 258, 301));
        CostLayout = new QVBoxLayout(layoutWidget3);
        CostLayout->setObjectName(QString::fromUtf8("CostLayout"));
        CostLayout->setContentsMargins(0, 0, 0, 0);
        CostLabel = new QLabel(layoutWidget3);
        CostLabel->setObjectName(QString::fromUtf8("CostLabel"));
        CostLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color: white;\n"
"}"));
        CostLabel->setFrameShape(QFrame::WinPanel);

        CostLayout->addWidget(CostLabel);

        CostText = new QLineEdit(layoutWidget3);
        CostText->setObjectName(QString::fromUtf8("CostText"));
        CostText->setEnabled(true);
        sizePolicy1.setHeightForWidth(CostText->sizePolicy().hasHeightForWidth());
        CostText->setSizePolicy(sizePolicy1);
        CostText->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: rgb(135, 243, 96);\n"
"}"));
        CostText->setAlignment(Qt::AlignCenter);
        CostText->setReadOnly(true);

        CostLayout->addWidget(CostText);

        InfoSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        CostLayout->addItem(InfoSpacer);

        ImprovementsLabel = new QLabel(layoutWidget3);
        ImprovementsLabel->setObjectName(QString::fromUtf8("ImprovementsLabel"));
        ImprovementsLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color: white;\n"
"}"));
        ImprovementsLabel->setFrameShape(QFrame::WinPanel);

        CostLayout->addWidget(ImprovementsLabel);

        ImprovementsText = new QLineEdit(layoutWidget3);
        ImprovementsText->setObjectName(QString::fromUtf8("ImprovementsText"));
        ImprovementsText->setEnabled(true);
        sizePolicy1.setHeightForWidth(ImprovementsText->sizePolicy().hasHeightForWidth());
        ImprovementsText->setSizePolicy(sizePolicy1);
        ImprovementsText->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: rgb(135, 243, 96);\n"
"}"));
        ImprovementsText->setAlignment(Qt::AlignCenter);
        ImprovementsText->setReadOnly(true);

        CostLayout->addWidget(ImprovementsText);

        progressSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        CostLayout->addItem(progressSpacer);

        AlgorithmsProgressBar = new QProgressBar(layoutWidget3);
        AlgorithmsProgressBar->setObjectName(QString::fromUtf8("AlgorithmsProgressBar"));
        AlgorithmsProgressBar->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(AlgorithmsProgressBar->sizePolicy().hasHeightForWidth());
        AlgorithmsProgressBar->setSizePolicy(sizePolicy2);
        AlgorithmsProgressBar->setValue(0);

        CostLayout->addWidget(AlgorithmsProgressBar);

        MapOfPoland = new QLabel(centralwidget);
        MapOfPoland->setObjectName(QString::fromUtf8("MapOfPoland"));
        MapOfPoland->setEnabled(true);
        MapOfPoland->setGeometry(QRect(390, 30, 581, 511));
        sizePolicy2.setHeightForWidth(MapOfPoland->sizePolicy().hasHeightForWidth());
        MapOfPoland->setSizePolicy(sizePolicy2);
        MapOfPoland->setCursor(QCursor(Qt::CrossCursor));
        MapOfPoland->setMouseTracking(true);
        MapOfPoland->setFrameShape(QFrame::NoFrame);
        MapOfPoland->setPixmap(QPixmap(QString::fromUtf8("../map_of_poland.png")));
        MapOfPoland->setScaledContents(true);
        TSPSolver->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TSPSolver);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1408, 22));
        TSPSolver->setMenuBar(menubar);
        statusbar = new QStatusBar(TSPSolver);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TSPSolver->setStatusBar(statusbar);

        retranslateUi(TSPSolver);

        QMetaObject::connectSlotsByName(TSPSolver);
    } // setupUi

    void retranslateUi(QMainWindow *TSPSolver)
    {
        TSPSolver->setWindowTitle(QCoreApplication::translate("TSPSolver", "MainWindow", nullptr));
        TimeLabel->setText(QCoreApplication::translate("TSPSolver", "Czas oczekiwania:", nullptr));
        ThreadsLabel->setText(QCoreApplication::translate("TSPSolver", "Liczba w\304\205tk\303\263w", nullptr));
        RunButton->setText(QCoreApplication::translate("TSPSolver", "RUN!", nullptr));
        AddVertexButton->setText(QCoreApplication::translate("TSPSolver", "Dodaj punkt na mapie", nullptr));
        RemoveVertexButton->setText(QCoreApplication::translate("TSPSolver", "Usu\305\204 punkt z mapy", nullptr));
        ClearVerticlesButton->setText(QCoreApplication::translate("TSPSolver", "Wyczy\305\233\304\207 map\304\231", nullptr));
        SACheckBox->setText(QCoreApplication::translate("TSPSolver", "Symulowane wy\305\274arzanie", nullptr));
        ACOCheckBox->setText(QCoreApplication::translate("TSPSolver", "Kolonia mr\303\263wek", nullptr));
        PSOCheckBox->setText(QCoreApplication::translate("TSPSolver", "R\303\263j cz\304\205stek", nullptr));
        CostLabel->setText(QCoreApplication::translate("TSPSolver", "Szacowany czas przejazdu:", nullptr));
        ImprovementsLabel->setText(QCoreApplication::translate("TSPSolver", "Poprawa nr: ", nullptr));
        MapOfPoland->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TSPSolver: public Ui_TSPSolver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
