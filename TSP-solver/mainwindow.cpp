#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "strategy.h"
#include "aco.h"
#include "sa.h"
#include "pso.h"
#include "dynamicprogrammingalgorithm.h"

#include <QCursor>
#include <QMouseEvent>
#include <QPixmap>
#include <qpainter.h>
#include <QScreen>
#include <QSlider>


#include <thread>
#include <algorithm>
#include <cmath>
#include <vector>


MainWindow::MainWindow(tsp::Graph<double, std::vector>& graph_, QWidget *parent)
    : QMainWindow(parent)
    , graph(graph_)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->TimeText->setText(QString::number(1) + " min");
    ui->ThreadsText->setText(QString::number(1) + " wątek");
    ui->CostText->setText("-----");


    // buttons
    std::vector<QPushButton*> buttons(4);
    QString add_button_name = "AddVertexButton";
    QString remove_button_name = "RemoveVertexButton";
    QString clear_button_name = "ClearVerticlesButton";
    QString run_button_name = "RunButton";

    buttons[0] = MainWindow::findChild<QPushButton*>(add_button_name);
    buttons[1] = MainWindow::findChild<QPushButton*>(remove_button_name);
    buttons[2] = MainWindow::findChild<QPushButton*>(clear_button_name);
    buttons[3] = MainWindow::findChild<QPushButton*>(run_button_name);

    connect(buttons[0], SIGNAL(released()), this, SLOT(click_add_vertex()));
    connect(buttons[1], SIGNAL(released()), this, SLOT(click_remove_vertex()));
    connect(buttons[2], SIGNAL(released()), this, SLOT(click_clear_graph()));
    connect(buttons[3], SIGNAL(released()), this, SLOT(run_algorithms()));

    // algorithms parameter checkboxes

    // sliders setting parameters
    QString time_slider_name = "TimeSlider";
    QString threads_slider_name = "ThreadsSlider";

    QSlider* time_slider = MainWindow::findChild<QSlider*>(time_slider_name);
    QSlider* threads_slider = MainWindow::findChild<QSlider*>(threads_slider_name);

    connect(time_slider, SIGNAL(valueChanged(int)), this, SLOT(set_time_of_running()));
    connect(threads_slider, SIGNAL(valueChanged(int)), this, SLOT(set_number_of_threads()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_time_of_running(){
    time_of_running = ui->TimeSlider->value() + 1;
    ui->TimeText->setText(QString::number(time_of_running) + " min");

}

void MainWindow::set_number_of_threads(){
    number_of_threads = ui->ThreadsSlider->value() + 1;
    if(number_of_threads == 1){
        ui->ThreadsText->setText(QString::number(number_of_threads) + " wątek");
    }
    else if(number_of_threads > 1 && number_of_threads < 5){
        ui->ThreadsText->setText(QString::number(number_of_threads) + " wątki");
    }
    else{
        ui->ThreadsText->setText(QString::number(number_of_threads) + " wątków");

    }
}

void MainWindow::run_algorithms(){
    if(graph.get_order() < 3){
        return;
    }

    bool aco{MainWindow::findChild<QCheckBox*>("ACOCheckBox")->isChecked()},
    pso{MainWindow::findChild<QCheckBox*>("PSOCheckBox")->isChecked()},
    sa{MainWindow::findChild<QCheckBox*>("SACheckBox")->isChecked()};
    int num_of_choosen_algorithms{0};
    if(aco){
        num_of_choosen_algorithms++;
    }
    if(pso){
        num_of_choosen_algorithms++;
    }
    if(sa){
        num_of_choosen_algorithms++;
    }

    unsigned available_minutes{0};

    if(num_of_choosen_algorithms){
        available_minutes /= num_of_choosen_algorithms;
    }


    algorithms.resize(number_of_threads);
    std::vector<unsigned> path_to_draw(graph.get_order());


    time_of_travel = 1000000000;
    if(sa){
        for(unsigned i = 0; i < number_of_threads; ++i){
            algorithms[i] = std::make_unique<SA>(graph, time_of_travel, path_to_draw);
        }
        for(auto& algorithm : algorithms){
            algorithm->get_algo_thread().join();
        }
    }


    if(aco){
        for(unsigned i = 0; i < number_of_threads; ++i){
            algorithms[i] = std::make_unique<ACO>(graph, time_of_travel, path_to_draw);
        }
        for(auto& algorithm : algorithms){
            algorithm->get_algo_thread().join();
        }
    }

    if(pso){
        for(unsigned i = 0; i < number_of_threads; ++i){
            algorithms[i] = std::make_unique<PSO>(graph, time_of_travel, path_to_draw);
        }
        for(auto& algorithm : algorithms){
            algorithm->get_algo_thread().join();
        }
    }


    if(!sa && !aco && !pso && graph.get_order() < 15){
        algorithms[0] = std::make_unique<DP>(graph, time_of_travel, path_to_draw);
        ui->CostText->setText(QString::number(time_of_travel) + " jednostek");
        print_route(path_to_draw);
    }
    else if(!sa && !aco && !pso && graph.get_order() >= 15){
        ui->CostText->setText("Proszę wybrać algorytmy");
    }
    else{
        ui->CostText->setText(QString::number(time_of_travel) + " jednostek");
        print_route(path_to_draw);
    }
}

void MainWindow::click_add_vertex(){
    addition_vertex_required = true;
    removal_vertex_required = false;
}

void MainWindow::click_remove_vertex(){
    if(graph.get_order()){
        removal_vertex_required = true;
        addition_vertex_required = false;
    }
}
void mousePressEvent(QMouseEvent* = nullptr);

void MainWindow::click_clear_graph(){
    QPixmap basic_map("../map_of_poland.png");
    ui->MapOfPoland->setPixmap(basic_map);
    array_of_points.clear();
    while(graph.get_order()){
        graph.remove_vertex(0);
    }
    graph.display_graph();
    ui->CostText->setText("-----");
}

void MainWindow::mousePressEvent(QMouseEvent* event) {
    //if cursor outside map
    const int bottom_os_navigation_bar_size = this->height() - QGuiApplication::primaryScreen()->geometry().height();
    const int left_os_navigation_bar_size = this->width() - QGuiApplication::primaryScreen()->geometry().width();

    if(cursor().pos().x() < ui->MapOfPoland->geometry().x() - left_os_navigation_bar_size
    || cursor().pos().x() > ui->MapOfPoland->geometry().x() + ui->MapOfPoland->width() - left_os_navigation_bar_size
    || cursor().pos().y() < ui->MapOfPoland->geometry().y() - bottom_os_navigation_bar_size
    || cursor().pos().y() > ui->MapOfPoland->geometry().y() + ui->MapOfPoland->height() - bottom_os_navigation_bar_size
    ){return;}

    if(event->button() == Qt::LeftButton){
        QPixmap pixmap = QPixmap(ui->MapOfPoland->pixmap()->copy());
        auto x_value = ((cursor().pos().x() - ui->MapOfPoland->geometry().x() + left_os_navigation_bar_size) * (pixmap.width())) / ui->MapOfPoland->width();
        auto y_value = ((cursor().pos().y() - ui->MapOfPoland->geometry().y() + bottom_os_navigation_bar_size) * (pixmap.height())) / ui->MapOfPoland->height();

        QPoint point;
        point.setX(x_value);
        point.setY(y_value);

        if(addition_vertex_required){

            if(std::find_if(array_of_points.begin(), array_of_points.end(),
                [&point](const QPoint& m_point)
                {return m_point.x() == point.x() && m_point.y() == point.y();}) == array_of_points.end()
            ){
                array_of_points.push_back(point);
            }

            ui->MapOfPoland->setPixmap(QPixmap("../map_of_poland.png"));
            pixmap = QPixmap(ui->MapOfPoland->pixmap()->copy());
            QPainter painter(&pixmap);
            painter.setPen(QPen(Qt::red, 30, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin));

            for(const auto& point_to_draw : array_of_points){
                painter.drawPoint(point_to_draw);
            }

            ui->MapOfPoland->setPixmap(pixmap);
            painter.end();

            graph.add_vertex(x_value, y_value);

            graph.display_graph();
            addition_vertex_required = false;
        }
        else if(removal_vertex_required){
            const auto array_iterator = std::find_if(array_of_points.begin(), array_of_points.end(),
                                    [&point](const QPoint& m_point)
                                    {return std::abs(m_point.x() - point.x()) < 20 && std::abs(m_point.y() - point.y()) < 20;});
            if(array_iterator != array_of_points.end()){
                array_of_points.erase(array_iterator);
            }
            else{return;}

            ui->MapOfPoland->setPixmap(QPixmap("../map_of_poland.png"));
            pixmap = QPixmap(ui->MapOfPoland->pixmap()->copy());
            QPainter painter(&pixmap);
            painter.setPen(QPen(Qt::red, 30, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin));

            for(const auto& point_to_draw : array_of_points){
                painter.drawPoint(point_to_draw);
            }

            ui->MapOfPoland->setPixmap(pixmap);
            painter.end();

            graph.remove_vertex(
                        ((cursor().pos().x() - ui->MapOfPoland->geometry().x() + left_os_navigation_bar_size) * (pixmap.width())) / ui->MapOfPoland->width(),
                        ((cursor().pos().y() - ui->MapOfPoland->geometry().y() + bottom_os_navigation_bar_size) * (pixmap.height())) / ui->MapOfPoland->height()
                        );
            graph.display_graph();
            removal_vertex_required = false;
        }

    }
}

void MainWindow::print_route(std::vector<unsigned> vertices_order){
    const int bottom_os_navigation_bar_size = height() - QGuiApplication::primaryScreen()->geometry().height();
    const int left_os_navigation_bar_size = width() - QGuiApplication::primaryScreen()->geometry().width();

    ui->MapOfPoland->setPixmap(QPixmap("../map_of_poland.png"));
    QPixmap pixmap = QPixmap(ui->MapOfPoland->pixmap()->copy());
    QPainter painter(&pixmap);

    painter.setPen(QPen(Qt::red, 30, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    for(const auto& vertex : graph.get_vertices_localization()){
        QPoint v;
        v.setX(vertex.second.get_x()); v.setY(vertex.second.get_y());
        painter.drawPoint(v);
    }

    painter.setPen(QPen(Qt::blue, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    for(unsigned i = 0; i < vertices_order.size(); ++i){
        const unsigned vertex_id = vertices_order[i];
        const unsigned succesor_id = vertices_order[(i + 1) % vertices_order.size()];
        std::pair<int, Point<double>> f_localization = *std::find_if(graph.get_vertices_localization().begin(), graph.get_vertices_localization().end(), [&](auto pair){
            return pair.first == vertex_id;
        });
        std::pair<int, Point<double>> s_localization = *std::find_if(graph.get_vertices_localization().begin(), graph.get_vertices_localization().end(), [&](auto pair){
            return pair.first == succesor_id;
        });
        QPoint p1, p2;

        p1.setX(f_localization.second.get_x()); p1.setY(f_localization.second.get_y());
        p2.setX(s_localization.second.get_x()); p2.setY(s_localization.second.get_y());
        painter.drawLine(p1, p2);

    }
    ui->MapOfPoland->setPixmap(pixmap);
    painter.end();
}
