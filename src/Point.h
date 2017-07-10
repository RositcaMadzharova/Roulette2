#ifndef POINT_H_
#define POINT_H_
#include <string>
using namespace std;

class Point
{
public:
    int X;
    int Y;
    string m_PullColor;
    int m_value;

    Point()
    {
        X = 0;
        Y = 0;
        m_PullColor = "";
        m_value =0;
    }

    Point(int x, int y, string color, int value)
    {
        X = x;
        Y = y;
        m_PullColor = color;
        m_value = value ;
    }
};


#endif /* POINT_H_ */
