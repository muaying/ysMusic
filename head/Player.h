//
// Created by 24100 on 2022/1/22.
//

#ifndef YSMUSIC_PLAYER_H
#define YSMUSIC_PLAYER_H

#include <QObject>

class Player : public QObject
{
    Q_OBJECT
public:
    Player(QObject *parent = nullptr);

    bool isPlaying();

public
    slots:
            void play(QString
    sheet,
    int delay
    );

    void setPlayFlag(bool flag);

    signals:

private:
    bool flag;
    bool playing;

    void playKey(char key);

    void playKey(char key1, char key2);
};


#endif //YSMUSIC_PLAYER_H
