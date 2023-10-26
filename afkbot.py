import pyautogui as pag
import time
import random

while True:
    x = random.randint(100,2000)
    y = random.randint(500,1000)

    pag.moveTo(x,y,0.5)
    time.sleep(5)