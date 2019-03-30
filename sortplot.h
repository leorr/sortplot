#ifndef SORTPLOT_H
#define SORTPLOT_H

#include <QMainWindow>

namespace Ui {
class sortplot;
}

class sortplot : public QMainWindow
{
    Q_OBJECT

public:
    explicit sortplot(QWidget *parent = nullptr);
    ~sortplot();

private:
    Ui::sortplot *ui;
};

#endif // SORTPLOT_H
