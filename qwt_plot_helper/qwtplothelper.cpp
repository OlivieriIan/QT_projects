/* =================== Includes ============================================ */
#include "qwtplothelper.h"

#include <qwt_plot_grid.h>

/* =================== Private Data Declaration ============================ */

/* =================== Private Function Definition ========================= */

/* =================== Public Class Methods Definition ===================== */

QwtPlotHelper::QwtPlotHelper(QWidget *parent):
    QwtPlot( parent )
{
    this->setCanvasBackground(QColor(Qt::white));
    this->canvas()->setCursor(Qt::ArrowCursor);

    // Plot Grid configuration
    QwtPlotGrid* grid = new QwtPlotGrid();

    grid->enableXMin(true);
    grid->enableYMin(true);
    grid->setMajorPen(QPen(QBrush(QColor(220,220,220)), 0, Qt::DotLine));
    grid->setMinorPen(QPen(QColor(240,240,240)));
    grid->attach( this );
} /* QwtPlotHelper::QwtPlotHelper */

QwtPlotHelper::~QwtPlotHelper()
{

} /* QwtPlotHelper::~QwtPlotHelper */

bool QwtPlotHelper::addCurve (
    const QString&             curveID,
    const QColor&              curveColor,
    const QVector<double>*     xVec,
    const QVector<double>*     yVec,
    int                        vecSize
) {

    bool success = true;
    QwtPlotCurve* curve = new QwtPlotCurve(curveID);
    curve->setPen(QPen(curveColor));
    if(xVec == nullptr || yVec == nullptr)
        curve->setRawSamples(nullptr, nullptr, 0);
    else
        curve->setSamples(xVec->data(), yVec->data(), vecSize);

    curve->attach(this);

    return(success);
} /* QwtPlotHelper::addCurve */

bool QwtPlotHelper::updateCurve(
    const QString&              curveID,
    const QVector<double>*      xVec,
    const QVector<double>*      yVec,
    int                         vecSize
) {
    bool success = true;
    QwtPlotCurve* curve = findCurve(curveID);
    if(curve == nullptr)
        success = false;
    else
        curve->setSamples(xVec->data(), yVec->data(), vecSize);

    return(success);
} /* QwtPlotHelper::updateCurve */

bool QwtPlotHelper::enableCurve(const QString& curveID, bool enabled)
{
    bool success = true;
    QwtPlotCurve* curve = findCurve(curveID);
    if(curve == nullptr)
    {
        success = false;
    }
    else
    {
        if(enabled) curve->show();
        else        curve->hide();
    }

    return(success);
} /* QwtPlotHelper::enableCurve */


bool QwtPlotHelper::removeCurve(const QString& curveID)
{
    bool success = true;
    QwtPlotCurve* curve = findCurve(curveID);
    if(curve == nullptr)
        success = false;
    else
        delete curve;

    return(success);
} /* QwtPlotHelper::removeCurve */


void QwtPlotHelper::removeAllCurves(void)
{
    QList<QwtPlotItem *> curveList = itemList(QwtPlotItem::Rtti_PlotCurve);
    while( curveList.size() > 0 )
    {
        QwtPlotItem* curve = curveList.takeFirst();
        delete curve;
    }
} /* QwtPlotHelper::removeAllCurves */

/* =================== Public Slots Definition ============================= */

/* =================== Private Class Methods Definition ==================== */
QwtPlotCurve* QwtPlotHelper::findCurve(const QString& curveID)
{ //QwtPlotItemList = QList<QwtPlotItem *>
    QList<QwtPlotItem *> curveList = itemList(QwtPlotItem::Rtti_PlotCurve);
    // iterate though the list to find the item to be deleted
    int curveNum = 0;
    for(curveNum = 0; curveNum < curveList.size(); curveNum++)
    {
        QwtPlotCurve* curve = static_cast<QwtPlotCurve*>(curveList.at(curveNum));
        if(curve->title() == curveID)// If the curve is in the list, delete it
        {
            return(curve); // Curve found, return it
        }
    }
    return(nullptr);
} /* QwtPlotHelper::findCurve */
/* =================== Private Slots Definition ============================ */

/* =================== Private Function Definition ========================= */

/* =================== End of File ========================================= */
