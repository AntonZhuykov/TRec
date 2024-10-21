#include "TRecIPEditBox.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QRegularExpression>
#include <QKeyEvent>



CTRecIPEditBox::CTRecIPEditBox()
{
    for(auto& f : m_pFields)
    {
        f = nullptr;
    }
}

CTRecIPEditBox::CTRecIPEditBox(QWidget* pParent)
    : QFrame(pParent)
{
    setFrameShape(QFrame::StyledPanel);
    setFrameShadow(QFrame::Sunken);

    QHBoxLayout* pLayout = new QHBoxLayout(this);
    setLayout(pLayout);
    pLayout->setContentsMargins(0,0,0,0);
    pLayout->setSpacing(0);

    for(auto i=0; i<AddressFieldsNum; i++)
    {
        if(i != 0)
        {
            QLabel* pDot = new QLabel(".", this);
            pDot->setStyleSheet("background: white");
            pLayout->addWidget(pDot);
            pLayout->setStretch(pLayout->count(), 0);
        }

        m_pFields[i] = new QLineEdit(this);
        m_pFields[i]->installEventFilter(this);

        pLayout->addWidget(m_pFields[i]);
        pLayout->setStretch(pLayout->count(), 1);

        m_pFields[i]->setFrame(false);
        m_pFields[i]->setAlignment(Qt::AlignCenter);

        QFont tmpFont = m_pFields[i]->font();
        tmpFont.setStyleHint(QFont::Monospace);
        tmpFont.setFixedPitch(true);
        m_pFields[i]->setFont(tmpFont);
    }

    setMaximumWidth(40 * AddressFieldsNum);

    connect(this, &CTRecIPEditBox::signalTextChanged,
            this, &CTRecIPEditBox::on_addressChanged);
}

CTRecIPEditBox::~CTRecIPEditBox()
{

}



void CTRecIPEditBox::IPAddress_set(const QString& IPStr)
{
    QRegularExpression re("(\\d+).(\\d+).(\\d+).(\\d+)");
    QRegularExpressionMatch match = re.match(IPStr);
    if(match.hasMatch())
    {
        for(auto i=0; i<AddressFieldsNum; i++)
        {
            m_pFields[i]->setText(match.captured(i+1));
        }
    }
}



QString CTRecIPEditBox::IPAddress_get()
{
    QString res;
    for(auto& f : m_pFields)
        res += f->text() + ".";
    return res.chopped(1);
}



void CTRecIPEditBox::on_addressChanged(QLineEdit* pLine)
{
    for(auto i=0; i<AddressFieldsNum; i++)
    {
        if(pLine == m_pFields[i])
        {
            if(pLine->text().size() == 2 && // IPItem2Str(UCHAR_MAX).size()
                pLine->text().size() == pLine->cursorPosition() )
            {
                if((i+1) != AddressFieldsNum)
                {
                    m_pFields[i+1]->setFocus();
                    m_pFields[i+1]->selectAll();
                }
            }
        }
    }
}



bool CTRecIPEditBox::eventFilter(QObject* pObj, QEvent* event)
{
    bool bRes = QFrame::eventFilter(pObj, event);

    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent* pEvent = dynamic_cast<QKeyEvent*>( event );
        if ( pEvent )
        {
            for ( auto i = 0; i != AddressFieldsNum; ++i )
            {
                QLineEdit* pEdit = m_pFields[i];
                if ( pEdit == pObj )
                {
                    switch ( pEvent->key() )
                    {
                    case Qt::Key_Left:
                    {
                        if ( pEdit->cursorPosition() == 0 )
                        {
                            // user wants to move to previous item
                            if ( i != 0 )
                            {
                                m_pFields[i-1]->setFocus();
                                m_pFields[i-1]->setCursorPosition( m_pFields[i-1]->text().size() );
                            }
                        }
                        break;
                    }
                    case Qt::Key_Right:
                    {
                        if ( pEdit->text().isEmpty() ||
                            (pEdit->text().size() == pEdit->cursorPosition()) )
                        {
                            // user wants to move to next item
                            if ( i+1 != AddressFieldsNum )
                            {
                                m_pFields[i+1]->setFocus();
                                m_pFields[i+1]->setCursorPosition( 0 );
                            }
                        }
                        break;
                    }
                    default:
                    {
                        emit signalTextChanged( pEdit );
                    }
                    }

                    break;
                }
            }
        }
    }

    return bRes;
}


