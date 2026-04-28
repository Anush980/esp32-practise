#pragma once

void mpuInit();
void mpuCalibrate();
void mpuRead(float &ax, float &ay, float &az,
             float &gx, float &gy, float &gz);