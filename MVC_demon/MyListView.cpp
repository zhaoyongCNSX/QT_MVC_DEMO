#include "stdafx.h"
#include "MyListView.h"


MyListView::MyListView(QWidget *parent /*= NULL*/)
	: QListView(parent)
{
	//setCurrentIndex();

	//setCurrentIndex()
}

MyListView::~MyListView()
{
}

void MyListView::currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
	qDebug() << "Pre Rect: " << rectForIndex(previous);
	qDebug() << "crt Rect: " << rectForIndex(current);


	scrollTo(current, QAbstractItemView::PositionAtBottom);

}
