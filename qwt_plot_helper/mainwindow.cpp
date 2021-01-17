
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtMath>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    this->initialisePlot();
    this->populatePlot();

    // Initialise Timer
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updatePlot()));
    m_timer->setInterval(50);
    m_timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialisePlot(void)
{
    m_plot = new QwtPlotHelper(this);
    ui->grid->addWidget(m_plot, 0, 0);
    m_plot->setAxisTitle( QwtPlot::yLeft, "Y Axis" );
    m_plot->setAxisTitle( QwtPlot::xBottom, "X Axis" );
}

void MainWindow::populatePlot(void)
{
    QColor curve_color = QColor("#039BE5");
    int values_size = 100;
    m_curve_1_id = "curve_1";
    m_curve_1_x = new QVector<double>;
    m_curve_1_y = new QVector<double>;
    m_curve_1_index = 0;

    // Create the base data arrays that will be displayes
    m_curve_1_x->resize(values_size);
    m_curve_1_y->resize(values_size);

    for(int i = 0; i < values_size; i++)
    {
        (*m_curve_1_x)[i] = i;
        (*m_curve_1_y)[i] = sin(i / (M_PI*2) + 0.5);
    }
    m_curve_1_index = 99;

    // Add a curve with the base data arrays to the plot
    m_plot->addCurve(m_curve_1_id, curve_color, m_curve_1_x, m_curve_1_y, values_size);
}

void MainWindow::updatePlot(void)
{
    QString curve_id = "curve_1";

    // Update the data arrays
    m_curve_1_index += 1;
    m_curve_1_x->push_back(m_curve_1_index);
    m_curve_1_x->pop_front();
    m_curve_1_y->push_back(sin(m_curve_1_index / (M_PI*2) + 0.5));
    m_curve_1_y->pop_front();

    // Update the curve with the new data arrays
    m_plot->updateCurve(m_curve_1_id, m_curve_1_x, m_curve_1_y, m_curve_1_x->length());

    // Update the plot itself.
    // NOTE: if this function isn't called, the plot won't be redrawn
    m_plot->replot();
}

