import RPi.GPIO as GPIO
import time
import jetson.inference
import jetson.utils
output_pins = {
    'JETSON_XAVIER': 18,
    'JETSON_NANO': 33,
    'JETSON_NX': 33,
    'CLARA_AGX_XAVIER': 18,
    'JETSON_TX2_NX': 32,
}
output_pin = output_pins.get(GPIO.model, None)

net = jetson.inference.detectNet("ssd-mobilenet-v2", threshold=0.5)
camera = jetson.utils.videoSource("csi://0")      # '/dev/video0' for V4L2
display = jetson.utils.videoOutput("display://0") # 'my_video.mp4' for file

area_count = 0
area_sum = 0

if output_pin is None:
    raise Exception('PWM not supported on this board')


def main():
    # Pin Setup:
    # Board pin-numbering scheme
    GPIO.setmode(GPIO.BOARD)
    # set pin as an output pin with optional initial state of HIGH
    GPIO.setup(output_pin, GPIO.OUT, initial=GPIO.HIGH)
    p = GPIO.PWM(output_pin, 50)
    val = 25
    incr = 0
    p.start(val)

    print("PWM running. Press CTRL+C to exit.")
    while display.IsStreaming():
        img = camera.Capture()
        detections = net.Detect(img)
        display.Render(img)
        display.SetStatus("Object Detection | Network {:.0f} FPS".format(net.GetNetworkFPS()))
        if (detections!= []):
            if (detections[0].ClassID == 1): # Human
                if (detections[0].Center[0] < 600): # frame 1200*720
                    print("cam's right")
                    val = 10
                else:
                    print("cam's left")
                    val = 100


        p.ChangeDutyCycle(val)
  

if __name__ == '__main__':
    main()
