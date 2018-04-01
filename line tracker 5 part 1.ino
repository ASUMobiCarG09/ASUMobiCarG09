void motor_control()
{

int left_motor_speed = initial_motor_speed-PID_value;
int right_motor_speed = initial_motor_speed+PID_value;

constrain(left_motor_speed,0,255);
constrain(right_motor_speed,0,255);
analogWrite(9,left_motor_speed); //Left Motor Speed
analogWrite(10,right_motor_speed); //Right Motor Speed
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
}

void loop()
{
read_sensor_values();
calculate_pid();
motor_control();
}
