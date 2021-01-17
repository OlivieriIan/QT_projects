#ifndef QWTPLOTHELPER_H
#define QWTPLOTHELPER_H

#include <QObject>
#include <QWidget>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

class QwtPlotHelper : public QwtPlot
{
    Q_OBJECT
public:
    QwtPlotHelper( QWidget *parent = nullptr );
    ~QwtPlotHelper();

    /**
     * @brief Add new curve to plot
     * @param curveID: Identifier of the curve used for its manipulation
     * (update, delete, enable/disable). This string will be shown in the legend.
     * @param curveColor: color of the curve to be added
     * @param xVec: x axis data vector
     * @param yVec: y axis data vector
     * @param vecSize: passed vector size
     * @return true if operation successful, false otherwise
     */
    bool addCurve (
        const QString&             curveID,
        const QColor&              curveColor,
        const QVector<double>*     xVec,
        const QVector<double>*     yVec,
        int                        vecSize
    );

    /**
     * @brief Updates the first curve that matches the the given ID
     * @param curveID: ID of the curve to be updated
     * @param xVec: updated x axis data vector
     * @param yVec: updated y axis data vector
     * @param vecSize: size of the updated vector
     * @return true if operation successful, false otherwise
     */
    bool updateCurve(
        const QString& curveID,
        const QVector<double>* xVec,
        const QVector<double>* yVec,
        int vecSize
    );

    /**
     * @brief Enables/disables the first curve that matches the the given ID
     * @param curveID: ID of the curve to be enabled/disabled
     * @param enabled: true if the curve should be shown, false to hide id
     * @return true if operation successful, false otherwise
     */
    bool enableCurve(const QString& curveID, bool enabled);

    /**
     * @brief Removes the first curve that matches the the given ID
     * @param curveID: ID of the curve to be removed
     * @return true if operation successful, false otherwise
     */
    bool removeCurve(const QString& curveID);

    /**
     * @brief Removes all the curves from the plot
     */
    void removeAllCurves(void);

private: // Methods
    /**
     * @brief Finds the first curve with the given ID and returns it if it exists
     * @param curveID: ID of the curve to be searched
     * @return Pointer to the found curve if it exists, nullptr if it doesn't
     */
    QwtPlotCurve* findCurve(const QString& curveID);
};

#endif // QWTPLOTHELPER_H
