#include "stdafx.h"
#include "MyDelegate.h"


MyDelegate::MyDelegate()
	: QStyledItemDelegate(NULL)
{
}


MyDelegate::~MyDelegate()
{
}

void MyDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

#if 1
	painter->save();

	if (option.state & QStyle::State_HasFocus) {
		painter->setPen(Qt::black);
		painter->setBrush(QBrush(Qt::red));
	}
	else if (option.state & QStyle::State_MouseOver) {
		painter->setPen(Qt::black);
		painter->setBrush(QBrush(Qt::green));
	}
	else {
		painter->setPen(Qt::black);
		painter->setBrush(QBrush(Qt::blue));
	}
	painter->drawRect(option.rect);
	painter->restore();
#else 
	QStyledItemDelegate::paint(painter, option, index);
#endif 
}

QSize MyDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	return QSize(150, 200);
}
