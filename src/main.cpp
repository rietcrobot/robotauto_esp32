#include <Arduino.h>

// put function declarations here:
#define motor_grippr1 18
#define motor_grippr2 5

#define solen1 19
#define solen2 21

#define limit_up 12
#define limit_down 13

#define sw_red 4
#define sw_blue 22

bool gripper_up();
bool gripper_down();

void gripper_hold();
void gripper_let();
void gripper_lift_up();
void gripper_lift_down();

void setup()

{

  Serial.begin(115200);

  pinMode(limit_up, INPUT_PULLUP);
  pinMode(limit_down, INPUT_PULLUP);

  pinMode(sw_red, INPUT_PULLUP);
  pinMode(sw_blue, INPUT_PULLUP);

  pinMode(motor_grippr1, OUTPUT);
  pinMode(motor_grippr2, OUTPUT);

  pinMode(solen1, OUTPUT);
  pinMode(solen2, OUTPUT);

  digitalWrite(solen1, 1);
  digitalWrite(solen2, 1);
  digitalWrite(motor_grippr1, 1);
  digitalWrite(motor_grippr2, 1);

  digitalWrite(solen2, 1);
  digitalWrite(solen2, 1);

  while (!gripper_up())
    ;
}

void loop()
{
  if (digitalRead(sw_red) == 0)
  {
    while (!gripper_up())
      ;
  }
  if (digitalRead(sw_blue) == 0)
  {
    while (!gripper_down())
      ;
  }
  /*
  Serial.print(digitalRead(limit_up));
  Serial.print("  ");
  Serial.print(digitalRead(limit_down));

  Serial.print("  ");

  Serial.print(digitalRead(sw_red));
  Serial.print("  ");
  Serial.println(digitalRead(sw_blue));

  */
  /*
    if (digitalRead(sw_red) == 0)
    {
      digitalWrite(solen1, 0);
    }
    else
    {
      digitalWrite(solen1, 1);
    }
    if (digitalRead(sw_blue) == 0)
    {
      digitalWrite(solen2, 0);
    }
    else
    {

      digitalWrite(solen2, 1);
    }*/
  // gripper_down();
  /*gripper_hold();
  delay(5000);
  gripper_let();
  delay(5000);*/

  // gripper_up();
  /*gripper_hold();
  delay(100);
  gripper_up();
  delay(1000);
  gripper_lift_up();
  delay(100);
  gripper_let();
    delay(1000);*/
}

bool gripper_up()
{
  if (digitalRead(limit_up) == 0)
  {
    digitalWrite(motor_grippr1, 1);
    digitalWrite(motor_grippr2, 1);
    return true;
  }
  else
  {
    digitalWrite(motor_grippr1, 1);
    digitalWrite(motor_grippr2, 0);
    return false;
  }
}

bool gripper_down()
{

  if (digitalRead(limit_down) == 0)
  {
    digitalWrite(motor_grippr1, 1);
    digitalWrite(motor_grippr2, 1);
    return true;
  }
  else
  {
    digitalWrite(motor_grippr1, 0);
    digitalWrite(motor_grippr2, 1);
    return false;
  }
}

void gripper_hold()
{

  digitalWrite(solen2, 1);
}

void gripper_let()
{

  digitalWrite(solen2, 0);
}

void gripper_lift_up()
{
  digitalWrite(solen1, 1);
}

void gripper_lift_down()
{

  digitalWrite(solen1, 0);
}