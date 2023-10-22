# A Python program that will organize files with different extensions such as .mp3, .mkv, .txt into separate folder and thus making appearnce much smoother and user friendly
# Can also be used as (.exe) windows application by using pyintsller 
import os
import shutil 

mainDir = os.getcwd()

# to set the working directory 
workDir = f"{mainDir}/data"


# Most common file types and extensions
audios = [
    '.mp3','.wav', 'm4a', '.flac' 
]

videos = [
    '.mp4','.mkv', '.avi', '.mov', '.flv', '.avchd',
]

images = [
    '.jpg', '.jpeg', '.png', '.svg', '.tif', '.tiff', '.gif',

]

documents = [
    ".pdf", '.dox', '.docx', '.html', '.xlsx', '.xls', '.txt',

]

others = [
    '.css', '.js', '.c', '.cpp',
]


# generates list of all files 
files = os.listdir(workDir)


# Moves files of different types into Separated folders

def fileOrganizer(folder, folderName):
    for file in files:
    # print(file)
        for file_ext in folder:
            if file_ext in file:
                print("yes")
                newPath = f"./data/{folderName}"

                # Checking for already existing folder 
                if not os.path.exists(newPath):
                    os.mkdir(newPath)
                    print(f"Folder {newPath} created! ")

                oldPath = f"./data/{file}"
                print(oldPath)

                # Handles the moving work
                shutil.move(oldPath, f"{newPath}")

                print("Moved Successfully! ")
        

# Function Call for different Filetypes

fileOrganizer(others, "Others")

fileOrganizer(audios, "Audios")

fileOrganizer(videos, "Videos")

fileOrganizer(documents, "Documents")

fileOrganizer(images, "Images")
