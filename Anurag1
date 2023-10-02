import boto3
import cv2
from cvzone.HandTrackingModule import HandDetector

myec2 = boto3.resource("ec2")

def launchOS():
    response = myec2.create_instances(
        ImageId="ami-0da59f1af71ea4ad2",
        InstanceType="t2.micro",
        MaxCount=1,
        MinCount=1
    )

cap = cv2.VideoCapture(0)
detector = HandDetector()

while True:
    status, photo = cap.read()
    cv2.imshow("my photo", photo)

    handphoto = detector.findHands(photo, draw=False)

    if handphoto:
        lmlist = handphoto[0]
        fingerstatus = detector.fingersUp(lmlist)

        if fingerstatus == [1, 1, 1, 1, 1]:
            print("all up")
            launchOS()
            launchOS()
            launchOS()
            launchOS()
            launchOS()
    
        elif fingerstatus == [0, 1, 0, 0, 0]:
            print("index finger up")
            launchOS()
    
        elif fingerstatus == [0, 1, 1, 0, 0]:
            print("index and middle finger up")
            launchOS()
            launchOS()
    
        else:
            print("idk")

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cv2.destroyAllWindows()
cap.release()
