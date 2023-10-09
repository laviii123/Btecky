
# pyttsx3 is a simple text to speech Python library
# Using pyttsx3
# An application invokes the pyttsx3.init() factory function to get a reference to a pyttsx3.Engine instance. During construction, the engine initializes a pyttsx3.driver.DriverProxy object responsible for loading a speech engine driver implementation from the pyttsx3.drivers module. After construction, an application uses the engine object to register and unregister event callbacks; produce and stop speech; get and set speech engine properties; and start and stop event loops.

# It allows you to read any text from a PDF , text , dat file or a HTML page and listen it like an audio book

# import pyttsx3
# engine = pyttsx3.init()

# text = "this is wonderful"
# engine.say(text)

# #play audio
# engine.runAndWait()

# reading a pdf file

import pyttsx3
import PyPDF2


pdf_file = open(r"C:\CODE\python\projects-automation-python\hello.pdf" , mode ="rb")
reader = PyPDF2.PdfReader(pdf_file , strict=False)

number_of_pages = len(reader.pages)


engine = pyttsx3.init()
for i in range (0,1):
    page = reader.pages[i]
    pageContent = page.extract_text()

    newrate = 300
    engine.setProperty('rate' , newrate)

    newvol = 100
    engine.setProperty('volume' , newvol)

    voices = engine.getProperty('voices')
    engine.setProperty('voice' , voices[1].id)

    engine.say(pageContent)

    engine.save_to_file(pageContent , "audioo.mp3")
    engine.runAndWait()
    engine.stop()
  

















