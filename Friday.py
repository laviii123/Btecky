# Import necessary libraries and modules
import win32com.client  # For text-to-speech
import os               # For system commands
import webbrowser       # For opening web pages
import speech_recognition as sr  # For speech recognition
import time             # For time-related operations

# Get the current timestamp
timestamp = time.strftime('%H hours %M minutes %S seconds')
# Get the current hour
hour = int(time.strftime('%H'))

# Choose the voice for the virtual assistant
your_voice_index = 1
speaker = win32com.client.Dispatch("SAPI.SpVoice")
speaker.Voice = speaker.GetVoices().Item(your_voice_index)

# Function to recognize voice commands
def takeCommand():
    r = sr.Recognizer()
    r.pause_threshold = 0.6
    with sr.Microphone() as source:
        audio = r.listen(source)
        try:
            print("Recognizing.....")
            query = r.recognize_google(audio, language="en-in")
            print(f"User said: {query}")
            return query
        except Exception as e:
            return "some error occurred. Sorry from Friday"

# Main program execution
if __name__ == '__main__':
    # Greet the user
    speaker.speak("Hello, I am Friday! Your virtual AI assistant. How can I help you, sir?")
    
    while True:
        print("Listening.....")
        query = takeCommand()
        
        # Define a list of websites to open
        sites = [["Youtube", "https://www.youtube.com"],
                 ["Instagram", "https://www.instagram.com"],
                 ["Github", "https://www.github.com"],
                 ["Whatsapp", "https://www.whatsapp.com"],
                 ["geeksforgeeks", "https://practice.geeksforgeeks.org/explore?page=1&sortBy=submissions&utm_source=geeksforgeeks&utm_medium=main_header&utm_campaign=practice_header"]]
        
        # Check if the user wants to open a website
        for site in sites:
            if f"open {site[0]}".lower() in query.lower():
                speaker.speak(f"opening {site[0]} sir")
                webbrowser.open(site[1])
                
        # Check for time-based greetings
        if query.lower() == f"good morning friday" or query.lower() == f"good afternoon Friday" or query.lower() == f"good evening Friday":
            if hour >= 6 and hour <= 12:
                speaker.speak(f"good morning sir, how can I help you")
            elif hour >= 12 and hour <= 17:
                speaker.speak(f"good afternoon sir, how can I help you")
            elif hour >= 17 and hour <= 20:
                speaker.speak(f"good evening sir, how can I help you")
            elif hour >= 20 and hour <= 6:
                speaker.speak(f"good evening sir, how can I help you")
            
        # Check for a "good night" command
        if "good night Friday" in query.lower():
            speaker.speak(f"good night sir, have a nice day ahead")
            break
        
        # Check for a "what is the time" command
        if "what is the time" in query.lower():
            speaker.speak(f"time is: {timestamp}")
        
        # Check for a greeting
        if "hello Friday" in query.lower():
            speaker.speak(f"I'm fine sir, how are you")
        
        # Check for a command to stop the program
        if "friday stop" in query.lower():
            speaker.speak(f"Sure sir")
            break
