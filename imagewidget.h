#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QPen>
#include <QLabel>
//线段
//typedef struct myLine{
//    QPoint startPnt;
//    QPoint endPnt;
//}myLine;

class ImageWidget : public QWidget
{
    Q_OBJECT

public:
    enum				/*定义图形的类型 */
    {
        NONE_DRAW,
        POINT_DRAW,
        LINE_DRAW,
        RECT_DRAW,
        ELLIPSE_DRAW,
        TEXT_DRAW,
        FILL_DRAW,
        ERASE_DRAW,
        MOVE_DRAW,
        SELECT_DRAW,
        CLIP_DRAW,
        IMAGE_DRAW,
        DEL_DRAW,
        COLORPICKER_DRAW
    } draw_type;
    ImageWidget(QWidget *parent = 0);
    ~ImageWidget();    
    QImage image,imgtemp,imgbuf[10],imgmove;
    QPoint startPnt;   //起点
    QPoint endPnt;     //终点
    QPen pen;
    QBrush brush;
    QString text;
    QLabel *labelFont;
    bool boolBorder,boolFill;
    void newfile();
    void load(QString fileName);
    void save(QString path);
    void setAngle(qreal rotateAngle);
    void zoomin();
    void zoomout();
    void zoom1();
    void rotate(qreal degrees);
    void mirror(bool bh,bool bv);
    void drawPoint();
    void drawLine();
    void drawRect();
    void drawEllipse();
    void drawText();
    void drawFill();
    void drawErase();
    void drawMove();
    void drawRectselect();
    void colorPicker();
    void cutSelect();
    void delSelect();    
    void copy();
    void paste();
    void draw(QImage &img);    
    void newsize(int width,int height);
    void scale(int ratioW,int ratioH);
    void moveImgbuf();
    void selectAll();
    void gray();
    void invert();
    void blur(int p);

public slots:
    void undo();
    void redo();

private slots:
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void moveTopUp();
    void moveTopDown();
    void moveLeftLeft();
    void moveLeftRight();
    void moveRightLeft();
    void moveRightRight();
    void moveBottomUp();
    void moveBottomDown();

protected:
    void paintEvent(QPaintEvent *);

private:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

};

#endif // IMAGEWIDGET_H
