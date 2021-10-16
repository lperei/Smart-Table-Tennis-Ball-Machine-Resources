#import RPi.GPIO as GPIO
#GPIO.setmode(GPIO.BOARD)
#GPIO.setup(33,GPIO.OUT)
#my_pwm=GPIO.PWM(33,100)

#my_pwm.start(100)
#my_pwm.ChangeDutyCycle(50)
#my_pwm.ChangeDutyCycle(50)
#my_pwm.ChangeDutyCycle(100)


import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)
GPIO.setup(33,GPIO.OUT)
def main():

	#GPIO.output(33,False)
	my_pwm=GPIO.PWM(33,30)

	my_pwm.start(20)
	my_pwm.ChangeDutyCycle(100)

if __name__ == '__main__':
    main()
