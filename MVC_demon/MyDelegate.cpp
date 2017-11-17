#include "stdafx.h"
#include "MyDelegate.h"
#include <QFileSystemModel>


MyDelegate::MyDelegate()
	: QStyledItemDelegate(NULL)
{
}


MyDelegate::~MyDelegate()
{
}

void MyDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

	const QFileSystemModel *nModel = qobject_cast<const QFileSystemModel *>(index.model());

	if (!nModel || !index.isValid()) {
		Q_ASSERT(0);
		return;
	}
	

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
	else if (option.state & QStyle::State_Selected) {
		painter->setPen(Qt::black);
		painter->setBrush(QBrush(Qt::black));
	}
	else {
		painter->setPen(Qt::black);
		painter->setBrush(QBrush(Qt::blue));
	}

	
	if (option.showDecorationSelected) {	//???
		painter->drawRect(option.rect);
	}
	else {
		painter->drawRect(option.rect.marginsRemoved(QMargins(10, 10, 10, 10)));
	}
	painter->restore();

#else 
	QStyledItemDelegate::paint(painter, option, index);
#endif 

	QPen nTextPen;
	nTextPen.setColor(Qt::black);
	nTextPen.setWidth(2);

	QFont nTextFont;
	nTextFont.setBold(true);
	nTextFont.setPointSize(20);

	painter->save();
	painter->setPen(nTextPen);
	painter->setFont(nTextFont);

	QString nStr("Other");
	QFileInfo nFileInfo = nModel->fileInfo(index);
	if (nFileInfo.isDir()) {
		nStr = QString("DIR");
	}
	else if (nFileInfo.isFile()){
		if (nFileInfo.suffix() == "mp4") {
			nStr = QString("Video");
		}
	}

	painter->drawText(option.rect, Qt::AlignHCenter | Qt::AlignBottom, nStr);
	painter->restore();
}

QSize MyDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	return QSize(150, 200);
}
