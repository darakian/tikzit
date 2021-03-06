#include "util.h"

float bezierInterpolate(float dist, float c0, float c1, float c2, float c3) {
    float distp = 1 - dist;
    return	(distp*distp*distp) * c0 +
            3 * (distp*distp) * dist * c1 +
            3 * (dist*dist) * distp * c2 +
            (dist*dist*dist) * c3;
}

QPointF bezierInterpolateFull (float dist, QPointF c0, QPointF c1, QPointF c2, QPointF c3) {
    return QPointF(bezierInterpolate (dist, c0.x(), c1.x(), c2.x(), c3.x()),
                   bezierInterpolate (dist, c0.y(), c1.y(), c2.y(), c3.y()));
}


float roundToNearest(float stepSize, float val) {
    if (stepSize==0.0f) return val;
    else return round(val/stepSize)*stepSize;
}

float radiansToDegrees (float radians) {
    return (radians * 180.0f) / M_PI;
}

float degreesToRadians(float degrees) {
    return (degrees * M_PI) / 180.0f;
}

int normaliseAngleDeg (int degrees) {
    while (degrees > 180) {
        degrees -= 360;
    }
    while (degrees <= -180) {
        degrees += 360;
    }
    return degrees;
}

float normaliseAngleRad (float rads) {
    while (rads > M_PI) {
        rads -= 2 * M_PI;
    }
    while (rads <= -M_PI) {
        rads += 2 * M_PI;
    }
    return rads;
}

// convert float to string, squashing very small floats to zero
QString floatToString(float f) {
    if (f >= -0.000001 && f <= 0.000001) return "0";
    else return QString::number(f);
}
