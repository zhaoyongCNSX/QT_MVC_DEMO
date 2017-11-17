#include "stdafx.h"
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


#include "MyDelegate.h"

Widget::Widget(QWidget *parent) 
	:QWidget(parent)
	, ui(new Ui::Widget)
	, m_model(new QFileSystemModel(this))
	, m_delegate(new MyDelegate())
{
    ui->setupUi(this);

    ui->m_view->setModel(m_model);
	ui->m_view->setItemDelegate(m_delegate);

    m_model->setRootPath("");

    ui->m_view->setRootIndex(m_model->index(""));
    ui->m_view->setViewMode(QListView::IconMode);
	ui->m_view->setSpacing(20);
	ui->m_view->setResizeMode(QListView::Adjust);
	ui->m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	ui->m_view->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);	//滚动单位为 item  可选px
	ui->m_view->setSelectionRectVisible(false);
	ui->m_view->setFlow(QListView::TopToBottom);	//从上到下布局

	ui->m_view->setDragEnabled(false);

	//ui->m_view->setAutoScroll(true);

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

		ui->m_view->setCurrentIndex(ui->m_view->currentIndex());
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
