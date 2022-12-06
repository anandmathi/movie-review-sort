#include "listdelegate.h"

    ListDelegate::ListDelegate(QObject *parent)
    {

    }

    void ListDelegate::paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const{
        // Create base rectangle space
        QRect r = option.rect;

        // Draw the background rectangle
        painter->setBrush( QColor(18,17,22));
        painter->drawRect(r);
        // Stylesheet not changing border for some reason -- have to draw over manually with same color as background
        painter->setPen(QPen(QColor::fromRgb(18,17,22), 1, Qt::SolidLine));
        painter->drawLine(r.topRight(),r.bottomRight());
        painter->drawLine(r.topLeft(),r.bottomLeft());

        // Write the header
            // For results list: Review by Name | XX/100 | DD/MM/YY
            // For favorites list: Title
        painter->setFont( QFont( ".AppleSystemUIFont", 13, QFont::Bold ));
        painter->setPen(QPen(QColor::fromRgb(255,255,255), 1, Qt::SolidLine));
        r = option.rect.adjusted(0, 10, -10, 0);
        painter->drawText(r.left(), r.top(), r.width(), r.height(), Qt::AlignTop|Qt::AlignLeft, index.data(Qt::DisplayRole).toString(), &r);

        // Write the body
            // For results list: "[review content]"
            // For favorites list: Mean Score: XX
        painter->setFont( QFont( ".AppleSystemUIFont", 12, QFont::Normal ));
        r = option.rect.adjusted(0, 35, -10, 35);
        painter->drawText(r.left(), r.top(), r.width(), r.height(), Qt::AlignLeft|Qt::TextWordWrap|Qt::TextWrapAnywhere, index.data(Qt::UserRole + 1).toString(), &r);
    }

    QSize ListDelegate::sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const{
        // Width doesn't seem to affect anything for some reason?
        return QSize(0, 85);
    }

    ListDelegate::~ListDelegate()
    {

    }
