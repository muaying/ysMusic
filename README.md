## 作者说明
本程序基于QT6社区版本，IDE为CLion

这是一个练习QT的demo,希望大家不要嫌弃

曲谱来自：
https://space.bilibili.com/76052941
B站演示 视频：https://www.bilibili.com/video/BV1LT4y1y73C?share_source=copy_web
## 下载
阿里云盘：https://www.aliyundrive.com/s/sCLpT1vJi51
PS: 使用Enigma Virtual Box 打包QT 文件稍微有点大，如果不放心 请自行编译

## 使用步骤
1. 管理员身份启动程序，务必是管理员，否则原神.exe 无法收到按键消息
2. 设置热键(默认设置F6)
3. 选择琴谱(默认选择琴谱1)，也可以载入自定义琴谱
4. 载入琴谱
4. 进入游戏，使用进去弹琴界面
5. 按下热键，开始弹琴，再次按下中断弹奏

PS: 程序启动自动载入了琴谱1，按下热键可以开始弹奏；载入失败，当前琴谱仍为上次载入成功的琴谱



## 示例琴谱文件
```txl
author : 作者名 ,
musicName : 曲名 ,
delay:延时,
sheet :
F6 (FA)6
```
完整见 /res/sheet 下

author,musicName,delay 不是必须的,但是sheet是必须的。
PS:
1. 每个属性必须是 `[<属性> : 内容 ,]`  冒号逗号都不可少，且都是半角符号。sheet最后无需跟逗号标记结束
2. delay 是默认延时，也就是一个按键缺省状态下的延时。该属性缺省，则为100ms

sheet 说明:
sheet标记琴谱的开始，
1. F6 表示按下 F 键 ，6ms延时
2. (FA)6 表示同时按下 FA 6ms延时
3. 基本格式为 `[key] [延时]` ，()抱起来的多个key表示同时按下，`[延时]`可以缺省默认为 delay。
4. 无视空格换行
