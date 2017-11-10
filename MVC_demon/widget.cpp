#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
  , m_model(new QFileSystemModel(this))
{
    ui->setupUi(this);

    ui->m_view->setModel(m_model);
    m_model->setRootPath("");

    ui->m_view->setRootIndex(m_model->index(""));

    ui->m_view->setViewMode(QListView::IconMode);

    connect(ui->m_view, &QListView::clicked, this, &Widget::SLOT_viewItemClicked);

    UpdateCrtRootPath();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::SLOT_viewItemClicked(const QModelIndex &index)
{
    if (index.isValid()) {
        ui->m_view->setRootIndex(index);
    }

    UpdateCrtRootPath();
}

void Widget::on_pushButton_clicked()
{
    QModelIndex nIndex = ui->m_view->rootIndex();

    QString nPath = m_model->filePath(nIndex);


    QDir nDir(nPath);
    qDebug() << "dir path: " << nDir.absolutePath();
    if (nDir.isRoot()) {
        ui->m_view->setRootIndex(m_model->index(""));
    } else {
        if (nDir.cdUp()) {
            qDebug() << "cdUp path: " << nDir.absolutePath();
            QModelIndex nCrtIndex = m_model->index(nDir.absolutePath());
            if (nCrtIndex.isValid()) {
                ui->m_view->setRootIndex(nCrtIndex);
            }
        }
    }

    UpdateCrtRootPath();

}

void Widget::UpdateCrtRootPath()
{
    QModelIndex nIndex = ui->m_view->rootIndex();
    QString nPath = m_model->filePath(nIndex);

    ui->crtPath->setText(QString("Crt Path: %1").arg(nPath));
}
