#include "mylabel.h"


mylabel::mylabel(QWidget *parent) : QLabel(parent)
{

}

bool mylabel::event(QEvent *e)
{
    if(e->type()==QEvent::MouseButtonDblClick){

        emit(doubleclick());
        //进行类型转换并处理事件
        return true;//表示处理完成
    }
    //重写此函数表示进行MouseButtonDblClick事件的拦截
    //对于其他触发的事件使用父类的evnet retrun QLabel::evnet
    return true;//表示处理完成
}
