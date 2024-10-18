#ifndef TRECIPEDITBOX_H
#define TRECIPEDITBOX_H

#include <QFrame>
#include <QLineEdit>
#include <QEvent>
#include <QHostAddress>

inline constexpr int AddressFieldsNum = 4;

using namespace std;

class CTRecIPEditBox : public QFrame
{
    Q_OBJECT
public:
    CTRecIPEditBox();
    CTRecIPEditBox(QWidget*);
    ~CTRecIPEditBox();

    virtual bool eventFilter(QObject* pObj, QEvent* event);

    void IPAddress_set(const QHostAddress& IP);
    QString IPAddress_get();

private slots:
    void on_addressChanged(QLineEdit*);

signals:
    void signalTextChanged(QLineEdit*);

private:
    QLineEdit* m_pFields[AddressFieldsNum];
};

#endif // TRECIPEDITBOX_H
