#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QCursor>
#include <QMouseEvent>
#include <QPixmap>
#include <qpainter.h>

extern tsp::Graph<double, std::vector> graph;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // graph manipulation buttons
    std::vector<QPushButton*> graph_buttons(3);
    QString add_button_name = "AddVertexButton";
    QString remove_button_name = "RemoveVertexButton";
    QString clear_button_name = "ClearVerticlesButton";

    graph_buttons[0] = MainWindow::findChild<QPushButton*>(add_button_name);
    graph_buttons[1] = MainWindow::findChild<QPushButton*>(remove_button_name);
    graph_buttons[2] = MainWindow::findChild<QPushButton*>(clear_button_name);

    connect(graph_buttons[0], SIGNAL(released()), this, SLOT(click_add_vertex()));
    connect(graph_buttons[1], SIGNAL(released()), this, SLOT(click_remove_vertex()));
    connect(graph_buttons[2], SIGNAL(released()), this, SLOT(click_clear_graph()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click_add_vertex(){
    QWidget* map_ptr = MainWindow::findChild<QWidget*>("MapOfPoland");
    cursor().setPos(map_ptr->geometry().x() + map_ptr->geometry().width() / 2, map_ptr->geometry().y() + map_ptr->geometry().height() / 2);
    adding_vertex_required = true;
}

void MainWindow::click_remove_vertex(){
    if(graph.get_order()){
        QWidget* map_ptr = MainWindow::findChild<QWidget*>("MapOfPoland");
        cursor().setPos(map_ptr->geometry().x() + map_ptr->geometry().width() / 2, map_ptr->geometry().y() + map_ptr->geometry().height() / 2);
        removing_vertex_required = true;
    }
}

void MainWindow::click_clear_graph(){
    QPixmap basic_map("../map_of_poland.png");
    ui->MapOfPoland->setPixmap(basic_map);
    while(graph.get_order()){
        graph.remove_vertex(0);
    }
    graph.display_graph();
}

void MainWindow::mousePressEvent(QMouseEvent* event) {
    if(event->button() == Qt::LeftButton){
        if(adding_vertex_required){

            ui->MapOfPoland->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
            QPixmap pixmap = QPixmap(ui->MapOfPoland->pixmap()->copy());
            QPainter painter(&pixmap);
            QPen pen(Qt::red, 20, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
            QPoint point;
            std::cout << "cursor.x " << cursor().pos().x() << " pixmap.width " << pixmap.width() << " sz. ekranu " << this->width() << " pozycja mapki " << ui->MapOfPoland->geometry().x() << " szerokosc mapki "<< ui->MapOfPoland->width() << " wartosc " << (cursor().pos().x()- ui->MapOfPoland->geometry().x()) * ((pixmap.width()))<< " "<<(580 * 2061)/581<<" "<<ui->MapOfPoland->width()*1737;
            point.setX( ((cursor().pos().x()- ui->MapOfPoland->geometry().x()) * (pixmap.width()))/581);
            point.setY(0);

            painter.setPen(pen);
            painter.drawPoint(point);

            ui->MapOfPoland->setPixmap(pixmap);
            ui->MapOfPoland->setScaledContents(true);
            painter.end();

            graph.add_vertex(
                        cursor().pos().x(),
                        cursor().pos().y()
                        );
            graph.display_graph();
            adding_vertex_required = false;
        }
        else if(removing_vertex_required){
            graph.remove_vertex(
                        std::move(cursor().pos().x()),
                        std::move(cursor().pos().y())
                        );
            graph.display_graph();
            removing_vertex_required = false;
        }

    }
}

