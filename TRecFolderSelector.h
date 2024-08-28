#ifndef TRECFOLDERSELECTOR_H
#define TRECFOLDERSELECTOR_H

#include <QLineEdit>


class CTRecFolderSelector : public QLineEdit
{
public:
    explicit CTRecFolderSelector(QWidget* parent = nullptr);

    void chooseFolder();

private:
    class QAction* m_action = nullptr;
};

#endif // TRECFOLDERSELECTOR_H
