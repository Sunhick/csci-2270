//
//  Widget.h
//  Move
//
//  Created by Sunil on 2/20/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef Widget_h
#define Widget_h

#include <iostream>

using namespace std;

class Widget {
public:
    Widget();
    Widget(Widget& widget);
    Widget(const Widget& widget);
    Widget(Widget&& Widget) noexcept(true);
    ~Widget();
    Widget& operator=(const Widget& widget);
    Widget& operator=(Widget&& widget) noexcept(true);
};

#endif /* Widget_h */
