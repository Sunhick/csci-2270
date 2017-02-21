//
//  Widget.cpp
//  Move
//
//  Created by Sunil on 2/20/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "Widget.h"

Widget::Widget() {
    cout << "Widget ctor" << endl;
}

Widget::~Widget() {
    cout << "Widget dtor" << endl;
}

Widget::Widget(Widget& Widget) {
    cout << "copy constructor" << endl;
}

Widget::Widget(const Widget& Widget) {
    cout << "const copy constructor" << endl;
}

Widget::Widget(Widget&& Widget) noexcept(true) {
    cout << "const move constructor" << endl;
}

Widget& Widget::operator=(const Widget& Widget) {
    cout << "copy assignment lvalue" << endl;
    return *this;
}

Widget& Widget::operator=(Widget&& Widget) noexcept(true) {
    cout << "move assignment Rvalue" << endl;
    return *this;
}
