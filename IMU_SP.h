#pragma once
#include <Windows.h>
#include <Math.h>
#include <gl\GL.h>
#using <System.dll>

using namespace System;
//using namespace std;

#define PI_F 3.14159265l
#define beta 0.01

float const sense = 5.0f;
float const alpha = 0.035;

float const X_pixel = GetSystemMetrics(SM_CXSCREEN);
float const Y_pixel = GetSystemMetrics(SM_CYSCREEN);

float const wand[4] = { 0.0f, -sense, 0.0f, 0.0f };


float invSqrt(float x);
float roundby2(float value);
float accl_num(int raw);
float magn_num(int raw);
float lpf(float in, float out);
float Deg_Rad(float Deg);
void QuaternionProduct(float p[4], float a[4], float b[4]);
void QuaternionUpdate(float &q0, float &q1, float &q2, float &q3, float &gx, float &gy, float &gz, float &ax, float &ay, float &az, float dt);
void QuaternionUpdate(float &q0, float &q1, float &q2, float &q3, float &gx, float &gy, float &gz, float &ax, float &ay, float &az, float &mx, float &my, float &mz, float dt);
void MahonyQuatUpdate(float &q0, float &q1, float &q2, float &q3, float &gx, float &gy, float &gz, float &ax, float &ay, float &az, float dt);
void Quat_to_Screen(float qx, float qy, float qz, float qw, float sensitivity);
Int16 finger_case(Int16, Int16, Int16, Int16, Int16);
void function_case(Int16);
