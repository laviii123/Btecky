import tkinter as tk
from tkinter import filedialog
import json
import yaml

# Function to convert JSON to YAML
def convert_json_to_yaml():
    # Ask the user to select a JSON file
    json_file_path = filedialog.askopenfilename(filetypes=[("JSON files", "*.json")])
    if not json_file_path:
        return  # User canceled the file selection

    # Load JSON data
    try:
        with open(json_file_path, 'r') as json_file:
            data = json.load(json_file)
    except Exception as e:
        error_label.config(text=f"Error reading JSON: {str(e)}")
        return

    # Ask the user to select a location to save the YAML file
    yaml_file_path = filedialog.asksaveasfilename(filetypes=[("YAML files", "*.yaml")])
    if not yaml_file_path:
        return  # User canceled the file selection

    # Convert JSON to YAML and save to the selected file
    try:
        with open(yaml_file_path, 'w') as yaml_file:
            yaml.dump(data, yaml_file, default_flow_style=False)
        success_label.config(text=f"Conversion successful. YAML file saved at {yaml_file_path}")
    except Exception as e:
        error_label.config(text=f"Error saving YAML: {str(e)}")

# Create the GUI window
window = tk.Tk()
window.title("JSON to YAML Converter")

# Create and configure labels
info_label = tk.Label(window, text="Select a JSON file to convert to YAML.")
info_label.pack()
error_label = tk.Label(window, fg="red")
error_label.pack()
success_label = tk.Label(window, fg="green")
success_label.pack()

# Create the "Convert" button
convert_button = tk.Button(window, text="Convert", command=convert_json_to_yaml)
convert_button.pack()

# Start the GUI main loop
window.mainloop()
