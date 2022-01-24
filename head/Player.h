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
            void play(QList<std::pair<QString,int>> musics);

    void setPlayFlag(bool flag);

    signals:

private:
    bool flag;
    bool playing;
    void playKey(QString keys);
};


#endif //YSMUSIC_PLAYER_H
