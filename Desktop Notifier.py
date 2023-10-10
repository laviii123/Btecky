from plyer import notification
import time

if __name__=='__main__':
    while True:
        notification.notify(
            title = "*** Take Rest ***",
            message = "Rest is helpful for complete the work successfully",
            app_icon = "D:/vs code/pythonpr/Python Projects/icon.ico",
            timeout = 5)
        time.sleep(10)
