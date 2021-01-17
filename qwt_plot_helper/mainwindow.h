#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "qwtplothelper.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updatePlot(void);

private: // Methods
    void initialisePlot(void);
    void populatePlot(void);


private: // Members
    Ui::MainWindow *ui;
    QwtPlotHelper* m_plot;
    QTimer* m_timer;

    QString m_curve_1_id;
    QVector <double>* m_curve_1_x;
    QVector <double>* m_curve_1_y;
    int m_curve_1_index;

};
#endif // MAINWINDOW_H
