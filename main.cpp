#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QPropertyAnimation>
#include <QLineEdit>
#include<QTextEdit>
#include <QMediaPlayer>
#include <QAudioOutput>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建一个QWidget窗口
    QWidget window;
    window.setWindowTitle("海龟汤");
    window.resize(1000, 800);
    // 设置窗口固定大小，禁止调整窗口大小

    window.setFixedSize(1000, 800);

    // 加载第一个窗口的背景图片
    QPixmap background(":/ph/ph/915fd0a2d767170fad637b50d38a584.jpg");
    // 创建第二个窗口的背景图片
    QPixmap background2(":/ph/ph/OIP.jpg");
    // 创建第三个窗口的背景图片
    QPixmap background3(":/ph/ph/bing.jpg");
    // 创建第四个窗口的背景图片
    QPixmap background4(":/ph/ph/zhuo.jpg");
    // 创建第五个窗口的背景图片
    QPixmap background5(":/ph/ph/wuzi.jpg");

    // 创建一个QLabel用于显示第一个窗口的背景图片
    QLabel *backgroundLabel = new QLabel(&window);
    backgroundLabel->setPixmap(background);
    backgroundLabel->setScaledContents(true); // 让图片按比例缩放以填充label
    backgroundLabel->resize(window.size());

    // 创建一个QPushButton用于控制音乐播放和暂停
    QPushButton *musicButton = new QPushButton(&window);
    musicButton->setIcon(QIcon(":/ph/ph/istockphoto-1244097573-612x612.jpg")); // 设置按钮图标
    musicButton->setIconSize(QSize(40, 40)); // 设置图标大小
    musicButton->setFixedSize(40, 40); // 设置按钮大小

    // 设置按钮位置为右上角
    musicButton->move(window.width() - musicButton->width()-5 , 5);
    // 创建媒体对象
    QMediaPlayer *player = new QMediaPlayer(&window);
    QAudioOutput *audioOutput = new QAudioOutput(&window);
    player->setAudioOutput(audioOutput);

    // 设置音频文件路径
    player->setSource(QUrl("qrc:/ph/ph/yinyue.mp3"));

    player->play();

    // 点击音乐按钮控制音乐播放和暂停
    QObject::connect(musicButton, &QPushButton::clicked, [=]() {
        if (player->playbackState() == QMediaPlayer::PlayingState) {
            player->pause();

        } else {
            player->play();

        }
    });




    // 创建一个QPushButton
    QPushButton *startButton = new QPushButton("开始游戏", &window);

    // 设置按钮的固定大小
    startButton->setFixedSize(100, 50);

    // 使用样式表设置按钮内字体的大小和对齐方式
    startButton->setStyleSheet("font-size: 30px; text-align: center;");

    // 使用样式表设置按钮的背景颜色为红色
    startButton->setStyleSheet("background-color: red;");

    // 将按钮放置在第一个窗口背景图片的中间
    int x = (window.width() - startButton->width()) ;
    int y = (window.height() - startButton->height()) ;
    startButton->move(x*2/9, y*3/4);

    // 提升按钮的层级，使其显示在 QLabel 上层
    startButton->raise();



    // 创建水平布局管理器
    QHBoxLayout *layout = new QHBoxLayout(&window);

    // 创建三个按钮，并设置按钮文字
    QPushButton *button1 = new QPushButton(&window);
    button1->setText("冰淇淋");
    QPushButton *button2 = new QPushButton(&window);
    button2->setText("捉迷藏");
    QPushButton *button3 = new QPushButton(&window);
    button3->setText("诡异的画像");

    // 使用样式表设置按钮上文字的大小
    button1->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                           "font-size: 40px;""border-radius: 12px;" "}");

    button1->setIconSize(QSize(200,70));
    button2->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                           "font-size: 40px;""border-radius: 12px;" "}");

    button2->setIconSize(QSize(200,70));
    button3->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                           "font-size: 40px;""border-radius: 12px;" "}");

    button3->setIconSize(QSize(200,70));

    // 将按钮添加到水平布局管理器中
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);

    button1->setFixedSize(200,70);
    button2->setFixedSize(200,70);
    button3->setFixedSize(200,70);

    // 设置布局管理器的间距和伸展因子
    layout->setSpacing(100); // 设置按钮之间的间距
    layout->setStretch(0, 1); // 设置第一个按钮的伸展因子为1，使其占据额外空间
    layout->setStretch(1, 1); // 设置第二个按钮的伸展因子为1
    layout->setStretch(2, 1); // 设置第三个按钮的伸展因子为1

    // 将水平布局管理器应用到窗口
    window.setLayout(layout);


    button1->hide();
    button2->hide();
    button3->hide();

    // 创建一个QLabel用于显示文本
    QLabel *textLabel = new QLabel("请选择关卡", &window);
    textLabel->setStyleSheet("font-size: 60px;");

    // 设置文本框的位置和大小
    textLabel->setGeometry(360, 150, 300, 150);

    // 将文本框添加到窗口
    textLabel->hide();

    //冰淇淋
    // 创建一个文本框
    QTextEdit *lineEdit = new QTextEdit(&window);
    lineEdit->setGeometry(150, 150, 700, 150); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdit->setFont(QFont("Arial", 20));
    lineEdit->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdit->setStyleSheet("background-color: transparent; border: none;");

    // 创建一个定时器
    QTimer timer;
    timer.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString text = "哥哥好后悔,如果那天自己吃了冰淇凌，弟弟就不会死了。";
    int currentIndex = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        if (currentIndex < text.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdit->setText(text.left(currentIndex + 1));
            currentIndex++;
        } else {
            // 停止定时器
            timer.stop();
        }
    });
    lineEdit->hide();

    // 创建一个文本框
    QLineEdit *lineEdit3 = new QLineEdit(&window);
    lineEdit3->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdit3->setFont(QFont("Arial", 20));
    lineEdit3->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdit3->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timer3;
    timer3.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString text3 = "哥哥真的自责吗？            是。";
    int currentIndex3 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timer3, &QTimer::timeout, [&]() {
        if (currentIndex3 < text3.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdit3->setText(text3.left(currentIndex3 + 1));
            currentIndex3++;
        } else {
            // 停止定时器
            timer3.stop();
        }
    });
    lineEdit3->hide();

    // 创建一个文本框
    QLineEdit *lineEdit4 = new QLineEdit(&window);
    lineEdit4->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdit4->setFont(QFont("Arial", 20));
    lineEdit4->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdit4->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timer4;
    timer4.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString text4 = "是哥哥谋杀了弟弟吗？            否。";
    int currentIndex4 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timer4, &QTimer::timeout, [&]() {
        if (currentIndex4 < text4.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdit4->setText(text4.left(currentIndex4 + 1));
            currentIndex4++;
        } else {
            // 停止定时器
            timer4.stop();
        }
    });
    lineEdit4->hide();

    // 创建一个文本框
    QLineEdit *lineEdit5 = new QLineEdit(&window);
    lineEdit5->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdit5->setFont(QFont("Arial", 20));
    lineEdit5->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdit5->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timer5;
    timer5.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString text5 = "弟弟是自杀的吗？            否。";
    int currentIndex5 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timer5, &QTimer::timeout, [&]() {
        if (currentIndex5 < text5.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdit5->setText(text5.left(currentIndex5 + 1));
            currentIndex5++;
        } else {
            // 停止定时器
            timer5.stop();
        }
    });
    lineEdit5->hide();

    // 创建一个文本框
    QLineEdit *lineEdit6 = new QLineEdit(&window);
    lineEdit6->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdit6->setFont(QFont("Arial", 20));
    lineEdit6->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdit6->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timer6;
    timer6.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString text6 = "尸体上有伤口吗？            否。";
    int currentIndex6 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timer6, &QTimer::timeout, [&]() {
        if (currentIndex6 < text6.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdit6->setText(text6.left(currentIndex6 + 1));
            currentIndex6++;
        } else {
            // 停止定时器
            timer6.stop();
        }
    });
    lineEdit6->hide();
    // 创建一个文本框
    QLineEdit *lineEdit7 = new QLineEdit(&window);
    lineEdit7->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdit7->setFont(QFont("Arial", 20));
    lineEdit7->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdit7->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timer7;
    timer7.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString text7 = "弟弟死在室外吗？            否，死在一个狭小的空间里。";
    int currentIndex7 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timer7, &QTimer::timeout, [&]() {
        if (currentIndex7 < text7.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdit7->setText(text7.left(currentIndex7 + 1));
            currentIndex7++;
        } else {
            // 停止定时器
            timer7.stop();
        }
    });
    lineEdit7->hide();

    // 创建一个文本框
    QLineEdit *lineEdit8 = new QLineEdit(&window);
    lineEdit8->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdit8->setFont(QFont("Arial", 20));
    lineEdit8->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdit8->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timer8;
    timer8.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString text8 = "冰淇淋融化了吗？            否。";
    int currentIndex8 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timer8, &QTimer::timeout, [&]() {
        if (currentIndex8< text8.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdit8->setText(text8.left(currentIndex8 + 1));
            currentIndex8++;
        } else {
            // 停止定时器
            timer8.stop();
        }
    });
    lineEdit8->hide();

    // 创建一个文本框
    QLineEdit *lineEdit9 = new QLineEdit(&window);
    lineEdit9->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdit9->setFont(QFont("Arial", 20));
    lineEdit9->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdit9->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timer9;
    timer9.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString text9 = "冰淇淋被吃掉了吗？            否，没有被任何人吃掉。";
    int currentIndex9 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timer9, &QTimer::timeout, [&]() {
        if (currentIndex9< text9.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdit9->setText(text9.left(currentIndex9 + 1));
            currentIndex9++;
        } else {
            // 停止定时器
            timer9.stop();
        }
    });
    lineEdit9->hide();

    // 创建一个文本框
    QTextEdit *lineEdit10 = new QTextEdit(&window);
    lineEdit10->setGeometry(150, 150, 700, 200); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdit10->setFont(QFont("Arial", 50));
    lineEdit10->setStyleSheet("color: red; background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timer10;
    timer10.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString text10 = "回答错误。                  就差一点点啦~";
    int currentIndex10 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timer10, &QTimer::timeout, [&]() {
        if (currentIndex10< text10.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdit10->setText(text10.left(currentIndex10 + 1));
            currentIndex10++;
        } else {
            // 停止定时器
            timer10.stop();
        }
    });
    lineEdit10->hide();

    // 创建一个文本框
    QTextEdit *lineEdit111 = new QTextEdit(&window);
    lineEdit111->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdit111->setFont(QFont("Arial", 50));
    lineEdit111->setStyleSheet("color: green; background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timer111;
    timer111.setInterval(400); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString text111 = "回答正确！你真厉害！";
    int currentIndex111 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timer111, &QTimer::timeout, [&]() {
        if (currentIndex111< text111.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdit111->setText(text111.left(currentIndex111 + 1));
            currentIndex111++;
        } else {
            // 停止定时器
            timer111.stop();
        }
    });
    lineEdit111->hide();

    // 创建一个文本框
    QTextEdit *lineEdit13 = new QTextEdit(&window);
    lineEdit13->setGeometry(150, 150, 700, 550); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdit13->setFont(QFont("Arial", 20));
    lineEdit13->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdit13->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timer13;
    timer13.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString text13 = "妈妈新买了一箱冰淇淋放在仓库的冰柜里，打算等过几天再放进冰箱，但她忘了关上冰柜的门。年幼的弟弟偷偷来到仓库玩耍，看到冰柜门是开的，便搬来小板凳，瞧见了里面的冰淇淋。他想要拿一支来吃，但很难够着，不小心失去平衡，一头栽倒掉了进去，冰箱门也因晃动盖上了。这时，哥哥正好放学回家，妈妈告诉他，“今天新买了冰淇淋，想吃的话可以去仓库拿哦！”哥哥拒绝了。直到吃晚饭的时候，大家才发现弟弟不见了，找了很久才在仓库的冰柜中找到，但弟弟已经死掉了。";
    int currentIndex13 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timer13, &QTimer::timeout, [&]() {
        if (currentIndex13< text13.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdit13->setText(text13.left(currentIndex13 + 1));
            currentIndex13++;
        } else {
            // 停止定时器
            timer13.stop();
        }
    });
    lineEdit13->hide();





    // 右下角按钮
    QPushButton *askButton = new QPushButton("提问", &window);
    askButton->setGeometry(window.width() - 120, window.height() - 140, 100, 50);

    QPushButton *answerButton = new QPushButton("回答", &window);
    answerButton->setGeometry(window.width() - 120, window.height() - 70, 100, 50);
    askButton->hide();
    answerButton->hide();

    QPushButton *answerButton2 = new QPushButton("查看汤底", &window);
    answerButton2->setGeometry(window.width() - 120, window.height() - 70, 100, 50);
    answerButton2->hide();



    // 创建三个按钮，并设置按钮文字
    QPushButton *button11 = new QPushButton("哥哥", &window);
    QPushButton *button12 = new QPushButton("弟弟", &window);
    QPushButton *button13 = new QPushButton("冰淇淋", &window);
    button11->setGeometry(window.width()/2-100, 120, 200, 70);
    button12->setGeometry(window.width()/2-100, 270, 200, 70);
    button13->setGeometry(window.width()/2-100, 420, 200, 70);
    button11->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    button11->setIconSize(QSize(200,70));
    button12->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    button12->setIconSize(QSize(200,70));
    button13->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    button13->setIconSize(QSize(200,70));



    button11->hide();
    button12->hide();
    button13->hide();
    QPushButton *returnButton1 = new QPushButton("返回", &window);
    returnButton1->setGeometry(20, window.height() - 70, 100, 50);
    returnButton1->hide();

    // 创建一个文本框
    QLineEdit *lineEdit11 = new QLineEdit(&window);
    lineEdit11->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdit11->setFont(QFont("Arial", 20));
    lineEdit11->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdit11->setStyleSheet("background-color: transparent; border: none;");

    // 创建一个定时器
    QTimer timer11;
    timer11.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString text11 = "弟弟是怎么死的？";
    int currentIndex11 = 0; // 记录当前显示的字符位置

    // 创建三个按钮，并设置按钮文字
    QPushButton *button21 = new QPushButton("自责", &window);
    QPushButton *button22 = new QPushButton("谋害", &window);

    button21->setGeometry(window.width()/2-100, 120, 200, 70);
    button22->setGeometry(window.width()/2-100, 270, 200, 70);

    button21->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    button21->setIconSize(QSize(200,70));
    button22->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    button22->setIconSize(QSize(200,70));

    button21->hide();
    button22->hide();

    // 创建三个按钮，并设置按钮文字
    QPushButton *button31 = new QPushButton("自杀", &window);
    QPushButton *button32 = new QPushButton("尸体", &window);
    QPushButton *button33 = new QPushButton("室外", &window);
    button31->setGeometry(window.width()/2-100, 120, 200, 70);
    button32->setGeometry(window.width()/2-100, 270, 200, 70);
    button33->setGeometry(window.width()/2-100, 420, 200, 70);
    button31->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    button31->setIconSize(QSize(200,70));
    button32->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    button32->setIconSize(QSize(200,70));
    button33->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    button33->setIconSize(QSize(200,70));

    button31->hide();
    button32->hide();
    button33->hide();

    // 创建三个按钮，并设置按钮文字
    QPushButton *button41 = new QPushButton("融化", &window);
    QPushButton *button42 = new QPushButton("吃掉", &window);

    button41->setGeometry(window.width()/2-100, 120, 200, 70);
    button42->setGeometry(window.width()/2-100, 270, 200, 70);

    button41->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    button41->setIconSize(QSize(200,70));
    button42->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    button42->setIconSize(QSize(200,70));


    button41->hide();
    button42->hide();

    // 创建三个按钮，并设置按钮文字
    QPushButton *button51 = new QPushButton("毒死", &window);
    QPushButton *button52 = new QPushButton("饿死", &window);

    button51->setGeometry(window.width()/3-150, 250, 200, 70);
    button52->setGeometry(window.width()/3-150, 370, 200, 70);

    button51->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    button51->setIconSize(QSize(200,70));
    button52->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    button52->setIconSize(QSize(200,70));


    button51->hide();
    button52->hide();

    // 创建三个按钮，并设置按钮文字
    QPushButton *button53 = new QPushButton("热死", &window);
    QPushButton *button54 = new QPushButton("冻死", &window);

    button53->setGeometry(window.width()*2/3-150, 250, 200, 70);
    button54->setGeometry(window.width()*2/3-150, 370, 200, 70);

    button53->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    button53->setIconSize(QSize(200,70));
    button54->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    button54->setIconSize(QSize(200,70));


    button53->hide();
    button54->hide();


    // 左下角按钮
    QPushButton *returnButton = new QPushButton("返回", &window);
    returnButton->setGeometry(20, window.height() - 70, 100, 50);
    returnButton->hide();



    QPushButton *returnButton11 = new QPushButton("返回", &window);
    returnButton11->setGeometry(20, window.height() - 70, 100, 50);
    returnButton11->hide();
    QPushButton *returnButton12 = new QPushButton("返回", &window);
    returnButton12->setGeometry(20, window.height() - 70, 100, 50);
    returnButton12->hide();
    QPushButton *returnButton13 = new QPushButton("返回", &window);
    returnButton13->setGeometry(20, window.height() - 70, 100, 50);
    returnButton13->hide();
    QPushButton *returnButton2 = new QPushButton("返回", &window);
    returnButton2->setGeometry(20, window.height() - 70, 100, 50);
    returnButton2->hide();
    QPushButton *returnButton3 = new QPushButton("返回", &window);
    returnButton3->setGeometry(20, window.height() - 70, 100, 50);
    returnButton3->hide();
    QPushButton *returnButton4 = new QPushButton("返回", &window);
    returnButton4->setGeometry(20, window.height() - 70, 100, 50);
    returnButton4->hide();
    QPushButton *returnButton5 = new QPushButton("返回", &window);
    returnButton5->setGeometry(20, window.height() - 70, 100, 50);
    returnButton5->hide();
    QPushButton *returnButton6 = new QPushButton("返回", &window);
    returnButton6->setGeometry(20, window.height() - 70, 100, 50);
    returnButton6->hide();

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timer11, &QTimer::timeout, [&]() {
        if (currentIndex11 < text11.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdit11->setText(text11.left(currentIndex11 + 1));
            currentIndex11++;
        } else {
            // 停止定时器
            timer11.stop();
        }
    });
    lineEdit11->hide();


    // 点击按钮时切换背景图片
    QObject::connect(startButton, &QPushButton::clicked, [=]() {
        backgroundLabel->setPixmap(background2);
        startButton->hide();
        button1->show();
        button2->show();
        button3->show();
        textLabel->show();
    });

    // 假设要延迟执行操作的时间为3秒
    int delayMilliseconds = 3000;

    // 创建一个定时器
    QTimer timer1;
    QObject::connect(button1, &QPushButton::clicked, [&]() {
        backgroundLabel->setPixmap(background3);
        button1->hide();
        button2->hide();
        button3->hide();
        textLabel->hide();
        lineEdit->show();
        lineEdit->setText(""); // 清空文本框内容
        currentIndex = 0; // 重置当前索引
        timer.start();
        timer1.start(delayMilliseconds);
    });



    // 连接定时器的timeout信号到槽函数，延迟执行
    QObject::connect(&timer1, &QTimer::timeout, [&]() {
        // 在这里编写延迟执行的操作
        returnButton->show();
        askButton->show();
        answerButton->show();
    });

    QObject::connect(returnButton, &QPushButton::clicked, [&]() {
        backgroundLabel->setPixmap(background2);
        button1->show();
        button2->show();
        button3->show();
        textLabel->show();
        lineEdit->hide();
        returnButton->hide();
        askButton->hide();
        answerButton->hide();
        timer1.stop();
    });

    QObject::connect(askButton, &QPushButton::clicked, [&]() {
        button11->show();
        button12->show();
        button13->show();
        textLabel->hide();
        lineEdit->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        returnButton1->show();
        answerButton->show();
    });
    QObject::connect(button11, &QPushButton::clicked, [&]() {
        button21->show();
        button22->show();
        button11->hide();
        button12->hide();
        button13->hide();
        textLabel->hide();
        lineEdit->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        returnButton11->show();
        answerButton->show();
    });
    QObject::connect(button12, &QPushButton::clicked, [&]() {
        button31->show();
        button32->show();
        button33->show();
        button11->hide();
        button12->hide();
        button13->hide();
        textLabel->hide();
        lineEdit->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        returnButton2->show();
        answerButton->show();
    });
    QObject::connect(button13, &QPushButton::clicked, [&]() {
        button41->show();
        button42->show();
        button11->hide();
        button12->hide();
        button13->hide();
        textLabel->hide();
        lineEdit->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        returnButton4->show();
        answerButton->show();
    });
    QObject::connect(button21, &QPushButton::clicked, [&]() {
        button21->hide();
        button22->hide();
        button11->hide();
        button12->hide();
        button13->hide();
        textLabel->hide();
        lineEdit->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit3->show();
        lineEdit3->setText(""); // 清空文本框内容
        currentIndex3 = 0; // 重置当前索引
        timer3.start();
        returnButton12->show();
        returnButton11->hide();
        answerButton->show();
    });
    QObject::connect(button22, &QPushButton::clicked, [&]() {
        button21->hide();
        button22->hide();
        button11->hide();
        button12->hide();
        button13->hide();
        textLabel->hide();
        lineEdit->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit4->show();
        lineEdit4->setText(""); // 清空文本框内容
        currentIndex4 = 0; // 重置当前索引
        timer4.start();
        returnButton12->show();
        returnButton11->hide();
        answerButton->show();
    });
    QObject::connect(button31, &QPushButton::clicked, [&]() {
        button31->hide();
        button32->hide();
        button33->hide();
        button11->hide();
        button12->hide();
        button13->hide();
        textLabel->hide();
        lineEdit->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit5->show();
        lineEdit5->setText(""); // 清空文本框内容
        currentIndex5 = 0; // 重置当前索引
        timer5.start();
        returnButton3->show();
        returnButton2->hide();
        answerButton->show();
    });
    QObject::connect(button32, &QPushButton::clicked, [&]() {
        button31->hide();
        button32->hide();
        button33->hide();
        button11->hide();
        button12->hide();
        button13->hide();
        textLabel->hide();
        lineEdit->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit6->show();
        lineEdit6->setText(""); // 清空文本框内容
        currentIndex6 = 0; // 重置当前索引
        timer6.start();
        returnButton3->show();
        returnButton2->hide();
        answerButton->show();
    });
    QObject::connect(button33, &QPushButton::clicked, [&]() {
        button31->hide();
        button32->hide();
        button33->hide();
        button11->hide();
        button12->hide();
        button13->hide();
        textLabel->hide();
        lineEdit->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit7->show();
        lineEdit7->setText(""); // 清空文本框内容
        currentIndex7 = 0; // 重置当前索引
        timer7.start();
        returnButton3->show();
        returnButton2->hide();
        answerButton->show();
    });
    QObject::connect(button41, &QPushButton::clicked, [&]() {
        button41->hide();
        button42->hide();
        button11->hide();
        button12->hide();
        button13->hide();
        textLabel->hide();
        lineEdit->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit8->show();
        lineEdit8->setText(""); // 清空文本框内容
        currentIndex8 = 0; // 重置当前索引
        timer8.start();
        returnButton5->show();
        returnButton4->hide();
        answerButton->show();
    });
    QObject::connect(button42, &QPushButton::clicked, [&]() {
        button41->hide();
        button42->hide();
        button11->hide();
        button12->hide();
        button13->hide();
        textLabel->hide();
        lineEdit->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit9->show();
        lineEdit9->setText(""); // 清空文本框内容
        currentIndex9 = 0; // 重置当前索引
        timer9.start();
        returnButton5->show();
        returnButton4->hide();
        answerButton->show();
    });
    QObject::connect(button51, &QPushButton::clicked, [&]() {
        button51->hide();
        button52->hide();
        button53->hide();
        button54->hide();
        lineEdit11->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit10->show();
        lineEdit10->setText(""); // 清空文本框内容
        currentIndex10 = 0; // 重置当前索引
        timer10.start();
        returnButton5->hide();
        returnButton4->hide();
        returnButton11->hide();
        answerButton->hide();
        answerButton2->show();
    });
    QObject::connect(button52, &QPushButton::clicked, [&]() {
        button51->hide();
        button52->hide();
        button53->hide();
        button54->hide();
        lineEdit11->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit10->show();
        lineEdit10->setText(""); // 清空文本框内容
        currentIndex10 = 0; // 重置当前索引
        timer10.start();
        returnButton5->hide();
        returnButton4->hide();
        returnButton11->hide();
        answerButton->hide();
        answerButton2->show();
    });
    QObject::connect(button53, &QPushButton::clicked, [&]() {
        button51->hide();
        button52->hide();
        button53->hide();
        button54->hide();
        lineEdit11->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit10->show();
        lineEdit10->setText(""); // 清空文本框内容
        currentIndex10 = 0; // 重置当前索引
        timer10.start();
        returnButton5->hide();
        returnButton4->hide();
        returnButton11->hide();
        answerButton->hide();
        answerButton2->show();
    });
    QObject::connect(button54, &QPushButton::clicked, [&]() {
        button51->hide();
        button52->hide();
        button53->hide();
        button54->hide();
        lineEdit11->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit111->show();
        lineEdit111->setText(""); // 清空文本框内容
        currentIndex111 = 0; // 重置当前索引
        timer111.start();
        returnButton5->hide();
        returnButton4->hide();
        returnButton11->hide();
        answerButton->hide();
        answerButton2->show();
    });
    QObject::connect(answerButton2, &QPushButton::clicked, [&]() {
        button51->hide();
        button52->hide();
        button53->hide();
        button54->hide();
        lineEdit10->hide();
        lineEdit111->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit13->show();
        lineEdit13->setText(""); // 清空文本框内容
        currentIndex13 = 0; // 重置当前索引
        timer13.start();
        returnButton5->hide();
        returnButton4->hide();
        returnButton11->hide();
        answerButton->hide();
        answerButton2->hide();
        returnButton6->show();
        askButton->hide();
    });
    QObject::connect(returnButton12, &QPushButton::clicked, [&]() {
        button21->show();
        button22->show();
        button12->hide();
        button13->hide();
        textLabel->hide();
        lineEdit->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit3->hide();
        lineEdit4->hide();
        returnButton12->hide();
        returnButton11->show();
        answerButton->show();
    });
    QObject::connect(returnButton2, &QPushButton::clicked, [&]() {
        button31->hide();
        button32->hide();
        button33->hide();
        button11->show();
        button12->show();
        button13->show();
        textLabel->hide();
        lineEdit11->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit5->hide();
        lineEdit6->hide();
        lineEdit7->hide();
        returnButton1->show();
        returnButton2->hide();
        answerButton->show();
    });
    QObject::connect(returnButton3, &QPushButton::clicked, [&]() {
        button31->show();
        button32->show();
        button33->show();
        button12->hide();
        button13->hide();
        textLabel->hide();
        lineEdit11->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit5->hide();
        lineEdit6->hide();
        lineEdit7->hide();
        returnButton2->show();
        returnButton3->hide();
        answerButton->show();
    });
    QObject::connect(returnButton4, &QPushButton::clicked, [&]() {
        button41->hide();
        button42->hide();
        button11->show();
        button12->show();
        button13->show();
        textLabel->hide();
        lineEdit11->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit5->hide();
        lineEdit6->hide();
        lineEdit7->hide();
        returnButton1->show();
        returnButton4->hide();
        answerButton->show();
    });
    QObject::connect(returnButton5, &QPushButton::clicked, [&]() {
        button41->show();
        button42->show();
        button11->hide();
        button12->hide();
        button13->hide();
        textLabel->hide();
        lineEdit11->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit8->hide();
        lineEdit9->hide();
        returnButton4->show();
        returnButton5->hide();
        answerButton->show();
    });
    QObject::connect(returnButton6, &QPushButton::clicked, [&]() {
        backgroundLabel->setPixmap(background2);
        button1->show();
        button2->show();
        button3->show();
        textLabel->hide();
        lineEdit11->hide();
        returnButton->hide();
        askButton->hide();
        timer1.stop();
        lineEdit8->hide();
        lineEdit13->hide();
        returnButton4->hide();
        returnButton6->hide();
    });
    QObject::connect(returnButton1, &QPushButton::clicked, [&]() {
        button11->hide();
        button12->hide();
        button13->hide();
        lineEdit->show();
        returnButton->show();
        askButton->show();
        timer1.stop();
        returnButton1->hide();
    });

    QObject::connect(returnButton11, &QPushButton::clicked, [&]() {
        button51->hide();
        button52->hide();
        button53->hide();
        button54->hide();
        button21->hide();
        button22->hide();
        button11->show();
        button12->show();
        button13->show();
        returnButton1->show();
        askButton->hide();
        timer1.stop();
        returnButton11->hide();
        lineEdit11->hide();
        answerButton->show();
    });
    QObject::connect(returnButton13, &QPushButton::clicked, [&]() {
        button31->hide();
        button32->hide();
        button33->hide();
        button11->show();
        button12->show();
        button13->show();
        returnButton1->show();
        askButton->show();
        timer1.stop();
        returnButton13->hide();
    });
    QObject::connect(answerButton, &QPushButton::clicked, [&]() {
        button51->show();
        button52->show();
        button53->show();
        button54->show();
        button11->hide();
        button12->hide();
        button13->hide();
        button21->hide();
        button22->hide();
        button31->hide();
        button32->hide();
        button33->hide();
        button41->hide();
        button42->hide();
        textLabel->hide();
        lineEdit->hide();
        lineEdit3->hide();
        lineEdit4->hide();
        lineEdit5->hide();
        lineEdit6->hide();
        lineEdit7->hide();
        lineEdit8->hide();
        lineEdit9->hide();
        lineEdit11->show();
        lineEdit11->setText(""); // 清空文本框内容
        currentIndex11 = 0; // 重置当前索引
        timer11.start();
        returnButton1->hide();
        returnButton11->show();
        returnButton12->hide();
        returnButton13->hide();
        returnButton2->hide();
        returnButton3->hide();
        returnButton4->hide();
        returnButton5->hide();
        answerButton->hide();
        timer1.stop();
        askButton->hide();
    });
    //捉迷藏








    // 创建一个文本框
    QTextEdit *lineEdita = new QTextEdit(&window);
    lineEdita->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdita->setFont(QFont("Arial", 20));
    lineEdita->setStyleSheet("color: white; background-color: transparent; border: none;");

    // 创建一个定时器
    QTimer timera;
    timera.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString texta = "我跟妈妈玩捉迷藏，当妈妈看到我时，我却一动也不能动了。";
    int currentIndexa = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timera, &QTimer::timeout, [&]() {
        if (currentIndexa < texta.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdita->setText(texta.left(currentIndexa + 1));
            currentIndexa++;
        } else {
            // 停止定时器
            timera.stop();
        }
    });
    lineEdita->hide();
    // 创建一个文本框
    QTextEdit *lineEdita1 = new QTextEdit(&window);
    lineEdita1->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdita1->setFont(QFont("Arial", 20));
    lineEdita1->setStyleSheet("color: white; background-color: transparent; border: none;");

    // 创建一个定时器
    QTimer timera1;
    timera1.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString texta1 = "我是因害怕而不能动吗？     是。";
    int currentIndexa1 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timera1, &QTimer::timeout, [&]() {
        if (currentIndexa1 < texta1.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdita1->setText(texta1.left(currentIndexa1 + 1));
            currentIndexa1++;
        } else {
            // 停止定时器
            timera1.stop();
        }
    });
    lineEdita1->hide();
    // 创建一个文本框
    QTextEdit *lineEdita2 = new QTextEdit(&window);
    lineEdita2->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdita2->setFont(QFont("Arial", 20));
    lineEdita2->setStyleSheet("color: white; background-color: transparent; border: none;");

    // 创建一个定时器
    QTimer timera2;
    timera2.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString texta2 = "我真的在玩捉迷藏吗？     是。";
    int currentIndexa2 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timera2, &QTimer::timeout, [&]() {
        if (currentIndexa2 < texta2.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdita2->setText(texta2.left(currentIndexa2 + 1));
            currentIndexa2++;
        } else {
            // 停止定时器
            timera2.stop();
        }
    });
    lineEdita2->hide();
    // 创建一个文本框
    QTextEdit *lineEdita3 = new QTextEdit(&window);
    lineEdita3->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdita3->setFont(QFont("Arial", 20));
    lineEdita3->setStyleSheet("color: white; background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timera3;
    timera3.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString texta3 = "我是在户外玩捉迷藏吗？     是。";
    int currentIndexa3 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timera3, &QTimer::timeout, [&]() {
        if (currentIndexa3 < texta3.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdita3->setText(texta3.left(currentIndexa3 + 1));
            currentIndexa3++;
        } else {
            // 停止定时器
            timera3.stop();
        }
    });
    lineEdita3->hide();
    // 创建一个文本框
    QTextEdit *lineEdita4 = new QTextEdit(&window);
    lineEdita4->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdita4->setFont(QFont("Arial", 20));
    lineEdita4->setStyleSheet("color: white; background-color: transparent; border: none;");

    // 创建一个定时器
    QTimer timera4;
    timera4.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString texta4 = "我躲在衣柜里吗？     否。";
    int currentIndexa4 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timera4, &QTimer::timeout, [&]() {
        if (currentIndexa4 < texta4.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdita4->setText(texta4.left(currentIndexa4 + 1));
            currentIndexa4++;
        } else {
            // 停止定时器
            timera4.stop();
        }
    });
    lineEdita4->hide();
    // 创建一个文本框
    QTextEdit *lineEdita5 = new QTextEdit(&window);
    lineEdita5->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdita5->setFont(QFont("Arial", 20));
    lineEdita5->setStyleSheet("color: white; background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timera5;
    timera5.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString texta5 = "我躲在床底吗？     是。";
    int currentIndexa5 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timera5, &QTimer::timeout, [&]() {
        if (currentIndexa5 < texta5.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdita5->setText(texta5.left(currentIndexa5 + 1));
            currentIndexa5++;
        } else {
            // 停止定时器
            timera5.stop();
        }
    });
    lineEdita5->hide();

    // 创建一个文本框
    QTextEdit *lineEditb1 = new QTextEdit(&window);
    lineEditb1->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEditb1->setFont(QFont("Arial", 20));
    lineEditb1->setStyleSheet("color: white; background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timerb1;
    timerb1.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString textb1 = "妈妈看到我的时候还活着吗？     否。";
    int currentIndexb1 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timerb1, &QTimer::timeout, [&]() {
        if (currentIndexb1 < textb1.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEditb1->setText(textb1.left(currentIndexb1 + 1));
            currentIndexb1++;
        } else {
            // 停止定时器
            timerb1.stop();
        }
    });
    lineEditb1->hide();
    // 创建一个文本框
    QTextEdit *lineEditb2 = new QTextEdit(&window);
    lineEditb2->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEditb2->setFont(QFont("Arial", 20));
    lineEditb2->setStyleSheet("color: white; background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timerb2;
    timerb2.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString textb2 = "妈妈的姿势正常吗？     否。";
    int currentIndexb2 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timerb2, &QTimer::timeout, [&]() {
        if (currentIndexb2 < textb2.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEditb2->setText(textb2.left(currentIndexb2 + 1));
            currentIndexb2++;
        } else {
            // 停止定时器
            timerb2.stop();
        }
    });
    lineEditb2->hide();
    // 创建一个文本框
    QTextEdit *lineEditb3 = new QTextEdit(&window);
    lineEditb3->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEditb3->setFont(QFont("Arial", 20));
    lineEditb3->setStyleSheet("color: white; background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timerb3;
    timerb3.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString textb3 = "妈妈是意外死的吗？     否。";
    int currentIndexb3 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timerb3, &QTimer::timeout, [&]() {
        if (currentIndexb3 < textb3.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEditb3->setText(textb3.left(currentIndexb3 + 1));
            currentIndexb3++;
        } else {
            // 停止定时器
            timerb3.stop();
        }
    });
    lineEditb3->hide();

    // 创建一个文本框
    QTextEdit *lineEditc = new QTextEdit(&window);
    lineEditc->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEditc->setFont(QFont("Arial", 20));
    lineEditc->setStyleSheet("color: white; background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timerc;
    timerc.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString textc = "我一动不能动的原因是什么？";
    int currentIndexc = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timerc, &QTimer::timeout, [&]() {
        if (currentIndexc < textc.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEditc->setText(textc.left(currentIndexc + 1));
            currentIndexc++;
        } else {
            // 停止定时器
            timerc.stop();
        }
    });
    lineEditc->hide();

    // 创建一个文本框
    QTextEdit *lineEditc1 = new QTextEdit(&window);
    lineEditc1->setGeometry(150, 150, 700, 300); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEditc1->setFont(QFont("Arial", 20));
    lineEditc1->setStyleSheet("color: white; background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timerc1;
    timerc1.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString textc1 = "我跟妈妈在家玩捉迷藏，我藏到了床底下，随着咚咚咚的脚步声，我知道妈妈要进来了，可当门被打开后，我看到了妈妈的眼睛，她倒在地上，身体被人拖着，似乎已经没有了呼吸，而我捂着口鼻一动也不敢动！";
    int currentIndexc1 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timerc1, &QTimer::timeout, [&]() {
        if (currentIndexc1 < textc1.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEditc1->setText(textc1.left(currentIndexc1 + 1));
            currentIndexc1++;
        } else {
            // 停止定时器
            timerc1.stop();
        }
    });
    lineEditc1->hide();






    // 创建三个按钮，并设置按钮文字
    QPushButton *buttona = new QPushButton("我", &window);
    QPushButton *buttonb = new QPushButton("妈妈", &window);

    buttona->setGeometry(window.width()/2-100, 120, 200, 70);
    buttonb->setGeometry(window.width()/2-100, 270, 200, 70);

    buttona->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                           "font-size: 30px;""border-radius: 12px;" "}");

    buttona->setIconSize(QSize(200,70));
    buttonb->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                           "font-size: 30px;""border-radius: 12px;" "}");

    buttonb->setIconSize(QSize(200,70));

    buttona->hide();
    buttonb->hide();

    // 创建三个按钮，并设置按钮文字
    QPushButton *buttona1 = new QPushButton("害怕", &window);
    QPushButton *buttona2 = new QPushButton("捉迷藏", &window);

    buttona1->setGeometry(window.width()/2-100, 120, 200, 70);
    buttona2->setGeometry(window.width()/2-100, 220, 200, 70);

    buttona1->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    buttona1->setIconSize(QSize(200,70));
    buttona2->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    buttona2->setIconSize(QSize(200,70));

    buttona1->hide();
    buttona2->hide();
    // 创建三个按钮，并设置按钮文字
    QPushButton *buttona3 = new QPushButton("户外", &window);
    QPushButton *buttona4 = new QPushButton("衣柜", &window);
    QPushButton *buttona5 = new QPushButton("床底", &window);
    buttona3->setGeometry(window.width()/2-100, 320, 200, 70);
    buttona4->setGeometry(window.width()/2-100, 420, 200, 70);
    buttona5->setGeometry(window.width()/2-100, 520, 200, 70);
    buttona3->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    buttona3->setIconSize(QSize(200,70));
    buttona4->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    buttona4->setIconSize(QSize(200,70));
    buttona5->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    buttona5->setIconSize(QSize(200,70));

    buttona3->hide();
    buttona4->hide();
    buttona5->hide();

    // 创建三个按钮，并设置按钮文字
    QPushButton *buttonb1 = new QPushButton("活着", &window);
    QPushButton *buttonb2 = new QPushButton("姿势", &window);
    QPushButton *buttonb3 = new QPushButton("意外", &window);
    buttonb1->setGeometry(window.width()/2-100, 120, 200, 70);
    buttonb2->setGeometry(window.width()/2-100, 270, 200, 70);
    buttonb3->setGeometry(window.width()/2-100, 420, 200, 70);
    buttonb1->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    buttonb1->setIconSize(QSize(200,70));
    buttonb2->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    buttonb2->setIconSize(QSize(200,70));
    buttonb3->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    buttonb3->setIconSize(QSize(200,70));

    buttonb1->hide();
    buttonb2->hide();
    buttonb3->hide();

    // 创建三个按钮，并设置按钮文字
    QPushButton *buttonc1 = new QPushButton("怕被妈妈发现", &window);
    QPushButton *buttonc2 = new QPushButton("怕被其他人发现", &window);

    buttonc1->setGeometry(window.width()/3-150, 250, 400, 70);
    buttonc2->setGeometry(window.width()/3-150, 370, 400, 70);

    buttonc1->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    buttonc1->setIconSize(QSize(200,70));
    buttonc2->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                            "font-size: 30px;""border-radius: 12px;" "}");

    buttonc2->setIconSize(QSize(200,70));


    buttonc1->hide();
    buttonc2->hide();



    // 右下角按钮
    QPushButton *askButtona = new QPushButton("提问", &window);
    askButtona->setGeometry(window.width() - 120, window.height() - 140, 100, 50);

    QPushButton *answerButtona = new QPushButton("回答", &window);
    answerButtona->setGeometry(window.width() - 120, window.height() - 70, 100, 50);
    askButtona->hide();
    answerButtona->hide();
    QPushButton *answerButtonb = new QPushButton("查看汤底", &window);
    answerButtonb->setGeometry(window.width() - 120, window.height() - 70, 100, 50);
    answerButtonb->hide();
    // 左下角按钮
    QPushButton *returnButtona = new QPushButton("返回", &window);
    returnButtona->setGeometry(20, window.height() - 70, 100, 50);
    returnButtona->hide();
    QPushButton *returnButtona1 = new QPushButton("返回", &window);
    returnButtona1->setGeometry(20, window.height() - 70, 100, 50);
    returnButtona1->hide();
    QPushButton *returnButtona2 = new QPushButton("返回", &window);
    returnButtona2->setGeometry(20, window.height() - 70, 100, 50);
    returnButtona2->hide();
    QPushButton *returnButtona3 = new QPushButton("返回", &window);
    returnButtona3->setGeometry(20, window.height() - 70, 100, 50);
    returnButtona3->hide();
    QPushButton *returnButtonb1 = new QPushButton("返回", &window);
    returnButtonb1->setGeometry(20, window.height() - 70, 100, 50);
    returnButtonb1->hide();
    QPushButton *returnButtonb2 = new QPushButton("返回", &window);
    returnButtonb2->setGeometry(20, window.height() - 70, 100, 50);
    returnButtonb2->hide();
    QPushButton *returnButtonb4 = new QPushButton("返回", &window);
    returnButtonb4->setGeometry(20, window.height() - 70, 100, 50);
    returnButtonb4->hide();
    QPushButton *returnButtonb5 = new QPushButton("返回", &window);
    returnButtonb5->setGeometry(20, window.height() - 70, 100, 50);
    returnButtonb5->hide();
    QPushButton *returnButtona8 = new QPushButton("返回", &window);
    returnButtona8->setGeometry(20, window.height() - 70, 100, 50);
    returnButtona8->hide();




    // 创建一个定时器
    QTimer timerx;
    QObject::connect(button2, &QPushButton::clicked, [&]() {
        backgroundLabel->setPixmap(background4);
        button1->hide();
        button2->hide();
        button3->hide();
        textLabel->hide();
        lineEdita->show();
        lineEdita->setText(""); // 清空文本框内容
        currentIndexa = 0; // 重置当前索引
        timera.start();
        timerx.start(delayMilliseconds);
    });
    // 连接定时器的timeout信号到槽函数，延迟执行
    QObject::connect(&timerx, &QTimer::timeout, [&]() {
        // 在这里编写延迟执行的操作
        returnButtona->show();
        askButtona->show();
        answerButtona->show();
    });
    QObject::connect(buttona, &QPushButton::clicked, [&]() {
        buttona->hide();
        buttonb->hide();
        buttona1->show();
        buttona2->show();
        buttona3->show();
        buttona4->show();
        buttona5->show();
        timerx.stop();
        returnButtona2->show();
        returnButtona1->hide();
    });
    QObject::connect(buttonb, &QPushButton::clicked, [&]() {
        buttona->hide();
        buttonb->hide();
        buttonb1->show();
        buttonb2->show();
        buttonb3->show();
        timerx.stop();
        returnButtonb1->show();
        returnButtona1->hide();
    });
    QObject::connect(buttona1, &QPushButton::clicked, [&]() {
        buttona1->hide();
        buttona2->hide();
        buttona3->hide();
        buttona4->hide();
        buttona5->hide();
        timerx.stop();
        lineEdita1->show();
        lineEdita1->setText(""); // 清空文本框内容
        currentIndexa1 = 0; // 重置当前索引
        timera1.start();
        returnButtona3->show();
        returnButtona2->hide();
    });
    QObject::connect(buttona2, &QPushButton::clicked, [&]() {
        buttona1->hide();
        buttona2->hide();
        buttona3->hide();
        buttona4->hide();
        buttona5->hide();
        timerx.stop();
        lineEdita2->show();
        lineEdita2->setText(""); // 清空文本框内容
        currentIndexa2 = 0; // 重置当前索引
        timera2.start();
        returnButtona3->show();
        returnButtona2->hide();
    });
    QObject::connect(buttona3, &QPushButton::clicked, [&]() {
        buttona1->hide();
        buttona2->hide();
        buttona3->hide();
        buttona4->hide();
        buttona5->hide();
        timerx.stop();
        lineEdita3->show();
        lineEdita3->setText(""); // 清空文本框内容
        currentIndexa3 = 0; // 重置当前索引
        timera3.start();
        returnButtona3->show();
        returnButtona2->hide();
    });
    QObject::connect(buttona4, &QPushButton::clicked, [&]() {
        buttona1->hide();
        buttona2->hide();
        buttona3->hide();
        buttona4->hide();
        buttona5->hide();
        timerx.stop();
        lineEdita4->show();
        lineEdita4->setText(""); // 清空文本框内容
        currentIndexa4 = 0; // 重置当前索引
        timera4.start();
        returnButtona3->show();
        returnButtona2->hide();
    });
    QObject::connect(buttona5, &QPushButton::clicked, [&]() {
        buttona1->hide();
        buttona2->hide();
        buttona3->hide();
        buttona4->hide();
        buttona5->hide();
        timerx.stop();
        lineEdita5->show();
        lineEdita5->setText(""); // 清空文本框内容
        currentIndexa5 = 0; // 重置当前索引
        timera5.start();
        returnButtona3->show();
        returnButtona2->hide();
    });
    QObject::connect(buttonb1, &QPushButton::clicked, [&]() {
        buttonb1->hide();
        buttonb2->hide();
        buttonb3->hide();
        timerx.stop();
        lineEditb1->show();
        lineEditb1->setText(""); // 清空文本框内容
        currentIndexb1 = 0; // 重置当前索引
        timerb1.start();
        returnButtonb2->show();
        returnButtonb1->hide();
    });
    QObject::connect(buttonb2, &QPushButton::clicked, [&]() {
        buttonb1->hide();
        buttonb2->hide();
        buttonb3->hide();
        timerx.stop();
        lineEditb2->show();
        lineEditb2->setText(""); // 清空文本框内容
        currentIndexb2 = 0; // 重置当前索引
        timerb2.start();
        returnButtonb2->show();
        returnButtonb1->hide();
    });
    QObject::connect(buttonb3, &QPushButton::clicked, [&]() {
        buttonb1->hide();
        buttonb2->hide();
        buttonb3->hide();
        timerx.stop();
        lineEditb3->show();
        lineEditb3->setText(""); // 清空文本框内容
        currentIndexb3 = 0; // 重置当前索引
        timerb3.start();
        returnButtonb2->show();
        returnButtonb1->hide();
    });
    QObject::connect(buttonc1, &QPushButton::clicked, [&]() {
        buttonc1->hide();
        buttonc2->hide();
        timerx.stop();
        lineEditc->hide();
        lineEdit10->show();
        lineEdit10->setText(""); // 清空文本框内容
        currentIndex10 = 0; // 重置当前索引
        timer10.start();
        answerButtonb->show();
        returnButtona->hide();
        returnButtona1->hide();
        returnButtona2->hide();
        returnButtona3->hide();
        returnButtonb1->hide();
        returnButtonb2->hide();
    });
    QObject::connect(buttonc2, &QPushButton::clicked, [&]() {
        buttonc1->hide();
        buttonc2->hide();
        timerx.stop();
        lineEditc->hide();
        lineEdit111->show();
        lineEdit111->setText(""); // 清空文本框内容
        currentIndex111 = 0; // 重置当前索引
        timer111.start();
        answerButtonb->show();
        returnButtona->hide();
        returnButtona1->hide();
        returnButtona2->hide();
        returnButtona3->hide();
        returnButtonb1->hide();
        returnButtonb2->hide();
    });
    QObject::connect(askButtona, &QPushButton::clicked, [&]() {
        buttona->show();
        buttonb->show();
        lineEdita->hide();
        timerx.stop();
        returnButtona->hide();
        askButtona->hide();
        returnButtona1->show();
    });
    QObject::connect(returnButtona, &QPushButton::clicked, [&]() {
        backgroundLabel->setPixmap(background2);
        button1->show();
        button2->show();
        button3->show();
        textLabel->show();
        lineEdita->hide();
        timerx.stop();
        returnButtona->hide();
        askButtona->hide();
        answerButtona->hide();
        lineEditc1->hide();
    });
    QObject::connect(returnButtona1, &QPushButton::clicked, [&]() {
        buttona->hide();
        buttonb->hide();
        buttonc1->hide();
        buttonc2->hide();
        lineEdita->show();
        lineEditc->hide();
        timerx.stop();
        returnButtona->show();
        askButtona->show();
        returnButtona1->hide();
        answerButtona->show();
        lineEditc1->hide();
    });
    QObject::connect(returnButtona2, &QPushButton::clicked, [&]() {
        buttona->show();
        buttonb->show();
        buttona1->hide();
        buttona2->hide();
        buttona3->hide();
        buttona4->hide();
        buttona5->hide();
        timerx.stop();
        returnButtona1->show();
        askButtona->hide();
        returnButtona2->hide();
    });
    QObject::connect(returnButtona3, &QPushButton::clicked, [&]() {
        buttona1->show();
        buttona2->show();
        buttona3->show();
        buttona4->show();
        buttona5->show();
        lineEdita1->hide();
        lineEdita2->hide();
        lineEdita3->hide();
        lineEdita4->hide();
        lineEdita5->hide();
        timerx.stop();
        returnButtona2->show();
        returnButtona3->hide();
    });
    QObject::connect(returnButtonb1, &QPushButton::clicked, [&]() {
        buttonb1->hide();
        buttonb2->hide();
        buttonb3->hide();
        buttona->show();
        buttonb->show();
        timerx.stop();
        returnButtona1->show();
        returnButtonb1->hide();
    });

    QObject::connect(returnButtonb2, &QPushButton::clicked, [&]() {
        buttonb1->show();
        buttonb2->show();
        buttonb3->show();
        lineEditb1->hide();
        lineEditb2->hide();
        lineEditb3->hide();
        timerx.stop();
        returnButtonb1->show();
        returnButtonb2->hide();
    });
    QObject::connect(answerButtona, &QPushButton::clicked, [&]() {
        buttona->hide();
        buttonb->hide();
        buttona1->hide();
        buttona2->hide();
        buttona3->hide();
        buttona4->hide();
        buttona5->hide();
        buttonb1->hide();
        buttonb2->hide();
        buttonb3->hide();
        buttonc1->show();
        buttonc2->show();
        returnButtona2->hide();
        returnButtona3->hide();
        returnButtonb1->hide();
        returnButtonb2->hide();
        lineEdita1->hide();
        lineEdita2->hide();
        lineEdita3->hide();
        lineEdita4->hide();
        lineEdita5->hide();
        lineEditb1->hide();
        lineEditb2->hide();
        lineEditb3->hide();
        lineEdita->hide();
        lineEditc->show();
        lineEditc->setText(""); // 清空文本框内容
        currentIndexc = 0; // 重置当前索引
        timerc.start();
        timerx.stop();
        askButtona->hide();
        returnButtona1->show();
        answerButtona->hide();
    });
    QObject::connect(answerButtonb, &QPushButton::clicked, [&]() {
        timerx.stop();
        lineEdit10->hide();
        lineEdit111->hide();
        lineEditc1->show();
        lineEditc1->setText(""); // 清空文本框内容
        currentIndexc1 = 0; // 重置当前索引
        timerc1.start();
        answerButtonb->hide();
        returnButtona->show();
    });

    //出租屋


    // 创建一个文本框
    QTextEdit *lineEdi1 = new QTextEdit(&window);
    lineEdi1->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdi1->setFont(QFont("Arial", 20));
    lineEdi1->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdi1->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer time1;
    time1.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString tex1 = "屋子有主人吗？     不重要。";
    int currentInde1 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&time1, &QTimer::timeout, [&]() {
        if (currentInde1 < tex1.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdi1->setText(tex1.left(currentInde1 + 1));
            currentInde1++;
        } else {
            // 停止定时器
            time1.stop();
        }
    });
    lineEdi1->hide();
    // 创建一个文本框
    QTextEdit *lineEdi2 = new QTextEdit(&window);
    lineEdi2->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdi2->setFont(QFont("Arial", 20));
    lineEdi2->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdi2->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer time2;
    time2.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString tex2 = "女孩不敢睡重要吗？    重要。";
    int currentInde2 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&time2, &QTimer::timeout, [&]() {
        if (currentInde2 < tex2.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdi2->setText(tex2.left(currentInde2 + 1));
            currentInde2++;
        } else {
            // 停止定时器
            time2.stop();
        }
    });
    lineEdi2->hide();
    // 创建一个文本框
    QTextEdit *lineEdi3 = new QTextEdit(&window);
    lineEdi3->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdi3->setFont(QFont("Arial", 20));
    lineEdi3->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdi3->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer time3;
    time3.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString tex3 = "是墙上的东西有异常吗？     是，她以为是一个画布。";
    int currentInde3 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&time3, &QTimer::timeout, [&]() {
        if (currentInde3 < tex3.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdi3->setText(tex3.left(currentInde3 + 1));
            currentInde3++;
        } else {
            // 停止定时器
            time3.stop();
        }
    });
    lineEdi3->hide();
    // 创建一个文本框
    QTextEdit *lineEdi4 = new QTextEdit(&window);
    lineEdi4->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdi4->setFont(QFont("Arial", 20));
    lineEdi4->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdi4->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer time4;
    time4.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString tex4 = "是屋里的花瓶有异常吗？     否。";
    int currentInde4 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&time4, &QTimer::timeout, [&]() {
        if (currentInde4 < tex4.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdi4->setText(tex4.left(currentInde4 + 1));
            currentInde4++;
        } else {
            // 停止定时器
            time4.stop();
        }
    });
    lineEdi4->hide();
    // 创建一个文本框
    QTextEdit *lineEdi5 = new QTextEdit(&window);
    lineEdi5->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdi5->setFont(QFont("Arial", 20));
    lineEdi5->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdi5->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer time5;
    time5.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString tex5 = "是门有异常吗？     否。";
    int currentInde5 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&time5, &QTimer::timeout, [&]() {
        if (currentInde5 < tex5.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdi5->setText(tex5.left(currentInde5 + 1));
            currentInde5++;
        } else {
            // 停止定时器
            time5.stop();
        }
    });
    lineEdi5->hide();
    // 创建一个文本框
    QTextEdit *lineEdi6 = new QTextEdit(&window);
    lineEdi6->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdi6->setFont(QFont("Arial", 20));
    lineEdi6->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdi6->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer time6;
    time6.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString tex6 = "第二天女孩周围有人吗？     否，但前一天有。";
    int currentInde6 = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&time6, &QTimer::timeout, [&]() {
        if (currentInde6 < tex6.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdi6->setText(tex6.left(currentInde6 + 1));
            currentInde6++;
        } else {
            // 停止定时器
            time6.stop();
        }
    });
    lineEdi6->hide();
    // 创建一个文本框
    QTextEdit *lineEdia = new QTextEdit(&window);
    lineEdia->setGeometry(150, 150, 700, 300); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdia->setFont(QFont("Arial", 20));
    lineEdia->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdia->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timea;
    timea.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString texa = "迷路的女孩找到了间空屋子，她很疲惫但她睡不着。第二天清晨，累得睡着的她醒过来，发现了异样，恐惧地逃离了屋子。";
    int currentIndea = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timea, &QTimer::timeout, [&]() {
        if (currentIndea < texa.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdia->setText(texa.left(currentIndea + 1));
            currentIndea++;
        } else {
            // 停止定时器
            timea.stop();
        }
    });
    lineEdia->hide();
    // 创建一个文本框
    QTextEdit *lineEdib = new QTextEdit(&window);
    lineEdib->setGeometry(150, 150, 700, 100); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdib->setFont(QFont("Arial", 20));
    lineEdib->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdib->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timeb;
    timeb.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString texb = "女孩发现了什么？";
    int currentIndeb = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timeb, &QTimer::timeout, [&]() {
        if (currentIndeb < texb.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdib->setText(texb.left(currentIndeb + 1));
            currentIndeb++;
        } else {
            // 停止定时器
            timeb.stop();
        }
    });
    lineEdib->hide();
    // 创建一个文本框
    QTextEdit *lineEdic = new QTextEdit(&window);
    lineEdic->setGeometry(150, 150, 700, 500); // 扩大文本框的宽度以适应文本

    // 设置文本框的字体大小和颜色
    lineEdic->setFont(QFont("Arial", 20));
    lineEdic->setStyleSheet("color: black;background-color: rgba(0, 0, 0, 0);");
    // 将文本框的背景颜色设置为透明
    lineEdic->setStyleSheet("background-color: transparent; border: none;");
    // 创建一个定时器
    QTimer timec;
    timec.setInterval(100); // 设置定时器间隔为100毫秒

    // 创建一个字符串，用于保存要显示的文字
    QString texc = "迷路的女孩黄昏时遇到了一间小屋。屋里墙上挂了一幅画像。她决定先睡一觉，但她觉得画像里的人在盯着她看，内心不安，很久都没有睡着。第二天早上女孩醒来发现画像里的人不见了，意识到墙上的不是画，而是窗户，昨晚窗外有人盯着她看，发觉了真相的女孩吓坏了，逃离了屋子。";
    int currentIndec = 0; // 记录当前显示的字符位置

    // 连接定时器的timeout()信号到槽函数
    QObject::connect(&timec, &QTimer::timeout, [&]() {
        if (currentIndec < texc.size()) {
            // 从字符串中截取下一个字符并添加到文本框中
            lineEdic->setText(texc.left(currentIndec + 1));
            currentIndec++;
        } else {
            // 停止定时器
            timec.stop();
        }
    });
    lineEdic->hide();

    // 创建三个按钮，并设置按钮文字
    QPushButton *butto1 = new QPushButton("主人", &window);
    QPushButton *butto2 = new QPushButton("不敢睡", &window);
    QPushButton *butto3 = new QPushButton("墙上", &window);
    butto1->setGeometry(window.width()/2-100, 120, 200, 70);
    butto2->setGeometry(window.width()/2-100, 220, 200, 70);
    butto3->setGeometry(window.width()/2-100, 320, 200, 70);
    butto1->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                          "font-size: 30px;""border-radius: 12px;" "}");

    butto1->setIconSize(QSize(200,70));
    butto2->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                          "font-size: 30px;""border-radius: 12px;" "}");

    butto2->setIconSize(QSize(200,70));
    butto3->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                          "font-size: 30px;""border-radius: 12px;" "}");

    butto3->setIconSize(QSize(200,70));

    butto1->hide();
    butto2->hide();
    butto3->hide();

    // 创建三个按钮，并设置按钮文字
    QPushButton *butto4 = new QPushButton("花瓶", &window);
    QPushButton *butto5 = new QPushButton("门", &window);
    QPushButton *butto6 = new QPushButton("第二天", &window);
    butto4->setGeometry(window.width()/2-100, 420, 200, 70);
    butto5->setGeometry(window.width()/2-100, 520, 200, 70);
    butto6->setGeometry(window.width()/2-100, 620, 200, 70);
    butto4->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                          "font-size: 30px;""border-radius: 12px;" "}");

    butto4->setIconSize(QSize(200,70));
    butto5->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                          "font-size: 30px;""border-radius: 12px;" "}");

    butto5->setIconSize(QSize(200,70));
    butto6->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                          "font-size: 30px;""border-radius: 12px;" "}");

    butto6->setIconSize(QSize(200,70));

    butto4->hide();
    butto5->hide();
    butto6->hide();

    // 创建三个按钮，并设置按钮文字
    QPushButton *buttob1 = new QPushButton("画布里有人活了", &window);
    QPushButton *buttob2 = new QPushButton("窗户里有人看她", &window);

    buttob1->setGeometry(window.width()/3-150, 250, 400, 70);
    buttob2->setGeometry(window.width()/3-150, 370, 400, 70);

    buttob1->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                           "font-size: 30px;""border-radius: 12px;" "}");

    buttob1->setIconSize(QSize(200,70));
    buttob2->setStyleSheet("QPushButton {" "border-image: url(:/ph/ph/anniu.jpg);""color: white;"
                           "font-size: 30px;""border-radius: 12px;" "}");

    buttob2->setIconSize(QSize(200,70));


    buttob1->hide();
    buttob2->hide();

    // 右下角按钮
    QPushButton *askButtoa = new QPushButton("提问", &window);
    askButtoa->setGeometry(window.width() - 120, window.height() - 140, 100, 50);

    QPushButton *answerButtoa = new QPushButton("回答", &window);
    answerButtoa->setGeometry(window.width() - 120, window.height() - 70, 100, 50);
    askButtoa->hide();
    answerButtoa->hide();
    QPushButton *answerButtob = new QPushButton("查看汤底", &window);
    answerButtob->setGeometry(window.width() - 120, window.height() - 70, 100, 50);
    answerButtob->hide();
    // 左下角按钮
    QPushButton *returnButto1 = new QPushButton("返回", &window);
    returnButto1->setGeometry(20, window.height() - 70, 100, 50);
    returnButto1->hide();
    QPushButton *returnButto2 = new QPushButton("返回", &window);
    returnButto2->setGeometry(20, window.height() - 70, 100, 50);
    returnButto2->hide();
    QPushButton *returnButto3 = new QPushButton("返回", &window);
    returnButto3->setGeometry(20, window.height() - 70, 100, 50);
    returnButto3->hide();
    QPushButton *returnButto4 = new QPushButton("返回", &window);
    returnButto4->setGeometry(20, window.height() - 70, 100, 50);
    returnButto4->hide();

    // 创建一个定时器
    QTimer timex;
    int delayMilliseconds1=6000;
    QObject::connect(button3, &QPushButton::clicked, [&]() {
        backgroundLabel->setPixmap(background5);
        button1->hide();
        button2->hide();
        button3->hide();
        textLabel->hide();
        lineEdia->show();
        lineEdia->setText(""); // 清空文本框内容
        currentIndea = 0; // 重置当前索引
        timea.start();
        timex.start(delayMilliseconds1);
    });
    // 连接定时器的timeout信号到槽函数，延迟执行
    QObject::connect(&timex, &QTimer::timeout, [&]() {
        // 在这里编写延迟执行的操作
        returnButto1->show();
        askButtoa->show();
        answerButtoa->show();
    });
    QObject::connect(butto1, &QPushButton::clicked, [&]() {
        butto1->hide();
        butto2->hide();
        butto3->hide();
        butto4->hide();
        butto5->hide();
        butto6->hide();
        timex.stop();
        lineEdi1->show();
        lineEdi1->setText(""); // 清空文本框内容
        currentInde1 = 0; // 重置当前索引
        time1.start();
        returnButto3->show();
        returnButto2->hide();
    });
    QObject::connect(butto2, &QPushButton::clicked, [&]() {
        butto1->hide();
        butto2->hide();
        butto3->hide();
        butto4->hide();
        butto5->hide();
        butto6->hide();
        timex.stop();
        lineEdi2->show();
        lineEdi2->setText(""); // 清空文本框内容
        currentInde2 = 0; // 重置当前索引
        time2.start();
        returnButto3->show();
        returnButto2->hide();
    });
    QObject::connect(butto3, &QPushButton::clicked, [&]() {
        butto1->hide();
        butto2->hide();
        butto3->hide();
        butto4->hide();
        butto5->hide();
        butto6->hide();
        timex.stop();
        lineEdi3->show();
        lineEdi3->setText(""); // 清空文本框内容
        currentInde3 = 0; // 重置当前索引
        time3.start();
        returnButto3->show();
        returnButto2->hide();
    });
    QObject::connect(butto4, &QPushButton::clicked, [&]() {
        butto1->hide();
        butto2->hide();
        butto3->hide();
        butto4->hide();
        butto5->hide();
        butto6->hide();
        timex.stop();
        lineEdi4->show();
        lineEdi4->setText(""); // 清空文本框内容
        currentInde4 = 0; // 重置当前索引
        time4.start();
        returnButto3->show();
        returnButto2->hide();
    });
    QObject::connect(butto5, &QPushButton::clicked, [&]() {
        butto1->hide();
        butto2->hide();
        butto3->hide();
        butto4->hide();
        butto5->hide();
        butto6->hide();
        timex.stop();
        lineEdi5->show();
        lineEdi5->setText(""); // 清空文本框内容
        currentInde5 = 0; // 重置当前索引
        time5.start();
        returnButto3->show();
        returnButto2->hide();
    });
    QObject::connect(butto6, &QPushButton::clicked, [&]() {
        butto1->hide();
        butto2->hide();
        butto3->hide();
        butto4->hide();
        butto5->hide();
        butto6->hide();
        timex.stop();
        lineEdi6->show();
        lineEdi6->setText(""); // 清空文本框内容
        currentInde6 = 0; // 重置当前索引
        time6.start();
        returnButto3->show();
        returnButto2->hide();
    });

    QObject::connect(buttob1, &QPushButton::clicked, [&]() {
        buttob1->hide();
        buttob2->hide();
        timex.stop();
        lineEdib->hide();
        lineEdit10->show();
        lineEdit10->setText(""); // 清空文本框内容
        currentIndex10 = 0; // 重置当前索引
        timer10.start();
        answerButtob->show();
        returnButto1->hide();
        returnButto2->hide();
        returnButto3->hide();
        returnButto4->hide();
    });
    QObject::connect(buttob2, &QPushButton::clicked, [&]() {
        buttob1->hide();
        buttob2->hide();
        timex.stop();
        lineEdib->hide();
        lineEdit111->show();
        lineEdit111->setText(""); // 清空文本框内容
        currentIndex111 = 0; // 重置当前索引
        timer111.start();
        answerButtob->show();
        returnButto1->hide();
        returnButto2->hide();
        returnButto3->hide();
        returnButto4->hide();
    });
    QObject::connect(askButtoa, &QPushButton::clicked, [&]() {
        butto1->show();
        butto2->show();
        butto3->show();
        butto4->show();
        butto5->show();
        butto6->show();
        lineEdia->hide();
        timex.stop();
        returnButto1->hide();
        askButtoa->hide();
        returnButto2->show();
    });
    QObject::connect(returnButto1, &QPushButton::clicked, [&]() {
        backgroundLabel->setPixmap(background2);
        button1->show();
        button2->show();
        button3->show();
        textLabel->show();
        lineEdia->hide();
        timex.stop();
        returnButto1->hide();
        askButtoa->hide();
        answerButtoa->hide();
        lineEdic->hide();
    });
    QObject::connect(returnButto2, &QPushButton::clicked, [&]() {
        butto1->hide();
        butto2->hide();
        butto3->hide();
        butto4->hide();
        butto5->hide();
        butto6->hide();
        buttob1->hide();
        buttob2->hide();
        lineEdia->show();
        lineEdic->hide();
        lineEdib->hide();
        timex.stop();
        returnButto1->show();
        askButtoa->show();
        returnButto2->hide();
        answerButtoa->show();
        lineEdic->hide();
    });

    QObject::connect(returnButto3, &QPushButton::clicked, [&]() {
        butto1->show();
        butto2->show();
        butto3->show();
        butto4->show();
        butto5->show();
        butto6->show();
        lineEdi1->hide();
        lineEdi2->hide();
        lineEdi3->hide();
        lineEdi4->hide();
        lineEdi5->hide();
        lineEdi6->hide();
        timex.stop();
        returnButto2->show();
        returnButto3->hide();
    });

    QObject::connect(returnButto4, &QPushButton::clicked, [&]() {
        buttob1->hide();
        buttob2->hide();
        lineEdib->hide();
        timex.stop();
        returnButto1->show();
        returnButto4->hide();
    });
    QObject::connect(answerButtoa, &QPushButton::clicked, [&]() {
        butto1->hide();
        butto2->hide();
        butto3->hide();
        butto4->hide();
        butto5->hide();
        butto6->hide();
        buttob1->show();
        buttob2->show();
        returnButto1->hide();
        returnButto2->hide();
        returnButto3->hide();
        lineEdi1->hide();
        lineEdi2->hide();
        lineEdi3->hide();
        lineEdi4->hide();
        lineEdi5->hide();
        lineEdi6->hide();
        lineEdia->hide();
        lineEdib->show();
        lineEdib->setText(""); // 清空文本框内容
        currentIndeb = 0; // 重置当前索引
        timeb.start();
        timex.stop();
        askButtoa->hide();
        returnButto2->show();
        answerButtoa->hide();
    });
    QObject::connect(answerButtob, &QPushButton::clicked, [&]() {
        timex.stop();
        lineEdit10->hide();
        lineEdit111->hide();
        lineEdic->show();
        lineEdic->setText(""); // 清空文本框内容
        currentIndec = 0; // 重置当前索引
        timec.start();
        answerButtob->hide();
        returnButto1->show();
    });



    window.show();

    return a.exec();
}
