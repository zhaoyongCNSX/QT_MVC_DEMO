#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QFileSystemModel>



namespace Ui {
class Widget;
}

class MyDelegate;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private slots:
    void SLOT_viewItemClicked(const QModelIndex &index);
    void on_pushButton_clicked();

private:
    void UpdateCrtRootPath();
private:
    Ui::Widget *ui;

    QFileSystemModel *m_model;
	MyDelegate *m_delegate;
};

#endif // WIDGET_H
