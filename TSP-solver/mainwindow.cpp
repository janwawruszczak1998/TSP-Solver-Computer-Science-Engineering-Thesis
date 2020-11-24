#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QCursor>
#include <QMouseEvent>
#include <QPixmap>
#include <qpainter.h>
#include <QScreen>
#include <vector>
#include <algorithm>
#include <cmath>
#include <QSlider>

extern tsp::Graph<double, std::vector> graph;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
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
    else if(number_of_threads > 1 && number_of_threads < 4){
        ui->ThreadsText->setText(QString::number(number_of_threads) + " wątki");
    }
    else{
        ui->ThreadsText->setText(QString::number(number_of_threads) + " wątków");

    }
}

void MainWindow::run_algorithms(){

    //preprocessing
    unsigned n = graph.get_order();
    double **dp;
    dp = new double *[1 << n];
    for (unsigned i = 0; i < (1 << n); ++i) dp[i] = new double[n];

    for (unsigned i = 0; i < (1 << n); ++i) {
        for (unsigned j = 0; j < n; ++j) {
            dp[i][j] = 1 << 30;    //wypełnienie tablicy tras nieskończonościami
        }
    }


    for (unsigned i = 0; i < n; ++i) {
        dp[(1 << i) |
           1][i] = graph.get_distance(0,i); //na początku koszt jednokrawędziowej ścieżki Hamiltona z 0 do I to po prostu koszt krawędzi
    }

    //dynamic programming
    for (unsigned bitMask = 0; bitMask < (1 << n); ++bitMask) {                        //dla każdej maski bitowej liczymy trasy
        for (unsigned v = 0; v < n; ++v) {                                             //rozważamy trasy zakończone w wierzchołku V
            if (!(bitMask & (1 << v))) {
                continue;                                                          //jeżeli w ścieżce nie ma w ogóle wierzchołja V, to pomijamy
            }
            for (unsigned j = 0; j < n; ++j) {                                         //patrzymy, do którego wierzchołka J możemy dojść z V
                if (!(bitMask & (1 << j))) {                                     //jeśli wierzchołka J nie ma w trasie
                    dp[bitMask | (1 << j)][j]
                        = std::min(dp[bitMask][v] + graph.get_distance(v,j), dp[bitMask |(1 << j)][j]);    //jeżeli koszt dojścia do V i przejścia do J jest mniejszy od aktualnie najlepszego osiągnięcia J, to zaktualizuj
                }
            }
        }
    }

    //ustalenie resultu
    unsigned result = 1e9;
    for (unsigned v = 0; v < n; ++v) {
        unsigned act = dp[(1 << n) - 1][v] +
                  graph.get_distance(v,0); //koszt "powrotu" z wierzchołka v do wierzchołka 0
        if (result > act) result = act;
    }

    //zwolnienie pamięci
    for (unsigned i = 0; i < (1 << n); ++i) {
        delete[] dp[i];
    }
    delete[] dp;

    std::cout << "Najtańszy cykl Hamiltona wyznaczona DP: " << result << std::endl;
    time_of_travel = result;
    ui->CostText->setText(QString::number(result) + " jednostek");
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
        QPoint point;
        point.setX( ((cursor().pos().x() - ui->MapOfPoland->geometry().x() + left_os_navigation_bar_size) * (pixmap.width())) / ui->MapOfPoland->width() );
        point.setY( ((cursor().pos().y() - ui->MapOfPoland->geometry().y() + bottom_os_navigation_bar_size) * (pixmap.height())) / ui->MapOfPoland->height() );

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

            graph.add_vertex(
                        ((cursor().pos().x() - ui->MapOfPoland->geometry().x() + left_os_navigation_bar_size) * (pixmap.width())) / ui->MapOfPoland->width(),
                        ((cursor().pos().y() - ui->MapOfPoland->geometry().y() + bottom_os_navigation_bar_size) * (pixmap.height())) / ui->MapOfPoland->height()
                        );
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

